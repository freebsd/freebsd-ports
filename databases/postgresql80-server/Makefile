# New ports collection makefile for:	PostgreSQL
# Date created:		November 13, 1998
# Whom:			Marc G. Fournier <scrappy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	postgresql
PKGNAMESUFFIX?=	-server
PORTVERSION?=	7.4.6
PORTREVISION?=	0
CATEGORIES?=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR=	source/v${PORTVERSION}
DISTFILES?=	postgresql-base-${PORTVERSION}${EXTRACT_SUFX} \
		postgresql-opt-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER?=	girgen@FreeBSD.org
COMMENT?=	The most advanced open-source database available anywhere

# XXX: this will eventually go away
.if !defined(PGSQL_WORK_IN_PROGRESS)
BROKEN=	You almost certainly do not want to be here right now
.endif

CONFLICTS?=	${PORTNAME}${PKGNAMESUFFIX}-7.[0-35-9]* \
		${PORTNAME}${PKGNAMESUFFIX}-8.*

WRKSRC=		${WRKDIR}/postgresql-${PORTVERSION}
DIST_SUBDIR=	postgresql

PKGINSTALL?=	${PKGDIR}/pkg-install${PKGNAMESUFFIX}
USE_BZIP2=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
.if defined(NO_BUILD)
.undef USE_GMAKE
.undef GNU_CONFIGURE
.endif

CONFIGURE_ARGS?=--with-libraries=${LOCALBASE}/lib \
		--with-includes=${LOCALBASE}/include
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"

PLIST=		${PKGDIR}/pkg-plist${PKGNAMESUFFIX}

BUILD_DIRS?=	src/backend src/backend/utils/mb/conversion_procs src/pl
INSTALL_DIRS?=	${BUILD_DIRS}
PKGMESSAGE=	${WRKDIR}/.pkg-message${PKGNAMESUFFIX}

.if !defined(CLIENT_ONLY) && !defined(SLAVE_ONLY)
SERVER_ONLY=	yes
USE_RC_SUBR=	yes
RCSCRIPT=	${PREFIX}/etc/rc.d/postgresql.sh
USE_PGSQL=	yes
WANT_PGSQL_VER=	${PORTVERSION:C/([0-9][0-9]*)\.([0-9][0-9]*).*/\1\2/g}
.endif

.if !defined(SLAVE_ONLY)
OPTIONS=	NLS "Use internationalized messages" on
OPTIONS+=	SSL "Build with SSL" on
.endif

.include <bsd.port.pre.mk>

.if !defined(SLAVE_ONLY)
# gnugetopt will always be used if already installed
.  if ${OSVERSION} < 500041
OPTIONS+=	GNUGETOPT "Depend on GNU getopt" on
.  endif
.  if defined(SERVER_ONLY)
OPTIONS+=	PAM "Build with PAM support" off
.  endif
OPTIONS+=	MIT_KRB5 "Build with MIT's kerberos support" off
OPTIONS+=	HEIMDAL_KRB5 "Builds with Heimdal's kerberos support" off
OPTIONS+=	OPTIMIZED_CFLAGS "Builds with compiler optimizations (-O3)" off
.  if defined(SERVER_ONLY)
OPTIONS+=	LIBC_R "Link with libc_r, needed by plpython" off
#  to run regression tests:
OPTIONS+=	TESTS "Allows the use of a \"check\" target" off
.  endif
OPTIONS+=	DEBUG "Builds with debugging symbols" off

.  if defined(SERVER_ONLY) && defined(WITH_PAM)
CONFIGURE_ARGS+=	--with-pam
.  endif

. if !defined(WITHOUT_GNUGETOPT)
USE_GETOPT_LONG=yes
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
CONFIGURE_ARGS+=	--enable-debug
INSTALL_TARGET=	install
.  else
INSTALL_TARGET=	install-strip
.  endif

.  if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	"--with-openssl=${OPENSSLBASE}"
.  endif

