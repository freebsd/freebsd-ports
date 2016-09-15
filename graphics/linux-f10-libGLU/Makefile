# Created by: bsam
# $FreeBSD$

PORTNAME=	libGLU
PORTVERSION=	7.2
CATEGORIES=	graphics linux
DISTNAME=	mesa-${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Mesa libGLU runtime library (Linux Fedora 10)

CONFLICTS=	linux_dri-[0-9]* linux_dri-devel-* linux-libGLU-[0-9]* \
		linux-f8-libGLU-[0-9]* linux-dri-[0-9]* linux-dri74-[0-9]*

USES=		linux:f10
USE_LINUX_RPM=	yes

RPMVERSION=	0.15.fc10
USE_LDCONFIG=	yes
SRC_DISTFILES=	mesa-${PORTVERSION}-${RPMVERSION}.src.rpm

PLIST_FILES=	usr/lib/libGLU.so.1 usr/lib/libGLU.so.1.3.070300
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
