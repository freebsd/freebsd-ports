# New ports collection makefile for:	erlang
# Date created:		11 Dec 1998
# Whom:			ruslan@shevchenko.kiev.ua
#
# $FreeBSD$
#

PORTNAME=	erlang
PORTVERSION=	7.2.0
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.erlang.org/pub/download/     \
		http://www.erlang.org/download/        \
		http://erlang.stacken.kth.se/download/ \
		http://www.csd.uu.se/ftp/mirror/erlang/download/
DISTNAME=	otp_src_R7B-2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${ERLANG_MAN} ${ERLANG_DOCS}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	http://www.erlang.org/download/patches/
PATCHFILES=
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sam@inf.enst.fr

BUILD_DEPENDS=  ${JAVAPORT}

CONFIGURE_TARGET=	# Empty

# Don't clutter up /usr/ports/distfiles with all distfiles (including patches)
DIST_SUBDIR=	erlang

ERLANG_MAN=     otp_doc_man_R7B.tar.gz
.if !defined(NOPORTDOCS)
ERLANG_DOCS=	otp_doc_html_R7B.tar.gz
.endif

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
.endif
USE_GMAKE=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes

# UPDATED_PACKAGES is the list of updated packages which documentation must
# be pulled in from the docs tarball. "erts" lives in the erlang root
# directory and should never be prefixed by lib/. See below for Java related
# packages.

UPDATED_PACKAGES=	erts lib/compiler lib/erl_interface \
			lib/kernel lib/mnesia lib/sasl \
			lib/snmp lib/stdlib lib/asn1 lib/debugger \
			lib/gs lib/ic lib/inets lib/orber \
			lib/runtime_tools lib/ssl lib/tools

.if !defined(WITHOUT_JAVA)
# The Java applications that are part of the Erlang distribution are
# not strictly necessary - it is included for completeness sake. A
# problem with the Erlang build procedure is that it only checks if
# javac is in the regular path - and then assumes that all of the jdk
# utilities is in the path as well. The only way to make sure that
# this is the case (that I could think of at least) was to make sure
# JAVABINDIR is added to the PATH, using the *_ENV macros.

# The following UPDATED_PACKAGES depend on java.
UPDATED_PACKAGES+=	lib/jinterface

# Set JAVABINDIR to where you have javac, if different from below
JAVABINDIR?=	${LOCALBASE}/jdk1.2.2/bin
JAVAPORT?=	${JAVABINDIR}/javac:${PORTSDIR}/java/jdk12-beta

# Make sure javabindir is in the path
CONFIGURE_ENV+= PATH=${PATH}:${JAVABINDIR}
MAKE_ENV+=      PATH=${PATH}:${JAVABINDIR}
SCRIPT_ENV+=    PATH=${PATH}:${JAVABINDIR}
.endif

.if !defined(WITHOUT_X11)
PLIST_SUB+= 	WITHOUT_X11=""
.else
PLIST_SUB+= 	WITHOUT_X11="@comment "
.endif

.if !defined(WITHOUT_JAVA)
PLIST_SUB+= 	WITHOUT_JAVA=""
.else
PLIST_SUB+= 	WITHOUT_JAVA="@comment "
.endif

# If X11 is not used, skip gs and etk applications.
pre-build:
.if defined(WITHOUT_X11)
	${ECHO} "WITHOUT_X11 defined" > ${WRKSRC}/lib/gs/SKIP
	${ECHO} "WITHOUT_X11 defined" > ${WRKSRC}/lib/etk/SKIP
.endif

# Check if javac is really in ${JAVABINDIR}.
pre-configure:
.if !defined(WITHOUT_JAVA)
	@if [ ! -x ${JAVABINDIR}/javac ]; then \
		${ECHO_MSG} ">> Error: cannot find javac in JAVABINDIR."; \
		${ECHO_MSG} ">> Please configure JAVABINDIR, or use the WITHOUT_JAVA option"; \
		exit 1; \
	fi
.endif

# Install documentation. (HTML docs need to be in same dir as the
# rest, not in share/doc/erlang as it should, because of relative
# links in the documentation.
post-install:
	@${TAR} --unlink -xzpf ${DISTDIR}/${DIST_SUBDIR}/${ERLANG_MAN} \
		-C ${PREFIX}/lib/erlang
