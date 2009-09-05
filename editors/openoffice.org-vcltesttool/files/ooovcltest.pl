#!/usr/bin/perl
# Copyright 2009 by NAKATA Maho <maho@FreeBSD.org> <maho@openoffice.org>
# All rights reserved.
use Cwd;
use File::HomeDir; #devel/p5-File-HomeDir, libfile-homedir-perl

sub parse_option {
        while ($_ = shift) {
                if (substr($_, 0, 1) eq '-') {
                        if ($_ eq '-help') {
                                print "ooovcltest [-tag tag]\n";
                                exit;
                        } elsif ($_ eq '-tag') {
				$ooo_tag_flag=1;
                                $ooo_tag = shift;
                        } elsif ($_ eq '-returnaddress') {
				$ooo_returnaddress_flag=1;
                                $ooo_returnaddress = shift;
                        } elsif ($_ eq '-pcname') {
				$ooo_pcname_flag=1;
                                $ooo_pcname = shift;
                        } else {
                                die "Invalid option: \"$_\"\n";
                        }
                }
        }
}

#main
$ooo_tag_flag=0;
$ooo_email_flag=0;
$ooo_pcname_flag=0;
$ooo_returnaddress="dummy\@openoffice.org";
$ooo_pcname="dummy";
parse_option(@ARGV);
split('_',$ooo_tag);
$ooo_codeline=@_[0];
$ooo_milestone=@_[1];
$ooo_milestone=~ s/m//; 

####
### Customize according your needs
$path_to_testttol = "/usr/local/openoffice.org-vcltesttool/program";
$path_to_ooo = "/usr/local/openoffice.org-$ooo_tag/openoffice.org3/program";
#for other environments
#$path_to_testttol = "/opt/openoffice-vcltesttool/testtool.bin";
#$path_to_ooo = "/usr/lib/openoffice/program";
####

$ooo_testautomation_archive_name="OOo_" . "$ooo_tag" . "_testautomation.tar.bz2" ;
$ooo_testautomation_site="http://ooopackages.good-day.net/pub/OpenOffice.org/qa/testautomation/";

if (!$ooo_tag_flag) {die "please speficy OOo tag\n";}
print "testing tag: $ooo_tag at ";
system("date\n");
print "downloading testautomation environment....\n";
system ("wget $ooo_testautomation_site" . "$ooo_testautomation_archive_name" . "\n");
print "done\n";

print "Downloading category list for scripts at $ooo_tag \n";

$uri="index.php\?option=com_quaste\&task=tests_overview\&workspace=" . "$ooo_codeline" . "\&milestone=" . "m$ooo_milestone";
$caturi="http://quaste.services.openoffice.org/" . $uri . "\&download=1";
$catlist=$ooo_codeline . "_m$ooo_milestone" . ".txt" ;
system ("wget -O $catlist \"$caturi\"\n");

print "Downloading hid list for scripts at $ooo_tag \n";
$hiduri="http://quaste.services.openoffice.org/" . $uri . "\&download=2";
$hidlist="hid.lst";
system ("wget -O $hidlist \"$hiduri\"\n");
print "Download done...\n";

print "extracting testautomation environment....\n";
system ("tar xfj $ooo_testautomation_archive_name\n");
print "done\n";

#download is done....

###########
#settings...
#copying hid.lst and test list 
system ("cp hid.lst $ooo_tag/testautomation/global/hid\n");
system ("grep bas $catlist >  $ooo_tag/testautomation/tools/run_tests/$catlist\n");

#settings of run_test.sh
$location=getcwd() . "/$ooo_tag/testautomation/" ;
system ("mkdir $location/errorlogs\n");
$location=~ s/\//\\\//g;
$path_to_testttol =~ s/\//\\\//g;
system ("sed -i.bak 's/sLocation=\"\"/sLocation=\"$location\"/\' $ooo_tag/testautomation/tools/run_tests/run_tests.sh\n");
system ("sed -i.bak 's/sTestTool=\"\"/sTestTool=\"$path_to_testttol\\/testtool\"/' $ooo_tag/testautomation/tools/run_tests/run_tests.sh\n");

#adjust ~/.testtoolrc
$HOME = File::HomeDir->my_home;
$location=getcwd() . "/$ooo_tag/testautomation" ;

