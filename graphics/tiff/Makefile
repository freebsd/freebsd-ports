# New ports collection makefile for:	tiff
# Date created:		8 October 1996
# Whom:			Richard Hwang <rhwang@bigpanda.com>
#			Mikhail Teterin <mi@aldan.algebra.com>
#			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

PORTNAME=	tiff
PORTVERSION=	3.7.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.remotesensing.org/pub/libtiff/ \
		http://dl1.maptools.org/dl/libtiff/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Tools and library routines for working with TIFF images

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_TARGET=
CONFIGURE_ARGS+=	--with-jpeg-include-dir=${LOCALBASE}/include \
			--with-jpeg-lib-dir=${LOCALBASE}/lib

.if defined(WITH_X11) && !defined(WITHOUT_X11)
USE_XLIB=	yes
.else
CONFIGURE_ARGS+=	--without-x --without-libgl
.endif

MAN1=	bmp2tiff.1 tiff2pdf.1 fax2ps.1 fax2tiff.1 gif2tiff.1 pal2rgb.1 \
	ppm2tiff.1 ras2tiff.1 raw2tiff.1 rgb2ycbcr.1 sgi2tiff.1 \
	thumbnail.1 tiff2bw.1 tiff2ps.1 tiff2rgba.1 tiffcmp.1 tiffcp.1 \
	tiffdither.1 tiffdump.1 tiffgt.1 tiffinfo.1 tiffmedian.1 \
	tiffsplit.1 tiffsv.1
MAN3=	TIFFClose.3t TIFFDataWidth.3t TIFFError.3t TIFFFlush.3t \
	TIFFGetField.3t TIFFOpen.3t TIFFPrintDirectory.3t TIFFRGBAImage.3t \
	TIFFReadDirectory.3t TIFFReadEncodedStrip.3t TIFFReadEncodedTile.3t \
	TIFFReadRGBAImage.3t TIFFReadRGBAStrip.3t TIFFReadRGBATile.3t \
	TIFFReadRawStrip.3t TIFFReadRawTile.3t TIFFReadScanline.3t \
	TIFFReadTile.3t TIFFSetDirectory.3t TIFFSetField.3t TIFFWarning.3t \
	TIFFWriteDirectory.3t TIFFWriteEncodedStrip.3t \
	TIFFWriteEncodedTile.3t TIFFWriteRawStrip.3t TIFFWriteRawTile.3t \
	TIFFWriteScanline.3t TIFFWriteTile.3t TIFFbuffer.3t TIFFcodec.3t \
	TIFFcolor.3t TIFFmemory.3t TIFFquery.3t TIFFsize.3t TIFFstrip.3t \
	TIFFswab.3t TIFFtile.3t libtiff.3t
MLINKS=	TIFFError.3t          TIFFSetErrorHandler.3t \
	TIFFFlush.3t          TIFFFlushData.3t \
	TIFFGetField.3t       TIFFGetFieldDefaulted.3t \
	TIFFGetField.3t       TIFFVGetField.3t \
	TIFFGetField.3t       TIFFVGetFieldDefaulted.3t \
	TIFFOpen.3t           TIFFFdOpen.3t \
	TIFFOpen.3t           TIFFClientOpen.3t \
	TIFFRGBAImage.3t      TIFFRGBAImageOK.3t \
	TIFFRGBAImage.3t      TIFFRGBAImageBegin.3t \
	TIFFRGBAImage.3t      TIFFRGBAImageGet.3t \
	TIFFRGBAImage.3t      TIFFRGBAImageEnd.3t \
	TIFFRGBAImage.3t      TIFFReadRGBAImageOriented.3t \
	TIFFSetDirectory.3t   TIFFSetSubDirectory.3t \
	TIFFSetField.3t       TIFFVSetField.3t \
	TIFFWarning.3t        TIFFSetWarningHandler.3t \
	TIFFWriteDirectory.3t TIFFRewriteDirectory.3t \
	TIFFbuffer.3t         TIFFReadBufferSetup.3t \
	TIFFbuffer.3t         TIFFWriteBufferSetup.3t \
	TIFFcodec.3t          TIFFFindCODEC.3t \
	TIFFcodec.3t          TIFFRegisterCODEC.3t \
	TIFFcodec.3t          TIFFUnRegisterCODEC.3t \
	TIFFmemory.3t         TIFFfree.3t \
	TIFFmemory.3t         TIFFmalloc.3t \
	TIFFmemory.3t         TIFFmemcmp.3t \
	TIFFmemory.3t         TIFFmemcpy.3t \
	TIFFmemory.3t         TIFFmemset.3t \
	TIFFmemory.3t         TIFFrealloc.3t \
	TIFFquery.3t          TIFFCurrentDirectory.3t \
	TIFFquery.3t          TIFFCurrentRow.3t \
	TIFFquery.3t          TIFFCurrentStrip.3t \
	TIFFquery.3t          TIFFCurrentTile.3t \
	TIFFquery.3t          TIFFFileName.3t \
	TIFFquery.3t          TIFFFileno.3t \
	TIFFquery.3t          TIFFGetMode.3t \
	TIFFquery.3t          TIFFIsTiled.3t \
	TIFFquery.3t          TIFFIsByteSwapped.3t \
	TIFFquery.3t          TIFFIsUpSampled.3t \
	TIFFquery.3t          TIFFIsMSB2LSB.3t \
	TIFFquery.3t          TIFFLastDirectory.3t \
	TIFFsize.3t           TIFFScanlineSize.3t \
	TIFFstrip.3t          TIFFComputeStrip.3t \
	TIFFstrip.3t          TIFFDefaultStripSize.3t \
	TIFFstrip.3t          TIFFNumberOfStrips.3t \
	TIFFstrip.3t          TIFFStripSize.3t \
	TIFFstrip.3t          TIFFVStripSize.3t \
	TIFFswab.3t           TIFFReverseBits.3t \
	TIFFswab.3t           TIFFSwabArrayOfLong.3t \
	TIFFswab.3t           TIFFSwabArrayOfShort.3t \
	TIFFswab.3t           TIFFSwabLong.3t \
	TIFFswab.3t           TIFFSwabShort.3t \
	TIFFtile.3t           TIFFCheckTile.3t \
	TIFFtile.3t           TIFFComputeTile.3t \
	TIFFtile.3t           TIFFDefaultTileSize.3t \
	TIFFtile.3t           TIFFNumberOfTiles.3t \
	TIFFtile.3t           TIFFTileSize.3t \
	TIFFtile.3t           TIFFTileRowSize.3t \
	TIFFtile.3t           TIFFVTileSize.3t

post-patch:
	${REINPLACE_CMD} \
		-e 's=-version-number .*$$=-version-number 4:0:0=' \
		${WRKSRC}/libtiff/Makefile.in

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}/images ${DOCSDIR}/man
	${INSTALL_DATA} ${WRKSRC}/html/*.html ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/html/images/*.jpg ${DOCSDIR}/images/
	${INSTALL_DATA} ${WRKSRC}/html/images/*.gif ${DOCSDIR}/images/
	${INSTALL_DATA} ${WRKSRC}/html/man/*.html ${DOCSDIR}/man/
.endif

.include <bsd.port.mk>
