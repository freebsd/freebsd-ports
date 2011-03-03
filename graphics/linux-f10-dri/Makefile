# New ports collection makefile for:	graphics/linux-f10-dri
# Date created:				2009-05-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	dri
PORTVERSION=	7.2
PORTREVISION=	1
CATEGORIES=	graphics linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-f10-
DISTFILES=	Glide3-20050815-7.fc9.${LINUX_RPM_ARCH}.rpm \
		freeglut-2.4.0-14.fc9.${LINUX_RPM_ARCH}.rpm \
		libdrm-2.4.0-0.21.fc10.${LINUX_RPM_ARCH}.rpm \
		mesa-dri-drivers-7.2-0.15.fc10.${LINUX_RPM_ARCH}.rpm \
		mesa-libGL-7.2-0.15.fc10.${LINUX_RPM_ARCH}.rpm \
		mesa-libGLU-7.2-0.15.fc10.${LINUX_RPM_ARCH}.rpm

.if defined(PACKAGE_BUILDING)
SRC_DISTFILES=	Glide3-20050815-7.fc9.src.rpm \
		freeglut-2.4.0-14.fc9.src.rpm \
		libdrm-2.4.0-0.21.fc10.src.rpm \
		mesa-7.2-0.15.fc10.src.rpm

ALWAYS_KEEP_DISTFILES=  YES
.endif

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Mesa libGL runtime libraries and DRI drivers (Linux Fedora 10)

CONFLICTS=	linux_dri-[0-9]* linux_dri-devel-[0-9]* linux-f8-dri-[0-9]* linux-dri-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	xorglibs
LINUX_DIST_VER=	10
USE_LDCONFIG=	yes

.include <bsd.port.mk>
