# New ports collection makefile for:	PostgreSQL
# Date created:		November 13, 1998
# Whom:			Marc G. Fournier <scrappy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	postgresql
DISTVERSION?=	9.1.1
DISTVERSION?=	9.1.0
CATEGORIES?=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR=	source/v${DISTVERSION}
PKGNAMESUFFIX?=	-server

MAINTAINER?=	girgen@FreeBSD.org
COMMENT?=	The most advanced open-source database available anywhere

CONFLICTS?=	${PORTNAME}-client-[78]* \
		${PORTNAME}-client-9.[02-9]* \
		${PORTNAME}${PKGNAMESUFFIX}-[78]* \
		${PORTNAME}${PKGNAMESUFFIX}-9.[02-9]

WRKSRC=		${WRKDIR}/postgresql-${DISTVERSION}
DIST_SUBDIR=	postgresql

UNIQUENAME?=	${PORTNAME}91
LATEST_LINK?=	${PKGNAMEPREFIX}${UNIQUENAME}${PKGNAMESUFFIX}

PKGINSTALL?=	${PKGDIR}/pkg-install${PKGNAMESUFFIX}
USE_BZIP2=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
.if defined(NO_BUILD)
.undef USE_GMAKE
.undef GNU_CONFIGURE
.endif

PG_USER?=	pgsql
PG_GROUP?=	${PG_USER}
PG_UID?=	70

LDFLAGS+=	-L${LOCALBASE}/lib
INCLUDES+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=--with-libraries=${PREFIX}/lib \
		--with-includes=${PREFIX}/include \
		--enable-thread-safety
CONFIGURE_ENV+=	INCLUDES="${INCLUDES}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

PLIST=		${PKGDIR}/pkg-plist${PKGNAMESUFFIX}

BUILD_DIRS?=	src/timezone src/backend src/backend/utils/mb/conversion_procs \
		src/backend/snowball src/backend/replication/libpqwalreceiver \
		src/bin/initdb src/bin/pg_ctl \
		src/bin/pg_controldata src/bin/pg_resetxlog src/pl

INSTALL_DIRS?=	${BUILD_DIRS}

.if !defined(CLIENT_ONLY) && !defined(SLAVE_ONLY)
SERVER_ONLY=	yes
USE_RC_SUBR=	postgresql
USE_PGSQL=	yes
WANT_PGSQL_VER=	${DISTVERSION:C/([0-9][0-9]*)\.([0-9][0-9]*).*/\1\2/g}
USERS?=		${PG_USER}
.if (${USERS} != "pgsql")
UID_FILES+=	${WRKDIR}/pguid
GID_FILES+=	${WRKDIR}/pggid
.endif
GROUPS?=	${PG_GROUP}
SUB_FILES+=	502.pgsql
.endif

.if !defined(SLAVE_ONLY)
OPTIONS=	NLS "Use internationalized messages" on
.endif

.if !defined(CLIENT_ONLY)
MAKE_ENV=	PATH=${PREFIX}/bin:${PATH}
CONFIGURE_ENV+=	PATH=${PREFIX}/bin:${PATH}
.endif

.if !defined(SLAVE_ONLY)
OPTIONS+=	DTRACE "Build with DTrace probes (server only)" off
OPTIONS+=	PAM "Build with PAM support (server only)" off
OPTIONS+=	LDAP "Build with LDAP authentication support" off
OPTIONS+=	MIT_KRB5 "Build with MIT's kerberos support" off
OPTIONS+=	HEIMDAL_KRB5 "Builds with Heimdal kerberos support" off
OPTIONS+=	OPTIMIZED_CFLAGS "Builds with compiler optimizations (-O3)" off
OPTIONS+=	XML "Build with XML data type (server)" on
OPTIONS+=	TZDATA "Use internal timezone database (server)" on
OPTIONS+=	DEBUG "Builds with debugging symbols" off
OPTIONS+=	GSSAPI "Build with GSSAPI support" off

# See http://people.freebsd.org/~girgen/postgresql-icu/README.html for more info
OPTIONS+=	ICU	"Use ICU for unicode collation (server)" off

