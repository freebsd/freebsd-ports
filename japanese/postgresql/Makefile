# New ports collection makefile for:	PostgreSQL-j
# Date created:		09 Nov 1999
# Whom:			Ichiro Fukuhara <ichiro@ichiro.org>
#
# $FreeBSD$
#

PORTNAME=	postgresql
PORTVERSION=	6.5.3
PORTREVISION=	1
CATEGORIES=	japanese databases
MASTER_SITES=	ftp://ftp.jaist.ac.jp/pub/dbms/PostgreSQL/ \
		ftp://ftp.sra.co.jp/pub/cmd/postgres/${PORTVERSION}/ \
		ftp://ftp.postgresql.org/pub/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	A robust, next generation, object-relational DBMS plus Multibyte-patch

NO_LATEST_LINK=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
PLISTS=

# if you want to use the tcl/tk frontend pgaccess, then you need to build
# postgresql with tcl support by typing: make WITH_TCL=yes
.if defined(WITH_TCL)
TCL_INCDIR=	${PREFIX}/include/tcl8.0jp
TK_INCDIR=	${PREFIX}/include/tk8.0jp
MAKE_ENV=	USE_TCL=true USE_TK=true TCL_INCDIR=${TCL_INCDIR}
CONFIGURE_ARGS= --with-tcl --with-tk \
		--with-tclconfig=${PREFIX}/lib/tcl8.0jp \
		--with-tkconfig=${PREFIX}/lib/tk8.0jp
LIB_DEPENDS=	tcl80jp.1:${PORTSDIR}/japanese/tcl80 \
		tk80jp.1:${PORTSDIR}/japanese/tk80
PLISTS+=	pkg-plist.tcl
.endif
.if defined(MULTIBYTE)
CONFIGURE_ARGS+= --with-mb=${MULTIBYTE}
.endif
.if defined(WITH_PERL)
CONFIGURE_ARGS+= --with-perl
PLISTS+=	pkg-plist.pl
.endif
.if defined(WITH_ODBC)
CONFIGURE_ARGS+= --with-odbc
PLISTS+=	pkg-plist.odbc
.endif

NO_PACKAGE=	"Requires ${PGSQL_UID} uid"

USE_GMAKE=	YES
MAKEFILE=	GNUmakefile
HAS_CONFIGURE=	YES
CONFIGURE_ARGS+= --prefix=${PREFIX}/${INSTALL_DIR} \
		--with-template=`uname -s | ${TR} '[A-Z]' '[a-z]'` \
		--with-includes="${PREFIX}/include ${TCL_INCDIR} ${TK_INCDIR}" \
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

MANPREFIX=	${PREFIX}/${INSTALL_DIR}
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	${PREFIX}/${INSTALL_DIR}/lib

PLIST_SUB=	INSTALL_DIR=${INSTALL_DIR}
PLIST=		${WRKDIR}/PLIST

# These values are easily overridable like as
#   "make PGQL_UID=postgresql PGSQL_GID=postgresql install"
INSTALL_DIR= 	pgsql
PGSQL_UID=	pgsql
PGSQL_GID=	pgsql

pre-fetch:
.if !defined(WITH_TCL) & !defined(WITH_PERL) & !defined(WITH_ODBC) & !defined(MULTIBYTE)

	@${ECHO_MSG} "To build the \"MULTIBYTE PostgreSQL\", type:"
	@${ECHO_MSG} "    make MULTIBYTE={EUC_JP,EUC_CN,EUC_KR,EUC_TW,UNICODE,MULE_INTERNAL,LATIN1-5}"
	@${ECHO_MSG} "          WITH_TCL=yes, WITH_PERL=yes, WITH_ODBC=yes"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "To build the \"PostgreSQL to Tcl interface library\", libpgtcl, type:"
	@${ECHO_MSG} "		make WITH_TCL=yes"
.else
	@${ECHO_MSG} "Building PostgreSQL with \"libpgtcl\"."
.endif

.include <bsd.port.pre.mk>

post-patch:
	${FIND} ${WRKDIR} -name '*.orig' -exec ${RM} {} \;

post-build:
	@ ${ECHO} "------------------------------------------------------------"
	@ ${ECHO} "Dump existing databases, before installing new db version !!"
	@ ${ECHO} "Detailed instructions, see INSTALL file under ${WRKDIR}...  "
	@ ${ECHO} "------------------------------------------------------------"
	@${RM} -f ${WRKDIR}/PLIST
.for i in ${PLISTS} pkg-plist
	${CAT} ${PKGDIR}/${i} >> ${WRKDIR}/PLIST
