# Created by: ruslan@shevchenko.kiev.ua
# $FreeBSD$

PORTNAME=	erlang
PORTVERSION=	16.b.03.1
PORTREVISION=	13
CATEGORIES=	lang parallel java
MASTER_SITES=	http://www.erlang.org/download/:erlangorg			\
		http://erlang.stacken.kth.se/download/:erlangorg		\
		http://www.csd.uu.se/ftp/mirror/erlang/download/:erlangorg	\
		http://olgeni.olgeni.com/~olgeni/distfiles/:local		\
		LOCAL/olgeni:local
PKGNAMESUFFIX=	-runtime16
DISTNAME=	otp_src_${ERLANG_REL}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:erlangorg
DIST_SUBDIR=	erlang
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Functional programming language from Ericsson

WRKSRC=		${WRKDIR}/otp_src_${ERLANG_REL}

ERLANG_LIB=	${PORTNAME}${PORTVERSION:C/\..*//}
ERLANG_REL=	R${PORTVERSION:S/.//g:tu:S/1$/-1/}

SUB_FILES=	pkg-message
SUB_LIST=	ERLANG_LIB=${ERLANG_LIB}

MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	DTRACE GS HIPE JAVA KQUEUE ODBC OPENSSL SCTP SMP THREADS WX
OPTIONS_DEFAULT=KQUEUE OPENSSL SCTP SMP THREADS

GS_DESC=	Enable GS application (deprecated)
HIPE_DESC=	Build native HiPE compiler
KQUEUE_DESC=	Enable Kernel Poll (kqueue) support
SCTP_DESC=	Enable SCTP support
SMP_DESC=	Enable SMP support
WX_DESC=	Enable WX application

.if !exists(/usr/sbin/dtrace)
OPTIONS_EXCLUDE+=	DTRACE
.endif

OPTIONS_EXCLUDE_DragonFly=	HIPE SCTP

OPENSSL_VARS=	BROKEN_SSL=openssl111

GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		gmake ncurses perl5
USE_PERL5=	build

# If you run Erlang and get a message resembling "WARNING: number of
# probes fixed does not match the number of defined probes (54 != 132,
# respectively)" you probably misconfigured DTrace in some way.

DTRACE_CFLAGS=		-fno-omit-frame-pointer
DTRACE_CONFIGURE_WITH=	dynamic-trace=dtrace
DTRACE_VARS=		STRIP=""
GS_USES=		tk:run
HIPE_CONFIGURE_ENABLE=	hipe
JAVA_CONFIGURE_ENV=	ac_cv_prog_JAVAC="${JAVAC}"
JAVA_CONFIGURE_WITH=	javac
JAVA_VARS=		USE_JAVA=yes
KQUEUE_CONFIGURE_ENABLE=kernel-poll
ODBC_CONFIGURE_WITH=	odbc
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
OPENSSL_CONFIGURE_WITH=	ssl=${OPENSSLBASE}
OPENSSL_USES=		ssl
SCTP_CONFIGURE_ENABLE=	sctp
SMP_CONFIGURE_ENABLE=	smp-support
THREADS_CONFIGURE_ENABLE=	threads
WX_CONFIGURE_WITH=	wx-config=${WX_CONFIG}
WX_VARS=		USE_WX=2.8+ WX_COMPS="wx contrib" USE_GL="gl glu"

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
.  if ${OSVERSION} >= 1200085 && ${SSL_DEFAULT} == base
BROKEN=	Does not support OpenSSL 1.1, use Erlang 19+
.  endif
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

pre-configure-MX-off:
	echo "disabled by port options" > ${WRKSRC}/lib/wx/SKIP

post-configure-ODBC-on:
	${RM} ${WRKSRC}/lib/odbc/SKIP

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
	${RM} -r ${STAGEDIR}${PREFIX}/lib/erlang/lib/wx-*

post-stage:
	${FIND} ${STAGEDIR}${PREFIX}/lib/${ERLANG_LIB}/* -type d -empty -delete
	@cd ${STAGEDIR}${PREFIX}; ${FIND} lib/${ERLANG_LIB}/* -type f -o -type l \
		| ${SORT} >> ${TMPPLIST}

.include <bsd.port.mk>
