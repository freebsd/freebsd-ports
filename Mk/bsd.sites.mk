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
.if !defined(IGNORE_MASTER_SITE_LOCAL)
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
.endif

##
##	KEEP THIS LIST SORTED
##

.if !defined(IGNORE_MASTER_SITE_AFTERSTEP)
MASTER_SITE_AFTERSTEP+=	\
	ftp://ftp.afterstep.org/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/X11/window_manager/AfterStep/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/X/AfterStep/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/X11/windowmanagers/afterstep/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_APACHE)
MASTER_SITE_APACHE+=	\
	http://www.apache.org/dist/%SUBDIR%/ \
	http://archive.apache.org/dist/%SUBDIR%/ \
	ftp://ftp.planetmirror.com/pub/apache/dist/%SUBDIR%/ \
	ftp://ftp.pop-mg.com.br/pub/apache/dist/%SUBDIR%/ \
	ftp://ftp.gin.cz/pub/mirrors/www.apache.org/dist/%SUBDIR%/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.apache.org/dist/%SUBDIR%/ \
	ftp://ftp.apache.de/mirrors/dev.apache.org/dist/%SUBDIR%/ \
	ftp://mir1.ovh.net/ftp.apache.org/dist/%SUBDIR%/ \
	ftp://ftp.forthnet.gr/pub/www/apache/dist/%SUBDIR%/ \
	ftp://sunsite.srce.hr/mirrors/ftp.apache.org/apache/dist/%SUBDIR%/ \
	ftp://xenia.sote.hu/pub/mirrors/www.apache.org/%SUBDIR%/ \
	ftp://ftp.esat.net/mirrors/ftp.apache.org/%SUBDIR%/ \
	ftp://ftp.heanet.ie/mirrors/www.apache.org/dist/%SUBDIR%/ \
	ftp://ftp.rhnet.is/pub/apache/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/apache/dist/&,} \
	ftp://ftp.sogang.ac.kr/www/apache/dist/%SUBDIR%/ \
	ftp://ftp.task.gda.pl/pub/www/apache/dist/%SUBDIR%/ \
	ftp://sunsite.icm.edu.pl/pub/www/apache/dist/%SUBDIR%/ \
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
	ftp://ftp.ccs.neu.edu/net/mirrors/Apache/dist/%SUBDIR%/ \
	ftp://ftp.tux.org/pub/net/apache/dist/%SUBDIR%/ \
	ftp://ftp.saix.net/pub/apache/dist/%SUBDIR%/ \
	http://nagoya.apache.org/mirror/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_APACHE_HTTPD)
MASTER_SITE_APACHE_HTTPD+=	\
	${MASTER_SITE_APACHE:S,%SUBDIR%,httpd/&,}
.endif

.if !defined(IGNORE_MASTER_SITE_APACHE_JAKARTA)
MASTER_SITE_APACHE_JAKARTA+=	\
	${MASTER_SITE_APACHE:S,%SUBDIR%,jakarta/&,}
.endif

.if !defined(IGNORE_MASTER_SITE_APACHE_XML)
MASTER_SITE_APACHE_XML+=	\
	${MASTER_SITE_APACHE:S,%SUBDIR%,xml/&,}
.endif

.if !defined(IGNORE_MASTER_SITE_COMP_SOURCES)
MASTER_SITE_COMP_SOURCES+=	\
	ftp://gatekeeper.dec.com/pub/usenet/comp.sources.%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/Unix/com.sources.%SUBDIR%/ \
	ftp://ftp.uu.net/usenet/comp.sources.%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/archive/comp.sources.%SUBDIR%/ \
	ftp://rtfm.mit.edu/pub/usenet/comp.sources.%SUBDIR%/
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
.endif

.if !defined(IGNORE_MASTER_SITE_DEBIAN_POOL)
MASTER_SITE_DEBIAN_POOL+=	\
	${MASTER_SITE_DEBIAN:C|(/%SUBDIR%/)|/pool/main/${PORTNAME:C/^(.).*$/\1/}/${PORTNAME}/|}
.endif

.if !defined(IGNORE_MASTER_SITE_ECLIPSE)
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
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,misc/eclipse/downloads/drops/&,} \
	http://mirror.island.liu.se/eclipse/downloads/drops/%SUBDIR%/ \
	ftp://sunsite.cnlab-switch.ch/mirror/eclipse/downloads/drops/%SUBDIR%/ \
	ftp://eclipse.cis.sinica.edu.tw/eclipse.org/%SUBDIR%/ \
	http://eclipse.cis.sinica.edu.tw/downloads/drops/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_EXIM)
MASTER_SITE_EXIM+=	\
	ftp://ftp.csx.cam.ac.uk/pub/software/email/exim/%SUBDIR%/ \
	ftp://ftp.exim.org/pub/exim/%SUBDIR%/ \
	http://public.planetmirror.com/pub/exim/exim/%SUBDIR%/ \
	ftp://ftp.easynet.be/exim/exim/%SUBDIR%/ \
	ftp://mirror.kn.vutbr.cz/pub/ftp.exim.org/exim/%SUBDIR%/ \
	ftp://sunsite.auc.dk/pub/mail/exim/exim/%SUBDIR%/ \
	ftp://ftp.doc.cs.univ-paris8.fr/mirrors/ftp.exim.org/exim/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/unix/mail/exim/%SUBDIR%/ \
	ftp://ftp.tin.org/pub/mail/exim/%SUBDIR%/ \
	ftp://ftp.freenet.de/pub/ftp.csx.cam.ac.uk/pub/software/email/exim/%SUBDIR%/ \
	ftp://ftp.esat.net/pub/networking/mail/mta/exim/%SUBDIR%/ \
	ftp://exim.stupendous.net/mirror/exim/exim/%SUBDIR%/ \
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
	http://www.us.exim.org/ftp/exim/%SUBDIR%/ \
	ftp://ftp.fsckit.net/pub/exim/exim/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_FEDORA_LINUX)
