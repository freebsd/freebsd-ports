# New ports collection makefile for:	erlang
# Version required:	47.4.0
# Date created:		11 Dec 1998
# Whom:			ruslan@shevchenko.kiev.ua
#
# $Id$
#

DISTNAME=	erlang-47.4.0.base
PKGNAME=	erlang-47.4.0
CATEGORIES=	lang
MASTER_SITES=	http://www.erlang.org/download/

MAINTAINER=	ruslan@shevchenko.kiev.ua

WRKSRC=		${WRKDIR}/erlang-47.4.0

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

STRIP=

MAN1PREFIX=	${PREFIX}/lib/erlang
MAN1=	epmd.1 erl.1 erlc.1 erl_call.1 erlsrv.1 start_erl.1 werl.1

MAN3PREFIX=	${PREFIX}/lib/erlang
MAN3=	application.3 auth.3 c.3 calendar.3 code.3 compile.3 \
	dets.3 dict.3 digraph.3 disk_log.3 epp.3 erl_boot_server.3 \
	erl_connect.3 erl_ddll.3 erl_error.3 erl_eterm.3 erl_eval.3 \
	erl_format.3 erl_global.3 erl_id_trans.3 erl_internal.3 erl_lint.3 \
	erl_malloc.3 erl_marshal.3 erl_parse.3 erl_pp.3 erl_prim_loader.3 \
	erl_scan.3 erl_set_memory_block.3 erlang.3 error_handler.3 error_logger.3 \
	ets.3 file.3 filename.3 gen_event.3 gen_fsm.3 gen_server.3 gen_tcp.3 \
	gen_udp.3 global.3 global_group.3 heart.3 inet.3 init.3 io.3 io_lib.3 \
	lib.3 lists.3 log_mf_h.3 math.3 net_adm.3 net_kernel.3 ordsets.3 os.3 pg.3 \
	pg2.3 pool.3 proc_lib.3 queue.3 random.3 regexp.3 registry.3 rpc.3 \
	seq_trace.3 shell.3 shell_default.3 slave.3 string.3  supervisor.3 \
	supervisor_bridge.3 sys.3 tags.3 timer.3 unix.3 user.3 wrap_log_reader.3 \
	yecc.3

MAN4PREFIX=	${PREFIX}/lib/erlang
MAN4=	app.4 config.4

MAN6PREFIX=	${PREFIX}/lib/erlang
MAN6=	kernel.6

NOMANCOMPRESS=	yes

.include <bsd.port.mk>
