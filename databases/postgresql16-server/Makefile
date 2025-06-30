PORTNAME?=	postgresql
DISTVERSION?=	16.9
# PORTREVISION must be ?= otherwise, all slave ports get this PORTREVISION and
# not their own.  Probably best to keep it at ?=0 when reset here too.
PORTREVISION?=	1
CATEGORIES?=	databases
MASTER_SITES=	PGSQL/source/v${DISTVERSION}
PKGNAMESUFFIX?= ${PORTVERSION:R}${COMPONENT}

MAINTAINER?=	pgsql@FreeBSD.org
COMMENT?=	PostgreSQL is the most advanced open-source database available anywhere
WWW=		https://www.postgresql.org/

LICENSE=	PostgreSQL

CONFLICTS+=	${PORTNAME}1[^${PORTVERSION:R:C/.*([0-9]$)/\\1/}]*

WRKSRC=		${WRKDIR}/postgresql-${DISTVERSION}
DIST_SUBDIR=	postgresql

OPTIONS_SUB=	yes

PKGINSTALL?=	${PKGDIR}/pkg-install${COMPONENT}
USES+=		tar:bzip2 cpe
.if !defined(NO_BUILD)
USES+=		gmake
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
.endif

PG_USER?=	postgres
PG_GROUP?=	postgres
PG_UID?=	770

LDFLAGS+=	-L${LOCALBASE}/lib
INCLUDES+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=--with-libraries=${PREFIX}/lib \
		--with-includes=${PREFIX}/include \
		--enable-thread-safety
CONFIGURE_ENV+=	INCLUDES="${INCLUDES}" \
		PTHREAD_LIBS="-lpthread" \
		LDFLAGS_SL="${LDFLAGS_SL}"
LDFLAGS+=	-lpthread
MAKE_ENV=	MAKELEVEL=0

PLIST=		${PKGDIR}/pkg-plist${COMPONENT}

INSTALL_DIRS?=	src/common src/timezone src/backend \
		src/backend/utils/mb/conversion_procs \
		src/backend/snowball src/backend/replication/libpqwalreceiver \
		src/backend/replication/pgoutput \
		src/bin/initdb src/bin/pg_ctl \
		src/bin/pg_archivecleanup src/bin/pg_basebackup \
		src/bin/pg_checksums \
		src/bin/pg_controldata src/bin/pg_resetwal src/pl \
		src/bin/pg_rewind \
		src/bin/pg_test_fsync src/bin/pg_test_timing \
		src/bin/pg_waldump src/bin/pg_upgrade

BUILD_DIRS?=	src/port ${INSTALL_DIRS}
INSTALL_TARGET?=install-strip

.if !defined(CLIENT_ONLY) && !defined(SLAVE_ONLY)
SERVER_ONLY=	yes
COMPONENT=	-server
USE_RC_SUBR=	postgresql
USES+=		pgsql:${DISTVERSION:C/([0-9]\.?[0-9]).*/\1/g}
USERS=		${PG_USER}
GROUPS=	${PG_GROUP}
SUB_FILES+=	502.pgsql
.endif

MAKE_ENV+=	PATH=${PREFIX}/bin:${PATH}
CONFIGURE_ENV+=	PATH=${PREFIX}/bin:${PATH}

.if defined(SERVER_ONLY)
OPTIONS_DEFINE=	DTRACE LDAP TZDATA XML DOCS
OPTIONS_DEFAULT+=XML
LDAP_DESC=	Build with LDAP authentication support
TZDATA_DESC=	Use internal timezone database
XML_DESC=	Build with XML data type

DTRACE_CONFIGURE_ENABLE=dtrace
DTRACE_LDFLAGS=		-lelf
DTRACE_INSTALL_TARGET=	install

.  if ${DISTVERSION:C/([0-9][0-9]).*/\1/g} >= 14
OPTIONS_DEFINE+=	LZ4
OPTIONS_DEFAULT+=	LZ4
LZ4_DESC=		Build with LZ4 compression support
LZ4_CONFIGURE_WITH=	lz4
LZ4_LIB_DEPENDS+=	liblz4.so:archivers/liblz4
.  endif

.  if ${DISTVERSION:C/([0-9][0-9]).*/\1/g} >= 15
OPTIONS_DEFINE+=	ZSTD
OPTIONS_DEFAULT+=	ZSTD
ZSTD_DESC=		Build with ZSTD compression support
ZSTD_CONFIGURE_WITH=	zstd
ZSTD_LIB_DEPENDS+=	libzstd.so:archivers/zstd
.  endif

OPTIONS_DEFINE+=	LLVM
OPTIONS_DEFAULT+=	LLVM
LLVM_DESC=		Build with support for JIT-compiling expressions
LLVM_CONFIGURE_WITH=	llvm
LLVM_CONFIGURE_ENV=	LLVM_CONFIG=${LLVM_CONFIG} \
			CLANG=${LOCALBASE}/bin/clang${LLVM_VERSION}
LLVM_USES=		llvm:min=11,lib

CONFIGURE_ARGS+=	--with-icu
LIB_DEPENDS+=		libicudata.so:devel/icu
USES+=			pkgconfig
.else
CONFIGURE_ARGS+=	--without-icu
.endif


