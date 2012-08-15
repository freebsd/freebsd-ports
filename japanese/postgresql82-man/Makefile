# New ports collection makefile for:	ja-postgresql-man
# Date created:				2003/05/20
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	postgresql82
PORTVERSION=	8.2.4
CATEGORIES=	japanese databases
MASTER_SITES=	http://www.postgresql.jp/document/pg${PORTVERSION:C/\.//g}doc/
PKGNAMESUFFIX=	-man
DISTNAME=	man
DIST_SUBDIR=	postgresql/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese online manual pages for PostgreSQL

MANLANG=	ja
NO_BUILD=	YES
NO_WRKSUBDIR=	YES

MAN1=		clusterdb.1 \
		createdb.1 \
		createlang.1 \
		createuser.1 \
		dropdb.1 \
		droplang.1 \
		dropuser.1 \
		ecpg.1 \
		initdb.1 \
		ipcclean.1 \
		pg_config.1 \
		pg_controldata.1 \
		pg_ctl.1 \
		pg_dump.1 \
		pg_dumpall.1 \
		pg_resetxlog.1 \
		pg_restore.1 \
		postgres.1 \
		postmaster.1 \
		psql.1 \
		reindexdb.1 \
		vacuumdb.1

MANL=		abort.l \
		alter_aggregate.l \
		alter_conversion.l \
		alter_database.l \
		alter_domain.l \
		alter_function.l \
		alter_group.l \
		alter_index.l \
		alter_language.l \
		alter_operator.l \
		alter_operator_class.l \
		alter_role.l \
		alter_schema.l \
		alter_sequence.l \
		alter_table.l \
		alter_tablespace.l \
		alter_trigger.l \
		alter_type.l \
		alter_user.l \
		analyze.l \
		begin.l \
		checkpoint.l \
		close.l \
		cluster.l \
		comment.l \
		commit.l \
		commit_prepared.l \
		copy.l \
		create_aggregate.l \
		create_cast.l \
		create_constraint_trigger.l \
		create_conversion.l \
		create_database.l \
		create_domain.l \
		create_function.l \
		create_group.l \
		create_index.l \
		create_language.l \
		create_operator.l \
		create_operator_class.l \
		create_role.l \
		create_rule.l \
		create_schema.l \
		create_sequence.l \
		create_table.l \
		create_table_as.l \
		create_tablespace.l \
		create_trigger.l \
		create_type.l \
		create_user.l \
		create_view.l \
		deallocate.l \
		declare.l \
		delete.l \
		drop_aggregate.l \
		drop_cast.l \
		drop_conversion.l \
		drop_database.l \
		drop_domain.l \
		drop_function.l \
		drop_group.l \
		drop_index.l \
		drop_language.l \
		drop_operator.l \
		drop_operator_class.l \
		drop_owned.l \
		drop_role.l \
		drop_rule.l \
		drop_schema.l \
		drop_sequence.l \
		drop_table.l \
		drop_tablespace.l \
		drop_trigger.l \
		drop_type.l \
		drop_user.l \
		drop_view.l \
		end.l \
		execute.l \
		explain.l \
		fetch.l \
		grant.l \
		insert.l \
		listen.l \
		load.l \
		lock.l \
		move.l \
		notify.l \
		prepare.l \
		prepare_transaction.l \
		reassign_owned.l \
		reindex.l \
		release_savepoint.l \
		reset.l \
		revoke.l \
		rollback.l \
		rollback_prepared.l \
		rollback_to_savepoint.l \
		savepoint.l \
		select.l \
		select_into.l \
		set.l \
		set_constraints.l \
		set_role.l \
		set_session_authorization.l \
		set_transaction.l \
		show.l \
		start_transaction.l \
		truncate.l \
		unlisten.l \
		update.l \
		vacuum.l \
		values.l

do-install:
.for file in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/man1/${file} ${MANPREFIX}/man/${MANLANG}/man1/
.endfor
.for file in ${MANL}
	@${INSTALL_MAN} ${WRKSRC}/manl/${file} ${MANPREFIX}/man/${MANLANG}/manl/
.endfor

.include <bsd.port.mk>
