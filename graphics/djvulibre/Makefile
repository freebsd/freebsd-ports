# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	djvulibre
PORTVERSION=	3.5.25.3
PORTREVISION=	1
CATEGORIES=	graphics www
MASTER_SITES=	SF/djvu/DjVuLibre/${PORTVERSION:R}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	DjVu base libraries and utilities

LICENSE=	GPLv2

LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg \
		tiff:${PORTSDIR}/graphics/tiff

USES=		pathfix iconv
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	JPEG_CFLAGS="-I${LOCALBASE}/include" \
		JPEG_LIBS="-L${LOCALBASE}/lib -ljpeg" \
		TIFF_CFLAGS="-I${LOCALBASE}/include" \
		TIFF_LIBS="-L${LOCALBASE}/lib -ltiff" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-threads=pthread --enable-shared
USE_LDCONFIG=	yes
CONFLICTS=	djvulibre-nox11-3*
WRKSRC =	${WRKDIR}/${DISTNAME:R}

OPTIONS_DEFINE =	ANY2DJVU
ANY2DJVU_DESC=		Install any2djvu script (requires curl)

MAN1=		bzz.1 c44.1 cjb2.1 cpaldjvu.1 csepdjvu.1 ddjvu.1 djvm.1 \
		djvmcvt.1 djvu.1 djvudump.1 djvuextract.1 djvumake.1 djvups.1 \
		djvused.1 djvuserve.1 djvutxt.1
MAN1_EN=	djvutoxml.1 djvuxml.1 djvuxmlparser.1 djvudigital.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MANY2DJVU}
MAN1_EN+=	any2djvu.1
RUN_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
PLIST_SUB+=	ANY2DJVU=""
.else
PLIST_SUB+=	ANY2DJVU="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${libdir}/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/libdjvu/Makefile.in
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

.if ${PORT_OPTIONS:MDOC}
PORTDOCS=	djvu2spec.djvu djvu3spec.djvu djvuchanges.txt lizard2002.djvu lizard2007.djvu

post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
