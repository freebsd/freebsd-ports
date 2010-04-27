# New ports collection makefile for:	gearmand
# Date created:		2009-01-29
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	gearmand
PORTVERSION=	0.13
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/gearmand/trunk/${PORTVERSION}/+download/ \
		LOCAL/glarkin

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Gearman C Server and Library

LIB_DEPENDS=	event:${PORTSDIR}/devel/libevent \
		uuid:${PORTSDIR}/misc/e2fsprogs-libuuid

CONFIGURE_ARGS=	--disable-libdrizzle --disable-libtokyocabinet
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
FETCH_ARGS=	-pRr
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
USE_RC_SUBR=	gearmand.sh

OPTIONS=	MEMCACHED "Enable memcached support" on \
		PQ "Enable PostgreSQL support" off \
		SQLITE3 "Enable SQLite3 support" off

MAN1=		gearman.1
MAN3=		gearman_bugreport.3 \
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
		gearman_client_job_status.3 \
		gearman_client_options.3 \
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
		gearman_client_set_options.3 \
		gearman_client_set_status_fn.3 \
		gearman_client_set_task_context_free_fn.3 \
		gearman_client_set_timeout.3 \
		gearman_client_set_warning_fn.3 \
		gearman_client_set_workload_fn.3 \
		gearman_client_set_workload_free_fn.3 \
		gearman_client_set_workload_malloc_fn.3 \
		gearman_client_task_free_all.3 \
		gearman_client_timeout.3 \
		gearman_client_wait.3 \
		gearman_job_free.3 \
		gearman_job_free_all.3 \
		gearman_job_function_name.3 \
		gearman_job_handle.3 \
		gearman_job_send_complete.3 \
		gearman_job_send_data.3 \
		gearman_job_send_exception.3 \
		gearman_job_send_fail.3 \
		gearman_job_send_status.3 \
		gearman_job_send_warning.3 \
		gearman_job_take_workload.3 \
		gearman_job_unique.3 \
		gearman_job_workload.3 \
		gearman_job_workload_size.3 \
		gearman_parse_servers.3 \
		gearman_task_context.3 \
		gearman_task_data.3 \
		gearman_task_data_size.3 \
		gearman_task_denominator.3 \
		gearman_task_free.3 \
		gearman_task_function_name.3 \
		gearman_task_give_workload.3 \
		gearman_task_is_known.3 \
		gearman_task_is_running.3 \
		gearman_task_job_handle.3 \
		gearman_task_numerator.3 \
		gearman_task_recv_data.3 \
		gearman_task_send_workload.3 \
		gearman_task_set_context.3 \
		gearman_task_take_data.3 \
		gearman_task_unique.3 \
		gearman_verbose_name.3 \
		gearman_version.3 \
		gearman_worker_add_function.3 \
		gearman_worker_add_options.3 \
		gearman_worker_add_server.3 \
		gearman_worker_add_servers.3 \
		gearman_worker_clone.3 \
		gearman_worker_context.3 \
		gearman_worker_create.3 \
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
		gearman_worker_set_options.3 \
		gearman_worker_set_timeout.3 \
		gearman_worker_set_workload_free_fn.3 \
		gearman_worker_set_workload_malloc_fn.3 \
		gearman_worker_timeout.3 \
		gearman_worker_unregister.3 \
		gearman_worker_unregister_all.3 \
		gearman_worker_wait.3 \
		gearman_worker_work.3
MAN8=		gearmand.8

.include <bsd.port.pre.mk>

.ifdef(WITHOUT_MEMCACHED)
CONFIGURE_ARGS+=	--disable-libmemcached
.else
CONFIGURE_ARGS+=	--with-libmemcached-prefix --without-memcached
LIB_DEPENDS+=	memcached:${PORTSDIR}/databases/libmemcached
.endif

.ifdef(WITH_PQ)
CONFIGURE_ARGS+=	--with-libpq-prefix
USE_PGSQL=	yes
.else
CONFIGURE_ARGS+=	--disable-libpq
.endif

.ifdef(WITH_SQLITE3)
CONFIGURE_ARGS+=	--with-libsqlite3-prefix
USE_SQLITE=	yes
.else
CONFIGURE_ARGS+=	--disable-libsqlite3
.endif

.include <bsd.port.post.mk>
