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

# Where to put distfiles that don't have any other master site
MASTER_SITE_LOCAL?= \
	ftp://ftp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/ \
	ftp://ftp.se.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/ \
	ftp://ftp.jp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/ \
	ftp://ftp.uk.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/ \
	ftp://ftp.ru.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/ \
	ftp://ftp.nectec.or.th/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/

MASTER_SITE_PORTS_JP+=	\
	ftp://ports.jp.FreeBSD.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/%SUBDIR%/ \
	ftp://ftp4.jp.FreeBSD.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/%SUBDIR%/ \
	ftp://ftp.ics.es.osaka-u.ac.jp/pub/mirrors/FreeBSD-jp/ports-jp/LOCAL_PORTS/%SUBDIR%/



##
##	KEEP THIS LIST SORTED
##

MASTER_SITE_AFTERSTEP+=	\
	ftp://ftp.afterstep.org/%SUBDIR%/ \
	ftp://ftp.digex.net/pub/X11/window-managers/afterstep/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/X11/AfterStep/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/X/AfterStep/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/X11/windowmanagers/afterstep/%SUBDIR%/

MASTER_SITE_COMP_SOURCES+=	\
	ftp://gatekeeper.dec.com/pub/usenet/comp.sources.%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/Unix/com.sources.%SUBDIR%/ \
	ftp://ftp.uu.net/usenet/comp.sources.%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/archive/comp.sources.%SUBDIR%/ \
	ftp://rtfm.mit.edu/pub/usenet/comp.sources.%SUBDIR%/

#
# FreeBSD mirror sites
#
# For the full list, see the Handbook:
#
#    http://www.FreeBSD.org/doc/en_US.ISO8859-1/books/handbook/mirrors-ftp.html
#
MASTER_SITE_FREEBSD_ORG+=	\
	ftp://ftp.FreeBSD.org/pub/FreeBSD/%SUBDIR%/ \
	ftp://ftp.se.FreeBSD.org/pub/FreeBSD/%SUBDIR%/ \
	ftp://ftp.jp.FreeBSD.org/pub/FreeBSD/%SUBDIR%/ \
	ftp://ftp.uk.FreeBSD.org/pub/FreeBSD/%SUBDIR%/ \
	ftp://ftp.ru.FreeBSD.org/pub/FreeBSD/%SUBDIR%/ \
	ftp://ftp.nectec.or.th/pub/FreeBSD/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,FreeBSD/&,}

MASTER_SITE_GNOME+=	\
	ftp://ftp.yggdrasil.com/mirrors/site/ftp.gnome.org/pub/GNOME/%SUBDIR%/ \
	ftp://ftp.rpmfind.net/linux/gnome.org/%SUBDIR%/ \
	ftp://ftp.cse.buffalo.edu/pub/Gnome/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/X11/GNOME/%SUBDIR%/ \
	ftp://ftp.dit.upm.es/linux/gnome/%SUBDIR%/ \
	ftp://ftp.tr.gnome.org/pub/GNOME/%SUBDIR%/ \
	ftp://ftp.no.gnome.org/pub/GNOME/%SUBDIR%/ \
	ftp://ftp.dataplus.se/pub/linux/gnome/%SUBDIR%/ \
	ftp://ftp.mirror.ac.uk/sites/ftp.gnome.org/pub/GNOME/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/X11/gnome/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,X/gnome/&,} \
	ftp://ftp.sourceforge.net/pub/mirrors/gnome/%SUBDIR%/

MASTER_SITE_GNU+=	\
	ftp://ftp.gnu.org/gnu/%SUBDIR%/ \
	ftp://gatekeeper.dec.com/pub/GNU/%SUBDIR%/ \
	ftp://ftp.uu.net/archive/systems/gnu/%SUBDIR%/ \
	ftp://ftp.de.uu.net/pub/gnu/%SUBDIR%/ \
	ftp://ftp.sourceforge.net/pub/mirrors/gnu/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/gnu/prep/%SUBDIR%/ \
	ftp://ftp.leo.org/pub/comp/os/unix/gnu/%SUBDIR%/ \
	ftp://ftp.digex.net/pub/gnu/%SUBDIR%/ \
	ftp://ftp.wustl.edu/systems/gnu/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/pub/gnu/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/gnu/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,GNU/&,} \
	ftp://ftp.shellhung.org/pub/gnu/%SUBDIR%/ \
	ftp://ftp.mirror.ac.uk/sites/ftp.gnu.org/pub/gnu/%SUBDIR%/ \
	ftp://sunsite.org.uk/Mirrors/ftp.gnu.org/pub/gnu/%SUBDIR%/

