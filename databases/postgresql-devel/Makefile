# New ports collection makefile for:	PostgreSQL
# Date created:		November 13, 1998
# Whom:			Marc G. Fournier <scrappy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	postgresql
PORTVERSION?=	8.0.0
PORTEPOCH=	1
CATEGORIES?=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR=	source/v${PORTVERSION}
PATCH_SITES=	http://people.FreeBSD.org/~seanc/patches/pgsql/
PKGNAMESUFFIX=	-devel
DIST_SUBDIR=	postgresql

MAINTAINER?=	seanc@FreeBSD.org
COMMENT=	Development snapshots of PostgreSQL's latest features

CONFLICTS=	postgresql7*
CONFIGURE_ENV+=	DOCBOOKSTYLE=${LOCALBASE}/share/sgml/docbook/3.1/
USE_BZIP2=	YES
USE_GMAKE=	YES
USE_PERL5_BUILD=	YES
GNU_CONFIGURE=	YES

MAN1=	ecpg.1 clusterdb.1 createdb.1 createlang.1 createuser.1 dropdb.1 \
	droplang.1 dropuser.1 initdb.1 ipcclean.1 pg_config.1 pg_controldata.1 \
	pg_ctl.1 pg_dump.1 pg_dumpall.1 pg_resetxlog.1 pg_restore.1 postgres.1 \
	postmaster.1 psql.1 vacuumdb.1

MAN7=	reset.7 set.7 abort.7 alter_aggregate.7 alter_conversion.7 alter_database.7 \
	alter_domain.7 alter_function.7 alter_group.7 alter_index.7 alter_language.7 \
	alter_operator.7 alter_operator_class.7 alter_schema.7 alter_sequence.7 \
	alter_table.7 alter_tablespace.7 alter_trigger.7 alter_type.7 alter_user.7 \
	analyze.7 begin.7 checkpoint.7 close.7 cluster.7 comment.7 commit.7 copy.7 \
	create_aggregate.7 create_cast.7 create_constraint_trigger.7 \
	create_conversion.7 create_database.7 create_domain.7 create_function.7 \
	create_group.7 create_index.7 create_language.7 create_operator.7 \
	create_operator_class.7 create_rule.7 create_schema.7 end.7 create_sequence.7 \
	create_table.7 create_table_as.7 create_tablespace.7 create_trigger.7 \
	create_type.7 create_user.7 create_view.7 deallocate.7 declare.7 delete.7 \
	drop_aggregate.7 drop_cast.7 drop_conversion.7 drop_database.7 drop_domain.7 \
	drop_function.7 drop_group.7 drop_index.7 drop_language.7 drop_rule.7 \
	drop_operator.7 drop_operator_class.7 drop_schema.7 drop_sequence.7 \
	drop_table.7 drop_tablespace.7 drop_trigger.7 drop_type.7 drop_user.7 \
	drop_view.7 execute.7 explain.7 fetch.7 grant.7 insert.7 listen.7 load.7 \
	lock.7 move.7 notify.7 prepare.7 reindex.7 release_savepoint.7 revoke.7 \
	rollback.7 rollback_to_savepoint.7 savepoint.7 select.7 select_into.7 \
	set_constraints.7 set_session_authorization.7 set_transaction.7 show.7 \
	spi_connect.7 spi_copytuple.7 spi_cursor_close.7 spi_cursor_fetch.7 \
	spi_cursor_find.7 spi_cursor_move.7 spi_cursor_open.7 spi_exec.7 spi_execp.7 \
	spi_execute.7 spi_execute_plan.7 spi_finish.7 spi_fname.7 spi_fnumber.7 \
	spi_freeplan.7 spi_freetuple.7 spi_freetuptable.7 spi_getargcount.7 \
	spi_getargtypeid.7 spi_getbinval.7 spi_getrelname.7 spi_gettype.7 \
	spi_gettypeid.7 spi_getvalue.7 spi_is_cursor_plan.7 spi_modifytuple.7 \
	spi_palloc.7 spi_pfree.7 spi_pop.7 spi_prepare.7 spi_push.7 spi_repalloc.7 \
	spi_returntuple.7 spi_saveplan.7 start_transaction.7 truncate.7 unlisten.7 \
	update.7 vacuum.7


