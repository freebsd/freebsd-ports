# Created by: ruslan@shevchenko.kiev.ua
# $FreeBSD$

PORTNAME=	erlang
DISTVERSIONPREFIX=	OTP-
DISTVERSION=	21.3.8.10
PORTEPOCH=	4
CATEGORIES=	lang parallel java
DIST_SUBDIR=	erlang

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Functional programming language from Ericsson

LICENSE=	APACHE20

BROKEN_sparc64=	Fails to build: error: fp_except undeclared

USES=		autoreconf:build gmake ncurses perl5
USE_GITHUB=	nodefault
GH_ACCOUNT=	erlang:otp,corba
GH_PROJECT=	otp:otp corba:corba
GH_TAGNAME=	4.5.2:corba
USE_PERL5=	build
USE_RC_SUBR=	epmd

WRKSRC=		${WRKSRC_otp}

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes

OPTIONS_SUB=	yes
SUB_FILES=	pkg-message
SUB_LIST=	TOOLS_VSN=${TOOLS_VSN}

ERLANG_LIB=	${PORTNAME}
EI_VSN=		3.11.3
SNMP_VSN=	5.2.12
TOOLS_VSN=	3.1.0.1

# On Erlang 22, native code generation does not currently work for all modules
# due to new BEAM instructions not supported by HiPE the native compiler.
# Remove HIPE from OPTIONS_DEFAULT if this is still the case when the port is
# upgraded to such version.

OPTIONS_DEFINE=	CORBA DIRTY DTRACE FOP HIPE JAVA KQUEUE MANPAGES NATIVE ODBC OPENSSL PDF SCTP THREADS WX
OPTIONS_DEFAULT=CORBA DIRTY DTRACE HIPE KQUEUE MANPAGES OPENSSL SCTP THREADS
OPTIONS_EXCLUDE_powerpc64=	HIPE ${OPTIONS_EXCLUDE_${ARCH}_${OSREL:R}}
OPTIONS_EXCLUDE_powerpc64_13=	DTRACE

CORBA_DESC=	Enable Corba support
DIRTY_DESC=	Enable Dirty schedulers
FOP_DESC=	Build full documentation with Apache FOP
HIPE_DESC=	Build native HiPE compiler
KQUEUE_DESC=	Enable Kernel Poll (kqueue) support
NATIVE_DESC=	Enable native libraries
PDF_DESC=	Build PDF documentation
SCTP_DESC=	Enable SCTP support
WX_DESC=	Enable WX application

FOP_PREVENTS=	MANPAGES
NATIVE_IMPLIES=	HIPE
PDF_IMPLIES=	FOP

.if !exists(/usr/sbin/dtrace)
OPTIONS_EXCLUDE+=	DTRACE
.endif

OPTIONS_EXCLUDE_DragonFly=	HIPE NATIVE SCTP
# ld(1) fails to link probes: missing __dtrace_erlang___* symbols
OPTIONS_EXCLUDE_aarch64=	DTRACE
OPTIONS_EXCLUDE_armv6=		DTRACE
OPTIONS_EXCLUDE_armv7=		DTRACE
OPTIONS_EXCLUDE_i386=		DTRACE

# If you run Erlang and get a message resembling "WARNING: number of
# probes fixed does not match the number of defined probes (54 != 132,
# respectively)" you probably misconfigured DTrace in some way.

CONFIGURE_ENABLE=	smp-support

DIRTY_CONFIGURE_ENABLE=	dirty-schedulers
DTRACE_CFLAGS=		-fno-omit-frame-pointer
DTRACE_CONFIGURE_WITH=	dynamic-trace=dtrace
DTRACE_VARS=		STRIP=""
FOP_BUILD_DEPENDS=	fop:textproc/fop \
			xsltproc:textproc/libxslt
HIPE_CONFIGURE_ENABLE=	hipe
JAVA_CONFIGURE_ENV=	ac_cv_prog_JAVAC="${JAVAC}"
JAVA_CONFIGURE_WITH=	javac
JAVA_VARS=		USE_JAVA=yes
KQUEUE_CONFIGURE_ENABLE=kernel-poll
MANPAGES_RUN_DEPENDS=	${LOCALBASE}/etc/man.d/erlang.conf:lang/erlang-man
NATIVE_CONFIGURE_ENABLE=native-libs
ODBC_CONFIGURE_WITH=	odbc
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
OPENSSL_CONFIGURE_WITH=	ssl=${OPENSSLBASE}
OPENSSL_USES=		ssl
SCTP_CONFIGURE_ENABLE=	sctp
THREADS_CONFIGURE_ENABLE=	threads
WX_CONFIGURE_WITH=	wx-config=${WX_CONFIG}
WX_USES=		gl
WX_VARS=		USE_WX=2.8+ WX_COMPS="wx contrib" USE_GL="gl glu"

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-DMAP_NORESERVE=0
.endif

.if ${ARCH} == i386
MAKE_ARGS+=	ARCH=x86
.endif

.if ${ARCH} == armv6 || ${ARCH} == armv7
MAKE_ARGS+=	ARCH=arm
.endif

