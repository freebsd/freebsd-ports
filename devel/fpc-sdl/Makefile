# $FreeBSD$

PORTREVISION=	4
CATEGORIES=	devel lang
PKGNAMESUFFIX=	-sdl

COMMENT=	Free Pascal interface to SDL library

USES=		fpc
USE_FPC=	pthreads x11

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	SDL
SDL_DESC=	Install SDL library
OPTIONS_DEFAULT=	SDL

SDL_USES=	sdl
SDL_USE=	SDL=sdl,image,mixer,ttf,gfx

.include "${MASTERDIR}/Makefile"
