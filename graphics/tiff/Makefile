# New ports collection makefile for:	tiff
# Version required:	3.5.3
# Date created:		8 October 1996
# Whom:			Richard Hwang <rhwang@bigpanda.com>
#			Mikhail Teterin <mi@aldan.algebra.com>
#			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

DISTNAME=	tiff-v3.5.3
PKGNAME=	tiff-3.5.3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.onshore.com/pub/libtiff/ \
		http://www.libtiff.org/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ZIP --with-JPEG \
		--with-DIR_BIN=${PREFIX}/bin \
		--with-DIR_LIB=${PREFIX}/lib \
		--with-DIR_INC=${PREFIX}/include \
		--with-DIR_MAN=${PREFIX}/man \
		--with-CC="${CC}" --with-GCOPTS="${CFLAGS}" \
		--with-DIRS_LIBINC=${LOCALBASE}/include \
		--with-DIR_GZLIB=/usr/lib \
		--with-DIR_JPEGLIB=${LOCALBASE}/lib \
		--with-LIBGL=no --with-LIBIMAGE=no \
		--with-INSTALL="${SH} ${WRKSRC}/port/install.sh" \
		--noninteractive

.if defined(NOPORTDOCS)
PLIST=			${PKGDIR}/PLIST.nodocs
.else
CONFIGURE_ARGS+=	--with-HTML --with-DIR_HTML=${PREFIX}/share/doc/tiff
.endif

MAN1=	fax2ps.1 fax2tiff.1 gif2tiff.1 pal2rgb.1 ppm2tiff.1 ras2tiff.1 \
	rgb2ycbcr.1 sgi2tiff.1 thumbnail.1 tiff2bw.1 tiff2ps.1 tiffcmp.1 \
	tiffcp.1 tiffdither.1 tiffdump.1 tiffgt.1 tiffinfo.1 tiffmedian.1 \
	tiffsplit.1 tiffsv.1
MAN3=	TIFFCheckTile.3t TIFFClose.3t TIFFComputeStrip.3t TIFFComputeTile.3t \
	TIFFCurrentDirectory.3t TIFFCurrentRow.3t TIFFCurrentStrip.3t \
	TIFFCurrentTile.3t TIFFDefaultStripSize.3t TIFFDefaultTileSize.3t \
	TIFFError.3t TIFFFdOpen.3t TIFFFileName.3t TIFFFileno.3t \
	TIFFFindCODEC.3t TIFFFlush.3t TIFFFlushData.3t TIFFGetField.3t \
	TIFFGetMode.3t TIFFIsByteSwapped.3t TIFFIsMSB2LSB.3t TIFFIsTiled.3t \
	TIFFIsUpSampled.3t TIFFLastDirectory.3t TIFFNumberOfStrips.3t \
	TIFFNumberOfTiles.3t TIFFOpen.3t TIFFPrintDirectory.3t \
	TIFFRGBAImage.3t TIFFRGBAImageBegin.3t TIFFRGBAImageEnd.3t \
	TIFFRGBAImageGet.3t TIFFRGBAImageOK.3t TIFFReadBufferSetup.3t \
	TIFFReadDirectory.3t TIFFReadEncodedStrip.3t TIFFReadEncodedTile.3t \
	TIFFReadRGBAImage.3t TIFFReadRGBAStrip.3t TIFFReadRGBATile.3t \
	TIFFReadRawStrip.3t TIFFReadRawTile.3t TIFFReadScanline.3t \
	TIFFReadTile.3t TIFFRegisterCODEC.3t TIFFReverseBits.3t \
	TIFFScanlineSize.3t TIFFSetDirectory.3t TIFFSetErrorHandler.3t \
	TIFFSetField.3t TIFFSetSubDirectory.3t TIFFSetWarningHandler.3t \
	TIFFStripSize.3t TIFFSwabArrayOfLong.3t TIFFSwabArrayOfShort.3t \
	TIFFSwabLong.3t TIFFSwabShort.3t TIFFTileRowSize.3t TIFFTileSize.3t \
	TIFFUnRegisterCODEC.3t TIFFVGetField.3t TIFFVSetField.3t \
	TIFFVStripSize.3t TIFFVTileSize.3t TIFFWarning.3t \
	TIFFWriteBufferSetup.3t TIFFWriteDirectory.3t TIFFWriteEncodedStrip.3t \
	TIFFWriteEncodedTile.3t TIFFWriteRawStrip.3t TIFFWriteRawTile.3t \
	TIFFWriteScanline.3t TIFFWriteTile.3t TIFFbuffer.3t TIFFcodec.3t \
	TIFFfree.3t TIFFmalloc.3t TIFFmemcmp.3t TIFFmemcpy.3t TIFFmemory.3t \
	TIFFmemset.3t TIFFquery.3t TIFFrealloc.3t TIFFsize.3t TIFFstrip.3t \
	TIFFswab.3t TIFFtile.3t libtiff.3t

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
