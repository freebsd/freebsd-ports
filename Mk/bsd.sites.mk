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
	http://ftp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/ \
	ftp://ftp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/ \
	ftp://ftp.se.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/ \
	ftp://ftp.uk.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/ \
	ftp://ftp.ru.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/ \
	ftp://ftp.jp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/ \
	ftp://ftp.tw.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/ \
	ftp://ftp.cn.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/%SUBDIR%/

MASTER_SITE_PORTS_JP+= \
	ftp://ports.jp.FreeBSD.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/%SUBDIR%/ \
	ftp://ftp4.jp.FreeBSD.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/%SUBDIR%/ \
	ftp://ftp.ics.es.osaka-u.ac.jp/pub/mirrors/FreeBSD-jp/ports-jp/LOCAL_PORTS/%SUBDIR%/
.endif

##
##	KEEP THIS LIST SORTED
##

.if !defined(IGNORE_MASTER_SITE_AFTERSTEP)
MASTER_SITE_AFTERSTEP+= \
	ftp://ftp.afterstep.org/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/X11/AfterStep/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/X/AfterStep/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_ALSA)
MASTER_SITE_ALSA+= \
	http://alsa.cybermirror.org/%SUBDIR%/ \
	ftp://ftp.alsa-project.org/pub/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_APACHE)
MASTER_SITE_APACHE+= \
	http://www.apache.org/dist/%SUBDIR%/ \
	http://archive.apache.org/dist/%SUBDIR%/ \
	http://ftp.twaren.net/Unix/Web/apache/%SUBDIR%/ \
	http://apache.mirror.uber.com.au/%SUBDIR%/ \
	http://apache.spd.co.il/%SUBDIR%/ \
	http://ftp.mirrorservice.org/sites/ftp.apache.org/%SUBDIR/ \
	http://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.apache.org/dist/%SUBDIR%/ \
	ftp://mir1.ovh.net/ftp.apache.org/dist/%SUBDIR%/ \
	ftp://ftp.forthnet.gr/pub/www/apache/%SUBDIR%/ \
	ftp://xenia.sote.hu/pub/mirrors/www.apache.org/%SUBDIR%/ \
	ftp://ftp.heanet.ie/mirrors/www.apache.org/dist/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/apache/&,} \
	ftp://ftp.sunet.se/pub/www/servers/apache/dist/%SUBDIR%/ \
	http://mirrors.ircam.fr/pub/apache/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_APACHE_COMMONS_BINARIES)
MASTER_SITE_APACHE_COMMONS_BINARIES+= \
	${MASTER_SITE_APACHE:S,%SUBDIR%,commons/&/binaries,}
.endif

.if !defined(IGNORE_MASTER_SITE_APACHE_COMMONS_SOURCE)
MASTER_SITE_APACHE_COMMONS_SOURCE+= \
	${MASTER_SITE_APACHE:S,%SUBDIR%,commons/&/source,}
.endif

.if !defined(IGNORE_MASTER_SITE_APACHE_HTTPD)
MASTER_SITE_APACHE_HTTPD+= \
	${MASTER_SITE_APACHE:S,%SUBDIR%,httpd/&,}
.endif

.if !defined(IGNORE_MASTER_SITE_APACHE_JAKARTA)
MASTER_SITE_APACHE_JAKARTA+= \
	${MASTER_SITE_APACHE:S,%SUBDIR%,jakarta/&,}
.endif

.if !defined(IGNORE_MASTER_SITE_APACHE_TOMCAT)
MASTER_SITE_APACHE_TOMCAT+= \
	${MASTER_SITE_APACHE:S,%SUBDIR%,tomcat/&,}
.endif

.if !defined(IGNORE_MASTER_SITE_APACHE_XML)
MASTER_SITE_APACHE_XML+= \
	${MASTER_SITE_APACHE:S,%SUBDIR%,xml/&,}
.endif

.if !defined(IGNORE_MASTER_SITE_BERLIOS)
MASTER_SITE_BERLIOS+= \
	http://download.berlios.de/%SUBDIR%/ \
	http://download2.berlios.de/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_CENKES)
MASTER_SITE_CENKES+= \
	http://bsd2.cenkes.org/%SUBDIR%/ \
	http://bsd3.cenkes.org/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_CHEESESHOP)
MASTER_SITE_CHEESESHOP+= \
	http://pypi.python.org/packages/%SUBDIR%/ \
	http://c.pypi.python.org/packages/%SUBDIR%/ \
	http://e.pypi.python.org/packages/%SUBDIR%/ \
	http://f.pypi.python.org/packages/%SUBDIR%/ \
	http://pypi.crate.io/packages/%SUBDIR%/ \
	http://pypi.python.jp/${DISTNAME:S/${DISTVERSION}//:S/-//}/
.endif

.if !defined(IGNORE_MASTER_SITE_COMP_SOURCES)
MASTER_SITE_COMP_SOURCES+= \
	ftp://gatekeeper.dec.com/pub/usenet/comp.sources.%SUBDIR%/ \
	ftp://ftp.uu.net/usenet/comp.sources.%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_CRITICAL)
MASTER_SITE_CRITICAL+= \
	http://critical.ch/distfiles/%SUBDIR%/ \
	http://energy.critical.ch/distfiles/%SUBDIR%/ \
	http://snow.critical.ch/distfiles/%SUBDIR%/ \
	http://fneu.fr/distfiles/%SUBDIR%/ \
	ftp://ftp.c.saper.info/distfiles/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_CSME)
MASTER_SITE_CSME+=	${MASTER_SITE_CENKES}
.endif

.if !defined(IGNORE_MASTER_SITE_DEBIAN)
MASTER_SITE_DEBIAN+= \
	http://www.gtlib.gatech.edu/pub/debian/%SUBDIR%/ \
	ftp://ftp.us.debian.org/debian/%SUBDIR%/ \
	${MASTER_SITE_DEBIAN_NON_US:S,/debian-non-US/,/debian/,}
.endif

.if !defined(IGNORE_MASTER_SITE_DEBIAN_NON_US)
MASTER_SITE_DEBIAN_NON_US+= \
	ftp://ftp.au.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.bg.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.br.debian.org/debian-non-US/%SUBDIR%/ \
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
	ftp://ftp2.de.debian.org/debian-non-US/%SUBDIR%/ \
	ftp://ftp.snt.utwente.nl/pub/linux/debian-non-US/%SUBDIR%/ \
	ftp://ftp.df.lth.se/pub/debian-non-US/%SUBDIR%/ \
	ftp://ftp.acc.umu.se/debian-non-US/%SUBDIR%/ \
	ftp://mirror.symnds.com/debian-non-US/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_DEBIAN_POOL)
MASTER_SITE_DEBIAN_POOL+= \
	${MASTER_SITE_DEBIAN:C|(/%SUBDIR%/)|/pool/main/${PORTNAME:C/^(.).*$/\1/}/${PORTNAME}/|}
.endif

.if !defined(IGNORE_MASTER_SITE_EASYSW)
MASTER_SITE_EASYSW+= \
	http://ftp.easysw.com/pub/%SUBDIR%/ \
	ftp://ftp.easysw.com/pub/%SUBDIR%/ \
	ftp://ftp.rz.tu-bs.de/pub/mirror/ftp.easysw.com/ftp/pub/%SUBDIR%/ \
	http://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_ECLIPSE)
MASTER_SITE_ECLIPSE+= \
	ftp://sunsite.informatik.rwth-aachen.de/pub/mirror/eclipse.org/%SUBDIR%/ \
	ftp://sunsite.informatik.rwth-aachen.de/pub/mirror/eclipse/%SUBDIR%/ \
	http://ftp-stud.fht-esslingen.de/pub/Mirrors/eclipse/%SUBDIR%/ \
	ftp://sunsite.cnlab-switch.ch/mirror/eclipse/%SUBDIR%/ \
	ftp://sunsite.cnlab-switch.ch/mirror/eclipse/eclipse/downloads/drops/%SUBDIR%/ \
	ftp://sunsite.cnlab-switch.ch/mirror/eclipse/eclipse/downloads/drops4/%SUBDIR%/ \
	http://eclipse.org/downloads/download.php?mirror_id=96&r=1&file=/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_EXIM)
