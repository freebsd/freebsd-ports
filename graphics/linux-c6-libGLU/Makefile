# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	libGLU
PORTVERSION=	10.1
PORTREVISION=	1
CATEGORIES=	graphics linux
DISTNAME=	mesa-libGLU-10.1.2-2.el6

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Mesa libGLU runtime libraries (Linux CentOS ${LINUX_DIST_VER})

ALWAYS_KEEP_DISTFILES=	YES

CONFLICTS=	linux-f10-dri-[0-9]* linux-f10-libGLU-[0-9]* linux-c6-dri-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
.if defined(PACKAGE_BUILDING)
SRC_DISTFILES=	mesa-10.1.2-2.el6.src.rpm:SOURCE
.endif

USE_LINUX=	c6
USE_LINUX_RPM=	yes
USE_LDCONFIG=	yes
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
