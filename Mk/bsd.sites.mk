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
# Note: because it is included for all invocations, please keep the size
# of this file manageable.  If a distfile is unfetchable from the first
# few dozen locations, it is unlikely to be fetchable from any past that,
# and those fetch failures will simply waste time and bandwidth.  Please
# pick a globally representative subset.
#
# Note: all entries should terminate with a slash.
#
# $FreeBSD$
#

# Where to put distfiles that don't have any other master site
.if !defined(IGNORE_MASTER_SITE_LOCAL)
MASTER_SITE_LOCAL+= \
	ftp://ftp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/ \
	ftp://ftp.se.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/ \
	ftp://ftp.uk.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/ \
	ftp://ftp.ru.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/ \
	ftp://ftp.jp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/ \
	ftp://ftp.tw.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/ \
	ftp://ftp.cn.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/

MASTER_SITE_PORTS_JP+=	\
	ftp://ports.jp.FreeBSD.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/%SUBDIR%/ \
	ftp://ftp4.jp.FreeBSD.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/%SUBDIR%/ \
	ftp://ftp.ics.es.osaka-u.ac.jp/pub/mirrors/FreeBSD-jp/ports-jp/LOCAL_PORTS/%SUBDIR%/
.endif

##
##	KEEP THIS LIST SORTED
##

.if !defined(IGNORE_MASTER_SITE_AFTERSTEP)
MASTER_SITE_AFTERSTEP+=	\
	ftp://ftp.afterstep.org/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/X11/AfterStep/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/X/AfterStep/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/X11/windowmanagers/afterstep/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_APACHE)
MASTER_SITE_APACHE+=	\
	http://www.apache.org/dist/%SUBDIR%/ \
	http://archive.apache.org/dist/%SUBDIR%/ \
	ftp://ftp.pop-mg.com.br/data/apache/dist/%SUBDIR%/ \
	ftp://ftp.gin.cz/pub/mirrors/www.apache.org/dist/%SUBDIR%/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.apache.org/dist/%SUBDIR%/ \
	ftp://ftp.apache.de/mirrors/dev.apache.org/dist/%SUBDIR%/ \
	ftp://mir1.ovh.net/ftp.apache.org/dist/%SUBDIR%/ \
	ftp://ftp.forthnet.gr/pub/www/apache/%SUBDIR%/ \
	ftp://xenia.sote.hu/pub/mirrors/www.apache.org/%SUBDIR%/ \
	ftp://ftp.esat.net/mirrors/ftp.apache.org/%SUBDIR%/ \
	ftp://ftp.heanet.ie/mirrors/www.apache.org/dist/%SUBDIR%/ \
	ftp://ftp.rhnet.is/pub/apache/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/apache/&,} \
	ftp://ftp.sogang.ac.kr/www/apache/dist/%SUBDIR%/ \
	ftp://ftp.task.gda.pl/pub/www/apache/dist/%SUBDIR%/ \
	ftp://sunsite.icm.edu.pl/pub/www/apache/dist/%SUBDIR%/ \
	ftp://ftp.kappa.ro/pub/mirrors/ftp.apache.org/%SUBDIR%/ \
	ftp://apache.rinet.ru/pub/mirror/apache.org/dist/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/WWW/apache/dist/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/www/servers/apache/dist/%SUBDIR%/ \
	ftp://ftp.flirble.org/pub/web/apache/dist/%SUBDIR%/ \
	ftp://mirrors.rmplc.co.uk/pub/apache/%SUBDIR%/ \
	ftp://apache.secsup.org/pub/apache/dist/%SUBDIR%/ \
	ftp://ftp.ccs.neu.edu/net/mirrors/Apache/dist/%SUBDIR%/ \
	ftp://ftp.tux.org/pub/net/apache/dist/%SUBDIR%/ \
	ftp://ftp.saix.net/pub/apache/dist/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_APACHE_COMMONS_BINARIES)
MASTER_SITE_APACHE_COMMONS_BINARIES+=	\
	${MASTER_SITE_APACHE:S,%SUBDIR%,commons/&/binaries,}
.endif

.if !defined(IGNORE_MASTER_SITE_APACHE_COMMONS_SOURCE)
MASTER_SITE_APACHE_COMMONS_SOURCE+=	\
	${MASTER_SITE_APACHE:S,%SUBDIR%,commons/&/source,}
.endif

.if !defined(IGNORE_MASTER_SITE_APACHE_HTTPD)
MASTER_SITE_APACHE_HTTPD+=	\
	${MASTER_SITE_APACHE:S,%SUBDIR%,httpd/&,}
.endif

.if !defined(IGNORE_MASTER_SITE_APACHE_JAKARTA)
MASTER_SITE_APACHE_JAKARTA+=	\
	${MASTER_SITE_APACHE:S,%SUBDIR%,jakarta/&,}
.endif

.if !defined(IGNORE_MASTER_SITE_APACHE_TOMCAT)
MASTER_SITE_APACHE_TOMCAT+=	\
	${MASTER_SITE_APACHE:S,%SUBDIR%,tomcat/&,}
.endif

.if !defined(IGNORE_MASTER_SITE_APACHE_XML)
MASTER_SITE_APACHE_XML+=	\
	${MASTER_SITE_APACHE:S,%SUBDIR%,xml/&,}
.endif

.if !defined(IGNORE_MASTER_SITE_BERLIOS)
MASTER_SITE_BERLIOS+=	\
	http://download.berlios.de/%SUBDIR%/ \
	http://download2.berlios.de/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_CENKES)
MASTER_SITE_CENKES+=	\
	http://bsd.cenkes.org/%SUBDIR%/ \
	http://bsd2.cenkes.org/%SUBDIR%/ \
	http://bsd3.cenkes.org/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_CHEESESHOP)
MASTER_SITE_CHEESESHOP+=	\
	http://pypi.python.org/packages/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_COMP_SOURCES)
MASTER_SITE_COMP_SOURCES+=	\
	ftp://gatekeeper.dec.com/pub/usenet/comp.sources.%SUBDIR%/ \
	ftp://ftp.uu.net/usenet/comp.sources.%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_CRITICAL)
MASTER_SITE_CRITICAL+=	\
	http://critical.ch/distfiles/%SUBDIR%/ \
	http://energy.critical.ch/distfiles/%SUBDIR%/ \
	http://sauerkraut.critical.ch/distfiles/%SUBDIR%/ \
	http://snow.critical.ch/distfiles/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_CSME)
MASTER_SITE_CSME+=	${MASTER_SITE_CENKES}
.endif

.if !defined(IGNORE_MASTER_SITE_DEBIAN)
MASTER_SITE_DEBIAN+=	\
	http://www.gtlib.cc.gatech.edu/pub/debian/%SUBDIR%/ \
	ftp://ftp.us.debian.org/debian/%SUBDIR%/ \
	${MASTER_SITE_DEBIAN_NON_US:S,/debian-non-US/,/debian/,}
.endif

.if !defined(IGNORE_MASTER_SITE_DEBIAN_NON_US)
MASTER_SITE_DEBIAN_NON_US+=	\
	ftp://ftp.au.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.bg.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.cl.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.cz.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.de.debian.org/debian-non-US/%SUBDIR%/ \
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
	ftp://ftp2.de.debian.org/debian-non-US/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_DEBIAN_POOL)
MASTER_SITE_DEBIAN_POOL+=	\
	${MASTER_SITE_DEBIAN:C|(/%SUBDIR%/)|/pool/main/${PORTNAME:C/^(.).*$/\1/}/${PORTNAME}/|}
.endif

.if !defined(IGNORE_MASTER_SITE_EASYSW)
MASTER_SITE_EASYSW+=	\
	http://ftp.easysw.com/pub/%SUBDIR%/ \
	ftp://ftp.easysw.com/pub/%SUBDIR%/ \
	http://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/%SUBDIR%/ \
	ftp://ftp.rz.tu-bs.de/pub/mirror/ftp.easysw.com/ftp/pub/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_ECLIPSE)
MASTER_SITE_ECLIPSE+= \
	ftp://sunsite.informatik.rwth-aachen.de/pub/mirror/eclipse/%SUBDIR%/ \
	http://sunsite.informatik.rwth-aachen.de/eclipse/downloads/drops/%SUBDIR%/ \
	ftp://ftp.tu-clausthal.de/pub/eclipse/downloads/drops/%SUBDIR%/ \
	http://ftp-stud.fht-esslingen.de/pub/Mirrors/eclipse/%SUBDIR%/ \
	ftp://ftp.unixag-zw.fh-kl.de/pub/mirrors/eclipse/drops/%SUBDIR%/ \
	http://eclipse.teccomm.les.inf.puc-rio.br/downloads/drops/%SUBDIR%/ \
	http://www.dawnspill.hu/mirror/eclipse/downloads/drops/%SUBDIR%/ \
	http://mirrors.ibiblio.org/pub/mirrors/eclipse/eclipse/downloads/drops/%SUBDIR%/ \
	http://www.eclipse.ps.pl/downloads/drops/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,misc/eclipse/downloads/drops/&,} \
	ftp://sunsite.cnlab-switch.ch/mirror/eclipse/eclipse/downloads/drops/%SUBDIR%/ \
	http://download.eclipse.org/eclipse/downloads/drops/%SUBDIR%/ \
	ftp://download.eclipse.org/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_EXIM)
MASTER_SITE_EXIM+=	\
	ftp://ftp.csx.cam.ac.uk/pub/software/email/exim/%SUBDIR%/ \
	ftp://ftp.exim.org/pub/exim/%SUBDIR%/ \
	ftp://ftp.easynet.be/exim/exim/%SUBDIR%/ \
	ftp://mirror.kn.vutbr.cz/pub/ftp.exim.org/exim/%SUBDIR%/ \
	ftp://sunsite.auc.dk/pub/mail/exim/exim/%SUBDIR%/ \
	ftp://ftp.doc.cs.univ-paris8.fr/mirrors/ftp.exim.org/exim/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/unix/mail/exim/%SUBDIR%/ \
	ftp://ftp.tin.org/pub/mail/exim/%SUBDIR%/ \
	ftp://ftp.freenet.de/pub/ftp.csx.cam.ac.uk/pub/software/email/exim/%SUBDIR%/ \
	ftp://ftp.esat.net/pub/networking/mail/mta/exim/%SUBDIR%/ \
	http://washitake.com/mail/exim/mirror/exim/%SUBDIR%/ \
	http://exim.psshee.com/ftp/exim/%SUBDIR%/ \
	ftp://ftp.nl.uu.net/pub/unix/mail/exim/exim/%SUBDIR%/ \
	ftp://ftp.demon.nl/pub/mirrors/exim/%SUBDIR%/ \
	ftp://ftp.easynet.nl/mirror/exim/exim/%SUBDIR%/ \
	ftp://sunsite.uio.no/pub/mail/exim/exim/%SUBDIR%/ \
	http://www.no.exim.org/ftp/exim/%SUBDIR%/ \
	http://sunsite.icm.edu.pl/pub/unix/mail/exim/exim/%SUBDIR%/ \
	ftp://exim.directnet.ru/pub/exim/exim/%SUBDIR%/ \
	ftp://ftp.is.co.za/networking/mail/mta/exim/%SUBDIR%/ \
	ftp://ftp.reaper.org/pub/exim/exim/%SUBDIR%/ \
	ftp://sunsite.cnlab-switch.ch/mirror/exim/exim/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.csx.cam.ac.uk/pub/software/email/exim/%SUBDIR%/ \
	ftp://ftp.demon.co.uk/pub/mirrors/exim/%SUBDIR%/ \
	ftp://ftp.fsckit.net/pub/exim/exim/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_FEDORA_LINUX)
