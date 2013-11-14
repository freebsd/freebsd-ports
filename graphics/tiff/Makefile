# Created by: Richard Hwang <rhwang@bigpanda.com>, Mikhail Teterin <mi@aldan.algebra.com>, Jun-ichiro itojun Itoh <itojun@itojun.org>
# $FreeBSD$

PORTNAME=	tiff
PORTVERSION=	4.0.3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.remotesensing.org/pub/libtiff/ \
		http://download.osgeo.org/libtiff/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Tools and library routines for working with TIFF images

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libjbig.so:${PORTSDIR}/graphics/jbigkit

USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS+=	--with-jpeg-include-dir=${LOCALBASE}/include \
			--with-jpeg-lib-dir=${LOCALBASE}/lib

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

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

.include <bsd.port.options.mk>

.if !defined(BUILDING_INDEX)
__pmlinks3!= ${ECHO_CMD} '${MLINKS:S/    / /}' | ${AWK} \
	'{ if (NF % 2 != 0) { print "broken"; exit; } \
	for (i=1; i<=NF; i++) { \
		if ( i % 2 == 0) { print " " $$i " ;"; } \
		else { printf "${LN} -s " $$i " "; } \
	} }'
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=	sm ice xmu xi x11
USE_GL=		glut glu gl
PLIST_SUB+=	WITH_X11=""
.else
CONFIGURE_ARGS+=	--without-x --without-libgl
PLIST_SUB+=	WITH_X11="@comment "
.endif

pre-configure:
	${REINPLACE_CMD} \
		-e 's|^LIBTIFF_VERSION_INFO =.*$$|LIBTIFF_VERSION_INFO = 4:0:0|' \
		${WRKSRC}/libtiff/Makefile.in
	${REINPLACE_CMD} -e 's|^docfiles|no-docfiles|' \
		-e 's|man html|man|' ${WRKSRC}/Makefile.in

post-install:
	( cd ${STAGEDIR}${MANPREFIX}/man/man3 && ${__pmlinks3} )
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/images ${STAGEDIR}${DOCSDIR}/man
	${INSTALL_DATA} ${WRKSRC}/html/*.html ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/html/images/*.jpg ${STAGEDIR}${DOCSDIR}/images/
	${INSTALL_DATA} ${WRKSRC}/html/images/*.gif ${STAGEDIR}${DOCSDIR}/images/
	${INSTALL_DATA} ${WRKSRC}/html/man/*.html ${STAGEDIR}${DOCSDIR}/man/
.endif

regression-test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
