# New ports collection makefile for:	graphics/linux-f10-libGLU
# Date created:				2009-09-10
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	libGLU
PORTVERSION=	7.2
CATEGORIES=	graphics linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Mesa libGLU runtime library (Linux Fedora 10)

CONFLICTS=	linux_dri-[0-9]* linux_dri-devel-* linux-libGLU-[0-9]* \
		linux-f8-libGLU-[0-9]* linux-dri-[0-9]* linux-dri74-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_NAME=	mesa-libGLU
LINUX_DIST_VER=	10
RPMVERSION=	0.15.fc10
USE_LDCONFIG=	yes
SRC_DISTFILES=	mesa-${PORTVERSION}-${RPMVERSION}.src.rpm

PLIST_FILES=	usr/lib/libGLU.so.1 usr/lib/libGLU.so.1.3.070300
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
