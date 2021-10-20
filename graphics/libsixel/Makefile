PORTNAME=	libsixel
PORTVERSION=	1.8.6
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/saitoha/libsixel/releases/download/v${PORTVERSION}/

MAINTAINER=	sue@iwmt.org
COMMENT=	Encoder/decoder library for DEC SIXEL graphics

LICENSE=	MIT

USES=		cpe libtool pkgconfig
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pkgconfigdir=${LOCALBASE}/libdata/pkgconfig
INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/sixel-${PORTVERSION}

PORTDOCS=	ChangeLog NEWS

OPTIONS_DEFINE=	CURL DOCS GD JPEG PIXBUF PNG PYTHON
OPTIONS_SUB=	yes

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_WITH=	libcurl

GD_LIB_DEPENDS=		libgd.so:graphics/gd
GD_CONFIGURE_WITH=	gd

JPEG_USES=		jpeg
JPEG_CONFIGURE_WITH=	jpeg
JPEG_CPPFLAGS=		-I${LOCALBASE}/include
JPEG_LDFLAGS=		-L${LOCALBASE}/lib

PIXBUF_CONFIGURE_WITH=	gdk-pixbuf2
PIXBUF_USES=		gettext gnome
PIXBUF_USE=		gnome=glib20,gdkpixbuf2

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_WITH=	png

PYTHON_USES=		python
PYTHON_USE=		python=py3kplist
PYTHON_CONFIGURE_ENABLE=	python

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