MASTER_SITE_FEDORA_LINUX+= \
	ftp://limestone.uoregon.edu/fedora/%SUBDIR%/ \
	ftp://mirror.stanford.edu/pub/mirrors/fedora/linux/core/%SUBDIR%/ \
	http://mirrors.kernel.org/fedora/core/%SUBDIR%/ \
	ftp://mirrors.kernel.org/fedora/core/%SUBDIR%/ \
	http://mirror.web-ster.com/fedora/%SUBDIR%/ \
	ftp://mirror.web-ster.com/fedora/%SUBDIR%/ \
	ftp://fedora.cs.utah.edu/pub/fedora/linux/core/%SUBDIR%/ \
	http://fedora.cat.pdx.edu/linux/core/%SUBDIR%/ \
	ftp://fedora.cat.pdx.edu/linux/core/%SUBDIR%/ \
	http://www.opensourcemirrors.org/linux/fedora/%SUBDIR%/ \
	ftp://ftp.opensourcemirrors.org/linux/fedora/%SUBDIR%/ \
	http://mirrors.xmission.com/fedora/core/%SUBDIR%/ \
	ftp://mirrors.xmission.com/fedora/core/%SUBDIR%/ \
	http://mirror.engr.sjsu.edu/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://mirror.engr.sjsu.edu/pub/fedora/linux/core/%SUBDIR%/ \
	http://mirror.usu.edu/mirrors/fedora/linux/core/%SUBDIR%/ \
	ftp://mirror.usu.edu/mirrors/fedora/linux/core/%SUBDIR%/ \
	ftp://acmserver.cs.ucr.edu/fedora/core/%SUBDIR%/ \
	ftp://wuarchive.wustl.edu/mirrors/linux/distributions/fedora/%SUBDIR%/ \
	ftp://redhat.taygeta.com/pub/RedHat/fedora/core/%SUBDIR%/ \
	ftp://ftp.uci.edu/mirrors/fedora/linux/core/%SUBDIR%/ \
	http://mirrors.usc.edu/pub/linux/distributions/fedora/%SUBDIR%/ \
	ftp://mirrors.usc.edu/pub/linux/distributions/fedora/%SUBDIR%/ \
	ftp://mirror.colorado.edu/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.linux.ncsu.edu/pub/fedora/linux/core/%SUBDIR%/ \
	http://mirror.linux.duke.edu/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://mirror.linux.duke.edu/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://mirror.cs.princeton.edu/pub/mirrors/fedora/linux/core/%SUBDIR%/ \
	http://distro.ibiblio.org/pub/linux/distributions/fedora/linux/core/%SUBDIR%/ \
	ftp://distro.ibiblio.org/pub/linux/distributions/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.cse.buffalo.edu/pub/fedora/linux/core/%SUBDIR%/ \
	http://mirror.eas.muohio.edu/fedora/linux/core/%SUBDIR%/ \
	ftp://mirror.eas.muohio.edu/pub/fedora/linux/core/%SUBDIR%/ \
	http://mirror.hiwaay.net/redhat/fedora/linux/core/%SUBDIR%/ \
	ftp://mirror.hiwaay.net/redhat/fedora/linux/core/%SUBDIR%/ \
	ftp://mirrors.hpcf.upr.edu/pub/Mirrors/redhat/download.fedora.redhat.com/%SUBDIR%/ \
	ftp://ftp.net.usf.edu/pub/fedora/linux/core/%SUBDIR%/ \
	http://redhat.secsup.org/fedora/core/%SUBDIR%/ \
	ftp://redhat.secsup.org/pub/linux/redhat/fedora/core/%SUBDIR%/ \
	http://rpmfind.net/linux/fedora/core/%SUBDIR%/ \
	ftp://rpmfind.net/linux/fedora/core/%SUBDIR%/ \
	ftp://ftp.dc.aleron.net/pub/linux/fedora/linux/core/%SUBDIR%/ \
	ftp://mirror.newnanutilities.org/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.software.umn.edu/pub/linux/fedora/core/%SUBDIR%/ \
	ftp://ftp.webtrek.com/pub/mirrors/fedora/%SUBDIR%/ \
	ftp://ftp.gtlib.cc.gatech.edu/pub/fedora.redhat/linux/core/%SUBDIR%/ \
	http://www.gtlib.cc.gatech.edu/pub/fedora.redhat/linux/core/%SUBDIR%/ \
	ftp://mirror.clarkson.edu/pub/distributions/fedora/%SUBDIR%/ \
	http://mirror.clarkson.edu/pub/distributions/fedora/%SUBDIR%/ \
	ftp://fedora.mirrors.tds.net/pub/fedora-core/%SUBDIR%/ \
	http://linux.nssl.noaa.gov/fedora/core/%SUBDIR%/ \
	ftp://linux.nssl.noaa.gov/fedora/core/%SUBDIR%/ \
	http://mirror.cs.wisc.edu/pub/mirrors/linux/download.fedora.redhat.com/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://mirror.cs.wisc.edu/pub/mirrors/linux/download.fedora.redhat.com/pub/fedora/linux/core/%SUBDIR%/ \
	http://fedora.glorb.com/core/%SUBDIR%/ \
	http://ftp.ale.org/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.ale.org/mirrors/fedora/linux/core/%SUBDIR%/ \
	http://ftp.ndlug.nd.edu/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.ndlug.nd.edu/pub/fedora/linux/core/%SUBDIR%/ \
	http://fedora.server4you.net/fedora/core/%SUBDIR%/ \
	ftp://fedora.server4you.net/fedora/core/%SUBDIR%/ \
	http://thales.memphis.edu/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://thales.memphis.edu/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://mirrors.ptd.net/fedora/core/%SUBDIR%/ \
	http://less.cogeco.net/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://less.cogeco.net/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.nrc.ca/pub/systems/linux/redhat/fedora/linux/core/%SUBDIR%/ \
	ftp://redhat.eyetap.org/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.telus.net/pub/fedora/linux/core/%SUBDIR%/ \
	http://gulus.usherbrooke.ca/pub/distro/fedora/linux/core/%SUBDIR%/ \
	http://mirror.cpsc.ucalgary.ca/mirror/fedora/linux/core/%SUBDIR%/ \
	ftp://mirror.cpsc.ucalgary.ca/mirror/fedora/linux/core/%SUBDIR%/ \
	http://ftp.muug.mb.ca/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.muug.mb.ca/pub/fedora/linux/core/%SUBDIR%/ \
	http://fedora.mirrored.ca/fedora/%SUBDIR%/ \
	ftp://fedora.mirrored.ca/fedora/%SUBDIR%/ \
	http://ftp.univie.ac.at/systems/linux/fedora/%SUBDIR%/ \
	ftp://ftp.univie.ac.at/systems/linux/fedora/%SUBDIR%/ \
	ftp://ftp.tugraz.at/mirror/redhat-linux/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.uni-klu.ac.at/linux/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.scarlet.be/pub/fedora/%SUBDIR%/ \
	http://ftp.belnet.be/linux/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.belnet.be/linux/fedora/linux/core/%SUBDIR%/ \
	http://mirrors.evrocom.net/fedora/linux/core/%SUBDIR%/ \
	ftp://mirrors.evrocom.net/pub/fedora/linux/core/%SUBDIR%/ \
	http://sunsite.mff.cuni.cz/pub/fedora/%SUBDIR%/ \
	ftp://sunsite.mff.cuni.cz/pub/fedora/%SUBDIR%/ \
	ftp://ultra.linux.cz/pub/fedora/%SUBDIR%/ \
	ftp://ftp.fi.muni.cz/pub/linux/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp6.linux.cz/pub/linux/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp1.skynet.cz/pub/linux/fedora%SUBDIR%/ \
	ftp://ftp.gin.cz/pub/fedora/core/%SUBDIR%/ \
	ftp://klid.dk/pub/fedora/linux/core/%SUBDIR%/ \
	http://redhat.linux.ee/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://redhat.linux.ee/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/mirrors/ftp.redhat.com/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.ipv6.funet.fi/pub/mirrors/ftp.redhat.com/pub/fedora/linux/core/%SUBDIR%/ \
	http://ftp.crihan.fr/mirrors/fedora.redhat.com/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.crihan.fr/mirrors/fedora.redhat.com/fedora/linux/core/%SUBDIR%/ \
	ftp://fr.rpmfind.net/linux/fedora/core/%SUBDIR%/ \
	http://fr2.rpmfind.net/linux/fedora/core/%SUBDIR%/ \
	ftp://fr2.rpmfind.net/linux/fedora/core/%SUBDIR%/ \
	ftp://ftp.ciril.fr/pub/linux/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.proxad.net/mirrors/fedora.redhat.com/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.univ-pau.fr/pub/mirrors/fedora/%SUBDIR%/ \
	http://ftp.inria.vthd.prd.fr/pub/linux/fedora/%SUBDIR%/ \
	ftp://ftp.inria.vthd.prd.fr/pub/linux/fedora/%SUBDIR%/ \
	http://wftp.tu-chemnitz.de/pub/linux/fedora-core/%SUBDIR%/ \
	ftp://ftp.tu-chemnitz.de/pub/linux/fedora-core/%SUBDIR%/ \
	ftp://ftp.uni-bayreuth.de/pub/linux/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.stw-bonn.de/pub/mirror/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.join.uni-muenster.de/pub/linux/distributions/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.informatik.uni-frankfurt.de/pub/linux/Mirror/ftp.redhat.com/fedora/core/%SUBDIR%/ \
	ftp://sunsite.informatik.rwth-aachen.de/pub/Linux/fedora-core/%SUBDIR%/ \
	ftp://ftp.rhein-zeitung.de/mirrors/fedora.redhat.com/%SUBDIR%/ \
	ftp://ftp.uni-erlangen.de/pub/Linux/MIRROR.fedora/core%SUBDIR%/ \
	http://ftp-stud.fht-esslingen.de/pub/Mirrors/fedora.redhat.com/linux/core/%SUBDIR%/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/fedora.redhat.com/linux/core/%SUBDIR%/ \
	http://ftp.uni-koeln.de/mirrors/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.uni-koeln.de/mirrors/fedora/linux/core/%SUBDIR%/ \
	http://download.atrpms.net/mirrors/fedoracore/%SUBDIR%/ \
	ftp://ftp.tvnet.hu/pub/fedora/linux/core/%SUBDIR%/ \
	http://mirrors.sth.sze.hu/linux/fedora/%SUBDIR%/ \
	ftp://mirrors.sth.sze.hu/linux/fedora/%SUBDIR%/ \
	http://ftp.rhnet.is/pub/fedora/%SUBDIR%/ \
	ftp://ftp.rhnet.is/pub/fedora/%SUBDIR%/ \
	http://ftp.heanet.ie/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.heanet.ie/pub/fedora/linux/core/%SUBDIR%/ \
	http://ftp.esat.net/pub/linux/fedora/%SUBDIR%/ \
	ftp://ftp.esat.net/pub/linux/fedora/%SUBDIR%/ \
	ftp://ftp.edisontel.com/pub/Fedora_Mirror/%SUBDIR%/ \
	ftp://ftp.quicknet.nl/pub/Linux/download.fedora.redhat.com/%SUBDIR%/ \
	ftp://alviss.et.tudelft.nl/pub/fedora/core/%SUBDIR%/ \
	http://ftp.surfnet.nl/ftp/pub/os/Linux/distr/fedora/%SUBDIR%/ \
	ftp://ftp.surfnet.nl/pub/os/Linux/distr/fedora/%SUBDIR%/ \
	http://ftp.nluug.nl/ftp/pub/os/Linux/distr/fedora/%SUBDIR%/ \
	ftp://ftp.nluug.nl/pub/os/Linux/distr/fedora/%SUBDIR%/ \
	ftp://ftp.easynet.nl/mirror/fedora/%SUBDIR%/ \
	ftp://ftp.eu.uu.net/pub/linux/fedora/%SUBDIR%/ \
	ftp://ftp.uninett.no/pub/linux/Fedora/core/%SUBDIR%/ \
	ftp://tux.cprm.net/pub/ftp.redhat.com/fedora/linux/core/%SUBDIR%/ \
	http://ftp.di.fct.unl.pt/pub/linux/fedora/%SUBDIR%/ \
	ftp://ftp.di.fct.unl.pt/pub/linux/fedora/%SUBDIR%/ \
	ftp://ftp.wsisiz.edu.pl/mirror/download.fedora.redhat.com/%SUBDIR%/ \
	ftp://ftp.pbone.net/pub/fedora/pub/fedora/linux/core/%SUBDIR%/ \
	http://sunsite.icm.edu.pl/pub/Linux/fedora/linux/core/%SUBDIR%/ \
	ftp://sunsite.icm.edu.pl/pub/Linux/fedora/linux/core/%SUBDIR%/ \
	http://ftp.man.poznan.pl/pub/linux/fedora/%SUBDIR%/ \
	ftp://ftp.man.poznan.pl/pub/linux/fedora/%SUBDIR%/ \
	http://ftp.ps.pl/pub/linux/fedora-core/%SUBDIR%/ \
	ftp://ftp.ps.pl/pub/linux/fedora-core/%SUBDIR%/ \
	http://ftp.iasi.roedu.net/mirrors/fedora.redhat.com/core/%SUBDIR%/ \
	http://ftp.iasi.roedu.net/pub/mirrors/fedora.redhat.com/core/%SUBDIR%/ \
	http://ftp.idilis.ro/mirrors/fedora/core/%SUBDIR%/ \
	ftp://ftp.idilis.ro/mirrors/fedora/core%SUBDIR%/ \
	http://ftp.lug.ro/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.lug.ro/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.rdsor.ro/pub/Linux/Distributions/Fedora/%SUBDIR%/ \
	ftp://ftp.kappa.ro/pub/Linux/Distributions/fedora/%SUBDIR%/ \
	http://ftp.chg.ru/pub/Linux/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/Linux/fedora/linux/core/%SUBDIR%/ \
	http://ftp.rhd.ru/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.rhd.ru/pub/fedora/linux/core/%SUBDIR%/ \
	http://ftp.mrtech.ru/pub/mirror/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.mrtech.ru/pub/mirror/fedora/linux/core/%SUBDIR%/ \
	http://fedora.officepark.ru%SUBDIR%/ \
	ftp://fedora.officepark.ru/%SUBDIR%/ \
	http://mirror.etf.bg.ac.yu/fedora/linux/core/%SUBDIR%/ \
	ftp://mirror.etf.bg.ac.yu/fedora/linux/core/%SUBDIR%/ \
	http://mirrors.bevc.net/fedora/%SUBDIR%/ \
	ftp://ftp.bevc.net/mirrors/fedora/%SUBDIR%/ \
	ftp://ftp.chl.chalmers.se/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://mirror.switch.ch/mirror/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.tlk-l.net/pub/mirrors/fedora.redhat.com/linux/core/%SUBDIR%/ \
	ftp://fedora.org.ua/pub/linux/fedora/%SUBDIR%/ \
	http://zeniiia.linux.org.uk/pub/distributions/fedora/linux/core/%SUBDIR%/ \
	ftp://zeniiia.linux.org.uk/pub/distributions/fedora/linux/core/%SUBDIR%/ \
	http://www.mirrorservice.org/sites/download.fedora.redhat.com/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/download.fedora.redhat.com/pub/fedora/linux/core/%SUBDIR%/ \
	http://www.mirror.ac.uk/sites/fedora.redhat.com/%SUBDIR%/ \
	http://mirror.poundhost.com/fedora.redhat.com/%SUBDIR%/ \
	ftp://mirror.poundhost.com/pub/fedora.redhat.com/%SUBDIR%/ \
	http://download.stmc.edu.hk/fedora/linux/core/%SUBDIR%/ \
	ftp://download.stmc.edu.hk/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.hostrino.com/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.sfc.wide.ad.jp/pub/Linux/Fedora/%SUBDIR%/ \
	http://ftp.kddilabs.jp/Linux/packages/fedora/core/%SUBDIR%/ \
	ftp://ftp.kddilabs.jp/Linux/packages/fedora/core/%SUBDIR%/ \
	ftp://ftp.riken.go.jp/pub/Linux/fedora/core/%SUBDIR%/ \
	ftp://ftp.kreonet.re.kr/pub/Linux/fedora/core/%SUBDIR%/ \
	ftp://mirror.hostway.co.kr/pub/fedora/%SUBDIR%/ \
	ftp://ftp.kaist.ac.kr/pub/fedora/linux/core/%SUBDIR%/ \
	http://mymirror.asiaosc.org/redhat/fedora/core/%SUBDIR%/ \
	ftp://ftp.oss.eznetsols.org/linux/fedora/%SUBDIR%/ \
	http://ftp.isu.edu.tw/pub/Linux/Fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.isu.edu.tw/pub/Linux/Fedora/linux/core/%SUBDIR%/ \
	http://planetmirror.com/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.planetmirror.com/pub/fedora/linux/core/%SUBDIR%/ \
	http://www.las.ic.unicamp.br/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://www.las.ic.unicamp.br/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://mirror.pop-rs.rnp.br/pub/download.fedora.redhat.com/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.tecnoera.com/pub/fedora/linux/%SUBDIR%/ \
	ftp://mirror.netglobalis.net/pub/fedora/%SUBDIR%/ \
	ftp://ftp.telmexchile.cl/Unix/fedora/linux/core/%SUBDIR%/ \
	http://ftp.isu.net.sa/pub/mirrors/fedora.redhat.com/%SUBDIR%/ \
	ftp://ftp.isu.net.sa/pub/mirrors/fedora.redhat.com/fedora/%SUBDIR%/ \
	http://ftp.udl.es/pub/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.udl.es/pub/fedora/linux/core/%SUBDIR%/ \
	http://ftp.rediris.es/mirror/fedora.redhat/%SUBDIR%/ \
	ftp://ftp.rediris.es/mirror/fedora.redhat/%SUBDIR%/ \
	ftp://ftp.cica.es/fedora/linux/core%SUBDIR%/ \
	http://ftp.caliu.info/pub/distribucions/fedora/%SUBDIR%/ \
	ftp://ftp.caliu.info/pub/distribucions/fedora/%SUBDIR%/ \
	ftp://ftp.linux.org.tr/pub/fedora/linux/core/%SUBDIR%/ \
	http://mirrors.cs.hacettepe.edu.tr/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.cs.hacettepe.edu.tr/pub/mirrors/fedora/linux/core/%SUBDIR%/ \
	http://ftp.ntua.gr/pub/linux/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/linux/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.otenet.gr/pub/linux/fedora/linux/core/%SUBDIR%/ \
	ftp://fedora.namibia.na/pub/fedora/%SUBDIR%/ \
	ftp://ftp.is.co.za/linux/distributions/fedora/linux/core/%SUBDIR%/ \
	ftp://ftp.netcraft.com.au/pub/fedora/linux/core/%SUBDIR%/ \
	http://mirror.pacific.net.au/linux/redhat/fedora/%SUBDIR%/ \
	ftp://mirror.pacific.net.au/linux/redhat/fedora/%SUBDIR%/ \
	ftp://ftp.wicks.co.nz/pub/linux/dist/fedora/%SUBDIR%/ \
	http://fedora.quicknet.nl/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_FESTIVAL)