MASTER_SITE_EXIM+= \
	ftp://ftp.exim.org/pub/exim/%SUBDIR%/ \
	ftp://exim.inode.at/exim/%SUBDIR%/ \
	ftp://exim-ftp.itsoft.at/exim/exim/%SUBDIR%/ \
	http://exim-ftp.itsoft.at/exim/%SUBDIR%/ \
	ftp://ftp.easynet.be/exim/exim/%SUBDIR%/ \
	ftp://mirror.kn.vutbr.cz/pub/ftp.exim.org/exim/%SUBDIR%/ \
	http://exim.mirror.fr/exim/%SUBDIR%/ \
	http://mirrors.zerg.biz/exim/exim/%SUBDIR%/ \
	http://dl.ambiweb.de/mirrors/ftp.exim.org/exim/%SUBDIR%/ \
	ftp://exim.noris.de/exim/%SUBDIR%/ \
	ftp://ftp.bytemine.net/exim/exim/%SUBDIR%/ \
	ftp://exim.mirror.iphh.net/ftp/exim/%SUBDIR%/ \
	http://exim.mirror.iphh.net/ftp/exim/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/unix/mail/exim/%SUBDIR%/ \
	http://exim-ftp.octet.hu/exim/%SUBDIR%/ \
	ftp://ftp.heanet.ie/pub/exim/%SUBDIR%/ \
	http://ftp.heanet.ie/pub/exim/%SUBDIR%/ \
	http://washitake.com/mail/exim/mirror/exim/%SUBDIR%/ \
	ftp://ftp.tin.org/pub/mail/exim/%SUBDIR%/ \
	http://exim.psshee.com/ftp/exim/%SUBDIR%/ \
	ftp://mirror.hostfuss.com/exim/ftp/exim/%SUBDIR%/ \
	http://mirror.hostfuss.com/exim/ftp/exim/%SUBDIR%/ \
	ftp://ftp.nl.uu.net/pub/unix/mail/exim/exim/%SUBDIR%/ \
	ftp://sunsite.uio.no/pub/mail/exim/exim/%SUBDIR%/ \
	http://piotrkosoft.net/pub/mirrors/ftp.exim.org/exim/%SUBDIR%/ \
	ftp://ftp.piotrkosoft.net/pub/mirrors/ftp.exim.org/exim/%SUBDIR%/ \
	ftp://sunsite.icm.edu.pl/pub/unix/mail/exim/exim/%SUBDIR%/ \
	http://sunsite.icm.edu.pl/pub/unix/mail/exim/exim/%SUBDIR%/ \
	ftp://ftp.is.co.za/networking/mail/mta/exim/ftp/exim/%SUBDIR%/ \
	ftp://mirrors.dominios.pt/pub/ftp.exim.org/exim/%SUBDIR%/ \
	ftp://mirror.switch.ch/mirror/exim/exim/%SUBDIR%/ \
	http://mirror.switch.ch/ftp/mirror/exim/exim/%SUBDIR%/ \
	ftp://ftp.reaper.org/pub/exim/exim/%SUBDIR%/ \
	ftp://sunsite.cnlab-switch.ch/mirror/exim/exim/%SUBDIR%/ \
	ftp://ftp.demon.co.uk/pub/mirrors/exim/%SUBDIR%/ \
	ftp://mirror.tje.me.uk/pub/mirrors/ftp.exim.org/exim/%SUBDIR%/ \
	http://mirror.tje.me.uk/pub/mirrors/ftp.exim.org/exim/%SUBDIR%/ \
	ftp://ftp.fsckit.net/pub/exim/exim/%SUBDIR%/ \
	ftp://idcnetwork.org/pub/exim/exim/%SUBDIR%/ \
	http://ftp.exim.llorien.org/exim/%SUBDIR%
.endif

.if !defined(IGNORE_MASTER_SITE_FEDORA_LINUX)
MASTER_SITE_FEDORA_LINUX+= \
	http://archives.fedoraproject.org/pub/archive/fedora/linux/core/%SUBDIR%/ \
	http://ftp.udl.es/pub/fedora/linux/core/%SUBDIR%/ \
	http://ftp.sunet.se/pub/Linux/distributions/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/Linux/distributions/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.udl.es/pub/fedora/linux/core/%SUBDIR%/ \
	http://mirrors.kernel.org/fedora/core/%SUBDIR%/ \
	ftp://mirrors.kernel.org/fedora/core/%SUBDIR%/ \
	http://mirror.web-ster.com/fedora/core/%SUBDIR%/ \
	ftp://mirror.web-ster.com/fedora/core/%SUBDIR%/ \
	http://rpmfind.net/linux/fedora/core/%SUBDIR%/ \
	ftp://rpmfind.net/linux/fedora/core/%SUBDIR%/ \
	ftp://ftp.gtlib.gatech.edu/pub/fedora.redhat/linux/core/%SUBDIR%/ \
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
	http://www.mirrorservice.org/sites/dl.fedoraproject.org/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/dl.fedoraproject.org/pub/fedora/linux/core/%SUBDIR%/ \
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
	http://ftp.uni-erlangen.de/pub/Linux/MIRROR.fedora/core/%SUBDIR%/ \
	ftp://ftp.uni-muenster.de/pub/linux/distributions/fedora/linux/core/%SUBDIR%/ \
	http://ftp.uni-bayreuth.de/linux/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.uni-bayreuth.de/pub/linux/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/linux/fedora/core/%SUBDIR%/ \
	http://ftp.uni-koeln.de/mirrors/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.uni-koeln.de/mirrors/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.informatik.uni-frankfurt.de/pub/linux/Mirror/ftp.redhat.com/fedora/core/%SUBDIR%/ \
	http://mirrors.ircam.fr/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://mirrors.ircam.fr/pub/fedora/linux/core/%SUBDIR%/ \
	http://ftp.crihan.fr/mirrors/fedora.redhat.com/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.crihan.fr/mirrors/fedora.redhat.com/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.univ-pau.fr/pub/mirrors/fedora/%SUBDIR%/ \
	ftp://ftp.lip6.fr/pub/linux/distributions/fedora/%SUBDIR%/ \
	http://fr.rpmfind.net/linux/fedora/core/%SUBDIR%/ \
	http://www.gtlib.gatech.edu/pub/fedora.redhat/linux/core/%SUBDIR%/ \
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
	ftp://ftp.kreonet.re.kr/pub/Linux/fedora/core/%SUBDIR%/ \
	ftp://fedora.ifc.unam.mx/linux/fedora/core/%SUBDIR%/ \
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
	ftp://ftp.rdsor.ro/pub/Linux/Distributions/Fedora/%SUBDIR%/ \
	http://ftp.chg.ru/pub/Linux/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/Linux/fedora/linux/core/%SUBDIR%/ \
	http://ftp.rhd.ru/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.rhd.ru/pub/fedora/linux/core/%SUBDIR%/ \
	http://ftp.port80.se/fedora/core/%SUBDIR%/ \
	ftp://ftp.port80.se/fedora/core/%SUBDIR%/ \
	http://ftp.upjs.sk/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.upjs.sk/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.tlk-l.net/pub/mirrors/fedora.redhat.com/linux/core/%SUBDIR%/ \
	http://limestone.uoregon.edu/ftp/fedora/%SUBDIR%/ \
	ftp://limestone.uoregon.edu/fedora/%SUBDIR%/ \
	ftp://fedora.bu.edu/core/%SUBDIR%/ \
	http://mirror.anl.gov/pub/fedora-linux-core/%SUBDIR%/ \
	ftp://mirror.anl.gov/pub/fedora-linux-core/%SUBDIR%/ \
	ftp://ftp.cse.buffalo.edu/pub/Linux/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.applios.net/pub/fedora/linux/core/%SUBDIR%/ \
	http://mirror.steadfast.net/fedora/core/%SUBDIR%/ \
	http://mirror.eas.muohio.edu/fedora/linux/core/%SUBDIR%/ \
	http://mirror.engr.sjsu.edu/pub/fedora/linux/core/%SUBDIR%/ \
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
MASTER_SITE_FREEBSD_ORG+= \
	ftp://ftp.FreeBSD.org/pub/FreeBSD/%SUBDIR%/ \
	ftp://ftp.se.FreeBSD.org/pub/FreeBSD/%SUBDIR%/ \
	ftp://ftp.jp.FreeBSD.org/pub/FreeBSD/%SUBDIR%/ \
	ftp://ftp.uk.FreeBSD.org/pub/FreeBSD/%SUBDIR%/ \
	ftp://ftp.ru.FreeBSD.org/pub/FreeBSD/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/FreeBSD/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_FRUGALWARE)
MASTER_SITE_FRUGALWARE+= \
	ftp://ftp7.frugalware.org/pub/frugalware/frugalware-stable/source/%SUBDIR%/ \
	ftp://ftp2.frugalware.org/mirror/ftp.frugalware.org/pub/frugalware/frugalware-stable/source/%SUBDIR%/ \
	ftp://ftp6.frugalware.org/mirrors/linux/frugalware/frugalware-stable/source/%SUBDIR%/ \
	ftp://ftp4.frugalware.org/pub/linux/distributions/frugalware/frugalware-stable/source/%SUBDIR%/ \
	ftp://ftp12.frugalware.org/mirrors/ftp.frugalware.org/pub/frugalware/frugalware-stable/source/%SUBDIR%/ \
	ftp://ftp10.frugalware.org/pub/linux/frugalware/frugalware-stable/source/%SUBDIR%/
