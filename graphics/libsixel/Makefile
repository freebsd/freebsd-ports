# $FreeBSD$

PORTNAME=	libsixel
PORTVERSION=	1.6.1
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	graphics

MAINTAINER=	sue@iwmt.org
COMMENT=	Encoder/decoder library for DEC SIXEL graphics

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	saitoha

USE_LDCONFIG=	yes
USES=		libtool pkgconfig

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pkgconfigdir=${LOCALBASE}/libdata/pkgconfig

INSTALL_TARGET=	install-strip

PORTDOCS=	README.md

OPTIONS_DEFINE=	CURL GD JPEG PIXBUF PNG PYTHON
OPTIONS_DEFAULT=
OPTIONS_SUB=	yes

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_WITH=	libcurl

GD_LIB_DEPENDS=		libgd.so:graphics/gd
GD_CONFIGURE_WITH=	gd

JPEG_USES=		jpeg
JPEG_CONFIGURE_WITH=	jpeg
JPEG_CPPFLAGS=		-I${LOCALBASE}/include
JPEG_LDFLAGS=		-L${LOCALBASE}/lib

PIXBUF_LIB_DEPENDS=	libgdk_pixbuf-2.0.so:graphics/gdk-pixbuf2
PIXBUF_CONFIGURE_WITH=	gdk-pixbuf2

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_WITH=	png

PYTHON_DESC=		Python interface
PYTHON_USES=		python
PYTHON_USE=		python=py3kplist
PYTHON_CONFIGURE_ENABLE=	python

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
