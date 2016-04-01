# Created by: vanilla
# $FreeBSD$

PORTNAME=	ofc
PORTVERSION=	0.8.1
PORTREVISION=	15
CATEGORIES=	lang
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	The Objective-C Foundation Classes library

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2

PROJECTHOST=	${PORTNAME}
USE_SDL=	sdl
USES=		jpeg libtool objc pathfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	GDBM GMP

GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
GMP_LIB_DEPENDS=	libgmp.so:math/gmp

.include <bsd.port.mk>
