PORTNAME=	pulseaudio
PORTVERSION=	15.0
DISTVERSIONSUFFIX=	-3.el9
PORTREVISION=	1
CATEGORIES=	audio linux
PKGNAMESUFFIX=	-utils

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Utils for PulseAudio clients (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://pulseaudio.org/

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	xorglibs pulseaudio-libs
USE_LINUX_RPM=	nolib

BIN_DISTNAMES=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSIONFULL}

CONFLICTS=	linux-c7-${PORTNAME}${PKGNAMESUFFIX}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr

.include <bsd.port.mk>
