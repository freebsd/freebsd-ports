# New ports collection makefile for:	libggi
# Date created:		4 January 2000
# Whom:			mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	libggi
PORTVERSION=	2.0.4
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	graphics devel
MASTER_SITES=	ftp://ftp.ggi-project.org/pub/packages/ggi/ggi/v2.0/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ggi
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A flexible drawing library

LIB_DEPENDS=	gii.0:${PORTSDIR}/devel/libgii

USE_BZIP2=	yes
USE_XLIB=	yes
INSTALLS_SHLIB=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-internal-dga	#This is broken for now
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.ifdef USE_THREADS
CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ARGS+=	--enable-threads
.endif

.if exists(/usr/include/kgi/kgi.h)
CONFIGURE_ARGS+=	--enable-kgi
.endif

MAN1=		cube3d.1 ggiteleserver.1 monitest.1
MAN3=		ggiCopyBox.3 ggiCrossBlit.3 ggiDBGetBuffer.3 \
		ggiDrawBox.3 ggiDrawHLine.3 ggiDrawLine.3 \
		ggiDrawPixel.3 ggiDrawVLine.3 ggiEventPoll.3 \
		ggiFillscreen.3 ggiFlush.3 ggiGetPixelFormat.3 \
		ggiGetc.3 ggiInit.3 ggiMapColor.3 ggiOpen.3 \
		ggiPanic.3 ggiParseMode.3 \
		ggiPutc.3 ggiResourceAcquire.3 \
		ggiSetColorfulPalette.3 ggiSetDisplayFrame.3 \
		ggiSetFlags.3 ggiSetGCClipping.3 \
		ggiSetGCForeground.3 ggiSetGamma.3 \
		ggiSetGraphMode.3 ggiSetMode.3 ggiSetOrigin.3 \
		ggiSetPalette.3 \
		ggiDetachInput.3 ggiEventSelect.3 \
		ggiGammaMax.3 ggiGetCharSize.3 ggiGetInput.3 \
		ggi_color.3 ggi_coord.3 ggi_directbuffer.3 \
		ggi_graphtype.3 ggi_mode.3 ggi_pixel.3 \
		ggi_pixelformat.3 ggi_pixellinearbuffer.3 \
		ggi_pixelplanarbuffer.3 ggi_samplelinearbuffer.3 \
		ggi_sampleplanarbuffer.3
MAN7=		libggi.7 \
		display-aa.7 display-dga.7 display-directx.7 \
		display-directxnt.7 display-fbdev.7 display-file.7 \
		display-glide.7 display-memory.7 display-monotext.7 \
		display-multi.7 display-palemu.7 display-sub.7 \
		display-svgalib.7 display-tele.7 display-tile.7 \
		display-trueemu.7 display-vcsa.7 display-vgl.7 \
		display-x.7
MLINKS=		ggiDBGetBuffer.3 ggiDBGetNumBuffers.3 \
		ggiDrawBox.3 ggiGetBox.3 - ggiPutBox.3 \
		ggiDrawHLine.3 ggiGetHLine.3 - ggiPutHLine.3 \
		ggiDrawPixel.3 ggiGetPixel.3 - ggiPutPixel.3 \
		ggiDrawVLine.3 ggiGetVLine.3 - ggiPutVLine.3 \
		ggiEventPoll.3 ggiAddEventMask.3 - ggiEventRead.3 \
		- ggiEventSend.3 - ggiEventsQueued.3 \
		- ggiGetEventMask.3 - ggiJoinInputs.3 \
		- ggiRemoveEventMask.3 - ggiSetEventMask.3 \
		ggiFlush.3 ggiFlushRegion.3 ggiGetc.3 ggiKbhit.3 \
		ggiInit.3 ggiExit.3 \
		ggiMapColor.3 ggiPackColors.3 - ggiUnmapPixel.3 \
		- ggiUnpackPixels.3 \
		ggiOpen.3 ggiClose.3 \
		ggiParseMode.3 ggiFPrintMode.3 - ggiPrintMode.3 \
		- ggiSPrintMode.3 ggiPutc.3 ggiPuts.3 \
		ggiResourceAcquire.3 ggiResourceMustAcquire.3 \
		- ggiResourceRelease.3 \
		ggiSetDisplayFrame.3 ggiGetDisplayFrame.3 \
		- ggiGetReadFrame.3 - ggiGetWriteFrame.3 \
		- ggiSetReadFrame.3 - ggiSetWriteFrame.3 \
		ggiSetFlags.3 ggiAddFlags.3 - ggiGetFlags.3 \
		- ggiRemoveFlags.3 \
		ggiSetGCClipping.3 ggiGetGCClipping.3 \
		ggiSetGCForeground.3 ggiGetGCBackground.3 \
		- ggiGetGCForeground.3 - ggiSetGCBackground.3 \
		ggiSetGamma.3ggi ggiGetGamma.3 - ggiGetGammaMap.3 \
		- ggiSetGammaMap.3 \
		ggiSetGraphMode.3 ggiCheckGraphMode.3 \
		- ggiCheckSimpleMode.3 - ggiCheckTextMode.3 \
		- ggiSetSimpleMode.3 - ggiSetTextMode.3 \
		ggiSetMode.3 ggiCheckMode.3 - ggiGetMode.3 \
		ggiSetOrigin.3 ggiGetOrigin.3 \
		ggiSetPalette.3 ggiGetPalette.3

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

.include <bsd.port.post.mk>