#	ftp://ftp5.frugalware.org/packages/frugalware/pub/frugalware/frugalware-stable/source/%SUBDIR%/
#	ftp://ftp3.frugalware.org/mirrors/frugalware/pub/frugalware/frugalware-stable/source/%SUBDIR%/
#	ftp://ftp9.frugalware.org/pub/frugalware/frugalware-stable/source/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GCC)
MASTER_SITE_GCC+= \
	${MASTER_SITE_SOURCEWARE:S,%SUBDIR%,gcc/&,} \
	ftp://gcc.gnu.org/pub/gcc/%SUBDIR%/ \
	ftp://mirrors.laffeycomputer.com/pub/gcc.gnu.org/pub/gcc/%SUBDIR%/ \
	ftp://ftp.lip6.fr/pub/gcc/%SUBDIR%/ \
	ftp://ftp.irisa.fr/pub/mirrors/gcc.gnu.org/gcc/%SUBDIR%/ \
	ftp://ftp.uvsq.fr/pub/gcc/%SUBDIR%/ \
	ftp://ftp.gwdg.de/pub/misc/gcc/%SUBDIR%/ \
	ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/gcc.gnu.org/pub/gcc/%SUBDIR%/ \
	ftp://ftp.iij.ad.jp/pub/gnu/gnu/gcc/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/lang/gcc/%SUBDIR%/ \
	ftp://ftp.nluug.nl/mirror/languages/gcc/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/sourceware.org/pub/gcc/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/gnu/gcc/%SUBDIR%/ \
	ftp://mirror.aarnet.edu.au/pub/gnu/gcc/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GENTOO)
MASTER_SITE_GENTOO+= \
	http://gentoo.mirrors.pair.com/%SUBDIR%/ \
	http://mirrors.tds.net/pub/gentoo/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/www.ibiblio.org/gentoo/%SUBDIR%/ \
	http://ftp.belnet.be/mirror/rsync.gentoo.org/gentoo/%SUBDIR%/ \
	http://ftp.snt.utwente.nl/pub/os/linux/gentoo/%SUBDIR%/ \
	http://trumpetti.atm.tut.fi/gentoo/%SUBDIR%/ \
	http://sunsite.cnlab-switch.ch/ftp/mirror/gentoo/%SUBDIR%/ \
	http://ftp.uni-erlangen.de/pub/mirrors/gentoo/%SUBDIR%/ \
	http://darkstar.ist.utl.pt/gentoo/%SUBDIR%/ \
	http://gentoo.inode.at/%SUBDIR%/ \
	http://ftp.rhnet.is/pub/gentoo/%SUBDIR%/ \
	http://gentoo.gg3.net/%SUBDIR%/ \
	http://gentoo.kems.net/%SUBDIR%/ \
	ftp://ftp.gtlib.gatech.edu/pub/gentoo/%SUBDIR%/ \
	ftp://mirror.iawnet.sandia.gov/pub/gentoo/%SUBDIR%/ \
	ftp://ftp.ussg.iu.edu/pub/linux/gentoo/%SUBDIR%/ \
	ftp://ftp.ucsb.edu/pub/mirrors/linux/gentoo/%SUBDIR%/ \
	ftp://gentoo.mirrors.pair.com/%SUBDIR%/ \
	ftp://mirrors.tds.net/pub/gentoo/%SUBDIR% \
	ftp://ftp.belnet.be/mirror/rsync.gentoo.org/gentoo/%SUBDIR%/ \
	ftp://ftp.snt.utwente.nl/pub/os/linux/gentoo/%SUBDIR%/ \
	ftp://trumpetti.atm.tut.fi/gentoo/%SUBDIR%/ \
	ftp://sunsite.cnlab-switch.ch/mirror/gentoo/%SUBDIR%/ \
	ftp://ftp6.uni-muenster.de/pub/linux/distributions/gentoo/%SUBDIR%/ \
	ftp://ftp.tu-clausthal.de/pub/linux/gentoo/%SUBDIR%/ \
	ftp://sunsite.informatik.rwth-aachen.de/pub/Linux/gentoo/%SUBDIR%/ \
	ftp://linux.rz.ruhr-uni-bochum.de/gentoo-mirror/%SUBDIR%/ \
	ftp://ftp.uni-erlangen.de/pub/mirrors/gentoo/%SUBDIR%/ \
	ftp://darkstar.ist.utl.pt/pub/gentoo/%SUBDIR%/ \
	ftp://gentoo.inode.at/source/%SUBDIR%/ \
	ftp://ftp.rhnet.is/pub/gentoo/%SUBDIR%/ \
	ftp://files.gentoo.gr/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GITHUB)
#
# In order to use GitHub your port must define USE_GITHUB and the following
# variables:
#
# GH_ACCOUNT    - account name of the GitHub user hosting the project
#                 default: not set, mandatory
#
# GH_PROJECT    - name of the project on GitHub
#                 default: ${PORTNAME}
#
# GH_TAGNAME    - name of the tag to download (2.0.1, hash, ...)
#                 Using the name of a branch here is incorrect. It is
#                 possible to do GH_TAGNAME=${GH_COMMIT} to do a snapshot
#                 default: ${DISTVERSION}
#
# GH_COMMIT     - first 7 digits of the commit that generated GH_TAGNAME
#                 (man git-describe(1))
#                 default: not set, mandatory
#
.if defined(USE_GITHUB)
.if defined(GH_TAGNAME) && ${GH_TAGNAME} == master
IGNORE?=	Using master as GH_TAGNAME is invalid. \
		Must use a tag or commit hash so the upstream does\
		not "reroll" as soon as the branch is updated
.endif
MASTER_SITE_GITHUB+=		https://codeload.github.com/%SUBDIR% \
				http://codeload.github.com/%SUBDIR%
MASTER_SITE_GITHUB_CLOUD+=	http://cloud.github.com/downloads/%SUBDIR%
.if !defined(MASTER_SITES) || !${MASTER_SITES:MGH} && !${MASTER_SITES:MGHC}
MASTER_SITES+=	GH GHC
.endif
GH_PROJECT?=	${PORTNAME}
GH_TAGNAME?=	${DISTVERSION}
FETCH_ARGS=	-Fpr
.endif
.endif
#
# GitHub files can also be obtained, without the commit hashes, by doing:
#
# MASTER_SITES=	http://github.com/accountname/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/
# FETCH_ARGS=	-Fpr
#

.if !defined(IGNORE_MASTER_SITE_GNOME)
MASTER_SITE_GNOME+= \
	ftp://ftp.belnet.be/mirror/ftp.gnome.org/%SUBDIR%/ \
	http://ftp.acc.umu.se/pub/GNOME/%SUBDIR%/ \
	ftp://ftp.cse.buffalo.edu/pub/Gnome/%SUBDIR%/ \
	http://fr2.rpmfind.net/linux/gnome.org/%SUBDIR%/ \
	http://www.gtlib.gatech.edu/pub/gnome/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/X/gnome/%SUBDIR%/ \
	http://linorg.usp.br/gnome/%SUBDIR%/ \
	http://mirror.aarnet.edu.au/pub/gnome/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,X/gnome/&,} \
	ftp://ftp.kddlabs.co.jp/pub/GNOME/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.gnome.org/pub/GNOME/%SUBDIR%/ \
	ftp://ftp.nara.wide.ad.jp/pub/X11/GNOME/%SUBDIR%/ \
	http://ftp.gnome.org/pub/GNOME/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GNU)
MASTER_SITE_GNU+= \
	http://ftp.gnu.org/gnu/%SUBDIR%/ \
	ftp://ftp.gnu.org/gnu/%SUBDIR%/ \
	http://www.gtlib.gatech.edu/pub/gnu/gnu/%SUBDIR%/ \
	http://mirrors.kernel.org/gnu/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/GNU/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/GNU/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,GNU/&,} \
	ftp://ftp.mirrorservice.org/sites/ftp.gnu.org/gnu/%SUBDIR%/ \
	ftp://ftp.informatik.hu-berlin.de/pub/gnu/gnu/%SUBDIR%/ \
	ftp://ftp.informatik.rwth-aachen.de/pub/mirror/ftp.gnu.org/pub/gnu/%SUBDIR%/ \
	http://ftp.funet.fi/pub/gnu/prep/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GNUPG)
MASTER_SITE_GNUPG+= \
	http://mirror.tje.me.uk/pub/mirrors/ftp.gnupg.org/%SUBDIR%/ \
	http://dotsrc.org/%SUBDIR%/ \
	ftp://ftp.freenet.de/pub/ftp.gnupg.org/gcrypt/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.gnupg.org/gcrypt/%SUBDIR%/ \
	ftp://mirror.cict.fr/gnupg/%SUBDIR%/ \
	http://artfiles.org/gnupg.org/%SUBDIR%/ \
	ftp://ftp.franken.de/pub/crypt/mirror/ftp.gnupg.org/gcrypt/%SUBDIR%/ \
	ftp://ftp.crysys.hu/pub/gnupg/%SUBDIR%/ \
	ftp://ftp.hi.is/pub/mirrors/gnupg/%SUBDIR%/ \
	http://ftp.heanet.ie/mirrors/ftp.gnupg.org/gcrypt/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/security/gnupg/%SUBDIR%/ \
	ftp://mirror.switch.ch/mirror/gnupg/%SUBDIR%/ \
	http://www.mirrorservice.org/sites/ftp.gnupg.org/gcrypt/%SUBDIR%/ \
	ftp://ftp.gnupg.org/gcrypt/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GNUSTEP)
