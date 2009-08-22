# New ports collection makefile for:	libgii
# Date created:		4 January 2000
# Whom:			mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	libgii
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.ggi-project.org/ftp/ggi/v2.2/ \
		SF/ggi/ggi-core/${PORTNAME}-${PORTVERSION}		

DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	antoine.brodin@laposte.net
COMMENT=	GGI API for input sources

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

MAN1=		mhub.1 \
		xsendbut.1
MAN3=		gg-error.3 \
		gg-queue.3 \
		gg-tree.3 \
		gg-types.3 \
		ggAddObserver.3 \
		ggAddTask.3 ggCurTime.3 \
		ggGetScope.3 \
		ggGetSwarType.3 ggGetUserDir.3 ggInit.3 \
		ggLoadConfig.3 \
		ggLockCreate.3 \
		ggParseOptions.3 \
		ggRegisterCleanup.3 ggstrlcpy.3 \
		giiEventPoll.3 \
		giiEventSend.3 giiInit.3 giiMTInit.3 \
		giiOpen.3 giiPanic.3 giiQueryDeviceInfo.3 \
		giiQueryValInfo.3 giiSetEventMask.3 gii_cmd_event.3 \
		gii_cmddata_getdevinfo.3 gii_cmddata_getvalinfo.3 \
		gii_event.3 gii_expose_event.3 \
		gii_key_event.3 gii_pbutton_event.3 gii_pmove_event.3 \
		gii_val_event.3
MAN5=		libgii.conf.5
MAN7=		filter-key.7 filter-mouse.7 filter-save.7 filter-tcp.7 \
		input-directx.7 input-file.7 input-linux-evdev.7 \
		input-linux-kbd.7 input-linux-mouse.7 input-lk201.7 \
		input-mouse.7 \
		input-quartz.7 \
		input-tcp.7 input-x.7 \
		libgg.7 libgii.7