MASTER_SITE_KDE+=	\
	ftp://ftp.us.kde.org/pub/kde/%SUBDIR%/ \
	ftp://ftp.sourceforge.net/pub/mirrors/kde/%SUBDIR%/ \
	ftp://ftp.kde.org/pub/kde/%SUBDIR%/ \
	ftp://ftp.tuniv.szczecin.pl/pub/kde/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/X11/kde/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/X11/kde/%SUBDIR%/ \
	ftp://ftp.synesis.net/pub/mirrors/kde/%SUBDIR%/ \
	ftp://ftp.twoguys.org/pub/kde/%SUBDIR%/ \
	ftp://ftp.mirror.ac.uk/sites/ftp.kde.org/pub/kde/%SUBDIR%/ \
	ftp://ftp.dataplus.se/pub/linux/kde/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,X/kde/&,}

MASTER_SITE_MOZILLA+= \
	ftp://ftp.mozilla.org/pub/%SUBDIR%/ \
	ftp://sunsite.utk.edu/pub/netscape-source/%SUBDIR%/ \
	ftp://ftp.informatik.uni-bonn.de/pub/www/mozilla/%SUBDIR%/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.mozilla.org/pub/%SUBDIR%/ \
	ftp://sunsite.auc.dk/pub/mozilla/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/mirrors/ftp.mozilla.org/pub/%SUBDIR%/ \
	ftp://ftp.sunsite.kth.se/archive/www/ftp.mozilla.org/%SUBDIR%/ \
	ftp://ftp2.sinica.edu.tw/pub3/www/mozilla/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/WWW/mozilla/%SUBDIR%/ \
	ftp://ftp.is.co.za/networking/info-service/www/clients/netscape/mozilla/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/mozilla/&,}

MASTER_SITE_NETBSD+=	\
	ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.planix.com/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.iastate.edu/pub/netbsd/packages/distfiles/%SUBDIR%/ \
	ftp://netbsd.stevens-tech.edu/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://river.styx.org/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://gd.tuwien.ac.at/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://mirror.inet.tele.dk/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.unina.it/pub/Unix/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://gort.ludd.luth.se/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.sunsite.org.uk/Mirrors/ftp.netbsd.org/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.uk.netbsd.org/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,NetBSD/packages/distfiles/&,} \
	ftp://ftp.dti.ad.jp/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.tokyonet.ad.jp/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.sra.co.jp/pub/os/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://melanoma.cs.rmit.edu.au/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.nectec.or.th/pub/bsd-distributions/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/NetBSD/packages/distfiles/%SUBDIR%/

MASTER_SITE_PERL_CPAN+=	\
	ftp://gatekeeper.dec.com/pub/plan/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.cpan.org/pub/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.sourceforge.net/pub/mirrors/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/languages/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://bioinfo.weizmann.ac.il/pub/software/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://csociety-ftp.ecn.purdue.edu/pub/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/lang/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/lang/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.auckland.ac.nz/pub/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://mirror.hiwaay.net/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.isu.net.sa/pub/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.bora.net/pub/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://uiarchive.uiuc.edu/pub/ftp/ftp.cpan.org/pub/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.ucr.ac.cr/pub/Unix/CPAN/modules/by-module/%SUBDIR%/ \
	http://www.cpan.dk/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.cs.colorado.edu/pub/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://cpan.pop-mg.com.br/pub/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.is.co.za/programming/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/lang/perl/CPAN/modules/by-module/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,lang/perl/CPAN/modules/by-module/&,} \
	http://cpan.shellhung.org/modules/by-module/%SUBDIR%/ \
	ftp://ftp.mirror.ac.uk/sites/ftp.funet.fi/pub/languages/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://sunsite.org.uk/packages/perl/CPAN/modules/by-module/%SUBDIR%/

