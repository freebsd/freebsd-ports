PORTNAME=	scripttools
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt Script additional components

USES=		compiler:c++11-lang qmake qt-dist:5,script
USE_QT=		core gui script widgets buildtools_build

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}
INSTALL_WRKSRC=	${WRKSRC}/src/${PORTNAME}

# Link in QtScript port
_QT5_ADDITIONAL_LINK=	script

.include <bsd.port.mk>
