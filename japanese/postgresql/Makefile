# New ports collection makefile for:	PostgreSQL-j
# Version required:	6.4+Multibyte-patch
# Date created:		25 Nov 1998
# Whom:			Ichiro Fukuhara <ichiro@ichiro.org>
#
# $Id$
#

DISTNAME=	postgresql-v6.4
PKGNAME=	ja-postgresql-6.4
CATEGORIES=	japanese databases
MASTER_SITES=	ftp://ftp.postgresql.org/pub/ \
		ftp://ftp.jaist.ac.jp/pub/dbms/PostgreSQL/ \
		ftp://ftp.sra.co.jp/pub/cmd/postgres/6.4/

PATCH_SITES=	ftp://ftp.sra.co.jp/pub/cmd/postgres/6.4/patches/
PATCHFILES=	jumbo-981124.patch.gz

MAINTAINER=	ichiro@ichiro.org

WRKSRC=		${WRKDIR}/${DISTNAME}/src
PATCH_DIST_ARGS=	-d ${WRKDIR}/${DISTNAME} --forward --quiet -E -p1
PLISTS=		PLIST

# if you want to use the tcl/tk frontend pgaccess, then you need to build
# postgresql with tcl support by typing: make USE_TCL=yes
.if defined(USE_TCL)
TCL_INCDIR=	${PREFIX}/include/tcl8.0jp
TK_INCDIR=	${PREFIX}/include/tk8.0jp
MAKE_ENV=	USE_TCL=true TCL_INCDIR=${TCL_INCDIR}
WITH_TCL=	--with-tcl --with-tclconfig="${PREFIX}/lib/tcl8.0jp ${PREFIX}/lib/tk8.0jp"
LIB_DEPENDS=	tcl80jp.1:${PORTSDIR}/japanese/tcl80 \
		tk80jp.1:${PORTSDIR}/japanese/tk80
PLISTS+=	PLIST.tcl
.endif
.if defined(MULTIBYTE)
WITH_MB=	--with-mb=${MULTIBYTE}
.endif
.if defined(USE_PERL)
WITH_PERL=      --with-perl
.endif
.if defined(USE_ODBC)
WITH_ODBC=      --with-odbc
PLISTS+=	PLIST.odbc
.endif

NO_PACKAGE=	"Requires ${PGSQL_UID} uid"

USE_GMAKE=	YES
MAKEFILE=	GNUmakefile
HAS_CONFIGURE=	YES
CONFIGURE_ARGS= --prefix=${PREFIX}/${INSTALL_DIR} \
		--with-template=`uname -s | ${TR} '[A-Z]' '[a-z]'` \
		--with-includes="${PREFIX}/include ${TCL_INCDIR} ${TK_INCDIR}" ${WITH_TCL}\
		--with-libraries=${PREFIX}/lib \
		${WITH_MB} ${WITH_PERL} ${WITH_ODBC}

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

PLIST_SUB=	INSTALL_DIR=${INSTALL_DIR}
PLIST=		${WRKDIR}/PLIST

# These values are easily overridable like as
#   "make PGQL_UID=postgresql PGSQL_GID=postgresql install"
INSTALL_DIR= 	pgsql
PGSQL_UID=	pgsql
PGSQL_GID=	pgsql

pre-fetch:
.if !defined(USE_TCL) & !defined(USE_PERL) & !defined(USE_ODBC) & !defined(MULTIBYTE)

	@${ECHO_MSG} "To build the \"MULTIBYTE PostgreSQL\", type:"
	@${ECHO_MSG} "    make MULTIBYTE={EUC_JP,EUC_CN,EUC_KR,EUC_TW,UNICODE,MULE_INTERNAL,LATIN1-5}"
	@${ECHO_MSG} "          USE_TCL=yes, USE_PERL=yes, USE_ODBC=yes"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "To build the \"PostgreSQL to Tcl interface library\", libpgtcl, type:"
	@${ECHO_MSG} "		make USE_TCL=yes"
.else
	@${ECHO_MSG} "Building PostgreSQL with \"libpgtcl\"."
.endif

.include <bsd.port.pre.mk>

post-patch:
	find ${WRKDIR} -name '*.orig' -exec ${RM} {} \;

post-build:
	@ ${ECHO} "------------------------------------------------------------"
	@ ${ECHO} "Dump existing databases, before installing new db version !!"
	@ ${ECHO} "Detailed instructions, see INSTALL file under ${WRKDIR}...  "
	@ ${ECHO} "------------------------------------------------------------"
	@${RM} -f ${WRKDIR}/PLIST
.for i in ${PLISTS}
	${CAT} ${PKGDIR}/${i} >> ${WRKDIR}/PLIST
.endfor

pre-install:
.if defined(PACKAGE_BUILDING)
	${RM} -rf ${PREFIX}/${INSTALL_DIR}
.endif
	@ ${MKDIR} ${PREFIX}/${INSTALL_DIR}
	@ ${SETENV} INSTALL_DIR=${INSTALL_DIR} \
	     	    PGSQL_UID=${PGSQL_UID} PGSQL_GID=${PGSQL_GID} \
		 ${SH} ${PKGDIR}/INSTALL PRE-INSTALL
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
	@ chown -R ${PGSQL_UID}:${PGSQL_GID} ${PREFIX}/${INSTALL_DIR}
	@ ${ECHO} 'Initializing PostgreSQL Databases - this may take a few minutes...'
	@ ${LDCONFIG} -m ${PREFIX}/${INSTALL_DIR}/lib
	@ /usr/bin/su -l ${PGSQL_UID} -c '${PREFIX}/${INSTALL_DIR}/bin/initdb --pglib=${PREFIX}/${INSTALL_DIR}/lib --pgdata=${PREFIX}/${INSTALL_DIR}/data'
	@ ${SED} "s=!!PG_PATH!!=${PREFIX}/${INSTALL_DIR}=g ; s=!!PGSQL_UID!!=${PGSQL_UID}=g" \
		< ${FILESDIR}/pgsql.sh.tmpl > ${PREFIX}/etc/rc.d/pgsql.sh
	@ chmod 554 ${PREFIX}/etc/rc.d/pgsql.sh
	@ chown root.${PGSQL_GID} ${PREFIX}/etc/rc.d/pgsql.sh
	@ ${INSTALL_DATA} ${FILESDIR}/post-install-notes ${PREFIX}/${INSTALL_DIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${INSTALL_DIR}
	${CP} -r ${WRKDIR}/${DISTNAME}/doc/* ${PREFIX}/share/doc/${INSTALL_DIR}
.endif
.if !defined(BATCH)
	@ more -e ${FILESDIR}/post-install-notes
.endif
#.if (${PORTOBJFORMAT} == "elf")
#	@${ECHO} "Hack for ELF library..."
#	@${RM} ${PREFIX}/${INSTALL_DIR}/lib/libpg.so.2.0
#	@${RM} ${PREFIX}/${INSTALL_DIR}/lib/libpg++.so.2.0
#.endif

.include <bsd.port.post.mk>
