# New ports collection makefile for:	ja-mozilla-jlp
# Date created:		02 Jul 2000
# Whom:			Yoichi ASAI <yatt@msc.biglobe.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	mozilla
PORTVERSION=	1.2.1
PORTREVISION?=	0
PORTEPOCH=	1
CATEGORIES=	japanese www
MASTER_SITES=	http://www2.starcat.ne.jp/~unha/jlp/
#MASTER_SITE_SUBDIR=	jlpmoz
PKGNAMESUFFIX=	-jlp
DISTNAME=	${PORTNAME}1.2-jajppack-kv0.4
EXTRACT_SUFX=	.xpi

MAINTAINER=	yatt@luna2.org

BUILD_DEPENDS=	${X11BASE}/lib/mozilla/regxpcom:${PORTSDIR}/www/mozilla
RUN_DEPENDS=	mozilla:${PORTSDIR}/www/mozilla \
		${PKG_DBDIR}/ja-alias-fonts-1.0:${PORTSDIR}/japanese/alias-fonts

WRKSRC=		${WRKDIR}/bin

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