MASTER_SITE_FESTIVAL+= \
	http://www.festvox.org/packed/festival/%SUBDIR%/ \
	http://www.speech.cs.cmu.edu/festival/cstr/festival/%SUBDIR%/ \
	ftp://rpmfind.net/linux/blinux/festival/mirror.festival_home/%SUBDIR%/ \
	ftp://speakeasy.rpmfind.net/linux/blinux/festival/mirror.festival_home/%SUBDIR%/\
	ftp://ftp.mayn.de/pub/linux/BLinux/festival/mirror.festival_home/%SUBDIR%/ \
	ftp://ftp.tuwien.ac.at/opsys/linux/blinux/festival/mirror.festival_home/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_FESTIVAL_OGI)
MASTER_SITE_FESTIVAL_OGI+= \
	ftp://rpmfind.net/linux/blinux/festival/mirror.ogi-synth_home/%SUBDIR%/\
	ftp://speakeasy.rpmfind.net/linux/blinux/festival/mirror.ogi-synth_home/%SUBDIR%/\
	ftp://ftp.mayn.de/pub/linux/BLinux/festival/mirror.ogi-synth_home/ \
	ftp://ftp.tuwien.ac.at/opsys/linux/blinux/festival/mirror.ogi-synth_home/ \
	ftp://cslu.cse.ogi.edu/pub/tts/
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
	ftp://ftp.nectec.or.th/pub/FreeBSD/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/FreeBSD/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,FreeBSD/&,}
.endif

.if !defined(IGNORE_MASTER_SITE_GCC)
MASTER_SITE_GCC+=	\
	${MASTER_SITE_SOURCEWARE:S,%SUBDIR%,gcc/&,}  \
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
	ftp://ftp.nluug.nl/mirror/languages/gcc/%SUBDIR%/ \
	ftp://ftp.task.gda.pl/pub/gnu/gcc/%SUBDIR%/ \
	ftp://sunsite.icm.edu.pl/pub/gnu/gcc/%SUBDIR%/ \
	ftp://ftp.nctu.edu.tw/computer-languages/C/gcc/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/sources.redhat.com/pub/gcc/%SUBDIR%/ \
	ftp://ftp.softaplic.com.br/pub/sourceware/gcc/%SUBDIR%/ \
	ftp://linux.ihep.su/pub/cygnus/egcs/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/gnu/gcc/%SUBDIR%/ \
	ftp://mirror.aarnet.edu.au/pub/gcc/%SUBDIR%/ \
	ftp://linux.sarang.net/pub/mirror/gnu/gnu/gcc/%SUBDIR%/ \
	ftp://ftp.sun.ac.za/mirrorsites/sourceware.cygnus.com/pub/gcc/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GENTOO)
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
	ftp://ftp.mirrorservice.org/sites/www.ibiblio.org/gentoo/%SUBDIR%/ \
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
.endif

.if !defined(IGNORE_MASTER_SITE_GNOME)
MASTER_SITE_GNOME+=	\
	ftp://ftp.belnet.be/mirror/ftp.gnome.org/%SUBDIR%/ \
	http://ftp.linux.org.uk/mirrors/ftp.gnome.org/%SUBDIR%/ \
	ftp://ftp.no.gnome.org/pub/GNOME/%SUBDIR%/ \
	ftp://ftp.dit.upm.es/linux/gnome/%SUBDIR%/ \
	http://ftp.rpmfind.net/linux/gnome.org/%SUBDIR%/ \
	ftp://ftp.dataplus.se/pub/linux/gnome/%SUBDIR%/ \
	ftp://ftp.cse.buffalo.edu/pub/Gnome/%SUBDIR%/ \
	http://ftp.unina.it/pub/linux/GNOME/%SUBDIR%/ \
	http://www.gtlib.cc.gatech.edu/pub/gnome/%SUBDIR%/ \
	http://archive.progeny.com/GNOME/%SUBDIR%/ \
	http://www.zentek-international.com/mirrors/gnome/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/X/gnome/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,X/gnome/&,} \
	ftp://ftp.kddlabs.co.jp/pub/GNOME/%SUBDIR%/ \
	http://public.planetmirror.com/pub/gnome/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.gnome.org/pub/GNOME/%SUBDIR%/ \
	http://ftp.gnome.org/pub/GNOME/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GNU)
