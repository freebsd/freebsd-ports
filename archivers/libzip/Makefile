# Created by: Alexander Zhuravlev <zaa@zaa.pp.ru>
# $FreeBSD$

PORTNAME=	libzip
PORTVERSION=	0.11.2
PORTREVISION=	2
CATEGORIES=	archivers devel
MASTER_SITES=	http://www.nih.at/libzip/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	C library for reading, creating, and modifying ZIP archives

CPE_VENDOR=	nih

GNU_CONFIGURE=	yes
MAKE_ENV=	LC_ALL="C"
USES=		cpe libtool pathfix tar:xz
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