MASTER_SITE_GNUSTEP+= \
	ftp://ftp.gnustep.org/pub/gnustep/%SUBDIR%/ \
	http://ftp.gnustep.org/pub/gnustep/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GNUSTEP_CH)
MASTER_SITE_GNUSTEP_CH+= \
	http://io.debian.net/~tar/ports/distfiles/
.endif

.if !defined(IGNORE_MASTER_SITE_GNU_ALPHA)
MASTER_SITE_GNU_ALPHA+= \
	ftp://alpha.gnu.org/pub/gnu/%SUBDIR%/ \
	ftp://ftp.lublin.pl/mirror/alpha.gnu.org/gnu/%SUBDIR%/ \
	ftp://ftp.ps.pl/mirrors/alpha.gnu.org/pub/gnu/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/mirrors/alpha.gnu.org/gnu/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GOOGLE_CODE)
PROJECTHOST?=	${PORTNAME}
MASTER_SITE_GOOGLE_CODE+= \
	http://${PROJECTHOST}.googlecode.com/files/
.endif

.if !defined(IGNORE_MASTER_SITE_HORDE)
MASTER_SITE_HORDE+= \
	http://ftp.horde.org/pub/%SUBDIR%/ \
	ftp://ftp.horde.org/pub/%SUBDIR%/ \
	ftp://ftp.at.horde.org/infosys/webapps/horde/%SUBDIR%/ \
	ftp://ftp.se.horde.org/mirror/horde/pub/%SUBDIR%/ \
	ftp://ftp.tw.horde.org/pub/%SUBDIR%/ \
	ftp://ftp.us.horde.org/pub/software/horde//%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_IDSOFTWARE)
MASTER_SITE_IDSOFTWARE+= \
	ftp://ftp.chg.ru/pub/games/idgames/idstuff/%SUBDIR%/ \
	http://ftp4.de.freesbie.org/pub/misc/ftp.idsoftware.com/idstuff/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/pc/games/idgames/idstuff/%SUBDIR%/ \
	ftp://ftp.gamers.org/pub/idgames/idstuff/%SUBDIR%/ \
	http://ftp.iinet.net.au/games/idstuff/%SUBDIR%/ \
	ftp://ftp.mirror.nl/disk2/idsoftware/idstuff/%SUBDIR%/ \
	ftp://freebsd.nsu.ru/mirrors/ftp.idsoftware.com/idstuff/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/vendors/idgames/idstuff/%SUBDIR%/ \
	ftp://ftp.omen.net.au/games/idstuff/%SUBDIR%/ \
	ftp://ftp.idsoftware.com/idstuff/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_ISC)
MASTER_SITE_ISC+= \
	http://ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.ciril.fr/pub/isc/%SUBDIR%/ \
	ftp://ftp.freenet.de/pub/ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.iij.ad.jp/pub/network/isc/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/net/isc/%SUBDIR%/ \
	ftp://ftp.u-aizu.ac.jp/pub/net/isc/%SUBDIR%/ \
	ftp://ftp.task.gda.pl/mirror/ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/network/isc/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.nominum.com/pub/isc/%SUBDIR%/ \
	ftp://ftp.ripe.net/mirrors/sites/ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/net/isc/isc/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/mirrors/ftp.isc.org/isc/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_KENAI)
MASTER_SITE_KENAI+= \
	http://projectkenai.com/downloads/%SUBDIR%/
.endif

# List:		http://download.kde.org/extra/mirrors.html
# Updated:	2012-10-26
.if !defined(IGNORE_MASTER_SITE_KDE)
MASTER_SITE_KDE+= \
	http://mirrors.isc.org/pub/kde/%SUBDIR%/ \
	ftp://ftp.gtlib.gatech.edu/pub/kde/%SUBDIR%/ \
	ftp://ftp.informatik.hu-berlin.de/pub/Mirrors/ftp.kde.org/%SUBDIR%/ \
	http://ftp.gtlib.gatech.edu/pub/kde/%SUBDIR%/ \
	ftp://ftp.solnet.ch/mirror/KDE/%SUBDIR%/ \
	ftp://gd.tuwien.ac.at/kde/%SUBDIR%/ \
	http://gd.tuwien.ac.at/kde/%SUBDIR%/ \
	http://kde.mirrors.tds.net/pub/kde/%SUBDIR%/ \
	ftp://ftp.rz.uni-wuerzburg.de/pub/unix/kde/%SUBDIR%/ \
	http://mirrors.dotsrc.org/kde/%SUBDIR%/ \
	ftp://mirrors.dotsrc.org/kde/%SUBDIR%/ \
	ftp://ftp.fi.muni.cz/pub/kde/%SUBDIR%/ \
	http://ftp.fi.muni.cz/pub/kde/%SUBDIR%/ \
	ftp://sunsite.icm.edu.pl/pub/unix/kde/%SUBDIR%/ \
	http://sunsite.icm.edu.pl/pub/unix/kde/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/X11/kde/%SUBDIR%/ \
	http://ftp.sunet.se/pub/X11/kde/%SUBDIR%/ \
	ftp://ftp.kde.org/pub/kde/%SUBDIR%/ \
	ftp://ftp.belnet.be/packages/kde/%SUBDIR%/ \
	http://ftp.belnet.be/packages/kde/%SUBDIR%/ \
	ftp://ftp.lip6.fr/pub/X11/kde/%SUBDIR%/ \
	http://www-ftp.lip6.fr/pub/X11/kde/%SUBDIR%/ \
	ftp://ftp.rhnet.is/pub/kde/%SUBDIR%/ \
	http://ftp.rhnet.is/pub/kde/%SUBDIR%/ \
	http://ftp-stud.fht-esslingen.de/Mirrors/ftp.kde.org/pub/kde/%SUBDIR%/ \
	ftp://ftp.cronyx.ru/pub/mirror/kde/%SUBDIR%/ \
	http://ftp.twaren.net/Unix/X/KDE/%SUBDIR%/ \
	ftp://ftp.na.kde.org/pub/kde/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/pub/unix/X11/gui/kde/%SUBDIR%/ \
	ftp://sunsite.informatik.rwth-aachen.de/pub/Linux/kde/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/X11/kde/%SUBDIR%/ \
	http://ftp.ntua.gr/pub/X11/kde/%SUBDIR%/ \
	ftp://ftp.heanet.ie/mirrors/ftp.kde.org/%SUBDIR%/ \
	http://ftp.heanet.ie/mirrors/ftp.kde.org/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/pub/X11/kde/%SUBDIR%/ \
	http://ftp.kddlabs.co.jp/pub/X11/kde/%SUBDIR%/ \
	http://ftp.cs.pu.edu.tw/pub/kde/%SUBDIR%/ \
	http://kde.mirror.uber.com.au/%SUBDIR%/ \
	ftp://ftp.ussg.iu.edu/pub/kde/%SUBDIR%/ \
	http://ftp.ussg.iu.edu/kde/%SUBDIR%/ \
	ftp://ftp.sayclub.com/pub/X/KDE/%SUBDIR%/ \
	http://ftp.sayclub.com/pub/X/KDE/%SUBDIR%/ \
	ftp://carroll.aset.psu.edu/pub/kde/%SUBDIR%/ \
	http://mirror.cc.columbia.edu/pub/software/kde/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.kde.org/pub/kde/%SUBDIR%/ \
	http://www.mirrorservice.org/sites/ftp.kde.org/pub/kde/%SUBDIR%/ \
	http://master.kde.org/%SUBDIR%/ \
	http://ftp.icm.edu.pl/pub/unix/kde/%SUBDIR%/ \
	http://kde-mirror.freenux.org/%SUBDIR%/ \
	http://ftp.fi.muni.cz/pub/kde/%SUBDIR%/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.kde.org/pub/kde/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,X/kde/&,} \
	ftp://ftp.funet.fi/pub/mirrors/ftp.kde.org/pub/kde/%SUBDIR%/ \
	http://ftp.funet.fi/pub/mirrors/ftp.kde.org/pub/kde/%SUBDIR%/ \
	http://download.kde.org/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_LOGILAB)
MASTER_SITE_LOGILAB+= \
	http://download.logilab.org/pub/%SUBDIR%/ \
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
	ftp://ftp.heanet.ie/pub/mozdev/%SUBDIR%/ \
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
	https://ftp.mozilla.org/pub/mozilla.org/%SUBDIR%/ \
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
	http://www.gtlib.gatech.edu/pub/mozilla.org/%SUBDIR%/ \
	ftp://ftp.mozilla.org/pub/mozilla.org/%SUBDIR%/ \
	ftp://ftp.fh-wolfenbuettel.de/pub/www/mozilla/%SUBDIR%/ \
	ftp://ftp.informatik.rwth-aachen.de/pub/mirror/ftp.mozilla.org/pub/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/mozilla/&,} \
	http://ftp.twaren.net/Unix/Mozilla/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_MOZILLA_EXTENDED)
MASTER_SITE_MOZILLA_EXTENDED+= \
	http://releases.mozilla.org/pub/mozilla.org/%SUBDIR%/ \
	${MASTER_SITE_MOZILLA}
