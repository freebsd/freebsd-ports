# New ports collection makefile for:	linux-sdl_mixer
# Date created:				25 May 2007
# Whom:					Marcus von Appen <mva@sysfault.org>
#
# $FreeBSD$
#

PORTNAME=	sdl_mixer
DISTVERSION=	1.2.6
PORTREVISION=	2
CATEGORIES=	audio linux
MASTER_SITE_SUBDIR=	../extras/${LINUX_DIST_VER}/${LINUX_RPM_ARCH}/
DISTNAME=	SDL_mixer-${PORTVERSION}-3.fc${LINUX_DIST_VER}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A sample multi-channel audio mixer library (Linux version)

CONFLICTS=	linux-f8-sdl_mixer-[0-9]* linux-f10-sdl_mixer-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	sdl12
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
AUTOMATIC_PLIST=yes
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
MASTER_SITE_SRC_SUBDIR=	../extras/${LINUX_DIST_VER}/SRPMS
BRANDELF_DIRS=	usr/bin

.include <bsd.port.mk>
