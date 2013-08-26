#!/usr/bin/perl
# generate full build shell script for Apache OpenOffice
# Whom:         Maho Nakata <maho@FreeBSD.org>
# $FreeBSD: /tmp/pcvs/ports/editors/openoffice-3/files/generate.pl,v 1.15 2012-05-09 03:48:16 maho Exp $

print "#!/bin/csh\n";
print "make deinstall clean\n";
print "/usr/bin/time -h make WITH_CCACHE=yes install package package-rename solver sdk ure languagepack deinstall >& log.en\n";
print "bzip2 log.en\n";
#print "rm work/.configure* work/.build* \n";
#workaround for breakage at odk sdk_oo
print "make deinstall clean\n";

print "/usr/bin/time -h make ALL_LOCALIZED_LANGS=yes >& log.all\n";
print "bzip2 log.all\n";

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
$oootag= `cd ..; make -V OOOTAG2`;
chomp($oootag);
$md5sumname = "$oootag" . "_md5sums.txt";
print "md5 OOo* > $md5sumname\n";

$arc= `uname -m`;
if ($arc == "amd64" ) {
print "sudo -u `who am i | awk '{print \$1}'` ssh build.good-day.net mkdir -p /home/ftp/pub/OpenOffice.org/contrib/freebsdx86-64/\n";
print "sudo -u `who am i | awk '{print \$1}'` scp OOo* $md5sumname build.good-day.net:/home/ftp/pub/OpenOffice.org/contrib/freebsdx86-64/\n";
} else { 
print "sudo -u `who am i | awk '{print \$1}'` ssh build.good-day.net mkdir -p /home/ftp/pub/OpenOffice.org/contrib/freebsdx86/\n";
print "sudo -u `who am i | awk '{print \$1}'` scp OOo* $md5sumname build.good-day.net:/home/ftp/pub/OpenOffice.org/contrib/freebsdx86/\n";
}
