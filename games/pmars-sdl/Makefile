# New ports collection makefile for:	pmars-sdl
# Date created:				30 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	pmars
PORTVERSION=	0.9.2
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.cs.helsinki.fi/u/jpihlaja/cw/pmars-sdl/
PKGNAMESUFFIX=	-sdl
DISTNAME=	${PORTNAME}-${PORTVERSION}-5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port of pMARS using the Simple Directmedia Library

USE_SDL=	sdl

WRKSRC=		${WRKDIR}/${DISTNAME}/src

OPTIONS=	ICWS94 "Enable ICWS'94 support" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		PERMUTATE "Enable the -P switch" on \
		SMALLMEM "Use 16-bit addresses (smaller)" off

MAKE_ARGS+=	CFLAGS+="${CFLAGS}" \
		CFLAGS+="-fno-builtin" \
		CFLAGS+="`${SDL_CONFIG} --cflags`" \
		LIB+="`${SDL_CONFIG} --libs`" \
		CFLAGS+="-DSDLGRAPHX"

PLIST_FILES=	bin/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_ICWS94)
MAKE_ARGS+=	CFLAGS+="-DEXT94"
.endif

.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
MAKE_ARGS+=	CFLAGS+="-O3 -fomit-frame-pointer"
.endif

.if !defined(WITHOUT_PERMUTATE)
MAKE_ARGS+=	CFLAGS+="-DPERMUTATE"
.endif

.if defined(WITH_SMALLMEM)
MAKE_ARGS+=	CFLAGS+="-DSMALLMEM"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.post.mk>