.  if defined(WITH_MIT_KRB5)
KRB5CONF=	${KRB5_HOME}/bin/krb5-config
LIB_DEPENDS+=	krb5.3:${PORTSDIR}/security/krb5
WITH_KRB5=	yes
.  endif

.  if defined(WITH_HEIMDAL_KRB5)
WITH_KRB5=	yes
.    if defined(HEIMDAL_HOME) && exists(${HEIMDAL_HOME}/lib/libgssapi.a)
CONFIGURE_ARGS+=	--with-krb5=${HEIMDAL_HOME}
KRB5CONF=	${HEIMDAL_HOME}/bin/krb5-config
.    elif ( defined(MAKE_KERBEROS5) || ${OSVERSION} > 500105 ) && exists(${DESTDIR}/usr/lib/libkrb5.a)
CONFIGURE_ARGS+=	--with-krb5=${DESTDIR}/usr
KRB5CONF=	${DESTDIR}/usr/bin/krb5-config
.    else
LIB_DEPENDS+=	krb5:${PORTSDIR}/security/heimdal
CONFIGURE_ARGS+=	--with-krb5=${LOCALBASE}
KRB5CONF=	${LOCALBASE}/bin/krb5-config
.    endif
.  endif

.  if defined(WITH_KRB5)
CONFIGURE_ARGS+=	--with-krb5="`${KRB5CONF} --prefix krb5`"
LDFLAGS+=	`${KRB5CONF} --libs krb5`
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"
.  endif

.  if defined(SERVER_ONLY) && defined(WITH_TESTS)
DISTFILES+=	postgresql-test-${PORTVERSION}${EXTRACT_SUFX}
.  endif

.  if defined(SERVER_ONLY) && defined(WITH_LIBC_R)
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
.  endif

.  if defined(WITH_MIT_KRB5) && defined(WITH_HEIMDAL_KRB5)
	@${ECHO} "WITH_MIT_KRB5 and WITH_HEIMDAL_KRB5 are mutually exclusive."
	@${ECHO} "Please choose one or the other."
	@exit 1
.  endif
.  if defined(WITH_MIT_KRB5) && !exists(${KRB5CONF})
	@${ECHO} "Unable to find krb5-config in your local base, please verify that"
	@${ECHO} "security/krb5 is installed or undefine the WITH_MIT_KRB5 tunable."
	@exit 1
.  endif
.  if defined(WITH_HEIMDAL_KRB5) && !exists(${KRB5CONF})
	@${ECHO} "Unable to find krb5-config in the base system.  Undefine"
	@${ECHO} "WITH_HEIMDAL_KRB5 or add MAKE_KERBEROS5=yes to /etc/make.conf"
	@${ECHO} "and remake world."
	@exit 1
.  endif

.endif # !SLAVE_ONLY

.if defined(CLIENT_ONLY)
MAN1=		clusterdb.1 createdb.1 createlang.1 createuser.1 dropdb.1 \
		droplang.1 dropuser.1 ecpg.1 initdb.1 initlocation.1 ipcclean.1 \
		pg_config.1 pg_controldata.1 pg_ctl.1 pg_dump.1 pg_dumpall.1 \
		pg_resetxlog.1 pg_restore.1 pgtclsh.1 pgtksh.1 postgres.1 \
		postmaster.1 psql.1 vacuumdb.1

