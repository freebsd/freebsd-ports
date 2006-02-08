# New ports collection makefile for:	zh-firefox-zh_CN
# Date created:		2005/06/25
# Whom:			chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	firefox
PORTVERSION=	1.5d
CATEGORIES=	chinese www
MASTER_SITES=	http://chinsan2.twbbs.org/distfiles/firefox/ \
		ftp://chinsan2.twbbs.org/distfiles/firefox/
PKGNAMESUFFIX=	-zh_CN
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}.${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}${PKGNAMESUFFIX}

MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	Firefox Simplified Chinese(zh-CN) Language Pack

BUILD_DEPENDS=	${FIREFOX}:${PORTSDIR}/www/firefox
RUN_DEPENDS=	${FIREFOX}:${PORTSDIR}/www/firefox

USE_X_PREFIX=	yes
NO_BUILD=	yes

FIREFOX=	${PORTNAME}
WRKSRC=		${WRKDIR}/${FIREFOX}
FIREFOX_HOME=	${PREFIX}/lib/${FIREFOX}
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
	(cd ${WRKSRC}; ${TAR} -cf - *) | \
	${TAR} -xf - -C ${FIREFOX_HOME}

.include <bsd.port.post.mk>
