# bsd.sites.mk - Popular master sites.
#
# Sites_MAINTAINER=		ports@FreeBSD.org
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
MASTER_SITE_LOCAL+= \
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
	ftp://ftp.kddlabs.co.jp/X11/AfterStep/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/X/AfterStep/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/X11/windowmanagers/afterstep/%SUBDIR%/

MASTER_SITE_APACHE+=	\
	http://www.apache.org/dist/%SUBDIR%/ \
	http://archive.apache.org/dist/%SUBDIR%/ \
	ftp://gd.tuwien.ac.at/pub/infosys/servers/http/apache/dist/%SUBDIR%/ \
	ftp://ftp.planetmirror.com/pub/apache/dist/%SUBDIR%/ \
	ftp://ftp.pop-mg.com.br/pub/apache/dist/%SUBDIR%/ \
	ftp://ftp.gin.cz/pub/mirrors/www.apache.org/dist/%SUBDIR%/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.apache.org/dist/%SUBDIR%/ \
	ftp://ftp.apache.de/mirrors/dev.apache.org/dist/%SUBDIR%/ \
	ftp://ftp.cs.tu-berlin.de/pub/net/www/apache/%SUBDIR%/ \
	ftp://mir1.ovh.net/ftp.apache.org/dist/%SUBDIR%/ \
	ftp://ftp.forthnet.gr/pub/www/apache/dist/%SUBDIR%/ \
	ftp://sunsite.srce.hr/mirrors/ftp.apache.org/apache/dist/%SUBDIR%/ \
	ftp://xenia.sote.hu/pub/mirrors/www.apache.org/%SUBDIR%/ \
	ftp://ftp.esat.net/mirrors/ftp.apache.org/%SUBDIR%/ \
	ftp://ftp.heanet.ie/mirrors/www.apache.org/dist/%SUBDIR%/ \
	ftp://ftp.rhnet.is/pub/apache/%SUBDIR%/ \
	ftp://apache.theomnistore.com/mirror/apache/dist/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/apache/dist/&,} \
	ftp://ftp.sogang.ac.kr/www/apache/dist/%SUBDIR%/ \
	ftp://ftp.task.gda.pl/pub/www/apache/dist/%SUBDIR%/ \
	ftp://sunsite.icm.edu.pl/pub/www/apache/dist/%SUBDIR%/ \
	ftp://ftp.telepac.pt/pub/apache/dist/%SUBDIR%/ \
	ftp://ftp.kappa.ro/pub/mirrors/ftp.apache.org/dist/%SUBDIR%/ \
	ftp://apache.rinet.ru/pub/mirror/apache.org/dist/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/WWW/apache/dist/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/www/servers/apache/dist/%SUBDIR%/ \
	ftp://apache.mirrors.rossfell.co.uk/mirrors/apache/dist/%SUBDIR%/ \
	ftp://ftp.flirble.org/pub/web/apache/dist/%SUBDIR%/ \
	ftp://ftp.gbnet.net/pub/apache/dist/%SUBDIR%/ \
	ftp://ftp.plig.net/pub/apache/dist/%SUBDIR%/ \
	ftp://mirrors.rmplc.co.uk/pub/apache/dist/%SUBDIR%/ \
	ftp://apache.secsup.org/pub/apache/dist/%SUBDIR%/ \
	ftp://ftp.apache.inetcosmos.org/pub/apache/dist/%SUBDIR%/ \
	ftp://ftp.ccs.neu.edu/net/mirrors/Apache/dist/%SUBDIR%/ \
	ftp://ftp.epix.net/pub/apache/%SUBDIR%/ \
	ftp://ftp.rge.com/pub/infosystems/apache/%SUBDIR%/ \
	ftp://ftp.tux.org/pub/net/apache/dist/%SUBDIR%/ \
	ftp://ftp.saix.net/pub/apache/dist/%SUBDIR%/ \
	http://nagoya.apache.org/dist/mirror/%SUBDIR%/

MASTER_SITE_APACHE_HTTPD+=	\
	${MASTER_SITE_APACHE:S,%SUBDIR%,httpd/&,}

MASTER_SITE_APACHE_JAKARTA+=	\
	${MASTER_SITE_APACHE:S,%SUBDIR%,jakarta/&,}

MASTER_SITE_APACHE_XML+=	\
	${MASTER_SITE_APACHE:S,%SUBDIR%,xml/&,}

MASTER_SITE_COMP_SOURCES+=	\
	ftp://gatekeeper.dec.com/pub/usenet/comp.sources.%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/Unix/com.sources.%SUBDIR%/ \
	ftp://ftp.uu.net/usenet/comp.sources.%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/archive/comp.sources.%SUBDIR%/ \
	ftp://rtfm.mit.edu/pub/usenet/comp.sources.%SUBDIR%/

MASTER_SITE_DEBIAN+=	\
	http://www.gtlib.cc.gatech.edu/pub/debian/%SUBDIR%/ \
	ftp://ftp.us.debian.org/debian/%SUBDIR%/ \
	${MASTER_SITE_DEBIAN_NON_US:S,/debian-non-US/,/debian/,}

MASTER_SITE_DEBIAN_NON_US+=	\
	ftp://ftp.au.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.bg.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.cl.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.cz.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.de.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.dk.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.ee.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.es.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.fi.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.fr.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.hk.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.hr.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.hu.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.ie.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.is.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.it.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.jp.debian.org/debian-non-US/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,linux/debian/debian-non-US/&,} \
	ftp://ftp.nl.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.no.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.pl.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.ru.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.se.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.si.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.sk.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.uk.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.wa.au.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp2.de.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp2.it.debian.org/debian-non-US/%SUBDIR%/

MASTER_SITE_DEBIAN_POOL+=	\
	${MASTER_SITE_DEBIAN:C|(/%SUBDIR%/)|/pool/main/${PORTNAME:C/^(.).*$/\1/}/${PORTNAME}/|}

