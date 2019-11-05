# Created by: alepulver
# $FreeBSD$

PORTNAME=	nehquake
PORTVERSION=	1.0
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	LOCAL/alepulver
DISTNAME=	NehQuake-bjp-bin-src.linux

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake engine designed for playing Nehahra

USES=		gl gmake dos2unix tar:bzip2 xorg
USE_GL=		gl
USE_XORG=	xxf86dga

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS SDL X86_ASM
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS SDL X86_ASM
OPTIONS_SUB=	yes

SDL_USES=	sdl
SDL_USE=	SDL=sdl
SDL_MAKE_ENV=	BUILD_SDL=YES

X86_ASM_DESC=	Enable x86 assembly code

ALL_TARGET=	release
SUB_FILES=	pkg-message

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.options.mk>

.for f in OPTIMIZED_CFLAGS X86_ASM
.   if ${PORT_OPTIONS:M${f}}
MAKE_ENV+=	USE_${f}=YES
.   else
MAKE_ENV+=	USE_${f}=NO
.   endif
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/release/nehahra ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MSDL}
	${INSTALL_PROGRAM} ${WRKSRC}/release/nehahra-sdl ${STAGEDIR}${PREFIX}/bin
.endif
	@${MKDIR} ${STAGEDIR}${Q1DIR}/nehahra

.include <bsd.port.mk>
