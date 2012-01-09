# New ports collection makefile for:	phantomjs
# Date created:		20 Apr 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	phantomjs
PORTVERSION=	1.4.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Minimalistic, headless, WebKit-based, JavaScript-driven tool

PROJECTHOST=	phantomjs
USE_QT_VER=	4
USE_GMAKE=	YES
USE_DOS2UNIX=	YES
QT_COMPONENTS=	moc qmake gui webkit rcc
PLIST_FILES=	bin/phantomjs
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-build:
	cd ${WRKSRC}/src/ && ${QMAKE} phantomjs.pro -o Makefile.phantomjs && ${REINPLACE_CMD} -e 's|-ldl||g' Makefile.phantomjs
	cd ${WRKSRC}/src/ && ${GMAKE} -f Makefile.phantomjs all

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} bin/phantomjs ${PREFIX}/bin/

.include <bsd.port.mk>
