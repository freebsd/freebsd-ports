# New ports collection makefile for:	PostgreSQL
# Version required:	6.4
# Date created:		November 13, 1998
# Whom:			Marc G. Fournier <scrappy@FreeBSD.ORG>
#
# $Id: Makefile,v 1.31 1998/12/23 17:37:03 billf Exp $
#

DISTNAME=	postgresql-v6.4
PKGNAME=	postgresql-6.4
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.postgresql.org/pub/

MAINTAINER=	andreas@FreeBSD.ORG

Y2K=		http://www.postgresql.org/y2k.html

# if you want to use the tcl/tk frontend pgaccess, then you need to build
# postgresql with tcl support by typing: make USE_TCL=yes
.if defined(USE_TCL)
TCL_INCDIR=	${PREFIX}/include/tcl8.0
TK_INCDIR=	${PREFIX}/include/tk8.0
MAKE_ENV=	USE_TCL=true TCL_INCDIR=${TCL_INCDIR}
LIB_DEPENDS=	tcl80.1:${PORTSDIR}/lang/tcl80 tk80.1:${PORTSDIR}/x11-toolkits/tk80
WITH_TCL=	--with-tcl --with-tclconfig="${PREFIX}/lib/tcl8.0 ${PREFIX}/lib/tk8.0"
.endif

NO_PACKAGE=	"Requires pgsql uid"
WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_GMAKE=	YES
MAKEFILE=	GNUmakefile
HAS_CONFIGURE=	YES
CONFIGURE_ARGS= --prefix=${PREFIX}/pgsql \
		--enable-locale \
		--with-template=`uname -s | ${TR} '[A-Z]' '[a-z]'` \
		--with-includes="/usr/local/include ${TCL_INCDIR} ${TK_INCDIR}" ${WITH_TCL} \
		--with-libraries=/usr/local/lib

INSTALL_TARGET= install install-man

MAN1=		cleardbdir.1 createdb.1 createuser.1 destroydb.1 \
		destroyuser.1 ecpg.1 initdb.1 initlocation.1 \
		ipcclean.1 pg_dump.1 pg_dumpall.1 pg_passwd.1 \
		pg_upgrade.1 postgres.1 postmaster.1 psql.1
MAN3=		catalogs.3 libpq.3
MAN5=		pg_hba.conf.5
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
		load.l lock.l move.l notify.l reset.l revoke.l rollback.l \
		select.l set.l show.l sql.l update.l vacuum.l

MANPREFIX=	${PREFIX}/pgsql

pre-fetch:
.if !defined(USE_TCL)
	@${ECHO_MSG} "To build the \"PostgreSQL to Tcl interface library\", libpgtcl, type:"
	@${ECHO_MSG} "    make USE_TCL=yes"
.else
	@${ECHO_MSG} "Building PostgreSQL with \"libpgtcl\"."
.endif

post-patch:

	@ ${MV} ${WRKSRC}/template/freebsd ${WRKSRC}/template/freebsd.orig
	@ ${SED} -e 's#CFLAGS:-O2 -m486 -pipe#CFLAGS:${CFLAGS}#' \
		-e 's#USE_LOCALE:no#USE_LOCALE:yes#' \
	${WRKSRC}/template/freebsd.orig >> ${WRKSRC}/template/freebsd

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
	@ ${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/pgsql/lib
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
