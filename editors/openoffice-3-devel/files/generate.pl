#!/usr/bin/perl
# generate full build shell script for OpenOffice.org
# Whom:         Maho Nakata <maho@FreeBSD.org>
# $FreeBSD$

print "#!/bin/csh\n";
print "make deinstall clean\n";
print "/usr/bin/time -h make WITH_CCACHE=yes install package package-rename solver sdk ure languagepack deinstall >& log.en\n";
print "bzip2 log.en\n";
#print "rm work/.configure* work/.build* \n";
#workaround for breakage at odk sdk_oo
print "make deinstall clean\n";

print "/usr/bin/time -h make ALL_LOCALIZED_LANGS=yes >& log.all\n";

open ( FILE,  "< Makefile.localized") ;
while(<FILE>){
@tmp=split (' ',$_);
@tmp2=split ('"',$tmp[3]);
if ( $tmp[0] eq ".if" && $tmp[1] eq "\${LOCALIZED_LANG}" ) { $LANG=$tmp2[1]; 
	print "make TWEAK_L10N=yes LOCALIZED_LANG=$LANG pre-everything\n";
	print "/usr/bin/time -h make LOCALIZED_LANG=$LANG WITH_CCACHE=yes languagepack package package-rename deinstall >& log.$LANG\n";
	print "bzip2 log.$LANG\n";
	}
}
close FILE;
print "md5 OOo* > MD5SUMS.log\n";
#print "ssh mkdir -p build.good-day.net:/home/ftp/pub/OpenOffice.org/FreeBSD/tmp/\n";
#print "scp OOo* MD5SUMS.log build.good-day.net:/home/ftp/pub/OpenOffice.org/FreeBSD/tmp/\n";
