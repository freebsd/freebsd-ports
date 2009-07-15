# New ports collection makefile for:   papi
# Date created:        21 May 2007
# Whom:                redcrash@gmail.com
#
# $FreeBSD$
#

PORTNAME=	papi
PORTVERSION=	3.6.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://icl.cs.utk.edu/projects/papi/downloads/

MAINTAINER=	redcrash@gmail.com
COMMENT=	API to access the performance counter hw in the microprocessor

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	HWPMC kernel module is only available for I386 and \
			AMD64 machines
NO_PACKAGE=	Needs to be compiled for specific CPU

STRIP=
USE_LDCONFIG=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
WRKMAN=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/man

# Although the package may not install the fortran binaries, it requires the
# fortran compiler
USE_FORTRAN=	yes
FFLAGS=		-fdefault-integer-8 -fno-range-check

OPTIONS=	CTESTS "Install C tests" On
OPTIONS+=	FTESTS "Install Fortran tests" On
OPTIONS+=	DEBUG  "Add debug information (increased verbosity)" Off

.include <bsd.port.pre.mk>

HAS_HWMPC!=     ${SYSCTL} kern.hwpmc >/dev/null 2>&1 && echo yes || true

.if ${HAS_HWMPC} != "yes"
IGNORE=		needs hwmpc module loaded or compiled into the kernel. \
		Please consult hwpmc(4) on how to do it (or cat pkg-message)
.endif

.if defined(WITHOUT_CTESTS)
PLIST_SUB+=	CTESTS="@comment "
.else
PLIST_SUB+=	CTESTS=""
.endif

.if defined(WITHOUT_FTESTS)
PLIST_SUB+=	FTESTS="@comment "
.else
PLIST_SUB+=	FTESTS=""
.endif

.if defined(WITHOUT_DEBUG)
CONFIGURE_ARGS+=	--without-debug
.else
CONFIGURE_ARGS+=	--with-debug
.endif

MAN1=	papi_avail.1 \
	papi_clockres.1 \
	papi_command_line.1 \
	papi_cost.1 \
	papi_decode.1 \
	papi_event_chooser.1 \
	papi_mem_info.1 \
	papi_native_avail.1
MAN3=	PAPI.3 \
	PAPIF.3 \
	PAPIF_get_clockrate.3 \
	PAPIF_get_domain.3 \
	PAPIF_get_exe_info.3 \
	PAPIF_get_granularity.3 \
	PAPIF_get_preload.3 \
	PAPIF_set_event_domain.3 \
	PAPI_accum.3 \
	PAPI_accum_counters.3 \
	PAPI_add_event.3 \
	PAPI_add_events.3 \
	PAPI_attach.3 \
	PAPI_cleanup_eventset.3 \
	PAPI_create_eventset.3 \
	PAPI_destroy_eventset.3 \
	PAPI_detach.3 \
	PAPI_encode_events.3 \
	PAPI_enum_event.3 \
	PAPI_event_code_to_name.3 \
	PAPI_event_name_to_code.3 \
	PAPI_flips.3 \
	PAPI_flops.3 \
	PAPI_get_dmem_info.3 \
	PAPI_get_event_info.3 \
	PAPI_get_executable_info.3 \
	PAPI_get_hardware_info.3 \
	PAPI_get_multiplex.3 \
	PAPI_get_opt.3 \
	PAPI_get_overflow_event_index.3 \
	PAPI_get_real_cyc.3 \
	PAPI_get_real_usec.3 \
	PAPI_get_shared_lib_info.3 \
	PAPI_get_substrate_info.3 \
	PAPI_get_thr_specific.3 \
	PAPI_get_virt_cyc.3 \
	PAPI_get_virt_usec.3 \
	PAPI_help.3 \
	PAPI_ipc.3 \
	PAPI_is_initialized.3 \
	PAPI_library_init.3 \
	PAPI_list_events.3 \
	PAPI_list_threads.3 \
	PAPI_lock.3 \
	PAPI_multiplex_init.3 \
	PAPI_native.3 \
	PAPI_num_counters.3 \
	PAPI_num_events.3 \
	PAPI_num_hwctrs.3 \
	PAPI_overflow.3 \
	PAPI_perror.3 \
	PAPI_presets.3 \
	PAPI_profil.3 \
	PAPI_query_event.3 \
	PAPI_read.3 \
	PAPI_read_counters.3 \
	PAPI_register_thread.3 \
	PAPI_remove_event.3 \
	PAPI_remove_events.3 \
	PAPI_reset.3 \
	PAPI_set_debug.3 \
	PAPI_set_domain.3 \
	PAPI_set_event_info.3 \
	PAPI_set_granularity.3 \
	PAPI_set_multiplex.3 \
	PAPI_set_opt.3 \
	PAPI_set_thr_specific.3 \
	PAPI_shutdown.3 \
	PAPI_sprofil.3 \
	PAPI_start.3 \
	PAPI_start_counters.3 \
	PAPI_state.3 \
	PAPI_stop.3 \
	PAPI_stop_counters.3 \
	PAPI_strerror.3 \
	PAPI_thread_id.3 \
	PAPI_thread_init.3 \
	PAPI_unlock.3 \
	PAPI_unregister_thread.3 \
	PAPI_write.3

