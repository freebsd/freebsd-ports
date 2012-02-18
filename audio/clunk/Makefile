# New ports collection makefile for:	clunk
# Date created:		05 Aug 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clunk
PORTVERSION=	1.2.130
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/clunk

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Real-time 3D sound generation library

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_SDL=	sdl
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS=	SIMD "Enable SIMD support (SSE)" off

.include <bsd.port.options.mk>

.if defined(WITH_SIMD)
CMAKE_ARGS+=	-DWITH_SSE:BOOL=TRUE
.endif

.include <bsd.port.mk>