MASTER_SITE_FEDORA_LINUX+= \
        http://ftp.udl.es/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.udl.es/pub/fedora/linux/core/%SUBDIR%/ \
	http://archives.fedoraproject.org/pub/archive/fedora/linux/core/%SUBDIR%/ \
	http://mirrors.kernel.org/fedora/core/%SUBDIR%/ \
	ftp://mirrors.kernel.org/fedora/core/%SUBDIR%/ \
	http://mirror.web-ster.com/fedora/core/%SUBDIR%/ \
	ftp://mirror.web-ster.com/fedora/core/%SUBDIR%/ \
	http://rpmfind.net/linux/fedora/core/%SUBDIR%/ \
	ftp://rpmfind.net/linux/fedora/core/%SUBDIR%/ \
	ftp://ftp.gtlib.cc.gatech.edu/pub/fedora.redhat/linux/core/%SUBDIR%/ \
	ftp://fedora.mirrors.tds.net/pub/fedora-core/%SUBDIR%/ \
	http://ftp.ndlug.nd.edu/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.ndlug.nd.edu/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.belnet.be/linux/fedora/linux/core/%SUBDIR%/ \
	http://sunsite.mff.cuni.cz/pub/fedora/%SUBDIR%/ \
	ftp://sunsite.mff.cuni.cz/pub/fedora/%SUBDIR%/ \
	ftp://ultra.linux.cz/pub/fedora/%SUBDIR%/ \
	http://fr2.rpmfind.net/linux/fedora/core/%SUBDIR%/ \
	ftp://fr2.rpmfind.net/linux/fedora/core/%SUBDIR%/ \
	http://wftp.tu-chemnitz.de/pub/linux/fedora-core/%SUBDIR%/ \
	ftp://ftp.tu-chemnitz.de/pub/linux/fedora-core/%SUBDIR%/ \
	http://ftp.heanet.ie/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.heanet.ie/pub/fedora/linux/core/%SUBDIR%/ \
	http://ftp.esat.net/pub/linux/fedora/%SUBDIR%/ \
	ftp://ftp.esat.net/pub/linux/fedora/%SUBDIR%/ \
	ftp://alviss.et.tudelft.nl/pub/fedora/core/%SUBDIR%/ \
	http://ftp.surfnet.nl/ftp/pub/os/Linux/distr/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.surfnet.nl/pub/os/Linux/distr/fedora/linux/core/%SUBDIR%/ \
	http://ftp.nluug.nl/ftp/pub/os/Linux/distr/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.nluug.nl/pub/os/Linux/distr/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.uninett.no/pub/linux/Fedora/core/%SUBDIR%/ \
	http://ftp.man.poznan.pl/pub/linux/fedora/core/%SUBDIR%/ \
	ftp://ftp.man.poznan.pl/pub/linux/fedora/%SUBDIR%/ \
	http://ftp.ps.pl/pub/linux/fedora-core/%SUBDIR%/ \
	ftp://ftp.ps.pl/pub/linux/fedora-core/%SUBDIR%/ \
	ftp://ftp.kappa.ro/pub/Linux/Distributions/fedora/%SUBDIR%/ \
	http://mirror.etf.bg.ac.yu/fedora/%SUBDIR%/ \
	ftp://mirror.etf.bg.ac.yu/fedora/%SUBDIR%/ \
	http://www.mirrorservice.org/sites/download.fedora.redhat.com/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/download.fedora.redhat.com/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.hostrino.com/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.sfc.wide.ad.jp/pub/Linux/Fedora/core/%SUBDIR%/ \
	http://ftp.kddilabs.jp/Linux/packages/fedora/core/%SUBDIR%/ \
	ftp://ftp.kddilabs.jp/Linux/packages/fedora/core/%SUBDIR%/ \
	ftp://ftp.riken.go.jp/pub/Linux/fedora/core/%SUBDIR%/ \
	http://ftp.isu.edu.tw/pub/Linux/Fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.isu.edu.tw/pub/Linux/Fedora/linux/core/%SUBDIR%/ \
	http://www.las.ic.unicamp.br/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://www.las.ic.unicamp.br/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://mirror.netglobalis.net/pub/fedora/%SUBDIR%/ \
	http://mirror.pacific.net.au/linux/redhat/fedora/%SUBDIR%/ \
	ftp://mirror.pacific.net.au/linux/redhat/fedora/%SUBDIR%/ \
	http://download.fedora.redhat.com/pub/fedora/linux/core/%SUBDIR%/ \
	http://ftp.univie.ac.at/systems/linux/fedora/core/%SUBDIR%/ \
	http://mirror.aarnet.edu.au/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://mirror.aarnet.edu.au/pub/fedora/linux/core/%SUBDIR%/ \
	http://fedora.mirror.iweb.ca/core/%SUBDIR%/ \
	ftp://fedora.mirror.iweb.ca/core/%SUBDIR%/ \
	ftp://ftp.telus.net/pub/fedora/linux/core/%SUBDIR%/ \
	http://fedora.arcticnetwork.ca/linux/core/%SUBDIR%/ \
	http://www.muug.mb.ca/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.muug.mb.ca/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.solnet.ch/mirror/fedora/linux/core/%SUBDIR%/ \
	http://mirror.karneval.cz/pub/linux/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.telmexchile.cl/Unix/fedora/linux/core/%SUBDIR%/ \
	http://ftp.sh.cvut.cz/MIRRORS/fedora/%SUBDIR%/ \
	ftp://ftp.sh.cvut.cz/MIRRORS/fedora/%SUBDIR%/ \
	http://sunsite.mff.cuni.cz/MIRRORS/fedora.redhat.com/linux/core/%SUBDIR%/ \
	ftp://sunsite.mff.cuni.cz/MIRRORS/fedora.redhat.com/linux/core/%SUBDIR%/ \
	http://ftp-stud.hs-esslingen.de/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp-stud.hs-esslingen.de/pub/fedora/linux/core/%SUBDIR%/ \
	http://www.jur-linux.org/download/fedora/core/%SUBDIR%/ \
	http://ftp.uni-erlangen.de/pub/Linux/MIRROR.fedora/core/%SUBDIR%/ \
	ftp://ftp.uni-muenster.de/pub/linux/distributions/fedora/linux/core/%SUBDIR%/ \
	http://ftp.uni-bayreuth.de/linux/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.uni-bayreuth.de/pub/linux/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/linux/fedora/core/%SUBDIR%/ \
	http://ftp.uni-koeln.de/mirrors/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.uni-koeln.de/mirrors/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.informatik.uni-frankfurt.de/pub/linux/Mirror/ftp.redhat.com/fedora/core/%SUBDIR%/ \
	http://ftp.udl.es/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.udl.es/pub/fedora/linux/core/%SUBDIR%/ \
	http://mirrors.ircam.fr/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://mirrors.ircam.fr/pub/fedora/linux/core/%SUBDIR%/ \
	http://ftp.crihan.fr/mirrors/fedora.redhat.com/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.crihan.fr/mirrors/fedora.redhat.com/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.univ-pau.fr/pub/mirrors/fedora/%SUBDIR%/ \
	ftp://ftp.lip6.fr/pub/linux/distributions/fedora/%SUBDIR%/ \
	http://fr.rpmfind.net/linux/fedora/core/%SUBDIR%/ \
	http://zeniiia.linux.org.uk/pub/distributions/fedora/linux/core/%SUBDIR%/ \
	ftp://zeniiia.linux.org.uk/pub/distributions/fedora/linux/core/%SUBDIR%/ \
	http://www.gtlib.gatech.edu/pub/fedora.redhat/linux/core/%SUBDIR%/ \
	http://download.stmc.edu.hk/fedora/linux/core/%SUBDIR%/ \
	ftp://download.stmc.edu.hk/fedora/linux/core/%SUBDIR%/ \
	http://ftp.rhnet.is/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.rhnet.is/pub/fedora/linux/core/%SUBDIR%/ \
	http://ftp.unina.it/pub/linux/distributions/fedora/%SUBDIR%/ \
	ftp://ftp.unina.it/pub/linux/distributions/fedora/%SUBDIR%/ \
	http://ftp.iij.ad.jp/pub/linux/fedora/core/%SUBDIR%/ \
	ftp://ftp.iij.ad.jp/pub/linux/fedora/core/%SUBDIR%/ \
	http://ftp.dti.ad.jp/pub/Linux/Fedora/core/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/Linux/Fedora/core/%SUBDIR%/ \
	http://ftp.nara.wide.ad.jp/pub/Linux/fedora/core/%SUBDIR%/ \
	http://ftp.yz.yamagata-u.ac.jp/pub/linux/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.yz.yamagata-u.ac.jp/pub/linux/fedora/linux/core/%SUBDIR%/ \
	http://ftp.jaist.ac.jp/pub/Linux/Fedora/core/%SUBDIR%/ \
	ftp://ftp.jaist.ac.jp/pub/Linux/Fedora/core/%SUBDIR%/ \
	http://ftp.riken.jp/Linux/fedora/core/%SUBDIR%/ \
	http://ftp.kaist.ac.kr/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.kaist.ac.kr/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.kreonet.re.kr/pub/Linux/fedora/core/%SUBDIR%/ \
	ftp://mirror.hostway.co.kr/pub/fedora/%SUBDIR%/ \
	http://fedora.ifc.unam.mx/fedora/core/%SUBDIR%/ \
	ftp://fedora.ifc.unam.mx/linux/fedora/core/%SUBDIR%/ \
	ftp://ftp.easynet.nl/mirror/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.quicknet.nl/pub/Linux/download.fedora.redhat.com/core/%SUBDIR%/ \
	ftp://ftp.uib.no/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.tpnet.pl/d17/fedora/%SUBDIR%/ \
	http://ftp.wsisiz.edu.pl/pub/linux/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.pbone.net/pub/fedora/pub/fedora/linux/core/%SUBDIR%/ \
	http://ftp.pwr.wroc.pl/pub/linux/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.pwr.wroc.pl/pub/linux/fedora/linux/core/%SUBDIR%/ \
	ftp://mirrors.hpcf.upr.edu/pub/Mirrors/redhat/download.fedora.redhat.com/%SUBDIR%/ \
	http://ftp.astral.ro/mirrors/fedora/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.astral.ro/mirrors/fedora/pub/fedora/linux/core/%SUBDIR%/ \
	http://ftp.iasi.roedu.net/mirrors/fedora.redhat.com/fedora/%SUBDIR%/ \
	ftp://ftp.rdsor.ro/pub/Linux/Distributions/Fedora/%SUBDIR%/ \
	http://ftp.chg.ru/pub/Linux/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/Linux/fedora/linux/core/%SUBDIR%/ \
	http://ftp.rhd.ru/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.rhd.ru/pub/fedora/linux/core/%SUBDIR%/ \
	http://ftp.sunet.se/pub/Linux/distributions/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/Linux/distributions/fedora/linux/core/%SUBDIR%/ \
	http://ftp.port80.se/fedora/core/%SUBDIR%/ \
	ftp://ftp.port80.se/fedora/core/%SUBDIR%/ \
	http://ftp.upjs.sk/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.upjs.sk/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.tlk-l.net/pub/mirrors/fedora.redhat.com/linux/core/%SUBDIR%/ \
	http://limestone.uoregon.edu/ftp/fedora/%SUBDIR%/ \
	ftp://limestone.uoregon.edu/fedora/%SUBDIR%/ \
	http://mirrors.tiatera.com/fedora/core/%SUBDIR%/ \
	ftp://mirrors.tiatera.com/fedora/core/%SUBDIR%/ \
	ftp://fedora.bu.edu/core/%SUBDIR%/ \
	http://mirror.anl.gov/pub/fedora-linux-core/%SUBDIR%/ \
	ftp://mirror.anl.gov/pub/fedora-linux-core/%SUBDIR%/ \
	ftp://ftp.cse.buffalo.edu/pub/Linux/fedora/linux/core/%SUBDIR%/ \
	http://coblitz.planet-lab.org/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.software.umn.edu/linux/fedora/core/%SUBDIR%/ \
	http://fedora.omnispring.com/core/%SUBDIR%/ \
	ftp://fedora.omnispring.com/core/%SUBDIR%/ \
	ftp://ftp.applios.net/pub/fedora/linux/core/%SUBDIR%/ \
	http://fedora.mirror.facebook.com/linux/core/%SUBDIR%/ \
	http://mirror.steadfast.net/fedora/core/%SUBDIR%/ \
	http://mirror.eas.muohio.edu/fedora/linux/core/%SUBDIR%/ \
	http://mirror.engr.sjsu.edu/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://wuarchive.wustl.edu/pub/linux/distributions/fedora/%SUBDIR%/ \
	http://www.gtlib.gatech.edu/pub/fedora.redhat/linux/core/%SUBDIR%/ \
	ftp://ftp.gtlib.gatech.edu/pub/fedora.redhat/linux/core/%SUBDIR%/ \
	http://mirror.cogentco.com/pub/linux/fedora/linux/core/%SUBDIR%/ \
	http://mirrors.tummy.com/pub/fedora.redhat.com/fedora/linux/core/%SUBDIR%/ \
	ftp://mirrors.tummy.com/pub/fedora.redhat.com/fedora/linux/core/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_FESTIVAL)
