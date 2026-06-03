PORTNAME=	libserialport
DISTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://sigrok.org/download/source/libserialport/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Framework for hardware logic analyzers, serial port support library
WWW=		https://sigrok.org/

LICENSE=	LGPL3

USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBS="-lusb"

MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip

post-install:
	${REINPLACE_CMD} \
		-e 's|Requires.private: libusb-2.0|Requires.private:|' \
		-e 's|Libs.private: $$|Libs.private: -lusb|' \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/libserialport.pc

.include <bsd.port.mk>
