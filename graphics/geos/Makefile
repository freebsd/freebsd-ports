PORTNAME=	geos
PORTVERSION=	3.12.2
CATEGORIES=	graphics geography
MASTER_SITES=	https://github.com/libgeos/geos/releases/download/${PORTVERSION}/ \
		https://download.osgeo.org/geos/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Geometry Engine, Open Source
WWW=		https://libgeos.org/ \
		https://github.com/libgeos/geos

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++14-lang pathfix tar:bzip2

CMAKE_OFF=	BUILD_BENCHMARKS DISABLE_GEOS_INLINE
CMAKE_ON=	BUILD_SHARED_LIBS
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
