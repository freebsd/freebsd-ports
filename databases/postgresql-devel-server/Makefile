# New ports collection makefile for:	PostgreSQL
# Date created:		November 13, 1998
# Whom:			Marc G. Fournier <scrappy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	postgresql
PORTVERSION?=	7.4.1
PORTREVISION?=	1
CATEGORIES?=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR=	source/v${PORTVERSION}
DISTFILES=	postgresql-base-${PORTVERSION}${EXTRACT_SUFX} \
		postgresql-opt-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER?=	girgen@pingpong.net
COMMENT?=	The most advanced open-source database available anywhere

WRKSRC=		${WRKDIR}/postgresql-${PORTVERSION}
DIST_SUBDIR=	postgresql

USE_BZIP2=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES

.if defined(POSTGRESQL_SUBPORT)
## the POSTGRESQL_SUBPORTS use this port's distinfo
MD5_FILE=	${.CURDIR}/../postgresql7/distinfo
.else

## POSTGRESQL_SUBPORTS stops here
## The rest of this file is for normal base installation
INSTALLS_SHLIB=	YES

CONFIGURE_ARGS=	--with-libraries=${LOCALBASE}/lib \
		--with-includes=${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"

.if defined(WITH_PAM)
CONFIGURE_ARGS+=	--with-pam
.endif

.if !defined(WITHOUT_GNUGETOPT)
USE_GETOPT_LONG=yes
.endif

.if !(defined(WITHOUT_GETTEXT) || defined(WITHOUT_NLS))
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	GETTEXT=""
USE_GETTEXT=	YES
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	GETTEXT="@comment "
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -funroll-loops
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
INSTALL_TARGET=	install
.else
INSTALL_TARGET=	install-strip
.endif

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	"--with-openssl=${OPENSSLBASE}"
.endif

.if defined(WITHOUT_SERVER)
PLIST_SUB+=	SERVER="@comment "
PKGNAMESUFFIX=	-client
PKGMSG=		/dev/null
CONFLICTS=	postgresql-7* postgresql-devel-*
.else
PKGMESSAGE=	${FILESDIR}/pkg-message.server
PKGMSG=		${PKGMESSAGE}
CONFLICTS=	postgresql-client-7* postgresql-devel-*
PLIST_SUB+=	SERVER=""
INSTALL_TARGET+=	install-all-headers
MAKEFILE=	GNUmakefile
.endif

.if defined(WITH_MIT_KRB5)
KRB5CONF=	${KRB5_HOME}/bin/krb5-config
LIB_DEPENDS+=	krb5.3:${PORTSDIR}/security/krb5
WITH_KRB5=	yes
.endif

.if defined(WITH_HEIMDAL_KRB5)
KRB5CONF=	/usr/bin/krb5-config
WITH_KRB5=	yes
.endif

.include <bsd.port.pre.mk>
.if defined(WITH_KRB5)
CONFIGURE_ARGS+=	--with-krb5="`${KRB5CONF} --prefix krb5`"
LDFLAGS+=	`${KRB5CONF} --libs krb5`
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"
.endif

.if defined(WITH_TESTS)
DISTFILES+=	postgresql-test-${PORTVERSION}${EXTRACT_SUFX}
.endif

.if defined(WITH_LIBC_R)
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
.endif

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

pre-everything::
	@${SH} ${PKGINSTALL} ${PORTNAME} BACKUPWARNING
	@${ECHO} ""
	@${ECHO} "${PORTNAME} has several tunables that can be used to configure PostgreSQL:"
	@${ECHO} ""
	@${ECHO} "	WITHOUT_GNUGETOPT	Don't install GNU getopt (will"
	@${ECHO} "				still be used if already installed)"
	@${ECHO} "	WITHOUT_NLS		Skips building with support for"
	@${ECHO} "				internationalized error messages"
	@${ECHO} "	WITHOUT_SERVER		Don't install the server,"
	@${ECHO} "				only install binaries, headers and libs"
	@${ECHO} "				for PostgreSQL clients"
	@${ECHO} "	WITHOUT_SSL		Builds without OpenSSL support"
	@${ECHO} "	WITH_PAM		Builds with PAM support"
	@${ECHO} "	WITH_MIT_KRB5		Builds with MIT's kerberos support"
	@${ECHO} "	WITH_HEIMDAL_KRB5	Builds with Heimdal's kerberos support"
	@${ECHO} "	WITH_OPTIMIZED_CFLAGS	Builds with compiler optimizations (-O3)"
	@${ECHO} "	WITH_DEBUG		Builds with debugging symbols"
	@${ECHO} "	WITH_TESTS		Allows the use of a \"check\" target"
	@${ECHO} "				to run regression tests"
	@${ECHO} "	WITH_LIBC_R		Link the binaries with libc_r."
	@${ECHO} "				Needed to run plpython"
	@${ECHO} ""
.if defined(WITH_MIT_KRB5) && defined(WITH_HEIMDAL_KRB5)
	@${ECHO} "WITH_MIT_KRB5 and WITH_HEIMDAL_KRB5 are mutually exclusive."
	@${ECHO} "Please choose one or the other."
	@exit 1
.endif
.if defined(WITH_MIT_KRB5) && !exists(${KRB5CONF})
	@${ECHO} "Unable to find krb5-config in your local base, please verify that"
	@${ECHO} "security/krb5 is installed or undefine the WITH_MIT_KRB5 tunable."
	@exit 1
.endif
.if defined(WITH_HEIMDAL_KRB5) && !exists(${KRB5CONF})
	@${ECHO} "Unable to find krb5-config in the base system.  Undefine"
	@${ECHO} "WITH_HEIMDAL_KRB5 or add MAKE_KERBEROS5=yes to /etc/make.conf"
	@${ECHO} "and remake world."
	@exit 1
.endif

.if defined(WITHOUT_SERVER)
do-install:
	@ cd ${WRKSRC}; \
	${GMAKE} -C src/bin ${INSTALL_TARGET} ;\
	${GMAKE} -C src/include ${INSTALL_TARGET} ;\
	${GMAKE} -C src/interfaces ${INSTALL_TARGET} ;\
	${GMAKE} -C doc ${INSTALL_TARGET}
.else
pre-install:
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL
.endif

post-install:
	@ ${MKDIR} ${PREFIX}/share/postgresql ;\
	${CAT} ${FILESDIR}/post-install-notes ${PKGMSG} |\
		${SED} "s|/usr/local|${PREFIX}|g" |\
		tee ${PREFIX}/share/postgresql/post-install-notes
.if !defined(WITHOUT_SERVER)
.for i in profile cshrc
	@ ${SED} "s|%%PREFIX%%|${PREFIX}|g" \
		< ${FILESDIR}/dot.$i.in \
		> ${PREFIX}/share/postgresql/dot.$i.dist; \
	${CP} ${PREFIX}/share/postgresql/dot.$i.dist ~pgsql/; \
	if [ ! -f ~pgsql/.$i ]; then \
		${CP} ${PREFIX}/share/postgresql/dot.$i.dist ~pgsql/.$i; \
	fi
.endfor
	@ ${SED} -e "s|%%PREFIX%%|${PREFIX}|g; s|%%PG_PREFIX%%|${PG_PREFIX}|g" \
		< ${FILESDIR}/pgsql.sh.tmpl \
		> ${PREFIX}/etc/rc.d/010.pgsql.sh ;\
	${CHMOD} 554 ${PREFIX}/etc/rc.d/010.pgsql.sh ;\
	${CHOWN} root:pgsql ${PREFIX}/etc/rc.d/010.pgsql.sh ;\
	${INSTALL_DATA} ${PREFIX}/share/postgresql/post-install-notes ~pgsql/. ;\
	${CHOWN} -R pgsql:pgsql ~pgsql/. ;\
	${INSTALL_DATA} ${FILESDIR}/502.pgsql \
			${PREFIX}/share/postgresql
.endif

.if defined(WITH_TESTS)
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
.endif