#
# RingServers in Japan
#
#
# Note: If you know which of the following RingServers is nearest to
# you, please specify it in your /etc/make.conf.
#
#	ring.etl.go.jp			ring.asahi-net.or.jp
#	ring.crl.go.jp			ring.astem.or.jp
#	ring.jah.ne.jp			ring.exp.fujixerox.co.jp
#	ring.so-net.ne.jp		ring.ip-kyoto.ad.jp
#	ring.iwate-pu.ac.jp		ring.shibaura-it.ac.jp
#	ring.ocn.ad.jp			ring.htcn.ne.jp
#	ring.omp.ad.jp			ring.jec.ad.jp
#	ring.tains.tohoku.ac.jp		ring.toyama-ix.net
#	ring.toyama-u.ac.jp		ring.edogawa-u.ac.jp
#	ring.data-hotel.net		ring.yamanashi.ac.jp
#	ring.nihon-u.ac.jp		ring.ctc.jp
#	ring.riken.go.jp		ring.hosei.ac.jp
#	ring.dcs.pref.mie.jp		ring.wakwak.com
#	ring.qgpop.net
#
# (The latest list is available at http://www.ring.gr.jp/)
#
# You can choose either http or ftp to access to a server:
#
#	http://<server>/archives/%SUBDIR%/
#	ftp://<server>/pub/%SUBDIR%/
#
MASTER_SITE_RINGSERVER+=	\
	ftp://ftp.dnsbalance.ring.gr.jp/pub/%SUBDIR%/ \
	http://www.dnsbalance.ring.gr.jp/archives/%SUBDIR%/

MASTER_SITE_RUBY+= \
	ftp://ftp.ruby-lang.org/pub/ruby/%SUBDIR%/ \
	ftp://fearless.ece.vill.edu/pub/ruby/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/unix/languages/ruby/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/lang/ruby/%SUBDIR%/ \
	ftp://ftp.TokyoNet.AD.JP/pub/misc/ruby/%SUBDIR%/ \
	ftp://ftp.iij.ad.jp/pub/lang/ruby/%SUBDIR%/ \
	ftp://ftp.krnet.ne.jp/pub/ruby/%SUBDIR%/ \
	ftp://mirror.nucba.ac.jp/mirror/ruby/%SUBDIR%/ \
	ftp://ftp.kr.FreeBSD.org/pub/ruby/%SUBDIR%/ \
	ftp://ftp.easynet.be/ruby/ruby/%SUBDIR%/

MASTER_SITE_SOURCEWARE+= \
	http://mirrors.rcn.net/pub/sourceware/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/mirrors/sourceware.cygnus.com/pub/%SUBDIR%/ \
	ftp://ftp.pvv.ntnu.no/pub/cygnus/sourceware.cygnus.com/%SUBDIR%/ \
	ftp://ftp1.sinica.edu.tw/pub3/CYGNUS/%SUBDIR%/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/sources.redhat.com/%SUBDIR%/ \
	ftp://gd.tuwien.ac.at/gnu/sourceware/%SUBDIR%/ \
	ftp://ftp.unina.it/pub/Unix/cygnus/%SUBDIR%/ \
	ftp://ftp.sdn.co.za/mirrors/sourceware.cygnus.com/pub/%SUBDIR%/ \
	http://sunsite.org.uk/Mirrors/sourceware.cygnus.com/pub/%SUBDIR%/ \
	ftp://unix.hensa.ac.uk/mirrors/sourceware.cygnus.com/pub/%SUBDIR%/ \
	ftp://mirrors.rcn.net/pub/sourceware/%SUBDIR%/ \
	ftp://sunsite.org.uk/Mirrors/sourceware.cygnus.com/pub/%SUBDIR%/

MASTER_SITE_SOURCEFORGE+= \
	http://prdownloads.sourceforge.net/%SUBDIR%/ \
	ftp://ftp3.sourceforge.net/pub/sourceforge/%SUBDIR%/ \
	http://ftp3.sourceforge.net/%SUBDIR%/ \
	ftp://ftp1.sourceforge.net/pub/sourceforge/%SUBDIR%/ \
	http://ftp1.sourceforge.net/%SUBDIR%/ \
	ftp://ftp2.sourceforge.net/pub/sourceforge/%SUBDIR%/ \
	http://ftp2.sourceforge.net/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/sourceforge/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/sourceforge/%SUBDIR%/ \
	http://telia.dl.sourceforge.net/%SUBDIR%/

