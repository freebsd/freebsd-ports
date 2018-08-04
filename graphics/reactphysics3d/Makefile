# $FreeBSD$

PORTNAME=	reactphysics3d
DISTVERSION=	0.7.0
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ physics engine library in 3D

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:outsource
USE_GITHUB=	yes
GH_ACCOUNT=	DanielChappuis
GH_TAGNAME=	f86038aa31875daacc2d950be7b999c0d6a19986  # branch 'fix37'
USE_LDCONFIG=	yes
CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
