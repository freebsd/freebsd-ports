# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	glx-utils
PORTVERSION=	8.3.0
CATEGORIES=	graphics linux
SRC_DISTFILES=	mesa-demos-${DISTVERSIONFULL}${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Mesa GLX utilities (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

RPMVERSION=	10.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	dri xorglibs
USE_LINUX_RPM=	nolib

.include <bsd.port.mk>
