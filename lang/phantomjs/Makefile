# New ports collection makefile for:	phantomjs
# Date created:		20 Apr 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	phantomjs
PORTVERSION=	1.6.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Minimalistic, headless, WebKit-based, JavaScript-driven tool

LICENSE=	BSD

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

PROJECTHOST=	phantomjs
USE_ZIP=	YES
USE_GMAKE=	YES
USE_DOS2UNIX=	YES
USE_QT4=	moc qmake gui webkit rcc
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-build:
	cd ${WRKSRC} && ${REINPLACE_CMD} -e 's|!/|!/usr/local/|g' build.sh
	cd ${WRKSRC}/src/qt && ${REINPLACE_CMD} -e 's|!/|!/usr/local/|g' preconfig.sh
	cd ${WRKSRC} && ${LOCALBASE}/bin/bash -x build.sh --jobs 2

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} bin/phantomjs ${PREFIX}/bin/
	${MKDIR} ${PREFIX}/lib/phantomjs/
	cd ${WRKSRC} && ${INSTALL_LIB} src/qt/lib/libQtWebKit.so.4 ${PREFIX}/lib/phantomjs/
	cd ${WRKSRC} && ${INSTALL_LIB} src/qt/lib/libQtGui.so.4 ${PREFIX}/lib/phantomjs/
	cd ${WRKSRC} && ${INSTALL_LIB} src/qt/lib/libQtNetwork.so.4 ${PREFIX}/lib/phantomjs/
	cd ${WRKSRC} && ${INSTALL_LIB} src/qt/lib/libQtCore.so.4 ${PREFIX}/lib/phantomjs/

.include <bsd.port.mk>
