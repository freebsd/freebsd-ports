# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	alsa-plugins-oss
PORTVERSION=	1.0.21
CATEGORIES=	audio linux
PKGNAMEPREFIX=	linux-${USE_LINUX}-

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	OSS plugin for ALSA (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	GPLv3

CONFLICTS=	linux-f10-alsa-plugins-oss-[0-9]*

.if defined(PACKAGE_BUILDING)
SRC_DISTFILES=	alsa-plugins-1.0.21-3.el6.src.rpm
.endif

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	c6
USE_LINUX_APPS=	alsalib
USE_LINUX_RPM=	yes
RPMVERSION=	3.el6

USE_LDCONFIG=	yes

CONF_FILE=	etc/alsa/pcm/pcm-oss.conf

post-patch:
	@${RM} ${WRKSRC}/${CONF_FILE}.orig

.include <bsd.port.mk>
