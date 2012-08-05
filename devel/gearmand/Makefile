# New ports collection makefile for:	gearmand
# Date created:		2009-01-29
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	gearmand
PORTVERSION=	0.26
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/gearmand/trunk/${PORTVERSION}/+download/ \
		LOCAL/glarkin

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Gearman C Server and Library

BUILD_DEPENDS=	boost-libs>=0:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	event:${PORTSDIR}/devel/libevent \
		uuid:${PORTSDIR}/misc/e2fsprogs-libuuid

FETCH_ARGS=	-pRr
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
USE_RC_SUBR=	gearmand
CONFIGURE_ARGS+=--with-lib-prefix=${LOCALBASE} --with-boost=${LOCALBASE}

OPTIONS=	DRIZZLE "Enable Drizzle support for persistent queue" off \
		MEMCACHED "Enable memcached support for persistent queue" off \
		PGSQL "Enable PostgreSQL support for persistent queue" off \
		SQLITE "Enable SQLite support for persistent queue" on \
		REDIS "Enable Redis support for persistent queue" off \
		TOKYOCAB "Enable Tokyo Cabinet support for persistent queue" off

MAN1=	gearadmin.1 \
	gearman.1
MAN3=	gearman_actions_t.3 \
	gearman_allocator_t.3 \
	gearman_argument_make.3 \
	gearman_argument_t.3 \
	gearman_bugreport.3 \
	gearman_client_add_options.3 \
	gearman_client_add_server.3 \
	gearman_client_add_servers.3 \
	gearman_client_add_task.3 \
	gearman_client_add_task_background.3 \
	gearman_client_add_task_high.3 \
	gearman_client_add_task_high_background.3 \
	gearman_client_add_task_low.3 \
	gearman_client_add_task_low_background.3 \
	gearman_client_add_task_status.3 \
	gearman_client_clear_fn.3 \
	gearman_client_clone.3 \
	gearman_client_context.3 \
	gearman_client_create.3 \
	gearman_client_do.3 \
	gearman_client_do_background.3 \
	gearman_client_do_high.3 \
	gearman_client_do_high_background.3 \
	gearman_client_do_job_handle.3 \
	gearman_client_do_low.3 \
	gearman_client_do_low_background.3 \
	gearman_client_do_status.3 \
	gearman_client_echo.3 \
	gearman_client_errno.3 \
	gearman_client_error.3 \
	gearman_client_free.3 \
	gearman_client_has_option.3 \
	gearman_client_job_status.3 \
	gearman_client_options.3 \
	gearman_client_options_t.3 \
	gearman_client_remove_options.3 \
	gearman_client_remove_servers.3 \
	gearman_client_run_tasks.3 \
	gearman_client_set_complete_fn.3 \
	gearman_client_set_context.3 \
	gearman_client_set_created_fn.3 \
	gearman_client_set_data_fn.3 \
	gearman_client_set_exception_fn.3 \
	gearman_client_set_fail_fn.3 \
	gearman_client_set_log_fn.3 \
	gearman_client_set_memory_allocators.3 \
	gearman_client_set_namespace.3 \
	gearman_client_set_options.3 \
	gearman_client_set_status_fn.3 \
	gearman_client_set_task_context_free_fn.3 \
	gearman_client_set_timeout.3 \
	gearman_client_set_warning_fn.3 \
	gearman_client_set_workload_fn.3 \
	gearman_client_set_workload_free_fn.3 \
	gearman_client_set_workload_malloc_fn.3 \
	gearman_client_st.3 \
	gearman_client_task_free_all.3 \
	gearman_client_timeout.3 \
	gearman_client_wait.3 \
	gearman_continue.3 \
	gearman_execute.3 \
	gearman_failed.3 \
	gearman_job_free.3 \
	gearman_job_free_all.3 \
	gearman_job_function_name.3 \
	gearman_job_handle.3 \
	gearman_job_handle_t.3 \
	gearman_job_send_complete.3 \
	gearman_job_send_data.3 \
	gearman_job_send_exception.3 \
	gearman_job_send_fail.3 \
	gearman_job_send_status.3 \
	gearman_job_send_warning.3 \
	gearman_job_st.3 \
	gearman_job_take_workload.3 \
	gearman_job_unique.3 \
	gearman_job_workload.3 \
	gearman_job_workload_size.3 \
	gearman_log_fn.3 \
	gearman_parse_servers.3 \
	gearman_result_boolean.3 \
	gearman_result_integer.3 \
	gearman_result_is_null.3 \
	gearman_result_size.3 \
	gearman_result_store_integer.3 \
	gearman_result_store_string.3 \
	gearman_result_store_value.3 \
	gearman_result_string.3 \
	gearman_return_t.3 \
	gearman_strerror.3 \
	gearman_string_t.3 \
	gearman_success.3 \
	gearman_task_attr_init.3 \
	gearman_task_attr_init_background.3 \
	gearman_task_attr_init_epoch.3 \
	gearman_task_attr_t.3 \
	gearman_task_context.3 \
	gearman_task_data.3 \
	gearman_task_data_size.3 \
	gearman_task_denominator.3 \
	gearman_task_error.3 \
	gearman_task_free.3 \
	gearman_task_function_name.3 \
	gearman_task_give_workload.3 \
	gearman_task_is_known.3 \
	gearman_task_is_running.3 \
	gearman_task_job_handle.3 \
	gearman_task_numerator.3 \
	gearman_task_recv_data.3 \
	gearman_task_return.3 \
	gearman_task_send_workload.3 \
	gearman_task_set_context.3 \
	gearman_task_st.3 \
	gearman_task_take_data.3 \
	gearman_task_unique.3 \
	gearman_verbose_name.3 \
	gearman_verbose_t.3 \
	gearman_version.3 \
	gearman_worker_add_function.3 \
	gearman_worker_add_options.3 \
	gearman_worker_add_server.3 \
	gearman_worker_add_servers.3 \
	gearman_worker_clone.3 \
	gearman_worker_context.3 \
	gearman_worker_create.3 \
	gearman_worker_define_function.3 \
	gearman_worker_echo.3 \
	gearman_worker_errno.3 \
	gearman_worker_error.3 \
	gearman_worker_free.3 \
	gearman_worker_function_exist.3 \
	gearman_worker_grab_job.3 \
	gearman_worker_options.3 \
	gearman_worker_register.3 \
	gearman_worker_remove_options.3 \
	gearman_worker_remove_servers.3 \
	gearman_worker_set_context.3 \
	gearman_worker_set_log_fn.3 \
	gearman_worker_set_memory_allocators.3 \
	gearman_worker_set_namespace.3 \
	gearman_worker_set_options.3 \
	gearman_worker_set_timeout.3 \
	gearman_worker_set_workload_free_fn.3 \
	gearman_worker_set_workload_malloc_fn.3 \
	gearman_worker_st.3 \
	gearman_worker_timeout.3 \
	gearman_worker_unregister.3 \
	gearman_worker_unregister_all.3 \
	gearman_worker_wait.3 \
	gearman_worker_work.3 \
	libgearman.3
