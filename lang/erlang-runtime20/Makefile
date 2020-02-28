# Created by: ruslan@shevchenko.kiev.ua
# $FreeBSD$

PORTNAME=	erlang
DISTVERSIONPREFIX=	OTP-
DISTVERSION=	20.3.8.26
CATEGORIES=	lang parallel java
PKGNAMESUFFIX=	-runtime20
DIST_SUBDIR=	erlang

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Functional programming language from Ericsson

LICENSE=	APACHE20

BROKEN_sparc64=	Fails to build: error: fp_except undeclared

USES=		autoreconf:build gmake ncurses perl5
USE_GITHUB=	yes
GH_PROJECT=	otp
USE_PERL5=	build

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes

SUB_FILES=	pkg-message
SUB_LIST=	ERLANG_LIB=${ERLANG_LIB}

ERLANG_LIB=	${PORTNAME}${PORTVERSION:C/\..*//}

OPTIONS_DEFINE=	DIRTY DTRACE HIPE JAVA KQUEUE NATIVE ODBC OPENSSL SCTP THREADS WX
OPTIONS_DEFAULT=DIRTY DTRACE HIPE KQUEUE OPENSSL SCTP THREADS
OPTIONS_EXCLUDE_powerpc64=	HIPE ${OPTIONS_EXCLUDE_${ARCH}_${OSREL:R}}
OPTIONS_EXCLUDE_powerpc64_13=	DTRACE

DIRTY_DESC=	Enable Dirty schedulers
HIPE_DESC=	Build native HiPE compiler
KQUEUE_DESC=	Enable Kernel Poll (kqueue) support
NATIVE_DESC=	Enable native libraries
SCTP_DESC=	Enable SCTP support
WX_DESC=	Enable WX application

NATIVE_IMPLIES=	HIPE

.if !exists(/usr/sbin/dtrace)
OPTIONS_EXCLUDE+=	DTRACE
.endif

OPTIONS_EXCLUDE_DragonFly=	HIPE NATIVE SCTP
# ld(1) fails to link probes: missing __dtrace_erlang___* symbols
OPTIONS_EXCLUDE_aarch64=	DTRACE
OPTIONS_EXCLUDE_armv6=		DTRACE
OPTIONS_EXCLUDE_armv7=		DTRACE
OPTIONS_EXCLUDE_i386=		DTRACE NATIVE HIPE

OPENSSL_VARS=	BROKEN_SSL=openssl

# If you run Erlang and get a message resembling "WARNING: number of
# probes fixed does not match the number of defined probes (54 != 132,
# respectively)" you probably misconfigured DTrace in some way.

CONFIGURE_ENABLE=	smp-support

DIRTY_CONFIGURE_ENABLE=	dirty-schedulers
DTRACE_CFLAGS=		-fno-omit-frame-pointer
DTRACE_CONFIGURE_WITH=	dynamic-trace=dtrace
DTRACE_VARS=		STRIP=""
HIPE_CONFIGURE_ENABLE=	hipe
JAVA_CONFIGURE_ENV=	ac_cv_prog_JAVAC="${JAVAC}"
JAVA_CONFIGURE_WITH=	javac
JAVA_VARS=		USE_JAVA=yes
KQUEUE_CONFIGURE_ENABLE=kernel-poll
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

.include <bsd.port.post.mk>