pre-configure:
	@if [ ! $$(${CAT} ${WRKSRC}/lib/erl_interface/vsn.mk | ${GREP} "EI_VSN *=" | ${CUT} -w -f3) = ${EI_VSN} ]; then \
		${ECHO_MSG} "===>  EI_VSN (${EI_VSN}) in Makefile does not match value in lib/erl_interface/vsn.mk"; exit 1; \
	fi
	@if [ ! $$(${CAT} ${WRKSRC}/lib/tools/vsn.mk | ${GREP} "TOOLS_VSN *=" | ${CUT} -w -f3) = ${TOOLS_VSN} ]; then \
		${ECHO_MSG} "===>  TOOLS_VSN (${TOOLS_VSN}) in Makefile does not match value in lib/tools/vsn.mk"; exit 1; \
	fi
	@if [ ! $$(${CAT} ${WRKSRC}/lib/snmp/vsn.mk | ${GREP} -E "SNMP_VSN *=" | ${CUT} -w -f3) = ${SNMP_VSN} ]; then \
		${ECHO_MSG} "===>  SNMP_VSN (${SNMP_VSN}) in Makefile does not match value in lib/snmp/vsn.mk"; exit 1; \
	fi
	@cd ${WRKSRC} && ./otp_build autoconf

pre-configure-WX-off:
	echo "disabled by port options" > ${WRKSRC}/lib/debugger/SKIP
	echo "disabled by port options" > ${WRKSRC}/lib/et/SKIP
	echo "disabled by port options" > ${WRKSRC}/lib/observer/SKIP
	echo "disabled by port options" > ${WRKSRC}/lib/wx/SKIP

post-configure-ODBC-on:
	${RM} ${WRKSRC}/lib/odbc/SKIP

pre-build-NATIVE-on:
	@cd ${WRKSRC} && ${MAKE_CMD} clean

post-build-CORBA-on:
	cd ${WRKSRC_corba} \
		&& ${SETENV} OVERRIDE_TARGET=${CONFIGURE_TARGET} ERL_TOP=${WRKSRC_otp} ${MAKE_CMD}

post-install-CORBA-on:
	cd ${WRKSRC_corba} \
		&& ${SETENV} OVERRIDE_TARGET=${CONFIGURE_TARGET} ERL_TOP=${WRKSRC_otp} \
			${MAKE_CMD} release RELEASE_ROOT=${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}

# The man-pages are put (in spite of FreeBSD's port convention) in a private
# subdir. This is to avoid cluttering up the man page name space. Also the
# Erlang man pages are more of internal documentation using the man format than
# actual system man pages. (erl.1 and epmd.1 perhaps being the exception).

post-build-FOP-on:
	@cd ${WRKSRC} && ${MAKE_CMD} docs
.if ${PORT_OPTIONS:MCORBA}
	cd ${WRKSRC_corba} \
		&& ${SETENV} OVERRIDE_TARGET=${CONFIGURE_TARGET} ERL_TOP=${WRKSRC_otp} ${MAKE_CMD} docs
.endif

post-install:
	${LN} -sf ../lib/${ERLANG_LIB}/lib/erl_interface-${EI_VSN}/bin/erl_call ${STAGEDIR}${PREFIX}/bin/erl_call
	${LN} -sf ../lib/${ERLANG_LIB}/lib/snmp-${SNMP_VSN}/bin/snmpc ${STAGEDIR}${PREFIX}/bin/snmpc

post-install-FOP-on:
	@${ECHO_CMD} "MANPATH ${PREFIX}/lib/erlang/man" > ${WRKDIR}/erlang.conf
	${INSTALL_DATA} ${WRKDIR}/erlang.conf ${STAGEDIR}${PREFIX}/etc/man.d/erlang.conf
	for SECTION in 1 3 4 6 7; do \
		${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/man/man$${SECTION}; \
	  	${FIND} ${WRKSRC}/erts ${WRKSRC}/lib -type f | ${GREP} doc/man$${SECTION} \
			| ${XARGS} -J % ${CP} -v % ${STAGEDIR}${PREFIX}/lib/erlang/man/man$${SECTION}; \
	done
.if ${PORT_OPTIONS:MCORBA}
	${FIND} ${WRKSRC_corba}/lib -type f | ${GREP} doc/man3 \
		| ${XARGS} -J % ${CP} -v % ${STAGEDIR}${PREFIX}/lib/erlang/man/man3
.endif

post-install-PDF-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${FIND} ${WRKSRC} -name \*.pdf | ${XARGS} -J % ${CP} -v % ${STAGEDIR}${DOCSDIR}
.if ${PORT_OPTIONS:MCORBA}
	${FIND} ${WRKSRC_corba} -name \*.pdf | ${XARGS} -J % ${CP} -v % ${STAGEDIR}${DOCSDIR}
.endif

post-install-JAVA-off:
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/jinterface-*

post-install-ODBC-off:
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/odbc-*

post-install-OPENSSL-off:
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/crypto-*
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/ssh-*
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/ssl-*

post-install-WX-off:
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/debugger-*
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/et-*
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/observer-*
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/wx-*

post-install-DTRACE-on:
	${MKDIR} ${STAGEDIR}${DATADIR}/dtrace
	${INSTALL_DATA} ${WRKSRC}/erts/emulator/beam/*.d \
		${WRKSRC}/lib/runtime_tools/c_src/*.d \
		${WRKSRC}/lib/runtime_tools/examples/*.d \
		${STAGEDIR}${DATADIR}/dtrace

post-stage:
	${FIND} ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/* -type d -empty -delete
	@cd ${STAGEDIR}${PREFIX}; ${FIND} lib/${ERLANG_LIB}/* ${DATADIR_REL}/* -type f -o -type l \
		| ${SORT} >> ${TMPPLIST}
	if [ -d ${STAGEDIR}/${DOCSDIR} ]; then \
		@cd ${STAGEDIR}${PREFIX}; ${FIND} ${DOCSDIR_REL}/* -name \*.pdf \
			| ${SORT} >> ${TMPPLIST}; \
	fi

.include <bsd.port.post.mk>
