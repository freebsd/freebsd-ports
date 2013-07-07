# Created by: Marc G. Fournier <scrappy@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	postgresql
DISTVERSION?=	8.4.17
PORTREVISION?=	1
CATEGORIES?=	databases
MASTER_SITES=	PGSQL
MASTER_SITE_SUBDIR=	source/v${DISTVERSION}
PKGNAMESUFFIX?=	-server

MAINTAINER?=	pgsql@FreeBSD.org
COMMENT?=	The most advanced open-source database available anywhere

CONFLICTS?=	${PORTNAME}-client-[^${PORTVERSION:R:R}].* \
		${PORTNAME}${PKGNAMESUFFIX}-[^${PORTVERSION:R:R}].* \
		${PORTNAME}-client-8.[^${PORTVERSION:R:E}].* \
		${PORTNAME}${PKGNAMESUFFIX}-8.[^${PORTVERSION:R:E}].*

WRKSRC=		${WRKDIR}/postgresql-${DISTVERSION}
DIST_SUBDIR=	postgresql

ICU_PATCHFILE?=	pg-840-icu-2009-09-15.diff.gz

UNIQUENAME?=	${PORTNAME}${DISTVERSION:R:S/.//}
LATEST_LINK?=	${PKGNAMEPREFIX}${UNIQUENAME}${PKGNAMESUFFIX}

PKGINSTALL?=	${PKGDIR}/pkg-install${PKGNAMESUFFIX}
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

PLIST=		${PKGDIR}/pkg-plist${PKGNAMESUFFIX}

BUILD_DIRS?=	src/timezone src/backend src/backend/utils/mb/conversion_procs \
		src/backend/snowball src/bin/initdb src/bin/pg_ctl \
		src/bin/pg_controldata src/bin/pg_resetxlog src/pl

INSTALL_DIRS?=	${BUILD_DIRS}

.if !defined(CLIENT_ONLY) && !defined(SLAVE_ONLY)
SERVER_ONLY=	yes
USE_RC_SUBR=	postgresql
USE_PGSQL=	yes
WANT_PGSQL_VER=	${DISTVERSION:C/([0-9][0-9]*)\.([0-9][0-9]*).*/\1\2/g}
USERS=		${PG_USER}
GROUPS=		${PG_GROUP}
SUB_FILES+=	502.pgsql
.endif

.if !defined(SLAVE_ONLY)
OPTIONS_DEFINE+=	NLS
NLS_DESC=	Use internationalized messages
OPTIONS_DEFAULT+=	NLS
.endif

.if !defined(CLIENT_ONLY)
MAKE_ENV=	PATH=${PREFIX}/bin:${PATH}
CONFIGURE_ENV+=	PATH=${PREFIX}/bin:${PATH}
.endif

.if !defined(SLAVE_ONLY)
. if ${DISTVERSION:R} == 8.4
OPTIONS_DEFINE+=	DTRACE GSSAPI
DTRACE_DESC=	Build with DTrace probes (server only)
GSSAPI_DESC=	Build with GSSAPI support
OPTIONS_DEFAULT+=	INTDATE
.endif
. if ${DISTVERSION:R} == 8.4 || ${DISTVERSION:R} == 8.3
OPTIONS_DEFINE+=	XML TZDATA
XML_DESC=	Build with XML data type (server)
TZDATA_DESC=	Use internal timezone database (server)
OPTIONS_DEFAULT+=	XML TZDATA
. endif
. if !empty(ICU_PATCHFILE)
# See http://people.freebsd.org/~girgen/postgresql-icu/README.html for more info
OPTIONS_DEFINE+=	ICU
.endif
OPTIONS_DEFINE+=	PAM LDAP OPTIMIZED_CFLAGS DEBUG KRB5
OPTIONS_SINGLE= KRB5
OPTIONS_SINGLE_KRB5= MIT_KRB5 HEIMDAL_KRB5
KRB5_DESC=       Build with kerberos provider support

# See http://www.freebsd.org/cgi/query-pr.cgi?pr=ports/76999 for more info
# (requires dump/restore if modified.)
OPTIONS_DEFINE+=	INTDATE SSL
OPTIONS_DEFAULT+=	SSL
.endif # !SLAVE_ONLY

ICU_DESC=	Use ICU for unicode collation (server)
PAM_DESC=	Build with PAM support (server only)
LDAP_DESC=	Build with LDAP authentication support
MIT_KRB5_DESC=	Build with MIT kerberos support
HEIMDAL_KRB5_DESC=	Builds with Heimdal kerberos
OPTIMIZED_CFLAGS_DESC=	Builds with compiler optimizations (-O3)
DEBUG_DESC=	Builds with debugging symbols
INTDATE_DESC=	Builds with 64-bit date/time type (server)
SSL_DESC=	Build with OpenSSL support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-openssl
.endif

.if !defined(SLAVE_ONLY)
.  if ( defined(SERVER_ONLY) && ${PORT_OPTIONS:MICU} ) || make(makesum)
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS+=--with-icu
PATCH_SITES+=	http://people.freebsd.org/~crees/postgresql-icu/:icu
PATCHFILES+=	${ICU_PATCHFILE}:icu
LIB_DEPENDS+=	icudata.50:${PORTSDIR}/devel/icu
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-icu4
.  endif
.endif # !SLAVE_ONLY

.if !defined(SLAVE_ONLY)
PATCH_DIST_STRIP=-p1

.  if ${PORT_OPTIONS:MDTRACE}
CONFIGURE_ARGS+=--enable-dtrace
LDFLAGS+=	-lelf
.    if ${OSVERSION} < 900021
IGNORE=	need userland DTrace support found in FreeBSD 9.0
.    endif
.  endif

.  if ${PORT_OPTIONS:MPAM}
CONFIGURE_ARGS+=--with-pam
.  endif

.  if ${PORT_OPTIONS:MLDAP}
CONFIGURE_ARGS+=--with-ldap
USE_OPENLDAP=	yes
.  endif

.  if ${PORT_OPTIONS:MXML}
CONFIGURE_ARGS+=--with-libxml
LIB_DEPENDS+=	xml2.5:${PORTSDIR}/textproc/libxml2
.  endif

.  if ${PORT_OPTIONS:MTZDATA}
PLIST_SUB+=	TZDATA=""
.  else
CONFIGURE_ARGS+=--with-system-tzdata=/usr/share/zoneinfo
PLIST_SUB+=	TZDATA="@comment "
.  endif

.  if ${PORT_OPTIONS:MINTDATE}
CONFIGURE_ARGS+=--enable-integer-datetimes
.  else
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
.    if exists(/usr/lib/libkrb5.so) || exists(/usr/bin/krb5-config)
IGNORE=	requires that you remove heimdal's /usr/bin/krb5-config and /usr/lib/libkrb5.so*, and set NO_KERBEROS=true in /etc/src.conf to build successfully with MIT-KRB
.    endif
# Allow defining a home built MIT Kerberos by setting KRB5_HOME
.    if defined(KRB5_HOME) && exists(${KRB5_HOME}/lib/libgssapi_krb5.a) && exists(${KRB5_HOME}/bin/krb5-config)
CONFIGURE_ARGS+=--with-krb5
.    else
LIB_DEPENDS+=	krb5.3:${PORTSDIR}/security/krb5
CONFIGURE_ARGS+=--with-krb5
.    endif
.  endif

.  if ${PORT_OPTIONS:MHEIMDAL_KRB5}
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
MAN1+=		clusterdb.1 createdb.1 createlang.1 createuser.1   \
		dropdb.1 droplang.1 dropuser.1 ecpg.1 initdb.1	   \
		pg_config.1 pg_controldata.1 pg_ctl.1   \
		pg_dump.1 pg_dumpall.1 pg_resetxlog.1 pg_restore.1 \
		postgres.1 postmaster.1 psql.1 reindexdb.1 vacuumdb.1

MAN7?=		alter_foreign_data_wrapper.7 alter_server.7 \
		alter_operator_family.7 				      \
		alter_text_search_configuration.7			      \
		alter_text_search_dictionary.7				      \
		alter_text_search_parser.7				      \
		alter_text_search_template.7				      \
		alter_user_mapping.7 alter_view.7			      \
		create_foreign_data_wrapper.7 create_server.7		      \
		create_operator_family.7 create_user_mapping.7		      \
		create_text_search_configuration.7			      \
		create_text_search_dictionary.7				      \
		create_text_search_parser.7				      \
		create_text_search_template.7				      \
		drop_text_search_configuration.7			      \
		drop_text_search_dictionary.7				      \
		drop_text_search_parser.7				      \
		drop_text_search_template.7 				      \
		discard.7 drop_foreign_data_wrapper.7 drop_server.7	      \
		drop_operator_family.7 drop_user_mapping.7		      \
		table.7 with.7
MAN7+=		abort.7 alter_aggregate.7 alter_conversion.7 alter_database.7 \
		alter_domain.7 alter_function.7 alter_group.7		      \
		alter_index.7 alter_language.7 alter_operator_class.7	      \
		alter_role.7						      \
		alter_schema.7 alter_sequence.7 alter_table.7		      \
		alter_trigger.7 alter_user.7 analyze.7 begin.7		      \
		checkpoint.7 close.7 cluster.7 comment.7 commit.7	      \
		commit_prepared.7					      \
		copy.7 create_aggregate.7 create_cast.7			      \
		create_constraint_trigger.7 create_conversion.7		      \
		create_database.7 create_domain.7 create_function.7	      \
		create_group.7 create_index.7 create_language.7		      \
		create_operator.7 create_operator_class.7		      \
		create_role.7 create_rule.7 create_schema.7 create_sequence.7 \
		create_table.7 create_table_as.7 create_trigger.7	      \
		create_type.7 create_user.7 create_view.7 deallocate.7	      \
		declare.7 delete.7					      \
		drop_aggregate.7 drop_cast.7 drop_conversion.7		      \
		drop_database.7 drop_domain.7 drop_function.7		      \
		drop_group.7 drop_index.7 drop_language.7		      \
		drop_operator.7 drop_operator_class.7			      \
		drop_owned.7 drop_role.7 drop_rule.7			      \
		drop_schema.7 drop_sequence.7 drop_table.7 drop_trigger.7     \
		drop_type.7 drop_user.7 drop_view.7 end.7 execute.7	      \
		explain.7 fetch.7 grant.7 insert.7 listen.7 load.7	      \
		lock.7 move.7 notify.7 prepare.7 prepare_transaction.7	      \
		reassign_owned.7 reindex.7 reset.7			      \
		revoke.7 rollback.7 rollback_prepared.7 select.7	      \
		select_into.7 set.7					      \
		set_constraints.7 set_role.7 set_transaction.7 show.7	      \
		set_session_authorization.7 start_transaction.7		      \
		truncate.7 unlisten.7 update.7 vacuum.7			      \
		alter_operator.7 alter_tablespace.7 alter_type.7	      \
		create_tablespace.7 drop_tablespace.7			      \
		release_savepoint.7 rollback_to_savepoint.7		      \
		savepoint.7 values.7
.endif

PLIST_SUB+=	PG_USER=${PG_USER} \
		PG_GROUP=${PG_GROUP}
SUB_LIST+=	PG_GROUP=${PG_GROUP} \
		PG_USER=${PG_USER} \
		PG_UID=${PG_UID}

# For testing files in FILESDIR
.include <bsd.port.pre.mk>

.if !defined(NO_BUILD)
.if !target(pre-build)
pre-build:
.  if defined(SERVER_ONLY)
	@${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL
.  endif
	@ cd ${WRKSRC}/src/backend && ${SETENV} ${MAKE_ENV} ${GMAKE} symlinks
.endif

do-build:
	@ for dir in ${BUILD_DIRS}; do \
		cd ${WRKSRC}/$${dir} && ${SETENV} ${MAKE_ENV} ${GMAKE}; \
	done

.  if exists(${FILESDIR}/pkg-message${PKGNAMESUFFIX}.in)
SUB_FILES+=	pkg-message${PKGNAMESUFFIX}
PKGMESSAGE=	${WRKSRC}/pkg-message${PKGNAMESUFFIX}
.  endif
.  if exists(${FILESDIR}/pkg-install${PKGNAMESUFFIX}.in)
SUB_FILES+=	pkg-install${PKGNAMESUFFIX}
PLIST_SUB+=	PG_USER=${PG_USER}
.  endif
.endif

.if !defined(NO_BUILD)
post-patch:
.  if ${PORT_OPTIONS:MICU}
	@${REINPLACE_CMD} -E -e \
		"s|^(m4_if.*)2.6[0-9](.*Autoconf version )2.6[0-9]|\1${AUTOCONF_VERSION}\2${AUTOCONF_VERSION}|g" \
		${WRKSRC}/configure.in
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
	${MKDIR} ${PREFIX}/${PG_USER} && ${CHOWN} ${PG_USER}:${PG_GROUP} ${PREFIX}/${PG_USER}
.  endif # SERVER_ONLY
.  if defined(CLIENT_ONLY)
	@ cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${GMAKE} install-local
.  endif
	@ if [ -r ${PKGMESSAGE} ]; then \
		${MKDIR} ${DOCSDIR} ;\
		${INSTALL_DATA} ${PKGMESSAGE} ${DOCSDIR}/README${PKGNAMESUFFIX} ;\
		${CAT} ${PKGMESSAGE} ;\
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
