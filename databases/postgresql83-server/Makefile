# New ports collection makefile for:	PostgreSQL
# Version required:	6.1 
# Date created:		April 2, 1997
# Whom:			Marc G. Fournier <scrappy@FreeBSD.ORG>
#
# $Id: Makefile,v 1.11 1997/06/14 19:40:03 andreas Exp $

DISTNAME=	postgresql-v6.1
PKGNAME=	postgresql-6.1
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.PostgreSQL.org/pub/ \
		ftp://ftp.luga.or.at/pub/postgres95/ \
		ftp://ftp.jaist.ac.jp/pub/dbms/postgres95/ 
		
MAINTAINER=	andreas@FreeBSD.ORG

NO_PACKAGE=	"Requires pgsql uid"
WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_GMAKE=	YES
HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=--prefix=${PREFIX}/pgsql \
		--enable-locale \
		--with-template=`uname -s | tr '[A-Z]' '[a-z]'`
MAKEFILE=	GNUmakefile

MAN1=		cleardbdir.1 createdb.1 createuser.1 destroydb.1 \
		destroyuser.1 initdb.1 ipcclean.1 monitor.1 pg_dump.1 \
		pg_dumpall.1 postgres.1 postmaster.1 psql.1 unix.1
MAN3=		built-in.3 catalogs.3 large_objects.3 libpq.3 oracle_compat.3
MAN5=		bki.5 page.5 pg_hba.conf.5 
MANL=		abort.l alter_table.l begin.l close.l cluster.l \
		commit.l copy.l create_aggregate.l create_database.l \
		create_function.l create_index.l create_operator.l \
		create_rule.l create_sequence.l create_table.l \
		create_type.l create_version.l create_view.l delete.l \
		drop.l drop_aggregate.l drop_database.l drop_function.l \
		drop_index.l drop_operator.l drop_rule.l drop_sequence.l \
		drop_type.l drop_view.l end.l explain.l fetch.l grant.l \
		insert.l listen.l load.l notify.l purge.l rename.l \
		reset.l revoke.l rollback.l select.l set.l show.l \
		sql.l update.l vacuum.l
MANPREFIX=	${PREFIX}/pgsql

pre-install:
	@ ${MKDIR} ${PREFIX}/pgsql
	@ ${SETENV} ${MAKE_ENV} /usr/bin/perl ${SCRIPTDIR}/createuser

post-install:
	@ if [ ! -f ${PREFIX}/pgsql/.profile ]; then \
		echo "PATH=${PATH}:${PREFIX}/pgsql/bin" \
			> ${PREFIX}/pgsql/.profile; \
		echo "MANPATH=${MANPATH}:${PREFIX}/pgsql/bin" \
			>> ${PREFIX}/pgsql/.profile; \
		echo "PGLIB=${PREFIX}/pgsql/lib" \
			>> ${PREFIX}/pgsql/.profile; \
		echo "PGDATA=${PREFIX}/pgsql/data" \
			>> ${PREFIX}/pgsql/.profile; \
		echo "export PATH MANPATH PGLIB PGDATA" \
			>> ${PREFIX}/pgsql/.profile; \
	fi
	@ chown -R pgsql:pgsql ${PREFIX}/pgsql
	@ echo 'Initializing PostgreSQL Databases - this may take a few minutes...'
	@ /sbin/ldconfig -m ${PREFIX}/pgsql/lib
	@ su -l pgsql -c '${PREFIX}/pgsql/bin/initdb --pglib=${PREFIX}/pgsql/lib --pgdata=${PREFIX}/pgsql/data'
	@ if [ ! -f ${PREFIX}/etc/rc.d/postgresql.sh ]; then \
		echo "Installing ${PREFIX}/etc/rc.d/postgresql.sh startup file."; \
		echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/postgresql.sh; \
		echo "[ -d ${PREFIX}/pgsql/lib ] && /sbin/ldconfig -m ${PREFIX}/pgsql/lib" >> ${PREFIX}/etc/rc.d/postgresql.sh; \
		echo "[ -x ${PREFIX}/pgsql/bin/postmaster ] && su -l pgsql -c '${PREFIX}/pgsql/bin/postmaster -D${PREFIX}/pgsql/data -o -F > ${PREFIX}/pgsql/errlog &' && echo -n ' pgsql'" >> ${PREFIX}/etc/rc.d/postgresql.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/postgresql.sh; \
	fi
	@ ${INSTALL_DATA} ${FILESDIR}/post-install-notes ${PREFIX}/pgsql
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/pgsql
	${CP} ${WRKDIR}/${DISTNAME}/doc/* ${PREFIX}/share/doc/pgsql
.endif
.if !defined(BATCH)
	@ more -e ${FILESDIR}/post-install-notes
.endif

.include <bsd.port.mk>
