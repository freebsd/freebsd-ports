# New ports collection makefile for:	PostgreSQL
# Date created:		7 Jun 2000
# Whom:			Tomokatsu Saito <saito@a2z.co.jp>
#
# $FreeBSD$
#

PORTNAME=	postgresql
PORTVERSION=	7.0.3.20001204
CATEGORIES=	japanese databases
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/cmd/postgres/${PORTVERSION:R}/ \
		ftp://ftp.jaist.ac.jp/pub/dbms/PostgreSQL/v${PORTVERSION:R}/ \
		ftp://ftp.postgresql.org/pub/v${PORTVERSION:R}/ \
		${MASTER_SITE_RINGSERVER}
MASTER_SITE_SUBDIR=	misc/db/postgresql-jp/${PORTVERSION:R}
DISTNAME=	${PORTNAME}-${PORTVERSION:R}
DIST_SUBDIR=	postgresql

PATCH_SITES=	ftp://ftp.sra.co.jp/pub/cmd/postgres/${PORTVERSION:R}/patches/ \
		ftp://ftp.18software.co.jp/pub/postgres/
PATCHFILES=	jumbo-${PORTVERSION:E}.patch.gz \
		psqlj-${PORTVERSION:R}.diff.gz
PATCH_DIST_STRIP=	-p0 -d ${WRKDIR}

MAINTAINER=	saito@a2z.co.jp

BUILD_DEPENDS=	${PATCH}:${PORTSDIR}/devel/patch

.if ${MACHINE_ARCH} == "alpha"
BROKEN=		doesn\'t build on the alpha yet
.endif

Y2K=		http://www.postgresql.org/y2k.html

INSTALLS_SHLIB=	YES
LDCONFIG_DIRS=	%%PREFIX%%/pgsql/lib
# if you want to use the tcl/tk frontend pgaccess, then you need to build
# postgresql with tcl support by typing: make -DWITH_TCL
.if defined(WITH_TCL)
LIB_DEPENDS=	tcl80jp.1:${PORTSDIR}/japanese/tcl80 \
		tk80jp.1:${PORTSDIR}/japanese/tk80
TCL_INCDIR=	${LOCALBASE}/include/tcl8.0jp
TK_INCDIR=	${LOCALBASE}/include/tk8.0jp
MAKE_ENV+=	TCL_INCDIR=${TCL_INCDIR}
CONFIGURE_TCL=	--with-tcl --with-tclconfig=${LOCALBASE}/lib/tcl8.0jp --with-tkconfig=${LOCALBASE}/lib/tk8.0jp
.endif
DEFAULT_ENCODING?=	EUC_JP
CONFIGURE_MULTIBYTE=	--enable-multibyte="${DEFAULT_ENCODING}"
.if defined(WITH_PERL)
CONFIGURE_PERL=		--with-perl
.endif
.if defined(WITH_ODBC)
CONFIGURE_ODBC=		--with-odbc
.endif

# if you want jdbc, type make -DWITH_JDBC
# Honors JAVA_HOME if you have it set, and don't want the dependency.
.if defined(WITH_JDBC)
JAVA_HOME?=	${LOCALBASE}/jdk1.1.8
BUILD_DEPENDS+=	${JAVA_HOME}/bin/javac:${PORTSDIR}/java/jdk
SCRIPTS_ENV+=	JAVA_HOME=${JAVA_HOME}
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}/src
DOCDIR=		${WRKDIR}/${DISTNAME}/doc

PATCH=		${LOCALBASE}/bin/gpatch
USE_GMAKE=	YES
MAKEFILE=	GNUmakefile
HAS_CONFIGURE=	YES
CONFIGURE_ARGS=	--prefix=${PREFIX}/pgsql \
		--enable-locale \
		--with-template=`uname -s | ${TR} '[A-Z]' '[a-z]'` \
		--with-includes="${PREFIX}/include ${TCL_INCDIR} ${TK_INCDIR}" \
		${CONFIGURE_TCL} \
		${CONFIGURE_MULTIBYTE} \
		${CONFIGURE_PERL} \
		${CONFIGURE_ODBC} \
		--with-libraries=${PREFIX}/lib

MAN1=		createdb.1 createlang.1 createuser.1 dropdb.1 droplang.1 \
		dropuser.1 ecpg.1 initdb.1 initlocation.1 ipcclean.1 pg_ctl.1 \
		pg_dump.1 pg_dumpall.1 pg_passwd.1 pg_upgrade.1 pgaccess.1 \
		pgadmin.1 pgtclsh.1 pgtksh.1 postgres.1 postmaster.1 psql.1 \
		vacuumdb.1
MANL=		abort.l alter_group.l alter_table.l alter_user.l \
		begin.l close.l cluster.l comment.l commit.l copy.l \
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
		set.l show.l truncate.l unlisten.l update.l vacuum.l

MANPREFIX=	${PREFIX}/pgsql

pre-fetch:
	@${ECHO_MSG} "To install and run postgresql you need to compile kernel with:"
	@${ECHO_MSG} "    options    \"SYSVSHM, SYSVSEM, SYSVMSG\""
.if !defined(WITH_TCL)
	@${ECHO_MSG} "To build the \"PostgreSQL to Tcl interface library\", libpgtcl, type:"
	@${ECHO_MSG} "    make -DWITH_TCL"
