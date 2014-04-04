# $FreeBSD$

PORTVERSION=	0.7
PORTREVISION=	7
PKGNAMESUFFIX=	-glide

COMMENT=	Glide64 graphics plugin for Mupen64

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

BROKEN=		Fails to patch
USE_SDL=	sdl
USE_GL=		yes

FIXFILES=	#

PLUGIN_NAME=	Glide64

MASTERDIR=	${.CURDIR}/../mupen64-base

OPTIONS_SLAVE=	GTK2

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