MASTER_SITE_SUNSITE+=	\
	ftp://metalab.unc.edu/pub/Linux/%SUBDIR%/ \
	ftp://ftp.oit.unc.edu/pub/Linux/%SUBDIR%/ \
	http://www.ibiblio.org/pub/Linux/%SUBDIR%/ \
	ftp://ftp.sourceforge.net/pub/mirrors/metalab/Linux/%SUBDIR%/ \
	ftp://ftp.unicamp.br/pub/systems/Linux/%SUBDIR%/ \
	ftp://ftp.tuwien.ac.at/z3/opsys/linux/ibiblio/%SUBDIR%/ \
	ftp://ftp.univie.ac.at/systems/linux/metalab/%SUBDIR%/ \
	ftp://sunsite.cnlab-switch.ch/mirror/linux/sunsite/%SUBDIR%/ \
	ftp://ftp.cs.tu-berlin.de/pub/linux/Mirrors/sunsite.unc.edu/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/unix/linux/mirrors/sunsite.unc.edu/%SUBDIR%/ \
	ftp://ftp.uni-bremen.de/pub/mirrors/sunsite/%SUBDIR%/ \
	ftp://ftp.uni-jena.de/pub/linux/MIRROR.sunsite/%SUBDIR%/ \
	ftp://ftp.rz.uni-karlsruhe.de/pub/mirror/ftp.uni-tuebingen.de/pub/linux/mirrors/ftp.metalab.unc.edu/pub/Linux/%SUBDIR%/ \
	ftp://ftp.uni-magdeburg.de/pub/mirror/linux/ftp.metalab.unc.edu/%SUBDIR%/ \
	ftp://ftp.uni-stuttgart.de/pub/mirror/sunsite.unc.edu/pub/Linux/%SUBDIR%/ \
	ftp://ftp.rediris.es/software/linux/sunsite/%SUBDIR%/ \
	ftp://ftp.uniovi.es/pub1/linux/%SUBDIR%/ \
	ftp://ftp.lip6.fr/pub/linux/sunsite/%SUBDIR%/ \
	ftp://ftp.medasys-digital-systems.fr/pub1/linux/sunsite/%SUBDIR%/ \
	ftp://ftp.uvsq.fr/pub5/linux/sunsite/%SUBDIR%/ \
	ftp://ftp.leidenuniv.nl/pub/linux/sunsite/%SUBDIR%/ \
	ftp://ftp.nvg.ntnu.no/pub/mirrors/metalab.unc.edu/%SUBDIR%/ \
	ftp://ftp.icm.edu.pl/vol/rzm1/linux-sunsite/%SUBDIR%/ \
	ftp://ftp.man.poznan.pl/vols/vol1/sunsite/%SUBDIR%/ \
	ftp://ftp.pku.edu.cn/pub/linux/%SUBDIR%/ \
	ftp://ftp.cse.cuhk.edu.hk/pub4/Linux/%SUBDIR%/ \
	ftp://ftp.kobe-u.ac.jp/pub/Linux/metalab.unc.edu/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/Linux/metalab.unc.edu/%SUBDIR%/ \
	ftp://sunsite.sut.ac.jp/pub/archives/linux/sunsite-unc/%SUBDIR%/ \
	ftp://ftp.dacom.co.kr/pub/mirrors/metalab.unc.edu/Linux/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/Linux/mirrors/metalab/%SUBDIR%/ \
	ftp://sunsite.doc.ic.ac.uk/packages/linux/sunsite.unc-mirror/%SUBDIR%/ \
	ftp://ftp.nluug.nl/vol/3/metalab/%SUBDIR%/ \
	ftp://ftp.is.co.za/linux/sunsite/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/Linux/sunsite/%SUBDIR%/

