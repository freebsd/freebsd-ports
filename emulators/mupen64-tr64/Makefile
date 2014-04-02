# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTVERSION=	0.7.8
PORTREVISION=	3
PKGNAMESUFFIX=	-tr64

COMMENT=	Tr64 graphics plugin for Mupen64

BROKEN=		Fails to patch
USE_SDL=	sdl
USE_GL=		yes

FIXFILES=	display.c sdlgl.c

PLUGIN_NAME=	tr64gl

MASTERDIR=	${.CURDIR}/../mupen64-base

OPTIONS_SLAVE=	GTK2

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
