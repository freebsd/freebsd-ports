# Created by: hashiz
# $FreeBSD: head/audio/linux-f10-alsa-plugins-oss/Makefile 362375 2014-07-20 21:23:49Z rene $

PORTNAME=	alsa-plugins-oss
PORTVERSION=	1.0.21
PORTREVISION=	3
CATEGORIES=	audio linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	OSS plugin for ALSA (Linux Fedora 10)

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	alsalib
LINUX_DIST_VER=	10
RPMVERSION=	3.fc10
SRC_DISTFILES=	${PORTNAME:S/-oss//}-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}
USE_LDCONFIG=	yes

CONF_FILE=	etc/alsa/pcm/pcm-oss.conf

post-patch:
	@${RM} ${WRKSRC}/${CONF_FILE}.orig
	@${MV} ${WRKSRC}/${CONF_FILE} ${WRKSRC}/${CONF_FILE}-dist

post-install:
	${MV} ${STAGEDIR}${PREFIX}/${CONF_FILE}-dist ${STAGEDIR}${PREFIX}/${CONF_FILE}.sample

.include <bsd.port.mk>
