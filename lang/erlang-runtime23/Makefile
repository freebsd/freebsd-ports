# Created by: ruslan@shevchenko.kiev.ua

PORTNAME=	erlang
DISTVERSIONPREFIX=	OTP-
DISTVERSION=	23.3.2
PORTREVISION=	0
CATEGORIES=	lang parallel java
PKGNAMESUFFIX=	-runtime23
DIST_SUBDIR=	erlang

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Functional programming language from Ericsson

LICENSE=	APACHE20

BROKEN_sparc64=	Fails to build: error: fp_except undeclared

USES=		autoreconf:build gmake ncurses perl5
USE_GITHUB=	nodefault
GH_ACCOUNT=	erlang:otp,corba
GH_PROJECT=	otp:otp corba:corba
GH_TAGNAME=	5.0.1:corba
USE_PERL5=	build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-smp-support

MAKE_JOBS_UNSAFE=	yes

DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}
SUB_FILES=	pkg-message
SUB_LIST=	ERLANG_LIB=${ERLANG_LIB}

WRKSRC=		${WRKSRC_otp}

ERLANG_LIB=	${PORTNAME}${PORTVERSION:C/\..*//}

OPTIONS_DEFINE=		CORBA DIRTY DTRACE HIPE JAVA KQUEUE NATIVE ODBC OPENSSL \
			SCTP THREADS WX
OPTIONS_DEFAULT=	CORBA DIRTY DTRACE KQUEUE OPENSSL SCTP THREADS

.if !exists(/usr/sbin/dtrace)
OPTIONS_EXCLUDE+=	DTRACE
.endif

OPTIONS_EXCLUDE_DragonFly=	HIPE NATIVE SCTP
# ld(1) fails to link probes: missing __dtrace_erlang___* symbols
OPTIONS_EXCLUDE_aarch64=	DTRACE
OPTIONS_EXCLUDE_armv6=	DTRACE
OPTIONS_EXCLUDE_armv7=	DTRACE
OPTIONS_EXCLUDE_i386=	DTRACE HIPE NATIVE
OPTIONS_EXCLUDE_powerpc64=	HIPE
OPTIONS_EXCLUDE_riscv64=	DTRACE

CORBA_DESC=	Enable Corba support
DIRTY_DESC=	Enable Dirty schedulers
HIPE_DESC=	Build native HiPE compiler
KQUEUE_DESC=	Enable Kernel Poll (kqueue) support
NATIVE_DESC=	Enable native libraries
SCTP_DESC=	Enable SCTP support
WX_DESC=	Enable WX application

# If you run Erlang and get a message resembling "WARNING: number of
# probes fixed does not match the number of defined probes (54 != 132,
# respectively)" you probably misconfigured DTrace in some way.

DIRTY_CONFIGURE_ENABLE=		dirty-schedulers
DTRACE_CONFIGURE_WITH=		dynamic-trace=dtrace
DTRACE_CFLAGS=			-fno-omit-frame-pointer
DTRACE_VARS=			STRIP=""
HIPE_CONFIGURE_ENABLE=		hipe
JAVA_CONFIGURE_WITH=		javac
JAVA_CONFIGURE_ENV=		ac_cv_prog_JAVAC="${JAVAC}"
JAVA_VARS=			USE_JAVA=yes
KQUEUE_CONFIGURE_ENABLE=	kernel-poll
NATIVE_IMPLIES=			HIPE
NATIVE_CONFIGURE_ENABLE=	native-libs
ODBC_LIB_DEPENDS=		libodbc.so:databases/unixODBC
ODBC_CONFIGURE_WITH=		odbc
ODBC_CFLAGS=			-I/usr/local/include
ODBC_LDFLAGS=			-L/usr/local/lib
OPENSSL_USES=			ssl
OPENSSL_CONFIGURE_WITH=		ssl=${OPENSSLBASE}
SCTP_CONFIGURE_ENABLE=		sctp
THREADS_CONFIGURE_ENABLE=	threads
WX_USES=			gl
WX_CONFIGURE_WITH=		wx-config=${WX_CONFIG}
WX_VARS=			USE_GL="gl glu" \
				USE_WX=3.1+ \
				WX_COMPS="wx"

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

post-build-CORBA-on:
	cd ${WRKSRC_corba} \
		&& ${SETENV} OVERRIDE_TARGET=${CONFIGURE_TARGET} ERL_TOP=${WRKSRC_otp} ${MAKE_CMD}

post-install-CORBA-on:
	cd ${WRKSRC_corba} \
		&& ${SETENV} OVERRIDE_TARGET=${CONFIGURE_TARGET} ERL_TOP=${WRKSRC_otp} \
			${MAKE_CMD} release RELEASE_ROOT=${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}

post-install-DTRACE-on:
	${MKDIR} ${STAGEDIR}${DATADIR}/dtrace
	${INSTALL_DATA} ${WRKSRC}/erts/emulator/beam/*.d \
		${WRKSRC}/lib/runtime_tools/c_src/*.d \
		${WRKSRC}/lib/runtime_tools/examples/*.d \
		${STAGEDIR}${DATADIR}/dtrace

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
	@cd ${STAGEDIR}${PREFIX}; ${FIND} lib/${ERLANG_LIB}/* ${DATADIR_REL}/* -type f -o -type l \
		| ${SORT} >> ${TMPPLIST}

.include <bsd.port.post.mk>
