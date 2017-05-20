# Created by: Marc G. Fournier <scrappy@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	postgresql
DISTVERSION?=	9.2.21
PORTREVISION?=	0
CATEGORIES?=	databases
MASTER_SITES=	PGSQL/source/v${DISTVERSION}
PKGNAMESUFFIX?=	${PORTVERSION:R:S/.//}${COMPONENT}

MAINTAINER?=	pgsql@FreeBSD.org
COMMENT?=	PostgreSQL is the most advanced open-source database available anywhere

LICENSE=	PostgreSQL

CONFLICTS?=	${PORTNAME}[^${PORTVERSION:R:R}]?-client* \
		${PORTNAME}${COMPONENT}-[^${PORTVERSION:R:R}].* \
		${PORTNAME}9[^${PORTVERSION:R:E}]-client* \
		${PORTNAME}${COMPONENT}-9.[^${PORTVERSION:R:E}].*

WRKSRC=		${WRKDIR}/postgresql-${DISTVERSION}
DIST_SUBDIR=	postgresql

ICU_PATCHFILE?=	pg-9218-icu-2016-08-10.diff.gz

OPTIONS_SUB=	yes

PKGINSTALL?=	${PKGDIR}/pkg-install${COMPONENT}
USES+=		tar:bzip2 cpe
.if !defined(NO_BUILD)
USES+=	gmake
GNU_CONFIGURE=	yes
.endif

PG_USER?=	pgsql
PG_GROUP?=	pgsql
PG_UID?=	70

LDFLAGS+=	-L${LOCALBASE}/lib
INCLUDES+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=--with-libraries=${PREFIX}/lib \
		--with-includes=${PREFIX}/include \
		--enable-thread-safety
CONFIGURE_ENV+=	INCLUDES="${INCLUDES}" \
		PTHREAD_LIBS="-lpthread" \
		LDFLAGS_SL="${LDFLAGS_SL}"
LDFLAGS+=	-lpthread

PLIST=		${PKGDIR}/pkg-plist${COMPONENT}

INSTALL_DIRS?=	src/timezone src/backend \
		src/backend/utils/mb/conversion_procs \
		src/backend/snowball src/backend/replication/libpqwalreceiver \
		src/bin/initdb src/bin/pg_ctl \
		src/bin/pg_controldata src/bin/pg_resetxlog src/pl \
		src/bin/pg_basebackup
BUILD_DIRS?=	src/port ${INSTALL_DIRS}
INSTALL_TARGET?=install-strip

.if !defined(CLIENT_ONLY) && !defined(SLAVE_ONLY)
SERVER_ONLY=	yes
COMPONENT=	-server
USE_RC_SUBR=	postgresql
USES+=		pgsql:${DISTVERSION:C/([0-9][0-9]*\.[0-9][0-9]*).*/\1/g}
USERS=		${PG_USER}
GROUPS=	${PG_GROUP}
SUB_FILES+=	502.pgsql
.endif

.if defined(CLIENT_ONLY)
OPTIONS_DEFINE+=LIBEDIT
LIBEDIT_DESC=	Use non-GPL libedit instead of readline
USES+=		perl5
.else
MAKE_ENV=	PATH=${PREFIX}/bin:${PATH}
CONFIGURE_ENV+=	PATH=${PREFIX}/bin:${PATH}
.endif

.if defined(SERVER_ONLY)
OPTIONS_DEFINE=	DTRACE LDAP INTDATE TZDATA XML
LDAP_DESC=	Build with LDAP authentication support
DTRACE_DESC=	Build with DTrace probes
TZDATA_DESC=	Use internal timezone database
XML_DESC=	Build with XML data type

# See http://people.freebsd.org/~girgen/postgresql-icu/README.html for more info
OPTIONS_DEFINE+=	ICU
ICU_DESC=	Use ICU for unicode collation

# See http://www.freebsd.org/cgi/query-pr.cgi?pr=ports/76999 for more info
# (requires dump/restore if modified.)
OPTIONS_DEFINE+=	INTDATE
INTDATE_DESC=	Builds with 64-bit date/time type
OPTIONS_DEFAULT+=	XML TZDATA INTDATE
.endif

.if !defined(SLAVE_ONLY)
OPTIONS_DEFINE+=	NLS PAM GSSAPI OPTIMIZED_CFLAGS DEBUG
OPTIONS_RADIO= KRB5
OPTIONS_RADIO_KRB5= MIT_KRB5 HEIMDAL_KRB5

KRB5_DESC=       Build with kerberos provider support
NLS_DESC=	Use internationalized messages
PAM_DESC=	Build with PAM Support
MIT_KRB5_DESC=	Build with MIT kerberos support
HEIMDAL_KRB5_DESC=	Builds with Heimdal kerberos
GSSAPI_DESC=	Build with GSSAPI support
OPTIMIZED_CFLAGS_DESC=	Builds with compiler optimizations (-O3)

OPTIONS_DEFINE+=	SSL
SSL_DESC=	Build with OpenSSL support

OPTIONS_DEFAULT+=	NLS SSL
.endif # !SLAVE_ONLY

.if defined(CLIENT_ONLY)
LIBEDIT_CONFIGURE_ON+=--with-libedit-preferred
LIBEDIT_USES=		libedit
LIBEDIT_USES_OFF=		readline
.endif # CLIENT_ONLY

SSL_USES=	ssl
SSL_CONFIGURE_WITH=openssl

PAM_CONFIGURE_WITH=	pam

XML_CONFIGURE_WITH=	libxml
XML_LIB_DEPENDS=	libxml2.so:textproc/libxml2

TZDATA_CONFIGURE_OFF=--with-system-tzdata=/usr/share/zoneinfo

INTDATE_CONFIGURE_OFF=--disable-integer-datetimes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

LDAP_CONFIGURE_WITH=	ldap
LDAP_USE=		OPENLDAP=yes

OPTIMIZED_CFLAGS_CFLAGS=	-O3 -funroll-loops

DEBUG_CONFIGURE_ENABLE=	debug

PLIST_SUB+=	PG_USER=${PG_USER} \
		PG_GROUP=${PG_GROUP}
SUB_LIST+=	PG_GROUP=${PG_GROUP} \
		PG_USER=${PG_USER} \
		PG_UID=${PG_UID}

.include <bsd.port.options.mk>

.if !defined(SLAVE_ONLY)
.  if ( defined(SERVER_ONLY) && ${PORT_OPTIONS:MICU} ) || make(makesum)
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS+=--with-icu
PATCH_SITES+=	http://people.freebsd.org/~girgen/postgresql-icu/:icu
PATCHFILES+=	${ICU_PATCHFILE}:icu
LIB_DEPENDS+=	libicudata.so:devel/icu
.  endif
.endif # !SLAVE_ONLY

.if !defined(SLAVE_ONLY)

PATCH_DIST_STRIP=-p1

.  if ${PORT_OPTIONS:MDTRACE}
CONFIGURE_ARGS+=--enable-dtrace
LDFLAGS+=-lelf
INSTALL_TARGET=install
.  endif

.if ${PORT_OPTIONS:MGSSAPI}
CONFIGURE_ARGS+=--with-gssapi
.if empty(PORT_OPTIONS:MMIT_KRB5) && empty(PORT_OPTIONS:MHEIMDAL_KRB5)
# Kerberos libraries will pull the proper GSSAPI library
# via linker dependencies, but otherwise we must specify
# it explicitely: ld --as-needed is used for compilation,
# so configure's -lgssapi_krb5 won't go.
LDFLAGS+=	-lgssapi
LDFLAGS_SL+=	-lgssapi
.endif
.else
CONFIGURE_ARGS+=--without-gssapi
.endif

.  if ${PORT_OPTIONS:MMIT_KRB5}
.   if defined(IGNORE_WITH_SRC_KRB5) && (exists(/usr/lib/libkrb5.so) || exists(/usr/bin/krb5-config))
IGNORE=	requires that you remove heimdal's /usr/bin/krb5-config and /usr/lib/libkrb5.so*, and set NO_KERBEROS=true in /etc/src.conf to build successfully with MIT-KRB
.   else
CONFIGURE_ARGS+=--with-krb5
# Allow defining a home built MIT Kerberos by setting KRB5_HOME
.    if defined(KRB5_HOME) && exists(${KRB5_HOME}/lib/libgssapi_krb5.a) && exists(${KRB5_HOME}/bin/krb5-config)
LIB_DEPENDS+=	libkrb5.so.3:security/krb5
.    endif
.   endif
.  endif

.  if ${PORT_OPTIONS:MHEIMDAL_KRB5}
CONFIGURE_ARGS+=--with-krb5
.  endif

.endif # !SLAVE_ONLY

# For testing files in FILESDIR
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MSSL} && ${SSL_DEFAULT:Mopenssl-devel}
BROKEN=		Does not build with openssl-devel
.endif

