# New ports collection makefile for:	PostgreSQL
# Date created:		November 13, 1998
# Whom:			Marc G. Fournier <scrappy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	postgresql
PORTVERSION=	6.5.3
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.postgresql.org/pub/ \
		ftp://ftp.iodynamics.com/pub/mirror/postgresql/ \
		ftp://ftp.de.postgresql.org/ \
		ftp://ftp.digex.net/pub/packages/database/postgresql/ \
		ftp://ftp.sunet.se/pub/unix/databases/relational/postgresql/

MAINTAINER=	andreas@FreeBSD.org

.if ${MACHINE_ARCH} == "alpha"
BROKEN=		doesn\'t build on the alpha yet
.endif

Y2K=		http://www.postgresql.org/y2k.html

# if you want to use the tcl/tk frontend pgaccess, then you need to build
# postgresql with tcl support by typing: make USE_TCL=yes
.if defined(USE_TCL)
TCL_INCDIR=	${LOCALBASE}/include/tcl8.0
TK_INCDIR=	${LOCALBASE}/include/tk8.0
MAKE_ENV=	USE_TCL=true TCL_INCDIR=${TCL_INCDIR}
LIB_DEPENDS=	tcl80.1:${PORTSDIR}/lang/tcl80 tk80.1:${PORTSDIR}/x11-toolkits/tk80
WITH_TCL=	--with-tcl --with-tclconfig="${LOCALBASE}/lib/tcl8.0 ${LOCALBASE}/lib/tk8.0"
.endif

# if you want jdbc, type make USE_JDBC=yes
# Honors JAVA_HOME if you have it set, and don't want the dependency.
.if defined(USE_JDBC)
JAVA_HOME?=	${LOCALBASE}/jdk1.1.8
BUILD_DEPENDS=	${JAVA_HOME}/bin/javac:${PORTSDIR}/java/jdk
#MAKE_ENV+=	JAVA_HOME=${JAVA_HOME}
#CONFIGURE_ENV+=	JAVA_HOME=${JAVA_HOME}
SCRIPTS_ENV+=	JAVA_HOME=${JAVA_HOME}
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_GMAKE=	YES
MAKEFILE=	GNUmakefile
HAS_CONFIGURE=	YES
CONFIGURE_ARGS= --prefix=${PREFIX}/pgsql \
		--enable-locale \
		--with-template=`uname -s | ${TR} '[A-Z]' '[a-z]'` \
		--with-includes="${PREFIX}/include ${TCL_INCDIR} ${TK_INCDIR}" ${WITH_TCL} \
		--with-libraries=${PREFIX}/lib

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
	@${ECHO_MSG} "To install and run postgresql you need to compile kernel with:"
	@${ECHO_MSG} "        options    \"SYSVSHM, SYSVSEM, SYSVMSG\""
.if !defined(USE_TCL)
	@${ECHO_MSG} "To build the \"PostgreSQL to Tcl interface library\", libpgtcl, type:"
	@${ECHO_MSG} "    make USE_TCL=yes"
.else
	@${ECHO_MSG} "Building PostgreSQL with \"libpgtcl\"."
.endif

.if !defined(USE_JDBC)
	@ ${ECHO_MSG} "To build Java (JDBC) support, type:"
	@ ${ECHO_MSG} "   make USE_JDBC=yes"
.else
	@ ${ECHO_MSG} "Building PostgreSQL with \"postgresql.jar\"."
.endif

post-patch:

	@ ${MV} ${WRKSRC}/template/freebsd ${WRKSRC}/template/freebsd.orig
	@ ${SED} -e 's#CFLAGS:-O2 -m486 -pipe#CFLAGS:${CFLAGS}#' \
		-e 's#USE_LOCALE:no#USE_LOCALE:yes#' \
	${WRKSRC}/template/freebsd.orig >> ${WRKSRC}/template/freebsd
	@ ${MV} ${WRKSRC}/Makefile.global.in ${WRKSRC}/Makefile.global.in.old
	@ ${SED} -e 's=!!PREFIX!!=${PREFIX}=g' \
		${WRKSRC}/Makefile.global.in.old \
		>> ${WRKSRC}/Makefile.global.in

# pgaccess (accidentally?) removed from distribution, so leave it for now
#.if defined(USE_TCL)
#	@ ${MV} ${WRKSRC}/bin/pgaccess/pgaccess.tcl \
#		${WRKSRC}/bin/pgaccess/pgaccess.tcl.orig
#	@ ${SED} -e "s=/usr/bin/wish=`/usr/bin/which wish8.0`=" \
#		${WRKSRC}/bin/pgaccess/pgaccess.tcl.orig \
#		>> ${WRKSRC}/bin/pgaccess/pgaccess.tcl
#.endif

