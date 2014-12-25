# Created by: vanilla
# $FreeBSD$

PORTNAME=	ofc
PORTVERSION=	0.8.1
PORTREVISION=	14
CATEGORIES=	lang
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	The Objective-C Foundation Classes library

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libpng.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libfreetype.so:${PORTSDIR}/print/freetype2

PROJECTHOST=	${PORTNAME}
USE_SDL=	sdl
USES=		libtool objc pathfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	GDBM GMP

GDBM_LIB_DEPENDS=	libgdbm.so:${PORTSDIR}/databases/gdbm
GMP_LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp

.include <bsd.port.mk>
