# bsd.sites.mk - Popular master sites.
#
# This file does not have any designated maintainer, so feel free to
# commit to it yourself.  However, it is generally a good idea to
# notify the principal maintainer in case you have a change to one of
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
	ftp://ftp.uk.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/ \
	ftp://ftp.ru.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/ \
	ftp://ftp.jp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/ \
	ftp://ftp.tw.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/
#	ftp://ftp.nectec.or.th/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/

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

MASTER_SITE_FESTIVAL+= \
	http://www.festvox.org/packed/festival/%SUBDIR%/ \
	http://www.speech.cs.cmu.edu/festival/cstr/festival/%SUBDIR%/ \
	ftp://ftp.leb.net/pub/blinux/festival/mirror.festival_home/%SUBDIR%/ \
	ftp://ftp.mayn.de/pub/linux/BLinux/festival/mirror.festival_home/%SUBDIR%/ \
	ftp://ftp.tuwien.ac.at/opsys/linux/blinux/festival/mirror.festival_home/%SUBDIR%/

MASTER_SITE_FESTIVAL_OGI+= \
	ftp://ftp.leb.net/pub/blinux/festival/mirror.ogi-synth_home/ \
	ftp://ftp.mayn.de/pub/linux/BLinux/festival/mirror.ogi-synth_home/ \
	ftp://cslu.cse.ogi.edu/pub/tts/

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
	ftp://ftp.dti.ad.jp/pub/FreeBSD/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,FreeBSD/&,}

MASTER_SITE_GCC+=	\
	${MASTER_SITE_SOURCEWARE:S,%SUBDIR%,gcc/&,}  \
	ftp://gcc.gnu.org/pub/gcc/%SUBDIR%/ \
	ftp://ftp.iij.ad.jp/pub/gcc/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/lang/gcc/%SUBDIR%/

MASTER_SITE_GNOME+=	\
	ftp://archive.progeny.com/GNOME/%SUBDIR%/ \
	ftp://ftp.rpmfind.net/linux/gnome.org/%SUBDIR%/ \
	ftp://ftp.mirror.ac.uk/sites/ftp.gnome.org/pub/GNOME/%SUBDIR%/ \
	ftp://fr.rpmfind.net/linux/gnome.org/%SUBDIR%/ \
	ftp://ftp.linux.org.uk/mirrors/ftp.gnome.org/%SUBDIR%/ \
	ftp://ftp.dit.upm.es/linux/gnome/%SUBDIR%/ \
	ftp://ftp.dataplus.se/pub/linux/gnome/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/X11/gnome/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/pub/GNOME/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/X/gnome/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,X/gnome/&,} \
	ftp://ftp.tr.gnome.org/pub/GNOME/%SUBDIR%/ \
	ftp://ftp.cse.buffalo.edu/pub/Gnome/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/X11/GNOME/%SUBDIR%/ \
	ftp://ftp.no.gnome.org/pub/GNOME/%SUBDIR%/

MASTER_SITE_GNU+=	\
	ftp://ftp.gnu.org/gnu/%SUBDIR%/ \
	ftp://gatekeeper.dec.com/pub/GNU/%SUBDIR%/ \
	ftp://ftp.uu.net/archive/systems/gnu/%SUBDIR%/ \
	ftp://ftp.de.uu.net/pub/gnu/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/gnu/prep/%SUBDIR%/ \
	ftp://ftp.leo.org/pub/comp/os/unix/gnu/%SUBDIR%/ \
	ftp://ftp.digex.net/pub/gnu/%SUBDIR%/ \
	ftp://ftp.wustl.edu/mirrors/gnu/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/pub/gnu/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/GNU/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,GNU/&,} \
	ftp://ftp.mirror.ac.uk/sites/ftp.gnu.org/gnu/%SUBDIR%/ \
	ftp://sunsite.org.uk/Mirrors/ftp.gnu.org/pub/gnu/%SUBDIR%/ \
	ftp://ftp.informatik.hu-berlin.de/pub/gnu/%SUBDIR%/ \
	ftp://ftp.rediris.es/mirror/gnu/%SUBDIR%/ \
	ftp://ftp.lip6.fr/pub/gnu/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/gnu/%SUBDIR%/

