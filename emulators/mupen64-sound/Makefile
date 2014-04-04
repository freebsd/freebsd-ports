# $FreeBSD$

PKGNAMESUFFIX=	-sound

COMMENT=	Sound plugin for Mupen64

BROKEN=		Fails to build
FIXFILES=	#

PLUGIN_NAME=	mupen64_audio

MASTERDIR=	${.CURDIR}/../mupen64-base

OPTIONS_SLAVE=	GTK2

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
