# bsd.sites.mk - Popular master sites.
#
# This file does not have any designated maintainer, so feel free to
# commit to it yourself.  However, it is generally a good idea to
# notify the principle maintainer in case you have a change to one of
# the software environments (KDE, GNOME, etc.).
#
# Also, this file is included from bsd.port.mk for all invocations, so
# committing a syntax error to this file is a cardinal sin, and will
# be punished accordingly.  DO NOT COMMIT SOMETHING YOU HAVEN'T TESTED.
# You have been warned. :)
#
# $FreeBSD$
#

MASTER_SITE_XCONTRIB+=	\
	ftp://crl.dec.com/pub/X11/contrib/%SUBDIR%/ \
	ftp://uiarchive.uiuc.edu/pub/X11/contrib/%SUBDIR%/ \
	ftp://ftp.gwdg.de/pub/x11/x.org/contrib/%SUBDIR%/ \
	ftp://ftp.duke.edu/pub/X11/contrib/%SUBDIR%/ \
	ftp://ftp.x.org/contrib/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/X11/contrib/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/X11/contrib/%SUBDIR%/ \
	ftp://mirror.xmission.com/X/contrib/%SUBDIR%/ \
	ftp://ftp2.x.org/contrib/%SUBDIR%/ \
	ftp://sunsite.sut.ac.jp/pub/archives/X11/contrib/%SUBDIR%/ \
	ftp://ftp.is.co.za/x/contrib/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/X11/contrib/%SUBDIR%/ \
	ftp://ftp.huji.ac.il/mirror/X11/contrib/%SUBDIR%/

MASTER_SITE_GNU+=	\
	ftp://ftp.gnu.org/gnu/%SUBDIR%/ \
	ftp://ftp.freesoftware.com/pub/gnu/%SUBDIR%/ \
	ftp://ftp.digital.com/pub/GNU/%SUBDIR%/ \
	ftp://ftp.uu.net/archive/systems/gnu/%SUBDIR%/ \
	ftp://ftp.de.uu.net/pub/gnu/%SUBDIR%/ \
	ftp://ftp.ecrc.net/pub/gnu/%SUBDIR%/ \
	ftp://ftp.sourceforge.net/pub/mirrors/gnu/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/gnu/prep/%SUBDIR%/ \
	ftp://ftp.leo.org/pub/comp/os/unix/gnu/%SUBDIR%/ \
	ftp://ftp.digex.net/pub/gnu/%SUBDIR%/ \
	ftp://ftp.wustl.edu/systems/gnu/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/pub/gnu/%SUBDIR%/

MASTER_SITE_PERL_CPAN+=	\
	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.cpan.org/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.freesoftware.com/pub/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.sourceforge.net/pub/mirrors/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/languages/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://bioinfo.weizmann.ac.il/pub/software/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://csociety-ftp.ecn.purdue.edu/pub/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/lang/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/lang/perl/CPAN/modlues/by-module/%SUBDIR%/ \
	ftp://ftp.auckland.ac.nz/pub/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://mirror.hiwaay.net/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.isu.net.sa/pub/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.bora.net/pub/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://uiarchive.uiuc.edu/pub/lang/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.ucr.ac.cr/pub/Unix/CPAN/modules/by-module/%SUBDIR%/ \
	http://www.cpan.dk/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.cs.colorado.edu/pub/perl/CPAN/modlues/by-module/%SUBDIR%/ \
	ftp://cpan.pop-mg.com.br/pub/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.is.co.za/programming/perl/CPAN/modules/by-module/%SUBDIR%/

MASTER_SITE_TEX_CTAN+=  \
	ftp://ftp.freesoftware.com/pub/tex/ctan/%SUBDIR%/  \
	ftp://wuarchive.wustl.edu/packages/TeX/%SUBDIR%/  \
	ftp://ftp.funet.fi/pub/TeX/CTAN/%SUBDIR%/  \
	ftp://ctan.unsw.edu.au/tex-archive/%SUBDIR%/ \
	ftp://ftp.cise.ufl.edu/tex-archive/%SUBDIR%/ \
	ftp://ftp.tex.ac.uk/tex-archive/%SUBDIR%/  \
	ftp://shadowmere.student.utwente.nl/pub/CTAN/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/CTAN/%SUBDIR%/ \
	ftp://sunsite.auc.dk/pub/tex/ctan/%SUBDIR%/ \
	ftp://ctan.tug.org/tex-archive/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/TeX/CTAN/%SUBDIR%/ \
	ftp://ftp.dante.de/tex-archive/%SUBDIR%/

MASTER_SITE_SUNSITE+=	\
	ftp://metalab.unc.edu/pub/Linux/%SUBDIR%/ \
	ftp://ftp.freesoftware.com/pub/linux/sunsite/%SUBDIR%/ \
	ftp://ftp.sourceforge.net/pub/mirrors/metalab/Linux/%SUBDIR%/ \
	ftp://ftp.sun.ac.za/pub/linux/sunsite/%SUBDIR%/ \
	ftp://ftp.nuri.net/pub/Linux/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp//Linux/metalab.unc.edu/%SUBDIR%/ \
	ftp://ftp.jaring.my/pub/Linux/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/Linux/mirrors/metalab/%SUBDIR%/ \
	ftp://ftp.archive.de.uu.net/pub/systems/Linux/Mirror.SunSITE/%SUBDIR%/ \
	ftp://sunsite.doc.ic.ac.uk/packages/linux/sunsite.unc-mirror/%SUBDIR%/ \
	ftp://uiarchive.cso.uiuc.edu/pub/systems/linux/sunsite/%SUBDIR%/ \
	ftp://ftp.cs.umn.edu/pub/Linux/sunsite/%SUBDIR%/

