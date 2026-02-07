PORTNAME=	PoseLib
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.5
CATEGORIES=	graphics

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Minimal solvers for calibrated camera pose estimation

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/eigen3.pc:math/eigen3

USES=		cmake pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NATIVE
NATIVE_CMAKE_BOOL=	MARCH_NATIVE
CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
