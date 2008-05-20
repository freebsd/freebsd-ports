# New ports collection makefile for:	mupen64plus-glide
# Date created:		2008-05-16
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-glide

COMMENT=	Glide64 graphics plugin for Mupen64plus

USE_SDL=	sdl
USE_GL=		yes

FIXFILES=	#

PLUGIN_NAME=	glide64

MASTERDIR=	${.CURDIR}/../mupen64plus-base

OPTIONS=	YASM	"Use yasm assembler instead of nasm"	on

.include "${MASTERDIR}/Makefile"