MASTER_SITE_ISC+=	\
	ftp://ftp.isc.org/isc/%SUBDIR%/ \
	ftp://gd.tuwien.ac.at/infosys/servers/isc/%SUBDIR%/ \
	ftp://ftp.ciril.fr/pub/isc/%SUBDIR%/ \
	ftp://ftp.grolier.fr/pub/isc/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/mirrors/ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.freenet.de/pub/ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.fsn.hu/pub/isc/%SUBDIR%/ \
	ftp://ftp.kyushu-u.ac.jp/pub/Net/isc/%SUBDIR%/ \
	ftp://ftp.iij.ad.jp/pub/network/isc/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/net/isc/%SUBDIR%/ \
	ftp://ftp.u-aizu.ac.jp/pub/net/isc/%SUBDIR%/ \
	ftp://ftp.linux.lv/pub/software/isc/%SUBDIR%/ \
	ftp://ftp.task.gda.pl/mirror/ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.cdu.elektra.ru/pub/unix/isc/%SUBDIR%/ \
	ftp://ftp.si.uniovi.es/mirror/isc/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/network/isc/%SUBDIR%/ \
	ftp://ftp.chl.chalmers.se/pub/unix/network/isc/%SUBDIR%/ \
	ftp://unix.hensa.ac.uk/mirrors/ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.epix.net/pub/isc/%SUBDIR%/ \
	ftp://ftp.nominum.com/pub/isc/%SUBDIR%/ \
	ftp://ftp.nerdc.ufl.edu/pub/mirrors/ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.ripe.net/mirrors/sites/ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.nl.uu.net/pub/mirrors/ftp.isc.org/%SUBDIR%/ \
	ftp://ftp.pop-mg.com.br/pub/isc/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/net/isc/isc/%SUBDIR%/ \
	ftp://ftp.ulak.net.tr/pub/networking/isc/%SUBDIR%/ \
	ftp://ftp.metu.edu.tr/pub/mirrors/ftp.isc.org/%SUBDIR%/

MASTER_SITE_KDE+=	\
	ftp://ftp.us.kde.org/pub/kde/%SUBDIR%/ \
	ftp://ftp.kde.org/pub/kde/%SUBDIR%/ \
	http://linux.dsi.internet2.edu/X11/kde/%SUBDIR%/ \
	ftp://ftp.tuniv.szczecin.pl/pub/kde/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/X11/kde/%SUBDIR%/ \
	ftp://ftp.mirror.ac.uk/sites/ftp.kde.org/pub/kde/%SUBDIR%/ \
	ftp://ftp.dataplus.se/pub/linux/kde/%SUBDIR%/ \
	ftp://ftp.informatik.hu-berlin.de/pub/Mirrors/ftp.kde.org/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,X/kde/&,} \
	ftp://ftp.chg.ru/pub/X11/kde/%SUBDIR%/

MASTER_SITE_MOZILLA+= \
	http://download.mozilla.org/pub/%SUBDIR%/ \
	ftp://ftp.mozilla.org/pub/%SUBDIR%/ \
	ftp://sunsite.utk.edu/pub/netscape-source/%SUBDIR%/ \
	ftp://ftp.informatik.uni-bonn.de/pub/www/mozilla/%SUBDIR%/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.mozilla.org/pub/%SUBDIR%/ \
	ftp://sunsite.auc.dk/pub/mozilla/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/mirrors/ftp.mozilla.org/pub/%SUBDIR%/ \
	ftp://ftp.sunsite.kth.se/archive/www/ftp.mozilla.org/%SUBDIR%/ \
	ftp://ftp2.sinica.edu.tw/pub3/www/mozilla/%SUBDIR%/ \
	ftp://ftp.is.co.za/networking/info-service/www/clients/netscape/mozilla/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/mozilla/&,} \
	ftp://ftp.rediris.es/mirror/mozilla/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/WWW/mozilla/%SUBDIR%/

