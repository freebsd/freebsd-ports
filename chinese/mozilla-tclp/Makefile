# New ports collection makefile for:	zh-mozilla-tclp
# Date created:		07 March 2001
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mozilla
PORTVERSION=	0.9.6
CATEGORIES=	chinese www
MASTER_SITES=	http://www.csie.ntu.edu.tw/~b7506051/mt4/langpack/
PKGNAMESUFFIX=	-tclp
# Same as ftp://ftp.mozilla.org/pub/mozilla/l10n/lang/moz0.96/langzhtw.xpi.
# Use this to avoid checksum problems.
DISTNAME=	langzhtw-0.9.6-1122
EXTRACT_SUFX=	.xpi

MAINTAINER=	piaip@csie.ntu.edu.tw

RUN_DEPENDS=	mozilla:${PORTSDIR}/www/mozilla

WRKSRC=		${WRKDIR}/bin

USE_X_PREFIX=	yes
USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-qo

.include <bsd.port.pre.mk>

do-build:
	${SED} -e "s;@PREFIX@;${PREFIX};g" \
	${FILESDIR}/mozilla.in > ${WRKDIR}/mozilla

do-install:
	(cd ${PREFIX}/lib/mozilla/chrome; \
	${MV} -f all-locales.rdf all-locales.rdf.orig; \
	${MV} -f user-locales.rdf user-locales.rdf.orig; \
	${MV} installed-chrome.txt installed-chrome.txt.orig)
	${MV} ${PREFIX}/bin/mozilla ${PREFIX}/bin/mozilla.orig
	${INSTALL_SCRIPT} ${WRKDIR}/mozilla ${PREFIX}/bin
	(cd ${PREFIX}/lib/mozilla/chrome; \
	${CP} installed-chrome.txt.orig installed-chrome.txt; \
	${CAT} ${FILESDIR}/installed-chrome.txt >> installed-chrome.txt)
	${INSTALL_DATA} ${WRKSRC}/chrome/zh-TW.jar \
		${PREFIX}/lib/mozilla/chrome;
	${INSTALL_DATA} ${WRKSRC}/chrome/zh-unix.jar \
		${PREFIX}/lib/mozilla/chrome;
	${INSTALL_DATA} ${WRKSRC}/chrome/TW.jar \
		${PREFIX}/lib/mozilla/chrome;
	# "===> Registering Language Pack for Mozilla...";
	${PREFIX}/bin/mozilla -v;

.include <bsd.port.post.mk>
