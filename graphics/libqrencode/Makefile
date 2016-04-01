# Created by: ijliao
# $FreeBSD$

PORTNAME=	libqrencode
PORTVERSION=	3.4.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://fukuchi.org/works/qrencode/
DISTNAME=	qrencode-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	C library for encoding data in a QR Code symbol

LICENSE=	LGPL21

LIB_DEPENDS=	libpng.so:graphics/png

USES=		pathfix pkgconfig libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/qrencode \
		include/qrencode.h \
		lib/libqrencode.so \
		lib/libqrencode.so.3 \
		lib/libqrencode.so.3.4.4 \
		libdata/pkgconfig/libqrencode.pc \
		man/man1/qrencode.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's,libpng12,libpng,' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '9s|$$| -lpthread|' ${WRKSRC}/libqrencode.pc.in

.include <bsd.port.mk>