MASTER_SITE_GNU+=	\
	http://ftp.gnu.org/gnu/%SUBDIR%/ \
	ftp://ftp.gnu.org/gnu/%SUBDIR%/ \
	http://ftp.lug.udel.edu/pub/gnu/%SUBDIR%/ \
	http://gnu.mirror.mcgill.ca/%SUBDIR%/ \
	ftp://ftp.nstu.ru/pub/mirrors/ftp.gnu.org/gnu/%SUBDIR%/ \
	http://www.gtlib.cc.gatech.edu/pub/gnu/gnu/%SUBDIR%/ \
	http://mirrors.usc.edu/pub/gnu/%SUBDIR%/ \
	http://gatekeeper.dec.com/pub/GNU/%SUBDIR%/ \
	ftp://ftp.de.uu.net/pub/gnu/%SUBDIR%/ \
	http://ftp.funet.fi/pub/gnu/prep/%SUBDIR%/ \
	ftp://ftp.leo.org/pub/comp/os/unix/gnu/%SUBDIR%/ \
	ftp://ftp.wustl.edu/mirrors/gnu/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/GNU/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/GNU/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,GNU/&,} \
	ftp://ftp.mirrorservice.org/sites/ftp.gnu.org/gnu/%SUBDIR%/ \
	ftp://ftp.sunsite.org.uk/package/gnu/%SUBDIR%/ \
	ftp://ftp.informatik.hu-berlin.de/pub/gnu/%SUBDIR%/ \
	ftp://ftp.informatik.rwth-aachen.de/pub/mirror/ftp.gnu.org/pub/gnu/%SUBDIR%/ \
	http://ftp.rediris.es/sites/ftp.gnu.org/pub/%SUBDIR%/ \
	ftp://ftp.lip6.fr/pub/gnu/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/gnu/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GNUPG)
MASTER_SITE_GNUPG+= 	\
	ftp://ftp.gnupg.org/gcrypt/%SUBDIR%/ \
	http://ftp.sunsite.dk/pub/security/gcrypt/%SUBDIR%/ \
	http://ftp.linux.it/pub/mirrors/gnupg/%SUBDIR%/ \
	ftp://ftp.demon.nl/pub/mirrors/gnupg/%SUBDIR%/ \
	ftp://ftp.ayamura.org/pub/gnupg/%SUBDIR%/ \
	ftp://sunsite.dk/pub/security/gcrypt/%SUBDIR%/ \
	ftp://ftp.jyu.fi/pub/crypt/gcrypt/%SUBDIR%/ \
	ftp://ftp.freenet.de/pub/ftp.gnupg.org/gcrypt/%SUBDIR%/ \
	ftp://ftp.surfnet.nl/pub/security/gnupg/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.gnupg.org/gcrypt/%SUBDIR%/ \
	ftp://sunsite.cnlab-switch.ch/mirror/gcrypt/%SUBDIR%/ \
	ftp://ftp.iasi.roedu.net/pub/mirrors/ftp.gnupg.org/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/gnupg/&,} \
	http://trumpetti.atm.tut.fi/gcrypt/%SUBDIR%/ \
	ftp://igloo.linux.gr/pub/crypto/gnupg/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GNUSTEP)
MASTER_SITE_GNUSTEP+= \
	http://python.planetmirror.com/pub/gnustep/gnustep/%SUBDIR%/ \
	ftp://ftp.gnustep.org/pub/gnustep/%SUBDIR%/ \
	ftp://ftp.easynet.nl/mirror/GNUstep/pub/gnustep/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GNU_ALPHA)
MASTER_SITE_GNU_ALPHA+=	\
	ftp://alpha.gnu.org/pub/gnu/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/mirrors/alpha.gnu.org/gnu/%SUBDIR%/ \
	ftp://ftp.lublin.pl/mirror/alpha.gnu.org/gnu/%SUBDIR%/ \
	ftp://ftp.ps.pl/mirrors/alpha.gnu.org/pub/gnu/%SUBDIR%/ \
	http://public.planetmirror.com/pub/gnu-alpha/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_ISC)
MASTER_SITE_ISC+=	\
	ftp://ftp.isc.org/isc/%SUBDIR%/ \
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
	ftp://ftp.sunet.se/pub/network/isc/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.epix.net/pub/isc/%SUBDIR%/ \
	ftp://ftp.nominum.com/pub/isc/%SUBDIR%/ \
	ftp://ftp.nerdc.ufl.edu/pub/mirrors/ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.ripe.net/mirrors/sites/ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.nl.uu.net/pub/mirrors/ftp.isc.org/%SUBDIR%/ \
	ftp://ftp.pop-mg.com.br/pub/isc/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/net/isc/isc/%SUBDIR%/ \
	ftp://ftp.metu.edu.tr/pub/mirrors/ftp.isc.org/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_KDE)
MASTER_SITE_KDE+=	\
	ftp://download.kde.org/pub/kde/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,X/kde/&,}
.endif

.if !defined(IGNORE_MASTER_SITE_MOZILLA)
MASTER_SITE_MOZILLA+= \
	http://ftp.mozilla.org/pub/mozilla.org/%SUBDIR%/ \
	http://www.gtlib.cc.gatech.edu/pub/mozilla.org/%SUBDIR%/ \
	http://mozilla.gnusoft.net/%SUBDIR%/ \
	ftp://ftp.mozilla.org/pub/mozilla.org/%SUBDIR%/ \
	ftp://ftp.belnet.be/packages/mozilla/%SUBDIR%/ \
	ftp://ftp.fh-wolfenbuettel.de/pub/www/mozilla/%SUBDIR%/ \
	ftp://ftp.uni-bayreuth.de/pub/packages/netscape/mozilla/%SUBDIR%/ \
	ftp://ftp.informatik.rwth-aachen.de/pub/mirror/ftp.mozilla.org/pub/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/mozilla/&,} \
	ftp://ftp.rediris.es/mirror/mozilla/%SUBDIR%/ \
	ftp://ftp.kaist.ac.kr/pub/mozilla/%SUBDIR%/ \
	ftp://mozilla.mirror.pacific.net.au/mozilla/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/WWW/mozilla/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_MYSQL)
MASTER_SITE_MYSQL+=	\
	ftp://ftp.easynet.be/mysql/Downloads/%SUBDIR%/ \
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
	ftp://mysql.mirror.trueserver.nl/pub/mirror/mysql/Downloads/%SUBDIR%/ \
	http://mysql.l.rt-comm.ru/Downloads/%SUBDIR%/ \
	ftp://mirror.etf.bg.ac.yu/mysql/Downloads/%SUBDIR%/ \
	ftp://mirror.switch.ch/mirror/mysql/Downloads/%SUBDIR%/ \
	http://mysql.dp.ua/Downloads/%SUBDIR%/ \
	http://mysql.mirrored.ca/Downloads/%SUBDIR%/ \
	ftp://mysql.azc.uam.mx/mirrors/mysql/Downloads/%SUBDIR%/ \
	ftp://mirror.services.wisc.edu/mirrors/mysql/Downloads/%SUBDIR%/ \
	ftp://ftp.orst.edu/pub/mysql/Downloads/%SUBDIR%/ \
	http://mysql.mirrors.pair.com/Downloads/%SUBDIR%/ \
	ftp://mysql.mirror.redwire.net/pub/mysql/Downloads/%SUBDIR%/ \
	ftp://mysql.bannerlandia.com.ar/mirrors/mysql/Downloads/%SUBDIR%/ \
	http://mysql.mesi.com.ar/Downloads/%SUBDIR%/ \
	ftp://ftp.linorg.usp.br/mysql/Downloads/%SUBDIR%/ \
	ftp://mysql.ihostunit.com/pub/Mirror/mysql/Downloads/%SUBDIR%/ \
	ftp://mirror.cbn.net.id/mysql/Downloads/%SUBDIR%/ \
	http://mysql.fresh.co.il/Downloads/%SUBDIR%/ \
	ftp://ftp.fresh.co.il/pub/mirrors/mysql.com/Downloads/%SUBDIR%/ \
	http://www.softagency.co.jp/MySQL/Downloads/%SUBDIR%/ \
	http://mysql.nctu.edu.tw/Downloads/%SUBDIR%/
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
	ftp://ftp.weird.com/pub/NetBSD/distfiles/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/unix/NetBSD/packages/distfiles/%SUBDIR%/ \
     ftp://sunsite.rediris.es/sites/ftp.netbsd.org/packages/distfiles/%SUBDIR%/\
	ftp://ftp.funet.fi/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.cz.netbsd.org/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.unina.it/pub/Unix/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.uninett.no/bsd/unix/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://sunsite.uio.no/bsd/unix/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.tpnet.pl/d3/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://gort.ludd.luth.se/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.sunsite.org.uk/sites/rsync.netbsd.org/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.demon.co.uk/pub/mirrors/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.uk.netbsd.org/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,NetBSD/packages/distfiles/&,} \
	ftp://ftp.dti.ad.jp/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.sra.co.jp/pub/os/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.iij.ad.jp/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.itjit.ne.jp/pub/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://ftp.spin.ad.jp/.02/NetBSD/packages/distfiles/%SUBDIR%/ \
	ftp://melanoma.cs.rmit.edu.au/pub/NetBSD/packages/distfiles/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_NETSCAPE)
MASTER_SITE_NETSCAPE+= \
	ftp://ftp.ciril.fr/pub2/netscape/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/unix/network/www/netscape/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/www/Netscape/%SUBDIR%/ \
	ftp://ftp.uit.no/pub/www/Netscape/%SUBDIR%/ \
	ftp://ftp.uni-bielefeld.de/pub/netscape/%SUBDIR%/ \
	ftp://ftp.uniovi.es/pub/netscape/%SUBDIR%/ \
	ftp://sunsite.cnlab-switch.ch/mirror/netscape/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.netscape.com/pub/%SUBDIR%/ \
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
.endif

.if !defined(IGNORE_MASTER_SITE_OSSP)
MASTER_SITE_OSSP+= \
	ftp://ftp.ossp.org/pkg/%SUBDIR%/ \
	http://public.planetmirror.com/pub/ossp/pkg/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/utils/ossp/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_PACKETSTORM)
MASTER_SITE_PACKETSTORM+= \
	http://packetstormsecurity.nl/%SUBDIR%/ \
	http://packetstorm.troop218.org/%SUBDIR%/ \
	http://packetstorm.linuxsecurity.com/%SUBDIR%/ \
	http://packetstormsecurity.com/%SUBDIR%/ \
	http://packetstorm.digital-network.net/%SUBDIR%/ \
	http://packetstorm.icx.fr/%SUBDIR%/ \
	http://packetstorm.security-guide.de/%SUBDIR%/ \
	http://packetstorm.trustica.cz/%SUBDIR%/ \
	http://packetstorm.dyn.org/%SUBDIR%/ \
	http://packetstorm.digitallinx.com/%SUBDIR%/ \
	http://packetstormsecurity.org.pk/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_PERL_CPAN)