MASTER_SITE_NETBSD+=	\
	ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://gatekeeper.dec.com/pub/BSD/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.iastate.edu/pub/netbsd/packages/distfiles/%SUBDIR%/ \
	ftp://netbsd.stevens-tech.edu/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.plig.net/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://gd.tuwien.ac.at/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.bme.hu/OS/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.unina.it/pub/Unix/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.uninett.no/bsd/unix/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://sunsite.uio.no/bsd/unix/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://gort.ludd.luth.se/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.sunsite.org.uk/Mirrors/ftp.netbsd.org/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.demon.co.uk/pub/mirrors/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.uk.netbsd.org/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,NetBSD/packages/distfiles/&,} \
	ftp://ftp.dti.ad.jp/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.sra.co.jp/pub/os/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.iij.ad.jp/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.itjit.ne.jp/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://melanoma.cs.rmit.edu.au/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.nectec.or.th/pub/bsd-distributions/NetBSD/packages/distfiles/%SUBDIR%/

MASTER_SITE_NETSCAPE+= \
	ftp://ftp.ciril.fr/pub2/netscape/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/unix/network/www/netscape/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/www/Netscape/%SUBDIR%/ \
	ftp://ftp.uit.no/pub/www/Netscape/%SUBDIR%/ \
	ftp://ftp.uni-bielefeld.de/pub/netscape/%SUBDIR%/ \
	ftp://ftp.uniovi.es/pub/netscape/%SUBDIR%/ \
	ftp://sunsite.cnlab-switch.ch/mirror/netscape/%SUBDIR%/ \
	ftp://sunsite.tus.ac.jp/pub/archives/WWW/netscape/%SUBDIR%/ \
	ftp://ftp.mirror.ac.uk/sites/ftp.netscape.com/pub/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/www/Netscape/%SUBDIR%/ \
	ftp://ftp.fct.unl.pt/.1/Netscape/%SUBDIR%/ \
	ftp://sunsite.tut.fi/pub/Mirror/mirrorsite.netscape.com/pub/%SUBDIR%/ \
	ftp://sunfreeware.unam.mx/pub/Netscape/%SUBDIR%/ \
	ftp://ftp.fh-wolfenbuettel.de/pub/www/netscape/%SUBDIR%/ \
	ftp://ftp.cyf-kr.edu.pl/pub/mirror/netscape/%SUBDIR%/ \
	ftp://ftp.rz.uni-karlsruhe.de/pub/mirror/ftp.netscape.com/pub/%SUBDIR%/ \
	ftp://ftp.gftp.netscape.com/pub/%SUBDIR%/ \
	ftp://ftpnscp.newaol.com/pub/%SUBDIR%/ \
	ftp://ftp.hu-berlin.de/pub/www/netscape/%SUBDIR%/ \
	ftp://ftp.nsysu.edu.tw/Netscape/%SUBDIR%/ \
	ftp://ftp.uniroma2.it/%7bC/Netscape/%SUBDIR%/ \
	ftp://ftp.ut.ee/pub/WWW/netscape/%SUBDIR%/ \
	ftp://ftp.skynet.be/mirror2/netscape/%SUBDIR%/ \
	ftp://ftp.uni-bremen.de/pub/mirrors/ftp.netscape.com/pub/%SUBDIR%/ \
	ftp://ftp.informatik.rwth-aachen.de/pub/mirror/ftp.netscape.com/pub/%SUBDIR%/

