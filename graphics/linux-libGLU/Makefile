# New ports collection makefile for:	graphics/linux-libGLU
# Date created:				06 Nov 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libGLU
PORTVERSION=	6.8.2
PORTREVISION=	3
CATEGORIES=	graphics linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
DISTNAME=	xorg-x11-Mesa-libGLU-${PORTVERSION}-${RPMVERSION}
SRC_DISTFILES=	xorg-x11-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	OpenGL utility library (Linux version)

CONFLICTS=	linux_dri-[0-9]* linux-f8-libGLU-[0-9]* linux-f10-libGLU-[0-9]* linux-dri-[0-9]* \
		linux-f8-dri-[0-9]* linux-f10-dri-[0-9]*

RPMVERSION=	37.FC4.49.2.1
ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
AUTOMATIC_PLIST=yes
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
