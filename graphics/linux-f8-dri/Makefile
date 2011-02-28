# New ports collection makefile for:	graphics/linux-f8-dri
# Date created:				2009-04-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	dri
PORTVERSION=	7.0.2
PORTREVISION=	1
CATEGORIES=	graphics linux
PKGNAMEPREFIX=	linux-f8-
DISTFILES=	Glide3-20050815-6.fc8.${LINUX_RPM_ARCH}.rpm \
		freeglut-2.4.0-11.fc8.${LINUX_RPM_ARCH}.rpm \
		libdrm-2.3.0-7.fc8.${LINUX_RPM_ARCH}.rpm \
		mesa-libGL-7.0.2-3.fc8.${LINUX_RPM_ARCH}.rpm \
		mesa-libGLU-7.0.2-3.fc8.${LINUX_RPM_ARCH}.rpm

.if defined(PACKAGE_BUILDING)
SRC_DISTFILES=	Glide3-20050815-6.fc8.src.rpm \
		freeglut-2.4.0-11.fc8.src.rpm \
		libdrm-2.3.0-7.fc8.src.rpm \
		mesa-7.0.2-3.fc8.src.rpm

ALWAYS_KEEP_DISTFILES=  YES
.endif

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Mesa libGL runtime libraries and DRI drivers (Linux Fedora 8)

CONFLICTS=	linux_dri-[0-9]* linux_dri-devel-[0-9]* linux-dri-[0-9]* linux-f10-dri-[0-9]*

DEPRECATED=	End of Life since Jan 7, 2009
EXPIRATION_DATE=2011-04-01

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	xorglibs
LINUX_DIST_VER=	8
RPMVERSION=	3.fc8
USE_LDCONFIG=	yes

.include <bsd.port.mk>
