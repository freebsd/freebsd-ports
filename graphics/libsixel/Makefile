# $FreeBSD$

PORTNAME=	libsixel
PORTVERSION=	1.4.5
PORTEPOCH=	1
CATEGORIES=	graphics

MAINTAINER=	sue@iwmt.org
COMMENT=	Encoder/decoder library for DEC SIXEL graphics

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	saitoha
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	3b6dd3e

USE_LDCONFIG=	yes
USES=		libtool pkgconfig

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pkgconfigdir=${LOCALBASE}/libdata/pkgconfig

INSTALL_TARGET=	install-strip

PORTDOCS=	README.md

OPTIONS_DEFINE=	CURL GD JPEG PIXBUF PNG
OPTIONS_DEFAULT=

CURL_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
CURL_CONFIGURE_WITH=	libcurl

GD_LIB_DEPENDS=		libgd.so:${PORTSDIR}/graphics/gd
GD_CONFIGURE_WITH=	gd

JPEG_LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg
JPEG_CONFIGURE_WITH=	jpeg
JPEG_CPPFLAGS=		-I${LOCALBASE}/include
JPEG_LDFLAGS=		-L${LOCALBASE}/lib

PIXBUF_LIB_DEPENDS=	libgdk_pixbuf-2.0.so:${PORTSDIR}/graphics/gdk-pixbuf2
PIXBUF_CONFIGURE_WITH=	gdk-pixbuf2

PNG_LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png
PNG_CONFIGURE_WITH=	png

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
