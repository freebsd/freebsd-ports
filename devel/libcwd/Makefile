# Created by: ijliao
# $FreeBSD$

PORTNAME=	libcwd
PORTVERSION=	1.0.6
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	C++ Debugging Support Library

LICENSE=	QPL10
LICENSE_NAME=	Q Public License, Version 1.0
LICENSE_FILE=	${WRKSRC}/LICENSE.QPL
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		gmake pathfix pkgconfig libtool
USE_GCC=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alloc --disable-location --disable-threading
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CFLAGS+=	-D__GNU_LIBRARY__

post-patch:
	@${REINPLACE_CMD} -e 's|malloc\.h|stdlib.h|g ; \
		 s|localtime(|localtime((const time_t *)|g' ${WRKSRC}/debugmalloc.cc

.include <bsd.port.mk>
