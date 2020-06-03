# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	djvulibre
PORTVERSION=	3.5.27
PORTREVISION=	2
CATEGORIES=	graphics www
MASTER_SITES=	SF/djvu/DjVuLibre/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DjVu base libraries and utilities

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtiff.so:graphics/tiff

USES=		cpe gmake iconv jpeg libtool
USE_LDCONFIG=	yes

CPE_VENDOR=	djvulibre_project

PORTDOCS=	*.djvu *.pdf *.txt

INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	JPEG_CFLAGS="-I${LOCALBASE}/include" \
		JPEG_LIBS="-L${LOCALBASE}/lib -ljpeg" \
		TIFF_CFLAGS="-I${LOCALBASE}/include" \
		TIFF_LIBS="-L${LOCALBASE}/lib -ltiff"
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		DESKTOPFILES DOCS ANY2DJVU
OPTIONS_DEFAULT=	DESKTOPFILES
OPTIONS_SUB=		yes

ANY2DJVU_DESC=		Install any2djvu script (requires curl)
ANY2DJVU_RUN_DEPENDS=	curl:ftp/curl
DESKTOPFILES_DESC=	Install icons and mime types
DESKTOPFILES_CONFIGURE_ENABLE=	desktopfiles
DESKTOPFILES_USES=	gnome shared-mime-info
DESKTOPFILES_VARS=	INSTALLS_ICONS=yes

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

post-patch-DESKTOPFILES-on:
# Use prebuilt icons, without using conversion tool
	@${SED} -i.c.bak -e 's/conversion_tool=[[:alpha:]]*/conversion_tool=no/' \
		${WRKSRC}/configure

post-install-DOCS-on:
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
