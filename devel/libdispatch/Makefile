# New ports collection makefile for:		libdispatch
# Date created:					2009-09-23
# Whom:						stas
#
# $FreeBSD$
#

PORTNAME=	libdispatch
PORTVERSION=	171
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/
DISTNAME=	${PORTNAME}-r${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Grand Central Dispatch API support library

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes

OPTIONS=	CLANG "Build with LLVM/Clang (required for blocks support)" off

MAN3=	dispatch.3 dispatch_after.3 dispatch_api.3 dispatch_apply.3 \
	dispatch_async.3 dispatch_benchmark.3 dispatch_group_create.3 \
	dispatch_object.3 dispatch_once.3 dispatch_queue_create.3 \
	dispatch_semaphore_create.3 dispatch_source_create.3 dispatch_time.3

MLINKS= dispatch_after.3 dispatch_after_f.3 \
	dispatch_apply.3 dispatch_apply_f.3 \
	dispatch_async.3 dispatch_sync.3 \
	dispatch_async.3 dispatch_async_f.3 \
	dispatch_async.3 dispatch_sync_f.3 \
	dispatch_benchmark.3 dispatch_benchmark_f.3 \
	dispatch_group_create.3 dispatch_group_enter.3 \
	dispatch_group_create.3 dispatch_group_leave.3 \
	dispatch_group_create.3 dispatch_group_wait.3 \
	dispatch_group_create.3 dispatch_group_notify.3 \
	dispatch_group_create.3 dispatch_group_notify_f.3 \
	dispatch_group_create.3 dispatch_group_async.3 \
	dispatch_group_create.3 dispatch_group_async_f.3 \
	dispatch_object.3 dispatch_retain.3 \
	dispatch_object.3 dispatch_release.3 \
	dispatch_object.3 dispatch_suspend.3 \
	dispatch_object.3 dispatch_resume.3 \
	dispatch_object.3 dispatch_get_context.3 \
	dispatch_object.3 dispatch_set_context.3 \
	dispatch_object.3 dispatch_set_finalizer_f.3 \
	dispatch_once.3 dispatch_once_f.3 \
	dispatch_queue_create.3 dispatch_queue_get_label.3 \
	dispatch_queue_create.3 dispatch_get_current_queue.3 \
	dispatch_queue_create.3 dispatch_get_global_queue.3 \
	dispatch_queue_create.3 dispatch_get_main_queue.3 \
	dispatch_queue_create.3 dispatch_main.3 \
	dispatch_queue_create.3 dispatch_set_target_queue.3 \
	dispatch_semaphore_create.3 dispatch_semaphore_signal.3 \
	dispatch_semaphore_create.3 dispatch_semaphore_wait.3 \
	dispatch_source_create.3 dispatch_source_set_event_handler.3 \
	dispatch_source_create.3 dispatch_source_set_event_handler_f.3 \
	dispatch_source_create.3 dispatch_source_set_cancel_handler.3 \
	dispatch_source_create.3 dispatch_source_set_cancel_handler_f.3 \
	dispatch_source_create.3 dispatch_source_cancel.3 \
	dispatch_source_create.3 dispatch_source_testcancel.3 \
	dispatch_source_create.3 dispatch_source_get_handle.3 \
	dispatch_source_create.3 dispatch_source_get_mask.3 \
	dispatch_source_create.3 dispatch_source_get_data.3 \
	dispatch_source_create.3 dispatch_source_merge_data.3 \
	dispatch_source_create.3 dispatch_source_set_timer.3 \
	dispatch_time.3 dispatch_walltime.3

#
# Get rid of .la and static library files
#
post-configure:
	@${REINPLACE_CMD} -E -e \
	'/Install the pseudo-library/,/staticlibs=/s,^,#,' ${WRKSRC}/libtool

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 800107 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900002)
IGNORE=	is not supported on this OS version
.endif

.if defined(WITH_CLANG)
BROKEN=	does not compile
.endif

.if defined(WITH_CLANG)
BUILD_DEPENDS+=	clang:${PORTSDIR}/devel/llvm-devel \
		${LOCALBASE}/lib/libBlocksRuntime.so:${PORTSDIR}/devel/compiler-rt
RUN_DEPENDS+=	clang:${PORTSDIR}/devel/llvm-devel \
		${LOCALBASE}/lib/libBlocksRuntime.so:${PORTSDIR}/devel/compiler-rt
CONFIGURE_ARGS+=	--with-blocks-runtime=/usr/local/lib
CONFIGURE_ENV+=	CC="clang"
MAKE_ENV+=	CC="clang"
.endif

.include <bsd.port.post.mk>
