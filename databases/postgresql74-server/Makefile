# New ports collection makefile for:	PostgreSQL
# Date created:		November 13, 1998
# Whom:			Marc G. Fournier <scrappy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	postgresql
PORTVERSION=	7.0.3
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.postgresql.org/pub/%SUBDIR%/ \
		ftp://ftp.de.postgresql.org/%SUBDIR%/ \
		ftp://ftp.iodynamics.com/pub/mirror/postgresql/%SUBDIR%/ \
		ftp://ftp.digex.net/pub/packages/database/postgresql/%SUBDIR%/ \
		ftp://ftp.sunet.se/pub/unix/databases/relational/postgresql/%SUBDIR%/
MASTER_SITE_SUBDIR=	source/v${PORTVERSION}
DISTFILES=	${PORTNAME}-${PORTVERSION}.base${EXTRACT_SUFX} \
		${PORTNAME}-${PORTVERSION}.support${EXTRACT_SUFX} \
		${PORTNAME}-${PORTVERSION}.docs${EXTRACT_SUFX}
#		${PORTNAME}-${PORTVERSION}.test${EXTRACT_SUFX}
DIST_SUBDIR=	postgresql

MAINTAINER=	girgen@partitur.se

BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf

INSTALLS_SHLIB=	YES
LDCONFIG_DIRS=	%%PREFIX%%/pgsql/lib

WRKSRC=		${WRKDIR}/${DISTNAME}/src
DOCDIR=		${WRKDIR}/${DISTNAME}/doc

USE_GMAKE=	YES
MAKEFILE=	GNUmakefile
HAS_CONFIGURE=	YES
CONFIGURE_ARGS=	--prefix=${PREFIX}/pgsql \
		--enable-locale \
		--with-template=`uname -s | ${TR} '[A-Z]' '[a-z]'` \
		--with-includes="${PREFIX}/include ${TCL_INCDIR} ${TK_INCDIR}" \
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

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		WRKDIR="${WRKDIR}" \
		FILESDIR="${FILESDIR}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \
		NO_OPENSSL="${NO_OPENSSL}" \
		DISTNAME="${DISTNAME}"

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

pre-extract:
	@ ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.postgresql

post-patch:
	@ ${MV} ${WRKSRC}/template/freebsd ${WRKSRC}/template/freebsd.orig
	@ ${SED} -e 's#CFLAGS:-O2 -m486 -pipe#CFLAGS:${CFLAGS}#' \
		-e 's#USE_LOCALE:no#USE_LOCALE:yes#' \
	${WRKSRC}/template/freebsd.orig >> ${WRKSRC}/template/freebsd
	@ ${MV} ${WRKSRC}/Makefile.global.in ${WRKSRC}/Makefile.global.in.old
	@ ${SED} -e 's=!!PREFIX!!=${PREFIX}=g' \
		${WRKSRC}/Makefile.global.in.old \
		>> ${WRKSRC}/Makefile.global.in

#
# USE_AUTOCONF implies GNU_CONFIGURE, which we don't want, so we have
# to do it by hand.
#
pre-configure:
	@(cd ${WRKSRC} && ${AUTOCONF})

post-build:
.if defined(WITH_JDBC)
	@ ${GMAKE} -C ${WRKSRC}/interfaces/jdbc jdbc${JAVAVERSION}
.endif

pre-install:
.if defined(PACKAGE_BUILDING)
	${RM} -rf ${PREFIX}/pgsql
.endif
	@ ${MKDIR} ${PREFIX}/pgsql
	@ ${SETENV} ${MAKE_ENV} perl ${SCRIPTDIR}/createuser
.if !defined(BATCH)
	@ ${SED} -e "s#%%WRKDIR%%#${WRKDIR}#; s#%%DISTNAME%%#${DISTNAME}#" \
	< ${FILESDIR}/pre-install-notes | more -e
.endif

post-install:
.if defined(NOPORTDOCS)
	@ ${GMAKE} -C ${DOCDIR} man
.else
	@ ${GMAKE} -C ${DOCDIR} install
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/doc/FAQ* ${PREFIX}/share/doc/pgsql
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/doc/README* ${PREFIX}/share/doc/pgsql
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/doc/TODO ${PREFIX}/share/doc/pgsql
#	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/doc/*ps.gz ${PREFIX}/share/doc/pgsql
	@ ${CAT} ${PKGDIR}/pkg-plist.doc >> ${TMPPLIST}
.endif
	@ ${SED} 's|%%PREFIX%%|${PREFIX}|g' \
		< ${FILESDIR}/dot.profile.in \
		> ${PREFIX}/pgsql/dot.profile.dist;
	@ if [ ! -f ${PREFIX}/pgsql/.profile ]; then \
		${CP} ${PREFIX}/pgsql/dot.profile.dist \
			${PREFIX}/pgsql/.profile; \
	fi
	@ ${CHOWN} -R pgsql:pgsql ${PREFIX}/pgsql
	@ ${CHOWN} root:pgsql ${PREFIX}/pgsql/lib
	@ ${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/pgsql/lib
	@ ${SED} -e "s=!!PREFIX!!=${PREFIX}=g" < ${FILESDIR}/pgsql.sh.tmpl \
		> ${PREFIX}/etc/rc.d/010.pgsql.sh
	@ ${CHMOD} 554 ${PREFIX}/etc/rc.d/010.pgsql.sh
	@ ${CHOWN} root.pgsql ${PREFIX}/etc/rc.d/010.pgsql.sh
	@ ${SED} -e 's#%%PREFIX%%#${PREFIX}#' < ${FILESDIR}/post-install-notes \
		> ${PREFIX}/pgsql/post-install-notes
.if defined(WITHOUT_MULTIBYTE)
	@${CP} ${TMPPLIST} ${TMPPLIST}.nomulti
	@${GREP} -v pgsql/bin/pg_encoding ${TMPPLIST}.nomulti > ${TMPPLIST}
.endif
.if defined(WITH_TCL)
	@${CP} ${TMPPLIST} ${TMPPLIST}.notcl
	@${CAT} ${PKGDIR}/${TCL_PLIST} ${TMPPLIST}.notcl > ${TMPPLIST}
	@${RM} ${TMPPLIST}.notcl
# Preparing a loadable TCL-package (pkgIndex.tcl)
# XXX This directory and the single file are not registered in
# XXX the PLIST, because of different PREFIX.
	@${MKDIR} ${LOCALBASE}/lib/tcl${WITH_TCL}/Pgtcl1.3
	@${SED} 's|%%PREFIX%%|${PREFIX}|' < ${FILESDIR}/pkgIndex.tcl.in \
		> ${LOCALBASE}/lib/tcl${WITH_TCL}/Pgtcl1.3/pkgIndex.tcl
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
.if !defined(BATCH)
	@ more -e ${PREFIX}/pgsql/post-install-notes
.endif
.if !defined(DEBUG_FLAGS)
.for file in ecpg pg_dump pg_id pg_passwd pg_version postgres psql
	@ strip ${PREFIX}/pgsql/bin/${file}
.endfor
.endif
	@ ${RMDIR} ${PREFIX}/pgsql/include/port/freebsd
	@ ${RMDIR} ${PREFIX}/pgsql/include/port
	@ ${CAT} ${PKGMESSAGE}

post-clean:
	@ ${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.mk>
