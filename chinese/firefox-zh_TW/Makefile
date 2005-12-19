# New ports collection makefile for:	zh-firefox-zh_TW
# Date created:		2005/06/25
# Whom:			chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	firefox
PORTVERSION=	1.5
CATEGORIES=	chinese www
MASTER_SITES=	http://bbs.ilc.edu.tw/~chinsan/firefox/
PKGNAMESUFFIX=	-zh_TW
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}.${PORTVERSION}

MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	Firefox Traditional Chinese(zh-TW) Language Pack

BUILD_DEPENDS=	${X11BASE}/lib/${FIREFOX}/regxpcom:${PORTSDIR}/www/firefox
RUN_DEPENDS=	${FIREFOX}:${PORTSDIR}/www/firefox

USE_X_PREFIX=	yes
NO_BUILD=	yes

FIREFOX=	${PORTNAME}
FIREFOX_HOME=	${PREFIX}/lib/${FIREFOX}
REGXPCOM=	${FIREFOX_HOME}/regxpcom
FIREFOX_BIN=	${FIREFOX_HOME}/${PORTNAME}-bin

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

	@${ECHO_MSG} "===> Building Chrome's registry..."
	(cd ${FIREFOX_HOME} || exit 1 ; \
	./run-mozilla.sh ${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. \
		${REGXPCOM} || true ; \
	./run-mozilla.sh ${FIREFOX_BIN} -register )
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