MASTER_SITE_PERL_CPAN+=	\
	http://www.cpan.dk/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/languages/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.cpan.org/pub/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://uiarchive.uiuc.edu/pub/ftp/cpan.cse.msu.edu/modules/by-module/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,lang/perl/CPAN/modules/by-module/&,} \
	ftp://ftp.kddlabs.co.jp/lang/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/lang/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/lang/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://mirror.hiwaay.net/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.bora.net/pub/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.mirror.ac.uk/sites/ftp.funet.fi/pub/languages/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://bioinfo.weizmann.ac.il/pub/software/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://csociety-ftp.ecn.purdue.edu/pub/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.auckland.ac.nz/pub/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.isu.net.sa/pub/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.ucr.ac.cr/pub/Unix/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.cs.colorado.edu/pub/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://cpan.pop-mg.com.br/pub/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.is.co.za/programming/perl/CPAN/modules/by-module/%SUBDIR%/ \
	http://cpan.shellhung.org/modules/by-module/%SUBDIR%/ \
	ftp://sunsite.org.uk/packages/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/lang/perl/CPAN/modules/by-module/%SUBDIR%/

MASTER_SITE_REDHAT_LINUX+= \
	ftp://ftp.rutgers.edu/pub/redhat/linux/%SUBDIR%/ \
	ftp://ftp.redhat.com/redhat/linux/%SUBDIR%/ \
	ftp://ftp.nluug.nl/site/ftp.redhat.com/redhat/linux/%SUBDIR%/ \
	ftp://ftp.mirror.ac.uk/sites/ftp.redhat.com/pub/redhat/linux/%SUBDIR%/ \
	ftp://ftp.riken.go.jp/pub/Linux/redhat/releases/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/pub/Linux/packages/RedHat/redhat/linux/%SUBDIR%/

#
# RingServers in Japan
#
#
# Note: If you know which of the following RingServers is nearest to
# you, please specify it in your /etc/make.conf.
#
#	ring.airnet.ne.jp		ring.asahi-net.or.jp
#	ring.astem.or.jp		ring.atr.co.jp
#	ring.crl.go.jp			ring.csi.ad.jp
#	ring.data-hotel.net		ring.dcs.pref.mie.jp
#	ring.edogawa-u.ac.jp		ring.etl.go.jp
#	ring.exp.fujixerox.co.jp	ring.hosei.ac.jp
#	ring.htcn.ne.jp			ring.ip-kyoto.ad.jp
#	ring.iwate-pu.ac.jp		ring.jah.ne.jp
#	ring.k-opti.com			ring.nihon-u.ac.jp		
#	ring.ocn.ad.jp			ring.pwd.ne.jp
#	ring.qgpop.net			ring.riken.go.jp
#	ring.sbp-shimane.net		ring.shibaura-it.ac.jp
#	ring.shizuoka.ac.jp		ring.so-net.ne.jp
#	ring.tains.tohoku.ac.jp		ring.toyama-ix.net
#	ring.toyama-u.ac.jp		ring.wakwak.com
#	ring.yamanashi.ac.jp
#
# (The latest list is available at http://www.ring.gr.jp/)
#
# You can choose either http or ftp to access to a server:
#
#	http://<server>/archives/%SUBDIR%/
#	ftp://<server>/pub/%SUBDIR%/
#
# {www,ftp}.dnsbalance.ring.gr.jp redirects requests to one of the
# least busy servers at the moment at the DNS lookup level. (safe to
# use with "fetch -A")
#
# {www,ftp}.t.ring.gr.jp redirects requests to one of the nearest
# servers at the DNS lookup level. (safe to use with "fetch -A")
#
MASTER_SITE_RINGSERVER+=	\
	ftp://www.dnsbalance.ring.gr.jp/pub/%SUBDIR%/ \
	http://www.t.ring.gr.jp/archives/%SUBDIR%/

