# Created by: Leonardo Martins <lmartins@nepe.eee.ufg.br>

PORTNAME=	geos
PORTVERSION=	3.11.0
CATEGORIES=	graphics geography
MASTER_SITES=	https://download.osgeo.org/geos/ \
		https://github.com/libgeos/geos/releases/download/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Geometry Engine, Open Source

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang tar:bzip2

CMAKE_OFF=	BUILD_BENCHMARKS DISABLE_GEOS_INLINE
CMAKE_ON=	BUILD_SHARED_LIBS
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
