# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	djvulibre
PORTVERSION=	3.5.27
CATEGORIES=	graphics www
MASTER_SITES=	SF/djvu/DjVuLibre/${PORTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	DjVu base libraries and utilities

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	rsvg-convert:graphics/librsvg2
LIB_DEPENDS=	libtiff.so:graphics/tiff

INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pkgconfigdir="${PREFIX}/libdata/pkgconfig"
CONFIGURE_ENV=	JPEG_CFLAGS="-I${LOCALBASE}/include" \
		JPEG_LIBS="-L${LOCALBASE}/lib -ljpeg" \
		TIFF_CFLAGS="-I${LOCALBASE}/include" \
		TIFF_LIBS="-L${LOCALBASE}/lib -ltiff"
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
USES=		cpe gmake iconv jpeg libtool shared-mime-info
CPE_VENDOR=	djvulibre_project
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CONFLICTS=	djvulibre-nox11-3*

PORTDOCS=	*.djvu *.pdf *.txt

OPTIONS_DEFINE=		DOCS ANY2DJVU
OPTIONS_SUB=		yes

ANY2DJVU_DESC=		Install any2djvu script (requires curl)
ANY2DJVU_RUN_DEPENDS=	curl:ftp/curl

post-patch:
# Remove custom optimization compiler flags
	@${REINPLACE_CMD} -e '/-[Og]\*)/d ; \
		/^ opt=/s|-O[[:digit:]]*||g' \
		${WRKSRC}/configure
# Convert bash to sh script, which uses fetch instead of wget
	@${REINPLACE_CMD} -e '/^#!/s|bash -f|sh| ; \
		s|^function || ; s| == | = |g ; \
		s|wget $$wgetopts -O|${FETCH_BINARY} $$wgetopts -o|' \
		${WRKSRC}/tools/any2djvu

post-patch-ANY2DJVU-off:
	@${REINPLACE_CMD} -e 's/any2djvu // ; s/any2djvu\.1 //' \
		${WRKSRC}/tools/Makefile.in

post-install-DOCS-on:
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
