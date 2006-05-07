# New ports collection makefile for:	ja-firefox-ja_JP
# Date created:		2005/07/16
# Whom:			chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	firefox
PORTVERSION=	1.5.0.3
CATEGORIES=	japanese www
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/${PORTVERSION}/linux-i686/ja
PKGNAMESUFFIX=	-ja
DIST_SUBDIR=	${PORTNAME}${PKGNAMESUFFIX}

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	Firefox Japanese(ja) Language Pack

BUILD_DEPENDS=	${FIREFOX}:${PORTSDIR}/www/firefox
RUN_DEPENDS=	${FIREFOX}:${PORTSDIR}/www/firefox

USE_X_PREFIX=	yes
NO_BUILD=	yes

FIREFOX=	${PORTNAME}
WRKSRC=		${WRKDIR}/${FIREFOX}
FIREFOX_HOME=	${PREFIX}/lib/${FIREFOX}
LOCALE_FILES=	browserconfig.properties \
		chrome/ja.jar \
		chrome/ja.manifest \
		defaults/pref/firefox-l10n.js \
		defaults/profile/bookmarks.html \
		searchplugins/*
PLIST_SUB=	FIREFOX=${FIREFOX}

.include <bsd.port.pre.mk>

do-install:
	@${ECHO_MSG} "===> Backup setting files..."
	(cd ${FIREFOX_HOME}; \
	${CP} -f browserconfig.properties browserconfig.properties.orig)
	(cd ${FIREFOX_HOME}/defaults/pref; \
	${CP} -f firefox-l10n.js firefox-l10n.js.orig)
	(cd ${FIREFOX_HOME}/defaults/profile; \
	${CP} -f bookmarks.html bookmarks.html.orig)

	@${ECHO_MSG} "===> Copying locale files..."
	(cd ${WRKSRC}; ${TAR} -cf - ${LOCALE_FILES}) | \
	${TAR} -xf - -C ${FIREFOX_HOME}

.include <bsd.port.post.mk>
