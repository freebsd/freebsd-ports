PORTNAME=	erlang
DISTVERSIONPREFIX=	OTP-
DISTVERSION=	26.2.5.15
PORTEPOCH=	4
CATEGORIES=	lang parallel java
DIST_SUBDIR=	erlang

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Functional programming language from Ericsson
WWW=		https://www.erlang.org/

LICENSE=	APACHE20

USES=		compiler cpe gmake ncurses perl5
CPE_VENDOR=	erlang
CPE_PRODUCT=	erlang/otp
USE_GITHUB=	nodefault

GH_ACCOUNT=	erlang:otp,corba
GH_PROJECT=	otp:otp corba:corba
GH_TAGNAME=	5.2.1:corba
USE_PERL5=	build
USE_RC_SUBR=	epmd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-dirty-schedulers \
		--enable-kernel-poll \
		--enable-smp-support \
		--enable-threads
MAKE_ARGS=	all
MAKE_ENV+=	ERL_LIBS=${WRKSRC}/lib

_ERLANG_LIB=	${PORTNAME}

SUB_FILES=	pkg-message
SUB_LIST=	_TOOLS_VSN=${_TOOLS_VSN}

WRKSRC=		${WRKSRC_otp}

USERS=		beam
GROUPS=		beam

_EI_VSN=	5.5.1
_SNMP_VSN=	5.15
_TOOLS_VSN=	3.6

OPTIONS_DEFINE=		CHUNKS CORBA DTRACE FOP JAVA KQUEUE MANPAGES ODBC \
			OPENSSL PDF SCTP SHARING WX
OPTIONS_DEFAULT=	CHUNKS CORBA DTRACE KQUEUE MANPAGES OPENSSL SCTP \
			SHARING

.if !exists(/usr/sbin/dtrace)
OPTIONS_EXCLUDE+=	DTRACE
.endif

OPTIONS_EXCLUDE_DragonFly=	SCTP
# ld(1) fails to link probes: missing __dtrace_erlang___* symbols
# see also https://reviews.freebsd.org/D22360
OPTIONS_EXCLUDE_aarch64=	DTRACE
OPTIONS_EXCLUDE_armv6=	DTRACE
OPTIONS_EXCLUDE_armv7=	DTRACE
OPTIONS_EXCLUDE_i386=	DTRACE
OPTIONS_EXCLUDE_riscv64=	DTRACE
OPTIONS_SUB=	yes

CHUNKS_DESC=	Enable in-line documentation in Erlang console
CORBA_DESC=	Enable Corba support
FOP_DESC=	Build full documentation with Apache FOP
KQUEUE_DESC=	Enable Kernel Poll (kqueue) support
PDF_DESC=	Build PDF documentation
SCTP_DESC=	Enable SCTP support
SHARING_DESC=	Enable term copy-and-share support
WX_DESC=	Enable WX application

# If you run Erlang and get a message resembling "WARNING: number of
# probes fixed does not match the number of defined probes (54 != 132,
# respectively)" you probably misconfigured DTrace in some way.

CHUNKS_MAKE_ARGS+=		DOC_TARGETS=chunks \
				docs
DTRACE_CONFIGURE_WITH=		dynamic-trace=dtrace
DTRACE_CFLAGS=			-fno-omit-frame-pointer
DTRACE_VARS=			STRIP=""
FOP_PREVENTS=			MANPAGES
FOP_BUILD_DEPENDS=		fop:textproc/fop \
				xsltproc:textproc/libxslt
JAVA_USES=			java
JAVA_CONFIGURE_WITH=		javac
JAVA_CONFIGURE_ENV=		ac_cv_prog_JAVAC="${JAVAC}"
KQUEUE_CONFIGURE_ENABLE=	kernel-poll
MANPAGES_RUN_DEPENDS=		${LOCALBASE}/etc/man.d/erlang.conf:lang/erlang-man
ODBC_LIB_DEPENDS=		libodbc.so:databases/unixODBC
ODBC_USES=			localbase:ldflags
ODBC_CONFIGURE_WITH=		odbc
OPENSSL_USES=			ssl
OPENSSL_CONFIGURE_WITH=		ssl=${OPENSSLBASE}
PDF_IMPLIES=			FOP
SCTP_CONFIGURE_ENABLE=		sctp
SHARING_CONFIGURE_ENABLE=	sharing-preserving
WX_USES=			gl
WX_CONFIGURE_WITH=		wx-config=${WX_CONFIG}
WX_VARS=			USE_GL="gl glu" \
				USE_WX=3.2+ \
				WX_COMPS="wx"

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
# PR 258494
CONFIGURE_ARGS+=	--disable-pgo
.endif

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
	@if [ ! $$(${CAT} ${WRKSRC}/lib/erl_interface/vsn.mk | ${GREP} "_EI_VSN *=" | ${CUT} -w -f3) = ${_EI_VSN} ]; then \
		${ECHO_MSG} "===>  _EI_VSN (${_EI_VSN}) in Makefile does not match value in lib/erl_interface/vsn.mk"; exit 1; \
	fi
	@if [ ! $$(${CAT} ${WRKSRC}/lib/tools/vsn.mk | ${GREP} "_TOOLS_VSN *=" | ${CUT} -w -f3) = ${_TOOLS_VSN} ]; then \
		${ECHO_MSG} "===>  _TOOLS_VSN (${_TOOLS_VSN}) in Makefile does not match value in lib/tools/vsn.mk"; exit 1; \
	fi
	@if [ ! $$(${CAT} ${WRKSRC}/lib/snmp/vsn.mk | ${GREP} -E "_SNMP_VSN *=" | ${CUT} -w -f3) = ${_SNMP_VSN} ]; then \
		${ECHO_MSG} "===>  _SNMP_VSN (${_SNMP_VSN}) in Makefile does not match value in lib/snmp/vsn.mk"; exit 1; \
	fi

