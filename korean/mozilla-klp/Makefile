# New ports collection makefile for:	ko-mozilla-klp
# Date created:		24 Mar 2001
# Whom:			cjh
#
# $FreeBSD$
#

PORTNAME=	mozilla
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	korean www
MASTER_SITES=	http://www.mozilla.pe.kr/archive/m1.1/
PKGNAMESUFFIX=	-klp
DISTNAME=	langkokr
DIST_SUBDIR=	mozilla-klp
EXTRACT_SUFX=	.xpi

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	Mozilla Korean Language Pack (KLP)

BUILD_DEPENDS=	${X11BASE}/lib/mozilla/regxpcom:${PORTSDIR}/www/mozilla
RUN_DEPENDS=	mozilla:${PORTSDIR}/www/mozilla

WRKSRC=		${WRKDIR}/bin

USE_X_PREFIX=	yes
USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-qo

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 450002
LOCALENAME=	ko_KR.eucKR
.elif ${OSVERSION} >= 400020
LOCALENAME=	ko_KR.EUC
.else
LOCALENAME=	ko_KR.EUC
LIBXPG4=	LD_PRELOAD=/usr/lib/libxpg4.so.2; export LD_PRELOAD
.endif

post-extract:
	${MKDIR} ${WRKSRC}/defaults/pref
	${CP} ${FILESDIR}/unix.js ${WRKSRC}/defaults/pref

do-build:
	${SED} -e "s^@PREFIX@^${PREFIX}^g" \
	       -e "s^@LOCALENAME@^${LOCALENAME}^g" \
	       -e "s^@LIBXPG4@^${LIBXPG4}^g" \
	${FILESDIR}/mozilla.sh > ${WRKDIR}/mozilla

do-install:
	(cd ${PREFIX}/lib/mozilla/chrome; \
	${MV} -f chrome.rdf chrome.rdf.orig; \
	${MV} -f installed-chrome.txt installed-chrome.txt.orig)
	(cd ${PREFIX}/lib/mozilla/defaults/pref; \
	${MV} -f unix.js unix.js.orig)
	(cd ${PREFIX}/lib/mozilla/components; \
	${MV} -f xpti.dat ../xpti.dat.orig)
	${MV} -f ${PREFIX}/bin/mozilla ${PREFIX}/bin/mozilla.orig
	${INSTALL_SCRIPT} ${WRKDIR}/mozilla ${PREFIX}/bin
	(cd ${WRKSRC}/searchplugins; ${TAR} -cf - *) | \
	${TAR} -xf - -C ${PREFIX}/lib/mozilla/searchplugins
	(cd ${WRKSRC}; ${TAR} -cf - chrome defaults) | \
	${TAR} -xf - -C ${PREFIX}/lib/mozilla
	(cd ${PREFIX}/lib/mozilla/chrome; \
	${CP} installed-chrome.txt.orig installed-chrome.txt; \
	${CAT} ${FILESDIR}/installed-chrome.txt >> installed-chrome.txt)
	(cd ${PREFIX}/lib/mozilla; \
	${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regxpcom; \
	${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regchrome)
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