MASTER_SITE_FESTIVAL+= \
	http://www.festvox.org/packed/festival/%SUBDIR%/ \
	http://www.cstr.ed.ac.uk/downloads/festival/%SUBDIR%/ \
	http://stuff.mit.edu/afs/sipb/project/speech-tools/src/festival/festvox.org/packed/festival/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_FESTIVAL_OGI)
MASTER_SITE_FESTIVAL_OGI+= \
	ftp://ftp.tuwien.ac.at/opsys/linux/blinux/festival/mirror.ogi-synth_home/ \
	http://www.cslu.ogi.edu/tts/download/data/
.endif

#
# FreeBSD mirror sites
#
# For the full list, see the Handbook:
#
#    http://www.FreeBSD.org/doc/en_US.ISO8859-1/books/handbook/mirrors-ftp.html
#
.if !defined(IGNORE_MASTER_SITE_FREEBSD_ORG)
MASTER_SITE_FREEBSD_ORG+=	\
	ftp://ftp.FreeBSD.org/pub/FreeBSD/%SUBDIR%/ \
	ftp://ftp.se.FreeBSD.org/pub/FreeBSD/%SUBDIR%/ \
	ftp://ftp.jp.FreeBSD.org/pub/FreeBSD/%SUBDIR%/ \
	ftp://ftp.uk.FreeBSD.org/pub/FreeBSD/%SUBDIR%/ \
	ftp://ftp.ru.FreeBSD.org/pub/FreeBSD/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/FreeBSD/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GCC)
MASTER_SITE_GCC+=	\
	${MASTER_SITE_SOURCEWARE:S,%SUBDIR%,gcc/&,}  \
	ftp://gcc.gnu.org/pub/gcc/%SUBDIR%/ \
	ftp://mirrors.laffeycomputer.com/pub/gcc.gnu.org/pub/gcc/%SUBDIR%/ \
	ftp://ftp.lip6.fr/pub/gcc/%SUBDIR%/ \
	ftp://ftp.irisa.fr/pub/mirrors/gcc.gnu.org/gcc/%SUBDIR%/ \
	ftp://ftp.uvsq.fr/pub/gcc/%SUBDIR%/ \
	ftp://ftp.gwdg.de/pub/misc/gcc/%SUBDIR%/ \
	ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/gcc.gnu.org/pub/gcc/%SUBDIR%/ \
	ftp://ftp.iij.ad.jp/pub/gcc/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/lang/gcc/%SUBDIR%/ \
	ftp://ftp.nluug.nl/mirror/languages/gcc/%SUBDIR%/ \
	ftp://ftp.nctu.edu.tw/computer-languages/C/gcc/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/sources.redhat.com/pub/gcc/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/gnu/gcc/%SUBDIR%/ \
	ftp://mirror.aarnet.edu.au/pub/gcc/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GENTOO)
MASTER_SITE_GENTOO+=	\
	http://ftp.roedu.net/pub/mirrors/gentoo.org/%SUBDIR%/ \
	http://distro.ibiblio.org/pub/linux/distributions/gentoo/%SUBDIR%/ \
	http://csociety-ftp.ecn.purdue.edu/pub/gentoo/%SUBDIR%/ \
	http://gentoo.mirrors.pair.com/%SUBDIR%/ \
	http://gentoo.chem.wisc.edu/gentoo/%SUBDIR%/ \
	http://adelie.polymtl.ca/%SUBDIR%/ \
	http://mirrors.tds.net/gentoo/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/www.ibiblio.org/gentoo/%SUBDIR%/ \
	http://ftp.belnet.be/mirror/rsync.gentoo.org/gentoo/%SUBDIR%/ \
	http://ftp.easynet.nl/mirror/gentoo/%SUBDIR%/ \
	http://ftp.snt.utwente.nl/pub/os/linux/gentoo/%SUBDIR%/ \
	http://trumpetti.atm.tut.fi/gentoo/%SUBDIR%/ \
	http://ds.thn.htu.se/linux/gentoo/%SUBDIR%/ \
	http://sunsite.cnlab-switch.ch/ftp/mirror/gentoo/%SUBDIR%/ \
	http://linux.rz.ruhr-uni-bochum.de/download/gentoo-mirror/%SUBDIR%/ \
	http://mirrors.sec.informatik.tu-darmstadt.de/gentoo/%SUBDIR%/ \
	http://ftp.uni-erlangen.de/pub/mirrors/gentoo/%SUBDIR%/ \
	http://darkstar.ist.utl.pt/gentoo/%SUBDIR%/ \
	http://gentoo.inode.at/%SUBDIR%/ \
	http://ftp.rhnet.is/pub/gentoo/%SUBDIR%/ \
	http://gentoo.mirror.sdv.fr/%SUBDIR%/ \
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
	ftp://mirrors.tds.net/gentoo/%SUBDIR%/ \
	ftp://ftp.belnet.be/mirror/rsync.gentoo.org/gentoo/%SUBDIR%/ \
	ftp://ftp.easynet.nl/mirror/gentoo/%SUBDIR%/ \
	ftp://ftp.snt.utwente.nl/pub/os/linux/gentoo/%SUBDIR%/ \
	ftp://trumpetti.atm.tut.fi/gentoo/%SUBDIR%/ \
	ftp://sunsite.cnlab-switch.ch/mirror/gentoo/%SUBDIR%/ \
	ftp://ftp.join.uni-muenster.de/pub/linux/distributions/gentoo/%SUBDIR%/\
	ftp://ftp6.uni-muenster.de/pub/linux/distributions/gentoo/%SUBDIR%/ \
	ftp://ftp.tu-clausthal.de/pub/linux/gentoo/%SUBDIR%/ \
	ftp://sunsite.informatik.rwth-aachen.de/pub/Linux/gentoo/%SUBDIR%/ \
	ftp://linux.rz.ruhr-uni-bochum.de/gentoo-mirror/%SUBDIR%/ \
	ftp://ftp.uni-erlangen.de/pub/mirrors/gentoo/%SUBDIR%/ \
	ftp://darkstar.ist.utl.pt/pub/gentoo/%SUBDIR%/ \
	ftp://gentoo.inode.at/source/%SUBDIR%/ \
	ftp://ftp.rhnet.is/pub/gentoo/%SUBDIR%/ \
	ftp://files.gentoo.gr/%SUBDIR%/ \
	ftp://ftp.ecc.u-tokyo.ac.jp/GENTOO/%SUBDIR%/ \
	ftp://gentoo.kems.net/pub/mirrors/gentoo/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GET_E)
MASTER_SITE_GET_E+=	\
	http://www0.get-e.org/%SUBDIR%/_files/ \
	http://www1.get-e.org/%SUBDIR%/_files/ \
	http://www2.get-e.org/%SUBDIR%/_files/ \
	http://www3.get-e.org/%SUBDIR%/_files/ \
	http://www4.get-e.org/%SUBDIR%/_files/ \
	http://www5.get-e.org/%SUBDIR%/_files/
.endif

.if !defined(IGNORE_MASTER_SITE_GNOME)
MASTER_SITE_GNOME+=	\
	ftp://ftp.belnet.be/mirror/ftp.gnome.org/%SUBDIR%/ \
	ftp://ftp.no.gnome.org/pub/GNOME/%SUBDIR%/ \
	ftp://ftp.dit.upm.es/linux/gnome/%SUBDIR%/ \
	http://ftp.acc.umu.se/pub/GNOME/%SUBDIR%/ \
	ftp://ftp.cse.buffalo.edu/pub/Gnome/%SUBDIR%/ \
	http://ftp.unina.it/pub/linux/GNOME/%SUBDIR%/ \
	http://fr2.rpmfind.net/linux/gnome.org/%SUBDIR%/ \
	http://www.gtlib.cc.gatech.edu/pub/gnome/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/X/gnome/%SUBDIR%/ \
	http://linorg.usp.br/gnome/%SUBDIR%/ \
	http://mirror.aarnet.edu.au/pub/GNOME/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,X/gnome/&,} \
	ftp://ftp.kddlabs.co.jp/pub/GNOME/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.gnome.org/pub/GNOME/%SUBDIR%/ \
	ftp://ftp.nara.wide.ad.jp/pub/X11/GNOME/%SUBDIR%/ \
	http://ftp.gnome.org/pub/GNOME/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GNU)
MASTER_SITE_GNU+=	\
	http://ftp.gnu.org/gnu/%SUBDIR%/ \
	ftp://ftp.gnu.org/gnu/%SUBDIR%/ \
	http://www.gtlib.cc.gatech.edu/pub/gnu/gnu/%SUBDIR%/ \
	http://mirrors.usc.edu/pub/gnu/%SUBDIR%/ \
	http://ftp.funet.fi/pub/gnu/prep/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/GNU/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/GNU/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,GNU/&,} \
	ftp://ftp.mirrorservice.org/sites/ftp.gnu.org/gnu/%SUBDIR%/ \
	ftp://ftp.sunsite.org.uk/package/gnu/%SUBDIR%/ \
	ftp://ftp.informatik.hu-berlin.de/pub/gnu/%SUBDIR%/ \
	ftp://ftp.informatik.rwth-aachen.de/pub/mirror/ftp.gnu.org/pub/gnu/%SUBDIR%/ \
	ftp://ftp.rediris.es/sites/ftp.gnu.org/ftp/gnu/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/gnu/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GNUPG)
MASTER_SITE_GNUPG+= 	\
	http://ftp.linux.it/pub/mirrors/gnupg/%SUBDIR%/ \
	ftp://ftp.demon.nl/pub/mirrors/gnupg/%SUBDIR%/ \
	ftp://sunsite.dk/pub/security/gcrypt/%SUBDIR%/ \
	ftp://ftp.jyu.fi/pub/crypt/gcrypt/%SUBDIR%/ \
	ftp://ftp.freenet.de/pub/ftp.gnupg.org/gcrypt/%SUBDIR%/ \
	ftp://ftp.surfnet.nl/pub/security/gnupg/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.gnupg.org/gcrypt/%SUBDIR%/ \
	ftp://sunsite.cnlab-switch.ch/mirror/gcrypt/%SUBDIR%/ \
	ftp://ftp.iasi.roedu.net/pub/mirrors/ftp.gnupg.org/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/gnupg/&,} \
	ftp://igloo.linux.gr/pub/crypto/gnupg/%SUBDIR%/ \
	ftp://ftp.gnupg.org/gcrypt/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GNUSTEP)
MASTER_SITE_GNUSTEP+= \
	ftp://ftp.gnustep.org/pub/gnustep/%SUBDIR%/ \
	ftp://ftp.easynet.nl/mirror/GNUstep/pub/gnustep/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GNUSTEP_CH)
MASTER_SITE_GNUSTEP_CH+= \
	http://io.debian.net/~tar/ports/distfiles/
.endif

