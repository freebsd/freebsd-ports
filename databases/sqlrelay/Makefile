# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	${SQLRELAY_PORTNAME}
PORTVERSION=	${SQLRELAY_PORTVERSION}
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Persistent DB connection pooling/proxying/load balancing system

LICENSE=	LGPL20

LIB_DEPENDS=	librudiments.so:devel/rudiments

WANT_GNOME=	yes
USES=		gmake libtool python
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=		${SQLRELAY_CONFIGURE_ARGS} \
			--disable-tcl \
			--disable-java \
			--disable-nodejs \
			--disable-perl \
			--disable-php \
			--disable-python \
			--disable-python3 \
			--disable-ruby \
			--disable-erlang
MAKE_JOBS_UNSAFE=yes
USE_LDCONFIG=	yes

PORTDOCS=	*

TOSTRIP=	bin/sqlr-start \
		bin/sqlr-stop \
		bin/sqlr-listener \
		bin/sqlr-connection \
		bin/sqlr-scaler \
		bin/sqlr-cachemanager \
		bin/sqlr-fields \
		bin/sqlr-query \
		bin/sqlr-export \
		bin/sqlr-import \
		bin/sqlr-pwdenc \
		bin/sqlr-status \
		bin/sqlrsh \
		lib/libsqlrodbc.so.2.0.0 \
		lib/libsqlrutil.so.2.0.0 \
		lib/libsqlrclient.so.2.0.0 \
		lib/libsqlrclientwrapper.so.2.0.0 \
		lib/libpqsqlrelay.so.2.0.0 \
		lib/libmysql3sqlrelay.so.2.0.0 \
		lib/libmysql40sqlrelay.so.2.0.0 \
		lib/libmysql41sqlrelay.so.2.0.0 \
		lib/libmysql50sqlrelay.so.2.0.0 \
		lib/libmysql51sqlrelay.so.2.0.0 \
		lib/libsqlrserver.so.2.0.0 \
		libexec/sqlrelay/sqlrauth_database.so \
		libexec/sqlrelay/sqlrauth_krb_userlist.so \
		libexec/sqlrelay/sqlrauth_proxied.so \
		libexec/sqlrelay/sqlrauth_sqlrelay.so \
		libexec/sqlrelay/sqlrauth_tls_userlist.so \
		libexec/sqlrelay/sqlrauth_userlist.so \
		libexec/sqlrelay/sqlrconfig_xml.so \
		libexec/sqlrelay/sqlrconfig_xmldom.so \
		libexec/sqlrelay/sqlrconnection_router.so \
		libexec/sqlrelay/sqlrfilter_patterns.so \
		libexec/sqlrelay/sqlrfilter_regex.so \
		libexec/sqlrelay/sqlrfilter_string.so \
		libexec/sqlrelay/sqlrlogger_custom_nw.so \
		libexec/sqlrelay/sqlrlogger_custom_sc.so \
		libexec/sqlrelay/sqlrlogger_debug.so \
		libexec/sqlrelay/sqlrlogger_slowqueries.so \
		libexec/sqlrelay/sqlrparser_default.so \
		libexec/sqlrelay/sqlrprotocol_sqlrclient.so \
		libexec/sqlrelay/sqlrpwdenc_crypt.so \
		libexec/sqlrelay/sqlrpwdenc_md5.so \
		libexec/sqlrelay/sqlrpwdenc_rot.so \
		libexec/sqlrelay/sqlrquery_sqlrcmdcstat.so \
		libexec/sqlrelay/sqlrquery_sqlrcmdgstat.so \
		libexec/sqlrelay/sqlrresultsettranslation_reformatdatetime.so \
		libexec/sqlrelay/sqlrtranslation_normalize.so

.include "${.CURDIR}/Makefile.common"

OPTIONS_DEFINE=	MYSQL ODBC ORACLE PGSQL SQLITE3 FREETDS FIREBIRD DOCS
OPTIONS_SUB=	yes

ORACLE_CONFIGURE_ENABLE=	oracle

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSQLITE3}
LIB_DEPENDS+=		libgdbm.so:databases/gdbm \
			libsqlite3.so:databases/sqlite3
CONFIGURE_ARGS+=	--with-gdbm-prefix="${LOCALBASE}" \
			--with-sqlite-prefix="${LOCALBASE}"
TOSTRIP+=		libexec/sqlrelay/sqlrconnection_sqlite.so
.else
CONFIGURE_ARGS+=	--disable-sqlite
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql-prefix="${LOCALBASE}"
TOSTRIP+=		libexec/sqlrelay/sqlrconnection_mysql.so
.else
CONFIGURE_ARGS+=	--disable-mysql
.endif

.if ${PORT_OPTIONS:MFIREBIRD}
USES+=		firebird
CONFIGURE_ARGS+=	--with-firebird-prefix="${LOCALBASE}"
TOSTRIP+=		libexec/sqlrelay/sqlrconnection_firebird.so
.else
CONFIGURE_ARGS+=	--disable-firebird
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=			pgsql
CONFIGURE_ARGS+=	--with-postgresql-prefix="${LOCALBASE}"
TOSTRIP+=		libexec/sqlrelay/sqlrconnection_postgresql.so
.else
CONFIGURE_ARGS+=	--disable-postgresql
.endif

.if ${PORT_OPTIONS:MODBC}
LIB_DEPENDS+=		libodbc.so:databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc-prefix="${LOCALBASE}"
TOSTRIP+=		libexec/sqlrelay/sqlrconnection_odbc.so
.else
CONFIGURE_ARGS+=	--disable-odbc
.endif

.if ${PORT_OPTIONS:MFREETDS}
LIB_DEPENDS+=		libtdsodbc.so:databases/freetds
CONFIGURE_ARGS+=	--with-freetds-prefix="${LOCALBASE}"
TOSTRIP+=		libexec/sqlrelay/sqlrconnection_freetds.so
.else
CONFIGURE_ARGS+=	--disable-freetds
.endif

post-patch:
	${REINPLACE_CMD} -E \
		-e 's,\$$\(initroot\),\$$\(initroot\)${PREFIX},g' \
		-e 's,/etc/rc.conf,/etc/defaults/rc.conf,g' \
			${WRKSRC}/init/Makefile
	${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} -E \
		-e 's#-release \$$\(SQLR_VERSION\)##g;'

post-configure:
	@${REINPLACE_CMD} 's,-Werror,,' ${WRKSRC}/config.mk

post-stage:
.for f in ${TOSTRIP}
	-${STRIP_CMD} ${STAGEDIR}${PREFIX}/${f}
.endfor
	${RM} ${STAGEDIR}${PREFIX}/lib/SQLRClient.dll
	${RM} ${STAGEDIR}${PREFIX}/lib/SQLRClient.dll.config

.include <bsd.port.mk>