# See http://www.freebsd.org/cgi/query-pr.cgi?pr=ports/76999 for more info
# (requires dump/restore if modified.)
OPTIONS+=	INTDATE "Builds with 64-bit date/time type (server)" on

OPTIONS+=	SSL "Build with OpenSSL support" on
.endif # !SLAVE_ONLY

.include <bsd.port.options.mk>

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-openssl
.endif

.if !defined(SLAVE_ONLY)
.  if (defined(SERVER_ONLY) && defined(WITH_ICU)) || make(makesum)
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS+=--with-icu
PATCH_SITES+=	http://people.freebsd.org/~mm/patches/postgresql-icu/:icu
PATCHFILES+=	pg-910-icu-2011-09-22.diff.gz:icu
LIB_DEPENDS+=	icudata.48:${PORTSDIR}/devel/icu
.  endif
.endif # !SLAVE_ONLY

.include <bsd.port.pre.mk>

.if !defined(SLAVE_ONLY)

PATCH_DIST_STRIP=-p1

.  if defined(WITH_DTRACE)
CONFIGURE_ARGS+=--enable-dtrace
LDFLAGS+=-lelf
.  endif

.  if defined(WITH_PAM)
CONFIGURE_ARGS+=--with-pam
.  endif

.  if defined(WITH_LDAP)
CONFIGURE_ARGS+=--with-ldap
.    if defined (SERVER_ONLY)
USE_OPENLDAP=	YES
.    endif
.  endif

.  if defined(WITH_XML)
CONFIGURE_ARGS+=--with-libxml
LIB_DEPENDS+=	xml2.5:${PORTSDIR}/textproc/libxml2
.  endif

.  if defined(WITH_TZDATA)
PLIST_SUB+=	TZDATA=""
.  else
CONFIGURE_ARGS+=--with-system-tzdata=/usr/share/zoneinfo
PLIST_SUB+=	TZDATA="@comment "
.  endif

.  if defined(WITHOUT_INTDATE)
CONFIGURE_ARGS+=--disable-integer-datetimes
.  endif

.  if !(defined(WITHOUT_GETTEXT) || defined(WITHOUT_NLS))
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	GETTEXT=""
USE_GETTEXT=	YES
.  else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	GETTEXT="@comment "
.  endif

.  if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -funroll-loops
.  endif

.  if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
INSTALL_TARGET=	install
.  else
INSTALL_TARGET=	install-strip
.  endif

.if (${OSVERSION} >= 700000) && !defined(WITHOUT_GSSAPI)
CONFIGURE_ARGS+=--with-gssapi
.if !defined(WITH_MIT_KRB5) && !defined(WITH_HEIMDAL_KRB5)
# Kerberos libraries will pull the proper GSSAPI library
# via linker dependencies, but otherwise we must specify
# it explicitely: ld --as-needed is used for compilation,
# so configure's -lgssapi_krb5 won't go.
LDFLAGS+=	-lgssapi
.endif
.endif

.  if defined(WITH_MIT_KRB5)
.    if exists(/usr/lib/libkrb5.so) || exists(/usr/bin/krb5-config)
BROKEN=		You must remove /usr/bin/krb5-config and /usr/lib/libkrb5.so* (from system heimdal), and set NO_KERBEROS=true in /etc/make.conf to build successfully with MIT-KRB
.    endif
# Allow defining a home built MIT Kerberos by setting KRB5_HOME
.    if defined(KRB5_HOME) && exists(${KRB5_HOME}/lib/libgssapi_krb5.a) && exists(${KRB5_HOME}/bin/krb5-config)
CONFIGURE_ARGS+=--with-krb5
.    else
LIB_DEPENDS+=	krb5.3:${PORTSDIR}/security/krb5
CONFIGURE_ARGS+=--with-krb5
.    endif
.  endif

