# Created by: bsam
# $FreeBSD$

PORTNAME=	cairo
PORTVERSION=	1.8.0
PORTREVISION=	3
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Vector graphics library Cairo (Linux Fedora 10)

CONFLICTS=	linux-cairo-[0-9]* linux-f8-cairo-[0-9]*

USES=		linux:f10
USE_LINUX_RPM=	yes
USE_LINUX=	fontconfig png xorglibs

RPMVERSION=	1.fc10
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libcairo.so.2 \
		usr/lib/libcairo.so.2.10800.0
PORTDOCS=	AUTHORS BIBLIOGRAPHY BUGS COPYING COPYING-LGPL-2.1 \
		COPYING-MPL-1.1 ChangeLog NEWS PORTING_GUIDE README

.include <bsd.port.mk>