PAPI_LIBS=	libpapi.a \
	libpapi.so.3

PAPI_BINARIES=	papi_avail \
	papi_clockres \
	papi_command_line \
	papi_cost \
	papi_decode \
	papi_event_chooser \
	papi_mem_info \
	papi_native_avail

PAPI_INCLUDES=	f77papi.h \
	f90papi.h \
	fpapi.h \
	papi.h \
	papiStdEventDefs.h

PAPI_FORTRAN_TESTS=	strtest \
	zero \
	first \
	second \
	tenth \
	description \
	fdmemtest \
	accum \
	highlevel \
	cost \
	johnmay2 \
	avail \
	case1 \
	case2 \
	clockres \
	eventname \
	fmatrixlowpapi \
	fmatrixpapi \
	flops \
	fmatrixpapi2 \
	fmultiplex1 \
	fmultiplex2

PAPI_C_TESTS=	ipc \
	hwinfo \
	code2name \
	reset \
	subinfo \
	realtime \
	first \
	exeinfo \
	zero \
	zero_fork \
	branches \
	dmem_info \
	all_native_events \
	all_events \
	derived \
	high-level2 \
	describe \
	memory \
	zero_flip \
 	low-level \
	high-level \
	eventname \
	case1 \
	case2 \
	calibrate \
	flops \
	second \
	johnmay2 \
	overflow \
	overflow_force_software \
	overflow_single_event \
	overflow_twoevents \
	timer_overflow \
	overflow2 \
	matrix-hl \
	tenth \
	encode \
	encode2 \
	profile \
	sprofile \
	profile_twoevents \
	byte_profile \
	overflow_index \
	overflow_one_and_read \
	multiplex1_pthreads \
	multiplex3_pthreads \
	kufrin \
	multiplex1 \
	multiplex2 \
	mendes-alt \
	sdsc-mpx \
	sdsc2-mpx \
	sdsc4-mpx \
	thrspecific \
	profile_pthreads \
	overflow_pthreads \
	zero_pthreads \
	unregister_pthreads \
	clockres_pthreads \
	overflow3_pthreads \
	locks_pthreads

do-install:
.for f in ${PAPI_BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/utils/${f} ${PREFIX}/bin
.endfor
.for f in ${PAPI_INCLUDES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/include
.endfor
.if defined(WITH_FTESTS)
	${MKDIR} ${DATADIR}/ftests
.for f in ${PAPI_FORTRAN_TESTS}
	${INSTALL_PROGRAM} ${WRKSRC}/ftests/${f} ${DATADIR}/ftests
.endfor
.endif
.if defined(WITH_CTESTS)
	${MKDIR} ${DATADIR}/ctests
.for f in ${PAPI_C_TESTS}
	${INSTALL_PROGRAM} ${WRKSRC}/ctests/${f} ${DATADIR}/ctests
.endfor
.endif
.for f in ${PAPI_LIBS}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/lib
.endfor
.for f in ${MAN1}
	${INSTALL_MAN} ${WRKMAN}/man1/${f} ${PREFIX}/man/man1
.endfor
.for f in ${MAN3}
	${INSTALL_MAN} ${WRKMAN}/man3/${f} ${PREFIX}/man/man3
.endfor

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
