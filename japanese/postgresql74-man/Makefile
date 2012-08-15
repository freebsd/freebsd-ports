# New ports collection makefile for:	ja-postgresql-man
# Date created:				2003/05/20
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	postgresql74
PORTVERSION=	7.4.6
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
		initlocation.1 \
		ipcclean.1 \
		pg_config.1 \
		pg_controldata.1 \
		pg_ctl.1 \
		pg_dump.1 \
		pg_dumpall.1 \
		pg_resetxlog.1 \
		pg_restore.1 \
		pgtclsh.1 \
		pgtksh.1 \
		postgres.1 \
		postmaster.1 \
		psql.1 \
		vacuumdb.1

MANL=		abort.l \
		alter_aggregate.l \
		alter_conversion.l \
		alter_database.l \
		alter_domain.l \
		alter_function.l \
		alter_group.l \
		alter_language.l \
		alter_operator_class.l \
		alter_schema.l \
		alter_sequence.l \
		alter_table.l \
		alter_trigger.l \
		alter_user.l \
		analyze.l \
		begin.l \
		checkpoint.l \
		close.l \
		cluster.l \
		comment.l \
		commit.l \
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
		create_rule.l \
		create_schema.l \
		create_sequence.l \
		create_table.l \
		create_table_as.l \
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
		drop_rule.l \
		drop_schema.l \
		drop_sequence.l \
		drop_table.l \
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
		pg_conndefaults.l \
		pg_connect.l \
		pg_disconnect.l \
		pg_exec.l \
		pg_execute.l \
		pg_listen.l \
		pg_lo_close.l \
		pg_lo_creat.l \
		pg_lo_export.l \
		pg_lo_import.l \
		pg_lo_lseek.l \
		pg_lo_open.l \
		pg_lo_read.l \
		pg_lo_tell.l \
		pg_lo_unlink.l \
		pg_lo_write.l \
		pg_on_connection_loss.l \
		pg_result.l \
		pg_select.l \
		prepare.l \
		reindex.l \
		reset.l \
		revoke.l \
		rollback.l \
		select.l \
		select_into.l \
		set.l \
		set_constraints.l \
		set_session_authorization.l \
		set_transaction.l \
		show.l \
		spi_connect.l \
		spi_copytuple.l \
		spi_copytupledesc.l \
		spi_copytupleintoslot.l \
		spi_cursor_close.l \
		spi_cursor_fetch.l \
		spi_cursor_find.l \
		spi_cursor_move.l \
		spi_cursor_open.l \
		spi_exec.l \
		spi_execp.l \
		spi_finish.l \
		spi_fname.l \
		spi_fnumber.l \
		spi_freeplan.l \
		spi_freetuple.l \
		spi_freetuptable.l \
		spi_getbinval.l \
		spi_getrelname.l \
		spi_gettype.l \
		spi_gettypeid.l \
		spi_getvalue.l \
		spi_modifytuple.l \
		spi_palloc.l \
		spi_pfree.l \
		spi_prepare.l \
		spi_repalloc.l \
		spi_saveplan.l \
		start_transaction.l \
		truncate.l \
		unlisten.l \
		update.l \
		vacuum.l

do-install:
.for file in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/man1/${file} ${MANPREFIX}/man/${MANLANG}/man1/
.endfor
.for file in ${MANL}
	@${INSTALL_MAN} ${WRKSRC}/manl/${file} ${MANPREFIX}/man/${MANLANG}/manl/
.endfor

.include <bsd.port.mk>