$testtoolrc="$HOME/.testtoolrc";
open (TESTTOOLRC,">$testtoolrc") || die "Can't open file $testtoolrc !\n";
print TESTTOOLRC "[Misc]\n";
print TESTTOOLRC "CurrentProfile=_profile_Default\n";
print TESTTOOLRC "ServerTimeout=4500\n";
print TESTTOOLRC "[OOoProgramDir]\n";
print TESTTOOLRC "Type=$path_to_ooo/\n";
print TESTTOOLRC "Current=$path_to_ooo\n";
print TESTTOOLRC "All=.\n";
print TESTTOOLRC "\n";
print TESTTOOLRC "[Crashreporter]\n";
print TESTTOOLRC "UseProxy=false\n";
print TESTTOOLRC "ProxyServer=none\n";
print TESTTOOLRC "ProxyPort=8080\n";
print TESTTOOLRC "AllowContact=false\n";
print TESTTOOLRC "ReturnAddress=$ooo_returnaddress\n";
print TESTTOOLRC "\n";
print TESTTOOLRC "[_profile_Default]\n";
print TESTTOOLRC "BaseDir=$location/\n";
print TESTTOOLRC "LogBaseDir=$location/errorlogs/\n";
print TESTTOOLRC "HIDDir=$location/global/hid\n";
print TESTTOOLRC "StopOnSyntaxError=0\n";
print TESTTOOLRC "AutoReload=0\n";
print TESTTOOLRC "AutoSave=0\n";
print TESTTOOLRC "[GUI Platform]\n";
print TESTTOOLRC "Current=08\n";
print TESTTOOLRC "\n";
print TESTTOOLRC "[Communication]\n";
print TESTTOOLRC "Host=localhost\n";
print TESTTOOLRC "TTPort=12479\n";
print TESTTOOLRC "UnoPort=12480\n";
print TESTTOOLRC "\n";
print TESTTOOLRC "[WinGeom]\n";
print TESTTOOLRC "WinParams=180,74,920,875;1;0,0,0,0;\n";
print TESTTOOLRC "\n";
print TESTTOOLRC "[LRU]\n";
print TESTTOOLRC "MaxLRU=4\n";
print TESTTOOLRC "[Others]\n";
print TESTTOOLRC "PCname=$ooo_pcname\n";

close(TESTTOOLRC);

###########
#checking hid.lst (generated and QUASTe)
system ("cat $path_to_ooo/../../hid.lst | sort > hid.lst.$ooo_tag.genrated\n");
system ("sed 's/\r//' hid.lst | sort > hid.lst.$ooo_tag.quaste\n");
#see http://www.openoffice.org/issues/show_bug.cgi?id=104359
system ("sed -i.bak '/^HID_EXPIRED.*/d' hid.lst.$ooo_tag.quaste\n");
system ("sed -i.bak '/^HID_LICENSING_DIALOG.*/d' hid.lst.$ooo_tag.quaste\n");
system ("sed -i.bak '/^HID_TP_LICENSE.*/d' hid.lst.$ooo_tag.quaste\n");
system ("sed -i.bak '/^HID_TP_PURCHASE.*/d' hid.lst.$ooo_tag.quaste\n");
system ("sed -i.bak '/^HID_TP_SUMMARY.*/d' hid.lst.$ooo_tag.quaste\n");
system ("sed -i.bak '/^HID_TP_UNLOCK.*/d' hid.lst.$ooo_tag.quaste\n");
system ("sed -i.bak '/^HID_WILL_EXPIRE.*/d' hid.lst.$ooo_tag.quaste\n");
system ("sed -i.bak '/^tab:Edit:TP_UNLOCK:ED_UNLOCK_A.*/d' hid.lst.$ooo_tag.quaste\n");
system ("sed -i.bak '/^tab:Edit:TP_UNLOCK:ED_UNLOCK_B.*/d' hid.lst.$ooo_tag.quaste\n");
system ("sed -i.bak '/^tab:Edit:TP_UNLOCK:ED_UNLOCK_C.*/d' hid.lst.$ooo_tag.quaste\n");
system ("sed -i.bak '/^tab:MultiLineEdit:TP_LICENSE:ML_LICENSE.*/d' hid.lst.$ooo_tag.quaste\n");
system ("sed -i.bak '/^tab:PushButton:DLG_EXPIRED:PB_EXPIRED_EXIT.*/d' hid.lst.$ooo_tag.quaste\n");
system ("sed -i.bak '/^tab:PushButton:DLG_EXPIRED:PB_EXPIRED_PURCHASE.*/d' hid.lst.$ooo_tag.quaste\n");
system ("sed -i.bak '/^tab:PushButton:DLG_WILL_EXPIRE:PB_EXPIRE_CONTINUE.*/d' hid.lst.$ooo_tag.quaste\n");
system ("sed -i.bak '/^tab:PushButton:DLG_WILL_EXPIRE:PB_EXPIRE_PURCHASE.*/d' hid.lst.$ooo_tag.quaste\n");
system ("sed -i.bak '/^tab:PushButton:TP_LICENSE:PB_LICENSE_DOWN.*/d' hid.lst.$ooo_tag.quaste\n");
system ("sed -i.bak '/^tab:PushButton:TP_PURCHASE:PB_PURCHASE_GET.*/d' hid.lst.$ooo_tag.quaste\n");
system ("diff -u hid.lst.$ooo_tag.genrated hid.lst.$ooo_tag.quaste > hid.lst.$ooo_tag.diff\n");
print "hid.lst diff...\n";
system ("cat hid.lst.$ooo_tag.diff\n");
print "hid.lst diff...done\n";
