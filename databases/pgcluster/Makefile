# New ports collection makefile for:	pgcluster
# Date created:		22 Jan 2004
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	pgcluster
PORTVERSION=	1.0.6b
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR=	v${BASEPGSQL}
DISTNAME=	postgresql-base-${BASEPGSQL}
DIST_SUBDIR=	postgresql

PATCH_SITES=	http://hiroshima.sraw.co.jp/people/mitani/jpug/pgcluster/current/
PATCHFILES=	pgcluster-${PORTVERSION}-patch.tar.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=The multi-master and synchronous replication system for PostgreSQL

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync

WRKSRC?=	${WRKDIR}/postgresql-${BASEPGSQL}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_FLAGS=	# empty
MAKEFILE=	# empty
CONFLICTS=	postgresql-*
USE_RC_SUBR=	yes
INSTALLS_SHLIB=	yes

BASEPGSQL=	7.3.4
.if defined(WITHOUT_PGCLUSTER_REPLICATION)
PGRP=		"@comment "
.endif
.if defined(WITHOUT_PGCLUSTER_LOADBALANCER)
PGLB=		"@comment "
.endif
PLIST_SUB=	PGRP=${PGRP} PGLB=${PGLB}
RCSUBR_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}
RCSUBR_SED=	${SED} ${RCSUBR_SUB:S|$|!g|:S|^| -e s!%%|:S|=|%%!|}

MAN1=	clusterdb.1 createdb.1 createlang.1 createuser.1 dropdb.1 droplang.1 \
	dropuser.1 ecpg.1 initdb.1 initlocation.1 ipcclean.1 \
	pg_config.1 pg_controldata.1 pg_ctl.1 pg_dump.1 pg_dumpall.1 \
	pg_resetxlog.1 pg_restore.1 pgtclsh.1 pgtksh.1 \
	postgres.1 postmaster.1 psql.1 vacuumdb.1
MAN7=	abort.7 alter_database.7 alter_group.7 alter_table.7 alter_trigger.7 \
	alter_user.7 analyze.7 begin.7 \
	checkpoint.7 close.7 cluster.7 comment.7 commit.7 copy.7 \
	create_aggregate.7 create_cast.7 create_constraint_trigger.7 \
	create_conversion.7 create_database.7 create_domain.7 \
	create_function.7 create_group.7 create_index.7 create_language.7 \
	create_operator.7 create_operator_class.7 create_rule.7 \
	create_schema.7 create_sequence.7 create_table.7 create_table_as.7 \
	create_trigger.7 create_type.7 create_user.7 create_view.7 \
	deallocate.7 declare.7 delete.7 drop_aggregate.7 drop_cast.7 \
	drop_conversion.7 drop_database.7 drop_domain.7 drop_function.7 \
	drop_group.7 drop_index.7 drop_language.7 drop_operator.7 \
	drop_operator_class.7 drop_rule.7 drop_schema.7 drop_sequence.7 \
	drop_table.7 drop_trigger.7 drop_type.7 drop_user.7 drop_view.7 \
	end.7 execute.7 explain.7 fetch.7 grant.7 insert.7 listen.7 load.7 \
	lock.7 move.7 notify.7 prepare.7 reindex.7 reset.7 revoke.7 \
	rollback.7 select.7 select_into.7 set.7 set_constraints.7 \
	set_session_authorization.7 set_transaction.7 show.7 \
	start_transaction.7 truncate.7 unlisten.7 update.7 vacuum.7

post-patch:
	cd ${WRKSRC}/src/pgcluster/pgrp; ${CHMOD} +x configure missing
	cd ${WRKSRC}/src/pgcluster/pglb; ${CHMOD} +x configure

post-build:
.if !defined(WITHOUT_PGCLUSTER_REPLICATION)
	${MAKE} WRKSRC=${WRKSRC}/src/pgcluster/pgrp do-configure
	${MAKE} WRKSRC=${WRKSRC}/src/pgcluster/pgrp do-build
.endif
.if !defined(WITHOUT_PGCLUSTER_LOADBALANCER)
	${MAKE} WRKSRC=${WRKSRC}/src/pgcluster/pglb do-configure
	${MAKE} WRKSRC=${WRKSRC}/src/pgcluster/pglb do-build
.endif

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

post-install:
.if !defined(WITHOUT_PGCLUSTER_REPLICATION)
	${MAKE} WRKSRC=${WRKSRC}/src/pgcluster/pgrp do-install
	${RCSUBR_SED} ${FILESDIR}/pgreplicate.sh.tmpl > \
		${PREFIX}/etc/rc.d/pgreplicate.sh
	${CHMOD} +x ${PREFIX}/etc/rc.d/pgreplicate.sh
.endif
.if !defined(WITHOUT_PGCLUSTER_LOADBALANCER)
	${MAKE} WRKSRC=${WRKSRC}/src/pgcluster/pglb do-install
	${RCSUBR_SED} ${FILESDIR}/pglb.sh.tmpl > ${PREFIX}/etc/rc.d/pglb.sh
	${CHMOD} +x ${PREFIX}/etc/rc.d/pglb.sh
.endif
	${RCSUBR_SED} ${FILESDIR}/pgcluster.sh.tmpl > \
		${PREFIX}/etc/rc.d/pgcluster.sh
	${CHMOD} +x ${PREFIX}/etc/rc.d/pgcluster.sh

.include <bsd.port.mk>