MASTER_SITE_PERL_CPAN+=	\
	ftp://ftp.funet.fi/pub/languages/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.cpan.org/pub/CPAN/modules/by-module/%SUBDIR%/ \
	http://www.cpan.dk/CPAN/modules/by-module/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,lang/perl/CPAN/modules/by-module/&,} \
	ftp://ftp.kddlabs.co.jp/lang/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/lang/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/lang/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://mirror.hiwaay.net/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.bora.net/pub/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.funet.fi/pub/languages/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://bioinfo.weizmann.ac.il/pub/software/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://csociety-ftp.ecn.purdue.edu/pub/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.isu.net.sa/pub/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.ucr.ac.cr/pub/Unix/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.cs.colorado.edu/pub/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://cpan.pop-mg.com.br/pub/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.is.co.za/programming/perl/CPAN/modules/by-module/%SUBDIR%/ \
	http://cpan.shellhung.org/modules/by-module/%SUBDIR%/ \
	http://at.cpan.org/modules/by-module/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/lang/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.auckland.ac.nz/pub/perl/CPAN/modules/by-module/%SUBDIR%/
.endif

#
# PostgreSQL mirror sites
#
# For the full list, see the following:
#
#	http://www.postgresql.org/mirrors-ftp.html
#
# Before update mirror list please consult with fenner's distfiles survey.
#
.if !defined(IGNORE_MASTER_SITE_PGSQL)
MASTER_SITE_PGSQL+= \
	ftp://ftp3.us.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp8.us.postgresql.org/postgresql/%SUBDIR%/ \
	ftp://ftp9.us.postgresql.org/pub/mirrors/postgresql/%SUBDIR%/ \
	ftp://ftp10.us.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp13.us.postgresql.org/mirror/postgresql/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,misc/db/postgresql/&,} \
	ftp://ftp.au.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp.at.postgresql.org/db/www.postgresql.org/pub/%SUBDIR%/ \
	ftp://ftp.be.postgresql.org/postgresql/%SUBDIR%/ \
	ftp://ftp.ba.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp.br.postgresql.org/pub/PostgreSQL/%SUBDIR%/ \
	ftp://ftp3.ca.postgresql.org/pub/%SUBDIR%/ \
	ftp://ftp2.cr.postgresql.org/pub/Unix/postgres/%SUBDIR%/ \
	ftp://ftp.cz.postgresql.org/pub/ftp.postgresql.org/%SUBDIR%/ \
	ftp://ftp2.cz.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp.ee.postgresql.org/mirrors/postgresql/%SUBDIR%/ \
	ftp://ftp.fr.postgresql.org/%SUBDIR%/ \
	ftp://ftp2.fr.postgresql.org/postgresql/%SUBDIR%/ \
	ftp://ftp.de.postgresql.org/mirror/postgresql/%SUBDIR%/ \
	ftp://ftp2.de.postgresql.org/pub/comp/os/unix/database/postgresql/%SUBDIR%/ \
	ftp://ftp3.de.postgresql.org/pub/Mirrors/ftp.postgresql.org/%SUBDIR%/ \
	ftp://ftp4.de.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp.gr.postgresql.org/pub/databases/postgresql/%SUBDIR%/ \
	ftp://ftp.hk.postgresql.org/postgresql/%SUBDIR%/ \
	ftp://ftp2.is.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp.ie.postgresql.org/mirrors/ftp.postgresql.org/pub/%SUBDIR%/ \
	ftp://ftp2.it.postgresql.org/mirrors/postgres/%SUBDIR%/ \
	ftp://ftp.kr.postgresql.org/mirror/database/postgresql/%SUBDIR%/ \
	ftp://ftp.lv.postgresql.org/pub/software/postgresql/%SUBDIR%/ \
	ftp://ftp.eu.postgresql.org/pub/unix/db/postgresql/%SUBDIR%/ \
	ftp://ftp2.nl.postgresql.org/mirror/postgresql/%SUBDIR%/ \
	ftp://ftp4.nl.postgresql.org/postgresql.zeelandnet.nl/%SUBDIR%/ \
	ftp://ftp.no.postgresql.org/pub/databases/postgresql/%SUBDIR%/ \
	ftp://ftp6.pl.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp7.pl.postgresql.org/pub/mirror/ftp.postgresql.org/%SUBDIR%/ \
	ftp://ftp.pt.postgresql.org/postgresql/%SUBDIR%/ \
	ftp://ftp6.ro.postgresql.org/pub/mirrors/ftp.postgresql.org/%SUBDIR%/ \
	ftp://ftp.ru.postgresql.org/pub/unix/database/pgsql/%SUBDIR%/ \
	ftp://ftp2.ru.postgresql.org/pub/databases/postgresql/%SUBDIR%/ \
	ftp://ftp3.ru.postgresql.org/pub/mirror/postgresql/pub/%SUBDIR%/ \
	ftp://ftp5.es.postgresql.org/mirror/postgresql/%SUBDIR%/ \
	ftp://ftp.se.postgresql.org/pub/databases/relational/postgresql/%SUBDIR%/ \
	ftp://ftp2.ch.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp.tw.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp3.tw.postgresql.org/pub/postgresql/%SUBDIR%/ \
	ftp://ftp.tr.postgresql.org/pub/SQL/postgresql/%SUBDIR%/ \
	ftp://ftp.postgresql.org/pub/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_PHP)
MASTER_SITE_PHP+= \
	http://br.php.net/%SUBDIR%/ \
	http://cn.php.net/%SUBDIR%/ \
	http://dk.php.net/%SUBDIR%/ \
	http://de.php.net/%SUBDIR%/ \
	http://es.php.net/%SUBDIR%/ \
	http://fi.php.net/%SUBDIR%/ \
	http://fr.php.net/%SUBDIR%/ \
	http://gr.php.net/%SUBDIR%/ \
	http://it.php.net/%SUBDIR%/ \
	http://jp.php.net/%SUBDIR%/ \
	http://nl.php.net/%SUBDIR%/ \
	http://se.php.net/%SUBDIR%/ \
	http://uk.php.net/%SUBDIR%/ \
	http://us2.php.net/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/php/&,}
.endif

.if !defined(IGNORE_MASTER_SITE_PYTHON)
MASTER_SITE_PYTHON+= \
	http://www.python.org/%SUBDIR%/ \
	http://python.planetmirror.com/%SUBDIR%/ \
	http://python.ilisys.com.au/%SUBDIR%/ \
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
	ftp://ftp.mirrorservice.org/sites/ftp.python.org/pub/www.python.org/%SUBDIR%/ \
	http://python.mirrors.pair.com/%SUBDIR%/ \
	http://mirrors.ccs.neu.edu/Python/pub/www.python.org/%SUBDIR%/ \
	http://shattered.teched.net/www.python.org/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_QMAIL)
MASTER_SITE_QMAIL+= \
	http://qmail.geto.net/%SUBDIR%/ \
	http://qmail.palomine.net/%SUBDIR%/ \
	http://qmail.mirrors.summersault.com/%SUBDIR%/ \
	http://qmail.cdsinet.net/%SUBDIR%/ \
	http://qmail.fidnet.com/%SUBDIR%/ \
	http://qmail.mscnetworks.com/%SUBDIR%/ \
	http://qmail.teleglobe.net/%SUBDIR%/ \
	http://qmail.glasswings.com.au/%SUBDIR%/ \
	http://qmail.planetmirror.com/%SUBDIR%/ \
	http://qmail.404-not-found.net/%SUBDIR%/ \
	http://qmail.hostlink.com.hk/%SUBDIR%/ \
	http://qmail.cbn.net.id/%SUBDIR%/ \
	http://qmailorg.data-hotel.net/%SUBDIR%/ \
	http://qmail.manic.co.kr/%SUBDIR%/ \
	http://qmail.psshee.com/%SUBDIR%/ \
	http://mirrors.kangaroot.net/qmail/%SUBDIR%/ \
	http://mirrors.sunsite.dk/qmailwww/%SUBDIR%/ \
	http://qmail.xinus.net/%SUBDIR%/ \
	http://qmail.lightwerk.com/%SUBDIR%/ \
	http://qmail.mirrors.Space.Net/%SUBDIR%/ \
	http://qmail-mirror.hoermann-rawema.de/%SUBDIR%/ \
	http://www.agria.hu/qmail/%SUBDIR%/ \
	http://qmail-mirror.naplopok.hu/%SUBDIR%/ \
	http://qmail.hu/%SUBDIR%/ \
	http://qmail.rhnet.is/%SUBDIR%/ \
	http://qmail.netsoc.ucd.ie/%SUBDIR%/ \
	http://mirrors.dataloss.nl/www.qmail.org/%SUBDIR%/ \
	http://qmail.basefreak.nl/%SUBDIR%/ \
	http://www.math.ntnu.no/mirror/www.qmail.org/%SUBDIR%/ \
	http://qmail.konnekt.org/%SUBDIR%/ \
	http://qmail.netvisao.pt/%SUBDIR%/ \
	http://qmail.ssc.nsu.ru/%SUBDIR%/ \
	http://qmail.ipg.sk/%SUBDIR%/ \
	http://qmail.imasd.elmundo.es/%SUBDIR%/ \
	http://qmail.netrogenic.com/%SUBDIR%/ \
	http://qmail.omnis.ch/%SUBDIR%/ \
	http://qmail.asylog.net/%SUBDIR%/ \
	http://qmail.humourengine.com/%SUBDIR%/ \
	http://qmail.softflare.com/%SUBDIR%/ \
	http://qmail.blueyonder.co.uk/%SUBDIR%/ \
	http://qmail.usp.br/%SUBDIR%/ \
	http://madhaus.utcs.utoronto.ca/qmail/%SUBDIR%/ \
	http://qmail.freezer-burn.org/%SUBDIR%/ \
	http://qmail.ru.ac.za/%SUBDIR%/ \
	http://www.qmail.org/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_QT)