WRKSRC=		${WRKDIR}/postgresql-${PORTVERSION}
.if defined(POSTGRESQL_SUBPORT)
## the POSTGRESQL_SUBPORTS use this port's distinfo
MD5_FILE=	${.CURDIR}/../postgresql-devel/distinfo
.else

## POSTGRESQL_SUBPORTS stops here
## The rest of this file is for normal base installation
INSTALLS_SHLIB=	YES

BUILD_DEPENDS+=	bison1875:${PORTSDIR}/devel/bison1875
CONFIGURE_ARGS=	--with-libraries=${LOCALBASE}/lib \
		--with-includes=${LOCALBASE}/include \
		--with-docdir=${LOCALBASE}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

.if !defined(WITHOUT_GNUGETOPT)
USE_GETOPT_LONG=yes
.endif

.if !defined(WITHOUT_GETTEXT)
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	GETTEXT=""
USE_GETTEXT=	yes
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	GETTEXT="@comment "
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+= -O3 -funroll-loops
.endif

.if defined(WITH_PGBLOCKSIZE)
.if (${WITH_PGBLOCKSIZE} == "16K")
PATCHFILES+=	"patch-pgblocksize-16K"
.elif (${WITH_PGBLOCKSIZE} == "32K")
PATCHFILES+=	"patch-pgblocksize-32K"
.elif (${WITH_PGBLOCKSIZE} == "65K")
#	This block size doesn't work, for use by developers only!!!
PATCHFILES+=	"patch-pgblocksize-65K"
.endif
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
INSTALL_TARGET=	install
.else
INSTALL_TARGET=	install-strip
.endif

.if !defined(WITHOUT_PGCRYPTO)
PLIST_SUB+=	PGCRYPTO=""
.else
PLIST_SUB+=	PGCRYPTO="@comment "
.endif

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+= "--with-openssl"
.endif

.if defined(WITHOUT_SERVER)
PKGMESSAGE=	${PKGDIR}/pkg-message.client
PLIST_SUB+=	SERVER="@comment "
PKGNAMESUFFIX=	-client
.else
PLIST_SUB+=	SERVER=""
MAKEFILE=	GNUmakefile
.endif

.if defined(WITHOUT_SPINLOCKS)
CONFIGURE_ARGS+=	--disable-spinlocks
.endif

.if defined(WITH_CASSERT)
CONFIGURE_ARGS+=	--enable-cassert
.endif

.if defined(WITH_JDBC)
CONFIGURE_ARGS+=	--with-java
.endif

.if defined(WITH_KRB5)
CONFIGURE_ARGS+=	--with-krb5="`${KRB5CONF} --prefix krb5`"
LDFLAGS+=	`${KRB5CONF} --libs krb5`
.endif

.if defined(WITH_MIT_KRB5)
KRB5CONF=	${KRB5_HOME}/bin/krb5-config
WITH_KRB5=	yes
.endif

.if defined(WITH_HEIMDAL_KRB5)
KRB5CONF=	/usr/bin/krb5-config
LIB_DEPENDS+=	krb5.3:${PORTSDIR}/security/krb5
WITH_KRB5=	yes
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+= -O3 -funroll-loops
.endif

.if defined(WITH_PERL)
CONFIGURE_ARGS+=	--with-perl
.endif

.if defined(WITH_PYTHON)
CONFIGURE_ARGS+=	--with-python
.endif

.if defined(WITH_RENDEZVOUS)
CONFIGURE_ARGS+=	--with-rendezvous
.endif

.if defined(WITH_TCL)
CONFIGURE_ARGS+=	--with-tcl
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" && ${OSVERSION} < 500000
BROKEN=		"Coredump during build on alpha 4.x"
.endif

