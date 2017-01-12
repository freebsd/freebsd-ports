# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	glx-utils
PORTVERSION=	11.0.7
PORTREVISION=	3
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of the GLX utils (Linux CentOS ${LINUX_DIST_VER})

RPMVERSION=	4.el6
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	dri xorglibs
USE_LINUX_RPM=	nolib

SRC_DISTFILES=	mesa-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE

.include <bsd.port.mk>