MASTER_SITE_QT+= \
	ftp://sunsite.rediris.es/mirror/Qt/source/%SUBDIR%/ \
	ftp://ftp.iasi.roedu.net/mirrors/ftp.trolltech.com/qt/sources/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/X11/Qt/qt/source/%SUBDIR%/ \
	ftp://ftp.tu-chemnitz.de/pub/Qt/source/%SUBDIR%/ \
	ftp://ftp.silug.org/mirrors/ftp.trolltech.com/qt/source/%SUBDIR%/ \
	ftp://ftp.planetmirror.com.au/pub/trolltech/qt/source/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/unix/X11/gui/Qt/source/%SUBDIR%/ \
	ftp://ftp.trolltech.com/qt/source/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_REDHAT_LINUX)
MASTER_SITE_REDHAT_LINUX+= \
	http://mirrors.usc.edu/pub/linux/distributions/redhat/redhat/linux/%SUBDIR%/ \
	http://www.gtlib.cc.gatech.edu/pub/redhat/linux/%SUBDIR%/ \
	ftp://ftp.rutgers.edu/pub/redhat/linux/%SUBDIR%/ \
	ftp://ftp.uci.edu/mirrors/redhat/linux/%SUBDIR%/ \
	ftp://mirror.cs.wisc.edu/pub/mirrors/linux/redhat/%SUBDIR%/ \
	ftp://ftp.redhat.com/pub/redhat/linux/%SUBDIR%/ \
     ftp://ftp.crc.ca/pub/systems/linux/redhat/ftp.redhat.com/linux/%SUBDIR%/ \
     ftp://ftp.univie.ac.at/systems/linux/ftp.redhat.com/redhat/linux/%SUBDIR%/\
	ftp://ftp.redhat.de/pub/redhat/linux/%SUBDIR%/ \
	ftp://ftp.lip6.fr/pub/linux/distributions/redhat/linux/%SUBDIR%/ \
	ftp://ftp.inet.it/pub/Linux/redhat/%SUBDIR%/ \
	ftp://ftp.nluug.nl/site/ftp.redhat.com/redhat/linux/%SUBDIR%/ \
	ftp://ftp.icm.edu.pl/pub/linux/redhat/linux/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.redhat.com/pub/redhat/linux/%SUBDIR%/ \
     ftp://ftp.cs.nott.ac.uk/Mirrors/ftp.redhat.com/pub/redhat/linux/%SUBDIR%/ \
	ftp://ftp.carrier.kiev.ua/pub/Linux/RedHat/redhat/linux/%SUBDIR%/ \
	ftp://ftp.riken.go.jp/pub/Linux/redhat/releases/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/pub/Linux/packages/RedHat/redhat/linux/%SUBDIR%/ \
	ftp://ftp.cse.cuhk.edu.hk/pub2/redhat/%SUBDIR%/
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
	ftp://www.t.ring.gr.jp/pub/%SUBDIR%/ \
	http://www.t.ring.gr.jp/archives/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_RUBY)
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
.endif

.if !defined(IGNORE_MASTER_SITE_SAMBA)
MASTER_SITE_SAMBA+= \
	http://us1.samba.org/samba/ftp/%SUBDIR%/ \
	http://us2.samba.org/samba/ftp/%SUBDIR%/ \
	http://us4.samba.org/samba/ftp/%SUBDIR%/ \
	http://us3.samba.org/samba/ftp/%SUBDIR%/ \
	ftp://ca.samba.org/%SUBDIR%/ \
	ftp://de.samba.org/samba.org/%SUBDIR%/ \
	ftp://ftp.k2.net/mirrors/samba/%SUBDIR%/ \
	ftp://ftp.oss.eznetsols.org/samba/%SUBDIR%/ \
	ftp://giswitch.sggw.waw.pl/pub/unix/samba/%SUBDIR%/ \
	ftp://ru.samba.org/pub/samba/%SUBDIR%/ \
	ftp://tr.samba.org/samba/%SUBDIR%/ \
	http://sambafr.idealx.org/samba/ftp/%SUBDIR%/ \
	ftp://ftp.easynet.be/samba/%SUBDIR%/ \
	ftp://ftp.linuxforum.net/ftp.samba.org/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/samba/&,}
.endif

.if !defined(IGNORE_MASTER_SITE_SAVANNAH)
MASTER_SITE_SAVANNAH+= \
	http://savannah.nongnu.org/download/%SUBDIR%/ \
	ftp://ftp.gnu.org/pub/savannah/files/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_SOURCEFORGE)
.for mirror in heanet aleron umn belnet nchc voxel optusnet kent unc ufpr
MASTER_SITE_SOURCEFORGE+= \
	http://${mirror}.dl.sourceforge.net/sourceforge/%SUBDIR%/
.endfor
.endif

# official sf.net mirrors that don't mirror all projects, check
# http://prdownloads.sourceforge.net/%SUBDIR%/
.if !defined(IGNORE_MASTER_SITE_SOURCEFORGE_EXTENDED)
.for mirror in easynews switch puzzle ovh peterhost citkit # keihanna is mostly unreachable
MASTER_SITE_SOURCEFORGE_EXTENDED+= \
	http://${mirror}.dl.sourceforge.net/sourceforge/%SUBDIR%/
.endfor
MASTER_SITE_SOURCEFORGE_EXTENDED+= \
	${MASTER_SITE_SOURCEFORGE}
.endif

.if !defined(IGNORE_MASTER_SITE_SOURCEFORGE_JP)
.for mirror in osdn kyushu-u keihanna
MASTER_SITE_SOURCEFORGE_JP+= \
	http://${mirror}.dl.sourceforge.jp/%SUBDIR%/
.endfor
.endif

.if !defined(IGNORE_MASTER_SITE_SOURCEWARE)
MASTER_SITE_SOURCEWARE+= \
	http://mirrors.rcn.net/pub/sourceware/%SUBDIR%/ \
	ftp://mirrors.rcn.net/pub/sourceware/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/mirrors/sources.redhat.com/pub/%SUBDIR%/ \
	ftp://ftp1.sinica.edu.tw/pub3/GNU/CYGNUS/%SUBDIR%/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/sources.redhat.com/%SUBDIR%/ \
	http://sourceware.urc.bl.ac.yu/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_SUNSITE)
MASTER_SITE_SUNSITE+=	\
	http://www.ibiblio.org/pub/Linux/%SUBDIR%/ \
	http://www.gtlib.cc.gatech.edu/pub/Linux/%SUBDIR%/ \
	ftp://sunsite.cnlab-switch.ch/mirror/linux/sunsite/%SUBDIR%/ \
	ftp://ftp.cs.tu-berlin.de/pub/linux/Mirrors/sunsite.unc.edu/%SUBDIR%/ \
	ftp://ftp.physics.auth.gr/pub/mirrors/ibiblio/Linux/%SUBDIR%/ \
	ftp://ftp.edisontel.com/pub/Sunsite_Mirror/%SUBDIR%/ \
	ftp://ftp.rz.uni-karlsruhe.de/pub/mirror/ftp.uni-tuebingen.de/pub/linux/mirrors/ftp.metalab.unc.edu/pub/Linux/%SUBDIR%/ \
	ftp://ftp.nluug.nl/pub/metalab/%SUBDIR%/ \
	ftp://ftp.rediris.es/sites2/ibiblio.org/linux/%SUBDIR%/ \
	ftp://ftp.lip6.fr/pub/linux/sunsite/%SUBDIR%/ \
	ftp://ftp.nvg.ntnu.no/pub/mirrors/metalab.unc.edu/%SUBDIR%/ \
	ftp://ftp.icm.edu.pl/pub/Linux/sunsite/%SUBDIR%/ \
	ftp://ftp.cse.cuhk.edu.hk/pub4/Linux/%SUBDIR%/ \
	ftp://ftp.kobe-u.ac.jp/pub/Linux/metalab.unc.edu/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/Linux/metalab.unc.edu/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/Linux/sunsite/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_SUSE)