MASTER_SITE_ECLIPSE+= \
	http://download.eclipse.org/downloads/drops/%SUBDIR%/ \
	ftp://download.eclipse.org/%SUBDIR%/ \
	ftp://sunsite.informatik.rwth-aachen.de/pub/mirror/eclipse/%SUBDIR%/ \
	http://sunsite.informatik.rwth-aachen.de/eclipse/downloads/drops/%SUBDIR%/ \
	ftp://ftp.tu-clausthal.de/pub/eclipse/downloads/drops/%SUBDIR%/ \
	http://ftp-stud.fht-esslingen.de/pub/Mirrors/eclipse/%SUBDIR%/ \
	ftp://ftp.unixag-zw.fh-kl.de/pub/mirrors/eclipse/%SUBDIR%/ \
	http://eclipse.teccomm.les.inf.puc-rio.br/downloads/drops/%SUBDIR%/ \
	http://www.dawnspill.hu/mirror/eclipse/downloads/drops/%SUBDIR%/ \
	http://eclipse.ftp.heanet.ie/downloads/drops/%SUBDIR%/ \
	ftp://ftp.ibiblio.org/pub/packages/development/eclipse/eclipse/downloads/drops/%SUBDIR%/ \
	http://www.ibiblio.org/pub/packages/development/eclipse/eclipse/downloads/drops/%SUBDIR%/ \
	http://mirror.ini2.net/eclipse/%SUBDIR%/ \
	http://www.eclipse.ps.pl/downloads/drops/%SUBDIR%/ \
	http://eclipse.planetmirror.com/downloads/drops/%SUBDIR%/ \
	ftp://gd.tuwien.ac.at/softeng/eclipse/%SUBDIR%/ \
	http://gd.tuwien.ac.at/softeng/eclipse/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,misc/eclipse/downloads/drops/&,} \
	http://mirror.island.liu.se/eclipse/downloads/drops/%SUBDIR%/ \
	ftp://sunsite.cnlab-switch.ch/mirror/eclipse/downloads/drops/%SUBDIR%/ \
	ftp://eclipse.cis.sinica.edu.tw/eclipse.org/%SUBDIR%/ \
	http://eclipse.cis.sinica.edu.tw/downloads/drops/%SUBDIR%/ \
	http://www.binarycode.org/eclipse/%SUBDIR%/ \
	http://eclipse.get-software.com/%SUBDIR%/

MASTER_SITE_EXIM+=	\
	ftp://ftp.csx.cam.ac.uk/pub/software/email/exim/%SUBDIR%/ \
	ftp://ftp.exim.org/pub/exim/%SUBDIR%/ \
	http://public.planetmirror.com/pub/exim/%SUBDIR%/ \
	ftp://gd.tuwien.ac.at/infosys/mail/exim/%SUBDIR%/ \
	ftp://ftp.easynet.be/exim/%SUBDIR%/ \
	ftp://mirror.direct.ca/pub/exim/%SUBDIR%/ \
	ftp://mirror.kn.vutbr.cz/pub/ftp.exim.org/%SUBDIR%/ \
	ftp://sunsite.auc.dk/pub/mail/exim/%SUBDIR%/ \
	ftp://ftp.doc.cs.univ-paris8.fr/mirrors/ftp.exim.org/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/unix/mail/exim/%SUBDIR%/ \
	ftp://ftp.tin.org/pub/mail/exim/%SUBDIR%/ \
	ftp://ftp.freenet.de/pub/ftp.csx.cam.ac.uk/pub/software/email/exim/%SUBDIR%/ \
	ftp://ftp.esat.net/pub/networking/mail/mta/exim/%SUBDIR%/ \
	ftp://exim.stupendous.net/mirror/exim/%SUBDIR%/ \
	http://washitake.com/mail/exim/mirror/%SUBDIR%/ \
	http://exim.psshee.com/ftp/%SUBDIR%/ \
	ftp://ftp.nl.uu.net/pub/unix/mail/exim/%SUBDIR%/ \
	ftp://ftp.demon.nl/pub/mirrors/exim/%SUBDIR%/ \
	ftp://ftp.easynet.nl/mirror/exim/%SUBDIR%/ \
	ftp://sunsite.uio.no/pub/mail/exim/%SUBDIR%/ \
	http://www.no.exim.org/ftp/%SUBDIR%/ \
	http://sunsite.icm.edu.pl/pub/unix/mail/exim/%SUBDIR%/ \
	ftp://exim.directnet.ru/pub/exim/%SUBDIR%/ \
	ftp://ftp.is.co.za/networking/mail/mta/exim/%SUBDIR%/ \
	ftp://ftp.reaper.org/pub/exim/%SUBDIR%/ \
	ftp://sunsite.cnlab-switch.ch/mirror/exim/%SUBDIR%/ \
	http://www.mirror.ac.uk/sites/ftp.csx.cam.ac.uk/pub/software/email/exim/%SUBDIR%/ \
	ftp://ftp.demon.co.uk/pub/mirrors/exim/%SUBDIR%/ \
	http://www.us.exim.org/ftp/%SUBDIR%/ \
	http://exim.stanford.edu/ftp/pub/exim/%SUBDIR%/ \
	ftp://ftp.fsckit.net/pub/exim/%SUBDIR%/

MASTER_SITE_FEDORA_LINUX+= \
	http://download.fedora.us/%SUBDIR%/ \
	http://fedora.multikabel.nl/%SUBDIR%/ \
	ftp://ftp-stud.fht-esslingen.de/fedora/%SUBDIR%/ \
	http://mirrors.usc.edu/pub/linux/fedora/%SUBDIR%/ \
	http://mirrors.kernel.org/fedora.us/%SUBDIR%/ \
	http://sunsite.informatik.rwth-aachen.de/ftp/pub/Linux/%SUBDIR%/ \
	http://wftp.tu-chemnitz.de/pub/linux/%SUBDIR%/ \
	ftp://ftp.g-int.net/Mirrors/download.fedora.us/pub/%SUBDIR%/

MASTER_SITE_FESTIVAL+= \
	http://www.festvox.org/packed/festival/%SUBDIR%/ \
	http://www.speech.cs.cmu.edu/festival/cstr/festival/%SUBDIR%/ \
	ftp://ftp.leb.net/pub/blinux/festival/mirror.festival_home/%SUBDIR%/ \
	ftp://ftp.mayn.de/pub/linux/BLinux/festival/mirror.festival_home/%SUBDIR%/ \
	ftp://ftp.tuwien.ac.at/opsys/linux/blinux/festival/mirror.festival_home/%SUBDIR%/

