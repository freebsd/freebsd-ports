# New ports collection makefile for:	linux-freealut
# Date created:        03 September 2006
# Whom:                Jona Joachim <walkingshadow@grummel.net>
#
# $FreeBSD$
#

PORTNAME=	freealut
PORTVERSION=	1.1.0
CATEGORIES=	audio linux
MASTER_SITE_SUBDIR=	../extras/${LINUX_DIST_VER}/${LINUX_RPM_ARCH}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1.fc${LINUX_DIST_VER}

MAINTAINER=	walkingshadow@grummel.net
COMMENT=	A free implementation of OpenAL's ALUT standard (Linux version)

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libopenal.so.0:${PORTSDIR}/audio/linux-openal

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
INSTALL_SHLIB=	yes
ONLY_FOR_ARCHS=	i386 amd64
DIST_SUBDIR=	rpm
AUTOMATIC_PLIST=yes
MASTER_SITE_SRC_SUBDIR=	../extras/${LINUX_DIST_VER}/SRPMS

.include <bsd.port.mk>
