# Created by: ijliao
# $FreeBSD$

PORTNAME=	libqrencode
PORTVERSION=	3.4.3
PORTREVISION=	0
CATEGORIES=	graphics
MASTER_SITES=	http://fukuchi.org/works/qrencode/
DISTNAME=	qrencode-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	C library for encoding data in a QR Code symbol

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

USES=		pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/qrencode \
		include/qrencode.h \
		lib/libqrencode.la \
		lib/libqrencode.so \
		lib/libqrencode.so.3 \
		libdata/pkgconfig/libqrencode.pc \
		man/man1/qrencode.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's,libpng12,libpng,' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '9s|$$| ${PTHREAD_LIBS}|' ${WRKSRC}/libqrencode.pc.in

.include <bsd.port.mk>