.if !defined(SLAVE_ONLY)
OPTIONS_DEFINE+=	NLS PAM GSSAPI OPTIMIZED_CFLAGS DEBUG DOCS SSL
NLS_DESC=		Use internationalized messages
PAM_DESC=		Build with PAM Support
GSSAPI_DESC=		Build with GSSAPI from base (security/krb5)
OPTIMIZED_CFLAGS_DESC=	Builds with compiler optimizations (-O3)
SSL_DESC=		Build with OpenSSL support

OPTIONS_DEFAULT+=	SSL

GSSAPI_USES=		gssapi:mit
GSSAPI_CONFIGURE_WITH=	gssapi
.endif # !SLAVE_ONLY

SSL_USES=		ssl
SSL_CONFIGURE_WITH=	openssl

PAM_CONFIGURE_WITH=	pam

XML_CONFIGURE_WITH=	libxml
XML_LIB_DEPENDS=	libxml2.so:textproc/libxml2

TZDATA_CONFIGURE_OFF=	--with-system-tzdata=/usr/share/zoneinfo

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

LDAP_CONFIGURE_WITH=	ldap
LDAP_USES=		ldap

OPTIMIZED_CFLAGS_CFLAGS=-O3 -funroll-loops

DEBUG_CONFIGURE_ENABLE=	debug

PLIST_SUB+=		PG_VERSION=${PORTVERSION:R} \
			PG_USER=${PG_USER} \
			PG_USER_regex=[[:<:]]${PG_USER}[[:>:]] \
			PG_GROUP=${PG_GROUP} \
			PG_GROUP_regex=[[:<:]]${PG_GROUP}[[:>:]]
SUB_LIST+=		PG_VERSION=${PORTVERSION:R} \
			PG_GROUP=${PG_GROUP} \
			PG_USER=${PG_USER} \
			PG_UID=${PG_UID}

.include <bsd.port.options.mk>

# i386 older than Pentium lacks SSE2 so the binary will not run if we build with clang -msse2
# For such ancient CPUs, gcc must be used to build PostgreSQL.
# https://www.postgresql.org/message-id/20190307140421.GA8362%40gate.oper.dinoex.org
.if ${ARCH} == "i386"
CFLAGS+=	-msse2
.endif

.if !defined(SLAVE_ONLY)
PATCH_DIST_STRIP=-p1
.endif # !SLAVE_ONLY

# For testing files in FILESDIR
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MLLVM}
INSTALL_DIRS+=		src/backend/jit/llvm
.endif

.if defined(SERVER_ONLY)
pre-build:
	@${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL
.endif

.if !defined(NO_BUILD) && !target(do-build)

do-build:
	@ cd ${WRKSRC}/src/backend && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} generated-headers
	@ for dir in ${BUILD_DIRS}; do \
		cd ${WRKSRC}/$${dir} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} ; \
	done

.  if exists(${FILESDIR}/pkg-message${COMPONENT}.in)
SUB_FILES+=	pkg-message${COMPONENT}
PKGMESSAGE=	${WRKSRC}/pkg-message${COMPONENT}
.  endif
.  if exists(${FILESDIR}/pkg-install${COMPONENT}.in)
SUB_FILES+=	pkg-install${COMPONENT}
.  endif

post-patch:
.  if defined(CLIENT_ONLY) && !defined(OPENSSL_PORT)
	@${REINPLACE_CMD} \
		-e '/^PKG_CONFIG_REQUIRES_PRIVATE = libssl libcrypto/d' \
		${WRKSRC}/src/interfaces/libpq/Makefile
.  endif

do-install:
	@for dir in ${INSTALL_DIRS}; do \
	    cd ${WRKSRC}/$${dir} && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${INSTALL_TARGET}; \
	done
.  if defined(SERVER_ONLY)
	@ ${MKDIR} ${STAGEDIR}${PREFIX}/share/postgresql ;\
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily ;\
	${INSTALL_SCRIPT} ${WRKDIR}/502.pgsql \
			${STAGEDIR}${PREFIX}/etc/periodic/daily
.  endif # SERVER_ONLY
.  if defined(CLIENT_ONLY)
	@ cd ${WRKSRC}/src && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-local
.  endif
	@ if [ -r ${PKGMESSAGE} ]; then \
		${MKDIR} ${STAGEDIR}${DOCSDIR} ;\
		${INSTALL_DATA} ${PKGMESSAGE} ${STAGEDIR}${DOCSDIR}/README${COMPONENT} ;\
	fi
.endif # !NO_BUILD

.if defined(SERVER_ONLY)
check:
	@if [ `id -u` != 0 ] ; then \
	  ${ECHO} "Running postgresql regressions tests" ;\
	  cd ${WRKSRC}; ${MAKE_CMD} check ;\
	 else \
	  ${ECHO} "You cannot run regression tests when postgresql is built as user root." ; \
	  ${ECHO} "Clean and rebuild the port as a regular user to run the tests." ;\
	 fi
.endif

.include <bsd.port.post.mk>