.if !defined(IGNORE_MASTER_SITE_GNU_ALPHA)
MASTER_SITE_GNU_ALPHA+=	\
	ftp://alpha.gnu.org/pub/gnu/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/mirrors/alpha.gnu.org/gnu/%SUBDIR%/ \
	ftp://ftp.lublin.pl/mirror/alpha.gnu.org/gnu/%SUBDIR%/ \
	ftp://ftp.ps.pl/mirrors/alpha.gnu.org/pub/gnu/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GOOGLE_CODE)
.if defined(PROJECTHOST)
MASTER_SITE_GOOGLE_CODE+= \
	http://${PROJECTHOST}.googlecode.com/files/
.else
MASTER_SITE_GOOGLE_CODE+= \
	http://${PORTNAME}.googlecode.com/files/
.endif
.endif

.if !defined(IGNORE_MASTER_SITE_HORDE)
MASTER_SITE_HORDE+=	\
	http://ftp.horde.org/pub/%SUBDIR%/ \
	http://ftp.at.horde.org/mirror/horde/%SUBDIR%/ \
	ftp://ftp.horde.org/pub/%SUBDIR%/ \
	ftp://ftp.at.horde.org/mirror/horde/%SUBDIR%/ \
	ftp://ftp.it.horde.org/horde/pub/%SUBDIR%/ \
	ftp://ftp.es.horde.org/pub/%SUBDIR%/ \
	ftp://ftp.nl.horde.org/mirror/horde-ftp/pub/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_IDSOFTWARE)
MASTER_SITE_IDSOFTWARE+=	\
	ftp://ftp.chg.ru/pub/games/idgames/idstuff/%SUBDIR%/ \
	http://ftp4.de.freesbie.org/pub/misc/ftp.idsoftware.com/idstuff/%SUBDIR%/ \
	ftp://ftp.fasta.fh-dortmund.de/mirror/idstuff/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/pc/games/idgames/idstuff/%SUBDIR%/ \
	ftp://ftp.gamers.org/pub/idgames/idstuff/%SUBDIR%/ \
	http://ftp.iinet.net.au/games/idstuff/%SUBDIR%/ \
	ftp://ftp.mirror.nl/disk2/idsoftware/idstuff/%SUBDIR%/ \
	ftp://ftp.nsu.ru/mirrors/ftp.idsoftware.com/idstuff/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/vendors/idgames/idstuff/%SUBDIR%/ \
	ftp://ftp.omen.net.au/games/idstuff/%SUBDIR%/ \
	ftp://ftp.sunsite.org.uk/sites/ftp.idsoftware.com/idstuff/%SUBDIR%/ \
	ftp://ftp.idsoftware.com/idstuff/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_ISC)
MASTER_SITE_ISC+=	\
	ftp://ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.ciril.fr/pub/isc/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/mirrors/ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.freenet.de/pub/ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.iij.ad.jp/pub/network/isc/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/net/isc/%SUBDIR%/ \
	ftp://ftp.u-aizu.ac.jp/pub/net/isc/%SUBDIR%/ \
	ftp://ftp.task.gda.pl/mirror/ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.chl.chalmers.se/pub/isc/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/network/isc/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.epix.net/pub/isc/%SUBDIR%/ \
	ftp://ftp.nominum.com/pub/isc/%SUBDIR%/ \
	ftp://ftp.ripe.net/mirrors/sites/ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/net/isc/isc/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_KENAI)
MASTER_SITE_KENAI+=	\
	http://projectkenai.com/downloads/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_KDE)
MASTER_SITE_KDE+=	\
	http://mirrors.isc.org/pub/kde/%SUBDIR%/ \
	ftp://ftp.gtlib.cc.gatech.edu/pub/kde/%SUBDIR%/ \
	ftp://ftp.informatik.hu-berlin.de/pub/Mirrors/ftp.kde.org/%SUBDIR%/ \
	http://ftp.gtlib.cc.gatech.edu/pub/kde/%SUBDIR%/ \
	ftp://ftp.oregonstate.edu/pub/kde/%SUBDIR%/ \
	ftp://ftp.solnet.ch/mirror/KDE/%SUBDIR%/ \
	ftp://gd.tuwien.ac.at/kde/%SUBDIR%/ \
	http://gd.tuwien.ac.at/kde/%SUBDIR%/ \
	ftp://kde.mirrors.tds.net/pub/kde/%SUBDIR%/ \
	http://kde.mirrors.tds.net/pub/kde/%SUBDIR%/ \
	ftp://ftp.rz.uni-wuerzburg.de/pub/unix/kde/%SUBDIR%/ \
	http://mirrors.dotsrc.org/kde/%SUBDIR%/ \
	ftp://mirrors.dotsrc.org/kde/%SUBDIR%/ \
	ftp://ibiblio.org/pub/mirrors/kde/%SUBDIR%/ \
	http://ibiblio.org/pub/mirrors/kde/%SUBDIR%/ \
	http://kambing.vlsm.org/kde/%SUBDIR%/ \
	http://mirrors.evolva.ro/kdeftp/%SUBDIR%/ \
	ftp://ftp.iasi.roedu.net/pub/mirrors/ftp.kde.org/%SUBDIR%/ \
	ftp://ftp.fi.muni.cz/pub/kde/%SUBDIR%/ \
	http://ftp.fi.muni.cz/pub/kde/%SUBDIR%/ \
	ftp://ftp.tu-chemnitz.de/pub/X11/kde/%SUBDIR%/ \
	ftp://ftp.tuniv.szczecin.pl/pub/kde/%SUBDIR%/ \
	http://ftp.tuniv.szczecin.pl/pub/kde/%SUBDIR%/ \
	ftp://sunsite.icm.edu.pl/pub/unix/kde/%SUBDIR%/ \
	http://sunsite.icm.edu.pl/pub/unix/kde/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/kde/%SUBDIR%/ \
	http://ftp.sunet.se/pub/kde/%SUBDIR%/ \
	ftp://ftp.kde.org/pub/kde/%SUBDIR%/ \
	http://ftp.scarlet.be/pub/kde/%SUBDIR%/ \
	ftp://ftp.unina.it/pub/Linux/kde/%SUBDIR%/ \
	http://ftp.unina.it/pub/Linux/kde/%SUBDIR%/ \
	ftp://ftp.belnet.be/packages/kde/%SUBDIR%/ \
	ftp://ftp.gwdg.de/pub/x11/kde/%SUBDIR%/ \
	http://ftp.belnet.be/packages/kde/%SUBDIR%/ \
	ftp://ftp.lip6.fr/pub/X11/kde/%SUBDIR%/ \
	http://www-ftp.lip6.fr/pub/X11/kde/%SUBDIR%/ \
	ftp://ftp.rhnet.is/pub/kde/%SUBDIR%/ \
	http://ftp.rhnet.is/pub/kde/%SUBDIR%/ \
	http://ftp-stud.fht-esslingen.de/Mirrors/ftp.kde.org/pub/kde/%SUBDIR%/ \
	ftp://ftp.esat.net/mirrors/ftp.kde.org/pub/kde/%SUBDIR%/ \
	http://ftp.esat.net/mirrors/ftp.kde.org/pub/kde/%SUBDIR%/ \
	ftp://kde.paralax.org/kde/%SUBDIR%/ \
	ftp://ftp.cronyx.ru/pub/mirror/kde/%SUBDIR%/ \
	ftp://linux.cis.nctu.edu.tw/X/wm/kde/%SUBDIR%/ \
	ftp://ftp.na.kde.org/pub/kde/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/pub/unix/X11/gui/kde/%SUBDIR%/ \
	ftp://ftp.estpak.ee/pub/kde/%SUBDIR%/ \
	ftp://sunsite.informatik.rwth-aachen.de/pub/Linux/kde/%SUBDIR%/ \
	http://www.qtopia.org.cn/ftp/mirror/ftp.kde.org/%SUBDIR%/ \
	ftp://ftp.qtopia.org.cn/mirror/ftp.kde.org/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/X11/kde/%SUBDIR%/ \
	http://ftp.ntua.gr/pub/X11/kde/%SUBDIR%/ \
	ftp://ftp.hol.gr/pub/mirror/kde/%SUBDIR%/ \
	http://ftp.hol.gr/mirror/kde/%SUBDIR%/ \
	ftp://ftp.heanet.ie/mirrors/ftp.kde.org/%SUBDIR%/ \
	http://ftp.heanet.ie/mirrors/ftp.kde.org/%SUBDIR%/ \
	ftp://mi.mirror.garr.it/pub/mirrors/KDE/%SUBDIR%/ \
	http://mi.mirror.garr.it/mirrors/KDE/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/pub/X11/kde/%SUBDIR%/ \
	http://ftp.kddlabs.co.jp/pub/X11/kde/%SUBDIR%/ \
	ftp://ftp.informatik.uni-hamburg.de/pub/soft/X/contrib/kde/%SUBDIR%/ \
	ftp://ftp.no.kde.org/pub/kde/%SUBDIR%/ \
	ftp://ftp.yz.yamagata-u.ac.jp/pub/X11/wm/kde/%SUBDIR%/ \
	http://ftp.yz.yamagata-u.ac.jp/pub/X11/wm/kde/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/mirrors/ftp.kde.org/pub/kde/%SUBDIR%/ \
	http://ftp.funet.fi/pub/mirrors/ftp.kde.org/pub/kde/%SUBDIR%/ \
	ftp://ftp.ussg.iu.edu/pub/kde/%SUBDIR%/ \
	http://ftp.ussg.iu.edu/kde/%SUBDIR%/ \
	ftp://mirror.pacific.net.au/kde/%SUBDIR%/ \
	http://mirror.pacific.net.au/kde/%SUBDIR%/ \
	ftp://ftp.sayclub.com/pub/X/KDE/%SUBDIR%/ \
	http://ftp.sayclub.com/pub/X/KDE/%SUBDIR%/ \
	ftp://carroll.aset.psu.edu/pub/kde/%SUBDIR%/ \
	http://mirror.cc.columbia.edu/pub/software/kde/%SUBDIR%/ \
	ftp://fr2.rpmfind.net/linux/KDE/%SUBDIR%/ \
	http://fr2.rpmfind.net/linux/KDE/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/kde/%SUBDIR%/ \
	http://ftp.chg.ru/pub/kde/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.kde.org/pub/kde/%SUBDIR%/ \
	http://www.mirrorservice.org/sites/ftp.kde.org/pub/kde/%SUBDIR%/ \
	ftp://ftp.xcp.kiev.ua/ftp.kde.org/%SUBDIR%/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.kde.org/pub/kde/%SUBDIR%/ \
	http://ftp.gwdg.de/pub/x11/kde/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,X/kde/&,}
.endif

.if !defined(IGNORE_MASTER_SITE_LOGILAB)
MASTER_SITE_LOGILAB+=	\
	http://ftp.logilab.org/pub/%SUBDIR%/ \
	ftp://ftp.logilab.org/pub/%SUBDIR%/ \
	ftp://ftp.logilab.fr/pub/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_MOZDEV)
MASTER_SITE_MOZDEV+= \
	http://ftp.scarlet.be/pub/mozdev/%SUBDIR%/ \
	http://ftp.rz.tu-bs.de/pub/mirror/downloads.mozdev.org/%SUBDIR%/ \
	http://ftp.ntua.gr/pub/www/mozdev/%SUBDIR%/ \
	http://ftp.heanet.ie/pub/mozdev/%SUBDIR%/ \
	http://mozdev.oregonstate.edu/%SUBDIR%/ \
	http://ftp.ntua.gr/pub/www/mozdev/%SUBDIR%/ \
	http://www.devlib.org/mozdev/%SUBDIR%/ \
	http://mozdev.archive.hk/%SUBDIR%/ \
	http://ftp.iasi.roedu.net/mirrors/mozdev.org/%SUBDIR%/ \
	ftp://mozdev.secsup.org/pub/software/mozdev/%SUBDIR%/ \
	ftp://ftp.heanet.ie/pub/mozdev/%SUBDIR%/ \
	ftp://ftp.iasi.roedu.net/pub/mirrors/mozdev.org/%SUBDIR%/ \
	http://mirrors.ibiblio.org/pub/mirrors/mozdev.org/%SUBDIR%/ \
	http://ftp.osuosl.org/pub/mozdev/%SUBDIR%/