MASTER_SITE_SUSE+= 	\
	http://mirrors.usc.edu/pub/linux/distributions/suse/%SUBDIR%/ \
	ftp://ftp-linux.cc.gatech.edu/pub/suse/suse/%SUBDIR%/ \
	http://mirror.usu.edu/mirrors/suse/%SUBDIR%/ \
	ftp://ftp.ale.org/pub/suse/%SUBDIR%/ \
	http://ftp.ale.org/pub/suse/%SUBDIR%/ \
	ftp://mirror.mcs.anl.gov/pub/suse/%SUBDIR%/ \
	ftp://chuck.ucs.indiana.edu/linux/suse/suse/%SUBDIR%/ \
	ftp://trane.caset.buffalo.edu/pub/suse/%SUBDIR%/ \
	ftp://distro.ibiblio.org/pub/linux/distributions/suse/suse/%SUBDIR%/ \
	ftp://ftp.oregonstate.edu/pub/suse/%SUBDIR%/ \
	http://suse.oregonstate.edu/%SUBDIR%/ \
	ftp://ftp://ftp.cnnet.upr.edu/linux/suse/%SUBDIR%/ \
	http://suse.cnnet.upr.edu/%SUBDIR%/ \
	ftp://ftp.sunsite.utk.edu/pub/linux/suse/%SUBDIR%/ \
	http://sunsite.utk.edu/ftp/pub/linux/suse/%SUBDIR%/ \
	http://ops.tamu.edu/suse/%SUBDIR%/ \
	ftp://ftp.empiricalnetworks.com/pub/suse/i386/%SUBDIR%/ \
	http://mirror.usu.edu/mirrors/suse/%SUBDIR%/ \
	ftp://suse.cs.utah.edu/%SUBDIR%/ \
	http://suse.cs.utah.edu/%SUBDIR%/ \
	ftp://ftp.mirrors.net.ar/pub/suse/%SUBDIR%/ \
	http://www.mirrors.net.ar/pub/suse/%SUBDIR%/ \
	ftp://ftp.telekabel.at/pub/linux/suse/%SUBDIR%/ \
	ftp://ftp.skynet.be/mirror/suse.com/ftp.suse.com/%SUBDIR%/ \
	ftp://ftp.belnet.be/linux/suse/%SUBDIR%/ \
	ftp://mirrors.telenet.be/mirrors/ftp.suse.com/%SUBDIR%/ \
	ftp://ftp.unicamp.br/pub/suse%SUBDIR%/ \
	http://ftp.unicamp.br/pub/suse%SUBDIR%/ \
	ftp://mirrors.netbg.com/suse/%SUBDIR%/ \
	ftp://ftp.suse.cl/pub/suse/%SUBDIR%/ \
	ftp://ftp.rdc.cl/pub/Unix/Linux/SuSe/%SUBDIR%/ \
	ftp://ftp.suse.cl/pub/suse/%SUBDIR%/ \
	ftp://ftp://ftp.sh.cvut.cz/SuSE/%SUBDIR%/ \
	http://ftp.sh.cvut.cz/SuSE/%SUBDIR%/ \
	ftp://klid.dk/suse/%SUBDIR%/ \
	http://klid.dk/suse/%SUBDIR%/ \
	ftp://ftp.linux.ee/pub/suse/suse/%SUBDIR%/ \
	ftp://garbo.uwasa.fi/pub/mirrors/suse/%SUBDIR%/ \
	http://fr2.rpmfind.net/linux/SUSE-LINUX/%SUBDIR%/ \
	http://ftp.iut-bm.univ-fcomte.fr/pub/Suse/suse/i386/%SUBDIR%/ \
	ftp://ftp.rez-gif.supelec.fr/pub/Linux/distrib/suse/%SUBDIR%/ \
	ftp://ftp.gwdg.de/pub/linux/suse/%SUBDIR%/ \
	ftp://sunsite.informatik.rwth-aachen.de/pub/Linux/suse/%SUBDIR%/ \
	ftp://ftp.rz.hu-berlin.de/pub/mirrors/ftp.suse.com/pub/suse/%SUBDIR%/ \
	ftp://suse-update.ftp.fu-berlin.de/i386/update/%SUBDIR%/ \
	ftp://ftp.uni-bremen.de/pub/mirrors/suse/%SUBDIR%/ \
	ftp://ftp.tu-chemnitz.de/pub/linux/suse/%SUBDIR%/ \
	ftp://ftp.tu-cottbus.de/pub/unix/linux/suse.com/suse/%SUBDIR%/ \
	ftp://linux.mathematik.tu-darmstadt.de/pub/linux/distributions/suse/%SUBDIR%/ \
	ftp://ftp.uni-erlangen.de/pub/Linux/MIRROR.suse/%SUBDIR%/ \
	http://ftp.uni-erlangen.de/pub/Linux/MIRROR.suse/%SUBDIR%/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.suse.com/pub/suse/%SUBDIR%/ \
	http://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.suse.com/pub/suse/%SUBDIR%/ \
	ftp://ftp.hs.uni-hamburg.de/pub/unix/linux/suse/%SUBDIR%/ \
	ftp://ftp.rrzn.uni-hannover.de/pub/mirror/linux/suse/%SUBDIR%/ \
	ftp://ftp.tu-ilmenau.de/Mirrors/ftp.suse.com/%SUBDIR%/ \
	http://ftp.tu-ilmenau.de/Mirrors/ftp.suse.com/%SUBDIR%/ \
	ftp://ftp.uni-kassel.de/pub/linux/suse/%SUBDIR%/ \
	ftp://ftp.htwk-leipzig.de/pub/suse.com/%SUBDIR%/ \
	ftp://ftp.join.uni-muenster.de/pub/linux/distributions/suse/%SUBDIR%/ \
	ftp://ftp.uni-rostock.de/pub/systems/unix/linux/suse/i386/%SUBDIR%/ \
	ftp://ftp.mpi-sb.mpg.de/pub/linux/mirror/ftp.suse.com/%SUBDIR%/ \
	ftp://ftp.uni-kl.de/pub/linux/suse/%SUBDIR%/ \
	ftp://ftp.uni-siegen.de/.mnt/6/linux/suse/suse/suse/%SUBDIR%/ \
	ftp://ftp.uni-mainz.de/pub/software/Linux/suse/%SUBDIR%/ \
	ftp://ftp.uni-heidelberg.de/pub/linux/suse/%SUBDIR%/ \
	ftp://ftp.rz.uni-ulm.de/pub/mirrors/suse/%SUBDIR%/ \
	ftp://ftp.rz.uni-wuerzburg.de/pub/linux/MIRROR.suse/%SUBDIR%/ \
	ftp://ftp.freenet.de/pub/.disk1/ftp.suse.com/pub/suse/%SUBDIR%/ \
	ftp://ftp.hs-niederrhein.de/pub/linux/updates/SuSE/%SUBDIR%/ \
	ftp://ftp.hu-berlin.de/pub/mirrors/ftp.suse.com/pub/suse/%SUBDIR%/ \
	ftp://ftp.isst.fhg.de/pub/mirrors/ftp.suse.com/pub/suse/%SUBDIR%/ \
	ftp://ftp.rz.uni-karlsruhe.de/pub/mirror/ftp.gwdg.de/pub/linux/suse/ftp.suse.com/suse/%SUBDIR%/ \
	ftp://ftp.rz.uni-kiel.de/pub2/linux/suse/%SUBDIR%/ \
	ftp://mirrors.sth.sze.hu/linux/suse%SUBDIR%/ \
	http://mirrors.sth.sze.hu/linux/suse%SUBDIR%/ \
	ftp://ftp.suselinux.hu/pub/suse/%SUBDIR%/ \
	ftp://ftp.heanet.ie/mirrors/ftp.suse.com/pub/suse/%SUBDIR%/ \
	ftp://ftp.esat.net/mirrors/ftp.suse.com/pub/suse/%SUBDIR%/ \
	ftp://ftp.unina.it/pub/linux/distributions/SuSE/%SUBDIR%/ \
	ftp://ftp.uniroma2.it/Linux/suse/pub/suse/%SUBDIR%/ \
	ftp://ftp.riken.jp/Linux/suse/%SUBDIR%/ \
	http://http.riken.jp/Linux/suse/%SUBDIR%/ \
	ftp://ftp.kddilabs.jp/Linux/packages/SuSE/%SUBDIR%/ \
	ftp://ftp.novell.co.jp/pub/suse/suse/%SUBDIR%/ \
	ftp://ftp.kreonet.re.kr/pub/Linux/suse/%SUBDIR%/ \
	ftp://ftp.mirror.nl/pub/mirror/suse/%SUBDIR%/ \
	ftp://ftp.chello.nl/pub/linux/suse/%SUBDIR%/ \
	ftp://ftp.nl.uu.net/pub/linux/suse/%SUBDIR%/ \
	http://ftp.tpnet.pl/d2/ftp.suse.com/%SUBDIR%/ \
	ftp://ftp.tpnet.pl/d2/ftp.suse.com/%SUBDIR%/ \
	ftp://ftp.icm.edu.pl/packages/linux-suse/i386/%SUBDIR%/ \
	ftp://ftp.task.gda.pl/mirror/ftp.suse.com/pub/suse/%SUBDIR%/ \
	ftp://ftp.lug.ro/suse/%SUBDIR%/ \
	http://ftp.lug.ro/suse/%SUBDIR%/ \
	ftp://ftp.iasi.roedu.net/pub/mirrors/ftp.suse.com/%SUBDIR%/ \
	http://ftp.iasi.roedu.net/pub/mirrors/ftp.suse.com/%SUBDIR%/ \
	ftp://ftp.linux.ro/pub/mirrors/ftp.suse.com/%SUBDIR%/ \
	ftp://ftp.idilis.ro/mirrors/ftp.suse.com/pub/suse/%SUBDIR%/ \
	http://ftp.idilis.ro/mirrors/ftp.suse.com/pub/suse/%SUBDIR%/ \
	ftp://ftp.isu.net.sa/pub/mirrors/ftp.suse.com/%SUBDIR%/ \
	http://ftp.isu.net.sa/pub/mirrors/ftp.suse.com/%SUBDIR%/ \
	ftp://mirror.etf.bg.ac.yu/distributions/suse%SUBDIR%/ \
	http://mirror.etf.bg.ac.yu/distributions/suse/%SUBDIR%/ \
	ftp://blizzard.vqbn.com/suse.de%SUBDIR%/ \
	http://blizzard.vqbn.com/suse.de%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/Linux/distributions/suse/suse/%SUBDIR%/ \
	ftp://ftp.solnet.ch/mirror/SuSE/%SUBDIR%/ \
	ftp://sunsite.cnlab-switch.ch/mirror/SuSE/suse/%SUBDIR%/ \
	ftp://ftp.isu.edu.tw/pub/Linux/SuSE/%SUBDIR%/ \
	http://ftp.isu.edu.tw/pub/Linux/SuSE/%SUBDIR%/ \
	ftp://ftp://ftp.mirrorservice.org/sites/ftp.suse.com/pub/%SUBDIR%/ \
	http://www.mirrorservice.org/sites/ftp.suse.com/pub/%SUBDIR%/ \
	ftp://ftp.plig.org/pub/suse/%SUBDIR%/ \
	ftp://ftp.mirror.ac.uk/sites/ftp.suse.com/i386/%SUBDIR%/ \
	http://ftp.mirror.ac.uk/sites/ftp.suse.com/i386/%SUBDIR%/ \
	ftp://ftp.kde.org/pub/suse/ftp.suse.com/suse/%SUBDIR%/ \
	ftp://ftp.suse.com/pub/suse/%SUBDIR%/ \
	ftp://ftp.linux.org.tr/pub/suse%SUBDIR%/ \
	ftp://ftp.be.itu.edu.tr/pub/mirror/suse%SUBDIR%/ \
	ftp://ftpdem.ubi.pt/pub/linux/suse/%SUBDIR%/ \
	http://darkstar.ist.utl.pt/pub/suse/%SUBDIR%/ \
	ftp://ftp.isr.ist.utl.pt/pub/suse/%SUBDIR%/ \
	http://ftp.isr.ist.utl.pt/pub/suse/%SUBDIR%/ \
	http://suse.freedevices.org/%SUBDIR%/ \
	ftp://ftp.softnet.tuc.gr/pub/linux/suse/%SUBDIR%/ \
	http://ftp.softnet.tuc.gr/pub/linux/suse/%SUBDIR%/ \
	ftp://ftp.duth.gr/pub/suse/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/linux/suse/i386/%SUBDIR%/ \
	ftp://ftp.is.co.za/linux/distributions/suse/%SUBDIR%/ \
	ftp://ftp.sun.ac.za/ftp/mirrorsites/suse/%SUBDIR%/ \
	http://ftp.sun.ac.za/ftp/mirrorsites/suse/%SUBDIR%/ \
	ftp://ftp.rediris.es/pub/linux/distributions/suse/%SUBDIR%/ \
	ftp://suse.grn.es/mirrors/suse/i386/%SUBDIR%/ \
	ftp://ftp.dqbo.cartuja.csic.es/mirror/suse/%SUBDIR%/ \
	ftp://ftp.cb.spb.ru/.1/Linux-Distrib/Suse/%SUBDIR%/ \
	ftp://ftp.neva.ru/.1/Linux-Distrib/Suse/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/Linux/SuSE/suse/%SUBDIR%/ \
	ftp://mirror.pacific.net.au/linux/suse/%SUBDIR%/ \
	http://mirror.pacific.net.au/linux/suse/%SUBDIR%/ \
	ftp://ftp.planetmirror.com/pub/linux/suse/suse/%SUBDIR%/ \
	http://www.planetmirror.com/pub/linux/suse/suse/%SUBDIR%/ \
	ftp://mirror.aarnet.edu.au/pub/suse/