MASTER_SITE_FESTIVAL_OGI+= \
	ftp://ftp.leb.net/pub/blinux/festival/mirror.ogi-synth_home/ \
	ftp://ftp.mayn.de/pub/linux/BLinux/festival/mirror.ogi-synth_home/ \
	ftp://ftp.tuwien.ac.at/opsys/linux/blinux/festival/mirror.ogi-synth_home/ \
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
	http://gcc.software-archive.net/%SUBDIR%/ \
	http://gcc.get-software.com/%SUBDIR%/ \
	http://www.binarycode.org/gcc/%SUBDIR%/ \
	ftp://gcc.gnu.org/pub/gcc/%SUBDIR%/ \
	ftp://mirrors.laffeycomputer.com/pub/gcc.gnu.org/pub/gcc/%SUBDIR%/ \
	ftp://ftp.lip6.fr/pub/gcc/%SUBDIR%/ \
	ftp://ftp.irisa.fr/pub/mirrors/gcc.gnu.org/gcc/%SUBDIR%/ \
	ftp://ftp.uvsq.fr/pub/gcc/%SUBDIR%/ \
	ftp://ftp.club-internet.fr/pub/gcc/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/unix/gnu/gcc/%SUBDIR%/ \
	ftp://ftp.gwdg.de/pub/misc/gcc/%SUBDIR%/ \
	ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/gcc.gnu.org/pub/gcc/%SUBDIR%/ \
	ftp://ftp.eos.hokudai.ac.jp/pub/gcc/%SUBDIR%/ \
	ftp://ftp.iij.ad.jp/pub/gcc/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/lang/gcc/%SUBDIR%/ \
	ftp://ring.aist.go.jp/pub/GNU/gcc/%SUBDIR%/ \
	ftp://ring.etl.go.jp/pub/lang/egcs/%SUBDIR%/ \
	ftp://ring.crl.go.jp/pub/GNU/gcc/%SUBDIR%/ \
	ftp://core.ring.gr.jp/pub/GNU/gcc/%SUBDIR%/ \
	ftp://ftp.ring.gr.jp/pub/GNU/gcc/%SUBDIR%/ \
	ftp://ftp.nluug.nl/mirror/languages/gcc%SUBDIR%/ \
	ftp://ftp.task.gda.pl/pub/gnu/gcc/%SUBDIR%/ \
	ftp://sunsite.icm.edu.pl/pub/gnu/gcc/%SUBDIR%/ \
	ftp://ftp.nctu.edu.tw/computer-languages/C/gcc/%SUBDIR%/ \
	ftp://ftp.mirror.ac.uk/sites/sources.redhat.com/pub/gcc/%SUBDIR%/ \
	ftp://ftp.softaplic.com.br/pub/sourceware/gcc/%SUBDIR%/ \
	ftp://linux.ihep.su/pub/cygnus/egcs/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/gnu/gcc/%SUBDIR%/ \
	ftp://mirror.aarnet.edu.au/pub/gcc/%SUBDIR%/ \
	ftp://linux.sarang.net/pub/mirror/gnu/gnu/gcc/%SUBDIR%/ \
	ftp://ftp.sun.ac.za/mirrorsites/sourceware.cygnus.com/pub/gcc/%SUBDIR%/

MASTER_SITE_GENTOO+=	\
	http://distro.ibiblio.org/pub/linux/distributions/gentoo/%SUBDIR%/ \
	http://csociety-ftp.ecn.purdue.edu/pub/gentoo/%SUBDIR%/ \
	http://gentoo.mirrors.pair.com/%SUBDIR%/ \
	http://gentoo.seren.com/gentoo/%SUBDIR%/ \
	http://gentoo.noved.org/%SUBDIR%/ \
	http://gentoo.chem.wisc.edu/gentoo/%SUBDIR%/ \
	http://adelie.polymtl.ca/%SUBDIR%/ \
	http://cudlug.cudenver.edu/gentoo/%SUBDIR%/ \
	http://gentoo.ccccom.com/%SUBDIR%/ \
	http://oss.redundant.com/pub/gentoo/%SUBDIR%/ \
	http://mirrors.tds.net/gentoo/%SUBDIR%/ \
	http://www.mirror.ac.uk/sites/www.ibiblio.org/gentoo/%SUBDIR%/ \
	http://ftp.gentoo.skynet.be/pub/gentoo/%SUBDIR%/ \
	http://ftp.belnet.be/mirror/rsync.gentoo.org/gentoo/%SUBDIR%/ \
	http://ftp.easynet.nl/mirror/gentoo/%SUBDIR%/ \
	http://ftp.snt.utwente.nl/pub/os/linux/gentoo/%SUBDIR%/ \
	http://gentoo.linux.no/%SUBDIR%/ \
	http://trumpetti.atm.tut.fi/gentoo/%SUBDIR%/ \
	http://ds.thn.htu.se/linux/gentoo/%SUBDIR%/ \
	http://mirror.pudas.net/gentoo/%SUBDIR%/ \
	http://sunsite.cnlab-switch.ch/ftp/mirror/gentoo/%SUBDIR%/ \
	http://www.fhh.opensource-mirror.de/gentoo.org/%SUBDIR%/ \
	http://linux.rz.ruhr-uni-bochum.de/download/gentoo-mirror/%SUBDIR%/ \
	http://mirrors.sec.informatik.tu-darmstadt.de/gentoo/%SUBDIR%/ \
	http://ftp.uni-erlangen.de/pub/mirrors/gentoo/%SUBDIR%/ \
	http://ftp6.uni-erlangen.de/pub/mirrors/gentoo/%SUBDIR%/ \
	http://darkstar.ist.utl.pt/gentoo/%SUBDIR%/ \
	http://ftp.caliu.info/pub/gentoo/%SUBDIR%/ \
	http://gentoo.inode.at/%SUBDIR%/ \
	http://ftp.rhnet.is/pub/gentoo/%SUBDIR%/ \
	http://gentoo.mirror.sdv.fr/%SUBDIR%/ \
	http://public.planetmirror.com/pub/gentoo/%SUBDIR%/ \
	http://www.zentek-international.com/mirrors/gentoo/%SUBDIR%/ \
	http://ftp.gentoo.or.kr/%SUBDIR%/ \
	http://mirror.gentoo.gr.jp/%SUBDIR%/ \
	http://gentoo.gg3.net/%SUBDIR%/ \
	http://gentoo.kems.net/%SUBDIR%/ \
	ftp://ftp.gtlib.cc.gatech.edu/pub/gentoo/%SUBDIR%/ \
	ftp://csociety-ftp.ecn.purdue.edu/pub/gentoo/%SUBDIR%/ \
	ftp://mirror.iawnet.sandia.gov/pub/gentoo/%SUBDIR%/ \
	ftp://ftp.ussg.iu.edu/pub/linux/gentoo/%SUBDIR%/ \
	ftp://ftp.ucsb.edu/pub/mirrors/linux/gentoo/%SUBDIR%/ \
	ftp://gentoo.mirrors.pair.com/%SUBDIR%/ \
	ftp://gentoo.noved.org/%SUBDIR%/ \
	ftp://cs.ubishops.ca/pub/gentoo/%SUBDIR%/ \
	ftp://sunsite.ualberta.ca/pub/unix/Linux/gentoo/%SUBDIR%/ \
	ftp://cudlug.cudenver.edu/pub/mirrors/distributions/gentoo/%SUBDIR%/ \
	ftp://gentoo.ccccom.com/%SUBDIR%/ \
	ftp://oss.redundant.com/pub/gentoo/%SUBDIR%/ \
	ftp://mirrors.tds.net/gentoo/%SUBDIR%/ \
	ftp://ftp.gentoo.skynet.be/pub/gentoo/%SUBDIR%/ \
	ftp://ftp.belnet.be/mirror/rsync.gentoo.org/gentoo/%SUBDIR%/ \
	ftp://ftp.easynet.nl/mirror/gentoo/%SUBDIR%/ \
	ftp://ftp.snt.utwente.nl/pub/os/linux/gentoo/%SUBDIR%/ \
	ftp://gentoo.linux.no/pub/gentoo/%SUBDIR%/ \
	ftp://ftp.uninett.no/pub/linux/Gentoo/%SUBDIR%/ \
	ftp://trumpetti.atm.tut.fi/gentoo/%SUBDIR%/ \
	ftp://mirror.pudas.net/gentoo/%SUBDIR%/ \
	ftp://sunsite.cnlab-switch.ch/mirror/gentoo/%SUBDIR%/ \
	ftp://ftp.join.uni-muenster.de/pub/linux/distributions/gentoo/%SUBDIR%/\
	ftp://ftp6.uni-muenster.de/pub/linux/distributions/gentoo/%SUBDIR%/ \
	ftp://ftp.ipv6.uni-muenster.de/pub/linux/distributions/gentoo/%SUBDIR%/\
	ftp://ftp.tu-clausthal.de/pub/linux/gentoo/%SUBDIR%/ \
	ftp://sunsite.informatik.rwth-aachen.de/pub/Linux/gentoo/%SUBDIR%/ \
	ftp://ftp.fhh.opensource-mirror.de/pub/gentoo.org/%SUBDIR%/ \
	ftp://linux.rz.ruhr-uni-bochum.de/gentoo-mirror/%SUBDIR%/ \
	ftp://ftp.uni-erlangen.de/pub/mirrors/gentoo/%SUBDIR%/ \
	ftp://ftp6.uni-erlangen.de/pub/mirrors/gentoo/%SUBDIR%/ \
	ftp://darkstar.ist.utl.pt/pub/gentoo/%SUBDIR%/ \
	ftp://ftp.caliu.info/pub/gentoo/%SUBDIR%/ \
	ftp://gentoo.inode.at/source/%SUBDIR%/ \
	ftp://ftp.rhnet.is/pub/gentoo/%SUBDIR%/ \
	ftp://files.gentoo.gr/%SUBDIR%/ \
	ftp://planetmirror.com/pub/gentoo/%SUBDIR%/ \
	ftp://gg3.net/pub/linux/gentoo/%SUBDIR%/ \
	ftp://ftp.ecc.u-tokyo.ac.jp/GENTOO/%SUBDIR%/ \
	ftp://gentoo.kems.net/pub/mirrors/gentoo/%SUBDIR%/

