# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	pulseaudio
PORTVERSION=	0.9.21
DISTVERSIONSUFFIX=	-26.el6
PORTREVISION=	6
CATEGORIES=	audio linux
PKGNAMESUFFIX=	-utils
LIB_DISTNAMES=	${LINUXNAME}-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Utils for PulseAudio clients (Linux CentOS ${LINUX_DIST_VER})

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
LINUXNAME=	${PORTNAME}${PKGNAMESUFFIX}
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	xorglibs pulseaudio-libs
USE_LINUX_RPM=	yes

.include <bsd.port.mk>
