# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	glx-utils
PORTVERSION=	8.2.0
PORTREVISION=	2
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of the GLX utils (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-${PORTNAME}-[0-9]* linux-c6-${PORTNAME}-[0-9]*

RPMVERSION=	2.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	dri xorglibs
USE_LINUX_RPM=	nolib

SRC_DISTFILES=	mesa-10.6.5-3.20150824.el7${SRC_SUFX}:SOURCE

.include <bsd.port.mk>