MASTER_SITE_TCLTK+= \
	ftp://ftp.scriptics.com/pub/tcl/%SUBDIR%/ \
	ftp://mirror.neosoft.com/pub/tcl/mirror/ftp.scriptics.com/%SUBDIR%/ \
	ftp://sunsite.utk.edu/pub/tcl/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/languages/tcl/tcl/%SUBDIR%/ \
	ftp://ftp.uu.net/languages/tcl/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/lang/tcl/ftp.scriptics.com/%SUBDIR%/ \
	ftp://ftp.cs.tu-berlin.de/pub/tcl/distrib/%SUBDIR%/ \
	ftp://ftp.srcc.msu.su/mirror/ftp.scriptics.com/pub/tcl/%SUBDIR%/ \
	ftp://ftp.lip6.fr/pub/tcl/distrib/%SUBDIR%/ \
	ftp://ftp.mirror.ac.uk/sites/ftp.scriptics.com/pub/tcl/%SUBDIR%/ \
	ftp://sunsite.org.uk/Mirrors/ftp.scriptics.com/pub/tcl/%SUBDIR%/

MASTER_SITE_TEX_CTAN+=  \
	ftp://wuarchive.wustl.edu/packages/TeX/%SUBDIR%/  \
	ftp://ftp.funet.fi/pub/TeX/CTAN/%SUBDIR%/  \
	ftp://ctan.unsw.edu.au/tex-archive/%SUBDIR%/ \
	ftp://ftp.cise.ufl.edu/tex-archive/%SUBDIR%/ \
	ftp://ftp.tex.ac.uk/tex-archive/%SUBDIR%/  \
	ftp://ftp.kddlabs.co.jp/CTAN/%SUBDIR%/ \
	ftp://sunsite.auc.dk/pub/tex/ctan/%SUBDIR%/ \
	ftp://ctan.tug.org/tex-archive/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/TeX/CTAN/%SUBDIR%/ \
	ftp://ftp.dante.de/tex-archive/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,text/CTAN/&,}

MASTER_SITE_THEMES+= \
	ftp://ftp.themes.org/pub/themes/%SUBDIR%/ \
	ftp://ftp.tuwien.ac.at/opsys/linux/themes.org/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/X11/themes/%SUBDIR%/ \
	ftp://ftp.debian.org/pub/mirrors/themes.org/%SUBDIR%/

MASTER_SITE_WINDOWMAKER+= \
	ftp://ftp.windowmaker.org/pub/%SUBDIR%/ \
	ftp://ftp.goldweb.com.au/pub/WindowMaker/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/X11/window_managers/windowmaker/%SUBDIR%/ \
	ftp://ftp.ameth.org/pub/mirrors/ftp.windowmaker.org/%SUBDIR%/ \
	ftp://ftp.minet.net/pub/windowmaker/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/X11/windowmanagers/windowmaker/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/X/WindowMaker/%SUBDIR%/

MASTER_SITE_XCONTRIB+=	\
	ftp://crl.dec.com/pub/X11/contrib/%SUBDIR%/ \
	ftp://ftp.net.ohio-state.edu/disk/d/X11/contrib/%SUBDIR%/ \
	ftp://uiarchive.uiuc.edu/pub/ftp/ftp.x.org/contrib/%SUBDIR%/ \
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
	ftp://ftp.chg.ru/pub/X11/contrib/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,X/opengroup/contrib/&,} \
	ftp://ftp.mirror.ac.uk/sites/ftp.x.org/contrib/%SUBDIR%/ \
	ftp://sunsite.org.uk/Mirrors/ftp.x.org/contrib/%SUBDIR%/

MASTER_SITE_XEMACS+= \
	ftp://ftp.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs/%SUBDIR%/ \
	ftp://ftp.usyd.edu.au/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.lab.kdd.co.jp/xemacs/%SUBDIR%/ \
	ftp://ftp.th-darmstadt.de/pub/editors/xemacs/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,text/xemacs/&,}

MASTER_SITE_XFREE+= \
	ftp://ftp.xfree86.org/pub/XFree86/%SUBDIR%/source/ \
	ftp://ftp.lip6.fr/pub/X11/XFree86/XFree86-%SUBDIR%/source/ \
	ftp://ftp.cs.tu-berlin.de/pub/X/XFree86/%SUBDIR%/source/ \
	ftp://sunsite.doc.ic.ac.uk/packages/XFree86/%SUBDIR%/source/ \
	http://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.xfree86.org/XFree86/%SUBDIR%/source/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,XFree86/&/source,} \
	ftp://ftp.chg.ru/pub/XFree86/%SUBDIR%/source/
