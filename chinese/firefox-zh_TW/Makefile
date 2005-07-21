# New ports collection makefile for:	zh-firefox-zh_TW
# Date created:		2005/06/25
# Whom:			chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	firefox
PORTVERSION=	1.0.6
CATEGORIES=	chinese www
MASTER_SITES=	http://bbs.ilc.edu.tw/~chinsan/firefox/
PKGNAMESUFFIX=	-zh_TW
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}.${PORTVERSION}

# Maintainership available: drop me a line if interested :p
MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	Firefox Traditional Chinese(zh-TW) Language Pack

BUILD_DEPENDS=	${X11BASE}/lib/${FIREFOX}/regxpcom:${PORTSDIR}/www/firefox
RUN_DEPENDS=	${FIREFOX}:${PORTSDIR}/www/firefox

USE_X_PREFIX=	yes
USE_ZIP=	yes
NO_BUILD=	yes
EXTRACT_BEFORE_ARGS=	-qo

FIREFOX=	${PORTNAME}
FIREFOX_HOME=	${PREFIX}/lib/${FIREFOX}
REGXPCOM=	${FIREFOX_HOME}/regxpcom
REGCHROME=	${FIREFOX_HOME}/regchrome
FIREFOX_BIN=	${FIREFOX_HOME}/${PORTNAME}-bin

PLIST_SUB=	FIREFOX=${FIREFOX}

.include <bsd.port.pre.mk>

do-install:
	echo "===> Backup setting files..."
	(cd ${FIREFOX_HOME}; \
	${MV} -f browserconfig.properties browserconfig.properties.orig)
	(cd ${FIREFOX_HOME}/defaults/pref; \
	${MV} -f firefox-l10n.js firefox-l10n.js.orig)
	(cd ${FIREFOX_HOME}/defaults/profile; \
	${MV} -f bookmarks.html bookmarks.html.orig)
	(cd ${FIREFOX_HOME}/chrome; \
	${MV} -f chrome.rdf chrome.rdf.orig; \
	${MV} -f installed-chrome.txt installed-chrome.txt.orig)

	echo "===> Copying locale files..."
	(cd ${WRKDIR}; ${TAR} -cf - *) | \
	${TAR} -xf - -C ${FIREFOX_HOME}

	echo "===> Cleaning Chrome's registry..."
	${RM} -rf ${FIREFOX_HOME}/chrome/overlayinfo
	${RM} -f ${FIREFOX_HOME}/chrome/*.rdf
	${MKDIR} ${FIREFOX_HOME}/chrome/overlayinfo
	${RM} -f ${FIREFOX_HOME}/component.reg
	${RM} -rf ${FIREFOX_HOME}/extensions

	echo "===> Building Chrome's registry..."
	(cd ${FIREFOX_HOME} || exit 1 ; \
	./run-mozilla.sh ${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. \
		${REGXPCOM} || true ; \
	./run-mozilla.sh ${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. \
		${REGCHROME} || true ; \
	./run-mozilla.sh ${FIREFOX_BIN} -register )
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
