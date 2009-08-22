# New ports collection makefile for:	libggi
# Date created:		4 January 2000
# Whom:			mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	libggi
PORTVERSION=	2.2.2
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	graphics devel
MASTER_SITES=	http://www.ggi-project.org/ftp/ggi/v2.2/ \
		SF/ggi/ggi-core/${PORTNAME}-${PORTVERSION}		

DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	antoine.brodin@laposte.net
COMMENT=	A flexible drawing library

LIB_DEPENDS=	gii.1:${PORTSDIR}/devel/libgii

USE_BZIP2=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"

MAN1=		cube3d.1 ggi-demo.1 ggiteleserver.1 monitest.1
MAN3=		ggiCheckMode.3 ggiCopyBox.3 ggiCrossBlit.3 \
		ggiDBGetNumBuffers.3 ggiDrawBox.3 ggiDrawHLine.3 \
		ggiDrawLine.3 ggiDrawPixel.3 ggiDrawVLine.3 \
		ggiEventSend.3 ggiFillscreen.3 ggiFlush.3 \
		ggiGetGamma.3 ggiGetInput.3 ggiGetPixelFormat.3 \
		ggiGetc.3 ggiInit.3 ggiJoinInputs.3 \
		ggiMapColor.3 \
		ggiOpen.3 ggiPanic.3 ggiParseMode.3 \
		ggiPutc.3 ggiResourceAcquire.3 ggiSetColorfulPalette.3 \
		ggiSetDisplayFrame.3 ggiSetFlags.3 ggiSetGCClipping.3 \
		ggiSetGCForeground.3 ggiSetMode.3 ggiSetOrigin.3 \
		ggiSetPalette.3 ggiSetTextMode.3 \
		ggi_color.3 ggi_colormap.3 \
		ggi_directbuffer.3 ggi_mode.3 ggi_pixelformat.3 \
		ggidev-add_3.3 \
		ggidev-assign_3.3 \
		ggidev-eq_3.3 \
		ggidev-inc_3.3 \
		ggidev-invert_3.3 \
		ggidev-sign_3.3
MAN7=		libggi.7 display-aa.7 display-auto.7 \
		display-directx.7 \
		display-fbdev.7 display-file.7 display-glide.7 \
		display-mansync.7 display-memory.7 display-monotext.7 \
		display-multi.7 display-palemu.7 \
		display-quartz.7 display-sub.7 \
		display-svgalib.7 display-tele.7 display-terminfo.7 \
		display-tile.7 display-trueemu.7 \
		display-vcsa.7 display-vgl.7 display-x.7 \
		ggidev-triple-int.7
