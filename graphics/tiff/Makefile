# New ports collection makefile for:	tiff
# Version required:	3.4
# Date created:		8 October 1996
# Whom:			Richard Hwang <rhwang@bigpanda.com>
#			Mikhail Teterin <mi@aldan.ziplink.net>
#			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.13 1998/11/25 09:01:07 asami Exp $
#

DISTNAME=	tiff-v3.4
PKGNAME=	tiff-3.4
CATEGORIES=	graphics
MASTER_SITES=   ftp://ftp.sgi.com/graphics/tiff/
EXTRACT_SUFX=	-tar.gz

MAINTAINER=	itojun@itojun.org

LIB_DEPENDS=    jpeg.9:${PORTSDIR}/graphics/jpeg

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ZIP --with-JPEG --with-DIR_BIN=${PREFIX}/bin \
		--with-DIR_LIB=${PREFIX}/lib \
		--with-DIR_INC=${PREFIX}/include \
		--with-CC="${CC}" --with-GCOPTS="${CFLAGS}" \
		--with-DIRS_LIBINC=${PREFIX}/include \
		--with-DIR_GZLIB=/usr/lib \
		--with-DIR_JPEGLIB=${PREFIX}/lib \
		--with-LIBGL=no --with-LIBIMAGE=no \
		--with-INSTALL="/bin/sh ${WRKSRC}/port/install.sh" \
		--noninteractive
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
	TIFFReadRGBAImage.3t TIFFReadRawStrip.3t TIFFReadRawTile.3t \
	TIFFReadScanline.3t TIFFReadTile.3t TIFFRegisterCODEC.3t \
	TIFFReverseBits.3t TIFFScanlineSize.3t TIFFSetDirectory.3t \
	TIFFSetErrorHandler.3t TIFFSetField.3t TIFFSetSubDirectory.3t \
	TIFFSetWarningHandler.3t TIFFStripSize.3t TIFFSwabArrayOfLong.3t \
	TIFFSwabArrayOfShort.3t TIFFSwabLong.3t TIFFSwabShort.3t \
	TIFFTileRowSize.3t TIFFTileSize.3t TIFFUnRegisterCODEC.3t \
	TIFFVGetField.3t TIFFVSetField.3t TIFFVStripSize.3t TIFFVTileSize.3t \
	TIFFWarning.3t TIFFWriteBufferSetup.3t TIFFWriteDirectory.3t \
	TIFFWriteEncodedStrip.3t TIFFWriteEncodedTile.3t TIFFWriteRawStrip.3t \
	TIFFWriteRawTile.3t TIFFWriteScanline.3t TIFFbuffer.3t TIFFcodec.3t \
	TIFFfree.3t TIFFmalloc.3t TIFFmemcmp.3t TIFFmemcpy.3t TIFFmemory.3t \
	TIFFmemset.3t TIFFquery.3t TIFFrealloc.3t TIFFsize.3t TIFFstrip.3t \
	TIFFswab.3t TIFFtile.3t libtiff.3t

DOCDIR=	${PREFIX}/share/doc/tiff

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}/images
	${INSTALL_DATA} ${WRKSRC}/html/*.html ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/html/images/* ${DOCDIR}/images
.endif
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libtiff.so.4.0 ${PREFIX}/lib/libtiff.so
.else
	${LN} -sf libtiff.so.4 ${PREFIX}/lib/libtiff.so
.endif
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