.  if defined(WITH_HEIMDAL_KRB5)
# Allow defining a home built Heimdal Kerberos by setting HEIMDAL_HOME
.    if defined(HEIMDAL_HOME) && exists(${HEIMDAL_HOME}/lib/libgssapi.a) && exists(${HEIMDAL_HOME}/bin/krb5-config)
CONFIGURE_ARGS+=--with-krb5
.    else
# Postgresql apps will not link properly when libpq is linked with base heimdal in /usr,
# so we always use the heimdal port. See
# http://lists.freebsd.org/pipermail/freebsd-stable/2005-October/018809.html
LIB_DEPENDS+=	krb5.26:${PORTSDIR}/security/heimdal
CONFIGURE_ARGS+=--with-krb5
.    endif
.  endif

.endif # !SLAVE_ONLY

.if defined(CLIENT_ONLY)
MAN1=		clusterdb.1 createdb.1 createlang.1 createuser.1   \
		dropdb.1 droplang.1 dropuser.1 ecpg.1 initdb.1	   \
		pg_basebackup.1 pg_config.1 pg_controldata.1 pg_ctl.1   \
		pg_dump.1 pg_dumpall.1 pg_resetxlog.1 pg_restore.1 \
		postgres.1 postmaster.1 psql.1 reindexdb.1 vacuumdb.1

MAN3=		SPI_connect.3 SPI_copytuple.3 SPI_cursor_close.3 SPI_cursor_fetch.3 \
		SPI_cursor_find.3 SPI_cursor_move.3 SPI_cursor_open.3 \
		SPI_cursor_open_with_args.3 SPI_cursor_open_with_paramlist.3 \
		SPI_exec.3 SPI_execp.3 SPI_execute.3 SPI_execute_plan.3 \
		SPI_execute_plan_with_paramlist.3 SPI_execute_with_args.3 \
		SPI_finish.3 SPI_fname.3 SPI_fnumber.3 SPI_freeplan.3 \
		SPI_freetuple.3 SPI_freetuptable.3 SPI_getargcount.3 \
		SPI_getargtypeid.3 SPI_getbinval.3 SPI_getnspname.3 \
		SPI_getrelname.3 SPI_gettype.3 SPI_gettypeid.3 \
		SPI_getvalue.3 SPI_is_cursor_plan.3 SPI_modifytuple.3 \
		SPI_palloc.3 SPI_pfree.3 SPI_pop.3 SPI_prepare.3 \
		SPI_prepare_cursor.3 SPI_prepare_params.3 SPI_push.3 \
		SPI_repalloc.3 SPI_returntuple.3 SPI_saveplan.3 \
		SPI_scroll_cursor_fetch.3 SPI_scroll_cursor_move.3 \
		dblink.3 dblink_build_sql_delete.3 dblink_build_sql_insert.3 \
		dblink_build_sql_update.3 dblink_cancel_query.3 \
		dblink_close.3 dblink_connect.3 dblink_connect_u.3 \
		dblink_disconnect.3 dblink_error_message.3 dblink_exec.3 \
		dblink_fetch.3 dblink_get_connections.3 dblink_get_notify.3 \
		dblink_get_pkey.3 dblink_get_result.3 dblink_is_busy.3 \
		dblink_open.3 dblink_send_query.3

