# Created by: Richard Hwang <rhwang@bigpanda.com>, Mikhail Teterin <mi@aldan.algebra.com>, Jun-ichiro itojun Itoh <itojun@itojun.org>
# $FreeBSD$

PORTNAME=	tiff
PORTVERSION=	4.0.9
CATEGORIES=	graphics
MASTER_SITES=	http://download.osgeo.org/libtiff/

MAINTAINER=	portmgr@FreeBSD.org
COMMENT=	Tools and library routines for working with TIFF images

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libjbig.so:graphics/jbigkit

USES=		cpe jpeg libtool pathfix
CPE_PRODUCT=	libtiff
CPE_VERSION=	${DISTVERSION:C/[a-z]+//}
CPE_UPDATE=	${DISTVERSION:C/[0-9.]+//}
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-jpeg-include-dir=${LOCALBASE}/include \
			--with-jpeg-lib-dir=${LOCALBASE}/lib \
			--without-x
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

MLNKS=	TIFFError.3tiff          TIFFSetErrorHandler.3tiff \
	TIFFFlush.3tiff          TIFFFlushData.3tiff \
	TIFFGetField.3tiff       TIFFGetFieldDefaulted.3tiff \
	TIFFGetField.3tiff       TIFFVGetField.3tiff \
	TIFFGetField.3tiff       TIFFVGetFieldDefaulted.3tiff \
	TIFFOpen.3tiff           TIFFFdOpen.3tiff \
	TIFFOpen.3tiff           TIFFClientOpen.3tiff \
	TIFFRGBAImage.3tiff      TIFFRGBAImageOK.3tiff \
	TIFFRGBAImage.3tiff      TIFFRGBAImageBegin.3tiff \
	TIFFRGBAImage.3tiff      TIFFRGBAImageGet.3tiff \
	TIFFRGBAImage.3tiff      TIFFRGBAImageEnd.3tiff \
	TIFFRGBAImage.3tiff      TIFFReadRGBAImageOriented.3tiff \
	TIFFSetDirectory.3tiff   TIFFSetSubDirectory.3tiff \
	TIFFSetField.3tiff       TIFFVSetField.3tiff \
	TIFFWarning.3tiff        TIFFSetWarningHandler.3tiff \
	TIFFWriteDirectory.3tiff TIFFRewriteDirectory.3tiff \
	TIFFbuffer.3tiff         TIFFReadBufferSetup.3tiff \
	TIFFbuffer.3tiff         TIFFWriteBufferSetup.3tiff \
	TIFFcodec.3tiff          TIFFFindCODEC.3tiff \
	TIFFcodec.3tiff          TIFFRegisterCODEC.3tiff \
	TIFFcodec.3tiff          TIFFUnRegisterCODEC.3tiff \
	TIFFmemory.3tiff         TIFFfree.3tiff \
	TIFFmemory.3tiff         TIFFmalloc.3tiff \
	TIFFmemory.3tiff         TIFFmemcmp.3tiff \
	TIFFmemory.3tiff         TIFFmemcpy.3tiff \
	TIFFmemory.3tiff         TIFFmemset.3tiff \
	TIFFmemory.3tiff         TIFFrealloc.3tiff \
	TIFFquery.3tiff          TIFFCurrentDirectory.3tiff \
	TIFFquery.3tiff          TIFFCurrentRow.3tiff \
	TIFFquery.3tiff          TIFFCurrentStrip.3tiff \
	TIFFquery.3tiff          TIFFCurrentTile.3tiff \
	TIFFquery.3tiff          TIFFFileName.3tiff \
	TIFFquery.3tiff          TIFFFileno.3tiff \
	TIFFquery.3tiff          TIFFGetMode.3tiff \
	TIFFquery.3tiff          TIFFIsTiled.3tiff \
	TIFFquery.3tiff          TIFFIsByteSwapped.3tiff \
	TIFFquery.3tiff          TIFFIsUpSampled.3tiff \
	TIFFquery.3tiff          TIFFIsMSB2LSB.3tiff \
	TIFFquery.3tiff          TIFFLastDirectory.3tiff \
	TIFFsize.3tiff           TIFFScanlineSize.3tiff \
	TIFFstrip.3tiff          TIFFComputeStrip.3tiff \
	TIFFstrip.3tiff          TIFFDefaultStripSize.3tiff \
	TIFFstrip.3tiff          TIFFNumberOfStrips.3tiff \
	TIFFstrip.3tiff          TIFFStripSize.3tiff \
	TIFFstrip.3tiff          TIFFVStripSize.3tiff \
	TIFFswab.3tiff           TIFFReverseBits.3tiff \
	TIFFswab.3tiff           TIFFSwabArrayOfLong.3tiff \
	TIFFswab.3tiff           TIFFSwabArrayOfShort.3tiff \
	TIFFswab.3tiff           TIFFSwabLong.3tiff \
	TIFFswab.3tiff           TIFFSwabShort.3tiff \
	TIFFtile.3tiff           TIFFCheckTile.3tiff \
	TIFFtile.3tiff           TIFFComputeTile.3tiff \
	TIFFtile.3tiff           TIFFDefaultTileSize.3tiff \
	TIFFtile.3tiff           TIFFNumberOfTiles.3tiff \
	TIFFtile.3tiff           TIFFTileSize.3tiff \
	TIFFtile.3tiff           TIFFTileRowSize.3tiff \
	TIFFtile.3tiff           TIFFVTileSize.3tiff

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if !defined(BUILDING_INDEX)
__pmlinks3!=	${ECHO_CMD} '${MLNKS:S/    / /}' | ${AWK} \
	'{ if (NF % 2 != 0) { print "broken"; exit; } \
	for (i=1; i<=NF; i++) { \
		if ( i % 2 == 0) { print " " $$i " ;"; } \
		else { print "${LN} -s " $$i " "; } \
	} }'
.endif

post-patch:
	@${REINPLACE_CMD} "/\.po 0/d" ${WRKSRC}/man/*

pre-configure:
	${REINPLACE_CMD} \
		-e 's|tiffgt.1 ||' \
		${WRKSRC}/man/Makefile.in
	${REINPLACE_CMD} -e 's|^docfiles|no-docfiles|' \
		-e 's|man html|man|' ${WRKSRC}/Makefile.in

post-install:
	( cd ${STAGEDIR}${PREFIX}/man/man3 && ${__pmlinks3} )
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/images ${STAGEDIR}${DOCSDIR}/man
	${INSTALL_DATA} ${WRKSRC}/html/*.html ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/html/images/*.jpg ${STAGEDIR}${DOCSDIR}/images/
	${INSTALL_DATA} ${WRKSRC}/html/images/*.gif ${STAGEDIR}${DOCSDIR}/images/
	${INSTALL_DATA} ${WRKSRC}/html/man/*.html ${STAGEDIR}${DOCSDIR}/man/
.endif

.include <bsd.port.mk>