.endif

# releases.mozilla.org mirror sites
#
# For the full list, see the following:
#
#	http://www.mozilla.org/mirrors.html
#
.if !defined(IGNORE_MASTER_SITE_MOZILLA)
MASTER_SITE_MOZILLA+= \
	http://ftp.mozilla.org/pub/mozilla.org/%SUBDIR%/ \
	http://mirror3.mirrors.tds.net/pub/mozilla.org/%SUBDIR%/ \
	http://mozilla.isc.org/pub/mozilla.org/%SUBDIR%/ \
	http://releases.mozilla.org/pub/mozilla.org/%SUBDIR%/ \
	http://kyoto-mz-dl.sinet.ad.jp/pub/mozilla.org/%SUBDIR%/ \
	http://jp-nii01.mozilla.org/pub/mozilla.org/%SUBDIR%/ \
	http://jp-nii02.mozilla.org/pub/mozilla.org/%SUBDIR%/ \
	http://mozilla.mtk.nao.ac.jp/pub/mozilla.org/%SUBDIR%/ \
	http://mirror.internode.on.net/pub/mozilla/%SUBDIR%/ \
	http://ftp.acc.umu.se/pub/mozilla.org/%SUBDIR%/ \
	http://mozilla.c3sl.ufpr.br/releases/%SUBDIR%/ \
	http://www.gtlib.cc.gatech.edu/pub/mozilla.org/%SUBDIR%/ \
	ftp://ftp.mozilla.org/pub/mozilla.org/%SUBDIR%/ \
	ftp://ftp.fh-wolfenbuettel.de/pub/www/mozilla/%SUBDIR%/ \
	ftp://ftp.informatik.rwth-aachen.de/pub/mirror/ftp.mozilla.org/pub/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/mozilla/&,} \
	ftp://ftp.kaist.ac.kr/pub/mozilla/%SUBDIR%/ \
	ftp://mozilla.mirror.pacific.net.au/mozilla/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/WWW/mozilla/%SUBDIR%/ \
	http://ftp.twaren.net/Unix/Mozilla/%SUBDIR%/ \
	http://ftp.isu.edu.tw/pub/Mozilla/%SUBDIR%/ \
	http://ftp.ntu.edu.tw/pub/mozilla/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_MOZILLA_EXTENDED)
MASTER_SITE_MOZILLA_EXTENDED+=	\
	http://releases.mozilla.org/pub/mozilla.org/%SUBDIR%/ \
	${MASTER_SITE_MOZILLA}
.endif

.if !defined(IGNORE_MASTER_SITE_MYSQL)
MASTER_SITE_MYSQL+=	\
	ftp://ftp.fi.muni.cz/pub/mysql/Downloads/%SUBDIR%/ \
	http://mysql.mirrors.cybercity.dk/Downloads/%SUBDIR%/ \
	ftp://ftp.fh-wolfenbuettel.de/pub/database/mysql/Downloads/%SUBDIR%/ \
	ftp://ftp.gwdg.de/pub/misc/mysql/Downloads/%SUBDIR%/ \
	http://netmirror.org/mirror/mysql.com/Downloads/%SUBDIR%/ \
	ftp://netmirror.org/mysql.com/Downloads/%SUBDIR%/ \
	http://mirrors.ntua.gr/MySQL/Downloads/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/databases/mysql/Downloads/%SUBDIR%/ \
	http://mysql.sote.hu/Downloads/%SUBDIR%/ \
	ftp://ftp.rhnet.is/pub/mysql/Downloads/%SUBDIR%/ \
	ftp://mirror.widexs.nl/pub/mysql/Downloads/%SUBDIR%/ \
	ftp://mirror.etf.bg.ac.yu/mysql/Downloads/%SUBDIR%/ \
	ftp://mirror.switch.ch/mirror/mysql/Downloads/%SUBDIR%/ \
	http://mysql.dp.ua/Downloads/%SUBDIR%/ \
	http://mysql.mirrored.ca/Downloads/%SUBDIR%/ \
	ftp://mirror.services.wisc.edu/mirrors/mysql/Downloads/%SUBDIR%/ \
	ftp://ftp.orst.edu/pub/mysql/Downloads/%SUBDIR%/ \
	http://mysql.mirrors.pair.com/Downloads/%SUBDIR%/ \
	ftp://mysql.bannerlandia.com.ar/mirrors/mysql/Downloads/%SUBDIR%/ \
	ftp://ftp.linorg.usp.br/mysql/Downloads/%SUBDIR%/ \
	ftp://ftp.cbn.net.id/mirror/mysql/Downloads/%SUBDIR%/ \
	ftp://ftp.easynet.be/mysql/Downloads/%SUBDIR%/ \
	http://download.softagency.net/MySQL/Downloads/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_NETBSD)
MASTER_SITE_NETBSD+=	\
	http://www.gtlib.cc.gatech.edu/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://gatekeeper.dec.com/pub/BSD/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.iastate.edu/pub/netbsd/packages/distfiles/%SUBDIR%/ \
	ftp://netbsd.secsup.org/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.plig.net/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.proxad.net/mirrors/ftp.netbsd.org/packages/distfiles/%SUBDIR%/\
	ftp://ftp.funet.fi/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.unina.it/pub/Unix/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.uninett.no/bsd/unix/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://sunsite.uio.no/bsd/unix/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.sunsite.org.uk/sites/rsync.netbsd.org/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.demon.co.uk/pub/mirrors/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.uk.netbsd.org/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,NetBSD/packages/distfiles/&,} \
	ftp://ftp.dti.ad.jp/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.iij.ad.jp/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://melanoma.cs.rmit.edu.au/pub/NetBSD/packages/distfiles/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_NVIDIA)
MASTER_SITE_NVIDIA+=	\
	http://jp.download.nvidia.com/%SUBDIR%/ \
	http://us.download.nvidia.com/%SUBDIR%/ \
	http://tw.download.nvidia.com/%SUBDIR%/ \
	http://download.nvidia.com/%SUBDIR%/ \
	http://download1.nvidia.com/%SUBDIR%/ \
	ftp://download.nvidia.com/%SUBDIR%/ \
	ftp://download1.nvidia.com/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_OPENBSD)
MASTER_SITE_OPENBSD+= \
	http://anga.funkfeuer.at/ftp/pub/OpenBSD/%SUBDIR%/ \
	http://spargel.kd85.com/ftp/pub/OpenBSD/%SUBDIR%/ \
	http://ftp.eu.openbsd.org/pub/OpenBSD/%SUBDIR%/ \
	http://obsd.cec.mtu.edu/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp.openbsd.org/pub/OpenBSD/%SUBDIR%/ \
	ftp://openbsd.informatik.uni-erlangen.de/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp5.usa.openbsd.org/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp3.usa.openbsd.org/pub/OpenBSD/%SUBDIR%/ \
	ftp://rt.fm/pub/OpenBSD/%SUBDIR%/ \
	http://ftp.heanet.ie/pub/OpenBSD/%SUBDIR%/ \
	http://ftp.belnet.be/packages/openbsd/%SUBDIR%/ \
	http://mirrors.nic.funet.fi/pub/OpenBSD/%SUBDIR%/ \
	http://mirror.public-internet.co.uk/ftp/OpenBSD/%SUBDIR%/ \
	http://mirror.pacific.net.au/OpenBSD/%SUBDIR%/ \
	http://ftp.openbsd.dk/pub/OpenBSD/%SUBDIR%/ \
	http://ftp.estpak.ee/pub/OpenBSD/%SUBDIR%/ \
	http://mirror.internode.on.net/pub/OpenBSD/%SUBDIR%/ \
	http://ftp.chg.ru/pub/OpenBSD/%SUBDIR%/ \
	http://ftp.arcane-networks.fr/pub/OpenBSD/%SUBDIR%/ \
	http://ftp.netbsd.se/OpenBSD/%SUBDIR%/ \
	http://openbsd.cs.pu.edu.tw/%SUBDIR%/ \
	http://ftp.wu-wien.ac.at/pub/OpenBSD/%SUBDIR%/ \
	http://www.mirrorservice.org/pub/OpenBSD/%SUBDIR%/ \
	http://mirror.switch.ch/ftp/pub/OpenBSD/%SUBDIR%/ \
	http://ftp.jaist.ac.jp/pub/OpenBSD/%SUBDIR%/ \
	http://ftp.kaist.ac.kr/pub/OpenBSD/%SUBDIR%/ \
	http://ftp.cc.uoc.gr/mirrors/OpenBSD/%SUBDIR%/ \
	http://mirror.hostfuss.com/pub/OpenBSD/%SUBDIR%/ \
	http://ivete.fis.unb.br/mirror/OpenBSD/%SUBDIR%/ \
	ftp://ftp.stacken.kth.se/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp.ca.openbsd.org/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp.freebsdchina.org/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp.dkuug.dk/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp.jyu.fi/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp.irisa.fr/pub/OpenBSD/%SUBDIR%/ \
	ftp://openbsd.ftp.fu-berlin.de/pub/OpenBSD/%SUBDIR%/ \
	ftp://mirror.roothell.org/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp.duth.gr/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp.nara.wide.ad.jp/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp.inet.no/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp.nluug.nl/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp.gamma.ru/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp.rediris.es/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp.su.se/pub/OpenBSD/%SUBDIR%/ \
	ftp://osmirrors.cerias.purdue.edu/pub/OpenBSD/%SUBDIR%/ \
	ftp://mirror.iawnet.sandia.gov/pub/OpenBSD/%SUBDIR%/ \
	ftp://carroll.cac.psu.edu/pub/OpenBSD/%SUBDIR%/ \
	ftp://openbsd.mirrors.tds.net/pub/OpenBSD/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_OSSP)
MASTER_SITE_OSSP+= \
	ftp://ftp.ossp.org/pkg/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/utils/ossp/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_PACKETSTORM)
MASTER_SITE_PACKETSTORM+= \
	http://packetstormsecurity.nl/%SUBDIR%/ \
	http://packetstorm.linuxsecurity.com/%SUBDIR%/ \
	http://packetstorm.setnine.com/%SUBDIR%/ \
	http://packetstorm.austin2600.net/%SUBDIR%/ \
	http://packetstorm.foofus.com/%SUBDIR%/ \
	http://packetstorm.codar.com.br/%SUBDIR%/ \
	http://packetstorm.rlz.cl/%SUBDIR%/ \
	http://packetstorm.wowhacker.com/%SUBDIR%/ \
	http://packetstorm.offensive-security.com/%SUBDIR%/ \
	http://packetstorm.igor.onlinedirect.bg/%SUBDIR%/ \
	http://packetstorm.unixteacher.org/%SUBDIR%/ \
	http://packetstorm.orion-hosting.co.uk/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_PERL_CPAN)
MASTER_SITE_PERL_CPAN+=	\
	ftp://ftp.funet.fi/pub/languages/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.cpan.org/pub/CPAN/modules/by-module/%SUBDIR%/ \
	http://www.cpan.dk/modules/by-module/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,lang/perl/CPAN/modules/by-module/&,} \
	ftp://ftp.kddlabs.co.jp/lang/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/lang/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/lang/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://mirror.hiwaay.net/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.funet.fi/pub/languages/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://csociety-ftp.ecn.purdue.edu/pub/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.isu.net.sa/pub/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.cs.colorado.edu/pub/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://cpan.pop-mg.com.br/pub/CPAN/modules/by-module/%SUBDIR%/ \
	http://at.cpan.org/modules/by-module/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/lang/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.auckland.ac.nz/pub/perl/CPAN/modules/by-module/%SUBDIR%/ \
	http://backpan.cpan.org/modules/by-module/%SUBDIR%/