pre-everything::
	@${SH} ${PKGDIR}/pkg-install ${PORTNAME} BACKUPWARNING
	@${ECHO} ""
	@${ECHO} "${PORTNAME} has several tunables that can be used to configure PostgreSQL:"
	@${ECHO} ""
	@${ECHO} "	WITH_CASSERT		Builds with C Asserts (debug opt, slows perf)"
	@${ECHO} "	WITH_DEBUG		Builds with debugging symbols"
	@${ECHO} "	WITH_HEIMDAL_KRB5	Builds with Heimdal's kerberos support"
	@${ECHO} "	WITH_JDBC		Builds with JDBC support"
	@${ECHO} "	WITH_MIT_KRB5		Builds with MIT's kerberos support"
	@${ECHO} "	WITH_OPTIMIZED_CFLAGS	Builds with compiler optimizations (-O3)"
	@${ECHO} "	WITH_PERL		Builds with pl/Perl support"
	@${ECHO} "	WITH_PYTHON		Builds with pl/Python support"
	@${ECHO} "	WITH_PGBLOCKSIZE	It's possible to change the blocksize to \"16K\""
	@${ECHO} "				or \"32K\" (defaults to 8K and different"
	@${ECHO} "				block sizes require a dump, initdb, reload!)"
	@${ECHO} "	WITH_RENDEZVOUS		Builds with Rendezvous support"
	@${ECHO} "	WITH_TCL		Builds with pl/tcl support"
	@${ECHO} "	WITHOUT_GETTEXT		Skips building with support for"
	@${ECHO} "				internationalized error messages"
	@${ECHO} "	WITHOUT_GNUGETOPT	Don't install GNU getopt (will"
	@${ECHO} "				still be used if already installed)"
	@${ECHO} "	WITHOUT_PGCRYPTO	Builds without pgcrypto support"
	@${ECHO} "	WITHOUT_SERVER		Installs the headers and libraries for"
	@${ECHO} "				PostgreSQL clients"
	@${ECHO} "	WITHOUT_SPINLOCKS	Builds without spin locks"
	@${ECHO} "	WITHOUT_SSL		Builds without OpenSSL support"
	@${ECHO} ""
	@${ECHO} ""
	@${ECHO} "	*** IMPORTANT NOTE FOR USERS OF 8.0 via -devel ***"
	@${ECHO} ""
	@${ECHO} "	The -devel port will begin tracking 8.1 after PR ports/75344"
	@${ECHO} "	has been committed.  Please be smart about tracking ports and"
	@${ECHO} "	move to using databases/postgresql80-server when appropriate"
	@${ECHO} "	(no dump/reload will be required when changing from -devel to"
	@${ECHO} "	postgresql80-server)."
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
	@${ECHO} "and remake world (or undefine the WITH_HEIMDAL_KRB5 tunable)."
	@exit 1
.endif

.if !defined(WITHOUT_PGCRYPTO)
post-build:
	${GMAKE} -C ${WRKSRC}/contrib/pgcrypto
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
		${SH} ${PKGDIR}/pkg-install ${PORTNAME} PRE-INSTALL
.endif

post-install:
.if !defined(WITHOUT_PGCRYPTO)
	${GMAKE} -C ${WRKSRC}/contrib/pgcrypto install
.endif
	@ ${MKDIR} ${PREFIX}/share/postgresql ;\
	${CAT} ${FILESDIR}/post-install-notes ${PKGMESSAGE} |\
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

check:
	@if [ `id -u` != 0 ] ; then \
		${ECHO} "Running postgresql regressions tests" ;\
		cd ${WRKSRC}; ${GMAKE} check ;\
	else \
		${ECHO} "You cannot run regression tests when postgresql is built as user root." ; \
		${ECHO} "Clean and rebuild the port as a regular user to run the tests." ;\
	fi

.include <bsd.port.post.mk>
.endif
