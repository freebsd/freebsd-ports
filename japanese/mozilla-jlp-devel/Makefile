# New ports collection makefile for:	ja-mozilla-jlp-devel
# Date created:		02 Jul 2000
# Whom:			Yoichi ASAI <yatt@msc.biglobe.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	mozilla
PORTVERSION=	1.2b
#PORTREVISION=	1
#PORTEPOCH=	1
CATEGORIES=	japanese www
MASTER_SITES=	http://www2.starcat.ne.jp/~unha/jlp/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jlpmoz
PKGNAMESUFFIX=	-jlp
DISTNAME=	${PORTNAME}${PORTVERSION}-jajppack-kv0.4.xpi \
		1.2b_langenus.xpi 1.2b_regus.xpi
EXTRACT_SUFX=	# none

MAINTAINER=	yatt@msc.biglobe.ne.jp

BUILD_DEPENDS=	${X11BASE}/lib/mozilla-devel/regxpcom:${PORTSDIR}/www/mozilla-devel
RUN_DEPENDS=	mozilla-devel:${PORTSDIR}/www/mozilla-devel \
		${PKG_DBDIR}/ja-alias-fonts-1.0:${PORTSDIR}/japanese/alias-fonts

WRKSRC=		${WRKDIR}/bin

LATEST_LINK=	ja-mozilla-jlp-devel
USE_X_PREFIX=	yes
USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-qo

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 450002
LOCALENAME=	ja_JP.eucJP
.elif ${OSVERSION} >= 400020
LOCALENAME=	ja_JP.EUC
.else
LOCALENAME=	ja_JP.EUC
LIBXPG4=	LD_PRELOAD=/usr/lib/libxpg4.so.2; export LD_PRELOAD
.endif

post-extract:
	${MKDIR} ${WRKSRC}/defaults/pref
	${CP} ${FILESDIR}/unix.js ${WRKSRC}/defaults/pref
	${RM} -r ${WRKSRC}/defaults/profile/US

do-build:
	${SED} -e "s^@PREFIX@^${PREFIX}^g" \
	       -e "s^@LOCALENAME@^${LOCALENAME}^g" \
	       -e "s^@LIBXPG4@^${LIBXPG4}^g" \
	${FILESDIR}/mozilla.sh > ${WRKDIR}/mozilla-devel

do-install:
	(cd ${PREFIX}/lib/mozilla-devel/chrome; \
	${MV} -f US.jar US.jar.orig; \
	${MV} -f chrome.rdf chrome.rdf.orig; \
	${MV} -f en-US.jar en-US.jar.orig; \
	${MV} -f en-mac.jar en-mac.jar.orig; \
	${MV} -f en-unix.jar en-unix.jar.orig; \
	${MV} -f en-win.jar en-win.jar.orig; \
	${MV} -f installed-chrome.txt installed-chrome.txt.orig)
	(cd ${PREFIX}/lib/mozilla-devel/defaults/pref; \
	${MV} -f unix.js unix.js.orig)
	(cd ${PREFIX}/lib/mozilla-devel/components; \
	${MV} -f xpti.dat ../xpti.dat.orig)
	${MV} -f ${PREFIX}/bin/mozilla-devel ${PREFIX}/bin/mozilla-devel.orig
	${INSTALL_SCRIPT} ${WRKDIR}/mozilla-devel ${PREFIX}/bin
	(cd ${WRKDIR}/sp; ${TAR} -cf - *) | \
	${TAR} -xf - -C ${PREFIX}/lib/mozilla-devel/searchplugins
	(cd ${WRKDIR}/sp_nomac; ${TAR} -cf - *) | \
	${TAR} -xf - -C ${PREFIX}/lib/mozilla-devel/searchplugins
	(cd ${WRKSRC}; ${TAR} -cf - chrome defaults) | \
	${TAR} -xf - -C ${PREFIX}/lib/mozilla-devel
	(cd ${PREFIX}/lib/mozilla-devel/chrome; \
	${CP} installed-chrome.txt.orig installed-chrome.txt; \
	${CAT} ${FILESDIR}/installed-chrome.txt >> installed-chrome.txt)
	(cd ${PREFIX}/lib/mozilla-devel; \
	${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regxpcom; \
	${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regchrome)
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
