# Created by: hashiz
# $FreeBSD: head/audio/linux-f10-alsa-plugins-oss/Makefile 327706 2013-09-20 14:36:35Z bapt $

PORTNAME=	alsa-plugins-oss
PORTVERSION=	1.0.21
PORTREVISION=	3
CATEGORIES=	audio linux

MAINTAINER=	hashiz@meridiani.jp
COMMENT=	OSS plugin for ALSA (Linux Fedora 10)

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	f10
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	alsalib

RPMVERSION=	3.fc10
SRC_DISTFILES=	${PORTNAME:S/-oss//}-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}
USE_LDCONFIG=	yes

.include <bsd.port.mk>
