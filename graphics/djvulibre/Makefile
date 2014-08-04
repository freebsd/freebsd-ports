# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	djvulibre
PORTVERSION=	3.5.25.3
PORTREVISION=	2
CATEGORIES=	graphics www
MASTER_SITES=	SF/djvu/DjVuLibre/${PORTVERSION:R}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	DjVu base libraries and utilities

LICENSE=	GPLv2

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libtiff.so:${PORTSDIR}/graphics/tiff

USES=		pathfix iconv
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
CONFIGURE_ENV=	JPEG_CFLAGS="-I${LOCALBASE}/include" \
		JPEG_LIBS="-L${LOCALBASE}/lib -ljpeg" \
		TIFF_CFLAGS="-I${LOCALBASE}/include" \
		TIFF_LIBS="-L${LOCALBASE}/lib -ltiff" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-threads=pthread --enable-shared
USE_LDCONFIG=	yes
CONFLICTS=	djvulibre-nox11-3*
WRKSRC=		${WRKDIR}/${DISTNAME:R}

PORTDOCS=	djvu2spec.djvu djvu3spec.djvu djvuchanges.txt lizard2002.djvu lizard2007.djvu

OPTIONS_DEFINE=		DOCS ANY2DJVU
OPTIONS_SUB=		yes

ANY2DJVU_DESC=		Install any2djvu script (requires curl)
ANY2DJVU_RUN_DEPENDS=	curl:${PORTSDIR}/ftp/curl

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		'/-[Og]\*)/d ; \
		s|$$OPTS -O[[:digit:]]*|$$OPTS|g ; \
		s|$$OPTS $$opt|$$OPTS|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|$${FLAGS}|| ; \
		s|@CPPFLAGS@|$${FLAGS} &|' \
		${WRKSRC}/tools/jb2cmp/Makefile.in
	@${REINPLACE_CMD} -e \
		's|_PROGRAM} -m 0755|_SCRIPT}|' \
		${WRKSRC}/tools/Makefile.in
.if empty(PORT_OPTIONS:MANY2DJVU)
	@${REINPLACE_CMD} -e 's,any2djvu,,' ${WRKSRC}/tools/Makefile.in
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
