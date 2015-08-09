# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	dri
PORTVERSION=	9.0
PORTREVISION=	1
CATEGORIES=	graphics linux
MASTER_SITES=	http://vault.centos.org/6.4/os/${LINUX_REPO_ARCH}/Packages/
PKGNAMESUFFIX=	-compat
DISTFILES=	mesa-libGL-9.0-0.7.el6.${LINUX_RPM_ARCH}.rpm \
		mesa-libGLU-9.0-0.7.el6.${LINUX_RPM_ARCH}.rpm \
		mesa-dri-drivers-9.0-0.7.el6.${LINUX_RPM_ARCH}.rpm \
		libdrm-2.4.39-1.el6.${LINUX_RPM_ARCH}.rpm \
		freeglut-2.6.0-1.el6.${LINUX_RPM_ARCH}.rpm

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Mesa libGL runtime libraries (Linux CentOS 6.4)

ALWAYS_KEEP_DISTFILES=	YES

CONFLICTS=	linux_dri-[0-9]* linux_dri-devel-[0-9]* linux-f10-dri-[0-9]* linux-dri-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
.if defined(LINUX_REPO_ARCH) && ${LINUX_REPO_ARCH} == "i686"
LINUX_REPO_ARCH=i386
.endif
.if defined(PACKAGE_BUILDING)
MASTER_SITES+=	http://vault.centos.org/6.4/os/Source/SPackages/:SOURCE
SRC_DISTFILES=	mesa-9.0-0.7.el6.src.rpm:SOURCE \
		libdrm-2.4.39-1.el6.src.rpm:SOURCE \
		freeglut-2.6.0-1.el6.src.rpm:SOURCE
.endif

USE_LINUX=	c6
USE_LINUX_APPS=	xorglibs
USE_LINUX_RPM=	yes
USE_LDCONFIG=	yes
DESCR=             ${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
