# New ports collection makefile for:	gearmand
# Date created:		2009-01-29
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	gearmand
PORTVERSION=	0.11
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/gearmand/trunk/${PORTVERSION}/+download/

MAINTAINER=	gslin@gslin.org
COMMENT=	Gearman C Server and Library

LIB_DEPENDS=	event:${PORTSDIR}/devel/libevent \
		uuid:${PORTSDIR}/misc/e2fsprogs-libuuid

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
FETCH_ARGS=	-pRr
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
USE_RC_SUBR=	gearmand.sh

OPTIONS=	PQ "Enable PostgreSQL support" off \
		SQLITE3 "Enable SQLite3 support" off \
		MEMCACHED "Enable memcached support" on

MAN1=		gearman.1
MAN3=		gearman_add_con.3 \
		gearman_add_con_args.3 \
		gearman_add_options.3 \
		gearman_add_packet.3 \
		gearman_add_packet_args.3 \
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
		gearman_client_job_status.3 \
		gearman_client_options.3 \
		gearman_client_remove_options.3 \
		gearman_client_remove_servers.3 \
		gearman_client_run_tasks.3 \
		gearman_client_set_complete_fn.3 \
		gearman_client_set_context.3 \
		gearman_client_set_created_fn.3 \
		gearman_client_set_data_fn.3 \
		gearman_client_set_event_watch_fn.3 \
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
		gearman_clone.3 \
		gearman_clone_con.3 \
		gearman_con_add_options.3 \
		gearman_con_close.3 \
		gearman_con_connect.3 \
		gearman_con_context.3 \
		gearman_con_flush.3 \
		gearman_con_free.3 \
		gearman_con_options.3 \
		gearman_con_protocol_context.3 \
		gearman_con_read.3 \
		gearman_con_recv.3 \
		gearman_con_recv_data.3 \
		gearman_con_remove_options.3 \
		gearman_con_reset_addrinfo.3 \
		gearman_con_send.3 \
		gearman_con_send_data.3 \
		gearman_con_set_context.3 \
		gearman_con_set_events.3 \
		gearman_con_set_fd.3 \
		gearman_con_set_host.3 \
		gearman_con_set_options.3 \
		gearman_con_set_packet_pack_fn.3 \
		gearman_con_set_packet_unpack_fn.3 \
		gearman_con_set_port.3 \
		gearman_con_set_protocol_context.3 \
		gearman_con_set_protocol_context_free_fn.3 \
		gearman_con_set_revents.3 \
		gearman_conf_create.3 \
		gearman_conf_errno.3 \
		gearman_conf_error.3 \
		gearman_conf_free.3 \
		gearman_conf_module_add_option.3 \
		gearman_conf_module_create.3 \
		gearman_conf_module_find.3 \
		gearman_conf_module_free.3 \
		gearman_conf_module_value.3 \
		gearman_conf_parse_args.3 \
		gearman_conf_return.3 \
		gearman_conf_set_options.3 \
		gearman_conf_usage.3 \
		gearman_create.3 \
		gearman_echo.3 \
		gearman_errno.3 \
		gearman_error.3 \
		gearman_flush_all.3 \
		gearman_free.3 \
		gearman_free_all_cons.3 \
		gearman_free_all_packets.3 \
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
		gearman_log.3 \
		gearman_log_crazy.3 \
		gearman_log_debug.3 \
		gearman_log_error.3 \
		gearman_log_fatal.3 \
		gearman_log_info.3 \
		gearman_options.3 \
		gearman_packet_add_arg.3 \
		gearman_packet_free.3 \
		gearman_packet_give_data.3 \
		gearman_packet_pack.3 \
		gearman_packet_pack_header.3 \
		gearman_packet_take_data.3 \
		gearman_packet_unpack.3 \
		gearman_packet_unpack_header.3 \
		gearman_parse_servers.3 \
		gearman_ready.3 \
		gearman_remove_options.3 \
		gearman_send_all.3 \
		gearman_server_client_add.3 \
		gearman_server_client_create.3 \
		gearman_server_client_free.3 \
		gearman_server_con_add.3 \
		gearman_server_con_con.3 \
		gearman_server_con_create.3 \
		gearman_server_con_data.3 \
		gearman_server_con_free.3 \
		gearman_server_con_free_worker.3 \
		gearman_server_con_free_workers.3 \
		gearman_server_con_host.3 \
		gearman_server_con_id.3 \
		gearman_server_con_io_add.3 \
		gearman_server_con_io_next.3 \
		gearman_server_con_io_remove.3 \
		gearman_server_con_port.3 \
		gearman_server_con_proc_add.3 \
		gearman_server_con_proc_next.3 \
		gearman_server_con_proc_remove.3 \
		gearman_server_con_set_data.3 \
		gearman_server_con_set_host.3 \
		gearman_server_con_set_id.3 \
		gearman_server_con_set_port.3 \
		gearman_server_create.3 \
		gearman_server_free.3 \
		gearman_server_function_create.3 \
		gearman_server_function_free.3 \
		gearman_server_function_get.3 \
		gearman_server_io_packet_add.3 \
		gearman_server_io_packet_remove.3 \
		gearman_server_job_add.3 \
		gearman_server_job_create.3 \
		gearman_server_job_free.3 \
		gearman_server_job_get.3 \
		gearman_server_job_peek.3 \
		gearman_server_job_queue.3 \
		gearman_server_job_take.3 \
		gearman_server_packet_create.3 \
		gearman_server_packet_free.3 \
		gearman_server_proc_packet_add.3 \
		gearman_server_proc_packet_remove.3 \
		gearman_server_queue_context.3 \
		gearman_server_queue_libdrizzle_conf.3 \
		gearman_server_queue_libdrizzle_deinit.3 \
		gearman_server_queue_libdrizzle_init.3 \
		gearman_server_queue_libmemcached_conf.3 \
		gearman_server_queue_libmemcached_deinit.3 \
		gearman_server_queue_libmemcached_init.3 \
		gearman_server_queue_libpq_conf.3 \
		gearman_server_queue_libpq_deinit.3 \
		gearman_server_queue_libpq_init.3 \
		gearman_server_queue_libsqlite3_conf.3 \
		gearman_server_queue_libsqlite3_deinit.3 \
		gearman_server_queue_libsqlite3_init.3 \
		gearman_server_queue_replay.3 \
		gearman_server_run_command.3 \
		gearman_server_set_job_retries.3 \
		gearman_server_set_log_fn.3 \
		gearman_server_set_queue_add_fn.3 \
		gearman_server_set_queue_context.3 \
		gearman_server_set_queue_done_fn.3 \
		gearman_server_set_queue_flush_fn.3 \
		gearman_server_set_queue_replay_fn.3 \
		gearman_server_set_worker_wakeup.3 \
		gearman_server_shutdown_graceful.3 \
		gearman_server_thread_create.3 \
		gearman_server_thread_errno.3 \
		gearman_server_thread_error.3 \
		gearman_server_thread_free.3 \
		gearman_server_thread_run.3 \
		gearman_server_thread_set_event_watch.3 \
		gearman_server_thread_set_log_fn.3 \
		gearman_server_thread_set_run.3 \
		gearman_server_worker_add.3 \
		gearman_server_worker_create.3 \
		gearman_server_worker_free.3 \
		gearman_set_error.3 \
		gearman_set_event_watch_fn.3 \
		gearman_set_log_fn.3 \
		gearman_set_options.3 \
		gearman_set_timeout.3 \
		gearman_set_workload_free_fn.3 \
		gearman_set_workload_malloc_fn.3 \
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
		gearman_timeout.3 \
		gearman_verbose_name.3 \
		gearman_version.3 \
		gearman_wait.3 \
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
		gearman_worker_grab_job.3 \
		gearman_worker_options.3 \
		gearman_worker_register.3 \
		gearman_worker_remove_options.3 \
		gearman_worker_remove_servers.3 \
		gearman_worker_set_context.3 \
		gearman_worker_set_event_watch_fn.3 \
		gearman_worker_set_log_fn.3 \
		gearman_worker_set_options.3 \
		gearman_worker_set_timeout.3 \
		gearman_worker_set_workload_free_fn.3 \
		gearman_worker_set_workload_malloc_fn.3 \
		gearman_worker_timeout.3 \
		gearman_worker_unregister.3 \
		gearman_worker_unregister_all.3 \
		gearman_worker_wait.3 \
		gearman_worker_work.3 \
		gearmand_con_check_queue.3 \
		gearmand_con_create.3 \
		gearmand_con_free.3 \
		gearmand_con_watch.3 \
		gearmand_create.3 \
		gearmand_free.3 \
		gearmand_port_add.3 \
		gearmand_protocol_http_conf.3 \
		gearmand_protocol_http_deinit.3 \
		gearmand_protocol_http_init.3 \
		gearmand_queue_libdrizzle_deinit.3 \
		gearmand_queue_libdrizzle_init.3 \
		gearmand_queue_libmemcached_deinit.3 \
		gearmand_queue_libmemcached_init.3 \
		gearmand_queue_libpq_deinit.3 \
		gearmand_queue_libpq_init.3 \
		gearmand_queue_libsqlite3_deinit.3 \
		gearmand_queue_libsqlite3_init.3 \
		gearmand_run.3 \
		gearmand_set_backlog.3 \
		gearmand_set_job_retries.3 \
		gearmand_set_log_fn.3 \
		gearmand_set_threads.3 \
		gearmand_set_worker_wakeup.3 \
		gearmand_thread_create.3 \
		gearmand_thread_free.3 \
		gearmand_thread_run.3 \
		gearmand_thread_wakeup.3 \
		gearmand_wakeup.3
MAN8=		gearmand.8

.include <bsd.port.pre.mk>

.ifdef(WITH_MEMCACHED)
PLIST_SUB+=	MEMCACHED=""
CONFIGURE_ARGS+=	--with-libmemcached-prefix --without-memcached
LIB_DEPENDS+=	memcached:${PORTSDIR}/databases/libmemcached
.else
PLIST_SUB+=	MEMCACHED="@comment "
CONFIGURE_ARGS+=	--disable-libmemcached
.endif

.ifdef(WITH_PQ)
PLIST_SUB+=	PG=""
CONFIGURE_ARGS+=	--with-libpq-prefix
USE_PGSQL=	yes
.else
PLIST_SUB+=	PG="@comment "
CONFIGURE_ARGS+=	--disable-libpq
.endif

.ifdef(WITH_SQLITE3)
PLIST_SUB+=	SQLITE=""
CONFIGURE_ARGS+=	--with-libsqlite3-prefix
USE_SQLITE=	yes
.else
PLIST_SUB+=	SQLITE="@comment "
CONFIGURE_ARGS+=	--disable-libsqlite3
.endif

.include <bsd.port.post.mk>
