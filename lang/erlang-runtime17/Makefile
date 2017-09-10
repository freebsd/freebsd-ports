# Created by: ruslan@shevchenko.kiev.ua
# $FreeBSD$

PORTNAME=	erlang
PORTVERSION=	17.5.6.9
PORTREVISION=	6
CATEGORIES=	lang parallel java
MASTER_SITES=	http://www.erlang.org/download/:erlangorg		\
		http://erlang.stacken.kth.se/download/:erlangorg	\
		http://www.csd.uu.se/ftp/mirror/erlang/download/:erlangorg
PKGNAMESUFFIX=	-runtime17
DISTNAME=	otp_src_${ERL_RELEASE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:erlangorg	\
		${ERLANG_MAN}:erlangorg
DIST_SUBDIR=	erlang
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	http://olgeni.olgeni.com/~olgeni/distfiles/ \
		LOCAL/olgeni
PATCHFILES=	patch-otp-17.5.1 patch-otp-17.5.2 patch-otp-17.5.3 \
		patch-otp-17.5.4 patch-otp-17.5.5 patch-otp-17.5.6 \
		patch-otp-17.5.6.1 patch-otp-17.5.6.2 patch-otp-17.5.6.3 \
		patch-otp-17.5.6.4 patch-otp-17.5.6.5 patch-otp-17.5.6.6 \
		patch-otp-17.5.6.7 patch-otp-17.5.6.8 patch-otp-17.5.6.9

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Functional programming language from Ericsson

WRKSRC=		${WRKDIR}/otp_src_${ERL_RELEASE}

ERLANG_LIB=	${PORTNAME}${PORTVERSION:C/\..*//}

SUB_FILES=	pkg-message
SUB_LIST=	ERLANG_LIB=${ERLANG_LIB}

MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	DOCS DTRACE GCC GS HIPE JAVA KQUEUE ODBC OPENSSL SCTP SMP THREADS WX DIRTY

DIRTY_DESC=	Enable Dirty schedulers (experimental)
DTRACE_DESC=	Enable DTrace support
GS_DESC=	Enable GS application (deprecated)
HIPE_DESC=	Build native HiPE compiler
KQUEUE_DESC=	Enable Kernel Poll (kqueue) support
SCTP_DESC=	Enable SCTP support
SMP_DESC=	Enable SMP support
WX_DESC=	Enable WX application

OPTIONS_DEFAULT=KQUEUE OPENSSL SCTP SMP THREADS
OPTIONS_EXCLUDE_DragonFly=	HIPE SCTP

ERL_RELEASE=	17.5

USES=		gmake ncurses perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	${ERLANG_DOCS}:erlangorg
.endif

# See http://wiki.freebsd.org/DTrace to learn how to enable DTrace
# on your system. You will need to configure STRIP, WITH_CTF and
# CFLAGS in your make.conf before building.

# If you run Erlang and get a message resembling "WARNING: number of
# probes fixed does not match the number of defined probes (54 != 132,
# respectively)" you probably misconfigured DTrace in some way.

.if ${PORT_OPTIONS:MGCC}
USE_GCC?=	yes
.endif

.if ${PORT_OPTIONS:MDTRACE}
CONFIGURE_ARGS+=--with-dynamic-trace=dtrace
.else
CONFIGURE_ARGS+=--without-dynamic-trace
.endif

.if ${PORT_OPTIONS:MOPENSSL}
USES+=		ssl
CONFIGURE_ARGS+=--with-ssl=${OPENSSLBASE}
.else
CONFIGURE_ARGS+=--without-ssl
.endif

.if ${PORT_OPTIONS:MJAVA}
USE_JAVA=	yes
CONFIGURE_ARGS+=--with-javac
CONFIGURE_ENV+=	ac_cv_prog_JAVAC="${JAVAC}"
.else
CONFIGURE_ARGS+=--without-javac
.endif

.if ${PORT_OPTIONS:MHIPE}
CONFIGURE_ARGS+=--enable-hipe
.else
CONFIGURE_ARGS+=--disable-hipe
.endif

.if ${PORT_OPTIONS:MKQUEUE}
CONFIGURE_ARGS+=--enable-kernel-poll
.else
CONFIGURE_ARGS+=--disable-kernel-poll
.endif

.if ${PORT_OPTIONS:MGS}
USES+=		tk:run
.endif

.if ${PORT_OPTIONS:MWX}
USE_WX=		2.8+
WX_COMPS=	wx contrib
CONFIGURE_ARGS+=--with-wx-config=${WX_CONFIG}
.endif

.if ${PORT_OPTIONS:MODBC}
CONFIGURE_ARGS+=--with-odbc
LIB_DEPENDS+=	libodbc.so:databases/unixODBC
.else
CONFIGURE_ARGS+=--without-odbc
.endif

ERLANG_MAN=	otp_doc_man_${ERL_RELEASE}.tar.gz
ERLANG_DOCS=	otp_doc_html_${ERL_RELEASE}.tar.gz

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=--enable-threads
.else
CONFIGURE_ARGS+=--disable-threads
.endif

.if ${PORT_OPTIONS:MSCTP}
CONFIGURE_ARGS+=--enable-sctp
.else
CONFIGURE_ARGS+=--disable-sctp
.endif

# enabling --enable-smp-support crashes the OS when
# net_kernel:start([node_name, shortnames]) invoked repeatedly
# TODO verify if it still applies

.if ${PORT_OPTIONS:MSMP}
CONFIGURE_ARGS+=--enable-smp-support
.else
CONFIGURE_ARGS+=--disable-smp-support
.endif

.if ${PORT_OPTIONS:MDIRTY}
CONFIGURE_ARGS+=--enable-dirty-schedulers
.endif

.if ${ARCH} == i386
MAKE_ARGS+=	ARCH=x86
.endif

.if ${ARCH} == armv6
MAKE_ARGS+=	ARCH=arm
.endif

# The man-pages are put (in spite of FreeBSD's port convention) in a private
# subdir. This is to avoid cluttering up the man page name space. Also the
# Erlang man pages are more of internal documentation using the man format than
# actual system man pages. (erl.1 and epmd.1 perhaps being the exception).

# Install documentation. (HTML docs need to be in same dir as the
# rest, not in share/doc/erlang as it should, because of relative
# links in the documentation.

pre-configure:
.if ${PORT_OPTIONS:MDTRACE}
	@if ! /sbin/kldstat | ${GREP} dtraceall >/dev/null 2>&1; then \
		${ECHO_CMD}; \
		${ECHO_CMD} "DTRACE option requires kernel module \"dtraceall\" to be loaded."; \
		${ECHO_CMD}; \
		exit 1; \
	fi
.endif
.if ! ${PORT_OPTIONS:MWX}
	echo "disabled by port options" > ${WRKSRC}/lib/wx/SKIP
.endif

post-configure:
.if ${PORT_OPTIONS:MODBC}
	${RM} ${WRKSRC}/lib/odbc/SKIP
.endif

post-install:
	for SECTION in 1 3 4 6 7; do \
		${TAR} --unlink -xzpf ${DISTDIR}/${DIST_SUBDIR}/${ERLANG_MAN} \
			-C ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB} \
			"man/man$${SECTION}/*.$${SECTION}" || ${TRUE}; \
	done
	${RM} -r ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/man/cat?
.if ${PORT_OPTIONS:MDOCS}
	${TAR} --unlink -xzpf ${DISTDIR}/${DIST_SUBDIR}/${ERLANG_DOCS} \
		-C ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}

	${MV} ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/erts-6.4/* \
		${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/erts-6.4.1.6
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/erts-6.4

	${MV} ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/inets-5.10.6/* \
		${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/inets-5.10.9
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/inets-5.10.6

	${MV} ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/ssh-3.2/* \
		${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/ssh-3.2.4
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/ssh-3.2

	${MV} ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/common_test-1.10/* \
		${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/common_test-1.10.1
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/common_test-1.10

	${MV} ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/diameter-1.9/* \
		${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/diameter-1.9.2.4
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/diameter-1.9

	${MV} ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/debugger-4.0.3/* \
		${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/debugger-4.0.3.1
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/debugger-4.0.3

	${MV} ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/snmp-5.1.1/* \
		${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/snmp-5.1.2
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/snmp-5.1.1

	${MV} ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/test_server-3.8/* \
		${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/test_server-3.8.1
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/test_server-3.8

	${MV} ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/ssl-6.0/* \
		${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/ssl-6.0.1.2
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/ssl-6.0

	${MV} ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/runtime_tools-1.8.16/* \
		${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/runtime_tools-1.8.16.1
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/runtime_tools-1.8.16

	${MV} ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/kernel-3.2/* \
		${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/kernel-3.2.0.1
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/kernel-3.2

	${INSTALL_DATA} ${WRKSRC}/lib/dialyzer/doc/*.txt \
		${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/lib/dialyzer-*/doc/
.endif
.if ! ${PORT_OPTIONS:MGS}
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/gs-*
.endif
.if ! ${PORT_OPTIONS:MJAVA}
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/jinterface-*
.endif
.if ! ${PORT_OPTIONS:MODBC}
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/odbc-*
.endif
.if ! ${PORT_OPTIONS:MOPENSSL}
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/crypto-*
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/ssh-*
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/ssl-*
.endif
.if ! ${PORT_OPTIONS:MWX}
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/wx-*
.endif
	${FIND} ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/* -type d -empty -delete

	@cd ${STAGEDIR}${PREFIX}; ${FIND} lib/${ERLANG_LIB}/* -type f -o -type l \
		| ${SORT} \
		>> ${TMPPLIST}

.include <bsd.port.mk>