.endif

#
# PostgreSQL mirror sites
#
# For the full list, see the following:
#
#	http://wwwmaster.postgresql.org/download/mirrors-ftp
#
# Before update mirror list please consult with fenner's distfiles survey.
#
.if !defined(IGNORE_MASTER_SITE_PGSQL)
MASTER_SITE_PGSQL+= \
	ftp://ftp9.us.postgresql.org/pub/mirrors/postgresql/%SUBDIR%/ \
	ftp://ftp10.us.postgresql.org/pub/postgresql/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,misc/db/postgresql/&,} \
	ftp://ftp.au.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp.at.postgresql.org/db/www.postgresql.org/pub/%SUBDIR%/ \
	ftp://ftp.be.postgresql.org/postgresql/%SUBDIR%/ \
	ftp://ftp.ba.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp.cz.postgresql.org/DATA/postgresql/%SUBDIR%/ \
	ftp://ftp2.cz.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp.ee.postgresql.org/mirrors/postgresql/%SUBDIR%/ \
	ftp://ftp.fr.postgresql.org/%SUBDIR%/ \
	ftp://ftp.de.postgresql.org/mirror/postgresql/%SUBDIR%/ \
	ftp://ftp3.de.postgresql.org/pub/Mirrors/ftp.postgresql.org/%SUBDIR%/ \
	ftp://ftp.gr.postgresql.org/pub/databases/postgresql/%SUBDIR%/ \
	ftp://ftp.hk.postgresql.org/postgresql/%SUBDIR%/ \
	ftp://ftp.ie.postgresql.org/mirrors/ftp.postgresql.org/pub/%SUBDIR%/ \
	ftp://ftp2.it.postgresql.org/mirrors/postgres/%SUBDIR%/ \
	ftp://ftp.kr.postgresql.org/postgresql/%SUBDIR%/ \
	ftp://ftp.lv.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp2.nl.postgresql.org/mirror/postgresql/%SUBDIR%/ \
	ftp://ftp4.nl.postgresql.org/postgresql.zeelandnet.nl/%SUBDIR%/ \
	ftp://ftp6.pl.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp7.pl.postgresql.org/pub/mirror/ftp.postgresql.org/%SUBDIR%/ \
	ftp://ftp6.ro.postgresql.org/pub/mirrors/ftp.postgresql.org/%SUBDIR%/ \
	ftp://ftp.ru.postgresql.org/pub/unix/database/pgsql/%SUBDIR%/ \
	ftp://ftp2.ru.postgresql.org/pub/databases/postgresql/%SUBDIR%/ \
	ftp://ftp3.ru.postgresql.org/pub/mirror/postgresql/pub/%SUBDIR%/ \
	ftp://ftp5.es.postgresql.org/mirror/postgresql/%SUBDIR%/ \
	ftp://ftp.se.postgresql.org/pub/databases/relational/postgresql/%SUBDIR%/ \
	ftp://ftp3.tw.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp.postgresql.org/pub/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_PHP)
MASTER_SITE_PHP+= \
	http://dk.php.net/%SUBDIR%/ \
	http://de.php.net/%SUBDIR%/ \
	http://es.php.net/%SUBDIR%/ \
	http://fi.php.net/%SUBDIR%/ \
	http://fr.php.net/%SUBDIR%/ \
	http://gr.php.net/%SUBDIR%/ \
	http://it.php.net/%SUBDIR%/ \
	http://jp.php.net/%SUBDIR%/ \
	http://se.php.net/%SUBDIR%/ \
	http://uk.php.net/%SUBDIR%/ \
	http://us2.php.net/%SUBDIR%/ \
	http://br.php.net/%SUBDIR%/ \
	http://cn.php.net/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/php/&,}
.endif

.if !defined(IGNORE_MASTER_SITE_PYTHON)
MASTER_SITE_PYTHON+= \
	http://www.python.org/%SUBDIR%/ \
	http://python.ilisys.com.au/%SUBDIR%/ \
	http://ftp.easynet.be/python/%SUBDIR%/ \
	http://www.linux.org.hk/mirror/python/%SUBDIR%/ \
	http://mirrors.sunsite.dk/pythonwww/%SUBDIR%/ \
	http://python.emdia.fi/%SUBDIR%/ \
	http://SunSITE.Informatik.RWTH-Aachen.DE/python/%SUBDIR%/ \
	http://www.auth.gr/mirrors/python/%SUBDIR%/ \
	http://www.cwi.nl/www.python.org/%SUBDIR%/ \
	http://gnu.kookel.org/ftp/www.python.org/%SUBDIR%/ \
	http://python.holywar.net/%SUBDIR%/ \
	http://python.cdpa.nsysu.edu.tw/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.python.org/pub/www.python.org/%SUBDIR%/ \
	http://python.mirrors.pair.com/%SUBDIR%/ \
	http://mirrors.ccs.neu.edu/Python/pub/www.python.org/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_QMAIL)
MASTER_SITE_QMAIL+= \
	http://qmail.geto.net/%SUBDIR%/ \
	http://qmail.palomine.net/%SUBDIR%/ \
	http://qmail.mirrors.summersault.com/%SUBDIR%/ \
	http://qmail.cdsinet.net/%SUBDIR%/ \
	http://qmail.glasswings.com.au/%SUBDIR%/ \
	http://qmail.hostlink.com.hk/%SUBDIR%/ \
	http://qmail.cbn.net.id/%SUBDIR%/ \
	http://qmail.manic.co.kr/%SUBDIR%/ \
	http://qmail.psshee.com/%SUBDIR%/ \
	http://mirrors.kangaroot.net/qmail/%SUBDIR%/ \
	http://mirrors.sunsite.dk/qmailwww/%SUBDIR%/ \
	http://qmail.mirrors.Space.Net/%SUBDIR%/ \
	http://qmail-mirror.hoermann-rawema.de/%SUBDIR%/ \
	http://www.agria.hu/qmail/%SUBDIR%/ \
	http://qmail.hu/%SUBDIR%/ \
	http://qmail.rhnet.is/%SUBDIR%/ \
	http://qmail.netsoc.ucd.ie/%SUBDIR%/ \
	http://mirrors.dataloss.nl/www.qmail.org/%SUBDIR%/ \
	http://qmail.basefreak.nl/%SUBDIR%/ \
	http://www.math.ntnu.no/mirror/www.qmail.org/%SUBDIR%/ \
	http://qmail.konnekt.org/%SUBDIR%/ \
	http://qmail.netvisao.pt/%SUBDIR%/ \
	http://qmail.ipg.sk/%SUBDIR%/ \
	http://qmail.imasd.elmundo.es/%SUBDIR%/ \
	http://qmail.omnis.ch/%SUBDIR%/ \
	http://qmail.asylog.net/%SUBDIR%/ \
	http://qmail.softflare.com/%SUBDIR%/ \
	http://qmail.blueyonder.co.uk/%SUBDIR%/ \
	http://qmail.usp.br/%SUBDIR%/ \
	http://madhaus.utcs.utoronto.ca/qmail/%SUBDIR%/ \
	http://qmail.ru.ac.za/%SUBDIR%/ \
	http://www.qmail.org/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_QT)
MASTER_SITE_QT+= \
	http://mi.mirror.garr.it/mirrors/qt/%SUBDIR%/ \
	ftp://ftp.heanet.ie/mirrors/trolltech/pub/qt/source/%SUBDIR%/ \
	http://download.qt.nokia.com/qt/source/%SUBDIR%/ \
	ftp://ftp.trolltech.com/qt/source/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_REDHAT_LINUX)
MASTER_SITE_REDHAT_LINUX+= \
	http://mirrors.usc.edu/pub/linux/distributions/redhat/redhat/linux/%SUBDIR%/ \
	http://www.gtlib.cc.gatech.edu/pub/redhat/linux/%SUBDIR%/ \
	ftp://mirror.cs.wisc.edu/pub/mirrors/linux/redhat/%SUBDIR%/ \
	ftp://ftp.nluug.nl/site/ftp.redhat.com/redhat/linux/%SUBDIR%/ \
	ftp://ftp.icm.edu.pl/pub/linux/redhat/linux/%SUBDIR%/ \
	ftp://ftp.riken.go.jp/pub/Linux/redhat/linux/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/pub/Linux/packages/RedHat/redhat/linux/%SUBDIR%/
.endif

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
.if !defined(IGNORE_MASTER_SITE_RINGSERVER)
MASTER_SITE_RINGSERVER+=	\
	http://ring.nict.go.jp/archives/%SUBDIR%/ \
	http://ring.k-opti.com/archives/%SUBDIR%/ \
	http://ring.riken.jp/archives/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_RUBY)
MASTER_SITE_RUBY+= \
	ftp://ftp.SpringDaemons.com/pub/ruby/ruby/%SUBDIR%/ \
	ftp://ftp.ruby-lang.org/pub/ruby/%SUBDIR%/ \
	http://www.ibiblio.org/pub/languages/ruby/%SUBDIR%/ \
	ftp://xyz.lcs.mit.edu/pub/ruby/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,lang/ruby/&,} \
	ftp://ftp.fu-berlin.de/unix/languages/ruby/%SUBDIR%/ \
	ftp://ftp.easynet.be/ruby/ruby/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/lang/ruby/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/lang/ruby/%SUBDIR%/ \
	ftp://ftp.kr.FreeBSD.org/pub/ruby/%SUBDIR%/ \
	http://mirrors.sunsite.dk/ruby/%SUBDIR%/ \
	ftp://ftp.iDaemons.org/pub/mirror/ftp.ruby-lang.org/ruby/%SUBDIR%/
.endif

# See http://rubyforge.org/credits/
.if !defined(IGNORE_MASTER_SITE_RUBYFORGE)
MASTER_SITE_RUBYFORGE+= \
	http://files.rubyforge.mmmultiworks.com/%SUBDIR%/ \
	http://files.rubyforge.vm.bytemark.co.uk/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_SAMBA)
MASTER_SITE_SAMBA+= \
	http://us1.samba.org/samba/ftp/%SUBDIR%/ \
	http://us2.samba.org/samba/ftp/%SUBDIR%/ \
	http://us4.samba.org/samba/ftp/%SUBDIR%/ \
	http://us3.samba.org/samba/ftp/%SUBDIR%/ \
	ftp://ca.samba.org/%SUBDIR%/ \
	ftp://de.samba.org/samba.org/%SUBDIR%/ \
	ftp://ftp.oss.eznetsols.org/samba/%SUBDIR%/ \
	ftp://ru.samba.org/pub/samba/%SUBDIR%/ \
	ftp://ftp.easynet.be/samba/%SUBDIR%/ \
	ftp://ftp.linuxforum.net/ftp.samba.org/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/samba/&,}
.endif

# List:		http://dl.sv.gnu.org/releases/00_MIRRORS.html
.if !defined(IGNORE_MASTER_SITE_SAVANNAH)
MASTER_SITE_SAVANNAH+= \
	http://download.savannah.gnu.org/releases/%SUBDIR%/ \
	http://ftp.cc.uoc.gr/mirrors/nongnu.org/%SUBDIR%/ \
	http://www.very-clever.com/download/nongnu/%SUBDIR%/ \
	http://ftp.twaren.net/Unix/NonGNU/%SUBDIR%/ \
	ftp://ftp.cc.uoc.gr/mirrors/nongnu.org/%SUBDIR%/ \
	ftp://ftp.twaren.net/Unix/NonGNU/%SUBDIR%/ \
	http://download.savannah.gnu.org/releases-noredirect/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_SOURCEFORGE)
.for mirror in heanet sunet iweb switch surfnet kent freefr \
		voxel jaist osdn nchc transact softlayer \
		internode biznetnetworks upfr
#		garr dfn ovh (redirect as of 2009-Sep-02)
MASTER_SITE_SOURCEFORGE+= \
	http://${mirror}.dl.sourceforge.net/project/%SUBDIR%/
