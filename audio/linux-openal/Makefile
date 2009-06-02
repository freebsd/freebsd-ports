# New ports collection makefile for:	linux-openal
# Date created:				25 Nov 2005
# Whom:					jylefort@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	openal
DISTVERSION=	0.0.9-0.6.20060204cvs.fc4
PORTREVISION=	3
CATEGORIES=	audio linux
MASTER_SITE_SUBDIR=	../extras/${LINUX_DIST_VER}/${LINUX_RPM_ARCH}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 3D positional spatialized sound library (Linux version)

CONFLICTS=	linux-f8-openal-[0-9]* linux-f10-openal-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	alsalib arts esound libaudiofile libvorbis sdl12
LINUX_DIST_VER=	4
MASTER_SITE_SRC_SUBDIR=	../extras/${LINUX_DIST_VER}/SRPMS
USE_LDCONFIG=	yes
AUTOMATIC_PLIST=yes
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