MASTER_SITE_RUBY+= \
	ftp://xyz.lcs.mit.edu/pub/ruby/%SUBDIR%/ \
	http://www.ibiblio.org/pub/languages/ruby/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,lang/ruby/&,} \
	ftp://ftp.iij.ad.jp/pub/lang/ruby/%SUBDIR%/ \
	ftp://ftp.ruby-lang.org/pub/ruby/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/unix/languages/ruby/%SUBDIR%/ \
	ftp://ftp.easynet.be/ruby/ruby/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/lang/ruby/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/lang/ruby/%SUBDIR%/ \
	ftp://ftp.kr.FreeBSD.org/pub/ruby/%SUBDIR%/ \
	http://mirrors.sunsite.dk/ruby/%SUBDIR%/ \
	ftp://ftp.iDaemons.org/pub/mirror/ftp.ruby-lang.org/ruby/%SUBDIR%/

MASTER_SITE_SOURCEFORGE+= \
	http://us.dl.sourceforge.net/%SUBDIR%/ \
	http://eu.dl.sourceforge.net/%SUBDIR%/ \
	ftp://us.dl.sourceforge.net/pub/sourceforge/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/sourceforge/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/sourceforge/%SUBDIR%/

MASTER_SITE_SOURCEWARE+= \
	http://mirrors.rcn.net/pub/sourceware/%SUBDIR%/ \
	ftp://mirrors.rcn.net/mirrors/sources.redhat.com/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/mirrors/sources.redhat.com/pub/%SUBDIR%/ \
	ftp://ftp.pvv.ntnu.no/pub/cygnus/sourceware.cygnus.com/%SUBDIR%/ \
	ftp://ftp1.sinica.edu.tw/pub3/CYGNUS/%SUBDIR%/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/sources.redhat.com/%SUBDIR%/ \
	ftp://gd.tuwien.ac.at/gnu/sourceware/%SUBDIR%/ \
	ftp://ftp.unina.it/pub/Unix/cygnus/%SUBDIR%/ \
	ftp://ftp.sdn.co.za/mirrors/sourceware.cygnus.com/pub/%SUBDIR%/ \
	http://sunsite.org.uk/Mirrors/sourceware.cygnus.com/pub/%SUBDIR%/ \
	ftp://unix.hensa.ac.uk/mirrors/sourceware.cygnus.com/pub/%SUBDIR%/ \
	ftp://sunsite.org.uk/Mirrors/sourceware.cygnus.com/pub/%SUBDIR%/

MASTER_SITE_SUNSITE+=	\
	http://www.ibiblio.org/pub/Linux/%SUBDIR%/ \
	http://linux.dsi.internet2.edu/%SUBDIR%/ \
	ftp://ftp.unicamp.br/pub/systems/Linux/%SUBDIR%/ \
	ftp://ftp.tuwien.ac.at/pub/linux/ibiblio/%SUBDIR%/ \
	ftp://sunsite.cnlab-switch.ch/mirror/linux/sunsite/%SUBDIR%/ \
	ftp://ftp.cs.tu-berlin.de/pub/linux/Mirrors/sunsite.unc.edu/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/unix/linux/mirrors/sunsite.unc.edu/%SUBDIR%/ \
	ftp://ftp.uni-jena.de/pub/linux/MIRROR.sunsite/%SUBDIR%/ \
	ftp://ftp.rz.uni-karlsruhe.de/pub/mirror/ftp.uni-tuebingen.de/pub/linux/mirrors/ftp.metalab.unc.edu/pub/Linux/%SUBDIR%/ \
	ftp://ftp.uni-magdeburg.de/pub/mirror/linux/ftp.metalab.unc.edu/%SUBDIR%/ \
	ftp://ftp.uni-stuttgart.de/pub/mirror/sunsite.unc.edu/pub/Linux/%SUBDIR%/ \
	ftp://ftp.informatik.rwth-aachen.de/pub/comp/Linux/sunsite.unc.edu/%SUBDIR%/ \
	ftp://ftp.lip6.fr/pub/linux/sunsite/%SUBDIR%/ \
	ftp://ftp.uvsq.fr/pub5/linux/sunsite/%SUBDIR%/ \
	ftp://ftp.leidenuniv.nl/pub/linux/sunsite/%SUBDIR%/ \
	ftp://ftp.nvg.ntnu.no/pub/mirrors/metalab.unc.edu/%SUBDIR%/ \
	ftp://ftp.icm.edu.pl/vol/rzm1/linux-sunsite/%SUBDIR%/ \
	ftp://ftp.pku.edu.cn/pub/linux/%SUBDIR%/ \
	ftp://ftp.cse.cuhk.edu.hk/pub4/Linux/%SUBDIR%/ \
	ftp://ftp.kobe-u.ac.jp/pub/Linux/metalab.unc.edu/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/Linux/metalab.unc.edu/%SUBDIR%/ \
	ftp://ftp.dacom.co.kr/pub/mirrors/metalab.unc.edu/Linux/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/Linux/mirrors/metalab/%SUBDIR%/ \
	ftp://sunsite.doc.ic.ac.uk/packages/linux/sunsite.unc-mirror/%SUBDIR%/ \
	ftp://ftp.is.co.za/linux/sunsite/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/Linux/sunsite/%SUBDIR%/