MAN7=		ABORT.7 ALTER_AGGREGATE.7 ALTER_COLLATION.7 ALTER_CONVERSION.7 \
		ALTER_DATABASE.7 ALTER_EXTENSION.7 ALTER_DEFAULT_PRIVILEGES.7 \
		ALTER_FOREIGN_TABLE.7 \
		ALTER_DOMAIN.7 ALTER_FOREIGN_DATA_WRAPPER.7 ALTER_FUNCTION.7 ALTER_GROUP.7 \
		ALTER_LARGE_OBJECT.7 ALTER_SERVER.7 \
		ALTER_USER_MAPPING.7		ALTER_INDEX.7 ALTER_LANGUAGE.7 ALTER_OPERATOR_CLASS.7	      \
		ALTER_OPERATOR_FAMILY.7 				      \
		ALTER_ROLE.7						      \
		ALTER_SCHEMA.7 ALTER_SEQUENCE.7 ALTER_TABLE.7		      \
		ALTER_TEXT_SEARCH_CONFIGURATION.7			      \
		ALTER_TEXT_SEARCH_DICTIONARY.7				      \
		ALTER_TEXT_SEARCH_PARSER.7				      \
		ALTER_TEXT_SEARCH_TEMPLATE.7				      \
		ALTER_TRIGGER.7 ALTER_USER.7 ALTER_VIEW.7 ANALYZE.7 BEGIN.7   \
		CHECKPOINT.7 CLOSE.7 CLUSTER.7 COMMENT.7 COMMIT.7	      \
		COMMIT_PREPARED.7					      \
		COPY.7 CREATE_AGGREGATE.7 CREATE_CAST.7			      \
		CREATE_CONVERSION.7		      \
		CREATE_DATABASE.7 CREATE_DOMAIN.7 CREATE_FOREIGN_DATA_WRAPPER.7 \
		CREATE_FUNCTION.7	      \
		CREATE_GROUP.7 CREATE_INDEX.7 CREATE_LANGUAGE.7		      \
		CREATE_OPERATOR.7 CREATE_OPERATOR_CLASS.7		      \
		CREATE_OPERATOR_FAMILY.7 CREATE_ROLE.7			      \
		CREATE_RULE.7 CREATE_SCHEMA.7 CREATE_SEQUENCE.7		      \
		CREATE_SERVER.7 CREATE_TABLE.7 CREATE_TABLE_AS.7			      \
		CREATE_TEXT_SEARCH_CONFIGURATION.7			      \
		CREATE_TEXT_SEARCH_DICTIONARY.7				      \
		CREATE_TEXT_SEARCH_PARSER.7				      \
		CREATE_TEXT_SEARCH_TEMPLATE.7 CREATE_TRIGGER.7		      \
		CREATE_TYPE.7 CREATE_USER.7 CREATE_USER_MAPPING.7 CREATE_VIEW.7 DEALLOCATE.7	      \
		DECLARE.7 DELETE.7 DISCARD.7				      \
		DO.7 DROP_AGGREGATE.7 DROP_CAST.7 DROP_CONVERSION.7		      \
		DROP_DATABASE.7 DROP_DOMAIN.7 DROP_FOREIGN_DATA_WRAPPER.7 DROP_FUNCTION.7		      \
		DROP_GROUP.7 DROP_INDEX.7 DROP_LANGUAGE.7		      \
		DROP_OPERATOR.7 DROP_OPERATOR_CLASS.7 DROP_OPERATOR_FAMILY.7  \
		DROP_OWNED.7 DROP_ROLE.7 DROP_RULE.7			      \
		DROP_SCHEMA.7 DROP_SEQUENCE.7 DROP_SERVER.7 DROP_TABLE.7		      \
		DROP_TEXT_SEARCH_CONFIGURATION.7			      \
		DROP_TEXT_SEARCH_DICTIONARY.7				      \
		DROP_TEXT_SEARCH_PARSER.7				      \
		DROP_TEXT_SEARCH_TEMPLATE.7 DROP_TRIGGER.7		      \
		DROP_TYPE.7 DROP_USER.7 DROP_USER_MAPPING.7 DROP_VIEW.7 END.7 EXECUTE.7	      \
		EXPLAIN.7 FETCH.7 GRANT.7 INSERT.7 LISTEN.7 LOAD.7	      \
		LOCK.7 MOVE.7 NOTIFY.7 PREPARE.7 PREPARE_TRANSACTION.7	      \
		REASSIGN_OWNED.7 REINDEX.7 RESET.7			      \
		REVOKE.7 ROLLBACK.7 ROLLBACK_PREPARED.7 SELECT.7	      \
		SELECT_INTO.7 SET.7					      \
		SET_CONSTRAINTS.7 SET_ROLE.7 SET_TRANSACTION.7 SHOW.7	      \
		SET_SESSION_AUTHORIZATION.7 START_TRANSACTION.7		      \
		TABLE.7 TRUNCATE.7 UNLISTEN.7 UPDATE.7 VACUUM.7			      \
		ALTER_OPERATOR.7 ALTER_TABLESPACE.7 ALTER_TYPE.7	      \
		CREATE_TABLESPACE.7 DROP_TABLESPACE.7			      \
		RELEASE_SAVEPOINT.7 ROLLBACK_TO_SAVEPOINT.7		      \
		SAVEPOINT.7 VALUES.7 WITH.7 \
		CREATE_COLLATION.7 CREATE_EXTENSION.7 CREATE_FOREIGN_TABLE.7 \
		DROP_COLLATION.7 DROP_EXTENSION.7 DROP_FOREIGN_TABLE.7 \
		SECURITY_LABEL.7
