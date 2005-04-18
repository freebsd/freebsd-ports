# New ports collection makefile for:	libgii
# Date created:		4 January 2000
# Whom:			mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	libgii
PORTVERSION=	0.9.1
CATEGORIES=	devel
MASTER_SITES=	http://www.ggi-project.org/ftp/ggi/v2.1/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ggi
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	antoine.brodin@laposte.net
COMMENT=	GGI API for input sources

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=	15
USE_REINPLACE=	yes

MAN1=		mhub.1
MAN3=		ggAddTask.3 ggCurTime.3 \
		ggGetSwarType.3 ggGetUserDir.3 ggInit.3 ggLoadModule.3 \
		ggLockCreate.3 ggRegisterCleanup.3 ggstrlcpy.3 \
		gg-error.3 gg-types.3 giiEventPoll.3 \
		giiEventSend.3 giiInit.3 giiMTInit.3 \
		giiOpen.3 giiPanic.3 giiQueryDeviceInfo.3 \
		giiQueryValInfo.3 giiSetEventMask.3 gii_cmd_event.3 \
		gii_cmddata_getdevinfo.3 gii_cmddata_getvalinfo.3 \
		gii_event.3 gii_expose_event.3 \
		gii_key_event.3 gii_pbutton_event.3 gii_pmove_event.3 \
		gii_val_event.3
MAN7=		filter-key.7 filter-mouse.7 filter-save.7 filter-tcp.7 \
		input-directx.7 input-file.7 input-linux-evdev.7 \
		input-linux-kbd.7 input-linux-mouse.7 input-lk201.7 \
		input-mouse.7 input-tcp.7 input-x.7 input-xwin.7 \
		libgg.7 libgii.7
MLINKS=		ggAddTask.3 ggDelTask.3 - ggTimeBase.3 \
		- GG_SCHED_TICKS2USECS.3 - GG_SCHED_USECS2TICKS.3 \
		ggRegisterCleanup.3 ggCleanupForceExit.3 \
		- ggUnregisterCleanup.3 \
		ggCurTime.3 ggUSleep.3 - ggUSlumber.3 \
		ggInit.3 ggExit.3 \
		ggLoadModule.3 ggFreeModule.3 - ggGetSymbolAddress.3 \
		ggLockCreate.3 ggLock.3 - ggLockDestroy.3 \
		- ggTryLock.3 - ggUnlock.3 \
		gg-error.3 ggi-error.3 - gii-error.3 \
		ggstrlcpy.3 ggstrlcat.3 \
		giiSetEventMask.3 giiAddEventMask.3 - giiGetEventMask.3 \
		giiOpen.3 giiClose.3 - giiJoinInputs.3 - giiSplitInputs.3 \
		giiEventPoll.3 giiEventRead.3 - giiEventSelect.3 \
		- giiEventsQueued.3 giiInit.3 giiExit.3 \
		giiQueryDeviceInfo.3 giiQueryDeviceInfoByNumber.3 \
		giiSetEventMask.3 giiRemoveEventMask.3 \
		gii_cmd_event.3 gii_cmd_nodata_event.3 \
		gii_event.3 gii_any_event.3 - gii_event_mask.3 \
		- gii_event_type.3 \
		gii_cmddata_getvalinfo.3 gii_phystype.3 - gii_valrange.3 \
		filter-key.7 filter-keytrans.7
DOCS=		ChangeLog NEWS README
EXAMPLES=	demos/demo.c demos/filter.c \
		demos/mhub.c demos/xsendbut.c

.if exists(/usr/include/dev/kii/kii.h)
CONFIGURE_ARGS+=	--enable-kii --with-extra-includes=/usr/include/dev
PLIST_SUB+=	KII=""
.else
PLIST_SUB+=	KII="@comment "
.endif

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
PLIST_SUB+=	WITH_X=""
MAN1+=		xsendbut.1
.else
CONFIGURE_ARGS+=	--disable-x --disable-xwin --without-x
PLIST_SUB+=	WITH_X="@comment "
.endif

.include <bsd.port.pre.mk>

.if !exists(/usr/include/vgl.h) || ${ARCH} != "i386"
CONFIGURE_ARGS+=	--disable-vgl
PLIST_SUB+=	VGL="@comment "
.else
PLIST_SUB+=	VGL=""
.endif

.if defined(WITHOUT_X11)
post-patch:
	@${REINPLACE_CMD} -e 's|\(mhub\.1\).*|\1|; s|xsendbut\.1||' \
		${WRKSRC}/doc/man/Makefile.in
.endif

post-install:
	@${CP} ${WRKSRC}/libgii.conf ${PREFIX}/etc/ggi/libgii.conf.dist
	@${CP} ${WRKSRC}/filter/mouse/mouse ${PREFIX}/etc/ggi/filter/mouse.dist
	@${CP} ${WRKSRC}/filter/keytrans/keytrans ${PREFIX}/etc/ggi/filter/keytrans.dist
	@${MKDIR} ${EXAMPLESDIR}
.for f in ${EXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${EXAMPLESDIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