.endif

.if !defined(IGNORE_MASTER_SITE_MPLAYERHQ)
MASTER_SITE_MPLAYERHQ+=	\
	http://www.mplayerhq.hu/MPlayer/%SUBDIR%/ \
	http://www1.mplayerhq.hu/MPlayer/%SUBDIR%/ \
	http://www2.mplayerhq.hu/MPlayer/%SUBDIR%/ \
	http://www3.mplayerhq.hu/MPlayer/%SUBDIR%/ \
	http://www4.mplayerhq.hu/MPlayer/%SUBDIR%/ \
	http://www5.mplayerhq.hu/MPlayer/%SUBDIR%/ \
	ftp://ftp.mplayerhq.hu/MPlayer/%SUBDIR%/ \
	ftp://ftp1.mplayerhq.hu/MPlayer/%SUBDIR%/ \
	ftp://ftp4.mplayerhq.hu/MPlayer/%SUBDIR%/ \
	ftp://ftp5.mplayerhq.hu/MPlayer/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_MYSQL)
MASTER_SITE_MYSQL+= \
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
	ftp://mirror.switch.ch/mirror/mysql/Downloads/%SUBDIR%/ \
	http://mysql.dp.ua/Downloads/%SUBDIR%/ \
	http://mysql.mirrored.ca/Downloads/%SUBDIR%/ \
	ftp://mirror.services.wisc.edu/mirrors/mysql/Downloads/%SUBDIR%/ \
	http://mysql.mirrors.pair.com/Downloads/%SUBDIR%/ \
	ftp://ftp.linorg.usp.br/mysql/Downloads/%SUBDIR%/ \
	ftp://ftp.cbn.net.id/mirror/mysql/Downloads/%SUBDIR%/ \
	ftp://ftp.easynet.be/mysql/Downloads/%SUBDIR%/ \
	http://download.softagency.net/MySQL/Downloads/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_NETBSD)
MASTER_SITE_NETBSD+= \
	ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.iastate.edu/pub/netbsd/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.plig.net/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.proxad.net/mirrors/ftp.netbsd.org/packages/distfiles/%SUBDIR%/\
	ftp://ftp.unina.it/pub/Unix/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.uninett.no/bsd/unix/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://sunsite.uio.no/bsd/unix/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.demon.co.uk/pub/mirrors/NetBSD/packages/distfiles/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,NetBSD/packages/distfiles/&,} \
	ftp://ftp.dti.ad.jp/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/NetBSD/packages/distfiles/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_NETLIB)
MASTER_SITE_NETLIB+= \
	ftp://ftp.netlib.org/%SUBDIR%/ \
	http://www.netlib.org/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.netlib.org/%SUBDIR%/ \
	http://www.mirrorservice.org/sites/ftp.netlib.org/%SUBDIR%/ \
	ftp://ftp.netlib.no/netlib/%SUBDIR%/ \
	http://www.netlib.no/netlib/%SUBDIR%/ \
	ftp://ftp.irisa.fr/pub/netlib/%SUBDIR%/ \
	http://artfiles.org/netlib.org/%SUBDIR%/ \
	http://netlib.amss.ac.cn/%SUBDIR%/ \
	http://netlib.caspur.it/%SUBDIR%/ \
	http://netlib.sandia.gov/%SUBDIR%/ \
	http://phase.hpcc.jp/mirrors/netlib/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_NVIDIA)
MASTER_SITE_NVIDIA+= \
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
	http://ftp.eu.openbsd.org/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp.openbsd.org/pub/OpenBSD/%SUBDIR%/ \
	ftp://openbsd.informatik.uni-erlangen.de/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp5.usa.openbsd.org/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp3.usa.openbsd.org/pub/OpenBSD/%SUBDIR%/ \
	ftp://rt.fm/pub/OpenBSD/%SUBDIR%/ \
	http://ftp.heanet.ie/pub/OpenBSD/%SUBDIR%/ \
	http://ftp.belnet.be/packages/openbsd/%SUBDIR%/ \
	http://mirror.pacific.net.au/OpenBSD/%SUBDIR%/ \
	http://ftp.openbsd.dk/pub/OpenBSD/%SUBDIR%/ \
	http://ftp.estpak.ee/pub/OpenBSD/%SUBDIR%/ \
	http://mirror.internode.on.net/pub/OpenBSD/%SUBDIR%/ \
	http://ftp.chg.ru/pub/OpenBSD/%SUBDIR%/ \
	http://ftp.arcane-networks.fr/pub/OpenBSD/%SUBDIR%/ \
	http://ftp.netbsd.se/OpenBSD/%SUBDIR%/ \
	http://openbsd.cs.pu.edu.tw/%SUBDIR%/ \
	http://www.mirrorservice.org/pub/OpenBSD/%SUBDIR%/ \
	http://mirror.switch.ch/ftp/pub/OpenBSD/%SUBDIR%/ \
	http://ftp.jaist.ac.jp/pub/OpenBSD/%SUBDIR%/ \
	http://ftp.cc.uoc.gr/mirrors/OpenBSD/%SUBDIR%/ \
	http://mirror.hostfuss.com/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp.stacken.kth.se/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp.ca.openbsd.org/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp.freebsdchina.org/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp.dkuug.dk/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp.jyu.fi/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp.irisa.fr/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp.nara.wide.ad.jp/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp.inet.no/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp.nluug.nl/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp.gamma.ru/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp.rediris.es/pub/OpenBSD/%SUBDIR%/ \
	ftp://ftp.su.se/pub/OpenBSD/%SUBDIR%/ \
	ftp://osmirrors.cerias.purdue.edu/pub/OpenBSD/%SUBDIR%/ \
	ftp://carroll.cac.psu.edu/pub/OpenBSD/%SUBDIR%/ \
	ftp://openbsd.mirrors.tds.net/pub/OpenBSD/%SUBDIR%/ \
	http://mirrors.nic.funet.fi/pub/OpenBSD/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_OSSP)
MASTER_SITE_OSSP+= \
	ftp://ftp.ossp.org/pkg/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/utils/ossp/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_PACKETSTORM)
MASTER_SITE_PACKETSTORM+= \
	http://dl.packetstormsecurity.net/%SUBDIR%/ \
	http://packetstorm.codar.com.br/%SUBDIR%/ \
	http://packetstorm.igor.onlinedirect.bg/%SUBDIR%/ \
	http://packetstorm.interhost.co.il/%SUBDIR%/ \
	http://packetstorm.foofus.com/%SUBDIR%/ \
	http://packetstorm.tacticalflex.com/%SUBDIR%/ \
	http://packetstorm.unixteacher.org/%SUBDIR%/ \
	http://packetstorm.wowhacker.com/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_PERL_CPAN)

_PERL_CPAN_SORT?= modules/by-module

# Please add URI to MASTER_SITE_PERL_CPAN_BY instead of this one.
MASTER_SITE_PERL_CPAN?=

MASTER_SITE_PERL_CPAN_BY+= \
	ftp://ftp.cpan.org/pub/CPAN/%CPANSORT%/%SUBDIR%/ \
	http://www.cpan.dk/%CPANSORT%/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/lang/perl/CPAN/%CPANSORT%/%SUBDIR%/ \
	http://ftp.jaist.ac.jp/pub/CPAN/%CPANSORT%/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/lang/perl/CPAN/%CPANSORT%/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/cpan.perl.org/CPAN/%CPANSORT%/%SUBDIR%/ \
	http://at.cpan.org/%CPANSORT%/%SUBDIR%/ \
	ftp://ftp.auckland.ac.nz/pub/perl/CPAN/%CPANSORT%/%SUBDIR%/ \
	http://backpan.perl.org/%CPANSORT%/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/languages/perl/CPAN/%CPANSORT%/%SUBDIR%/ \
	http://ftp.twaren.net/Unix/Lang/CPAN/%CPANSORT%/%SUBDIR%/ \
	ftp://ftp.cpan.org/pub/CPAN/modules/by-module/%SUBDIR%/ \
	http://www.cpan.dk/modules/by-module/%SUBDIR%/

_PERL_CPAN_FLAG=${MASTER_SITE_SUBDIR:C/(CPAN):.*$/\1/}
_PERL_CPAN_ID=	${MASTER_SITE_SUBDIR:C/^CPAN:(.)(.)(.*)$/\1\/\1\2\/\1\2\3/}