MLINKS=		gg-error.3 ggi-error.3 - gii-error.3 \
		gg-queue.3 GG_CIRCLEQ_EMPTY.3 \
		- GG_CIRCLEQ_ENTRY.3 \
		- GG_CIRCLEQ_FIRST.3 \
		- GG_CIRCLEQ_FOREACH.3 \
		- GG_CIRCLEQ_FOREACH_REVERSE.3 \
		- GG_CIRCLEQ_HEAD.3 \
		- GG_CIRCLEQ_HEAD_INITIALIZER.3 \
		- GG_CIRCLEQ_INIT.3 \
		- GG_CIRCLEQ_INSERT_AFTER.3 \
		- GG_CIRCLEQ_INSERT_BEFORE.3 \
		- GG_CIRCLEQ_INSERT_HEAD.3 \
		- GG_CIRCLEQ_INSERT_TAIL.3 \
		- GG_CIRCLEQ_LAST.3 \
		- GG_CIRCLEQ_NEXT.3 \
		- GG_CIRCLEQ_PREV.3 \
		- GG_CIRCLEQ_REMOVE.3 \
		- GG_LIST_EMPTY.3 \
		- GG_LIST_ENTRY.3 \
		- GG_LIST_FIRST.3 \
		- GG_LIST_FOREACH.3 \
		- GG_LIST_HEAD.3 \
		- GG_LIST_HEAD_INITIALIZER.3 \
		- GG_LIST_INIT.3 \
		- GG_LIST_INSERT_AFTER.3 \
		- GG_LIST_INSERT_BEFORE.3 \
		- GG_LIST_INSERT_HEAD.3 \
		- GG_LIST_NEXT.3 \
		- GG_LIST_REMOVE.3 \
		- GG_SIMPLEQ_EMPTY.3 \
		- GG_SIMPLEQ_ENTRY.3 \
		- GG_SIMPLEQ_FIRST.3 \
		- GG_SIMPLEQ_FOREACH.3 \
		- GG_SIMPLEQ_HEAD.3 \
		- GG_SIMPLEQ_HEAD_INITIALIZER.3 \
		- GG_SIMPLEQ_INIT.3 \
		- GG_SIMPLEQ_INSERT_AFTER.3 \
		- GG_SIMPLEQ_INSERT_HEAD.3 \
		- GG_SIMPLEQ_INSERT_TAIL.3 \
		- GG_SIMPLEQ_NEXT.3 \
		- GG_SIMPLEQ_REMOVE.3 \
		- GG_SIMPLEQ_REMOVE_HEAD.3 \
		- GG_SLIST_EMPTY.3 \
		- GG_SLIST_ENTRY.3 \
		- GG_SLIST_FIRST.3 \
		- GG_SLIST_FOREACH.3 \
		- GG_SLIST_HEAD.3 \
		- GG_SLIST_HEAD_INITIALIZER.3 \
		- GG_SLIST_INIT2.3 \
		- GG_SLIST_INSERT_AFTER.3 \
		- GG_SLIST_INSERT_HEAD.3 \
		- GG_SLIST_NEXT.3 \
		- GG_SLIST_REMOVE.3 \
		- GG_SLIST_REMOVE_HEAD.3 \
		- GG_TAILQ_EMPTY.3 \
		- GG_TAILQ_ENTRY.3 \
		- GG_TAILQ_FIRST.3 \
		- GG_TAILQ_FOREACH.3 \
		- GG_TAILQ_FOREACH_REVERSE.3 \
		- GG_TAILQ_HEAD.3 \
		- GG_TAILQ_HEAD_INITIALIZER.3 \
		- GG_TAILQ_INIT.3 \
		- GG_TAILQ_INSERT_AFTER.3 \
		- GG_TAILQ_INSERT_BEFORE.3 \
		- GG_TAILQ_INSERT_HEAD.3 \
		- GG_TAILQ_INSERT_TAIL.3 \
		- GG_TAILQ_LAST.3 \
		- GG_TAILQ_NEXT.3 \
		- GG_TAILQ_PREV.3 \
		- GG_TAILQ_REMOVE.3 \
		gg-tree.3 GG_RB_EMPTY.3 \
		- GG_RB_ENTRY.3 \
		- GG_RB_FIND.3 \
		- GG_RB_FOREACH.3 \
		- GG_RB_GENERATE.3 \
		- GG_RB_HEAD.3 \
		- GG_RB_INIT.3 \
		- GG_RB_INITIALIZER.3 \
		- GG_RB_INSERT.3 \
		- GG_RB_LEFT.3 \
		- GG_RB_MAX.3 \
		- GG_RB_MIN.3 \
		- GG_RB_NEXT.3 \
		- GG_RB_PARENT.3 \
		- GG_RB_PROTOTYPE.3 \
		- GG_RB_REMOVE.3 \
		- GG_RB_RIGHT.3 \
		- GG_RB_ROOT.3 \
		- GG_SPLAY_EMPTY.3 \
		- GG_SPLAY_ENTRY.3 \
		- GG_SPLAY_FIND.3 \
		- GG_SPLAY_FOREACH.3 \
		- GG_SPLAY_GENERATE.3 \
		- GG_SPLAY_HEAD.3 \
		- GG_SPLAY_INIT.3 \
		- GG_SPLAY_INITIALIZER.3 \
		- GG_SPLAY_INSERT.3 \
		- GG_SPLAY_LEFT.3 \
		- GG_SPLAY_MAX.3 \
		- GG_SPLAY_MIN.3 \
		- GG_SPLAY_NEXT.3 \
		- GG_SPLAY_PROTOTYPE.3 \
		- GG_SPLAY_REMOVE.3 \
		- GG_SPLAY_RIGHT.3 \
		- GG_SPLAY_ROOT.3 \
		ggAddObserver.3 ggClearPublisher.3 \
		- ggDelObserver.3 - ggNotifyObservers.3 \
		ggAddTask.3 ggDelTask.3 - ggTimeBase.3 \
		- GG_SCHED_TICKS2USECS.3 - GG_SCHED_USECS2TICKS.3 \
		ggRegisterCleanup.3 ggCleanupForceExit.3 \
		- ggUnregisterCleanup.3 \
		ggCurTime.3 ggUSleep.3 - ggUSlumber.3 \
		ggGetScope.3 ggDelScope.3 - ggFromScope.3 \
		- ggNewScope.3 \
		ggInit.3 ggExit.3 \
		ggLoadConfig.3 ggConfigIterLocation.3 - ggConfigIterTarget.3 \
		- ggFreeConfig.3 \
		ggLockCreate.3 ggLock.3 - ggLockDestroy.3 \
		- ggTryLock.3 - ggUnlock.3 \
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

.if exists(/usr/include/dev/kii/kii.h)
CONFIGURE_ARGS+=	--enable-kii --with-extra-includes=/usr/include/dev
PLIST_SUB+=	KII=""
.else
PLIST_SUB+=	KII="@comment "
.endif

.if !defined(WITHOUT_X11)
USE_XORG=	x11
PLIST_SUB+=	WITH_X=""
.else
CONFIGURE_ARGS+=	--disable-x --without-x
PLIST_SUB+=	WITH_X="@comment "
.endif

.include <bsd.port.pre.mk>

.if !exists(/usr/include/vgl.h) || ${ARCH} != "i386"
CONFIGURE_ARGS+=	--disable-vgl
PLIST_SUB+=	VGL="@comment "
.else
PLIST_SUB+=	VGL=""
.endif

pre-configure:
	${REINPLACE_CMD} -e 's/-lpthread/${PTHREAD_LIBS}/' ${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/libgii.conf ${PREFIX}/etc/ggi/libgii.conf.dist
	${INSTALL_DATA} ${WRKSRC}/filter/mouse/mouse ${PREFIX}/etc/ggi/filter/mouse.dist
	${INSTALL_DATA} ${WRKSRC}/filter/keytrans/keytrans ${PREFIX}/etc/ggi/filter/keytrans.dist

.include <bsd.port.post.mk>
