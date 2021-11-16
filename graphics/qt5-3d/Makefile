PORTNAME=	3d
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	3
CATEGORIES=	graphics
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt3D module

LIB_DEPENDS=	libassimp.so:multimedia/assimp

USES=		compiler:c++11-lang pkgconfig qmake:norecursive qt-dist:5,3d
USE_QT=		concurrent core declarative gui network buildtools_build

QT_BINARIES=	yes

.include <bsd.port.mk>
