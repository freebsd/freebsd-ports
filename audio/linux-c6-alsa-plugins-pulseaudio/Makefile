# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	alsa-plugins
PORTVERSION=	1.1.0
DISTVERSIONSUFFIX=	-1.el6
PORTREVISION=	4
CATEGORIES=	audio linux
PKGNAMESUFFIX=	-pulseaudio
LIB_DISTNAMES=	${LINUXNAME}-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	PulseAudio plugin for ALSA (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	GPLv3

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${LINUXNAME}-${PORTVERSION}
LINUXNAME=	${PORTNAME}${PKGNAMESUFFIX}
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	alsalib pulseaudio-libs
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
