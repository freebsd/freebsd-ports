# $FreeBSD$

PORTNAME=	libsixel
PORTVERSION=	0.19.5
PORTEPOCH=	1
CATEGORIES=	graphics

MAINTAINER=	sue@iwmt.org
COMMENT=	Encoder/decoder library for DEC SIXEL graphics

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	saitoha
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	200e4d9

USE_LDCONFIG=	yes
USES=		libtool

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pkgconfigdir=${LOCALBASE}/libdata/pkgconfig

INSTALL_TARGET=		install-strip

PORTDOCS=	README.md

OPTIONS_DEFINE=	CURL GD PIXBUF
OPTIONS_DEFAULT=

CURL_DESC=	libcurl support
GD_DESC=	gd support
PIXBUF_DESC=	gdk-pixbuf2 support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=	libcurl.so:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=--with-libcurl
.endif

.if ${PORT_OPTIONS:MGD}
LIB_DEPENDS+=	libgd.so:${PORTSDIR}/graphics/gd
CONFIGURE_ARGS+=--with-gd
.endif

.if ${PORT_OPTIONS:MPIXBUF}
LIB_DEPENDS+=	libgdk_pixbuf-2.0.so:${PORTSDIR}/graphics/gdk-pixbuf2
CONFIGURE_ARGS+=--with-gdk-pixbuf2
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