MAN8=	gearmand.8

.include <bsd.port.pre.mk>

# Workaround for missing sigignore that wasn't introduced until
# FreeBSD 8.0
.if ${OSVERSION} < 800500
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-libtest__test.cc
.endif

# This hack is required for the test programs invoked by configure,
# in the event that libmemcached was compiled with SASL support.
.if exists(${LOCALBASE}/lib/libsasl.so)
LDFLAGS+=	-L${LOCALBASE}/lib -lsasl
.elif exists(${LOCALBASE}/lib/libsasl2.a)
LDFLAGS+=	-L${LOCALBASE}/lib -lsasl2
.else
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

.ifdef(WITH_DRIZZLE)
LIB_DEPENDS+=		drizzle:${PORTSDIR}/databases/libdrizzle
.else
CONFIGURE_ARGS+=	--disable-libdrizzle
.endif

.ifdef(WITH_MEMCACHED)
LIB_DEPENDS+=		memcached:${PORTSDIR}/databases/libmemcached
BUILD_DEPENDS+=		memcached>=0:${PORTSDIR}/databases/memcached
CONFIGURE_ARGS+=	--enable-libmemcached --with-memcached=${LOCALBASE}/bin
.else
CONFIGURE_ARGS+=	--disable-libmemcached
.endif

.ifdef(WITH_PGSQL)
USE_PGSQL=		yes
.else
CONFIGURE_ARGS+=	--disable-libpq
.endif

.ifdef(WITH_SQLITE)
BUILD_DEPENDS+=		sqlite3>=3.0.0:${PORTSDIR}/databases/sqlite3
LIB_DEPENDS+=		sqlite3:${PORTSDIR}/databases/sqlite3
CONFIGURE_ARGS+=	--with-sqlite3=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-sqlite3
.endif

.ifdef(WITH_TOKYOCAB)
LIB_DEPENDS+=		tokyocabinet:${PORTSDIR}/databases/tokyocabinet
CONFIGURE_ARGS+=	--with-libtokyocabinet-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--disable-libtokyocabinet
.endif

.ifdef(WITH_REDIS)
LIB_DEPENDS+=		hiredis:${PORTSDIR}/databases/hiredis
CONFIGURE_ARGS+=	--with-libhiredis-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-libhiredis-prefix
.endif

.include <bsd.port.post.mk>
