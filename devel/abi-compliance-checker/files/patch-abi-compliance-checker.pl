--- abi-compliance-checker.pl.orig	2009-08-18 14:29:08.000000000 -0400
+++ abi-compliance-checker.pl	2009-08-23 05:20:10.000000000 -0400
@@ -276,7 +276,7 @@
     my $LibVersion = $_[0];
     if(not -e $Descriptor{$LibVersion}{'Path'})
     {
-        print "descriptor d$LibVersion does not exists, incorrect file path $Descriptor{$LibVersion}{'Path'}\n";
+        print "descriptor d$LibVersion does not exist: incorrect file path $Descriptor{$LibVersion}{'Path'}\n";
         exit(0);
     }
     my $Descriptor_File = `cat $Descriptor{$LibVersion}{'Path'}`;
@@ -2470,7 +2470,7 @@
 	system("g++ >header_compile_errors/$TargetLibraryName/$Descriptor{$Version}{'Version'} 2>&1 -fdump-translation-unit temp/$Lib_VersionName.h $CompilerOptions{$Version} $AddOpt");
     if($?)
     {
-        print "WARNING: some errors have occured while headers compilation\nyou can see compilation errors in the file header_compile_errors/$TargetLibraryName/$Descriptor{$Version}{'Version'}\n";
+        print "WARNING: some errors have occured while compiling header(s)\nyou can see compilation errors in the file header_compile_errors/$TargetLibraryName/$Descriptor{$Version}{'Version'}\n";
     }
     `mv -f $Lib_VersionName.h*.tu temp/`;
 	return (split("\n", `find temp -maxdepth 1 -name "$Lib_VersionName\.h*\.tu"`))[0];
@@ -2565,13 +2565,13 @@
 sub parseHeaders_AllInOne($)
 {
     $Version = $_[0];
-    print "headers checking v$Descriptor{$Version}{'Version'} ...\n";
+    print "checking header(s) v$Descriptor{$Version}{'Version'} ...\n";
     `mkdir -p header_compile_errors/$TargetLibraryName/`;
     `rm -fr header_compile_errors/$TargetLibraryName/$Descriptor{$Version}{'Version'}`;
 	my $DumpPath = getDump_AllInOne();
 	if(not $DumpPath)
 	{
-		print "\nERROR: can't create gcc syntax tree for headers\nyou can see compilation errors in the file header_compile_errors/$TargetLibraryName/$Descriptor{$Version}{'Version'}\n";
+		print "\nERROR: can't create gcc syntax tree for header(s)\nyou can see compilation errors in the file header_compile_errors/$TargetLibraryName/$Descriptor{$Version}{'Version'}\n";
 		exit(1);
 	}
 	getInfo($DumpPath);
@@ -4306,7 +4306,7 @@
 
 sub testSystem_cpp()
 {
-    print "testing on C++ library changes\n";
+    print "testing for C++ library changes\n";
     my @DataDefs_v1 = ();
     my @Sources_v1 = ();
     my @DataDefs_v2 = ();
@@ -4690,7 +4690,7 @@
 
 sub testSystem_c()
 {
-    print "\ntesting on C library changes\n";
+    print "\ntesting for C library changes\n";
     my @DataDefs_v1 = ();
     my @Sources_v1 = ();
     my @DataDefs_v2 = ();
@@ -5448,27 +5448,27 @@
                         elsif($Kind eq "Return_Type_And_Size")
                         {
                             $Incompatibility = "Type of return value has been changed from <span style='white-space:nowrap;'><b>$Old_Value</b> (<b>$Old_Size</b> bytes)</span> to <span style='white-space:nowrap;'><b>$New_Value</b> (<b>$New_Size</b> bytes)</span>\n";
-                            $Effect = "Applications will have got different return value and it's execution may change";
+                            $Effect = "Applications will get a different return value and execution may change";
                         }
                         elsif($Kind eq "Return_Type")
                         {
                             $Incompatibility = "Type of return value has been changed from <span style='white-space:nowrap;'><b>$Old_Value</b></span> to <span style='white-space:nowrap;'><b>$New_Value</b></span>\n";
-                            $Effect = "Applications will have got different return value and it's execution may change";
+                            $Effect = "Applications will get a different return value and execution may change";
                         }
                         elsif($Kind eq "Return_BaseType")
                         {
                             $Incompatibility = "Base type of return value has been changed from <span style='white-space:nowrap;'><b>$Old_Value</b> (<b>$Old_Size</b> bytes)</span> to <span style='white-space:nowrap;'><b>$New_Value</b> (<b>$New_Size</b> bytes)</span>\n";
-                            $Effect = "Applications will have got different return value and it's execution may change";
+                            $Effect = "Applications will get a different return value and execution may change";
                         }
                         elsif($Kind eq "Return_PointerLevel_And_Size")
                         {
                             $Incompatibility = "Type pointer level of return value has been changed from <b>$Old_Value</b> to <b>$New_Value</b> and size of type has been changed from <b>$Old_Size</b> bytes to <b>$New_Size</b> bytes\n";
-                            $Effect = "Applications will have got different return value and it's execution may change";
+                            $Effect = "Applications will get a different return value and execution may change";
                         }
                         elsif($Kind eq "Return_PointerLevel")
                         {
                             $Incompatibility = "Type pointer level of return value has been changed from <b>$Old_Value</b> to <b>$New_Value</b>\n";
-                            $Effect = "Applications will have got different return value and it's execution may change";
+                            $Effect = "Applications will get a different return value and execution may change";
                         }
                         if($Incompatibility)
                         {
@@ -6056,7 +6056,7 @@
     my @SoLibPaths = getSoPaths($LibVersion);
     if($#SoLibPaths eq -1)
     {
-        print "ERROR: there are no any shared objects in specified paths in library descriptor d$LibVersion\n";
+        print "ERROR: there are no shared objects in the paths specified in library descriptor d$LibVersion\n";
         exit(1);
     }
     foreach my $SoLibPath (@SoLibPaths)
@@ -6436,7 +6436,7 @@
         system("cd $InfoDump_FilePath/ && tar -cf $InfoDump_FileName".".tar $InfoDump_FileName");
         system("cd $InfoDump_FilePath/ && gzip $InfoDump_FileName".".tar --best");
         `rm -f $InfoDump_FilePath/$InfoDump_FileName`;
-        print "see library info dump in $InfoDump_FilePath/$InfoDump_FileName.tar.gz and use it instead of library version descriptor on other machine\n";
+        print "see library info dump in $InfoDump_FilePath/$InfoDump_FileName.tar.gz: use it instead of library version descriptor on other machine\n";
         exit(0);
     }
     
@@ -6487,15 +6487,15 @@
             parseHeaders_AllInOne(2);
         }
         
-        print "headers comparison ...\n";
+        print "comparing headers ...\n";
         mergeHeaders();
     }
     
     #LIBS MERGING
-    print "shared objects comparison ...\n";
+    print "comparing shared objects ...\n";
     mergeLibs();
     
-    print "ABI compliance report drawing ...\n";
+    print "creating ABI compliance report ...\n";
     create_HtmlReport();
     
     if($HeaderCheckingMode_Separately)
