# $FreeBSD$
#
# Handle dependency on jpeg
#
# Feature:	jpeg
# Usage:	USES=jpeg or USES=jpeg:ARGS
# Valid ARGS:	lib (default, implicit), build, run, both
#
# User defined variables:
# JPEG_PORT		- jpeg implementation
#			Valid values: graphics/jpeg and graphics/jpeg-turbo
#			Default value: graphics/jpeg-turbo
#
# MAINTAINER: portmgr@FreeBSD.org

.if !defined(_INCLUDE_USES_JPEG_MK)

_INCLUDE_USES_JPEG_MK=	yes
JPEG_PORT?=	graphics/jpeg-turbo

.if empty(jpeg_ARGS)
jpeg_ARGS=	lib
.endif

.if ${jpeg_ARGS} == lib
LIB_DEPENDS+=	libjpeg.so:${JPEG_PORT}
.elif ${jpeg_ARGS} == build
BUILD_DEPENDS+=	cjpeg:${JPEG_PORT}
.elif ${jpeg_ARGS} == run
RUN_DEPENDS+=	cjpeg:${JPEG_PORT}
.elif ${jpeg_ARGS} == both
BUILD_DEPENDS+=	cjpeg:${JPEG_PORT}
RUN_DEPENDS+=	cjpeg:${JPEG_PORT}
.else
IGNORE=		USES=jpeg - invalid args: [${jpeg_ARGS}] specified
.endif

.endif
