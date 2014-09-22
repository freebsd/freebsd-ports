# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	dri
PORTVERSION=	9.2
CATEGORIES=	graphics linux
DISTFILES=		mesa-libGL-9.2-0.5.el6.i686.rpm \
		mesa-libGLU-9.2-0.5.el6.i686.rpm \
		mesa-dri-drivers-9.2-0.5.el6.i686.rpm \
		libdrm-2.4.45-2.el6.i686.rpm \
		freeglut-2.6.0-1.el6.i686.rpm

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Mesa libGL runtime libraries (Linux CentOS ${LINUX_DIST_VER})

ALWAYS_KEEP_DISTFILES=	YES

CONFLICTS=	linux_dri-[0-9]* linux_dri-devel-[0-9]* linux-f10-dri-[0-9]* linux-dri-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
.if defined(PACKAGE_BUILDING)
SRC_DISTFILES=	mesa-9.2-0.5.el6.src.rpm \
				libdrm-2.4.45-2.el6.src.rpm \
				freeglut-2.6.0-1.el6.src.rpm
.endif

USE_LINUX=	c6
USE_LINUX_APPS=	xorglibs
USE_LINUX_RPM=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
