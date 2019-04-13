# Created by: ruslan@shevchenko.kiev.ua
# $FreeBSD$

PORTNAME=	erlang
DISTVERSIONPREFIX=	OTP-
DISTVERSION=	19.3.6.13
PORTREVISION=	1
PORTEPOCH=	4
CATEGORIES=	lang parallel java
DIST_SUBDIR=	erlang

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Functional programming language from Ericsson

LICENSE=	APACHE20

BROKEN_sparc64=	Fails to build: error: fp_except undeclared

USES=		autoreconf:build gmake ncurses perl5
USE_GITHUB=	yes
GH_PROJECT=	otp
USE_PERL5=	build
USE_RC_SUBR=	epmd

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes

OPTIONS_SUB=	yes
SUB_FILES=	pkg-message
SUB_LIST=	TOOLS_VSN=${TOOLS_VSN}

ERLANG_LIB=	${PORTNAME}
EI_VSN=		3.9.3
SNMP_VSN=	5.2.5
TOOLS_VSN=	2.9.1

# On Erlang 22, native code generation does not currently work for all modules
# due to new BEAM instructions not supported by HiPE the native compiler.
# Remove HIPE from OPTIONS_DEFAULT if this is still the case when the port is
# upgraded to such version.

OPTIONS_DEFINE=	DIRTY DTRACE FOP GS HIPE JAVA KQUEUE MANPAGES NATIVE ODBC OPENSSL PDF SCTP SMP THREADS WX
OPTIONS_DEFAULT=DTRACE HIPE KQUEUE MANPAGES OPENSSL SCTP SMP THREADS

DIRTY_DESC=	Enable Dirty schedulers (experimental)
FOP_DESC=	Build full documentation with Apache FOP
GS_DESC=	Enable GS application (deprecated)
HIPE_DESC=	Build native HiPE compiler
KQUEUE_DESC=	Enable Kernel Poll (kqueue) support
NATIVE_DESC=	Enable native libraries
PDF_DESC=	Build PDF documentation
SCTP_DESC=	Enable SCTP support
SMP_DESC=	Enable SMP support
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

DIRTY_CONFIGURE_ENABLE=	dirty-schedulers
DTRACE_CFLAGS=		-fno-omit-frame-pointer
DTRACE_CONFIGURE_WITH=	dynamic-trace=dtrace
DTRACE_VARS=		STRIP=""
FOP_BUILD_DEPENDS=	fop:textproc/fop \
			xsltproc:textproc/libxslt
GS_USES=		tk:run
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
SMP_CONFIGURE_ENABLE=	smp-support
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

# The man-pages are put (in spite of FreeBSD's port convention) in a private
# subdir. This is to avoid cluttering up the man page name space. Also the
# Erlang man pages are more of internal documentation using the man format than
# actual system man pages. (erl.1 and epmd.1 perhaps being the exception).

post-build-FOP-on:
	@cd ${WRKSRC} && ${MAKE_CMD} docs

post-install:
	${LN} -sf ../lib/${ERLANG_LIB}/lib/erl_interface-${EI_VSN}/bin/erl_call ${STAGEDIR}${PREFIX}/bin/erl_call
	${LN} -sf ../lib/${ERLANG_LIB}/lib/snmp-${SNMP_VSN}/bin/snmpc ${STAGEDIR}${PREFIX}/bin/snmpc

post-install-FOP-on:
	@${ECHO_CMD} "MANPATH ${PREFIX}/lib/erlang/man" > ${WRKDIR}/erlang.conf
	${INSTALL_DATA} ${WRKDIR}/erlang.conf ${STAGEDIR}${PREFIX}/etc/man.d/erlang.conf
	for SECTION in 1 3 4 6 7; do \
		${MKDIR} -p ${STAGEDIR}${PREFIX}/lib/erlang/man/man$${SECTION}; \
	  	${FIND} ${WRKSRC}/erts ${WRKSRC}/lib -type f | ${GREP} doc/man$${SECTION} \
			| ${XARGS} -J % ${CP} -v % ${STAGEDIR}${PREFIX}/lib/erlang/man/man$${SECTION}; \
	done

post-install-PDF-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${FIND} ${WRKSRC} -name \*.pdf | ${XARGS} -J % ${CP} -v % ${STAGEDIR}${DOCSDIR}

post-install-GS-off:
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/gs-*

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

post-stage:
	${FIND} ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/* -type d -empty -delete
	@cd ${STAGEDIR}${PREFIX}; ${FIND} lib/${ERLANG_LIB}/* -type f -o -type l \
		| ${SORT} >> ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}; ${FIND} ${DOCSDIR_REL}/* -name \*.pdf \
		| ${SORT} >> ${TMPPLIST}

.include <bsd.port.post.mk>