.endfor
.if defined(WITH_TCL)
	${CAT} ${PKGDIR}/pkg-plist.tcl.dirrm >> ${WRKDIR}/PLIST
.endif
.if defined(WITH_ODBC)
	${CAT} ${PKGDIR}/pkg-plist.odbc.dirrm >> ${WRKDIR}/PLIST
.endif
	${CAT} ${PKGDIR}/pkg-plist.dirrm >> ${WRKDIR}/PLIST

pre-install:
.if defined(PACKAGE_BUILDING)
	${RM} -rf ${PREFIX}/${INSTALL_DIR}
.endif
	@ ${MKDIR} ${PREFIX}/${INSTALL_DIR}
	@ ${SETENV} INSTALL_DIR=${INSTALL_DIR} \
	     	    PGSQL_UID=${PGSQL_UID} PGSQL_GID=${PGSQL_GID} \
		    PKG_PREFIX=${PREFIX} \
			${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
post-install:
	@ if [ ! -f ${PREFIX}/${INSTALL_DIR}/.profile ]; then \
		${ECHO} "PATH=${PATH}:${PREFIX}/${INSTALL_DIR}/bin" \
			> ${PREFIX}/${INSTALL_DIR}/.profile; \
		${ECHO} "MANPATH=${MANPATH}:${PREFIX}/${INSTALL_DIR}/bin" \
			>> ${PREFIX}/${INSTALL_DIR}/.profile; \
		${ECHO} "PGLIB=${PREFIX}/${INSTALL_DIR}/lib" \
			>> ${PREFIX}/${INSTALL_DIR}/.profile; \
		${ECHO} "# note: PGDATA overwrites the -D startup option" \
			>> ${PREFIX}/${INSTALL_DIR}/.profile; \
		${ECHO} "PGDATA=${PREFIX}/${INSTALL_DIR}/data" \
			>> ${PREFIX}/${INSTALL_DIR}/.profile; \
		${ECHO} "DISPLAY=:0" \
			>> ${PREFIX}/${INSTALL_DIR}/.profile; \
		${ECHO} "export PATH MANPATH PGLIB PGDATA DISPLAY" \
			>> ${PREFIX}/${INSTALL_DIR}/.profile; \
		${ECHO} "# if you want to make regression tests use this TZ" \
			>> ${PREFIX}/${INSTALL_DIR}/.profile; \
		${ECHO} "#TZ=PST8PDT" \
			>> ${PREFIX}/${INSTALL_DIR}/.profile; \
		${ECHO} "#export TZ" \
			>> ${PREFIX}/${INSTALL_DIR}/.profile; \
	fi
	@ ${CHOWN} -R ${PGSQL_UID}:${PGSQL_GID} ${PREFIX}/${INSTALL_DIR}
	@ ${ECHO} 'Initializing PostgreSQL Databases - this may take a few minutes...'
	@ ${LDCONFIG} -m ${PREFIX}/${INSTALL_DIR}/lib
	@ /usr/bin/su -l ${PGSQL_UID} -c '${PREFIX}/${INSTALL_DIR}/bin/initdb --pglib=${PREFIX}/${INSTALL_DIR}/lib --pgdata=${PREFIX}/${INSTALL_DIR}/data'
	@ ${SED} "s=!!PG_PATH!!=${PREFIX}/${INSTALL_DIR}=g ; s=!!PGSQL_UID!!=${PGSQL_UID}=g" \
		< ${FILESDIR}/pgsql.sh.tmpl > ${PREFIX}/etc/rc.d/pgsql.sh
	@ ${CHMOD} 554 ${PREFIX}/etc/rc.d/pgsql.sh
	@ ${CHOWN} root:${PGSQL_GID} ${PREFIX}/etc/rc.d/pgsql.sh
	@ ${INSTALL_DATA} ${FILESDIR}/post-install-notes ${PREFIX}/${INSTALL_DIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${INSTALL_DIR}
	${CP} -R ${WRKDIR}/${DISTNAME}/doc/* ${PREFIX}/share/doc/${INSTALL_DIR}
.for f in . src src/sgml src/sgml/ref src/graphics
	@${RM} -rf ${PREFIX}/share/doc/${INSTALL_DIR}/$f/CVS
	@${RM} -f ${PREFIX}/share/doc/${INSTALL_DIR}/$f/#cvs*
.endfor
.endif
.if !defined(BATCH)
	@ more -e ${FILESDIR}/post-install-notes
.endif

.include <bsd.port.post.mk>
