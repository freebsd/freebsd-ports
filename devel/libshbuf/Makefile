# Created by: ijliao
# $FreeBSD$

PORTNAME=	libshbuf
PORTVERSION=	0.0.3
CATEGORIES=	devel
MASTER_SITES=	http://0pointer.de/lennart/projects/libshbuf/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for Shared Buffer IPC

LICENSE=	GPLv2 # though COPYING says LGPL21

USE_LDCONFIG=	yes
USES=		pathfix libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-lynx --disable-doxygen
INSTALL_TARGET=	install-strip
CFLAGS+=	-D_WANT_SEMUN

.include <bsd.port.mk>
