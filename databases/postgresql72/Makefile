# New ports collection makefile for:	PostgreSQL
# Date created:		November 13, 1998
# Whom:			Marc G. Fournier <scrappy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	postgresql
PORTVERSION?=	7.2.4
PORTREVISION=	2
CATEGORIES?=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR=	source/v${PORTVERSION}
DISTFILES=	postgresql-base-${PORTVERSION}${EXTRACT_SUFX} \
		postgresql-opt-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER?=	girgen@pingpong.net
COMMENT?=	The most advanced open-source database available anywhere

WRKSRC=		${WRKDIR}/postgresql-${PORTVERSION}
DIST_SUBDIR=	postgresql

LATEST_LINK=	postgresql72
USE_SUBMAKE=	yes
USE_GMAKE=	YES
GNU_CONFIGURE=	YES

.if defined(POSTGRESQL_SUBPORT)
## the POSTGRESQL_SUBPORTS use this port's distinfo
MD5_FILE=	${.CURDIR}/../postgresql72/distinfo
.else

## The rest of this file is for normal base installation
INSTALLS_SHLIB=	YES

CONFIGURE_ARGS=	--enable-locale --enable-syslog --with-CXX \
		--docdir=${PREFIX}/share/doc --with-libdir=${LOCALBASE}/lib \
		--with-includes=${LOCALBASE}/include

.if !defined(WITHOUT_GNUGETOPT)
USE_GETOPT_LONG=yes
.endif

# if you want localized messages, make -DWITH_GETTEXT
# WARNING: this seems to require relinking binaries depending on
# libpq.so, including for example mod_php and tcl.
.if defined(WITH_GETTEXT)
CONFIGURE_ARGS+=--enable-nls
CONFIGURE_ENV+=	"LIBS=-lintl"
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
LIB_DEPENDS+=	intl.5:${PORTSDIR}/devel/gettext-old
PLIST_SUB+=	GETTEXT=""
.else
PLIST_SUB+=	GETTEXT="@comment "
.endif

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+= "--with-openssl=${OPENSSLBASE}"
.endif

MAN1=		createdb.1 createlang.1 createuser.1 dropdb.1 droplang.1 \
		dropuser.1 ecpg.1 initdb.1 initlocation.1 ipcclean.1 pg_config.1 \
		pg_ctl.1 pg_dump.1 pg_dumpall.1 pg_passwd.1 pg_restore.1 \
		pgaccess.1 pgtclsh.1 pgtksh.1 postgres.1 postmaster.1 psql.1 \
		vacuumdb.1
MAN7=		abort.7 alter_group.7 alter_table.7 alter_user.7 analyze.7 \
		begin.7 checkpoint.7 close.7 cluster.7 comment.7 commit.7 copy.7 \
		create_aggregate.7 create_constraint_trigger.7 \
		create_database.7 create_function.7 create_group.7 \
		create_index.7 create_language.7 create_operator.7 \
		create_rule.7 create_sequence.7 create_table.7 \
		create_table_as.7 create_trigger.7 create_type.7 \
		create_user.7 create_view.7 declare.7 delete.7 \
		drop_aggregate.7 drop_database.7 drop_function.7 \
		drop_group.7 drop_index.7 drop_language.7 \
		drop_operator.7 drop_rule.7 drop_sequence.7 \
		drop_table.7 drop_trigger.7 drop_type.7 drop_user.7 \
		drop_view.7 end.7 explain.7 fetch.7 grant.7 insert.7 \
		listen.7 load.7 lock.7 move.7 notify.7 reindex.7 \
		reset.7 revoke.7 rollback.7 select.7 select_into.7 \
		set.7 set_constraints.7 set_transaction.7 show.7 \
		set_session_authorization.7 \
		truncate.7 unlisten.7 update.7 vacuum.7

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		WRKDIR="${WRKDIR}" \
		FILESDIR="${FILESDIR}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \
		DISTNAME="${DISTNAME}"

# We must .include here because we need the Makefile.inc @ pre-install
# to determine the correct plist.
.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

.if defined(WITHOUT_SERVER)
PKGMESSAGE=	${PKGDIR}/pkg-message.client
PLIST_SUB+=	SERVER="@comment "
.else
PLIST_SUB+=	SERVER=""
.endif

.if defined(WITHOUT_MULTIBYTE)
PLIST_SUB+=	MULTIBYTE="@comment "
.else
PLIST_SUB+=	MULTIBYTE=""
CONFIGURE_ARGS+=--enable-multibyte=${MULTIBYTE_ENCODING}
.endif

pre-everything::
	@ ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.postgresql

pre-install:
.if !defined(WITHOUT_SERVER)
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/pkg-install ${PORTNAME} PRE-INSTALL
.endif

post-build:
	@ cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${GMAKE} -C src/interfaces/odbc odbc-drop.sql

post-install:
	@ ${MKDIR} ${PREFIX}/share/postgresql ;\
	${CAT} ${FILESDIR}/post-install-notes ${PKGMESSAGE} |\
		${SED} "s|/usr/local|${PREFIX}|g" |\
		tee ${PREFIX}/share/postgresql/post-install-notes
.if !defined(DEBUG_FLAGS)
.for file in ecpg pg_dump pg_id pg_passwd pg_restore psql
	@ ${STRIP_CMD} ${PREFIX}/bin/${file}
.endfor
.endif
.if !defined(WITHOUT_SERVER)
# install shell defaults for pgsql user
	@ ${STRIP_CMD} ${PREFIX}/bin/postgres
.for i in profile cshrc
	@ ${SED} "s|%%PREFIX%%|${PREFIX}|g" \
		< ${FILESDIR}/dot.$i.in \
		> ${PREFIX}/share/postgresql/dot.$i.dist; \
	${CP} ${PREFIX}/share/postgresql/dot.$i.dist ~pgsql/; \
	if [ ! -f ~pgsql/.$i ]; then \
		${CP} ${PREFIX}/share/postgresql/dot.$i.dist ~pgsql/.$i; \
	fi
.endfor
	@ ${SED} -e "s|%%PREFIX%%|${PREFIX}|g; s|%%PG_PREFIX%%|${PG_PREFIX}|g" \
		< ${FILESDIR}/pgsql.sh.tmpl \
		> ${PREFIX}/etc/rc.d/010.pgsql.sh ;\
	${CHMOD} 554 ${PREFIX}/etc/rc.d/010.pgsql.sh ;\
	${CHOWN} root:pgsql ${PREFIX}/etc/rc.d/010.pgsql.sh ;\
	${INSTALL_DATA} ${PREFIX}/share/postgresql/post-install-notes ~pgsql/. ;\
	${CHOWN} -R pgsql:pgsql ~pgsql/. ;\
	${INSTALL_DATA} ${FILESDIR}/502.pgsql \
			${WRKSRC}/src/interfaces/odbc/odbc.sql \
			${WRKSRC}/src/interfaces/odbc/odbc-drop.sql \
			${PREFIX}/share/postgresql
.else
do-install:
	@ cd ${WRKSRC}; \
	${GMAKE} -C src/bin install ;\
	${GMAKE} -C src/include install ;\
	${GMAKE} -C src/interfaces install
.endif

post-clean:
	@ ${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.mk>
.endif
