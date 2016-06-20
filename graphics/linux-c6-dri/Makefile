# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	dri
PORTVERSION=	11.0.7
CATEGORIES=	graphics linux
DISTFILES=	#
LIB_DISTFILES=	mesa-libGL-${PORTVERSION}-4.el6.${LINUX_RPM_ARCH}.rpm \
		mesa-libGLU-${PORTVERSION}-4.el6.${LINUX_RPM_ARCH}.rpm \
		mesa-dri-drivers-${PORTVERSION}-4.el6.${LINUX_RPM_ARCH}.rpm \
		libdrm-2.4.65-2.el6.${LINUX_RPM_ARCH}.rpm \
		freeglut-2.6.0-1.el6.${LINUX_RPM_ARCH}.rpm

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Mesa libGL runtime libraries (Linux CentOS ${LINUX_DIST_VER})

ALWAYS_KEEP_DISTFILES=	YES

CONFLICTS=	linux_dri-[0-9]* linux_dri-devel-[0-9]* linux-f10-dri-[0-9]* linux-dri-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
.if defined(PACKAGE_BUILDING)
SRC_DISTFILES=	mesa-${PORTVERSION}-4.el6.src.rpm:SOURCE \
		libdrm-2.4.65-2.el6.src.rpm:SOURCE \
		freeglut-2.6.0-1.el6.src.rpm:SOURCE
.endif

USE_LINUX=	c6
USE_LINUX_APPS=	xorglibs
USE_LINUX_RPM=	yes
USE_LDCONFIG=	yes
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
