#!/usr/bin/perl

#############################################################
# creation of a stand-alone-running Testtool for one platform
#
# created by thorsten.bosbach@sun.com 03.02.2003
#
# has to be called with three parameters
#
# 1. the file list that should be processed
#    that file list is system dependant and exists for 
#    a. windows
#    b. linux
#    c. solaris-sparc
#    d. solaris-intel
#    e. macos x
#
# 2. the path to the binary libraries in the build environment
#    at least 3 parts: /SRX644/unxlngi4.pro/lib.r/
#    works also for: SRX644/unxlngi4/lib/
#    the last / has to be there!!!!
#
# 3. the path to where the files should be copied.
#    the directory has to exist.
#    the last / has to be there!!!!
#
# example ./createTestTool.pl filelinx.txt /net/jumbo/ws8/SRX644/unxlngi4.pro/lib.u/ /home/autotbo/work/c/
##############################################################

use File::Basename;
use File::Copy;
use Cwd 'abs_path';

   $sScriptSource = dirname(abs_path($0));
   if ($#ARGV != 2) {
      die "syntax: createTestTool.pl ListFileName SourceDirectory/LIB/ DestinationDirectory/ \n";
   }
   $sFileWithFilenames = $ARGV[0];
   $sBaseSrcDirectory  = $ARGV[1];
   $sBaseDestDirectory = $ARGV[2];
   $sBaseDestDirectoryOrg = $sBaseDestDirectory;

   # get the directory one level higher and set the Minor Version
   print "$sBaseSrcDirectory \n";
   $sRootSrcDirectory = dirname($sBaseSrcDirectory),"\n";
   print $sRootSrcDirectory ,"\n";

   $l2 = length($sRootSrcDirectory);
   $temp = substr($sBaseSrcDirectory, $l2, length($sBaseSrcDirectory) - $l2);
   print $temp, "\n";
   $iLib = index($temp, "lib");
   if ($iLib < 0) {
      $iProgram = index($temp, "program");
      if ($iProgram < 0) {
         $iProgram = index($temp, "MacOS");
         if ($iProgram < 0) {
            die "  Starting not in directory 'lib' nor directory 'program' nor 'MacOS' :-( \n";
         } else {
            $bBuildEnvironment = 0;
         }
      } else {
         $bBuildEnvironment = 0;
      }
   } else {
      $bBuildEnvironment = 1;
   }
   if ($bBuildEnvironment) {
      $iMinor = index($temp, ".");
      if ($iMinor > -1) {
         $sMinor = substr($temp, $iMinor, length($temp)-($iMinor+1));
      } else {
         $sMinor = "";
      }
      print $sMinor, "\n";
      $sMinor2 = substr($sMinor, 1, length($sMinor)-1);

      # get the directory one more level higher and set the Pro/NONPro Version
      print "$sRootSrcDirectory \n";
      $sRootDirectory = dirname($sRootSrcDirectory),"\n";
      print $sRootDirectory ,"\n";

      $l2 = length($sRootDirectory);
      $temp = substr($sRootSrcDirectory, $l2, length($sRootSrcDirectory) - $l2);
      print $temp, "\n";
      $sPlatform = substr($temp, 1, length($temp)-1);
      $iPro = index($temp, ".");
      if ($iPro > -1) {
         $sPro = substr($temp, $iPro, 4);
      } else {
         $sPro = "";
      }
      print $sPro, "\n";

      # generate version.txt file with the version of the testtool like: Date; Time; this is a (pro/nonpro) TestTool version: 644v
      if (! -e $sBaseDestDirectory) {
          mkdir ($sBaseDestDirectory, 0777)                   or die "cannot create directory $sBaseDestDirectory: $!";
      }
      if (! -e "$sBaseDestDirectory/resource") {
          mkdir ("$sBaseDestDirectory/resource", 0777)                   or die "cannot create directory $sBaseDestDirectory: $!";
      }
      open(OUT, ">$sBaseDestDirectory/Version.txt")                  or die "cannot write version.txt: $!";
         if ($sPro eq ".pro") {
            $sKind = "";
         } else {
            $sKind = "NON";
         }
         $sTime = localtime;
         $sVersion = basename($sRootDirectory);
         print OUT "$sTime; This is a $sKind-Produkt TestTool; Version: $sVersion$sMinor\n";
      close(OUT);
   }

   # read filenames from file and put into array, and count them
   @asFileNames = ();
   $iFiles = 0;
   open(DATA, "< $sFileWithFilenames")       or die "Couldn't read from datafile '$sFileWithFilenames': $!\n";
   while (<DATA>) {
      chomp;
      push(@asFileNames, $_);
      ++$iFiles;
      #      print "  $iFiles : ", $_, "\n";
   }
   #   print "--|$asFileNames[$#asFileNames]|--$#asFileNames \n";

   # generate array with directories to proceed, 3 by now
   # process the directory with the most files first (lib)(on unixen, for windoze it would be bin :-))
   @saTempDirectory = ();
   push (@saTempDirectory, "$sBaseSrcDirectory/");
   if ($bBuildEnvironment) {
      # special files in same level bin directory
      push (@saTempDirectory, "$sRootSrcDirectory/bin$sMinor/");
      # special files in upper level common bin directory
      push (@saTempDirectory, "$sRootDirectory/common$sPro/bin$sMinor/");
   } else {
      # special files in recource directory
      push (@saTempDirectory, "$sBaseSrcDirectory/resource/");
   }

   # find all files in filelist, try in all directories
   if (! -e "$sBaseDestDirectory") {
      $temp = mkdir ("$sBaseDestDirectory");
      if ($temp != 1) {
         warn "Couldn't create dir -(\n";
      }
   }
  # if MacOS package, create .app
      if (substr(basename($sFileWithFilenames),0,7) eq 'fileosx') {
          print "  Starting creating MacOS application package.  \n";
          mkdir ("$sBaseDestDirectory/tt.app", 0777)                   or die "cannot create directory $sBaseDestDirectory/tt.app: $!";
          if (-e "$sScriptSource/macos-template.zip") {
              $temp = system "unzip", "-q", "$sScriptSource/macos-template.zip", "-d$sBaseDestDirectory/tt.app";
              if ($temp != 0) {
                  warn "Couldn't unzip mactemplate :-(\n";
              }
          }
          $sBaseDestDirectory = "$sBaseDestDirectory/tt.app/Contents/MacOS/";
      }
   if (! -e "$sBaseDestDirectory/resource") {
      $temp = mkdir ("$sBaseDestDirectory/resource");
      if ($temp != 1) {
         warn "Couldn't create dir -(\n";
      }
   }
   @asNotFoundFileNames = @asFileNames;
   for ($n=0; $n<=$#saTempDirectory; $n++){
      $sTempDirectory = $saTempDirectory[$n];
      print " + processing directory '$sTempDirectory' \n";
      @asTempFileNames = @asNotFoundFileNames;
      @asNotFoundFileNames = ();
      for ($i=0; $i <= $#asTempFileNames; $i++) {
         $name = "$sTempDirectory$asTempFileNames[$i]";
         if (-e $name) {
            @a = $name;
         } else {
	    @a = <$name*>;
         }

         if ($#a > -1 ) {
            foreach $aref (@a) {
               if (-l "$aref") {
                   $temp = basename($aref);
                   symlink(readlink("$aref"), "$sBaseDestDirectory$temp");
               } else {
                  # Identify *.res files, to put them into the resource directory; otherwise they are not found :-(
                   if (substr($aref, -4, 4) eq ".res") {
                       copy("$aref", "$sBaseDestDirectory/resource/")               or die "copy failed $asTempFileNames[$i] : $! $aref -> resource";
                   } else {
                       copy("$aref", "$sBaseDestDirectory")               or die "copy failed $asTempFileNames[$i] : $! $aref";
                   }
               }
           } 
         } else {
            push (@asNotFoundFileNames, $asTempFileNames[$i]);
         }
      }
      #   $temp = $#asTempFileNames - $#asNotFoundFileNames;
      #   print " -               found files count: $temp' \n";
      #   for ($i=0; $i <= $#asNotFoundFileNames; $i++) {
      #      print "--- $i: $asNotFoundFileNames[$i] \n";
      #   }
   }

   # print all not found files, if any
   for ($i=0; $i <= $#asNotFoundFileNames; $i++) {
      print "--- $i: $asNotFoundFileNames[$i] \n";
   }

   if ($#asNotFoundFileNames == -1) {
      print " * * * * * * * * * * * * * * * * * * * * * * * *  \n";
      print "* * * * * * FINISHED all files copied * * * * * * \n";
      print " * * * * * * * * * * * * * * * * * * * * * * * *  \n";
   } else {
      print "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n";
      print "@     ERROR there are files missing!             @\n";
      print "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n";
   }
    
   if (-e "$sBaseDestDirectory/soffice") {
       copy("$sBaseDestDirectory/soffice", "$sBaseDestDirectory/testtool")               or die "copy failed soffice -> testtool";
    }
   $temp = chmod (0555,<$sBaseDestDirectory/testtool*>);
   if ($temp != 2) {
      warn "Couldn't change permissions for testool* :-(\n";
   }
   $temp = unlink (<$sBaseDestDirectory/*.a>);
   print $temp;
 #   if ($temp != 2) {
 #      warn "Couldn't remove *.a files :-(\n";
 #   }
   if (-e "$sBaseDestDirectory/javaldx") {
      $temp = chmod (0555,<$sBaseDestDirectory/javaldx>);
      if ($temp != 1) {
         warn "Couldn't change permissions for types.rdb :-(\n";
      }
   }
   # if images_tt.zip is missing or an image in that file is missing, use images.zip!
   $images = "images_tt.zip";
   $path = '';
   if (-e "$sBaseDestDirectory/$images") {
       $path = "$sBaseDestDirectory/$images";
   } else {
       if (-e "$sScriptSource/$images") {
           $path = "$sScriptSource/$images";
       }
   }
   if ($path) {
      print "  Starting unzipping $images file; This may take a while, please standby....  \n";
      $temp = system "unzip", "-q", "$path", "-d$sBaseDestDirectory";
      if ($temp != 0) {
         warn "Couldn't unzip $images :-(\n";
      }
      print "  Finished unzipping.  \n";
      if ($path eq "$sBaseDestDirectory/$images") {
           unlink ("$sBaseDestDirectory/$images"); 
      }
   }
  # tar the directory to preserve links on moving between filesystems! 
      print "  Starting creating compressed testtool archive. This may take a while, please standby....  \n";
      $temp = substr($sBaseDestDirectoryOrg, 0, length($sBaseDestDirectoryOrg) - 1);
      $sMinor2 = $sMinor2,"_";
      $temp = system "tar", "cf", "tt_$sVersion$sMinor2$sPlatform.tar", "$temp";
      if ($temp != 0) {
         warn "Couldn't tar :-(\n";
      }
      print "  Finished taring.  \n";
  # TODO: print size!
exit;

#----------------------------------------------------------------------------------------------------------

