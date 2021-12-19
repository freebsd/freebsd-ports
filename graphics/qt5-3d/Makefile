PORTNAME=	3d
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	4
CATEGORIES=	graphics
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt3D module

LIB_DEPENDS=	libassimp.so:multimedia/assimp

USES=		compiler:c++11-lang pkgconfig qmake:norecursive qt-dist:5,3d
USE_QT=		concurrent core declarative gui network buildtools_build

OPTIONS_DEFINE_amd64=	AVX
OPTIONS_DEFINE_i386=	AVX

AVX_DESC=		Build for Intel CPUs with AVX* support (Haswell+)
AVX_EXTRA_PATCHES=	${FILESDIR}/extrapatch-src_core_configure.json

QT_BINARIES=	yes

.include <bsd.port.mk>
