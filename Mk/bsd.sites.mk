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
	ftp://ftp.duke.edu/pub/X11/contrib/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/X11/contrib/%SUBDIR%/ \
	ftp://sunsite.sut.ac.jp/pub/archives/X11/contrib/%SUBDIR%/

MASTER_SITE_GNU+=	\
	ftp://ftp.gnu.org/gnu/%SUBDIR%/ \
	ftp://ftp.freesoftware.com/pub/gnu/%SUBDIR%/ \
	ftp://ftp.digital.com/pub/GNU/%SUBDIR%/ \
	ftp://ftp.uu.net/archive/systems/gnu/%SUBDIR%/ \
	ftp://ftp.de.uu.net/pub/gnu/%SUBDIR%/ \
	ftp://ftp.ecrc.net/pub/gnu/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/gnu/prep/%SUBDIR%/ \
	ftp://ftp.leo.org/pub/comp/os/unix/gnu/%SUBDIR%/ \
	ftp://ftp.digex.net/pub/gnu/%SUBDIR%/ \
	ftp://ftp.wustl.edu/systems/gnu/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/pub/gnu/%SUBDIR%/

MASTER_SITE_PERL_CPAN+=	\
	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.freesoftware.com/pub/perl/CPAN/modules/by-module/%SUBDIR%/

MASTER_SITE_TEX_CTAN+=  \
	ftp://ftp.freesoftware.com/pub/tex/ctan/%SUBDIR%/  \
	ftp://wuarchive.wustl.edu/packages/TeX/%SUBDIR%/  \
	ftp://ftp.funet.fi/pub/TeX/CTAN/%SUBDIR%/  \
	ftp://ftp.tex.ac.uk/tex-archive/%SUBDIR%/  \
	ftp://ftp.dante.de/tex-archive/%SUBDIR%/

MASTER_SITE_SUNSITE+=	\
	ftp://metalab.unc.edu/pub/Linux/%SUBDIR%/ \
	ftp://ftp.infomagic.com/pub/mirrors/linux/sunsite/%SUBDIR%/ \
	ftp://ftp.freesoftware.com/pub/linux/sunsite/%SUBDIR%/

MASTER_SITE_KDE+=	\
	ftp://ftp.us.kde.org/pub/kde/%SUBDIR%/ \
	ftp://ftp.kde.org/pub/kde/%SUBDIR%/ \
	ftp://ftp.tuniv.szczecin.pl/pub/kde/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/pub/unix/X11/gui/kde/%SUBDIR%/ \
	ftp://ftp.dataplus.se/pub/linux/kde/%SUBDIR%/

MASTER_SITE_COMP_SOURCES+=	\
	ftp://gatekeeper.dec.com/pub/usenet/comp.sources.%SUBDIR%/ \
	ftp://ftp.uu.net/usenet/comp.sources.%SUBDIR%/ \
	ftp://rtfm.mit.edu/pub/usenet/comp.sources.%SUBDIR%/

MASTER_SITE_GNOME+=	\
	ftp://ftp.gnome.org/pub/GNOME/%SUBDIR%/ \
	ftp://download.sourceforge.net/pub/mirrors/gnome/%SUBDIR%/ \
	ftp://ftp.cybertrails.com/pub/gnome/%SUBDIR%/ \
	ftp://ftp.snoopy.net/pub/mirrors/GNOME/%SUBDIR%/

MASTER_SITE_AFTERSTEP+=	\
	ftp://ftp.afterstep.org/%SUBDIR%/ \
	ftp://ftp.digex.net/pub/X11/window-managers/afterstep/%SUBDIR%/ \
	ftp://ftp.alpha1.net/pub/mirrors/ftp.afterstep.org/%SUBDIR%/ \
	ftp://ftp.math.uni-bonn.de/pub/mirror/ftp.afterstep.org/pub/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/X/AfterStep/%SUBDIR%/ \
	ftp://casper.yz.yamagata-u.ac.jp/pub/X11/apps/afterstep/%SUBDIR%/

MASTER_SITE_WINDOWMAKER+= \
	ftp://ftp.windowmaker.org/pub/%SUBDIR%/ \
	ftp://ftp.goldweb.com.au/pub/WindowMaker/%SUBDIR%/ \
	ftp://ftp.io.com/pub/%SUBDIR%/ \
	ftp://ftp.ameth.org/pub/mirrors/ftp.windowmaker.org/%SUBDIR%/

MASTER_SITE_PORTS_JP+=	\
	ftp://ports.jp.FreeBSD.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/%SUBDIR%/ \
	ftp://ftp4.jp.FreeBSD.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/%SUBDIR%/ \
	ftp://ftp.ics.es.osaka-u.ac.jp/pub/mirrors/FreeBSD-jp/ports-jp/LOCAL_PORTS/%SUBDIR%/

MASTER_SITE_TCLTK+= \
	ftp://ftp.scriptics.com/pub/tcl/%SUBDIR%/ \
	ftp://mirror.neosoft.com/pub/tcl/mirror/ftp.scriptics.com/%SUBDIR%/ \
	ftp://sunsite.utk.edu/pub/tcl/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/languages/tcl/tcl/%SUBDIR%/ \
	ftp://ftp.cs.tu-berlin.de/pub/tcl/distrib/%SUBDIR%/ \
	ftp://ftp.srcc.msu.su/mirror/ftp.scriptics.com/pub/tcl/%SUBDIR%/ \
	ftp://ftp.lip6.fr/pub/tcl/distrib/%SUBDIR%/

MASTER_SITE_SOURCEFORGE+= \
	ftp://download.sourceforge.net/pub/sourceforge/%SUBDIR%/ \
	http://download.sourceforge.net/%SUBDIR%/

# Where to put distfiles that don't have any other master site
MASTER_SITE_LOCAL?= \
	ftp://ftp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/ \
	ftp://ftp.jp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/ \
	ftp://ftp7.de.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/