MASTER_SITE_GNOME+=	\
	http://www.gtlib.cc.gatech.edu/pub/gnome/%SUBDIR%/ \
	ftp://ftp.mirror.ac.uk/sites/ftp.gnome.org/pub/GNOME/%SUBDIR%/ \
	http://ftp.linux.org.uk/mirrors/ftp.gnome.org/%SUBDIR%/ \
	http://public.planetmirror.com/pub/GNOME/%SUBDIR%/ \
	ftp://ftp.dit.upm.es/linux/gnome/%SUBDIR%/ \
	ftp://ftp.dataplus.se/pub/linux/gnome/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/X11/gnome/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/pub/GNOME/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/X/gnome/%SUBDIR%/ \
	ftp://ftp.belnet.be/mirror/ftp.gnome.org/%SUBDIR%/ \
	ftp://ftp.no.gnome.org/pub/GNOME/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,X/gnome/&,} \
	http://archive.progeny.com/GNOME/%SUBDIR%/ \
	ftp://ftp.tuwien.ac.at/linux/gnome.org/%SUBDIR%/ \
	http://ftp.gnome.org/pub/GNOME/%SUBDIR%/

MASTER_SITE_GNU+=	\
	http://www.gtlib.cc.gatech.edu/pub/gnu/%SUBDIR%/ \
	ftp://ftp.gnu.org/gnu/%SUBDIR%/ \
	http://mirrors.usc.edu/pub/gnu/%SUBDIR%/ \
	ftp://gatekeeper.dec.com/pub/GNU/%SUBDIR%/ \
	ftp://ftp.de.uu.net/pub/gnu/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/gnu/prep/%SUBDIR%/ \
	ftp://ftp.leo.org/pub/comp/os/unix/gnu/%SUBDIR%/ \
	ftp://ftp.wustl.edu/mirrors/gnu/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/GNU/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/GNU/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,GNU/&,} \
	ftp://ftp.mirror.ac.uk/sites/ftp.gnu.org/gnu/%SUBDIR%/ \
	ftp://ftp.sunsite.org.uk/package/gnu/%SUBDIR%/ \
	ftp://ftp.informatik.hu-berlin.de/pub/gnu/%SUBDIR%/ \
	ftp://ftp.informatik.rwth-aachen.de/pub/mirror/ftp.gnu.org/pub/gnu/%SUBDIR%/ \
	ftp://ftp.rediris.es/sites/ftp.gnu.org/pub/%SUBDIR%/ \
	ftp://ftp.lip6.fr/pub/gnu/%SUBDIR%/ \
	ftp://ftp.tuwien.ac.at/linux/gnu/gnusrc/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/gnu/%SUBDIR%/

MASTER_SITE_GNUPG+= 	\
	ftp://gd.tuwien.ac.at/privacy/gnupg/%SUBDIR%/ \
	ftp://ftp.gnupg.org/gcrypt/%SUBDIR%/ \
	http://ftp.sunsite.dk/pub/security/gcrypt/%SUBDIR%/ \
	http://ftp.linux.it/pub/mirrors/gnupg/%SUBDIR%/ \
	ftp://ftp.demon.nl/pub/mirrors/gnupg/%SUBDIR%/ \
	ftp://ftp.ayamura.org/pub/gnupg/%SUBDIR%/ \
	ftp://sunsite.dk/pub/security/gcrypt/%SUBDIR%/ \
	ftp://ftp.jyu.fi/pub/crypt/gcrypt/%SUBDIR%/ \
	ftp://ftp.freenet.de/pub/ftp.gnupg.org/gcrypt/%SUBDIR%/ \
	ftp://ftp.surfnet.nl/pub/security/gnupg/%SUBDIR%/ \
	ftp://ftp.mirror.ac.uk/sites/ftp.gnupg.org/gcrypt/%SUBDIR%/ \
	ftp://sunsite.cnlab-switch.ch/mirror/gcrypt/%SUBDIR%/ \
	ftp://ftp.iasi.roedu.net/pub/mirrors/ftp.gnupg.org/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/gnupg/&,} \
	http://trumpetti.atm.tut.fi/gcrypt/%SUBDIR%/ \
	ftp://igloo.linux.gr/pub/crypto/gnupg/%SUBDIR%/

