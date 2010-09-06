# New ports collection makefile for:	vxlog
# Date created:               2010-05-18
# Whom:                       Konstantin Lepa <konstantin.lepa@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	vxlog
PORTVERSION=	1.0.1
CATEGORIES=	devel
MASTER_SITES=	http://bitbucket.org/klepa/vxlog/get/
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	konstantin.lepa@gmail.com
COMMENT=	C++ logging library

LICENSE=	MIT

USE_GZIP=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes
USE_GCC=	4.2+

CMAKE_ARGS+=	-DTESTING:BOOL=OFF

WRKSRC=	${WRKDIR}/${PORTNAME}

.if defined(WITH_DEBUG)
CMAKE_ARGS+=    -DDEBUG_MODE:BOOL=ON
.endif

.include <bsd.port.mk>
