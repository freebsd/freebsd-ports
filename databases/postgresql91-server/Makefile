# Created by: Marc G. Fournier <scrappy@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	postgresql
DISTVERSION?=	9.1.13
PORTREVISION?=	0
CATEGORIES?=	databases
MASTER_SITES=	PGSQL
MASTER_SITE_SUBDIR=	source/v${DISTVERSION}
PKGNAMESUFFIX?=	${DISTVERSION:R:S/.//}${COMPONENT}

MAINTAINER?=	pgsql@FreeBSD.org
COMMENT?=	The most advanced open-source database available anywhere

CONFLICTS?=	${PORTNAME}[^${PORTVERSION:R:R}]?-client* \
		${PORTNAME}${COMPONENT}-[^${PORTVERSION:R:R}].* \
		${PORTNAME}9[^${PORTVERSION:R:E}]-client* \
		${PORTNAME}${COMPONENT}-9.[^${PORTVERSION:R:E}].*

WRKSRC=		${WRKDIR}/postgresql-${DISTVERSION}
DIST_SUBDIR=	postgresql

ICU_PATCHFILE?=	pg-923-icu-2014-02-10.diff.gz

.if !defined(SLAVE_ONLY)
UNIQUENAME?=	${PORTNAME}${DISTVERSION:R:S/.//}
.else # Contrib has different options from -client/-server
UNIQUENAME?=	${PORTNAME}${DISTVERSION:R:S/.//}${PKGNAMESUFFIX}
.endif

PKGINSTALL?=	${PKGDIR}/pkg-install${COMPONENT}
USE_BZIP2=	yes
.if !defined(NO_BUILD)
USES+=	gmake
GNU_CONFIGURE=	yes
.endif

PG_USER=	pgsql
PG_GROUP=	pgsql
PG_UID=	70

LDFLAGS+=	-L${LOCALBASE}/lib
INCLUDES+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=--with-libraries=${PREFIX}/lib \
		--with-includes=${PREFIX}/include \
		--enable-thread-safety
CONFIGURE_ENV+=	INCLUDES="${INCLUDES}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		LDFLAGS_SL="${LDFLAGS_SL}"

PLIST=		${PKGDIR}/pkg-plist${COMPONENT}

INSTALL_DIRS?=	src/timezone src/backend \
		src/backend/utils/mb/conversion_procs \
		src/backend/snowball src/backend/replication/libpqwalreceiver \
		src/bin/initdb src/bin/pg_ctl \
		src/bin/pg_controldata src/bin/pg_resetxlog src/pl \
		src/bin/pg_basebackup
BUILD_DIRS?=	src/port ${INSTALL_DIRS}

.if !defined(CLIENT_ONLY) && !defined(SLAVE_ONLY)
COMPONENT=	-server
SERVER_ONLY=	yes
USE_RC_SUBR=	postgresql
USE_PGSQL=	yes
WANT_PGSQL_VER=	${DISTVERSION:C/([0-9][0-9]*)\.([0-9][0-9]*).*/\1\2/g}
USERS=		${PG_USER}
GROUPS=	${PG_GROUP}
SUB_FILES+=	502.pgsql
.endif

.if !defined(CLIENT_ONLY)
MAKE_ENV=	PATH=${PREFIX}/bin:${PATH}
CONFIGURE_ENV+=	PATH=${PREFIX}/bin:${PATH}
.endif

.if !defined(SLAVE_ONLY)
OPTIONS_DEFINE+=	NLS DTRACE PAM LDAP GSSAPI OPTIMIZED_CFLAGS XML TZDATA DEBUG KRB5
OPTIONS_SINGLE= KRB5
OPTIONS_SINGLE_KRB5= MIT_KRB5 HEIMDAL_KRB5

KRB5_DESC=       Build with kerberos provider support
NLS_DESC=	Use internationalized messages
DTRACE_DESC=	Build with DTrace probes (server only)
PAM_DESC=	Build with PAM Support
LDAP_DESC=	Build with LDAP authentication support (server only)
MIT_KRB5_DESC=	Build with MIT kerberos support
HEIMDAL_KRB5_DESC=	Builds with Heimdal kerberos
GSSAPI_DESC=	Build with GSSAPI support
OPTIMIZED_CFLAGS_DESC=	Builds with compiler optimizations (-O3)
XML_DESC=	Build with XML data type (server)
TZDATA_DESC=	Use internal timezone database (server)
DEBUG_DESC=	Builds with debugging symbols
OSSP_UUID_DESC=	Enable / disable ossp-uuid support

# See http://people.freebsd.org/~girgen/postgresql-icu/README.html for more info
OPTIONS_DEFINE+=	ICU
ICU_DESC=	Use ICU for unicode collation (server)

# See http://www.freebsd.org/cgi/query-pr.cgi?pr=ports/76999 for more info
# (requires dump/restore if modified.)
OPTIONS_DEFINE+=	INTDATE
INTDATE_DESC=	Builds with 64-bit date/time type (server)

OPTIONS_DEFINE+=	SSL
SSL_DESC=	Build with OpenSSL support

OPTIONS_DEFAULT=	NLS XML TZDATA INTDATE SSL
.endif # !SLAVE_ONLY

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-openssl
.endif

.if !defined(SLAVE_ONLY)
.  if ( defined(SERVER_ONLY) && ${PORT_OPTIONS:MICU} ) || make(makesum)
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS+=--with-icu
PATCH_SITES+=	http://people.freebsd.org/~girgen/postgresql-icu/:icu
PATCHFILES+=	${ICU_PATCHFILE}:icu
LIB_DEPENDS+=	libicudata.so:${PORTSDIR}/devel/icu
.  endif
.endif # !SLAVE_ONLY

.if ${PORT_OPTIONS:MOSSP_UUID}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libuuid.a:${PORTSDIR}/misc/ossp-uuid
CONFIGURE_ARGS+=--with-ossp-uuid
PLIST_SUB+=	OSSP=""
.else
PLIST_SUB+=	OSSP="@comment "
.endif

.if !defined(SLAVE_ONLY)

PATCH_DIST_STRIP=-p1

.  if ${PORT_OPTIONS:MDTRACE}
CONFIGURE_ARGS+=--enable-dtrace
LDFLAGS+=-lelf
.    if ${OSVERSION} < 900021
IGNORE=	need userland DTrace support found in FreeBSD 9.0
.    endif
.  endif

.  if ${PORT_OPTIONS:MPAM}
CONFIGURE_ARGS+=--with-pam
.  endif

.  if ${PORT_OPTIONS:MLDAP}
.    if defined (SERVER_ONLY)
CONFIGURE_ARGS+=--with-ldap
USE_OPENLDAP=	yes
.    endif
.  endif

.  if ${PORT_OPTIONS:MXML}
CONFIGURE_ARGS+=--with-libxml
LIB_DEPENDS+=	libxml2.so:${PORTSDIR}/textproc/libxml2
.  endif

.  if ${PORT_OPTIONS:MTZDATA}
PLIST_SUB+=	TZDATA=""
.  else
CONFIGURE_ARGS+=--with-system-tzdata=/usr/share/zoneinfo
PLIST_SUB+=	TZDATA="@comment "
.  endif

.  if empty(PORT_OPTIONS:MINTDATE)
CONFIGURE_ARGS+=--disable-integer-datetimes
.  endif

.  if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	GETTEXT=""
USES+=	gettext
.  else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	GETTEXT="@comment "
.  endif

.  if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -funroll-loops
.  endif

.  if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
INSTALL_TARGET=	install
.  else
INSTALL_TARGET=	install-strip
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
LIB_DEPENDS+=	krb5.3:${PORTSDIR}/security/krb5
.    endif
.   endif
.  endif

.  if ${PORT_OPTIONS:MHEIMDAL_KRB5}
CONFIGURE_ARGS+=--with-krb5
.  endif

.endif # !SLAVE_ONLY

PLIST_SUB+=	PG_USER=${PG_USER} \
		PG_GROUP=${PG_GROUP}
SUB_LIST+=	PG_GROUP=${PG_GROUP} \
		PG_USER=${PG_USER} \
		PG_UID=${PG_UID}

# For testing files in FILESDIR
.include <bsd.port.pre.mk>

.if defined(SERVER_ONLY)
pre-build:
	@${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL
.endif

.if !defined(NO_BUILD) && !target(do-build)

do-build:
	@ cd ${WRKSRC}/src/backend && ${SETENV} ${MAKE_ENV} ${GMAKE} symlinks
	@ for dir in ${BUILD_DIRS}; do \
		cd ${WRKSRC}/$${dir} && ${SETENV} ${MAKE_ENV} ${GMAKE}; \
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
.  if ${PORT_OPTIONS:MICU}
	@${REINPLACE_CMD} -E -e \
		"s|^(m4_if.*)2.6[0-9](.*Autoconf version )2.6[0-9]|\1${AUTOCONF_VERSION}\2${AUTOCONF_VERSION}|g" \
		${WRKSRC}/configure.in
.  endif

do-install:
	@for dir in ${INSTALL_DIRS}; do \
	    cd ${WRKSRC}/$${dir} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} ${INSTALL_TARGET}; \
	done
.  if defined(SERVER_ONLY)
	@ ${MKDIR} ${STAGEDIR}${PREFIX}/share/postgresql ;\
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily ;\
	${INSTALL_SCRIPT} ${WRKDIR}/502.pgsql \
			${STAGEDIR}${PREFIX}/etc/periodic/daily
	${MKDIR} ${STAGEDIR}${PREFIX}/${PG_USER}
.  endif # SERVER_ONLY
.  if defined(CLIENT_ONLY)
	@ cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install-local
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
	  cd ${WRKSRC}; ${GMAKE} check ;\
	 else \
	  ${ECHO} "You cannot run regression tests when postgresql is built as user root." ; \
	  ${ECHO} "Clean and rebuild the port as a regular user to run the tests." ;\
	 fi
.endif

.include <bsd.port.post.mk>
