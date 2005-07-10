# New ports collection makefile for:	tiff
# Date created:		8 October 1996
# Whom:			Richard Hwang <rhwang@bigpanda.com>
#			Mikhail Teterin <mi@aldan.algebra.com>
#			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

PORTNAME=	tiff
PORTVERSION=	3.7.3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.remotesensing.org/pub/libtiff/ \
		http://dl1.maptools.org/dl/libtiff/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Tools and library routines for working with TIFF images

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_TARGET=
CONFIGURE_ARGS+=	--with-jpeg-include-dir=${LOCALBASE}/include \
			--with-jpeg-lib-dir=${LOCALBASE}/lib
LDFLAGS+=	-lcompat
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"

.if defined(WITH_X11) && !defined(WITHOUT_X11)
USE_XLIB=	yes
.else
CONFIGURE_ARGS+=	--without-x --without-libgl
.endif

MAN1=	bmp2tiff.1 tiff2pdf.1 fax2ps.1 fax2tiff.1 gif2tiff.1 pal2rgb.1 \
	ppm2tiff.1 ras2tiff.1 raw2tiff.1 rgb2ycbcr.1 sgi2tiff.1 \
	thumbnail.1 tiff2bw.1 tiff2ps.1 tiff2rgba.1 tiffcmp.1 tiffcp.1 \
	tiffdither.1 tiffdump.1 tiffgt.1 tiffinfo.1 tiffmedian.1 \
	tiffset.1 tiffsplit.1 tiffsv.1
MAN3=	TIFFClose.3tiff TIFFDataWidth.3tiff TIFFError.3tiff TIFFFlush.3tiff \
	TIFFGetField.3tiff TIFFOpen.3tiff TIFFPrintDirectory.3tiff \
	TIFFRGBAImage.3tiff TIFFReadDirectory.3tiff \
	TIFFReadEncodedStrip.3tiff TIFFReadEncodedTile.3tiff \
	TIFFReadRGBAImage.3tiff TIFFReadRGBAStrip.3tiff \
	TIFFReadRGBATile.3tiff TIFFReadRawStrip.3tiff TIFFReadRawTile.3tiff \
	TIFFReadScanline.3tiff TIFFReadTile.3tiff TIFFSetDirectory.3tiff \
	TIFFSetField.3tiff TIFFWarning.3tiff TIFFWriteDirectory.3tiff \
	TIFFWriteEncodedStrip.3tiff TIFFWriteEncodedTile.3tiff \
	TIFFWriteRawStrip.3tiff TIFFWriteRawTile.3tiff \
	TIFFWriteScanline.3tiff TIFFWriteTile.3tiff TIFFbuffer.3tiff \
	TIFFcodec.3tiff TIFFcolor.3tiff TIFFmemory.3tiff TIFFquery.3tiff \
	TIFFsize.3tiff TIFFstrip.3tiff TIFFswab.3tiff TIFFtile.3tiff \
	libtiff.3tiff
MLINKS=	TIFFError.3tiff          TIFFSetErrorHandler.3tiff \
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

pre-configure:
	${REINPLACE_CMD} \
		-e 's|^LIBTIFF_VERSION_INFO =.*$$|LIBTIFF_VERSION_INFO = 4:0:0|' \
		${WRKSRC}/libtiff/Makefile.in
	${REINPLACE_CMD} -e 's|^docfiles|no-docfiles|' \
		-e 's|man html|man|' ${WRKSRC}/Makefile.in

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}/images ${DOCSDIR}/man
	${INSTALL_DATA} ${WRKSRC}/html/*.html ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/html/images/*.jpg ${DOCSDIR}/images/
	${INSTALL_DATA} ${WRKSRC}/html/images/*.gif ${DOCSDIR}/images/
	${INSTALL_DATA} ${WRKSRC}/html/man/*.html ${DOCSDIR}/man/
.endif

.include <bsd.port.mk>
