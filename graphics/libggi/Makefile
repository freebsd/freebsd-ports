# New ports collection makefile for:	libggi
# Date created:		4 January 2000
# Whom:			mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	libggi
PORTVERSION=	2.0b3
CATEGORIES=	graphics devel
MASTER_SITES=	ftp://ftp.ggi-project.org/pub/ggi/ggi/2_0_beta_3/

MAINTAINER=	mwest@uct.ac.za

LIB_DEPENDS=	gii.0:${PORTSDIR}/devel/libgii

USE_BZIP2=	yes
USE_XLIB=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gii=${PREFIX}

MAN3=		ggiCopyBox.3ggi ggiCrossBlit.3ggi ggiDBGetBuffer.3ggi \
		ggiDrawBox.3ggi ggiDrawHLine.3ggi ggiDrawLine.3ggi \
		ggiDrawPixel.3ggi ggiDrawVLine.3ggi ggiEventPoll.3ggi \
		ggiFillscreen.3ggi ggiFlush.3ggi ggiGetPixelFormat.3ggi \
		ggiGetc.3ggi ggiInit.3ggi ggiMapColor.3ggi ggiOpen.3ggi \
		ggiPanic.3ggi ggiParseMode.3ggi \
		ggiPutc.3ggi ggiResourceAcquire.3ggi \
		ggiSetColorfulPalette.3ggi ggiSetDisplayFrame.3ggi \
		ggiSetFlags.3ggi ggiSetGCClipping.3ggi \
		ggiSetGCForeground.3ggi ggiSetGamma.3ggi \
		ggiSetGraphMode.3ggi ggiSetMode.3ggi ggiSetOrigin.3ggi \
		ggiSetPalette.3ggi
MAN6=		cube3d.6
MAN7=		libggi.7ggi
MLINKS=		ggiDBGetBuffer.3ggi ggiDBGetNumBuffers.3ggi \
		ggiDrawBox.3ggi ggiGetBox.3ggi - ggiPutBox.3ggi \
		ggiDrawHLine.3ggi ggiGetHLine.3ggi - ggiPutHLine.3ggi \
		ggiDrawPixel.3ggi ggiGetPixel.3ggi - ggiPutPixel.3ggi \
		ggiDrawVLine.3ggi ggiGetVLine.3ggi - ggiPutVLine.3ggi \
		ggiEventPoll.3ggi ggiAddEventMask.3ggi - ggiEventRead.3ggi \
		- ggiEventSend.3ggi - ggiEventsQueued.3ggi \
		- ggiGetEventMask.3ggi - ggiJoinInputs.3ggi \
		- ggiRemoveEventMask.3ggi - ggiSetEventMask.3ggi \
		ggiFlush.3ggi ggiFlushRegion.3ggi ggiGetc.3ggi ggiKbhit.3ggi \
		ggiInit.3ggi ggiExit.3ggi \
		ggiMapColor.3ggi ggiPackColors.3ggi - ggiUnmapPixel.3ggi \
		- ggiUnpackPixels.3ggi \
		ggiOpen.3ggi ggiClose.3ggi \
		ggiParseMode.3ggi ggiFPrintMode.3ggi - ggiPrintMode.3ggi \
		- ggiSPrintMode.3ggi ggiPutc.3ggi ggiPuts.3ggi \
		ggiResourceAcquire.3ggi ggiResourceMustAcquire.3ggi \
		- ggiResourceRelease.3ggi \
		ggiSetDisplayFrame.3ggi ggiGetDisplayFrame.3ggi \
		- ggiGetReadFrame.3ggi - ggiGetWriteFrame.3ggi \
		- ggiSetReadFrame.3ggi - ggiSetWriteFrame.3ggi \
		ggiSetFlags.3ggi ggiAddFlags.3ggi - ggiGetFlags.3ggi \
		- ggiRemoveFlags.3ggi \
		ggiSetGCClipping.3ggi ggiGetGCClipping.3ggi \
		ggiSetGCForeground.3ggi ggiGetGCBackground.3ggi \
		- ggiGetGCForeground.3ggi - ggiSetGCBackground.3ggi \
		ggiSetGamma.3ggi ggiGetGamma.3ggi - ggiGetGammaMap.3ggi \
		- ggiSetGammaMap.3ggi \
		ggiSetGraphMode.3ggi ggiCheckGraphMode.3ggi \
		- ggiCheckSimpleMode.3ggi - ggiCheckTextMode.3ggi \
		- ggiSetSimpleMode.3ggi - ggiSetTextMode.3ggi \
		ggiSetMode.3ggi ggiCheckMode.3ggi - ggiGetMode.3ggi \
		ggiSetOrigin.3ggi ggiGetOrigin.3ggi \
		ggiSetPalette.3ggi ggiGetPalette.3ggi

.include <bsd.port.pre.mk>

.if defined(WITH_AALIB) || exists(${LOCALBASE}/include/aalib.h)
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib
PLIST_SUB+=	WITH_AALIB=""
.else
PLIST_SUB+=	WITH_AALIB="@comment "
.endif

.if defined(WITH_SVGALIB) || exists(${LOCALBASE}/include/vga.h)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
PLIST_SUB+=	WITH_SVGALIB=""
.else
PLIST_SUB+=	WITH_SVGALIB="@comment "
.endif

post-install:
	@${CP} ${WRKSRC}/libggi.conf ${PREFIX}/etc/ggi/libggi.conf.dist
	@${CP} ${WRKSRC}/extensions/misc/libggimisc.conf ${PREFIX}/etc/ggi/libggimisc.conf.dist

.include <bsd.port.post.mk>
