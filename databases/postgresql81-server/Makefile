# New ports collection makefile for:	PostgreSQL
# Version required:			6.0 
# Date created:				April 2, 1997
# Whom:	      				Marc G. Fournier <scrappy@FreeBSD.ORG>
#
#   $Id: Makefile,v 1.2 1997/04/02 18:17:50 jfitz Exp $

DISTNAME=	postgresql-v6.0
PKGNAME=	postgresql-6.0
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.PostgreSQL.org/pub/ \
		ftp://ftp.luga.or.at/pub/postgres95/ \
		ftp://ftp.jaist.ac.jp/pub/dbms/postgres95/ 
		
MAINTAINER=	scrappy@FreeBSD.ORG

NO_PACKAGE=	"Requires pgsql uid"
WRKSRC=		${WRKDIR}/src
USE_GMAKE=	YES
MAKEFILE=	GNUmakefile

MAN1=		createdb.1 psql.1 unix.1 postgres.1 pg_dumpall.1 monitor.1 \
		initdb.1 ipcclean.1 destroydb.1 cleardbdir.1 createuser.1 \
		destroyuser.1 pg_dump.1 postmaster.1
MAN3=		libpq.3 large_objects.3 built-in.3 catalogs.3
MAN5=		pg_hba.conf.5 bki.5 page.5
MANL=		vacuum.l sql.l select.l update.l revoke.l rename.l purge.l \
		load.l listen.l insert.l fetch.l end.l grant.l drop_rule.l \
		drop_type.l drop_function.l create_aggregate.l drop.l \
		delete.l destroydb.l create_view.l create_rule.l \
		create_index.l copy.l cluster.l create_database.l \
		create_function.l begin.l abort.l alter_table.l close.l \
		create_operator.l create_table.l create_type.l \
		create_version.l drop_aggregate.l drop_operator.l explain.l \
		notify.l remove_view.l rollback.l commit.l drop_index.l
MANPREFIX=	${PREFIX}/pgsql

pre-install:
		@ ${MKDIR} ${PREFIX}/pgsql
		@ ${SETENV} ${MAKE_ENV} /usr/bin/perl ${SCRIPTDIR}/createuser

post-install:
		@ chown -R pgsql:pgsql ${PREFIX}/pgsql
		@ if [ ! -f ${PREFIX}/pgsql/.profile ]; then \
			echo "PATH=\${PATH}:${PREFIX}/pgsql/bin" > ${PREFIX}/pgsql/.profile; \
			echo "export PATH" >> ${PREFIX}/pgsql/.profile; \
		fi
		@ echo 'Initializing PostgreSQL Databases - this may take a few minutes...'
		@ su -l pgsql -c '${PREFIX}/pgsql/bin/initdb --pglib=${PREFIX}/pgsql/lib --pgdata=${PREFIX}/pgsql/data'
		@ if [ ! -f ${PREFIX}/etc/rc.d/postgresql.sh ]; then \
			echo "Installing ${PREFIX}/etc/rc.d/postgresql.sh startup file."; \
			echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/postgresql.sh; \
			echo "[ -x ${PREFIX}/pgsql/bin/postmaster ] && su -l pgsql -c '${PREFIX}/pgsql/bin/postmaster -D${PREFIX}/pgsql/data -o -F > ${PREFIX}/pgsql/errlog &' && echo -n ' pgsql'" >> ${PREFIX}/etc/rc.d/postgresql.sh; \
			chmod 751 ${PREFIX}/etc/rc.d/postgresql.sh; \
		fi
		@ ${INSTALL_DATA} ${FILESDIR}/post-install-notes ${PREFIX}/pgsql
.if !defined(BATCH)
		@ more -e ${FILESDIR}/post-install-notes
.endif

.include <bsd.port.mk>