.endfor
.endif

.if !defined(IGNORE_MASTER_SITE_SOURCEFORGE_JP)
.for mirror in keihanna osdn qgpop
MASTER_SITE_SOURCEFORGE_JP+= \
	http://${mirror}.dl.sourceforge.jp/%SUBDIR%/
.endfor
.endif

.if !defined(IGNORE_MASTER_SITE_SOURCEWARE)
MASTER_SITE_SOURCEWARE+= \
	ftp://ftp.funet.fi/pub/mirrors/sources.redhat.com/pub/%SUBDIR%/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/sources.redhat.com/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_SUNSITE)
MASTER_SITE_SUNSITE+=	\
	http://www.ibiblio.org/pub/Linux/%SUBDIR%/ \
	http://www.gtlib.cc.gatech.edu/pub/Linux/%SUBDIR%/ \
	ftp://ftp.cs.tu-berlin.de/pub/linux/Mirrors/sunsite.unc.edu/%SUBDIR%/ \
	ftp://ftp.physics.auth.gr/pub/mirrors/ibiblio/Linux/%SUBDIR%/ \
	ftp://ftp.edisontel.com/pub/Sunsite_Mirror/%SUBDIR%/ \
	ftp://ftp.nluug.nl/pub/metalab/%SUBDIR%/ \
	ftp://ftp.nvg.ntnu.no/pub/mirrors/metalab.unc.edu/%SUBDIR%/ \
	ftp://ftp.icm.edu.pl/pub/Linux/sunsite/%SUBDIR%/ \
	ftp://ftp.cse.cuhk.edu.hk/pub4/Linux/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/Linux/metalab.unc.edu/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/Linux/sunsite/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_SUSE)
MASTER_SITE_SUSE+= 	\
	http://mirrors.usc.edu/pub/linux/distributions/suse/%SUBDIR%/ \
	ftp://ftp-linux.cc.gatech.edu/pub/suse/suse/%SUBDIR%/ \
	http://mirror.usu.edu/mirrors/suse/%SUBDIR%/ \
	ftp://mirror.mcs.anl.gov/pub/suse/%SUBDIR%/ \
	ftp://chuck.ucs.indiana.edu/linux/suse/suse/%SUBDIR%/ \
	ftp://distro.ibiblio.org/pub/linux/distributions/suse/suse/%SUBDIR%/ \
	ftp://ftp.oregonstate.edu/pub/suse/suse/%SUBDIR%/ \
	ftp://ftp.sunsite.utk.edu/pub/linux/suse/suse/%SUBDIR%/ \
	http://sunsite.utk.edu/ftp/pub/linux/suse/suse/%SUBDIR%/ \
	http://mirror.tamu.edu/suse/%SUBDIR%/ \
	ftp://ftp.empiricalnetworks.com/pub/suse/%SUBDIR%/ \
	http://suse.cs.utah.edu/suse/%SUBDIR%/ \
	ftp://ftp.belnet.be/linux/suse/suse/%SUBDIR%/ \
	http://ftp.unicamp.br/pub/suse/%SUBDIR%/ \
	ftp://mirrors.netbg.com/suse/%SUBDIR%/ \
	ftp://ftp.suse.cl/pub/suse/%SUBDIR%/ \
	http://ftp.sh.cvut.cz/MIRRORS/SuSE/pub/%SUBDIR%/ \
	ftp://ftp.linux.ee/pub/suse/suse/%SUBDIR%/ \
	ftp://garbo.uwasa.fi/pub/mirrors/suse/%SUBDIR%/ \
	http://fr2.rpmfind.net/linux/SuSE-Linux/%SUBDIR%/ \
	http://ftp.iut-bm.univ-fcomte.fr/Suse/suse/%SUBDIR%/ \
	ftp://ftp.gwdg.de/pub/linux/suse/ftp.suse.com/suse/%SUBDIR%/ \
	ftp://sunsite.informatik.rwth-aachen.de/pub/Linux/suse/%SUBDIR%/ \
	ftp://ftp.rz.hu-berlin.de/pub/mirrors/ftp.suse.com/pub/suse/%SUBDIR%/ \
	ftp://ftp.tu-chemnitz.de/pub/linux/suse/ftp.suse.com/suse/%SUBDIR%/ \
	ftp://ftp.tu-cottbus.de/pub/unix/linux/suse.com/suse/%SUBDIR%/ \
	http://ftp.uni-erlangen.de/pub/Linux/MIRROR.suse/pub/suse/%SUBDIR%/ \
	http://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.suse.com/pub/suse/%SUBDIR%/ \
	ftp://ftp.hs.uni-hamburg.de/pub/unix/linux/suse/%SUBDIR%/ \
	ftp://ftp.rrzn.uni-hannover.de/pub/mirror/linux/suse/%SUBDIR%/ \
	http://ftp.tu-ilmenau.de/Mirrors/ftp.suse.com/%SUBDIR%/ \
	ftp://ftp.uni-kassel.de/pub/linux/suse/%SUBDIR%/ \
	ftp://ftp.join.uni-muenster.de/pub/linux/distributions/suse/%SUBDIR%/ \
	ftp://ftp.uni-rostock.de/pub/systems/unix/linux/suse/%SUBDIR%/ \
	ftp://ftp.mpi-sb.mpg.de/pub/linux/mirror/ftp.suse.com/suse/%SUBDIR%/ \
	ftp://ftp.uni-kl.de/pub/linux/suse/%SUBDIR%/ \
	ftp://ftp.uni-siegen.de/pub/suse/%SUBDIR%/ \
	ftp://ftp.uni-mainz.de/pub/software/Linux/suse/%SUBDIR%/ \
	ftp://ftp.uni-heidelberg.de/pub/linux/suse/%SUBDIR%/ \
	ftp://ftp.rz.uni-ulm.de/pub/mirrors/suse/%SUBDIR%/ \
	ftp://ftp.rz.uni-wuerzburg.de/pub/linux/MIRROR.suse/%SUBDIR%/ \
	ftp://ftp.freenet.de/pub/.disk1/ftp.suse.com/pub/suse/%SUBDIR%/ \
	ftp://ftp.hu-berlin.de/pub/mirrors/ftp.suse.com/pub/suse/%SUBDIR%/ \
	ftp://ftp.rz.uni-karlsruhe.de/pub/mirror/ftp.gwdg.de/pub/linux/suse/ftp.suse.com/suse/%SUBDIR%/ \
	ftp://ftp.rz.uni-kiel.de/pub2/linux/suse/%SUBDIR%/ \
	http://mirrors.sth.sze.hu/linux/suse/%SUBDIR%/ \
	ftp://ftp.heanet.ie/mirrors/ftp.suse.com/pub/suse/ftp.suse.com/suse/%SUBDIR%/ \
	ftp://ftp.esat.net/mirrors/ftp.suse.com/pub/suse/%SUBDIR%/ \
	ftp://ftp.unina.it/pub/linux/distributions/SuSE/ftp.suse.com/suse/%SUBDIR%/ \
	ftp://ftp.uniroma2.it/Linux/suse/pub/suse/%SUBDIR%/ \
	ftp://ftp.riken.jp/Linux/suse/suse/%SUBDIR%/ \
	ftp://ftp.kddilabs.jp/Linux/packages/SuSE/suse/%SUBDIR%/ \
	ftp://ftp.novell.co.jp/pub/suse/suse/%SUBDIR%/ \
	ftp://ftp.kreonet.re.kr/pub/Linux/suse/%SUBDIR%/ \
	http://ftp.tpnet.pl/vol/d7/ftp.suse.com/%SUBDIR%/ \
	ftp://ftp.icm.edu.pl/packages/linux-suse/%SUBDIR%/ \
	http://ftp.iasi.roedu.net/pub/mirrors/ftp.suse.com/pub/suse/%SUBDIR%/ \
	http://ftp.idilis.ro/mirrors/ftp.suse.com/pub/suse/%SUBDIR%/ \
	http://ftp.isu.net.sa/pub/mirrors/ftp.suse.com/%SUBDIR%/ \
	http://mirror.etf.bg.ac.yu/distributions/suse/suse/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/Linux/distributions/suse/suse/%SUBDIR%/ \
	ftp://ftp.solnet.ch/mirror/SuSE/%SUBDIR%/ \
	ftp://sunsite.cnlab-switch.ch/mirror/SuSE/suse/%SUBDIR%/ \
	http://ftp.isu.edu.tw/pub/Linux/SuSE/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.suse.com/pub/suse/%SUBDIR%/ \
	http://www.mirrorservice.org/sites/ftp.suse.com/pub/suse/%SUBDIR%/ \
	ftp://ftp.kde.org/pub/suse/ftp.suse.com/suse/%SUBDIR%/ \
	ftp://ftp.suse.com/pub/suse/%SUBDIR%/ \
	ftp://ftp.softnet.tuc.gr/pub/linux/suse/suse/%SUBDIR%/ \
	http://ftp.softnet.tuc.gr/pub/linux/suse/suse/%SUBDIR%/ \
	ftp://ftp.duth.gr/pub/suse/suse/%SUBDIR%/ \
	ftp://ftp.is.co.za/linux/distributions/suse/%SUBDIR%/ \
	http://ftp.sun.ac.za/ftp/mirrorsites/suse/%SUBDIR%/ \
	ftp://ftp.rediris.es/pub/linux/distributions/suse/pub/suse/%SUBDIR%/ \
	ftp://suse.grn.es/mirrors/suse/%SUBDIR%/ \
	ftp://ftp.cb.spb.ru/.1/Linux-Distrib/Suse/%SUBDIR%/ \
	ftp://ftp.neva.ru/.1/Linux-Distrib/Suse/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/Linux/SuSE/suse/%SUBDIR%/ \
	http://mirror.pacific.net.au/linux/suse/%SUBDIR%/ \
	ftp://mirror.aarnet.edu.au/pub/suse/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_TCLTK)
MASTER_SITE_TCLTK+= \
	ftp://ftp.tcl.tk/pub/tcl/%SUBDIR%/ \
	ftp://sunsite.utk.edu/pub/tcl/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/languages/tcl/tcl/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/lang/tcl/ftp.scriptics.com/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.tcl.tk/pub/tcl/%SUBDIR%/ \
	ftp://sunsite.org.uk/sites/ftp.scriptics.com/pub/tcl/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_TEX_CTAN)
MASTER_SITE_TEX_CTAN+=  \
	ftp://ftp.funet.fi/pub/TeX/CTAN/%SUBDIR%/  \
	ftp://ctan.unsw.edu.au/tex-archive/%SUBDIR%/ \
	ftp://ftp.tex.ac.uk/tex-archive/%SUBDIR%/  \
	ftp://ftp.kddlabs.co.jp/CTAN/%SUBDIR%/ \
	ftp://ctan.tug.org/tex-archive/%SUBDIR%/ \
	ftp://ftp.dante.de/tex-archive/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,text/CTAN/&,} \
	ftp://ftp.chg.ru/pub/TeX/CTAN/%SUBDIR%/ \
	ftp://mirror.macomnet.net/pub/CTAN/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_THEMES)
MASTER_SITE_THEMES+= \
	http://download.freshmeat.net/themes/%SUBDIR%/ \
	ftp://gd.tuwien.ac.at/opsys/linux/freshmeat/themes/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_TUCOWS)
.for mirror in chariot ns-linux iinets easyhost bihnet pucpr cdli olivant otenet hellasonline pihk \
	cyberec panservice fastweb mclink kasnet wananchi latvia uunetnl wish bit vianl introweb \
	dekooi inspirenet pl-task clix simplesnet netvisao idilis rdstm atk saix mweb mundo-r gva \
	dataphone ankara tulumba tr-net mintac epix theplanet wcn ukms blueyonder
MASTER_SITE_TUCOWS+= \
	http://${mirror}.linux.tucows.com/files/%SUBDIR%/