.endif

.if defined(SERVER_ONLY)
pre-everything::
	@${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL
.endif

.if !defined(NO_BUILD)

pre-configure:
.  if defined(WITH_MIT_KRB5) && defined(WITH_HEIMDAL_KRB5)
	@${ECHO} "MIT's and Heimdal Kerberos are mutually exclusive."
	@${ECHO} "Please choose one or the other."
	@exit 1
.  endif

do-build:
	@ cd ${WRKSRC}/src/backend && ${SETENV} ${MAKE_ENV} ${GMAKE} symlinks
	@ for dir in src/port ${BUILD_DIRS}; do \
		cd ${WRKSRC}/$${dir} && ${SETENV} ${MAKE_ENV} ${GMAKE}; \
	done

.  if exists(${FILESDIR}/pkg-message${PKGNAMESUFFIX}.in)
SUB_FILES+=	pkg-message${PKGNAMESUFFIX}
PKGMESSAGE=	${WRKSRC}/pkg-message${PKGNAMESUFFIX}
.  endif
.  if exists(${FILESDIR}/pkg-install${PKGNAMESUFFIX}.in)
SUB_FILES+=	pkg-install${PKGNAMESUFFIX}
SUB_LIST=	PG_GROUP=$(PG_GROUP) \
		PG_USER=$(PG_USER) \
		PG_UID=$(PG_UID)
PLIST_SUB+=	PG_USER=$(PG_USER)
.  endif
.endif

.if !defined(NO_BUILD)
post-patch:
	@${REINPLACE_CMD} s/@PTHREAD_LIBS@// ${WRKSRC}/src/Makefile.global.in
.  if defined(WITH_ICU)
	@${REINPLACE_CMD} -E -e \
		"s|^(m4_if.*)2.6[0-9](.*Autoconf version )2.6[0-9]|\1${AUTOCONF_VERSION}\2${AUTOCONF_VERSION}|g" \
		${WRKSRC}/configure.in
.  endif

.  if defined(SERVER_ONLY) && (${PG_USER} != "pgsql")
pre-install:
	@${SED} -n s,pgsql,${PG_USER},gp ${PORTSDIR}/UIDs > ${WRKDIR}/pguid
	@${SED} -n s,pgsql,${PG_GROUP},gp ${PORTSDIR}/GIDs > ${WRKDIR}/pggid
.  endif

do-install:
	@for dir in ${INSTALL_DIRS}; do \
	    cd ${WRKSRC}/$${dir} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${INSTALL_TARGET}; \
	done
.  if defined(SERVER_ONLY)
	@ ${MKDIR} ${PREFIX}/share/postgresql ;\
	${MKDIR} ${PREFIX}/etc/periodic/daily ;\
	${INSTALL_SCRIPT} ${WRKDIR}/502.pgsql \
			${PREFIX}/etc/periodic/daily
.  endif # SERVER_ONLY
.  if defined(CLIENT_ONLY)
	@ cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${GMAKE} install-local
.  endif
	@ if [ -r ${PKGMESSAGE} ]; then \
		${MKDIR} ${DOCSDIR} ;\
		${INSTALL_DATA} ${PKGMESSAGE} ${DOCSDIR}/README${PKGNAMESUFFIX} ;\
		${ECHO} "======================================================================" ;\
		${CAT} ${PKGMESSAGE} ;\
		${ECHO} "======================================================================" ;\
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
