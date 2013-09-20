# Created by: Konstantin Lepa <konstantin.lepa@gmail.com>
# $FreeBSD$

PORTNAME=	vxlog
PORTVERSION=	1.0.3
CATEGORIES=	devel
MASTER_SITES=	http://bitbucket.org/klepa/vxlog/downloads/ \
		SF/${PORTNAME}

MAINTAINER=	konstantin.lepa@gmail.com
COMMENT=	C++ logging library

LICENSE=	MIT

USES=		cmake
USE_LDCONFIG=	yes
USE_GCC=	4.2+

CMAKE_ARGS+=	-DTESTING:BOOL=OFF

NO_STAGE=	yes
.include <bsd.port.mk>