.if !defined(NOPORTDOCS)
	@${TAR} --unlink -xzpf ${DISTDIR}/${DIST_SUBDIR}/${ERLANG_DOCS} \
		-C ${PREFIX}/lib/erlang
	@${RM} -rf ${PREFIX}/lib/erlang/man/cat?

	@for erlang_package in ${UPDATED_PACKAGES}; do \
		epkg_pathname=${PREFIX}/lib/erlang/$${erlang_package}; \
		epkg_dirname=`dirname $${epkg_pathname}`; \
		epkg_basename=`basename $${epkg_pathname}`; \
		doc_release=`ls $${epkg_dirname}/ \
			| ${GREP} -E "^$${epkg_basename}-" | ${SED} -e "2d"`; \
		app_release=`ls $${epkg_dirname}/ \
			| ${GREP} -E "^$${epkg_basename}-" | ${SED} -e "1d"`; \
		if [ -z "$${doc_release}" -o -z "$${app_release}" ]; then \
			${ECHO_MSG} ">> Error: post-install target failed to merge documentation"; \
			exit 1; \
		fi; \
		( \
		${ECHO_MSG} ">> Documentation merge: $${doc_release} -> $${app_release}"; \
		${PERL} -pi -e "s/$${doc_release}/$${app_release}/g;" \
			${PREFIX}/lib/erlang/doc/index.html; \
		${CP} -R $${epkg_dirname}/$${app_release}/* \
			$${epkg_dirname}/$${doc_release}/; \
		${RM} -rf $${epkg_dirname}/$${app_release}; \
		${MV} $${epkg_dirname}/$${doc_release} \
			$${epkg_dirname}/$${app_release} \
		); \
	done
.endif
	sslapp=`ls -d ${PREFIX}/lib/erlang/lib/ssl-* | tail -1`; \
	cd $$sslapp/priv/obj && ${MAKE} && strip ../bin/ssl_esock
	@${CP} ${PLIST} ${TMPPLIST}
	@find ${PREFIX}/lib/erlang -type f | ${SED} -e "s@${PREFIX}/@@" | sort >> ${TMPPLIST}
	@find ${PREFIX}/lib/erlang -type l | ${SED} -e "s@${PREFIX}/@@" | sort >> ${TMPPLIST}
	@find ${PREFIX}/lib/erlang -type d | ${SED} -e "s@${PREFIX}/@@" | ${PERL} -e 'print (join ("\n", reverse map ("\@dirrm " . substr ($$_, 0, -1), <STDIN>)) . "\n");' >> ${TMPPLIST}

# The man-pages are put (in spite of FreeBSD's port convention) in a
# private subdir. This is to avoid cluttering up the man page name
# space. Also the Erlang man pages are more of internal documentation
# using the man format than actual system man pages. (The erl.1 and
# epmd.1 perhaps being the exception).

NOMANCOMPRESS=	yes

MAN1PREFIX=	${PREFIX}/lib/erlang
MAN1=		epmd.1 erl.1 erl_call.1 erlc.1 erlsrv.1 start_erl.1 \
		werl.1 run_erl.1 start.1

MAN3PREFIX=	${PREFIX}/lib/erlang
MAN3=		CORBA_Environment_alloc.3 CosEventChannelAdmin.3 \
		CosEventChannelAdmin_ConsumerAdmin.3 \
		CosEventChannelAdmin_EventChannel.3 \
		CosEventChannelAdmin_ProxyPullConsumer.3 \
		CosEventChannelAdmin_ProxyPullSupplier.3 \
		CosEventChannelAdmin_ProxyPushConsumer.3 \
		CosEventChannelAdmin_ProxyPushSupplier.3 \
		CosEventChannelAdmin_SupplierAdmin.3 CosNaming.3 \
		CosNaming_BindingIterator.3 CosNaming_NamingContext.3 \
		CosTransactions_Control.3 CosTransactions_Coordinator.3 \
		CosTransactions_RecoveryCoordinator.3 \
		CosTransactions_Resource.3 \
		CosTransactions_SubtransactionAwareResource.3 \
		CosTransactions_Terminator.3 \
		CosNaming_NamingContextExt.3 \
		cosTime.3 CosTime_TIO.3 CosTime_TimeService.3 CosTime_UTO.3 \
		CosTimerEvent_TimerEventHandler.3 \
		CosTimerEvent_TimerEventService.3 \
		cosNotificationApp.3 \
		CosNotifyChannelAdmin_EventChannelFactory.3 \
		CosNotifyChannelAdmin_EventChannel.3 \
		CosNotification_QoSAdmin.3 \
		CosNotification_AdminPropertiesAdmin.3 \
		CosNotifyChannelAdmin_ConsumerAdmin.3 \
		CosNotifyChannelAdmin_SupplierAdmin.3 \
		CosNotifyComm_NotifyPublish.3 \
		CosNotifyComm_NotifySubscribe.3 \
		CosNotifyFilter_FilterAdmin.3 \
		CosNotifyFilter_FilterFactory.3 \
		CosNotifyFilter_Filter.3 \
		CosNotifyFilter_MappingFilter.3 \
		CosNotifyChannelAdmin_ProxyConsumer.3 \
		CosNotifyChannelAdmin_ProxySupplier.3 \
		CosNotifyChannelAdmin_ProxyPullConsumer.3 \
		CosNotifyChannelAdmin_ProxyPullSupplier.3 \
		CosNotifyChannelAdmin_ProxyPushConsumer.3 \
		CosNotifyChannelAdmin_ProxyPushSupplier.3 \
		CosNotifyChannelAdmin_SequenceProxyPullConsumer.3 \
		CosNotifyChannelAdmin_SequenceProxyPullSupplier.3 \
		CosNotifyChannelAdmin_SequenceProxyPushConsumer.3 \
		CosNotifyChannelAdmin_SequenceProxyPushSupplier.3 \
		CosNotifyChannelAdmin_StructuredProxyPullConsumer.3 \
		CosNotifyChannelAdmin_StructuredProxyPullSupplier.3 \
		CosNotifyChannelAdmin_StructuredProxyPushConsumer.3 \
		CosNotifyChannelAdmin_StructuredProxyPushSupplier.3 \
		CosTransactions_TransactionFactory.3 Module_Interface.3 \
		OrberEventChannel.3 OrberEventChannel_EventChannelFactory.3 \
		beam_lib.3 digraph_utils.3 orddict.3 sets.3 win32reg.3 \
		comet.3 erl_com.3 \
		alarm_handler.3 any.3 application.3 appmon.3 asn1ct.3 \
		asn1rt.3 auth.3 c.3 calendar.3 coast.3 code.3 compile.3 \
		corba.3 corba_object.3 cosTransactions.3 cpu_sup.3 crypto.3 \
		dbg.3 dets.3 dict.3 digraph.3 disk_log.3 disksup.3 epp.3 \
		eprof.3 erl_boot_server.3 erl_connect.3 erl_ddll.3 \
		erl_error.3 erl_eterm.3 erl_eval.3 erl_format.3 erl_global.3 \
		erl_id_trans.3 erl_internal.3 erl_lint.3 erl_malloc.3 \
		erl_marshal.3 erl_parse.3 erl_pp.3 erl_prim_loader.3 \
		erl_scan.3 erl_set_memory_block.3 erlang.3 error_handler.3 \
		error_logger.3 etk.3 ets.3 eva.3 eva_log.3 eva_log_snmp.3 \
		eva_server.3 eva_snmp_adaptation.3 eva_sup.3 exref.3 \
		file.3 filename.3 ftp.3 gen_event.3 gen_fsm.3 gen_server.3 \
		gen_tcp.3 gen_udp.3 global.3 global_group.3 gs.3 heart.3 \
		httpd.3 httpd_conf.3 httpd_core.3 httpd_socket.3 httpd_util.3 \
		i.3 ic.3 inet.3 init.3 instrument.3 int.3 io.3 io_lib.3 lib.3 \
		lists.3 lname.3 lname_component.3 log.3 log_mf_h.3 \
		log_server.3 log_snmp.3 log_snmpea.3 make.3 math.3 memsup.3 \
		mesh.3 mesh_lib.3 mesh_snmp.3 mnemosyne.3 mnesia.3 \
		mnesia_registry.3 mnesia_session.3 mod_actions.3 mod_alias.3 \
		mod_auth.3 mod_cgi.3 mod_dir.3 mod_disk_log.3 mod_esi.3 \
		mod_include.3 mod_log.3 mod_security.3 net_adm.3 net_kernel.3 \
		nteventlog.3 odbc.3 orber.3 orber_ifr.3 orber_tc.3 ordsets.3 \
		os.3 os_mon.3 os_sup.3 overload.3 pg.3 pg2.3 pman.3 pool.3 \
		proc_lib.3 queue.3 random.3 rb.3 regexp.3 registry.3 \
		release_handler.3 rpc.3 seq_trace.3 shell.3 shell_default.3 \
		slave.3 snmp.3 snmp_community_mib.3 snmp_error.3 \
		snmp_framework_mib.3 snmp_generic.3 snmp_index.3 \
		snmp_local_db.3 snmp_mgr.3 snmp_mpd.3 snmp_notification_mib.3 \
		snmp_pdus.3 snmp_standard_mib.3 snmp_supervisor.3 \
		snmp_target_mib.3 snmp_user_based_sm_mib.3 \
		snmp_view_based_acm_mib.3 ssl.3 ssl_socket.3 string.3 \
		supervisor.3 supervisor_bridge.3 sys.3 systools.3 tags.3 \
		timer.3 tk.3 toolbar.3 tv.3 unix.3 user.3 wrap_log_reader.3 \
		xref.3 yecc.3

MAN4PREFIX=	${PREFIX}/lib/erlang
MAN4=		app.4 appup.4 config.4 rel.4 relup.4 script.4

MAN6PREFIX=	${PREFIX}/lib/erlang
MAN6=		crypto.6 eva.6 inets.6 kernel.6 mesh.6 runtime_tools.6 \
		sasl.6 snmp.6 ssl.6

.include <bsd.port.mk>
