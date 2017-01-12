# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	cairo
PORTVERSION=	1.8.8
PORTREVISION=	7
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Vector graphics library Cairo (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-cairo-[0-9]* linux-f10-cairo-[0-9]*

RPMVERSION=	6.el6_6
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	fontconfig pixman png xorglibs
USE_LINUX_RPM=	yes

PORTDOCS=	AUTHORS BIBLIOGRAPHY BUGS COPYING COPYING-LGPL-2.1 \
		COPYING-MPL-1.1 NEWS README

.include <bsd.port.mk>