MASTER_SITE_TCLTK+= \
	ftp://ftp.scriptics.com/pub/tcl/%SUBDIR%/ \
	ftp://sunsite.utk.edu/pub/tcl/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/languages/tcl/tcl/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/lang/tcl/ftp.scriptics.com/%SUBDIR%/ \
	ftp://ftp.srcc.msu.su/mirror/ftp.scriptics.com/pub/tcl/%SUBDIR%/ \
	ftp://ftp.mirror.ac.uk/sites/ftp.scriptics.com/pub/tcl/%SUBDIR%/ \
	ftp://sunsite.org.uk/Mirrors/ftp.scriptics.com/pub/tcl/%SUBDIR%/

MASTER_SITE_TEX_CTAN+=  \
	ftp://wuarchive.wustl.edu/packages/TeX/%SUBDIR%/  \
	ftp://ftp.funet.fi/pub/TeX/CTAN/%SUBDIR%/  \
	ftp://ctan.unsw.edu.au/tex-archive/%SUBDIR%/ \
	ftp://ftp.cise.ufl.edu/tex-archive/%SUBDIR%/ \
	ftp://ftp.tex.ac.uk/tex-archive/%SUBDIR%/  \
	ftp://ftp.kddlabs.co.jp/CTAN/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/lang/CTAN/%SUBDIR%/ \
	ftp://sunsite.auc.dk/pub/tex/ctan/%SUBDIR%/ \
	ftp://ctan.tug.org/tex-archive/%SUBDIR%/ \
	ftp://ftp.dante.de/tex-archive/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,text/CTAN/&,} \
	ftp://ftp.chg.ru/pub/TeX/CTAN/%SUBDIR%/

MASTER_SITE_THEMES+= \
	ftp://ftp.themes.org/pub/themes/%SUBDIR%/ \
	ftp://ftp.tuwien.ac.at/opsys/linux/themes.org/%SUBDIR%/ \
	ftp://ftp.debian.org/pub/mirrors/themes.org/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/X11/themes/%SUBDIR%/

MASTER_SITE_WINDOWMAKER+= \
	ftp://ftp.windowmaker.org/pub/%SUBDIR%/ \
	ftp://ftp.goldweb.com.au/pub/WindowMaker/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/X11/window_managers/windowmaker/%SUBDIR%/ \
	ftp://ftp.ameth.org/pub/mirrors/ftp.windowmaker.org/%SUBDIR%/ \
	ftp://ftp.minet.net/pub/windowmaker/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/X/WindowMaker/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/X11/windowmanagers/windowmaker/%SUBDIR%/

