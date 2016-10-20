# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	alsa-plugins-pulseaudio
PORTVERSION=	1.0.27
PORTREVISION=	1
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	PulseAudio plugin for ALSA (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	GPLv3

CONFLICTS=	linux-f10-${PORTNAME}-[0-9]* linux-c6-${PORTNAME}-[0-9]*

SRC_DISTFILES=	alsa-plugins-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE

USES=		linux:c7
USE_LINUX=	alsalib pulseaudio-libs
USE_LINUX_RPM=	yes
RPMVERSION=	3.el7

USE_LDCONFIG=	yes

.include <bsd.port.mk>
