# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	alsa-plugins-pulseaudio
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	PulseAudio plugin for ALSA (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	GPLv3

CONFLICTS=	linux-f10-alsa-plugins-pulseaudio-[0-9]*

.if defined(PACKAGE_BUILDING)
SRC_DISTFILES=	alsa-plugins-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE
.endif

USES=		linux:c6
USE_LINUX=	alsalib pulseaudio-libs
USE_LINUX_RPM=	yes
RPMVERSION=	1.el6

USE_LDCONFIG=	yes

# We will use native configuration file, so delete a linux one
post-extract:
	@${RM} -r ${WRKSRC}/etc

.include <bsd.port.mk>
