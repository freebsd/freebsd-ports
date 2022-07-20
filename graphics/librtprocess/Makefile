PORTNAME=	librtprocess
PORTVERSION=	0.12.0
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Library for raw image processing

LICENSE=	GPLv3+

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	CarVac
USE_LDCONFIG=	yes

.if !defined(WITH_DEBUG)
CXXFLAGS+=	-DNDEBUG
.endif

.if !exists(/usr/include/omp.h)
CMAKE_ARGS+=	-DOPTION_OMP:BOOL=OFF
.endif

.include <bsd.port.mk>
