# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	glx-utils
PORTVERSION=	11.0.7
DISTVERSIONSUFFIX=	-4.el6
PORTREVISION=	3
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Mesa GLX utilities (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	dri xorglibs
USE_LINUX_RPM=	nolib

SRC_DISTFILES=	mesa-${DISTVERSIONFULL}${SRC_SUFX}:SOURCE

.include <bsd.port.mk>
