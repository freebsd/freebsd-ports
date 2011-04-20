# New ports collection makefile for:	phantomjs
# Date created:		20 Apr 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	phantomjs
PORTVERSION=	1.0.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Minimalistic, headless, WebKit-based, JavaScript-driven tool

PROJECTHOST=	phantomjs
USE_QT_VER=	4
USE_GMAKE=	YES
QT_COMPONENTS=	moc qmake gui webkit rcc
PLIST_FILES=	bin/phantomjs

do-configure:
	cd ${WRKSRC} && ${QMAKE}

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} bin/phantomjs ${PREFIX}/bin/

.include <bsd.port.mk>
