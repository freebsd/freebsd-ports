# New ports collection makefile for:	ko-mozilla-klp
# Date created:		24 Mar 2001
# Whom:			cjh
#
# $FreeBSD$
#

PORTNAME=	mozilla
PORTVERSION=	0.8.${KLP_DATE}
CATEGORIES=	korean www
MASTER_SITES=	http://www.kr.FreeBSD.org/~cjh/freetime/mozilla/mozilla-ko/archive/m0.8/
PKGNAMESUFFIX=	-klp
DISTNAME=	${KLP_SRC}
EXTRACT_SUFX=	.xpi
EXTRACT_ONLY=	${KLP_SRC}${EXTRACT_SUFX}

MAINTAINER=	cjh@FreeBSD.org

BUILD_DEPENDS=	${X11BASE}/lib/mozilla/regxpcom:${PORTSDIR}/www/mozilla
RUN_DEPENDS=	mozilla:${PORTSDIR}/www/mozilla \
		${X11BASE}/lib/X11/fonts/local/gulim12.pcf.gz:${PORTSDIR}/korean/baekmukfonts-bdf

WRKSRC=		${WRKDIR}/bin

USE_X_PREFIX=	yes
USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-qo

KLP_DATE=	20010219
KLP_SRC=	langkokr-${KLP_DATE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400020
MOZILLA_SH=	mozilla.noxpg4
.else
MOZILLA_SH=	mozilla.xpg4
.endif

post-extract:
	${MKDIR} ${WRKSRC}/defaults/pref
	${CP} ${FILESDIR}/all.js ${WRKSRC}/defaults/pref
	${CP} ${FILESDIR}/unix.js ${WRKSRC}/defaults/pref

post-patch:
	find ${WRKSRC} -name '*.orig' | xargs ${RM}

do-build:
	${SED} -e "s;@PREFIX@;${PREFIX};g" \
	${FILESDIR}/${MOZILLA_SH} > ${WRKDIR}/mozilla

do-install:
	(cd ${PREFIX}/lib/mozilla/chrome; \
	${MV} all-locales.rdf all-locales.rdf.orig; \
	${MV} all-packages.rdf all-packages.rdf.orig; \
	${MV} all-skins.rdf all-skins.rdf.orig; \
	${MV} user-locales.rdf user-locales.rdf.orig; \
	${MV} user-skins.rdf user-skins.rdf.orig; \
	${MV} installed-chrome.txt installed-chrome.txt.orig)
	(cd ${PREFIX}/lib/mozilla/defaults/pref; \
	${MV} all.js all.js.orig; ${MV} unix.js unix.js.orig)
	${MV} ${PREFIX}/bin/mozilla ${PREFIX}/bin/mozilla.orig
	${INSTALL_SCRIPT} ${WRKDIR}/mozilla ${PREFIX}/bin
	(cd ${WRKSRC}; ${TAR} -cf - chrome defaults searchplugins) | \
	${TAR} -xf - -C ${PREFIX}/lib/mozilla
	(cd ${PREFIX}/lib/mozilla/chrome; \
	${CP} installed-chrome.txt.orig installed-chrome.txt; \
	${CAT} ${FILESDIR}/installed-chrome.txt >> installed-chrome.txt)
	(cd ${PREFIX}/lib/mozilla; \
	${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regxpcom; \
	${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regchrome)

.include <bsd.port.post.mk>