MLINKS=		ggi-demo.1 demo.1 \
		display-directx.7 display-directxnt.7 \
		ggiCheckMode.3 ggiCheckGraphMode.3 - ggiCheckSimpleMode.3 \
		- ggiCheckTextMode.3 ggiDBGetNumBuffers.3 ggiDBGetBuffer.3 \
		ggiDrawBox.3 ggiGetBox.3 - ggiPutBox.3 \
		ggiDrawHLine.3 ggiGetHLine.3 - ggiPutHLine.3 \
		ggiDrawPixel.3 ggiGetPixel.3 - ggiPutPixel.3 \
		ggiDrawVLine.3 ggiGetVLine.3 - ggiPutVLine.3 \
		ggiFlush.3 ggiFlushRegion.3 \
		ggiGetGamma.3 ggiGammaMax.3 - ggiGetGammaMap.3 \
		- ggiSetGamma.3 - ggiSetGammaMap.3 \
		ggiGetInput.3 ggiDetachInput.3 \
		ggiGetc.3 ggiKbhit.3 \
		ggiInit.3 ggiExit.3 \
		ggiJoinInputs.3 ggiAddEventMask.3 - ggiEventPoll.3 \
		- ggiEventRead.3 \
		ggiJoinInputs.3 ggiEventSelect.3 - ggiEventsQueued.3 \
		- ggiGetEventMask.3 - ggiRemoveEventMask.3 \
		- ggiSetEventMask.3 \
		ggiMapColor.3 ggiPackColors.3 - ggiUnmapPixel.3 \
		- ggiUnpackPixels.3 ggiOpen.3 ggiClose.3 \
		ggiParseMode.3 ggiFPrintMode.3 - ggiPrintMode.3 \
		- ggiSPrintMode.3 ggiPutc.3 ggiGetCharSize.3 \
		- ggiPuts.3 ggiResourceAcquire.3 ggiResourceMustAcquire.3 \
		- ggiResourceRelease.3 \
		ggiSetDisplayFrame.3 ggiGetDisplayFrame.3 - ggiGetReadFrame.3 \
		ggiSetDisplayFrame.3 ggiGetWriteFrame.3 - ggiSetReadFrame.3 \
		- ggiSetWriteFrame.3 \
		ggiSetFlags.3 ggiAddFlags.3 - ggiGetFlags.3 \
		- ggiRemoveFlags.3 \
		ggiSetGCClipping.3 ggiGetGCClipping.3 \
		ggiSetGCForeground.3 ggiGetGCBackground.3 \
		- ggiGetGCForeground.3 - ggiSetGCBackground.3 \
		ggiSetMode.3 ggiGetMode.3 \
		ggiSetOrigin.3 ggiGetOrigin.3 \
		ggiSetPalette.3 ggiGetPalette.3 \
		ggiSetTextMode.3 ggiSetGraphMode.3 - ggiSetSimpleMode.3 \
		ggi_color.3 ggi_pixel.3 \
		ggi_colormap.3 ggi_colormap_region.3 \
		ggi_directbuffer.3 ggi_pixellinearbuffer.3 \
		- ggi_pixelplanarbuffer.3 - ggi_samplelinearbuffer.3 \
		- ggi_sampleplanarbuffer.3 \
		ggi_mode.3 ggi_coord.3 - ggi_graphtype.3 \
		ggidev-add_3.3 ggidev-divmod_3.3 \
		- ggidev-mul_3.3 \
		- ggidev-sub_3.3 \
		ggidev-assign_3.3 ggidev-assign_int_3.3 \
		- ggidev-assign_unsigned_3.3 \
		ggidev-eq_3.3 ggidev-ge_3.3 \
		ggidev-inc_3.3 ggidev-abs_3.3 \
		- ggidev-dec_3.3 \
		- ggidev-negate_3.3 \
		ggidev-invert_3.3 ggidev-lshift_3.3 \
		- ggidev-rshift_3.3 \
		ggidev-sign_3.3 ggidev-bits_3.3 \
		- ggidev-eq0_3.3 \
		- ggidev-ge0_3.3 \
		- ggidev-gt0_3.3 \
		- ggidev-le0_3.3 \
		- ggidev-lt0_3.3

.if exists(/usr/include/dev/kgi/kgi.h)
CONFIGURE_ARGS+=	--enable-kgi --with-extra-includes=/usr/include/dev
.endif

.if !defined(WITHOUT_X11)
USE_XORG=	x11 xxf86dga xxf86vm ice sm xau xext
PLIST_SUB+=	WITH_X=""
.else
CONFIGURE_ARGS+=	--disable-x --disable-dga
PLIST_SUB+=	WITH_X="@comment "
.endif

.include <bsd.port.pre.mk>

.if !exists(/usr/include/vgl.h) || ${ARCH} != "i386"
CONFIGURE_ARGS+=	--disable-vgl
PLIST_SUB+=	WITH_VGL="@comment "
.else
PLIST_SUB+=	WITH_VGL=""
.endif

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
	${TOUCH} ${PREFIX}/lib/ggi/default/fbdev/.keep
	${TOUCH} ${PREFIX}/lib/ggi/default/kgi/.keep
	${TOUCH} ${PREFIX}/lib/ggi/helper/.keep
	${INSTALL_DATA} ${WRKSRC}/libggi.conf ${PREFIX}/etc/ggi/libggi.conf.dist

.include <bsd.port.post.mk>
