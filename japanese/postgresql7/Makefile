# New ports collection makefile for:	PostgreSQL
# Date created:		7 Jun 2000
# Whom:			Tomokatsu Saito <saito@a2z.co.jp>
#
# $FreeBSD$
#

PORTNAME=	postgresql
PORTVERSION=	7.1.3
CATEGORIES=	japanese databases
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/cmd/postgres/${PORTVERSION}/ \
	ftp://ftp.postgresql.org/pub/v${PORTVERSION}/ \
	${MASTER_SITE_RINGSERVER}
MASTER_SITE_SUBDIR=	misc/db/postgresql-jp/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	postgresql

PATCH_SITES=	ftp://ftp.net-newbie.com/pub/postgres/
PATCHFILES=	psqlj-7.1.2.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	saito@a2z.co.jp

BUILD_DEPENDS=	${PATCH}:${PORTSDIR}/devel/patch

.if ${MACHINE_ARCH} == "alpha"
BROKEN=		doesn\'t build on the alpha yet
.endif

INSTALLS_SHLIB=	YES
LDCONFIG_DIRS=	%%PREFIX%%/lib

PATCH=	${LOCALBASE}/bin/gpatch

PLIST=	${WRKDIR}/.PLIST.generated
USE_GMAKE=	YES
HAS_CONFIGURE=	YES
CONFIGURE_ARGS=	--enable-locale \
		--enable-syslog --with-CXX \
		--sysconfdir=${PREFIX}/etc/postgresql \
		--with-includes="${PREFIX}/include ${TCL_INCDIR} ${TK_INCDIR}" \
		--with-libraries=${PREFIX}/lib
.if defined(WITH_OLD_LAYOUT)
CONFIGURE_ARGS+=--docdir=${PREFIX}/share/doc --includedir=${PREFIX}/pgsql/include \
		--datadir=${PREFIX}/share \
		--with-template=`uname -s | ${TR} '[A-Z]' '[a-z]'` \
		--prefix=${PREFIX}/pgsql
PG_PREFIX=	pgsql/
PG_INCLUDE=	pgsql/include
LDCONFIG_DIRS=	%%PREFIX%%/pgsql/lib
MANPREFIX=	${PREFIX}/pgsql
.else
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--docdir=${PREFIX}/share/doc --includedir=${PREFIX}/include/pgsql
PG_PREFIX=""
PG_INCLUDE=	include/pgsql
.endif

PLIST_SUB=	PG_PREFIX="${PG_PREFIX}" PG_INCLUDE="${PG_INCLUDE}" WITH_TCL="${WITH_TCL}"

MAN1=		createdb.1 createlang.1 createuser.1 dropdb.1 droplang.1 \
		dropuser.1 ecpg.1 initdb.1 initlocation.1 ipcclean.1 pg_config.1 \
		pg_ctl.1 pg_dump.1 pg_dumpall.1 pg_passwd.1 pg_restore.1 \
		pgaccess.1 pgtclsh.1 pgtksh.1 postgres.1 postmaster.1 psql.1 \
		vacuumdb.1
MANL=		abort.l alter_group.l alter_table.l alter_user.l \
		begin.l checkpoint.l close.l cluster.l comment.l commit.l copy.l \
		create_aggregate.l create_constraint_trigger.l \
		create_database.l create_function.l create_group.l \
		create_index.l create_language.l create_operator.l \
		create_rule.l create_sequence.l create_table.l \
		create_table_as.l create_trigger.l create_type.l \
		create_user.l create_view.l declare.l delete.l \
		drop_aggregate.l drop_database.l drop_function.l \
		drop_group.l drop_index.l drop_language.l \
		drop_operator.l drop_rule.l drop_sequence.l \
		drop_table.l drop_trigger.l drop_type.l drop_user.l \
		drop_view.l end.l explain.l fetch.l grant.l insert.l \
		listen.l load.l lock.l move.l notify.l reindex.l \
		reset.l revoke.l rollback.l select.l select_into.l \
		set.l set_constraints.l set_transaction.l show.l \
		truncate.l unlisten.l update.l vacuum.l

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		WRKDIR="${WRKDIR}" \
		FILESDIR="${FILESDIR}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \
		NO_OPENSSL="${NO_OPENSSL}" \
		DISTNAME="${DISTNAME}"

# We must .include here because we need the Makefile.inc @ pre-install
# to determine the correct plist.
.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.else
# make utility targets like depends and describe happy
LIB_DEPENDS=	tcl80jp:${PORTSDIR}/japanese/tcl80 \
		tk80jp:${PORTSDIR}/japanese/tk80
.endif

pre-everything::
	@ ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.postgresql