MASTER_SITE_XCONTRIB+=	\
	ftp://crl.dec.com/pub/X11/contrib/%SUBDIR%/ \
	ftp://ftp.net.ohio-state.edu/disk/d/X11/contrib/%SUBDIR%/ \
	ftp://uiarchive.uiuc.edu/pub/ftp/ftp.x.org/contrib/%SUBDIR%/ \
	ftp://ftp.gwdg.de/pub/x11/x.org/contrib/%SUBDIR%/ \
	ftp://ftp.duke.edu/pub/X11/contrib/%SUBDIR%/ \
	ftp://ftp.x.org/contrib/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/X11/contrib/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/X/XFree86/X.Org/contrib/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/X11/contrib/%SUBDIR%/ \
	ftp://mirror.xmission.com/X/contrib/%SUBDIR%/ \
	ftp://ftp2.x.org/contrib/%SUBDIR%/ \
	ftp://sunsite.tus.ac.jp/pub/archives/X11/contrib/%SUBDIR%/ \
	ftp://ftp.is.co.za/x/contrib/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/X11/contrib/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,X/opengroup/contrib/&,} \
	ftp://ftp.mirror.ac.uk/sites/ftp.x.org/contrib/%SUBDIR%/ \
	ftp://ftp.dl.ac.uk/src/X/contrib/%SUBDIR%/ \
	ftp://sunsite.org.uk/Mirrors/ftp.x.org/contrib/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/X11/contrib/%SUBDIR%/

MASTER_SITE_XEMACS+= \
	ftp://ftp.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs/%SUBDIR%/ \
	ftp://ftp.usyd.edu.au/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.lab.kdd.co.jp/xemacs/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/unix/editor/xemacs/%SUBDIR%/ \
	ftp://ftp.th-darmstadt.de/pub/editors/xemacs/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,text/xemacs/&,}

MASTER_SITE_XFREE+= \
	ftp://ftp.xfree86.org/pub/XFree86/%SUBDIR%/source/ \
	ftp://ftp.rge.com/pub/X/XFree86/%SUBDIR%/source/ \
	ftp://archive.progeny.com/XFree86/%SUBDIR%/source/ \
	ftp://ftp.mirrorcentral.com/pub/XFree86/%SUBDIR%/source/ \
	ftp://ftp.dti.ad.jp/pub/X/XFree86/XFree86/%SUBDIR%/source/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,XFree86/&/source,} \
	ftp://gd.tuwien.Ac.at/hci/X11/XFree86/%SUBDIR%/source/ \
	ftp://ftp.fit.vutbr.cz/pub/XFree86/%SUBDIR%/source/ \
	ftp://ftp.free.fr/pub/XFree86/%SUBDIR%/source/ \
	ftp://mir1.ovh.net/ftp.xfree86.org/%SUBDIR%/source/ \
	ftp://ftp.lami.univ-evry.fr/XFree86/%SUBDIR%/source/ \
	ftp://ftp.cs.tu-berlin.de/pub/X/XFree86/%SUBDIR%/source/ \
	ftp://ftp.gwdg.de/pub/xfree86/XFree86/%SUBDIR%/source/ \
	http://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.xfree86.org/XFree86/%SUBDIR%/source/ \
	ftp://ftp.rediris.es/mirror/XFree86/%SUBDIR%/source/ \
	ftp://ftp.esat.net/pub/X11/XFree86/%SUBDIR%/source/ \
	ftp://ftp.nl.uu.net/pub/XFree86/%SUBDIR%/source/ \
	ftp://sunsite.uio.no/pub/XFree86/%SUBDIR%/source/ \
	ftp://ftp.task.gda.pl/pub/XFree86/%SUBDIR%/source/ \
	ftp://ftp.physics.uvt.ro/pub/XFree86/%SUBDIR%/source/ \
	ftp://ftp.chg.ru/pub/XFree86/%SUBDIR%/source/