.else
	@${ECHO_MSG} "Building PostgreSQL with \"libpgtcl\"."
.endif
.if !defined(DEFAULT_ENCODING)
	@${ECHO_MSG} "To set the default encoding for the multibyte support, type:"
	@${ECHO_MSG} "    make DEFAULT_ENCODING=<encoding>"
	@${ECHO_MSG} "where <encoding> is one of these:"
	@${ECHO_MSG} "    SQL_ASCII   LATIN1      LATIN2      LATIN3      LATIN4      LATIN5"
	@${ECHO_MSG} "    EUC_JP      EUC_CN      EUC_KR      EUC_TW      KOI8"
	@${ECHO_MSG} "    UNICODE     MULE_INTERNAL           WIN         ALT"
.endif
	@${ECHO_MSG} "The default encoding is '${DEFAULT_ENCODING}'."
.if !defined(WITH_JDBC)
	@${ECHO_MSG} "To build Java (JDBC) support, type:"
	@${ECHO_MSG} "    make -DWITH_JDBC"
.else
	@${ECHO_MSG} "Building PostgreSQL with \"postgresql.jar\"."
.endif
.if !defined(WITH_PERL)
	@${ECHO_MSG} "To build Perl interface and pl/Perl interpreter:"
	@${ECHO_MSG} "    make -DWITH_PERL"
.else
	@${ECHO_MSG} "Building PostgreSQL with \"pl/Perl\"."
.endif
.if !defined(WITH_ODBC)
	@${ECHO_MSG} "To build the ODBC driver package:"
	@${ECHO_MSG} "    make -DWITH_ODBC"
.else
	@${ECHO_MSG} "Building PostgreSQL with ODBC Drivers."
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

post-build:
.if defined(WITH_JDBC)
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
.if defined(NOPORTDOCS)
	@ ( cd ${DOCDIR}; ${GMAKE} man )
.else
	@ ( cd ${DOCDIR}; ${GMAKE} install )
.endif
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
	@ ${CHOWN} root:pgsql ${PREFIX}/pgsql/lib
	@ ${ECHO} 'Initializing PostgreSQL Databases - this may take a few minutes...'
	@ ${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/pgsql/lib
	@ su -l pgsql -c 'PATH=${PREFIX}/pgsql/bin:${PATH} LD_LIBRARY_PATH=${PREFIX}/pgsql/lib ${PREFIX}/pgsql/bin/initdb --pglib=${PREFIX}/pgsql/lib --pgdata=${PREFIX}/pgsql/data'
	@ ${SED} -e "s=!!PREFIX!!=${PREFIX}=g" < ${FILESDIR}/pgsql.sh.tmpl \
		> ${PREFIX}/etc/rc.d/pgsql.sh
	@ ${CHMOD} 554 ${PREFIX}/etc/rc.d/pgsql.sh
	@ ${CHOWN} root.pgsql ${PREFIX}/etc/rc.d/pgsql.sh
	@ ${INSTALL_DATA} ${FILESDIR}/post-install-notes ${PREFIX}/pgsql
.if defined(WITH_TCL)
	@${CP} ${TMPPLIST} ${TMPPLIST}.notcl
	@${CAT} ${PKGDIR}/pkg-plist.tcl ${TMPPLIST}.notcl > ${TMPPLIST}
	@${RM} ${TMPPLIST}.notcl
.endif
.if defined(WITH_ODBC)
	@${CP} ${TMPPLIST} ${TMPPLIST}.noodbc
	@${CAT} ${PKGDIR}/pkg-plist.odbc ${TMPPLIST}.noodbc > ${TMPPLIST}
	@${RM} ${TMPPLIST}.noodbc
.endif
.if defined(WITH_JDBC)
	@ ${MKDIR} -m 0555 ${PREFIX}/share/java/classes
	@ ${INSTALL_DATA} ${WRKSRC}/interfaces/jdbc/postgresql.jar \
			  ${PREFIX}/share/java/classes/postgresql.jar
	@ ${ECHO_MSG} "---------------------------------------------------------"
	@ ${ECHO_MSG} "Putting postgresql.jar in"
	@ ${ECHO_MSG} "${PREFIX}/share/java/classes/postgresql.jar"
	@ ${ECHO_MSG} "Add this to your CLASSPATH!"
	@ ${ECHO_MSG} "ALSO NOTE: path inside jar file modified from 6.5.x:"
	@ ${ECHO_MSG} "  'postgresql.*' -> 'org.postgresql.*'!"
	@ ${ECHO_MSG} "You will need to modify you applications' props files."
	@ ${ECHO_MSG} "---------------------------------------------------------"
	@ ${CAT} ${PKGDIR}/pkg-plist.jdbc >> ${TMPPLIST}
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
	${GMAKE} -C ${WRKDIR}/${DISTNAME}/doc install
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/doc/FAQ* ${PREFIX}/share/doc/pgsql
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/doc/README* ${PREFIX}/share/doc/pgsql
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/doc/TODO ${PREFIX}/share/doc/pgsql
#	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/doc/*ps ${PREFIX}/share/doc/pgsql
	@ ${CAT} ${PKGDIR}/pkg-plist.doc >> ${TMPPLIST}
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
