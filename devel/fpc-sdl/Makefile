# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTVERSION=	0
CATEGORIES=	devel lang
PKGNAMESUFFIX=	-sdl

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to SDL library

USE_FPC=	pthreads x11

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	SDL
SDL_DESC=	Install SDL library
OPTIONS_DEFAULT=	SDL

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