.endfor
MASTER_SITE_TUCOWS+= \
	http://linuxberg.nexicom.net/files/%SUBDIR%/ \
	http://linuxberg.xs4all.nl/files/%SUBDIR%/
.endif

# List:		http://www.vim.org/mirrors.php
# Updated:	2006-06-13
.if !defined(IGNORE_MASTER_SITE_VIM)
MASTER_SITE_VIM+= \
	http://ftp.vim.org/pub/vim/unix/ \
	http://mirrors.24-7-solutions.net/pub/vim/unix/ \
	http://ftp.tw.vim.org/pub/vim/unix/ \
	http://vim.stu.edu.tw/unix/ \
	http://gd.tuwien.ac.at/pub/vim/unix/ \
	http://www.etsimo.uniovi.es/pub/vim/unix/ \
	http://www.pt.vim.org/pub/vim/unix/ \
	http://www.pangora.org/vim.org/pub/vim/unix/ \
	http://www.math.technion.ac.il/pub/vim/unix/ \
	http://vim.fyxm.net/pub/vim/unix/ \
	http://zloba.ath.cx/pub/vim/unix/ \
	http://ftp2.uk.vim.org/sites/ftp.vim.org/pub/vim/unix/ \
	http://vim.mirror.fr/unix/ \
	ftp://ftp.vim.org/pub/vim/unix/ \
	ftp://ftp2.us.vim.org/pub/vim/unix/ \
	ftp://ftp9.us.vim.org/pub/vim/unix/ \
	ftp://ftp.ca.vim.org/pub/vim/unix/ \
	ftp://ftp.nl.vim.org/pub/vim/unix/ \
	ftp://ftp.de.vim.org/unix/ \
	ftp://ftp3.de.vim.org/pub/vim/unix/ \
	ftp://ftp.uk.vim.org/pub/vim/unix/ \
	ftp://ftp.ie.vim.org/pub/vim/unix/ \
	ftp://ftp.at.vim.org/pub/vim/unix/ \
	ftp://ftp.pt.vim.org/pub/vim/unix/ \
	ftp://ftp.is.vim.org/pub/vim/unix/ \
	ftp://ftp.il.vim.org/pub/vim/unix/ \
	ftp://ftp.pl.vim.org/pub/vim/unix/ \
	ftp://ftp.ro.vim.org/pub/vim/unix/ \
	ftp://ftp.sk.vim.org/pub/vim/unix/ \
	ftp://ftp.tw.vim.org/pub/vim/unix/ \
	ftp://vim.stu.edu.tw/pub/vim/unix/ \
	ftp://ftp.jp.vim.org/pub/vim/unix/ \
	ftp://ftp.kr.vim.org/pub/vim/unix/ \
	ftp://ftp.mirrorservice.org/sites/ftp.vim.org/pub/vim/unix/
.endif

.if !defined(IGNORE_MASTER_SITE_WINDOWMAKER)
MASTER_SITE_WINDOWMAKER+= \
	ftp://ftp.windowmaker.info/pub/%SUBDIR%/ \
	ftp://ftp.uvsq.fr/pub/X11/window-managers/windowmaker/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/X/WindowMaker/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_XCONTRIB)
MASTER_SITE_XCONTRIB+=	\
	ftp://ftp.net.ohio-state.edu/pub/X11/contrib/%SUBDIR%/ \
	ftp://ftp.gwdg.de/pub/x11/x.org/contrib/%SUBDIR%/ \
	ftp://ftp.x.org/contrib/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/X11/ftp.x.org/contrib/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/X/XFree86/mirror/X.Org/contrib/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/X11/ftp.x.org/contrib/%SUBDIR%/ \
	ftp://ftp2.x.org/contrib/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,X/opengroup/contrib/&,} \
	ftp://ftp.mirrorservice.org/sites/ftp.x.org/contrib/%SUBDIR%/ \
	ftp://sunsite.org.uk/sites/ftp.x.org/contrib/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/X11/x.org/contrib/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_XEMACS)
MASTER_SITE_XEMACS+= \
	ftp://ftp.at.xemacs.org/editors/xemacs/%SUBDIR%/ \
	ftp://ftp.be.xemacs.org/xemacs/%SUBDIR%/ \
	ftp://ftp.br.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.ca.xemacs.org/pub/Mirror/xemacs/%SUBDIR%/ \
	ftp://ftp.ch.xemacs.org/mirror/xemacs/%SUBDIR%/ \
	ftp://ftp.de.xemacs.org/pub/ftp.xemacs.org/tux/xemacs/%SUBDIR%/ \
	ftp://ftp.dk.xemacs.org/pub/emacs/xemacs/%SUBDIR%/ \
	ftp://ftp.fi.xemacs.org/pub/mirrors/ftp.xemacs.org/pub/tux/xemacs/%SUBDIR%/ \
	ftp://ftp.fr.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.hk.xemacs.org/pub/xemacsftp/%SUBDIR%/ \
	ftp://ftp.ie.xemacs.org/mirrors/ftp.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.it.xemacs.org/unix/packages/XEMACS/%SUBDIR%/ \
	ftp://ftp.kr.xemacs.org/pub/tools/emacs/xemacs/%SUBDIR%/ \
	ftp://ftp.no.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.pt.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.ru.xemacs.org/pub/emacs/xemacs/%SUBDIR%/ \
	ftp://ftp.se.xemacs.org/pub/gnu/xemacs/%SUBDIR%/ \
	ftp://ftp.tw.xemacs.org/Unix/Editors/XEmacs/%SUBDIR%/ \
	ftp://ftp.uk.xemacs.org/sites/ftp.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.us.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://xemacs.xmundo.net/pub/mirrors/xemacs/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/unix/editor/xemacs/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,text/xemacs/&,}
.endif

.if !defined(IGNORE_MASTER_SITE_XFCE)
MASTER_SITE_XFCE+= \
	http://mocha.xfce.org/archive/%SUBDIR%/src/ \
	http://www.us.xfce.org/archive/%SUBDIR%/src/ \
	http://www.de.xfce.org/archive/%SUBDIR%/src/ \
	http://www.ca-us.xfce.org/archive/%SUBDIR%/src/ \
	http://www.p0llux.be/xfce/%SUBDIR%/src/
.endif

.if !defined(IGNORE_MASTER_SITE_XFREE)
MASTER_SITE_XFREE+= \
	http://www.gtlib.cc.gatech.edu/pub/XFree86/%SUBDIR%/source/ \
	ftp://ftp.xfree86.org/pub/XFree86/%SUBDIR%/source/ \
	ftp://ftp.dti.ad.jp/pub/X/XFree86/XFree86/%SUBDIR%/source/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,XFree86/&/source,} \
	ftp://ftp.fit.vutbr.cz/pub/XFree86/%SUBDIR%/source/ \
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
.endif

.if !defined(IGNORE_MASTER_SITE_XORG)
MASTER_SITE_XORG+= \
	ftp://ftp.gwdg.de/pub/x11/x.org/pub/%SUBDIR%/ \
	ftp://ftp.cica.es/pub/X/pub/%SUBDIR%/ \
	ftp://ftp.cs.cuhk.edu.hk/pub/X11/%SUBDIR%/ \
	ftp://ftp.unicamp.br/pub/X11/releases/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/X11/X.org/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,X/opengroup/&/,} \
	ftp://ftp.task.gda.pl/mirror/ftp.x.org/pub/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/X11/ftp.x.org/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.x.org/pub/%SUBDIR%/ \
	ftp://sunsite.uio.no/pub/X11/%SUBDIR%/ \
	http://xorg.freedesktop.org/%SUBDIR%/ \
	http://xorg.freedesktop.org/releases/%SUBDIR%/ \
	ftp://ftp.x.org/pub/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_KERNEL_ORG)
MASTER_SITE_KERNEL_ORG+= \
	http://kernel.org/pub/%SUBDIR%/ \
	http://www.us.kernel.org/pub/%SUBDIR%/ \
	http://www.uk.kernel.org/pub/%SUBDIR%/ \
	http://www.no.kernel.org/pub/%SUBDIR%/ \
	http://www.de.kernel.org/pub/%SUBDIR%/ \
	http://www.it.kernel.org/pub/%SUBDIR%/ \
	http://www.ru.kernel.org/pub/%SUBDIR%/ \
	http://www.au.kernel.org/pub/%SUBDIR%/
.endif

# Macro magic

MASTER_SITES_ABBREVS=	CPAN:PERL_CPAN \
			SF:SOURCEFORGE \
			SFJP:SOURCEFORGE_JP \
			RF:RUBYFORGE
MASTER_SITES_SUBDIRS=	\
			APACHE_JAKARTA:${PORTNAME:S,-,/,}/source \
			BERLIOS:${PORTNAME:L} \
			CENKES:myports \
			CHEESESHOP:source/${DISTNAME:C/(.).*/\1/}/${DISTNAME:C/(.*)-[0-9].*/\1/} \
			CSME:myports \
			DEBIAN:pool/main/${PORTNAME:C/^((lib)?.).*$/\1/}/${PORTNAME} \
			GCC:releases/${DISTNAME} \
			GNOME:sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/} \
			GNU:${PORTNAME} \
			HORDE:${PORTNAME} \
			LOGILAB:${PORTNAME} \
			MOZDEV:${PORTNAME:L} \
			PERL_CPAN:${PORTNAME:C/-.*//} \
			PNET:${PNET_MASTER_SITE_SUBDIR} \
			PYTHON:${PYTHON_MASTER_SITE_SUBDIR} \
			RUBY_DBI:${RUBY_DBI_MASTER_SITE_SUBDIR} \
			RUBY_GNOME:${RUBY_GNOME_MASTER_SITE_SUBDIR} \
			SAVANNAH:${PORTNAME:L} \
			SOURCEFORGE:${PORTNAME:L}/${PORTNAME:L}/${PORTVERSION} \
			RUBYFORGE:${PORTNAME:L}

.if defined(MASTER_SITES) && ${MASTER_SITES:N*\:/*}

.for _site__ in ${MASTER_SITES}
_site_=${_site__}
.	if ${_site_:M*\:/*}
MASTER_SITES_EXP+=	${_site_}
MASTER_SITES_EXP:=	${MASTER_SITES_EXP}
.	else
_site_urlpath_=	${_site_:C@^(.*):[^/:]+$@\1@}
.		if ${_site_urlpath_:M*/*}
_site_url_=		${_site_urlpath_:C@^([^/]+)/.*$@\1@}
_site_subdir_=	${_site_urlpath_:S/^${_site_urlpath_:C@^([^/]+)/.*$@\1@}//:S!^/!!:S!/$!!}
.		else
_site_url_=		${_site_urlpath_}
.undef _site_subdir_
.		endif
_site_group_=	${_site_:S/^${_site_:C@^(.*):[^/:]+$@\1@}//:S/^://}
.		for _abbrev_ in ${MASTER_SITES_ABBREVS}
.			if ${_site_url_} == ${_abbrev_:C/:.*//}
_site_url_=	${_abbrev_:C/.*://}
.			endif
.		endfor
.		for _subdir_ in ${MASTER_SITES_SUBDIRS}
.			if ${_site_url_} == ${_subdir_:C/:.*//} && !defined(MASTER_SITE_SUBDIR)
_site_subdir_?=	${_subdir_:C/.*://}
.			endif
.		endfor
.		ifdef MASTER_SITE_${_site_url_}
.			ifdef _site_subdir_
MASTER_SITES_EXP+=	${MASTER_SITE_${_site_url_}:S^%SUBDIR%^${_site_subdir_}^:S/$/:${_site_group_}/:S/:$//}
.			else
MASTER_SITES_EXP+=	${MASTER_SITE_${_site_url_}:S/$/:${_site_group_}/:S/:$//}
.			endif
MASTER_SITES_EXP:=	${MASTER_SITES_EXP}
.		endif
.	endif
.endfor
MASTER_SITES=	${MASTER_SITES_EXP}

.endif