MASTER_SITE_GNU_ALPHA+=	\
	ftp://alpha.gnu.org/pub/gnu/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/mirrors/alpha.gnu.org/gnu/%SUBDIR%/ \
	ftp://ftp.lublin.pl/mirror/alpha.gnu.org/gnu/%SUBDIR%/ \
	ftp://ftp.ps.pl/mirrors/alpha.gnu.org/pub/gnu/%SUBDIR%/ \
	http://public.planetmirror.com/pub/gnu-alpha/%SUBDIR%/

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
	ftp://ftp.si.uniovi.es/mirror/isc/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/network/isc/%SUBDIR%/ \
	ftp://ftp.mirror.ac.uk/sites/ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.epix.net/pub/isc/%SUBDIR%/ \
	ftp://ftp.nominum.com/pub/isc/%SUBDIR%/ \
	ftp://ftp.nerdc.ufl.edu/pub/mirrors/ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.ripe.net/mirrors/sites/ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.nl.uu.net/pub/mirrors/ftp.isc.org/%SUBDIR%/ \
	ftp://ftp.pop-mg.com.br/pub/isc/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/net/isc/isc/%SUBDIR%/ \
	ftp://ftp.metu.edu.tr/pub/mirrors/ftp.isc.org/%SUBDIR%/

MASTER_SITE_KDE+=	\
	ftp://ftp.us.kde.org/pub/kde/%SUBDIR%/ \
	ftp://ftp.kde.org/pub/kde/%SUBDIR%/ \
	ftp://ibiblio.org/pub/packages/desktops/kde/%SUBDIR%/ \
	ftp://ftp.gtlib.cc.gatech.edu/pub/kde/%SUBDIR%/ \
	ftp://mirrors.midco.net/pub/kde/%SUBDIR%/ \
	ftp://ftp.oregonstate.edu/pub/kde/%SUBDIR%/ \
	ftp://download.uk.kde.org/pub/kde/%SUBDIR%/ \
	ftp://download.au.kde.org/pub/kde/%SUBDIR%/ \
	ftp://download.at.kde.org/pub/kde/%SUBDIR%/ \
	ftp://ftp.eu.uu.net/pub/kde/%SUBDIR%/ \
	ftp://ftp.tiscali.nl/pub/mirrors/kde/%SUBDIR%/ \
	ftp://ftp.roedu.net/pub/mirrors/ftp.kde.org/%SUBDIR%/ \
	ftp://ftp.rediris.es/mirror/kde/%SUBDIR%/ \
	ftp://ftp.du.se/pub/mirrors/kde/%SUBDIR%/ \
	ftp://download.tw.kde.org/pub/kde/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,X/kde/&,}

MASTER_SITE_MOZILLA+= \
	http://ftp.mozilla.org/pub/mozilla.org/%SUBDIR%/ \
	http://www.gtlib.cc.gatech.edu/pub/mozilla.org/%SUBDIR%/ \
	ftp://ftp.mozilla.org/pub/mozilla.org/%SUBDIR%/ \
	ftp://sunsite.utk.edu/pub/netscape-source/%SUBDIR%/ \
	ftp://ftp.informatik.uni-bonn.de/pub/www/mozilla/%SUBDIR%/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.mozilla.org/pub/%SUBDIR%/ \
	ftp://ftp.informatik.rwth-aachen.de/pub/mirror/ftp.mozilla.org/pub/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/mirrors/ftp.mozilla.org/pub/%SUBDIR%/ \
	ftp://ftp.sunsite.kth.se/mirrors/ftp.mozilla.org/%SUBDIR%/ \
	ftp://ftp2.sinica.edu.tw/pub3/www/mozilla/mozilla.org/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/mozilla/&,} \
	ftp://ftp.rediris.es/mirror/mozilla/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/WWW/mozilla/%SUBDIR%/

MASTER_SITE_NETBSD+=	\
	http://www.gtlib.cc.gatech.edu/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://gatekeeper.dec.com/pub/BSD/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.iastate.edu/pub/netbsd/packages/distfiles/%SUBDIR%/ \
	ftp://netbsd.stevens-tech.edu/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.plig.net/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
     ftp://ftp.proxad.net/mirrors/ftp.netbsd.org/packages/distfiles/%SUBDIR%/\
	ftp://ftp.weird.com/pub/NetBSD/distfiles/%SUBDIR%/ \
	ftp://gd.tuwien.ac.at/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/unix/NetBSD/packages/distfiles/%SUBDIR%/ \
     ftp://sunsite.rediris.es/sites/ftp.netbsd.org/packages/distfiles/%SUBDIR%/\
	ftp://ftp.funet.fi/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.duth.gr/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.bme.hu/OS/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.unina.it/pub/Unix/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.uninett.no/bsd/unix/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://sunsite.uio.no/bsd/unix/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.icm.edu.pl/vol/rzm9/NetBSD/packages/distfiles/%SUBDIR%/ \
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
	ftp://ftp.nihon-u.ac.jp/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.spin.ad.jp/.02/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://zoffy.asahi-net.or.jp/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://melanoma.cs.rmit.edu.au/pub/NetBSD/packages/distfiles/%SUBDIR%/

MASTER_SITE_NETSCAPE+= \
	ftp://ftp.ciril.fr/pub2/netscape/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/unix/network/www/netscape/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/www/Netscape/%SUBDIR%/ \
	ftp://ftp.uit.no/pub/www/Netscape/%SUBDIR%/ \
	ftp://ftp.uni-bielefeld.de/pub/netscape/%SUBDIR%/ \
	ftp://ftp.uniovi.es/pub/netscape/%SUBDIR%/ \
	ftp://sunsite.cnlab-switch.ch/mirror/netscape/%SUBDIR%/ \
	ftp://ftp.mirror.ac.uk/sites/ftp.netscape.com/pub/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/www/Netscape/%SUBDIR%/ \
	ftp://ftp.fct.unl.pt/pub/Netscape/%SUBDIR%/ \
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
	ftp://ftp.skynet.be/mirror/netscape/%SUBDIR%/ \
	ftp://ftp.uni-bremen.de/pub/mirrors/ftp.netscape.com/pub/%SUBDIR%/ \
	ftp://ftp.informatik.rwth-aachen.de/pub/mirror/ftp.netscape.com/pub/%SUBDIR%/

