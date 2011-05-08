# New ports collection makefile for:	distorm
# Date created:				13 May 2008
# Whom:					bf <bf2006a@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	distorm
PORTVERSION=	3.0.0
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		LOCAL/bf
DISTNAME=	${PORTNAME}${PORTVERSION:R:R}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Fast x86 and x86-64 disassembler library

LICENSE=	GPLv3

USE_DOS2UNIX=	yes
USE_ZIP=	yes
USE_LDCONFIG=	yes

BUILD_WRKSRC=	${WRKSRC}/make/linux
PLIST_FILES=	bin/disasm lib/libdistorm3.a lib/libdistorm3.so lib/libdistorm3.so.0

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} \
	EXTRAFLAGS="${PICFLAG} -DDISTORM_DYNAMIC" ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} clib clean)
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} \
	EXTRAFLAGS="-DDISTORM_STATIC" ${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} staticlib)
	${CC} ${CFLAGS} ${LDFLAGS} -DSUPPORT_64BIT_OFFSET \
	-o ${BUILD_WRKSRC}/disasm ${WRKSRC}/examples/linux/main.c \
	${BUILD_WRKSRC}/libdistorm3.a

do-install:
	(cd ${BUILD_WRKSRC}; ${INSTALL_LIB} libdistorm3.a ${PREFIX}/lib; \
	${INSTALL_LIB} libdistorm3.so ${PREFIX}/lib/libdistorm3.so.0; \
	${LN} -sf ${PREFIX}/lib/libdistorm3.so.0 ${PREFIX}/lib/libdistorm3.so; \
	${INSTALL_PROGRAM} disasm ${PREFIX}/bin)

.include <bsd.port.post.mk>
