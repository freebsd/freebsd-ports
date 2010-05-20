# New ports collection makefile for:	mupen64plus-rice
# Date created:		2008-05-16
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-rice

COMMENT=	The rice graphics plugin for Mupen64plus

BROKEN=		does not compile

USE_GL=		yes
USE_SDL=	sdl

FIXFILES=	rice_video/liblinux/BMGImage.c rice_video/liblinux/BMGUtils.c

PLUGIN_NAME=	ricevideo

MASTERDIR=	${.CURDIR}/../mupen64plus-base

OPTIONS=	#

.include "${MASTERDIR}/Makefile"