pre-configure-WX-off:
	echo "disabled by port options" > ${WRKSRC}/lib/debugger/SKIP
	echo "disabled by port options" > ${WRKSRC}/lib/et/SKIP
	echo "disabled by port options" > ${WRKSRC}/lib/observer/SKIP
	echo "disabled by port options" > ${WRKSRC}/lib/wx/SKIP

post-configure-ODBC-on:
	${RM} ${WRKSRC}/lib/odbc/SKIP

post-configure-ODBC-off:
	echo "disabled by port options" > ${WRKSRC}/lib/odbc/SKIP

post-build-CORBA-on:
	cd ${WRKSRC_corba} && \
		${SETENV} OVERRIDE_TARGET=${CONFIGURE_TARGET} ERL_TOP=${WRKSRC_otp} \
		${MAKE_CMD}

# The man-pages are put (in spite of FreeBSD's port convention) in a private
# subdir. This is to avoid cluttering up the man page name space. Also the
# Erlang man pages are more of internal documentation using the man format than
# actual system man pages. (erl.1 and epmd.1 perhaps being the exception).

post-build-FOP-on:
	@cd ${WRKSRC} && \
		${MAKE_CMD} docs
.if ${PORT_OPTIONS:MCORBA}
	cd ${WRKSRC_corba} && \
		${SETENV} OVERRIDE_TARGET=${CONFIGURE_TARGET} ERL_TOP=${WRKSRC_otp} \
		${MAKE_CMD} docs
.endif

post-install:
	${LN} -sf ../lib/${_ERLANG_LIB}/lib/erl_interface-${_EI_VSN}/bin/erl_call \
		${STAGEDIR}${PREFIX}/bin/erl_call
	${LN} -sf ../lib/${_ERLANG_LIB}/lib/snmp-${_SNMP_VSN}/bin/snmpc \
		${STAGEDIR}${PREFIX}/bin/snmpc

post-install-CORBA-on:
	cd ${WRKSRC_corba} && \
		${SETENV} OVERRIDE_TARGET=${CONFIGURE_TARGET} ERL_TOP=${WRKSRC_otp} \
		${MAKE_CMD} release RELEASE_ROOT=${STAGEDIR}${PREFIX}/lib/${_ERLANG_LIB}

post-install-CHUNKS-on:
	cd ${WRKSRC_otp} && \
		${SETENV} ERL_TOP=${WRKSRC_otp} \
		${MAKE_CMD} release_docs DOC_TARGETS=chunks \
		RELEASE_ROOT=${STAGEDIR}${PREFIX}/lib/${_ERLANG_LIB}

post-install-DTRACE-on:
	${MKDIR} ${STAGEDIR}${DATADIR}/dtrace
	${INSTALL_DATA} ${WRKSRC}/erts/emulator/beam/*.d \
		${WRKSRC}/lib/runtime_tools/c_src/*.d \
		${WRKSRC}/lib/runtime_tools/examples/*.d \
		${STAGEDIR}${DATADIR}/dtrace

post-install-FOP-on:
	@${ECHO_CMD} "MANPATH ${PREFIX}/lib/erlang/man" > ${WRKDIR}/erlang.conf
	${INSTALL_DATA} ${WRKDIR}/erlang.conf \
		${STAGEDIR}${PREFIX}/etc/man.d/erlang.conf
	for SECTION in 1 3 4 6 7; \
		do ${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/man/man$${SECTION}; \
		${FIND} ${WRKSRC}/erts ${WRKSRC}/lib -type f | \
		${GREP} doc/man$${SECTION} | \
		${XARGS} -J % ${CP} -v % ${STAGEDIR}${PREFIX}/lib/erlang/man/man$${SECTION}; \
		done
.if ${PORT_OPTIONS:MCORBA}
	${FIND} ${WRKSRC_corba}/lib -type f | \
		${GREP} doc/man3 | \
		${XARGS} -J % ${CP} -v % ${STAGEDIR}${PREFIX}/lib/erlang/man/man3
.endif

post-install-JAVA-off:
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/jinterface-*

post-install-ODBC-off:
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/odbc-*

post-install-OPENSSL-off:
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/crypto-*
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/ssh-*
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/ssl-*

post-install-PDF-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${FIND} ${WRKSRC} -name \*.pdf | \
		${XARGS} -J % ${CP} -v % ${STAGEDIR}${DOCSDIR}
.if ${PORT_OPTIONS:MCORBA}
	${FIND} ${WRKSRC_corba} -name \*.pdf | \
		${XARGS} -J % ${CP} -v % ${STAGEDIR}${DOCSDIR}
.endif

post-install-WX-off:
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/debugger-*
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/et-*
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/observer-*
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/wx-*

post-stage:
	${FIND} ${STAGEDIR}${PREFIX}/lib/${_ERLANG_LIB}/* -type d -empty \
		-delete
	@cd ${STAGEDIR}${PREFIX}; \
		${FIND} lib/${_ERLANG_LIB}/* ${DATADIR_REL}/* -type f -o \
		-type l | \
		${SORT} >> ${TMPPLIST}
	@if [ -d ${STAGEDIR}/${DOCSDIR} ]; then \
		cd ${STAGEDIR}${PREFIX}; \
		${FIND} ${DOCSDIR_REL}/* -name \*.pdf | \
		${SORT} >> ${TMPPLIST}; \
		fi

.include <bsd.port.post.mk>
