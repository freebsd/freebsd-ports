# New ports collection makefile for:	audio/linux-f10-alsa-plugins-oss
# Date created:				2010-06-06
# Whom:					hashiz
#
# $FreeBSD$
#

PORTNAME=	alsa-plugins-oss
PORTVERSION=	1.0.21
PORTREVISION=	1
CATEGORIES=	audio linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	hashiz@meridiani.jp
COMMENT=	OSS plugin for ALSA (Linux Fedora 10)

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	alsalib
LINUX_DIST_VER=	10
RPMVERSION=	3.fc10
SRC_DISTFILES= ${PORTNAME:S/-oss//}-${PORTVERSION}-${RPMVERSION}.src.rpm
USE_LDCONFIG=	yes

post-patch:
	${RM} ${WRKDIR}/etc/alsa/pcm/pcm-oss.conf.orig

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
