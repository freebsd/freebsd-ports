# Created by: ijliao
# $FreeBSD$

PORTNAME=	libcwd
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ Debugging Support Library

USES=		gmake pathfix pkgconfig libtool
USE_GCC=	any
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alloc --disable-location --disable-threading \
		--disable-pch
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CFLAGS+=	-D__GNU_LIBRARY__

post-patch:
	@${REINPLACE_CMD} -e 's|malloc\.h|stdlib.h|g ; \
		 s|localtime(|localtime((const time_t *)|g' ${WRKSRC}/debugmalloc.cc

.include <bsd.port.mk>
