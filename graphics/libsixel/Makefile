# $FreeBSD$

PORTNAME=	libsixel
PORTVERSION=	0.28.0
PORTEPOCH=	1
CATEGORIES=	graphics

MAINTAINER=	sue@iwmt.org
COMMENT=	Encoder/decoder library for DEC SIXEL graphics

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	saitoha
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	0283eca

USE_LDCONFIG=	yes
USES=		libtool

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pkgconfigdir=${LOCALBASE}/libdata/pkgconfig

INSTALL_TARGET=	install-strip

PORTDOCS=	README.md

OPTIONS_DEFINE=	CURL GD PIXBUF
OPTIONS_DEFAULT=

CURL_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
CURL_CONFIGURE_WITH=	libcurl

GD_LIB_DEPENDS=		libgd.so:${PORTSDIR}/graphics/gd
GD_CONFIGURE_WITH=	gd

PIXBUF_LIB_DEPENDS=	libgdk_pixbuf-2.0.so:${PORTSDIR}/graphics/gdk-pixbuf2
PIXBUF_CONFIGURE_WITH=	gdk-pixbuf2

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