.if !empty(_PERL_CPAN_ID) && ${_PERL_CPAN_FLAG:L} == "cpan"
    _PERL_CPAN_SORT=authors/id/${_PERL_CPAN_ID}
    MASTER_SITE_PERL_CPAN=${MASTER_SITE_PERL_CPAN_BY:S/%CPANSORT%/${_PERL_CPAN_SORT}/:S/%SUBDIR%\///}
.else
    MASTER_SITE_PERL_CPAN=${MASTER_SITE_PERL_CPAN_BY:S/%CPANSORT%/${_PERL_CPAN_SORT}/}
.endif

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
	ftp://ftp.se.postgresql.org/pub/databases/relational/postgresql/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,misc/db/postgresql/&,} \
	ftp://ftp2.cz.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp.ee.postgresql.org/mirrors/postgresql/%SUBDIR%/ \
	ftp://ftp3.de.postgresql.org/pub/Mirrors/ftp.postgresql.org/%SUBDIR%/ \
	ftp://ftp.gr.postgresql.org/pub/databases/postgresql/%SUBDIR%/ \
	ftp://ftp.ie.postgresql.org/mirrors/ftp.postgresql.org/pub/%SUBDIR%/ \
	ftp://ftp2.it.postgresql.org/mirrors/postgres/%SUBDIR%/ \
	http://ftp2.jp.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp.lv.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp2.nl.postgresql.org/mirror/postgresql/%SUBDIR%/ \
	ftp://ftp6.pl.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp7.pl.postgresql.org/pub/mirror/ftp.postgresql.org/%SUBDIR%/ \
	ftp://ftp6.ro.postgresql.org/pub/mirrors/ftp.postgresql.org/%SUBDIR%/ \
	ftp://ftp3.ru.postgresql.org/pub/mirror/postgresql/pub/%SUBDIR%/ \
	ftp://ftp5.es.postgresql.org/mirror/postgresql/%SUBDIR%/ \
	ftp://ftp3.tw.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp.postgresql.org/pub/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_PHP)
MASTER_SITE_PHP+= \
	http://dk1.php.net/%SUBDIR%/ \
	http://de.php.net/%SUBDIR%/ \
	http://es.php.net/%SUBDIR%/ \
	http://fr.php.net/%SUBDIR%/ \
	http://gr.php.net/%SUBDIR%/ \
	http://it.php.net/%SUBDIR%/ \
	http://jp.php.net/%SUBDIR%/ \
	http://se.php.net/%SUBDIR%/ \
	http://uk3.php.net/%SUBDIR%/ \
	http://us2.php.net/%SUBDIR%/ \
	http://br.php.net/%SUBDIR%/ \
	http://cn.php.net/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/php/&,}
.endif

.if !defined(IGNORE_MASTER_SITE_PYTHON)
MASTER_SITE_PYTHON+= \
	http://www.python.org/%SUBDIR%/ \
	http://python.ilisys.com.au/%SUBDIR%/ \
	http://www.linux.org.hk/mirror/python/%SUBDIR%/ \
	http://mirrors.sunsite.dk/pythonwww/%SUBDIR%/ \
	http://python.emdia.fi/%SUBDIR%/ \
	http://SunSITE.Informatik.RWTH-Aachen.DE/python/%SUBDIR%/ \
	http://www.auth.gr/mirrors/python/%SUBDIR%/ \
	http://www.cwi.nl/www.python.org/%SUBDIR%/ \
	http://gnu.kookel.org/ftp/www.python.org/%SUBDIR%/ \
	http://python.holywar.net/%SUBDIR%/ \
	http://mirrors.ccs.neu.edu/Python/pub/www.python.org/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_QMAIL)
MASTER_SITE_QMAIL+= \
	http://qmail.geto.net/%SUBDIR%/ \
	http://qmail.palomine.net/%SUBDIR%/ \
	http://qmail.mirrors.summersault.com/%SUBDIR%/ \
	http://qmail.cdsinet.net/%SUBDIR%/ \
	http://qmail.glasswings.com.au/%SUBDIR%/ \
	http://qmail.psshee.com/%SUBDIR%/ \
	http://mirrors.sunsite.dk/qmailwww/%SUBDIR%/ \
	http://www.agria.hu/qmail/%SUBDIR%/ \
	http://qmail.rhnet.is/%SUBDIR%/ \
	http://mirrors.dataloss.nl/www.qmail.org/%SUBDIR%/ \
	http://www.math.ntnu.no/mirror/www.qmail.org/%SUBDIR%/ \
	http://qmail.netvisao.pt/%SUBDIR%/ \
	http://qmail.ipg.sk/%SUBDIR%/ \
	http://qmail.omnis.ch/%SUBDIR%/ \
	http://qmail.asylog.net/%SUBDIR%/ \
	http://qmail.blueyonder.co.uk/%SUBDIR%/ \
	http://www.qmail.org/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_QT)
MASTER_SITE_QT+= \
	http://download.qt-project.org/%SUBDIR%/ \
	http://master.qt-project.org/%SUBDIR%/ \
	http://www.mirrorservice.org/sites/download.qt-project.org/%SUBDIR%/ \
	http://www.nic.funet.fi/pub/mirrors/download.qt-project.org/%SUBDIR%/ \
	http://qtmirror.ics.com/pub/qtproject/%SUBDIR%/ \
	http://anychimirror101.mirrors.tds.net/pub/Qt/%SUBDIR%/ \
	http://www.las.ic.unicamp.br/pub/qtproject/%SUBDIR%/ \
	http://linorg.usp.br/Qt/%SUBDIR%/ \
	http://ftp.jaist.ac.jp/pub/qtproject/%SUBDIR%/ \
	http://mirrors.neusoft.edu.cn/qt/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_REDHAT_LINUX)
MASTER_SITE_REDHAT_LINUX+= \
	http://mirrors.usc.edu/pub/linux/distributions/redhat/redhat/linux/%SUBDIR%/ \
	http://www.gtlib.gatech.edu/pub/redhat/linux/%SUBDIR%/ \
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
MASTER_SITE_RINGSERVER+= \
	http://ring.nict.go.jp/archives/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_RUBY)
MASTER_SITE_RUBY+= \
	ftp://ftp.ruby-lang.org/pub/ruby/%SUBDIR%/ \
	ftp://ftp.SpringDaemons.com/pub/ruby/ruby/%SUBDIR%/ \
	http://www.ibiblio.org/pub/languages/ruby/%SUBDIR%/ \
	ftp://xyz.lcs.mit.edu/pub/ruby/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,lang/ruby/&,} \
	ftp://ftp.fu-berlin.de/unix/languages/ruby/%SUBDIR%/ \
	ftp://ftp.easynet.be/ruby/ruby/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/lang/ruby/%SUBDIR%/ \
	ftp://ftp.kr.FreeBSD.org/pub/ruby/%SUBDIR%/ \
	http://mirrors.sunsite.dk/ruby/%SUBDIR%/ \
	ftp://ftp.iDaemons.org/pub/mirror/ftp.ruby-lang.org/ruby/%SUBDIR%/
.endif

# See http://rubyforge.org/credits/
.if !defined(IGNORE_MASTER_SITE_RUBYFORGE)
MASTER_SITE_RUBYFORGE+= \
	http://files.rubyforge.vm.bytemark.co.uk/%SUBDIR%/
.endif

# See http://rubygems.org/pages/about
.if !defined(IGNORE_MASTER_SITE_RUBYGEMS)
MASTER_SITE_RUBYGEMS+= \
	http://production.s3.rubygems.org/gems/%SUBDIR%/ \
	http://production.cf.rubygems.org/gems/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_SAMBA)
MASTER_SITE_SAMBA+= \
	http://ftp.samba.org/pub/%SUBDIR%/ \
	ftp://ca.samba.org/pub/%SUBDIR%/ \
	ftp://de.samba.org/pub/%SUBDIR%/ \
	ftp://ftp.easynet.be/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/samba/&,}
.endif

# List:	http://download.savannah.gnu.org/mirmon/
.if !defined(IGNORE_MASTER_SITE_SAVANNAH)
MASTER_SITE_SAVANNAH+= \
	http://nongnu.askapache.com/%SUBDIR%/ \
	http://mirror.lihnidos.org/GNU/savannah/%SUBDIR%/ \
	http://ftp.twaren.net/Unix/NonGNU/%SUBDIR%/ \
	ftp://ftp.twaren.net/Unix/NonGNU/%SUBDIR%/ \
	http://gnu.mirrors.pair.com/savannah/savannah/%SUBDIR%/ \
	ftp://gnu.mirrors.pair.com/savannah/%SUBDIR%/ \
	http://download-mirror.savannah.gnu.org/releases/%SUBDIR%/
.endif

# List:		http://sourceforge.net/apps/trac/sourceforge/wiki/Mirrors
# Updated:	2013-03-25
.if !defined(IGNORE_MASTER_SITE_SOURCEFORGE)
.for mirror in heanet sunet iweb switch freefr garr aarnet jaist master \
	nchc ncu internode waix hivelocity superb-dca3 ufpr tenet \
	netcologne ignum kent kaz
MASTER_SITE_SOURCEFORGE+= \
	http://${mirror}.dl.sourceforge.net/project/%SUBDIR%/
.endfor
.endif

.if !defined(IGNORE_MASTER_SITE_SOURCEFORGE_JP)
.for mirror in iij jaist keihanna osdn
MASTER_SITE_SOURCEFORGE_JP+= \
	http://${mirror}.dl.sourceforge.jp/%SUBDIR%/
.endfor
.endif

.if !defined(IGNORE_MASTER_SITE_SOURCEWARE)
MASTER_SITE_SOURCEWARE+= \
	http://mirrors.kernel.org/sources.redhat.com/%SUBDIR%/ \
	http://gd.tuwien.ac.at/gnu/sourceware/%SUBDIR%/ \
	http://ftp.cs.pu.edu.tw/Linux/sourceware/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/mirrors/sources.redhat.com/pub/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_SUDO)
MASTER_SITE_SUDO+= \
	http://www.sudo.ws/sudo/dist/ \
	http://ftp.arcane-networks.fr/pub/mirrors/sudo/ \
	http://sudo.p8ra.de/sudo/dist/ \
	http://sudo.cybermirror.org/ \
	http://sudo-ftp.basemirror.de/ \
	http://core.ring.gr.jp/archives/misc/sudo/ \
	http://www.ring.gr.jp/archives/misc/sudo/ \
	http://ftp.twaren.net/Unix/Security/Sudo/ \
	ftp://ftp.sudo.ws/pub/sudo/ \
	ftp://plier.ucar.edu/pub/sudo/ \
	ftp://obsd.isc.org/pub/sudo/ \
	ftp://ftp.uwsg.indiana.edu/pub/security/sudo/ \
	ftp://ftp.tuwien.ac.at/utils/admin-tools/sudo/ \
	ftp://sunsite.ualberta.ca/pub/Mirror/sudo/ \
	ftp://zoot.tele.dk/pub/sudo/ \
	ftp://ftp.in2p3.fr/pub/sudo/ \
	ftp://ftp.arcane-networks.fr/pub/mirrors/sudo/ \
	ftp://ftp.usbm.de/pub/sudo/ \
	ftp://ftp.cs.tu-berlin.de/pub/misc/sudo/ \
	ftp://ftp.informatik.uni-hamburg.de/pub/os/unix/utils/sudo/ \
	ftp://ftp.st.ryukoku.ac.jp/pub/security/tool/sudo/ \
	ftp://ftp.cin.nihon-u.ac.jp/pub/misc/sudo/ \
	ftp://core.ring.gr.jp/pub/misc/sudo/ \
	ftp://ftp.ring.gr.jp/pub/misc/sudo/ \
	ftp://sunsite.icm.edu.pl/packages/sudo/ \
	ftp://mirror.cdmon.com/pub/sudo/ \
	ftp://ftp.twaren.net/Unix/Security/Sudo/
.endif

.if !defined(IGNORE_MASTER_SITE_SUNSITE)
MASTER_SITE_SUNSITE+= \
	http://www.ibiblio.org/pub/Linux/%SUBDIR%/ \
	http://www.gtlib.gatech.edu/pub/Linux/%SUBDIR%/ \
	ftp://ftp.cs.tu-berlin.de/pub/linux/Mirrors/sunsite.unc.edu/%SUBDIR%/ \
	ftp://ftp.etsimo.uniovi.es/pub/linux/%SUBDIR%/ \
	ftp://ftp.lip6.fr/pub/linux/sunsite/%SUBDIR%/ \
	ftp://ftp.nluug.nl/pub/metalab/%SUBDIR%/ \
	ftp://ftp.nvg.ntnu.no/pub/mirrors/metalab.unc.edu/%SUBDIR%/ \
	ftp://ftp.icm.edu.pl/pub/Linux/sunsite/%SUBDIR%/ \
	ftp://ftp.cse.cuhk.edu.hk/pub4/Linux/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/Linux/metalab.unc.edu/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/Linux/sunsite/%SUBDIR%/ \
	ftp://ftp.sun.ac.za/pub/mirrors/sunsite.unc.edu/pub/Linux/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_SUSE)
MASTER_SITE_SUSE+= 	\
	http://mirrors.usc.edu/pub/linux/distributions/suse/%SUBDIR%/ \
	http://mirror.usu.edu/mirrors/suse/%SUBDIR%/ \
	ftp://mirror.mcs.anl.gov/pub/suse/%SUBDIR%/ \
	ftp://chuck.ucs.indiana.edu/linux/suse/suse/%SUBDIR%/ \
	ftp://ftp.oregonstate.edu/pub/suse/suse/%SUBDIR%/ \
	ftp://ftp.sunsite.utk.edu/pub/linux/suse/suse/%SUBDIR%/ \
	http://sunsite.utk.edu/ftp/pub/linux/suse/suse/%SUBDIR%/ \
	http://mirror.tamu.edu/suse/%SUBDIR%/ \
	ftp://ftp.empiricalnetworks.com/pub/suse/%SUBDIR%/ \
	http://suse.cs.utah.edu/suse/%SUBDIR%/ \
	ftp://ftp.belnet.be/linux/suse/suse/%SUBDIR%/ \
	http://ftp.unicamp.br/pub/suse/%SUBDIR%/ \
	ftp://mirrors.netbg.com/suse/%SUBDIR%/ \
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
	ftp://ftp.rz.uni-kiel.de/pub2/linux/suse/%SUBDIR%/ \
	http://mirrors.sth.sze.hu/linux/suse/%SUBDIR%/ \
	ftp://ftp.heanet.ie/mirrors/ftp.suse.com/pub/suse/ftp.suse.com/suse/%SUBDIR%/ \
	ftp://ftp.unina.it/pub/linux/distributions/SuSE/ftp.suse.com/suse/%SUBDIR%/ \
	ftp://ftp.uniroma2.it/Linux/suse/pub/suse/%SUBDIR%/ \
	ftp://ftp.riken.jp/Linux/suse/suse/%SUBDIR%/ \
	ftp://ftp.kddilabs.jp/Linux/packages/SuSE/suse/%SUBDIR%/ \
	ftp://ftp.novell.co.jp/pub/suse/suse/%SUBDIR%/ \
	ftp://ftp.kreonet.re.kr/pub/Linux/suse/%SUBDIR%/ \
	http://ftp.tpnet.pl/vol/d7/ftp.suse.com/%SUBDIR%/ \
	ftp://ftp.icm.edu.pl/packages/linux-suse/%SUBDIR%/ \
	http://ftp.idilis.ro/mirrors/ftp.suse.com/pub/suse/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/Linux/distributions/suse/suse/%SUBDIR%/ \
	ftp://ftp.solnet.ch/mirror/SuSE/%SUBDIR%/ \
	ftp://sunsite.cnlab-switch.ch/mirror/SuSE/suse/%SUBDIR%/ \
	http://ftp.isu.edu.tw/pub/Linux/SuSE/%SUBDIR%/ \
	ftp://ftp.kde.org/pub/suse/ftp.suse.com/suse/%SUBDIR%/ \
	ftp://ftp.suse.com/pub/suse/%SUBDIR%/ \
	ftp://ftp.softnet.tuc.gr/pub/linux/suse/suse/%SUBDIR%/ \
	http://ftp.softnet.tuc.gr/pub/linux/suse/suse/%SUBDIR%/ \
	ftp://ftp.is.co.za/linux/distributions/suse/%SUBDIR%/ \
	http://ftp.sun.ac.za/ftp/mirrorsites/suse/%SUBDIR%/ \
	ftp://ftp.rediris.es/pub/linux/distributions/suse/pub/suse/%SUBDIR%/ \
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
	ftp://ftp.kddlabs.co.jp/lang/tcl/ftp.scriptics.com/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.tcl.tk/pub/tcl/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/languages/tcl/tcl/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_TEX_CTAN)
MASTER_SITE_TEX_CTAN+= \
	ftp://ctan.unsw.edu.au/tex-archive/%SUBDIR%/ \
	ftp://ftp.tex.ac.uk/tex-archive/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/CTAN/%SUBDIR%/ \
	ftp://ctan.tug.org/tex-archive/%SUBDIR%/ \
	ftp://ftp.dante.de/tex-archive/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,text/CTAN/&,} \
	ftp://ftp.chg.ru/pub/TeX/CTAN/%SUBDIR%/ \
	ftp://mirror.macomnet.net/pub/CTAN/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/TeX/CTAN/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_THEMES)
MASTER_SITE_THEMES+= \
	http://download.freshmeat.net/themes/%SUBDIR%/ \
	ftp://gd.tuwien.ac.at/opsys/linux/freshmeat/themes/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_TUCOWS)
.for mirror in ankara blueyonder casemanl chariot clix dataphone dialog epix \
	fastweb genotec hellasonline iinets inspirenet latvia mclink netvisao \
	ns-linux nyi otenet personainternet pl-task ukms
MASTER_SITE_TUCOWS+= \
	http://${mirror}.linux.tucows.com/files/%SUBDIR%/
.endfor
MASTER_SITE_TUCOWS+= \
	http://www12.tucows.com/linux/files/%SUBDIR%/ \
	http://linux.tucows.gunadarma.ac.id/files/%SUBDIR%/
.endif

# List:		http://www.vim.org/mirrors.php
# Updated:	2013-08-19
.if !defined(IGNORE_MASTER_SITE_VIM)
MASTER_SITE_VIM+= \
	http://ftp.vim.org/pub/vim/unix/ \
	http://artfiles.org/vim.org/unix/ \
	http://ftp.gr.vim.org/pub/vim/unix/ \
	http://ftp.stut.edu.tw/vim/unix/ \
	http://ftp.tw.vim.org/pub/vim/unix/ \
	http://ftp.vim.ossmirror.de/pub/vim/unix/ \
	http://ftp2.jp.vim.org/pub/vim/unix/ \
	http://ftp2.kr.vim.org/pub/vim/unix/ \
	http://ftp2.tw.vim.org/pub/vim/unix/ \
	http://ftp2.uk.vim.org/pub/vim/unix/ \
	http://servingzone.com/mirrors/vim/unix/ \
	http://tweedo.com/mirror/ftp.vim.org/unix/ \
	http://vim.cybermirror.org/unix/ \
	http://vim.mirror.fr/unix/ \
	ftp://ftp.home.vim.org/pub/vim/unix/ \
	ftp://artfiles.org/vim.org/unix/ \
	ftp://ftp.ar.vim.org/pub/vim/unix/ \
	ftp://ftp.ca.vim.org/pub/vim/unix/ \
	ftp://ftp.de.vim.org/unix/ \
	ftp://ftp.gr.vim.org/pub/vim/unix/ \
	ftp://ftp.is.vim.org/pub/vim/unix/ \
	ftp://ftp.jp.vim.org/pub/vim/unix/ \
	ftp://ftp.pl.vim.org/pub/vim/unix/ \
	ftp://ftp.stut.edu.tw/pub/vim/unix/ \
	ftp://ftp.uk.vim.org/pub/vim/unix/ \
	ftp://ftp.za.vim.org/mirrors/ftp.vim.org/unix/ \
	ftp://ftp2.kr.vim.org/pub/vim/unix/ \
	ftp://ftp2.tw.vim.org/pub/vim/unix/ \
	ftp://ftp2.uk.vim.org/pub/vim/unix/ \
	ftp://ftp3.de.vim.org/pub/vim/unix/ \
	ftp://vim.tsu.ru/pub/vim/unix/
.endif

.if !defined(IGNORE_MASTER_SITE_WINDOWMAKER)
MASTER_SITE_WINDOWMAKER+= \
	ftp://ftp.windowmaker.info/pub/%SUBDIR%/ \
	ftp://ftp.uvsq.fr/pub/X11/window-managers/windowmaker/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/X/WindowMaker/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_XCONTRIB)
MASTER_SITE_XCONTRIB+= \
	ftp://ftp.gwdg.de/pub/x11/x.org/contrib/%SUBDIR%/ \
	ftp://ftp.x.org/contrib/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/X11/ftp.x.org/contrib/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/X/XFree86/mirror/X.Org/contrib/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/X11/ftp.x.org/contrib/%SUBDIR%/ \
	ftp://ftp2.x.org/contrib/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,X/opengroup/contrib/&,}
.endif

.if !defined(IGNORE_MASTER_SITE_XEMACS)
MASTER_SITE_XEMACS+= \
	http://ftp.it.xemacs.org/%SUBDIR%/ \
	http://ftp.pt.xemacs.org/%SUBDIR%/ \
	http://xemacsftp.hkmirror.org/%SUBDIR%/ \
	http://ftp.dti.ad.jp/pub/unix/editor/xemacs/%SUBDIR%/ \
	http://ftp.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.be.xemacs.org/xemacs/%SUBDIR%/ \
	ftp://ftp.ch.xemacs.org/mirror/xemacs/%SUBDIR%/ \
	ftp://ftp.de.xemacs.org/pub/ftp.xemacs.org/tux/xemacs/%SUBDIR%/ \
	ftp://ftp.fi.xemacs.org/pub/mirrors/ftp.xemacs.org/pub/tux/xemacs/%SUBDIR%/ \
	ftp://ftp.fr.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.gr.xemacs.org/mirrors/XEmacs/ftp/%SUBDIR%/ \
	ftp://ftp.heanet.ie/mirrors/ftp.xemacs.org/%SUBDIR%/ \
	ftp://ftp.ie.xemacs.org/mirrors/ftp.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.no.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.pasteur.fr/pub/computing/xemacs/%SUBDIR%/ \
	ftp://ftp.sa.xemacs.org/pub/xemacs.org/%SUBDIR%/ \
	ftp://ftp.se.xemacs.org/pub/gnu/xemacs/%SUBDIR%/ \
	ftp://ftp.tw.xemacs.org/Unix/Editors/XEmacs/%SUBDIR%/ \
	ftp://ftp.uk.xemacs.org/sites/ftp.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.yz.yamagata-u.ac.jp/pub/misc/xemacs/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,text/xemacs/&,}
.endif

.if !defined(IGNORE_MASTER_SITE_XFCE)
MASTER_SITE_XFCE+= \
	http://mirror.perldude.de/archive.xfce.org/%SUBDIR%/ \
	http://mirror.netcologne.de/xfce/%SUBDIR%/ \
	http://ftp.udc.es/xfce/%SUBDIR%/ \
	http://xfce.mirror.uber.com.au/%SUBDIR%/ \
	http://archive.be.xfce.org/%SUBDIR%/ \
	http://archive.be2.xfce.org/%SUBDIR%/ \
	http://archive.se.xfce.org/%SUBDIR%/ \
	http://archive.al-us.xfce.org/%SUBDIR%/ \
	http://mirrors.tummy.com/pub/archive.xfce.org/%SUBDIR%/ \
	http://mirror.yongbok.net/X11/xfce-mirror/%SUBDIR%/ \
	http://xfce.ognisco.com/%SUBDIR%/ \
	http://mirror.sinn3r.org/xfce/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_XORG)
MASTER_SITE_XORG+= \
	http://xorg.freedesktop.org/releases/%SUBDIR%/ \
	http://xorg.mirrors.pair.com/%SUBDIR%/ \
	http://mirror.us.leaseweb.net/xorg/%SUBDIR%/ \
	http://mirror.csclub.uwaterloo.ca/x.org/%SUBDIR%/ \
	http://artfiles.org/x.org/pub/%SUBDIR%/ \
	http://ftp.gwdg.de/pub/x11/x.org/pub/%SUBDIR%/ \
	http://gd.tuwien.ac.at/X11/%SUBDIR%/ \
	http://mi.mirror.garr.it/mirrors/x.org/%SUBDIR%/ \
	http://mirror.switch.ch/ftp/mirror/X11/pub/%SUBDIR%/ \
	http://mirrors.ircam.fr/pub/x.org/%SUBDIR%/ \
	http://www.mirrorservice.org/sites/ftp.x.org/pub/%SUBDIR%/ \
	http://www.portal-to-web.de/pub/mirrors/x.org/%SUBDIR%/ \
	http://x.cybermirror.org/%SUBDIR%/ \
	http://x.europnews.de/pub/%SUBDIR%/ \
	http://xorg.mirror.solnet.ch/pub/%SUBDIR%/ \
	http://mirror.nl.leaseweb.net/xorg/%SUBDIR%/ \
	http://mirror.de.leaseweb.net/xorg/%SUBDIR%/ \
	http://mirrors.go-part.com/xorg/%SUBDIR%/ \
	http://ftp.yz.yamagata-u.ac.jp/pub/X11/x.org/%SUBDIR%/ \
	http://ftp.kaist.ac.kr/x.org/%SUBDIR%/ \
	http://x.cs.pu.edu.tw/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_KERNEL_ORG)
MASTER_SITE_KERNEL_ORG+= \
	https://www.kernel.org/pub/%SUBDIR%/ \
	ftp://ftp.ntu.edu.tw/%SUBDIR%/ \
	http://ftp.sunet.se/pub/Linux/kernel.org/%SUBDIR%/ \
	http://ftp.yandex.ru/pub/%SUBDIR%/ \
	http://ftp.heanet.ie/pub/%SUBDIR%/ \
	http://slackware.cs.utah.edu/pub/kernel.org/pub/%SUBDIR%/
.endif

# Macro magic

MASTER_SITES_ABBREVS=	CPAN:PERL_CPAN \
			GH:GITHUB \
			GHC:GITHUB_CLOUD \
			NL:NETLIB \
			SF:SOURCEFORGE \
			SFJP:SOURCEFORGE_JP \
			RG:RUBYGEMS \
			RF:RUBYFORGE
MASTER_SITES_SUBDIRS=	\
			APACHE_JAKARTA:${PORTNAME:S,-,/,}/source \
			BERLIOS:${PORTNAME:L} \
			CENKES:myports \
			CHEESESHOP:source/${DISTNAME:C/(.).*/\1/}/${DISTNAME:C/(.*)-[0-9].*/\1/} \
			CSME:myports \
			DEBIAN:pool/main/${PORTNAME:C/^((lib)?.).*$/\1/}/${PORTNAME} \
			GCC:releases/${DISTNAME} \
			GITHUB:${GH_ACCOUNT}/${GH_PROJECT}/legacy.tar.gz/${GH_TAGNAME}?dummy=/ \
			GITHUB_CLOUD:${GH_ACCOUNT}/${GH_PROJECT}/ \
			GNOME:sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/} \
			GNU:${PORTNAME} \
			HORDE:${PORTNAME} \
			LOGILAB:${PORTNAME} \
			MOZDEV:${PORTNAME:L} \
			NETLIB:${PORTNAME} \
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
