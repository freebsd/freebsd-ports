# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	gearmand
PORTVERSION=	1.1.8
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/gearmand/1.2/${PORTVERSION}/+download/

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Gearman C Server and Library

BUILD_DEPENDS=	boost-libs>=0:${PORTSDIR}/devel/boost-libs \
		libexecinfo>=0:${PORTSDIR}/devel/libexecinfo \
		${PYTHON_PKGNAMEPREFIX}sphinx>=0:${PORTSDIR}/textproc/py-sphinx
LIB_DEPENDS=	event:${PORTSDIR}/devel/libevent \
		uuid:${PORTSDIR}/misc/e2fsprogs-libuuid \
		execinfo:${PORTSDIR}/devel/libexecinfo

CONFLICTS=	p5-Gearman-Server-1.* gearmand-1.0.*

.if defined(MAINTAINER_MODE) && ${MAINTAINER_MODE:Myes}
UID_FILES=	../../UIDs
GID_FILES=	../../GIDs
.if !exists(${UID_FILES}) || !exists(${GID_FILES})
.error ${UID_FILES} or ${GID_FILES} does not exist - please check
.endif
.endif

LATEST_LINK=	gearmand-devel

USERS=		gearmand
GROUPS=		gearmand

FETCH_ARGS=	-pRr
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USES=	pathfix
USE_LDCONFIG=	yes
USE_PYTHON_BUILD=yes
USE_RC_SUBR=	gearmand
SUB_LIST+=	USERS=${USERS} GROUPS=${GROUPS}

CONFIGURE_ARGS+=--with-lib-prefix=${LOCALBASE} --with-boost=${LOCALBASE} \
		--localstatedir=/var/db/${PORTNAME} --enable-static
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lexecinfo

OPTIONS_DEFINE=	DRIZZLE MEMCACHED PGSQL SQLITE MYSQL HIREDIS TOKYOCAB
OPTIONS_DEFAULT=SQLITE

DRIZZLE_DESC=	Enable Drizzle support for persistent queue
MEMCACHED_DESC=	Enable memcached support for persistent queue
MYSQL_DESC=	Enable MySQL support for persistent queue
PGSQL_DESC=	Enable PostgreSQL support for persistent queue
SQLITE_DESC=	Enable SQLite support for persistent queue
HIREDIS_DESC=	Enable Hiredis support for persistent queue
TOKYOCAB_DESC=	Enable Tokyo Cabinet support for persistent queue

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
	gearman_worker_set_identifier.3 \
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

.include <bsd.port.options.mk>

# Workaround for missing sigignore that wasn't introduced until
# FreeBSD 8.0
.if ${OSVERSION} < 800041
BROKEN=	Does not compile without POSIX spawn() support
.endif

.if ${PORT_OPTIONS:MDRIZZLE}
LIB_DEPENDS+=		drizzle:${PORTSDIR}/databases/libdrizzle
CONFIGURE_ARGS+=	--enable-libdrizzle
.else
CONFIGURE_ARGS+=	--disable-libdrizzle
.endif

.if ${PORT_OPTIONS:MMEMCACHED}
LIB_DEPENDS+=		memcached:${PORTSDIR}/databases/libmemcached
BUILD_DEPENDS+=		memcached>=0:${PORTSDIR}/databases/memcached
CONFIGURE_ARGS+=	--enable-libmemcached
# This hack is required for the test programs invoked by configure,
# in the event that libmemcached was compiled with SASL support.
.if exists(${LOCALBASE}/lib/libsasl.so)
LDFLAGS+=		-L${LOCALBASE}/lib -lsasl
CONFIGURE_ARGS+=	--with-memcached-sasl=${LOCALBASE}/bin/memcached
.elif exists(${LOCALBASE}/lib/libsasl2.a)
LDFLAGS+=		-L${LOCALBASE}/lib -lsasl2
CONFIGURE_ARGS+=	--with-memcached-sasl=${LOCALBASE}/bin/memcached
.else
LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-memcached=${LOCALBASE}/bin/memcached
.endif
.else
CONFIGURE_ARGS+=	--disable-libmemcached
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql=yes
.else
CONFIGURE_ARGS+=	--with-mysql=no
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--enable-libpq
.else
CONFIGURE_ARGS+=	--disable-libpq
.endif

.if ${PORT_OPTIONS:MSQLITE}
BUILD_DEPENDS+=		sqlite3>=3.0.0:${PORTSDIR}/databases/sqlite3
LIB_DEPENDS+=		sqlite3:${PORTSDIR}/databases/sqlite3
CONFIGURE_ARGS+=	--with-sqlite3=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-sqlite3
.endif

.if ${PORT_OPTIONS:MTOKYOCAB}
LIB_DEPENDS+=		tokyocabinet:${PORTSDIR}/databases/tokyocabinet
CONFIGURE_ARGS+=	--enable-libtokyocabinet
CONFIGURE_ENV+=		LIBTOKYOCABINET_CPPFLAGS=-I${LOCALBASE}/include \
			LIBTOKYOCABINET_LDFLAGS=-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--disable-libtokyocabinet
.endif

.if ${PORT_OPTIONS:MHIREDIS}
LIB_DEPENDS+=		hiredis:${PORTSDIR}/databases/hiredis
CONFIGURE_ARGS+=	--enable-hires
CONFIGURE_ENV+=		LIBHIREDIS_CPPFLAGS=-I${LOCALBASE}/include/hiredis \
			LIBHIREDIS_LDFLAGS=-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--disable-hires
.endif

.include <bsd.port.mk>
