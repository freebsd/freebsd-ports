# New ports collection makefile for:	libggi
# Date created:		4 January 2000
# Whom:			mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	libggi
PORTVERSION=	2.0b2.1
CATEGORIES=	graphics devel
MASTER_SITES=	ftp://ftp.ggi-project.org/pub/ggi/ggi/2_0_beta_2.1/

MAINTAINER=	mwest@uct.ac.za

LIB_DEPENDS=	gii.0:${PORTSDIR}/devel/libgii

USE_BZIP2=	yes
USE_XLIB=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gii=${PREFIX}

MAN3=		ggiAddFlags.3ggi ggiCheckGraphMode.3ggi ggiCheckMode.3ggi \
		ggiCheckSimpleMode.3ggi ggiCheckTextMode.3ggi ggiClose.3ggi \
		ggiCopyBox.3ggi ggiCrossBlit.3ggi ggiDBGetBuffer.3ggi \
		ggiDBGetNumBuffers.3ggi ggiDrawBox.3ggi ggiDrawHLine.3ggi \
		ggiDrawLine.3ggi ggiDrawPixel.3ggi ggiDrawVLine.3ggi \
		ggiExit.3ggi ggiFPrintMode.3ggi ggiFillscreen.3ggi \
		ggiFlush.3ggi ggiGetBox.3ggi ggiGetDisplayFrame.3ggi \
		ggiGetFlags.3ggi ggiGetGCBackground.3ggi \
		ggiGetGCClipping.3ggi ggiGetGCForeground.3ggi \
		ggiGetGamma.3ggi ggiGetGammaMap.3ggi ggiGetHLine.3ggi \
		ggiGetMode.3ggi ggiGetOrigin.3ggi ggiGetPalette.3ggi \
		ggiGetPixel.3ggi ggiGetPixelFormat.3ggi ggiGetReadFrame.3ggi \
		ggiGetVLine.3ggi ggiGetWriteFrame.3ggi ggiInit.3ggi \
		ggiMapColor.3ggi ggiOpen.3ggi ggiPackColors.3ggi \
		ggiPanic.3ggi ggiParseMode.3ggi ggiPrintMode.3ggi \
		ggiPutBox.3ggi ggiPutHLine.3ggi ggiPutPixel.3ggi \
		ggiPutVLine.3ggi ggiPutc.3ggi ggiPuts.3ggi \
		ggiRemoveFlags.3ggi ggiSPrintMode.3ggi \
		ggiSetDisplayFrame.3ggi ggiSetFlags.3ggi \
		ggiSetGCBackground.3ggi ggiSetGCClipping.3ggi \
		ggiSetGCForeground.3ggi ggiSetGamma.3ggi ggiSetGammaMap.3ggi \
		ggiSetGraphMode.3ggi ggiSetMode.3ggi ggiSetOrigin.3ggi \
		ggiSetPalette.3ggi ggiSetReadFrame.3ggi ggiSetSimpleMode.3ggi \
		ggiSetTextMode.3ggi ggiSetWriteFrame.3ggi ggiUnmapPixel.3ggi \
		ggiUnpackPixels.3ggi ggiSetColorfulPalette.3ggi \
		ggiFlushRegion.3ggi ggiResourceAcquire.3ggi \
		ggiResourceRelease.3ggi ggiResourceMustAcquire.3ggi
MAN6=		cube3d.6
MAN7=		libggi.7ggi

.include <bsd.port.mk>
