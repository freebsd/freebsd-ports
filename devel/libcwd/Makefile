# ex:ts=8
# Ports collection makefile for:	libcwd
# Date created:			Nov 10, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libcwd
PORTVERSION=	1.0.4
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The C++ Debugging Support Library

USE_GNOME=	gnomehack pkgconfig
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS=	--disable-alloc --disable-location --disable-threading \
		--disable-pch
USE_LDCONFIG=	yes

CFLAGS+=	-D__GNU_LIBRARY__

post-patch:
	@${REINPLACE_CMD} -e 's|malloc\.h|stdlib.h|g ; \
		 s|localtime(|localtime((const time_t *)|g' ${WRKSRC}/debugmalloc.cc

.include <bsd.port.mk>
