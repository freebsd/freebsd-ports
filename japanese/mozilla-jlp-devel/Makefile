# New ports collection makefile for:	ja-mozilla-jlp
# Date created:		02 Jul 2000
# Whom:			Yoichi ASAI <yatt@msc.biglobe.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	mozilla
PORTVERSION=	0.9.6
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	japanese www
MASTER_SITES=	http://www.mozilla.gr.jp/jlp/ \
		http://www.ash.ne.jp/~mal/mozilla/ \
		http://dev.jp/
PKGNAMESUFFIX=	-jlp
DISTNAME=	${PORTNAME}${PORTVERSION}-jajppack-v02
EXTRACT_SUFX=	.xpi

MAINTAINER=	yatt@msc.biglobe.ne.jp

BUILD_DEPENDS=	${X11BASE}/lib/mozilla/regxpcom:${MOZILLA_PORT}
RUN_DEPENDS=	mozilla:${MOZILLA_PORT} \
		${PKG_DBDIR}/ja-netscape-fonts-1.0:${PORTSDIR}/japanese/netscape-fonts

WRKSRC=		${WRKDIR}/bin

USE_X_PREFIX=	yes
USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-qo

.if defined(MOZILLA_IPV6)
MOZILLA_PORT=	${PORTSDIR}/www/mozilla+ipv6
.else
MOZILLA_PORT=	${PORTSDIR}/www/mozilla
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400020
MOZILLA_SH=	mozilla.noxpg4
.else
MOZILLA_SH=	mozilla.xpg4
.endif

.if !defined(MOZILLA_IPV6)
pre-everything::
	@${ECHO} ""
	@${ECHO} "If you need IPv6 compliant mozilla, define \"MOZILLA_IPV6\"."
	@${ECHO} ""
.endif

post-extract:
	${MKDIR} ${WRKSRC}/defaults/pref
	${CP} ${FILESDIR}/unix.js ${WRKSRC}/defaults/pref

do-build:
	${SED} -e "s;@PREFIX@;${PREFIX};g" \
	${FILESDIR}/${MOZILLA_SH} > ${WRKDIR}/mozilla

do-install:
	(cd ${PREFIX}/lib/mozilla/chrome; \
	${MV} -f all-locales.rdf all-locales.rdf.orig; \
	${MV} -f all-packages.rdf all-packages.rdf.orig; \
	${MV} -f all-skins.rdf all-skins.rdf.orig; \
	${MV} -f user-locales.rdf user-locales.rdf.orig; \
	${MV} -f user-skins.rdf user-skins.rdf.orig; \
	${MV} -f installed-chrome.txt installed-chrome.txt.orig)
	(cd ${PREFIX}/lib/mozilla/defaults/pref; \
	${MV} -f unix.js unix.js.orig)
	(cd ${PREFIX}/lib/mozilla/searchplugins; \
	${MV} -f google.gif google.gif.orig; \
	${MV} -f google.src google.src.orig)
	${MV} -f ${PREFIX}/bin/mozilla ${PREFIX}/bin/mozilla.orig
	${INSTALL_SCRIPT} ${WRKDIR}/mozilla ${PREFIX}/bin
	(cd ${WRKDIR}/sp; ${TAR} -cf - *) | \
	${TAR} -xf - -C ${PREFIX}/lib/mozilla/searchplugins
	(cd ${WRKDIR}/sp_nomac; ${TAR} -cf - *) | \
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