MAN7=		abort.7 alter_aggregate.7 alter_conversion.7 \
		alter_database.7 alter_domain.7 alter_function.7 \
		alter_group.7 alter_language.7 alter_operator_class.7 \
		alter_schema.7 alter_sequence.7 alter_table.7 \
		alter_trigger.7 alter_user.7 analyze.7 begin.7 checkpoint.7 \
		close.7 cluster.7 comment.7 commit.7 copy.7 create_aggregate.7 \
		create_cast.7 create_constraint_trigger.7 create_conversion.7 \
		create_database.7 create_domain.7 create_function.7 create_group.7 \
		create_index.7 create_language.7 create_operator.7 \
		create_operator_class.7 create_rule.7 create_schema.7 \
		create_sequence.7 create_table.7 create_table_as.7 \
		create_trigger.7 create_type.7 create_user.7 create_view.7 \
		deallocate.7 declare.7 delete.7 drop_aggregate.7 \
		drop_cast.7 drop_conversion.7 drop_database.7 drop_domain.7 \
		drop_function.7 drop_group.7 drop_index.7 drop_language.7 \
		drop_operator.7 drop_operator_class.7 drop_rule.7 drop_schema.7 \
		drop_sequence.7 \
		drop_table.7 drop_trigger.7 drop_type.7 drop_user.7 \
		drop_view.7 end.7 execute.7 explain.7 fetch.7 grant.7 insert.7 \
		listen.7 load.7 lock.7 move.7 notify.7 prepare.7 reindex.7 \
		reset.7 revoke.7 rollback.7 select.7 select_into.7 \
		set.7 set_constraints.7 set_transaction.7 show.7 \
		set_session_authorization.7 start_transaction.7 \
		truncate.7 unlisten.7 update.7 vacuum.7
.endif

.if defined(SERVER_ONLY)
pre-everything::
	@${SH} ${PKGINSTALL} ${PORTNAME} BACKUPWARNING
.endif

.if !defined(NO_BUILD)
do-build:
	@ cd ${WRKSRC}/src/backend ;\
	${GMAKE} ../../src/include/parser/parse.h ../../src/include/utils/fmgroids.h
	@ for dir in ${BUILD_DIRS}; do \
		cd ${WRKSRC}/$${dir} && ${SETENV} ${MAKE_ENV} ${GMAKE}; \
	done

.  if exists(${MASTERDIR}/pkg-message${PKGNAMESUFFIX})
post-build:
	@ ${SED} "s|/usr/local|${PREFIX}|g" \
		< ${MASTERDIR}/pkg-message${PKGNAMESUFFIX} \
		> ${PKGMESSAGE}
.  endif
.endif

.if defined(SERVER_ONLY)
pre-install:
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL
.endif

.if !defined(NO_BUILD)
do-install:
	@for dir in ${INSTALL_DIRS}; do \
	    cd ${WRKSRC}/$${dir} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${INSTALL_TARGET}; \
	done
	${MKDIR} ${PREFIX}/share/postgresql
.  if defined(SERVER_ONLY)
	@ cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} install-all-headers
.  for i in profile cshrc
	@ ${SED} "s|%%PREFIX%%|${PREFIX}|g" \
		< ${FILESDIR}/dot.$i.in \
		> ${PREFIX}/share/postgresql/dot.$i.dist; \
	${CP} ${PREFIX}/share/postgresql/dot.$i.dist ~pgsql/; \
	if [ ! -f ~pgsql/.$i ]; then \
		${CP} ${PREFIX}/share/postgresql/dot.$i.dist ~pgsql/.$i; \
	fi
.  endfor
	@ ${SED} -e "s|%%PREFIX%%|${PREFIX}|g; s|%%RC_SUBR%%|${RC_SUBR}|g" \
		< ${FILESDIR}/pgsql.sh.tmpl \
		> ${RCSCRIPT} ;\
	${CHMOD} 554 ${RCSCRIPT} ;\
	${CHOWN} root:pgsql ${RCSCRIPT} ;\
	${CHOWN} -R pgsql:pgsql ~pgsql/. ;\
	${MKDIR} ${PREFIX}/etc/periodic/daily ;\
	${INSTALL_DATA} ${FILESDIR}/502.pgsql \
			${PREFIX}/etc/periodic/daily
.  endif # SERVER_ONLY
	@ if [ -r ${PKGMESSAGE} ]; then \
		${INSTALL_DATA} ${PKGMESSAGE} ${PREFIX}/share/postgresql/README${PKGNAMESUFFIX} ;\
		${ECHO} "======================================================================" ;\
		${CAT} ${PKGMESSAGE} ;\
		${ECHO} "======================================================================" ;\
	fi
.endif # !NO_BUILD

.if defined(SERVER_ONLY) && defined(WITH_TESTS)
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