MASTER_SITE_PACKETSTORM+= \
	http://packetstormsecurity.nl/%SUBDIR%/ \
	http://packetstorm.troop218.org/%SUBDIR%/ \
	http://packetstorm.linuxsecurity.com/%SUBDIR%/ \
	http://packetstorm.touchpointmedia.com/%SUBDIR%/ \
	http://packetstorm.digital-network.net/%SUBDIR%/ \
	http://packetstorm.icx.fr/%SUBDIR%/ \
	http://packetstorm.security-guide.de/%SUBDIR%/ \
	http://packetstorm.trustica.cz/%SUBDIR%/ \
	http://packetstorm.dyn.org/%SUBDIR%/ \
	http://packetstorm.digitallinx.com/%SUBDIR%/ \
	http://packetstormsecurity.org.pk/%SUBDIR%/

MASTER_SITE_PERL_CPAN+=	\
	http://www.cpan.dk/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/languages/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.cpan.org/pub/CPAN/modules/by-module/%SUBDIR%/ \
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
	http://at.cpan.org/modules/by-module/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/lang/perl/CPAN/modules/by-module/%SUBDIR%/

#
# PostgreSQL mirror sites
#
# For the full list, see the following:
#
#	http://www.postgresql.org/mirrors-ftp.html
#
# Before update mirror list please consult with fenner's distfiles survey.
#
MASTER_SITE_PGSQL+= \
	ftp://ftp3.us.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp5.us.postgresql.org/pub/PostgreSQL/%SUBDIR%/ \
	ftp://ftp8.us.postgresql.org/pub/pgsql/%SUBDIR%/ \
	ftp://ftp9.us.postgresql.org/pub/mirrors/postgresql/%SUBDIR%/ \
	ftp://ftp10.us.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp13.us.postgresql.org/mirror/postgresql/%SUBDIR%/ \
	ftp://ftp15.us.postgresql.org/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,misc/db/postgresql/&,} \
	ftp://ftp.au.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp.at.postgresql.org/db/www.postgresql.org/pub/%SUBDIR%/ \
	ftp://ftp.be.postgresql.org/postgresql/%SUBDIR%/ \
	ftp://ftp.ba.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp.br.postgresql.org/pub/PostgreSQL/%SUBDIR%/ \
	ftp://ftp3.ca.postgresql.org/pub/%SUBDIR%/ \
	ftp://ftp.cl.postgresql.org/pub/GNU/pgsql/%SUBDIR%/ \
	ftp://ftp2.cr.postgresql.org/pub/Unix/postgres/%SUBDIR%/ \
	ftp://ftp.cz.postgresql.org/pub/ftp.postgresql.org/%SUBDIR%/ \
	ftp://ftp2.cz.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp.ee.postgresql.org/mirrors/postgresql/%SUBDIR%/ \
	ftp://ftp.fr.postgresql.org/%SUBDIR%/ \
	ftp://ftp2.fr.postgresql.org/postgresql/%SUBDIR%/ \
	ftp://ftp5.fr.postgresql.org/mirrors/postgresql/%SUBDIR%/ \
	ftp://ftp.de.postgresql.org/mirror/postgresql/%SUBDIR%/ \
	ftp://ftp2.de.postgresql.org/pub/comp/os/unix/database/postgresql/%SUBDIR%/ \
	ftp://ftp3.de.postgresql.org/pub/Mirrors/ftp.postgresql.org/%SUBDIR%/ \
	ftp://ftp4.de.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp.gr.postgresql.org/pub/databases/postgresql/%SUBDIR%/ \
	ftp://ftp.hk.postgresql.org/postgresql/%SUBDIR%/ \
	ftp://ftp2.is.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp.ie.postgresql.org/mirrors/ftp.postgresql.org/pub/%SUBDIR%/ \
	ftp://ftp2.ie.postgresql.org/mirrors/ftp.postgresql.org/%SUBDIR%/ \
	ftp://ftp2.it.postgresql.org/mirrors/postgres/%SUBDIR%/ \
	ftp://ftp3.it.postgresql.org/postgresql/%SUBDIR%/ \
	ftp://ftp.kr.postgresql.org/mirror/database/postgresql/%SUBDIR%/ \
	ftp://ftp.lv.postgresql.org/pub/software/postgresql/%SUBDIR%/ \
	ftp://ftp.nl.postgresql.org/pub/mirror/postgresql/%SUBDIR%/ \
	ftp://ftp.eu.postgresql.org/pub/unix/db/postgresql/%SUBDIR%/ \
	ftp://ftp2.nl.postgresql.org/mirror/postgresql/%SUBDIR%/ \
	ftp://ftp4.nl.postgresql.org/postgresql.zeelandnet.nl/%SUBDIR%/ \
	ftp://ftp.no.postgresql.org/pub/databases/postgresql/%SUBDIR%/ \
	ftp://ftp2.pl.postgresql.org/mirrors/ftp.postgresql.org/%SUBDIR%/ \
	ftp://ftp6.pl.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp7.pl.postgresql.org/pub/mirror/ftp.postgresql.org/%SUBDIR%/ \
	ftp://ftp.pt.postgresql.org/postgresql/%SUBDIR%/ \
	ftp://ftp6.ro.postgresql.org/pub/mirrors/ftp.postgresql.org/%SUBDIR%/ \
	ftp://ftp.ru.postgresql.org/pub/unix/database/pgsql/%SUBDIR%/ \
	ftp://ftp2.ru.postgresql.org/pub/databases/postgresql/%SUBDIR%/ \
	ftp://ftp3.ru.postgresql.org/pub/mirror/postgresql/pub/%SUBDIR%/ \
	ftp://ftp.za.postgresql.org/%SUBDIR%/ \
	ftp://ftp5.es.postgresql.org/mirror/postgresql/%SUBDIR%/ \
	ftp://ftp.se.postgresql.org/pub/databases/relational/postgresql/%SUBDIR%/ \
	ftp://ftp2.ch.postgresql.org/mirror/postgresql/%SUBDIR%/ \
	ftp://ftp.tw.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp3.tw.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp.tr.postgresql.org/pub/SQL/postgresql/%SUBDIR%/ \
	ftp://ftp.postgresql.org/pub/%SUBDIR%/