post-build:

.if defined(USE_JDBC)
	@ cd ${WRKSRC}/interfaces/jdbc && ${GMAKE}
.if !defined(NOPORTDOCS)
	@ cd ${WRKSRC}/interfaces/jdbc && ${GMAKE} examples
.endif
.endif

	@ ${ECHO} "------------------------------------------------------------"
	@ ${ECHO} "Dump existing databases, before installing new db version !!"
	@ ${ECHO} "Detailed instructions, see"
	@ ${ECHO} "${WRKDIR}/${DISTNAME}/INSTALL"
	@ ${ECHO} "------------------------------------------------------------"

pre-install:
.if defined(PACKAGE_BUILDING)
	${RM} -rf ${PREFIX}/pgsql
.endif
	@ ${MKDIR} ${PREFIX}/pgsql
	@ ${SETENV} ${MAKE_ENV} perl ${SCRIPTDIR}/createuser

post-install:
	@ if [ ! -f ${PREFIX}/pgsql/.profile ]; then \
		${ECHO} "PATH=${PATH}:${PREFIX}/pgsql/bin" \
			> ${PREFIX}/pgsql/.profile; \
		${ECHO} "MANPATH=${MANPATH}:${PREFIX}/pgsql/man" \
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
	@ ${CHOWN} -R pgsql:pgsql ${PREFIX}/pgsql
	@ ${ECHO} 'Initializing PostgreSQL Databases - this may take a few minutes...'
	@ ${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/pgsql/lib
	@ su -l pgsql -c 'PATH=${PREFIX}/pgsql/bin:${PATH} ${PREFIX}/pgsql/bin/initdb --pglib=${PREFIX}/pgsql/lib --pgdata=${PREFIX}/pgsql/data'
	@ ${SED} -e "s=!!PREFIX!!=${PREFIX}=g" < ${FILESDIR}/pgsql.sh.tmpl \
		> ${PREFIX}/etc/rc.d/pgsql.sh
	@ ${CHMOD} 554 ${PREFIX}/etc/rc.d/pgsql.sh
	@ ${CHOWN} root.pgsql ${PREFIX}/etc/rc.d/pgsql.sh
	@ ${INSTALL_DATA} ${FILESDIR}/post-install-notes ${PREFIX}/pgsql

.if defined(USE_TCL)
	${CP} ${TMPPLIST} ${TMPPLIST}.notcl
	${CAT} ${PKGDIR}/PLIST.tcl ${TMPPLIST}.notcl > ${TMPPLIST}
	${RM} ${TMPPLIST}.notcl
.endif

.if defined(USE_JDBC)
	@ ${MKDIR} -m 0555 ${PREFIX}/share/java
	@ ${INSTALL_DATA} ${WRKSRC}/interfaces/jdbc/postgresql.jar \
			  ${PREFIX}/share/java/postgresql.jar
	@ ${ECHO_MSG} "---------------------------------------------------------"
	@ ${ECHO_MSG} "Putting postgresql.jar in ${PREFIX}/share/java"
	@ ${ECHO_MSG} "Add this to your CLASSPATH!"
	@ ${ECHO_MSG} "---------------------------------------------------------"
	${CAT} ${PKGDIR}/PLIST.jdbc >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@ ${MKDIR} -m 0555 ${PREFIX}/share/examples/pgsql/jdbc
	@ ${INSTALL_DATA} ${WRKSRC}/interfaces/jdbc/example/*java \
			  ${PREFIX}/share/examples/pgsql/jdbc
	@ ${INSTALL_DATA} ${WRKSRC}/interfaces/jdbc/README* \
			  ${PREFIX}/share/examples/pgsql/jdbc
	@ ${ECHO_MSG} "---------------------------------------------------------"
	@ ${ECHO_MSG} "Putting jdbc examples into ${PREFIX}/share/examples/pgsql"
	@ ${ECHO_MSG} "---------------------------------------------------------"
.endif
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/pgsql
	@ ${GMAKE} -C ${WRKDIR}/${DISTNAME}/doc install
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/doc/FAQ* ${PREFIX}/share/doc/pgsql
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/doc/README* ${PREFIX}/share/doc/pgsql
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/doc/TODO* ${PREFIX}/share/doc/pgsql
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/doc/*ps.gz ${PREFIX}/share/doc/pgsql
.endif
.if !defined(BATCH)
	@ more -e ${FILESDIR}/post-install-notes
.endif
.if !defined(DEBUG_FLAGS)
.for file in ecpg pg_dump pg_id pg_passwd pg_version postgres psql
	@ strip ${PREFIX}/pgsql/bin/${file}
.endfor
.endif

.include <bsd.port.mk>
