# New ports collection makefile for:	libdjvu++
# Date Created:		20 July 1999
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	djvulibre
PORTVERSION=	3.5.22
PORTREVISION=	1
CATEGORIES=	graphics www
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/ \
		SFP/djvu/DjVuLibre/${PORTVERSION}/
PKGNAMESUFFIX=	-nox11

MAINTAINER=	stas@FreeBSD.org
COMMENT=	DjVu base libraries and utilities

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_ICONV=	yes
USE_GNOME=	gnomehack gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	JPEG_CFLAGS="-I${LOCALBASE}/include" \
		JPEG_LIBS="-L${LOCALBASE}/lib -ljpeg" \
		TIFF_CFLAGS="-I${LOCALBASE}/include" \
		TIFF_LIBS="-L${LOCALBASE}/lib -ltiff" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		LOCALBASE="${LOCALBASE}" \
		CXX="${CXX}"
CONFIGURE_ARGS=	--enable-threads=pthread --enable-shared
USE_LDCONFIG=	yes

OPTIONS=	ANY2DJVU "Install any2djvu script (requires curl)" off

MANLANG=	"" ja
MAN1=		bzz.1 c44.1 cjb2.1 cpaldjvu.1 csepdjvu.1 ddjvu.1 djvm.1 \
		djvmcvt.1 djvu.1 djvudump.1 djvuextract.1 djvumake.1 djvups.1 \
		djvused.1 djvuserve.1 djvutxt.1
MAN1_EN=	djvutoxml.1 djvuxml.1 djvuxmlparser.1 djvudigital.1

PORTDOCS=	djvu2spec.djvu lizard2002.djvu

CONFIGURE_ARGS+=	--disable-djview --without-x

.include <bsd.port.pre.mk>

.if defined(WITH_ANY2DJVU)
MAN1_EN+=		any2djvu.1
RUN_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
PLIST_SUB+=	ANY2DJVU=""
.else
PLIST_SUB+=	ANY2DJVU="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${libdir}/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/libdjvu/Makefile.in
	@${REINPLACE_CMD} -e '/-O\*/d ; \
		 s|$$OPTS -O3|$$OPTS|g ; \
		 s|$$OPTS -O2|$$OPTS|g ; \
		 s|$$OPTS $$opt|$$OPTS|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|= @CPPFLAGS|= $${FLAGS} @CPPFLAGS|g ; \
		 s|@ $${FLAGS}|@|g ; \
		 s|} $${FLAGS}|}|g ; \
		 s|/netscape/|/djvulibre/|g ; \
		 s|eucjp|eucJP|g ; \
		 s|_PROGRAM} -m|} -m|g'

.if !defined(WITH_ANY2DJVU)
	@${REINPLACE_CMD} -e 's,any2djvu,,' ${WRKSRC}/tools/Makefile.in
.endif

post-install:

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