MASTER_SITE_PYTHON+= \
	http://www.python.org/%SUBDIR%/ \
	http://python.planetmirror.com/%SUBDIR%/ \
	http://python.ilisys.com.au/%SUBDIR%/ \
	http://gd.tuwien.ac.at/www.python.org/%SUBDIR%/ \
	http://ftp.easynet.be/python/%SUBDIR%/ \
	http://www.linux.org.hk/mirror/python/%SUBDIR%/ \
	http://mirrors.sunsite.dk/pythonwww/%SUBDIR%/ \
	http://python.emdia.fi/%SUBDIR%/ \
	http://python.via.ecp.fr/%SUBDIR%/ \
	http://SunSITE.Informatik.RWTH-Aachen.DE/python/%SUBDIR%/ \
	http://www.auth.gr/mirrors/python/%SUBDIR%/ \
	http://www.cwi.nl/www.python.org/%SUBDIR%/ \
	http://gnu.kookel.org/ftp/www.python.org/%SUBDIR%/ \
	http://python.holywar.net/%SUBDIR%/ \
	http://python.unam.mx/%SUBDIR%/ \
	http://python.cdpa.nsysu.edu.tw/%SUBDIR%/ \
	http://www.mirror.ac.uk/sites/ftp.python.org/pub/www.python.org/%SUBDIR%/ \
	http://python.mirrors.pair.com/%SUBDIR%/ \
	http://mirrors.ccs.neu.edu/Python/pub/www.python.org/%SUBDIR%/ \
	http://shattered.teched.net/www.python.org/%SUBDIR%/

MASTER_SITE_REDHAT_LINUX+= \
	http://mirrors.usc.edu/pub/linux/distributions/redhat/redhat/linux/%SUBDIR%/ \
	http://www.gtlib.cc.gatech.edu/pub/redhat/linux/%SUBDIR%/ \
	ftp://ftp.rutgers.edu/pub/redhat/linux/%SUBDIR%/ \
	ftp://ftp.uci.edu/mirrors/redhat/linux/%SUBDIR%/ \
	ftp://ftp.cso.uiuc.edu/mirrors/ftp/linux.aiss.uiuc.edu/pub/linux/redhat/linux/%SUBDIR%/ \
	ftp://mirror.cs.wisc.edu/pub/mirrors/linux/redhat/%SUBDIR%/ \
	ftp://ftp.redhat.com/pub/redhat/linux/%SUBDIR%/ \
     ftp://ftp.crc.ca/pub/systems/linux/redhat/ftp.redhat.com/linux/%SUBDIR%/ \
     ftp://ftp.univie.ac.at/systems/linux/ftp.redhat.com/redhat/linux/%SUBDIR%/\
	ftp://ftp.redhat.de/pub/redhat/linux/%SUBDIR%/ \
	ftp://ftp.lip6.fr/pub/linux/distributions/redhat/linux/%SUBDIR%/ \
	ftp://ftp.inet.it/pub/Linux/redhat/%SUBDIR%/ \
	ftp://ftp.nluug.nl/site/ftp.redhat.com/redhat/linux/%SUBDIR%/ \
	ftp://ftp.icm.edu.pl/vol/rzm9/linux-redhat/linux/%SUBDIR%/ \
	ftp://ftp.mirror.ac.uk/sites/ftp.redhat.com/pub/redhat/linux/%SUBDIR%/ \
     ftp://ftp.cs.nott.ac.uk/Mirrors/ftp.redhat.com/pub/redhat/linux/%SUBDIR%/ \
	ftp://ftp.carrier.kiev.ua/pub/Linux/RedHat/redhat/linux/%SUBDIR%/ \
	ftp://ftp.kobe-u.ac.jp/pub/Linux/packages/RedHat/redhat/linux/%SUBDIR%/\
	ftp://ftp.riken.go.jp/pub/Linux/redhat/releases/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/pub/Linux/packages/RedHat/redhat/linux/%SUBDIR%/ \
	ftp://ftp.cse.cuhk.edu.hk/pub2/redhat/%SUBDIR%/ \
	ftp://ftp.monash.edu.au/pub/linux/redhat/linux/%SUBDIR%/ \
	ftp://ftp2.compaq.com/pub/linux/RedHat/7.2-alpha/updates/rpms/alpha/ \
	ftp://alpha.crl.dec.com/pub/linux/redhat/7.2-alpha/updates/rpms/alpha/ \
	ftp://ftp.rz.uni-karlsruhe.de/pub/mirror/ftp.redhat.de/pub/redhat/updates/7.2/en/os/i386/

#
# RingServers in Japan
#
#
# Note: If you know which of the RingServers is nearest to you,
# please specify it in your /etc/make.conf. (The server list is
# available at http://www.ring.gr.jp/)
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
	ftp://www.t.ring.gr.jp/pub/%SUBDIR%/ \
	http://www.t.ring.gr.jp/archives/%SUBDIR%/

MASTER_SITE_RUBY+= \
	ftp://ftp.iij.ad.jp/pub/lang/ruby/%SUBDIR%/ \
	http://www.ibiblio.org/pub/languages/ruby/%SUBDIR%/ \
	ftp://xyz.lcs.mit.edu/pub/ruby/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,lang/ruby/&,} \
	ftp://ftp.ruby-lang.org/pub/ruby/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/unix/languages/ruby/%SUBDIR%/ \
	ftp://ftp.easynet.be/ruby/ruby/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/lang/ruby/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/lang/ruby/%SUBDIR%/ \
	ftp://ftp.kr.FreeBSD.org/pub/ruby/%SUBDIR%/ \
	http://mirrors.sunsite.dk/ruby/%SUBDIR%/ \
	ftp://ftp.iDaemons.org/pub/mirror/ftp.ruby-lang.org/ruby/%SUBDIR%/

MASTER_SITE_SAVANNAH+= \
	http://savannah.nongnu.org/download/%SUBDIR%/

MASTER_SITE_SOURCEFORGE+= \
	http://us.dl.sourceforge.net/%SUBDIR%/ \
	http://eu.dl.sourceforge.net/%SUBDIR%/ \
	ftp://us.dl.sourceforge.net/pub/sourceforge/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/sourceforge/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/sourceforge/%SUBDIR%/

MASTER_SITE_SOURCEFORGE_JP+= \
	http://osdn.dl.sourceforge.jp/%SUBDIR%/ \
	http://kyushu-u.dl.sourceforge.jp/%SUBDIR%/ \
	http://keihanna.dl.sourceforge.jp/%SUBDIR%/

MASTER_SITE_SOURCEWARE+= \
	http://mirrors.rcn.net/pub/sourceware/%SUBDIR%/ \
	ftp://mirrors.rcn.net/mirrors/sources.redhat.com/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/mirrors/sources.redhat.com/pub/%SUBDIR%/ \
	ftp://ftp1.sinica.edu.tw/pub3/GNU/CYGNUS/%SUBDIR%/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/sources.redhat.com/%SUBDIR%/ \
	ftp://gd.tuwien.ac.at/gnu/sourceware/%SUBDIR%/ \
	ftp://ftp.unina.it/pub/Unix/cygnus/%SUBDIR%/