.if defined(SERVER_ONLY)
pre-build:
	@${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL
.endif

.if !defined(NO_BUILD) && !target(do-build)

do-build:
	@ cd ${WRKSRC}/src/backend && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} symlinks
	@ for dir in ${BUILD_DIRS}; do \
		cd ${WRKSRC}/$${dir} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD}; \
	done

.  if exists(${FILESDIR}/pkg-message${COMPONENT}.in)
SUB_FILES+=	pkg-message${COMPONENT}
PKGMESSAGE=	${WRKSRC}/pkg-message${COMPONENT}
.  endif
.  if exists(${FILESDIR}/pkg-install${COMPONENT}.in)
SUB_FILES+=	pkg-install${COMPONENT}
PLIST_SUB+=	PG_USER=${PG_USER}
.  endif

post-patch:
.  if defined(SERVER_ONLY) && ${PORT_OPTIONS:MICU}
	@${REINPLACE_CMD} -E -e \
		"s|^(m4_if.*)2.6[0-9](.*Autoconf version )2.6[0-9]|\1${AUTOCONF_VERSION}\2${AUTOCONF_VERSION}|g" \
		-e '/icu/s/_57//' \
		${WRKSRC}/configure.in
.  endif

do-install:
	@for dir in ${INSTALL_DIRS}; do \
	    cd ${WRKSRC}/$${dir} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${INSTALL_TARGET}; \
	done
.  if defined(SERVER_ONLY)
	@ ${MKDIR} ${STAGEDIR}${PREFIX}/share/postgresql ;\
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily ;\
	${INSTALL_SCRIPT} ${WRKDIR}/502.pgsql \
			${STAGEDIR}${PREFIX}/etc/periodic/daily
.  endif # SERVER_ONLY
.  if defined(CLIENT_ONLY)
	@ cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-local
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
