PORTNAME=	uitools
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt Designer UI forms support module

USES=		compiler:c++11-lang perl5 qmake qt-dist:5,tools
USE_PERL5=	build
USE_QT=		core gui uiplugin widgets buildtools:build

BUILD_WRKSRC=	${WRKSRC}/src/designer/src/${PORTNAME}
INSTALL_WRKSRC=	${WRKSRC}/src/designer/src/${PORTNAME}

.include <bsd.port.mk>
