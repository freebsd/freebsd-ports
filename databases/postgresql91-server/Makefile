# New ports collection makefile for:	PostgreSQL
# Version required:	6.2.1
# Date created:		April 2, 1997
# Whom:			Marc G. Fournier <scrappy@FreeBSD.ORG>
#
# $Id: Makefile,v 1.24 1998/04/21 21:51:51 andreas Exp $
#

DISTNAME=	postgresql-6.3.2
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.postgresql.org/pub/

MAINTAINER=	andreas@FreeBSD.ORG

# if you want to use the tcl/tk frontend pgaccess, then you need to build
# postgresql with tcl support by typing: make USE_TCL=yes
.if defined(USE_TCL)
MAKE_ENV=	USE_TCL=true TCL_INCDIR=${PREFIX}/include/tcl8.0
LIB_DEPENDS=	tcl80\\.1\\.:${PORTSDIR}/lang/tcl80
WITH_TCL=	--with-tcl
.endif

NO_PACKAGE=	"Requires pgsql uid"
WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_GMAKE=	YES
MAKEFILE=	GNUmakefile
HAS_CONFIGURE=	YES
CONFIGURE_ARGS= --prefix=${PREFIX}/pgsql \
		--enable-locale \
		--with-template=`uname -s | ${TR} '[A-Z]' '[a-z]'` \
		--with-includes=/usr/local/include ${WITH_TCL} \
		--with-libraries=/usr/local/lib

MAN1=		cleardbdir.1 createdb.1 createuser.1 destroydb.1 \
		destroyuser.1 ecpg.1 initdb.1 ipcclean.1 initlocation.1 \
		pg_dump.1 pg_dumpall.1 pg_passwd.1 pgintro.1 postgres.1 \
		postmaster.1 psql.1
MAN3=		catalogs.3 large_objects.3 libpq.3 oracle_compat.3 pgbuiltin.3
MAN5=		bki.5 page.5 pg_hba.conf.5
MANL=		abort.l alter_table.l alter_user.l begin.l close.l cluster.l \
		commit.l copy.l create_aggregate.l create_database.l \
		create_function.l create_index.l create_language.l \
		create_operator.l create_rule.l create_sequence.l \
		create_table.l create_trigger.l create_type.l create_user.l \
		create_version.l create_view.l declare.l delete.l drop.l \
		drop_aggregate.l drop_database.l drop_function.l drop_index.l \
		drop_language.l drop_operator.l drop_rule.l drop_sequence.l \
		drop_table.l drop_trigger.l drop_type.l drop_user.l \
		drop_view.l end.l explain.l fetch.l grant.l insert.l listen.l \
		load.l lock.l move.l notify.l reset.l revoke.l \
		rollback.l select.l set.l show.l sql.l update.l vacuum.l

MANPREFIX=	${PREFIX}/pgsql

pre-fetch:
.if !defined(USE_TCL)
	@${ECHO_MSG} "To build the \"PostgreSQL to Tcl interface library\", libpgtcl, type:"
	@${ECHO_MSG} "    make USE_TCL=yes"
.else
	@${ECHO_MSG} "Building PostgreSQL with \"libpgtcl\"."
.endif

post-build:
	@ ${ECHO} "------------------------------------------------------------"
	@ ${ECHO} "Dump existing databases, before installing new db version !!"
	@ ${ECHO} "Detailed instructions, see INSTALL file under ${WRKDIR}...  "
	@ ${ECHO} "------------------------------------------------------------"

pre-install:
.if defined(PACKAGE_BUILDING)
	/bin/rm -rf ${PREFIX}/pgsql
.endif
	@ ${MKDIR} ${PREFIX}/pgsql
	@ ${SETENV} ${MAKE_ENV} perl ${SCRIPTDIR}/createuser

post-install:
	@ if [ ! -f ${PREFIX}/pgsql/.profile ]; then \
		${ECHO} "PATH=${PATH}:${PREFIX}/pgsql/bin" \
			> ${PREFIX}/pgsql/.profile; \
		${ECHO} "MANPATH=${MANPATH}:${PREFIX}/pgsql/bin" \
			>> ${PREFIX}/pgsql/.profile; \
		${ECHO} "PGLIB=${PREFIX}/pgsql/lib" \
			>> ${PREFIX}/pgsql/.profile; \
		${ECHO} "# note: PGDATA overwrites the -D startup option" \
			>> ${PREFIX}/pgsql/.profile; \
		${ECHO} "PGDATA=${PREFIX}/pgsql/data" \
			>> ${PREFIX}/pgsql/.profile; \
		${ECHO} "DISPLAY=:0" \
			>> ${PREFIX}/pgsql/.profile; \
		${ECHO} "export PATH MANPATH PGLIB PGDATA DISPLAY" \
			>> ${PREFIX}/pgsql/.profile; \
		${ECHO} "# if you want to make regression tests use this TZ" \
			>> ${PREFIX}/pgsql/.profile; \
		${ECHO} "#TZ=PST8PDT" \
			>> ${PREFIX}/pgsql/.profile; \
		${ECHO} "#export TZ" \
			>> ${PREFIX}/pgsql/.profile; \
	fi
	@ chown -R pgsql:pgsql ${PREFIX}/pgsql
	@ ${ECHO} 'Initializing PostgreSQL Databases - this may take a few minutes...'
	@ ${LDCONFIG} -m ${PREFIX}/pgsql/lib
	@ su -l pgsql -c '${PREFIX}/pgsql/bin/initdb --pglib=${PREFIX}/pgsql/lib --pgdata=${PREFIX}/pgsql/data'
	@ ${SED} -e "s=!!PREFIX!!=${PREFIX}=g" < ${FILESDIR}/pgsql.sh.tmpl \
		> ${PREFIX}/etc/rc.d/pgsql.sh
	@ chmod 554 ${PREFIX}/etc/rc.d/pgsql.sh
	@ chown root.pgsql ${PREFIX}/etc/rc.d/pgsql.sh
	@ ${INSTALL_DATA} ${FILESDIR}/post-install-notes ${PREFIX}/pgsql
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/pgsql
	${CP} -r ${WRKDIR}/${DISTNAME}/doc/* ${PREFIX}/share/doc/pgsql
.endif
.if !defined(BATCH)
	@ more -e ${FILESDIR}/post-install-notes
.endif

.include <bsd.port.mk>