.endif

.if !defined(IGNORE_MASTER_SITE_TCLTK)
MASTER_SITE_TCLTK+= \
	ftp://ftp.scriptics.com/pub/tcl/%SUBDIR%/ \
	ftp://sunsite.utk.edu/pub/tcl/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/languages/tcl/tcl/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/lang/tcl/ftp.scriptics.com/%SUBDIR%/ \
	ftp://ftp.srcc.msu.su/mirror/ftp.scriptics.com/pub/tcl/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.tcl.tk/pub/tcl/%SUBDIR%/ \
	ftp://sunsite.org.uk/Mirrors/ftp.scriptics.com/pub/tcl/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_TEX_CTAN)
MASTER_SITE_TEX_CTAN+=  \
	ftp://ftp.funet.fi/pub/TeX/CTAN/%SUBDIR%/  \
	ftp://ctan.unsw.edu.au/tex-archive/%SUBDIR%/ \
	ftp://ftp.tex.ac.uk/tex-archive/%SUBDIR%/  \
	ftp://ftp.kddlabs.co.jp/CTAN/%SUBDIR%/ \
	ftp://ctan.tug.org/tex-archive/%SUBDIR%/ \
	ftp://ftp.dante.de/tex-archive/%SUBDIR%/ \
	ftp://ftp.ntnu.no/pub/tex/CTAN/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,text/CTAN/&,} \
	ftp://ftp.chg.ru/pub/TeX/CTAN/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_THEMES)
MASTER_SITE_THEMES+= \
	http://download.freshmeat.net/themes/%SUBDIR%/ \
	ftp://gd.tuwien.ac.at/opsys/linux/freshmeat/themes/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_VIM)
MASTER_SITE_VIM+= \
	ftp://ftp.vim.org/pub/vim/unix/  \
	ftp://ftp.is.co.za/applications/editors/vim/unix/  \
	ftp://ftp.prz.tu-berlin.de/pub/unix/editors/vim/unix/  \
	ftp://ftp.mirrorservice.org/sites/ftp.vim.org/pub/vim/unix  \
	ftp://ftp.jp.vim.org/pub/vim/unix/
.endif

.if !defined(IGNORE_MASTER_SITE_WINDOWMAKER)
MASTER_SITE_WINDOWMAKER+= \
	ftp://ftp.windowmaker.org/pub/%SUBDIR%/ \
	ftp://ftp.minet.net/pub/windowmaker/%SUBDIR%/ \
	ftp://ftp.zcu.cz/pub/X11/windowmaker/%SUBDIR%/ \
	ftp://ftp.informatik.uni-hamburg.de/pub/soft/X/contrib/window_managers/windowmaker/%SUBDIR%/ \
	ftp://ftp.uvsq.fr/pub8/X11/window-managers/windowmaker/%SUBDIR%/ \
	ftp://ftp.maisel.int-evry.fr/pub/windowmaker/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/X/WindowMaker/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/X11/windowmanagers/windowmaker/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_XCONTRIB)
MASTER_SITE_XCONTRIB+=	\
	ftp://ftp.net.ohio-state.edu/pub/X11/contrib/%SUBDIR%/ \
	ftp://ftp.gwdg.de/pub/x11/x.org/contrib/%SUBDIR%/ \
	ftp://ftp.duke.edu/pub/X11/contrib/%SUBDIR%/ \
	ftp://ftp.x.org/contrib/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/X11/ftp.x.org/contrib/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/X/XFree86/mirror/X.Org/contrib/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/X11/ftp.x.org/contrib/%SUBDIR%/ \
	ftp://ftp2.x.org/contrib/%SUBDIR%/ \
	ftp://sunsite.tus.ac.jp/pub/archives/X11/contrib/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,X/opengroup/contrib/&,} \
	ftp://ftp.mirrorservice.org/sites/ftp.x.org/contrib/%SUBDIR%/ \
	ftp://sunsite.org.uk/sites/ftp.x.org/contrib/%SUBDIR%/ \
	ftp://ftp.chg.ru/pub/X11/contrib/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_XEMACS)
MASTER_SITE_XEMACS+= \
	ftp://ftp.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.at.xemacs.org/editors/xemacs/%SUBDIR%/ \
	ftp://ftp.au.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.be.xemacs.org/xemacs/%SUBDIR%/ \
	ftp://ftp.br.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.ca.xemacs.org/pub/Mirror/xemacs/%SUBDIR%/ \
	ftp://ftp.ch.xemacs.org/mirror/xemacs/%SUBDIR%/ \
	ftp://ftp.cz.xemacs.org/MIRRORS/ftp.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.de.xemacs.org/pub/ftp.xemacs.org/tux/xemacs/%SUBDIR%/ \
	ftp://ftp.dk.xemacs.org/pub/emacs/xemacs/%SUBDIR%/ \
	ftp://ftp.fi.xemacs.org/pub/mirrors/ftp.xemacs.org/pub/tux/xemacs/%SUBDIR%/ \
	ftp://ftp.fr.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.is.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.ie.xemacs.org/mirrors/ftp.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.it.xemacs.org/unix/packages/XEMACS/%SUBDIR%/ \
	ftp://ftp.jp.xemacs.org/pub/GNU/xemacs/%SUBDIR%/ \
	ftp://ftp.kr.xemacs.org/pub/tools/emacs/xemacs/%SUBDIR%/ \
	ftp://ftp.no.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.pl.xemacs.org/pub/unix/editors/xemacs/%SUBDIR%/ \
	ftp://ftp.pt.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.ru.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.se.xemacs.org/pub/gnu/xemacs/%SUBDIR%/ \
	ftp://ftp.tw.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.uk.xemacs.org/sites/ftp.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.us.xemacs.org/pub/xemacs/%SUBDIR%/ \
	ftp://ftp.nz.xemacs.org/mirror/ftp.xemacs.org/%SUBDIR%/ \
	ftp://ftp.za.xemacs.org/mirrorsites/ftp.xemacs.org/%SUBDIR%/ \
	ftp://xemacs.xmundo.net/pub/mirrors/xemacs/%SUBDIR%/ \
	ftp://ftp.lab.kdd.co.jp/xemacs/%SUBDIR%/ \
	ftp://ftp.dti.ad.jp/pub/unix/editor/xemacs/%SUBDIR%/ \
	ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs/%SUBDIR%/ \
	ftp://ftp.th-darmstadt.de/pub/editors/xemacs/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,text/xemacs/&,}
.endif

.if !defined(IGNORE_MASTER_SITE_XFREE)
MASTER_SITE_XFREE+= \
	http://www.gtlib.cc.gatech.edu/pub/XFree86/%SUBDIR%/source/ \
	ftp://ftp.xfree86.org/pub/XFree86/%SUBDIR%/source/ \
	ftp://ftp.rge.com/pub/X/XFree86/%SUBDIR%/source/ \
	ftp://archive.progeny.com/XFree86/%SUBDIR%/source/ \
	ftp://ftp.mirrorcentral.com/pub/XFree86/%SUBDIR%/source/ \
	ftp://ftp.dti.ad.jp/pub/X/XFree86/XFree86/%SUBDIR%/source/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,XFree86/&/source,} \
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
.endif

.if !defined(IGNORE_MASTER_SITE_XORG)
MASTER_SITE_XORG+= \
	ftp://ftp.gwdg.de/pub/x11/x.org/pub/%SUBDIR%/ \
	ftp://ftp.cica.es/pub/X/pub/%SUBDIR%/ \
	ftp://ftp.cs.cuhk.edu.hk/pub/X11/%SUBDIR%/ \
	ftp://sunsite.sut.ac.jp/pub/archives/X11/%SUBDIR%/ \
	ftp://ftp.unicamp.br/pub/X11/releases/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/X11/X.org/%SUBDIR%/ \
	ftp://ftp.task.gda.pl/mirror/ftp.x.org/pub/%SUBDIR%/ \
	ftp://ftp.sunet.se/pub/X11/ftp.x.org/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.x.org/pub/%SUBDIR%/ \
	ftp://sunsite.uio.no/pub/X11/%SUBDIR%/ \
	ftp://ftp.cs.tu-berlin.de/pub/X/x/%SUBDIR%/ \
	http://xorg.freedesktop.org/%SUBDIR%/ \
	ftp://ftp.x.org/pub/%SUBDIR%/
.endif