MASTER_SITE_KDE+=	\
	ftp://ftp.us.kde.org/pub/kde/%SUBDIR%/ \
	ftp://ftp.sourceforge.net/pub/sourceforge/kde/%SUBDIR%/ \
	ftp://ftp.kde.org/pub/kde/%SUBDIR%/ \
	ftp://ftp.tuniv.szczecin.pl/pub/kde/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/X11/kde/%SUBDIR%/ \
	ftp://ftp2.sinica.edu.tw/pub5/wmgrs/kde/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/X11/kde/%SUBDIR%/ \
	ftp://ftp.synesis.net/pub/mirrors/kde/%SUBDIR%/ \
	ftp://gd.tuwien.ac.at/hci/kde/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/pub/unix/X11/gui/kde/%SUBDIR%/ \
	ftp://ftp.twoguys.org/pub/kde/%SUBDIR%/ \
	ftp://ftp.dataplus.se/pub/linux/kde/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/pub/unix/X11/gui/kde/%SUBDIR%/

MASTER_SITE_COMP_SOURCES+=	\
	ftp://gatekeeper.dec.com/pub/usenet/comp.sources.%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/Unix/com.sources.%SUBDIR%/ \
	ftp://ftp.uu.net/usenet/comp.sources.%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/archive/comp.sources.%SUBDIR%/ \
	ftp://rtfm.mit.edu/pub/usenet/comp.sources.%SUBDIR%/

MASTER_SITE_GNOME+=	\
	ftp://ftp.gnome.org/pub/GNOME/%SUBDIR%/ \
	ftp://download.sourceforge.net/pub/mirrors/gnome/%SUBDIR%/ \
	ftp://rpmfind.net/linux/gnome.org/%SUBDIR%/ \
	ftp://ftp.mirror.ac.uk/sites/ftp.gnome.org/pub/GNOME/%SUBDIR%/ \
	ftp://slave.opensource.captech.com/gnome/%SUBDIR%/ \
	ftp://ftp.snoopy.net/pub/mirrors/GNOME/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/X11/GNOME/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/X11/GNOME/%SUBDIR%/ \
	ftp://ftp.cybertrails.com/pub/gnome/%SUBDIR%/ \
	ftp://ftp2.sinica.edu.tw/pub5/gnome/%SUBDIR%/ \
	ftp://gnomeftp.blue-labs.org/pub/gnome/%SUBDIR%/ \
	ftp://ftp.informatik.uni-bonn.de/pub/os/unix/gnome/%SUBDIR%/ \
	ftp://ftp.tas.gov.au/gnome/%SUBDIR%/

MASTER_SITE_AFTERSTEP+=	\
	ftp://ftp.afterstep.org/%SUBDIR%/ \
	ftp://ftp.digex.net/pub/X11/window-managers/afterstep/%SUBDIR%/ \
	ftp://ftp.alpha1.net/pub/mirrors/ftp.afterstep.org/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/X11/AfterStep/%SUBDIR%/ \
	ftp://ftp.math.uni-bonn.de/pub/mirror/ftp.afterstep.org/pub/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/X/AfterStep/%SUBDIR%/ \
	ftp://ftp.linux.co.za/pub/windowmanagers/afterstep/%SUBDIR%/

MASTER_SITE_WINDOWMAKER+= \
	ftp://ftp.windowmaker.org/pub/%SUBDIR%/ \
	ftp://ftp.goldweb.com.au/pub/WindowMaker/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/X11/window_managers/windowmaker/%SUBDIR%/ \
	ftp://ftp.ameth.org/pub/mirrors/ftp.windowmaker.org/%SUBDIR%/ \
	ftp://ftp.minet.net/pub/windowmaker/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/X/WindowMaker/%SUBDIR%/

MASTER_SITE_PORTS_JP+=	\
	ftp://ports.jp.FreeBSD.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/%SUBDIR%/ \
	ftp://ftp4.jp.FreeBSD.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/%SUBDIR%/ \
	ftp://ftp.ics.es.osaka-u.ac.jp/pub/mirrors/FreeBSD-jp/ports-jp/LOCAL_PORTS/%SUBDIR%/

MASTER_SITE_TCLTK+= \
	ftp://ftp.scriptics.com/pub/tcl/%SUBDIR%/ \
	ftp://mirror.neosoft.com/pub/tcl/mirror/ftp.scriptics.com/%SUBDIR%/ \
	ftp://sunsite.utk.edu/pub/tcl/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/languages/tcl/tcl/%SUBDIR%/ \
	ftp://ftp.uu.net/languages/tcl/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/lang/tcl/ftp.scriptics.com/%SUBDIR%/ \
	ftp://ftp.cs.tu-berlin.de/pub/tcl/distrib/%SUBDIR%/ \
	ftp://ftp.srcc.msu.su/mirror/ftp.scriptics.com/pub/tcl/%SUBDIR%/ \
	ftp://ftp.lip6.fr/pub/tcl/distrib/%SUBDIR%/

MASTER_SITE_SOURCEFORGE+= \
	ftp://download.sourceforge.net/pub/sourceforge/%SUBDIR%/ \
	http://download.sourceforge.net/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/sourceforge/%SUBDIR%/

# Where to put distfiles that don't have any other master site
MASTER_SITE_LOCAL?= \
	ftp://ftp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/ \
	ftp://ftp.jp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/ \
	ftp://ftp7.de.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/