pre-install:
	@ ${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/pkg-install ${PORTNAME} PRE-INSTALL
.if !defined(BATCH)
# remind folks twice for a while, so they really don't miss the layout shift
	@ ${SED} "s|/usr/local|${PREFIX}|g" < ${PKGMESSAGE} | head -n 25 | more -e
.endif
	@ ${CP} ${PKGDIR}/pkg-plist ${PLIST}
.if defined(WITHOUT_MULTIBYTE)
	@${CP} ${PLIST} ${PLIST}.nomulti ;\
	 ${GREP} -v bin/pg_encoding ${PLIST}.nomulti > ${PLIST}
.endif
.if defined(WITH_TCL)
	@ ${CP} ${PLIST} ${PLIST}.notcl ;\
	  ${CAT} ${PKGDIR}/${TCL_PLIST} ${PLIST}.notcl > ${PLIST} ;\
	  ${RM} ${PLIST}.notcl
.endif
.if defined(WITH_ODBC)
	@ ${CP} ${PLIST} ${PLIST}.noodbc ;\
	  ${CAT} ${PKGDIR}/pkg-plist.odbc ${PLIST}.noodbc > ${PLIST} ;\
	  ${RM} ${PLIST}.noodbc
.endif
.if defined(WITH_JDBC)
	@ ${CP} ${PLIST} ${PLIST}.nojdbc ;\
	  ${CAT} ${PKGDIR}/pkg-plist.jdbc ${PLIST}.nojdbc > ${PLIST} ;\
	  ${RM} ${PLIST}.nojdbc
.endif
.if !defined(NOPORTDOCS)
	@ ${CAT} ${PKGDIR}/pkg-plist.doc >> ${PLIST}
.endif

post-install:
# install shell defaults for pgsql user
.for i in profile cshrc
	@ ${SED} "s|%%PREFIX%%|${PREFIX}|g; s|%%PG_PREFIX%%|${PG_PREFIX}|g" \
		< ${FILESDIR}/dot.$i.in \
		> ${PREFIX}/share/postgresql/dot.$i.dist; \
	${CP} ${PREFIX}/share/postgresql/dot.$i.dist ~pgsql/; \
	if [ ! -f ~pgsql/.$i ]; then \
		${CP} ${PREFIX}/share/postgresql/dot.$i.dist ~pgsql/.$i; \
	fi
.endfor
	@ ${SED} -e "s|%%PREFIX%%|${PREFIX}|g; s|%%PG_PREFIX%%|${PG_PREFIX}|g" \
		< ${FILESDIR}/pgsql.sh.tmpl \
		> ${PREFIX}/etc/rc.d/010.pgsql.sh
	@ ${CHMOD} 554 ${PREFIX}/etc/rc.d/010.pgsql.sh
	@ ${CHOWN} root:pgsql ${PREFIX}/etc/rc.d/010.pgsql.sh
.if defined(WITH_TCL)
# Preparing a loadable TCL-package (pkgIndex.tcl)
	@${MKDIR} ${PREFIX}/lib/tcl${WITH_TCL}/Pgtcl1.3
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${FILESDIR}/pkgIndex.tcl.in \
		> ${PREFIX}/lib/tcl${WITH_TCL}/Pgtcl1.3/pkgIndex.tcl
.endif
.if defined(WITH_JDBC)
	@ ${MKDIR} -m 0555 ${PREFIX}/share/java/classes
	@ ${INSTALL_DATA} ${WRKSRC}/src/interfaces/jdbc/jars/postgresql.jar \
			  ${PREFIX}/share/java/classes/postgresql.jar
	@ ${ECHO_MSG} "---------------------------------------------------------"
	@ ${ECHO_MSG} "Putting postgresql.jar in"
	@ ${ECHO_MSG} "${PREFIX}/share/java/classes/postgresql.jar"
	@ ${ECHO_MSG} "Add this to your CLASSPATH!"
	@ ${ECHO_MSG} "ALSO NOTE: path inside jar file modified from 6.5.x:"
	@ ${ECHO_MSG} "  'postgresql.*' -> 'org.postgresql.*'!"
	@ ${ECHO_MSG} "---------------------------------------------------------"
.if !defined(NOPORTDOCS)
	@ ${MKDIR} -m 0555 ${PREFIX}/share/examples/postgresql ;\
	  cd ${WRKSRC}/src/interfaces/jdbc/example ;\
	  pax -rw . ${PREFIX}/share/examples/postgresql
.for i in README Implementation
	@ ${INSTALL_DATA} ${WRKSRC}/src/interfaces/jdbc/$i \
			  ${PREFIX}/share/examples/postgresql
.endfor
	@ ${ECHO_MSG} "---------------------------------------------------------------"
	@ ${ECHO_MSG} "Putting java examples into ${PREFIX}/share/examples/postgresql"
	@ ${ECHO_MSG} "---------------------------------------------------------------"
.endif
.endif
.if !defined(DEBUG_FLAGS)
.for file in ecpg pg_dump pg_id pg_passwd pg_restore postgres psql
	@ strip ${PREFIX}/${PG_PREFIX}bin/${file}
.endfor
.endif
# information overload mode activated, sorry about this... ;-)
	@ ${CAT} ${FILESDIR}/post-install-notes ${PKGMESSAGE} |\
		${SED} "s|/usr/local|${PREFIX}|g" |\
		tee ${PREFIX}/share/postgresql/post-install-notes ;\
	${INSTALL_DATA} ${PREFIX}/share/postgresql/post-install-notes ~pgsql/. ;\
	${CHOWN} -R pgsql:pgsql ~pgsql/.
.if defined(WITH_OLD_LAYOUT)
	@ ${CHOWN} root:pgsql ${PREFIX}/${PG_PREFIX}lib
.endif

post-clean:
	@ ${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

post-extract: ${POSTEXTRACT}

.include <bsd.port.mk>