MASTER_SITE_SUNSITE+=	\
	http://www.ibiblio.org/pub/Linux/%SUBDIR%/ \
	http://www.gtlib.cc.gatech.edu/pub/Linux/%SUBDIR%/ \
	ftp://ftp.tuwien.ac.at/pub/linux/ibiblio/%SUBDIR%/ \
	ftp://sunsite.cnlab-switch.ch/mirror/linux/sunsite/%SUBDIR%/ \
	ftp://ftp.cs.tu-berlin.de/pub/linux/Mirrors/sunsite.unc.edu/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/unix/linux/mirrors/sunsite.unc.edu/%SUBDIR%/ \
	ftp://ftp.uni-jena.de/pub/linux/MIRROR.sunsite/%SUBDIR%/ \
	ftp://ftp.rz.uni-karlsruhe.de/pub/mirror/ftp.uni-tuebingen.de/pub/linux/mirrors/ftp.metalab.unc.edu/pub/Linux/%SUBDIR%/ \
	ftp://ftp.uni-magdeburg.de/pub/mirror/linux/ftp.metalab.unc.edu/%SUBDIR%/ \
	ftp://ftp.uni-stuttgart.de/pub/mirror/sunsite.unc.edu/pub/Linux/%SUBDIR%/ \
	ftp://ftp.lip6.fr/pub/linux/sunsite/%SUBDIR%/ \
	ftp://ftp.nvg.ntnu.no/pub/mirrors/metalab.unc.edu/%SUBDIR%/ \
	ftp://ftp.icm.edu.pl/pub/Linux/sunsite/%SUBDIR%/ \
	ftp://ftp.cse.cuhk.edu.hk/pub4/Linux/%SUBDIR%/ \
	ftp://ftp.kobe-u.ac.jp/pub/Linux/metalab.unc.edu/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/Linux/metalab.unc.edu/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/Linux/sunsite/%SUBDIR%/

MASTER_SITE_TCLTK+= \
	ftp://ftp.scriptics.com/pub/tcl/%SUBDIR%/ \
	ftp://sunsite.utk.edu/pub/tcl/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/languages/tcl/tcl/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/lang/tcl/ftp.scriptics.com/%SUBDIR%/ \
	ftp://ftp.srcc.msu.su/mirror/ftp.scriptics.com/pub/tcl/%SUBDIR%/ \
	ftp://ftp.mirror.ac.uk/sites/ftp.scriptics.com/pub/tcl/%SUBDIR%/ \
	ftp://gd.tuwien.ac.at/languages/tcl/scriptics/%SUBDIR%/ \
	ftp://sunsite.org.uk/Mirrors/ftp.scriptics.com/pub/tcl/%SUBDIR%/

MASTER_SITE_TEX_CTAN+=  \
	ftp://ftp.funet.fi/pub/TeX/CTAN/%SUBDIR%/  \
	ftp://ctan.unsw.edu.au/tex-archive/%SUBDIR%/ \
	ftp://ftp.tex.ac.uk/tex-archive/%SUBDIR%/  \
	ftp://ftp.kddlabs.co.jp/CTAN/%SUBDIR%/ \
	ftp://ctan.tug.org/tex-archive/%SUBDIR%/ \
	ftp://ftp.dante.de/tex-archive/%SUBDIR%/ \
	ftp://gd.tuwien.ac.at/publishing/tex/CTAN/%SUBDIR%/ \
	ftp://ftp.ntnu.no/pub/tex/CTAN/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,text/CTAN/&,} \
	ftp://ftp.chg.ru/pub/TeX/CTAN/%SUBDIR%/

MASTER_SITE_THEMES+= \
	http://download.freshmeat.net/themes/%SUBDIR%/ \
	ftp://gd.tuwien.ac.at/opsys/linux/freshmeat/themes/%SUBDIR%/

MASTER_SITE_VIM+= \
	ftp://ftp.vim.org/pub/vim/unix/  \
	ftp://ftp.is.co.za/applications/editors/vim/unix/  \
	ftp://ftp.prz.tu-berlin.de/pub/unix/editors/vim/unix/  \
	ftp://ftp.mirror.ac.uk/sites/ftp.vim.org/pub/vim/unix/

MASTER_SITE_WINDOWMAKER+= \
	ftp://ftp.windowmaker.org/pub/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/X11/window_managers/windowmaker/%SUBDIR%/ \
	ftp://ftp.minet.net/pub/windowmaker/%SUBDIR%/ \
	ftp://gd.tuwien.ac.at/hci/windowmaker/%SUBDIR%/ \
	ftp://ftp.zcu.cz/pub/X11/windowmaker/%SUBDIR%/ \
	ftp://ftp.informatik.uni-hamburg.de/pub/soft/X/contrib/window_managers/windowmaker/%SUBDIR%/ \
	ftp://ftp.uvsq.fr/pub8/X11/window-managers/windowmaker/%SUBDIR%/ \
	ftp://ftp.maisel.int-evry.fr/pub/windowmaker/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/X/WindowMaker/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/X11/windowmanagers/windowmaker/%SUBDIR%/

MASTER_SITE_XCONTRIB+=	\
	ftp://ftp.net.ohio-state.edu/pub/X11/contrib/%SUBDIR%/ \
	ftp://ftp.gwdg.de/pub/x11/x.org/contrib/%SUBDIR%/ \
	ftp://ftp.duke.edu/pub/X11/contrib/%SUBDIR%/ \
	ftp://ftp.x.org/contrib/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/X11/contrib/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/X/XFree86/X.Org/contrib/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/X11/contrib/%SUBDIR%/ \
	ftp://mirror.xmission.com/X/contrib/%SUBDIR%/ \
	ftp://ftp2.x.org/contrib/%SUBDIR%/ \
	ftp://sunsite.tus.ac.jp/pub/archives/X11/contrib/%SUBDIR%/ \
	ftp://gd.tuwien.ac.at/hci/x.org/contrib/%SUBDIR%/ \
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
	ftp://gd.tuwien.ac.at/editors/xemacs/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,text/xemacs/&,}

MASTER_SITE_XFREE+= \
	http://www.gtlib.cc.gatech.edu/pub/XFree86/%SUBDIR%/source/ \
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

MASTER_SITE_GNUSTEP+= \
	http://python.planetmirror.com/pub/gnustep/gnustep/%SUBDIR%/ \
	ftp://ftp.gnustep.org/pub/gnustep/%SUBDIR%/ \
	ftp://ftp.easynet.nl/mirror/GNUstep/pub/gnustep/%SUBDIR%/ 

