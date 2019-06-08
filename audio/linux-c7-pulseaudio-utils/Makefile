# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	pulseaudio
PORTVERSION=	10.0
PORTREVISION=	1
CATEGORIES=	audio linux
PKGNAMESUFFIX=	-utils
BIN_DISTNAMES=	${LINUXNAME}-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Utils for PulseAudio clients (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-c6-${LINUXNAME}-[0-9]*

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
LINUXNAME=	${PORTNAME}${PKGNAMESUFFIX}
RPMVERSION=	5.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	xorglibs pulseaudio-libs
USE_LINUX_RPM=	nolib

.include <bsd.port.mk>
