# $FreeBSD$

PORTNAME=	mariadb
PORTVERSION=	5.3.12
PORTREVISION?=	6
CATEGORIES=	databases ipv6
MASTER_SITES=	http://ftp.osuosl.org/pub/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://mirrors.supportex.net/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://mirror.aarnet.edu.au/pub/MariaDB/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://mirror2.hs-esslingen.de/pub/Mirrors/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://gd.tuwien.ac.at/db/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://mirrors.fe.up.pt/pub/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://mirror.de.gsnw.de:56431/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://mirror.layerjet.com/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://mirror.switch.ch/mirror/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/
PKGNAMESUFFIX?=	53-server

MAINTAINER=	spil.oss@gmail.com
COMMENT=	Database server - drop-in replacement for MySQL

LICENSE=	GPLv2

CONFLICTS?=	mariadb5[4-9]-server-* \
		mariadb1[0-9][0-9]-server-* \
		mysql*-server-* \
		percona*-server-*

GNU_CONFIGURE=	yes
USES+=		libtool shebangfix
SHEBANG_FILES=	scripts/*

.if !defined(MARIADB_CLIENT_SLAVE)
USE_MYSQL=	yes
WANT_MYSQL_VER=	53m
.endif

.if !defined(MARIADB_SCRIPTS_SLAVE)
CPPFLAGS+=	-I${LOCALBASE}/include

DATADIR=	${PREFIX}/share/mysql
USE_LDCONFIG=	${PREFIX}/lib/mysql

USERS=		mysql
GROUPS=		mysql

OPTIONS_DEFINE+=	STATIC SSL OPENSSL
OPTIONS_DEFAULT+=	SSL
STATIC_DESC=	Statically link executables (not on 9.x)
SSL_DESC=	Activate SSL support
OPENSSL_DESC=	Use OpenSSL instead of bundled yassl

.if !defined(MARIADB_CLIENT_SLAVE)
LIB_DEPENDS=	libevent.so:${PORTSDIR}/devel/libevent2

MANS=	innochecksum.1 my_print_defaults.1 myisam_ftdump.1 myisamchk.1 \
	myisamlog.1 myisampack.1 mysql.server.1 mysql_client_test_embedded.1 \
	mysql_install_db.1 mysql_tzinfo_to_sql.1 mysql_waitpid.1 mysqld_safe.1 \
	mysqltest_embedded.1 perror.1 replace.1 resolve_stack_dump.1 resolveip.1

INFO=		mysql

CONFIGURE_ARGS+=	--with-embedded-server --enable-local-infile
USE_RC_SUBR=	mysql-server

OPTIONS_DEFINE+=	ARIADB ARCHIVE BLACKHOLE SPHINX FEDX FEDERATED XTRADB INNODB \
			OQGRAPH PBXT PARTITION HANDLERSOCKET EXAMPLES MAXKEY

ARIADB_DESC=		Aria storage engine
ARCHIVE_DESC=		Archive storage plugin
BLACKHOLE_DESC=		Blackhole storage engine
SPHINX_DESC=		SE client for Sphinx search daemon
FEDX_DESC=		FederatedX (new) storage engine
FEDERATED_DESC=		Federated (old) storage engine
XTRADB_DESC=		XtraDB (InnoDB replacement) engine
INNODB_DESC=		InnoDB (old) engine
OQGRAPH_DESC=		Open Query Graph Computation engine
PBXT_DESC=		MVCC-based transactional engine
PARTITION_DESC=		Partitioning support
HANDLERSOCKET_DESC=	HandlerSocket support
NDB_DESC=		Enable NDB support (implies PARTITION)
EXAMPLES_DESC=		Example engine,daemon and ftsearch plugins
MAXKEY_DESC=		Change max key length from 1000 to 4000

OPTIONS_DEFAULT+=	ARIADB ARCHIVE BLACKHOLE SPHINX FEDX XTRADB HANDLERSOCKET
.endif	# .if !defined(MARIADB_CLIENT_SLAVE)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSTATIC}
BROKEN=	WITH_STATIC is not functional on 9-current
.endif

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
CONFIGURE_ARGS+=	--enable-assembler
.endif
.if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--with-big-tables
.endif
.if ${PORT_OPTIONS:MSSL}
.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}
.else
CONFIGURE_ARGS+=	--with-ssl=bundled
MDB_EXTRA_SUBDIRS=	extra
.endif
.else
CONFIGURE_ARGS+=	--without-ssl
.endif
.if ${PORT_OPTIONS:MSTATIC}
CONFIGURE_ARGS+=	--with-client-ldflags="-static -all-static"
.endif
.if ${PORT_OPTIONS:MTHREADSAFE}
CONFIGURE_ARGS+=	--enable-thread-safe-client
.endif

.if !defined(MARIADB_CLIENT_SLAVE)
.if ${PORT_OPTIONS:MARIADB}
PLIST_SUB+=	ARIADB=""
CONFIGURE_ARGS+=	--with-plugin-aria --with-aria-tmp-tables
PLUGINS+=	aria
.else
CONFIGURE_ARGS+=	--without-plugin-aria
PLIST_SUB+=	ARIADB="@comment "
.endif
.if ${PORT_OPTIONS:MSPHINX}
PLIST_SUB+=	SPHINX=""
PLUGINS+=	sphinx
.else
CONFIGURE_ARGS+=	--without-plugin-sphinx
PLIST_SUB+=	SPHINX="@comment "
.endif
.if ${PORT_OPTIONS:MARCHIVE}
PLIST_SUB+=	ARCHIVE=""
PLUGINS+=	archive
.else
CONFIGURE_ARGS+=	--without-plugin-archive
PLIST_SUB+=	ARCHIVE="@comment "
.endif
.if ${PORT_OPTIONS:MBLACKHOLE}
PLIST_SUB+=	BLACKHOLE=""
PLUGINS+=	blackhole
.else
CONFIGURE_ARGS+=	--without-plugin-blackhole
PLIST_SUB+=	BLACKHOLE="@comment "
.endif
.if ${PORT_OPTIONS:MFEDERATED}
PLIST_SUB+=	FEDERATED=""
PLUGINS+=	federated
.else
CONFIGURE_ARGS+=	--without-plugin-federated
PLIST_SUB+=	FEDERATED="@comment "
.endif
.if ${PORT_OPTIONS:MFEDX}
PLIST_SUB+=	FEDERATEDX=""
PLUGINS+=	federatedx
.else
CONFIGURE_ARGS+=	--without-plugin-federatedx
PLIST_SUB+=	FEDERATEDX="@comment "
.endif
.if ${PORT_OPTIONS:MINNODB}
PLIST_SUB+=	INNODB=""
PLUGINS+=	innodb_plugin
.else
CONFIGURE_ARGS+=	--without-plugin-innodb_plugin
PLIST_SUB+=	INNODB="@comment "
.endif
.if ${PORT_OPTIONS:MXTRADB}
PLIST_SUB+=	XTRADB=""
PLUGINS+=	xtradb
.else
CONFIGURE_ARGS+=	--without-plugin-xtradb
PLIST_SUB+=	XTRADB="@comment "
.endif
.if ${PORT_OPTIONS:MHANDLERSOCKET}
PLIST_SUB+=	HANDLERSOCKET=""
PLUGINS+=	handlersocket
.else
CONFIGURE_ARGS+=	--without-plugin-handlersocket
PLIST_SUB+=	HANDLERSOCKET="@comment "
.endif
.if ${PORT_OPTIONS:MOQGRAPH}
CONFIGURE_ARGS+=	--with-plugin-oqgraph
PLIST_SUB+=	OQGRAPH=""
LIB_DEPENDS+=	libboost_system.so:${PORTSDIR}/devel/boost-libs
PLUGINS+=	oqgraph
.else
CONFIGURE_ARGS+=	--without-plugin-oqgraph
PLIST_SUB+=	OQGRAPH="@comment "
.endif
.if ${PORT_OPTIONS:MPBXT}
CONFIGURE_ARGS+=	--with-plugin-pbxt
PLIST_SUB+=	PBXT=""
PLUGINS+=	pbxt
.else
CONFIGURE_ARGS+=	--without-plugin-pbxt
PLIST_SUB+=	PBXT="@comment "
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
PLIST_SUB+=	EXAMPLES=""
.else
CONFIGURE_ARGS+=	--without-plugin-example --without-plugin-daemon_example --without-plugin-ftexample
PLIST_SUB+=	EXAMPLES="@comment "
.endif
.if ${PORT_OPTIONS:MNDB}
CONFIGURE_ARGS+=	--with-plugin-ndbcluster
WITH_PARTITION=yes
PLIST_SUB+=	NDB=""
PLUGINS+=	ndbcluster
.else
CONFIGURE_ARGS+=	--without-plugin-ndbcluster
PLIST_SUB+=	NDB="@comment "
.endif
.if ${PORT_OPTIONS:MPARTITION}
CONFIGURE_ARGS+=	--with-plugin-partition
PLUGINS+=	partition
.else
CONFIGURE_ARGS+=	--without-plugin-partition
.endif
.if ${PORT_OPTIONS:MSTATIC}
CONFIGURE_ARGS+=	--with-mysqld-ldflags="-static -all-static" --with-plugins="${PLUGINS}"
PLIST_SUB+=	STATIC="@comment "
.else
PLIST_SUB+=	STATIC=""
.endif
.if ${PORT_OPTIONS:MMAXKEY}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-include__my_handler.h
.endif
.endif	# .if !defined(MARIADB_CLIENT_SLAVE)

.if defined(WITH_CHARSET) && ${WITH_CHARSET} != ""
CONFIGURE_ARGS+=	--with-charset=${WITH_CHARSET}
.endif
.if defined(WITH_XCHARSET) && ${WITH_XCHARSET} != ""
CONFIGURE_ARGS+=	--with-extra-charsets=${WITH_XCHARSET}
.else
CONFIGURE_ARGS+=	--with-extra-charsets=complex
.endif
.if defined(WITH_COLLATION) && ${WITH_COLLATION} != ""
CONFIGURE_ARGS+=	--with-collation=${WITH_COLLATION}
.endif

.if ${PORT_OPTIONS:MSTATIC} && ( ${PORT_OPTIONS:MOPENSSL} || ${PORT_OPTIONS:MNDB} )
pre-extract:
	@${ECHO} ''
	@${ECHO} "STATIC is not compatible with OPENSSL or NDB"
	@${ECHO} ''
	@${FALSE}
.endif

.if !defined(MARIADB_CLIENT_SLAVE)
.if empty(PORT_OPTIONS:MSTATIC)
SUB_FILES=	pkg-message
.endif

pre-fetch:
	@${ECHO} ''
	@${ECHO} '	The following configuration options can be set in /etc/make.conf'
	@${ECHO} ''
	@${ECHO} "	WITH_COLLATION=collate"
	@${ECHO} "		Default collation (default: latin1_swedish_ci, selected: ${WITH_COLLATION})."
	@${ECHO} "	WITH_CHARSET=charset"
	@${ECHO} "		Primary built-in charset (default: latin1, selected: ${WITH_CHARSET})."
	@${ECHO} "	WITH_XCHARSET=list"
	@${ECHO} "		Other built-in charsets (default: complex, selected: ${WITH_XCHARSET})."
	@${ECHO} ''

EXTRA_PATCHES+=	${FILESDIR}/scripts__Makefile.in
MDB_SERVER_SUBDIRS=	include @docs_dirs@ sql-common libservices mysys strings dbug ${MDB_EXTRA_SUBDIRS} unittest cmd-line-utils libmysql scripts @sql_server_dirs@ @sql_server@ @man_dirs@ @libmysqld_dirs@ support-files

post-patch:
	@${REINPLACE_CMD} -e "s|%%SUBDIRS%%|${MDB_SERVER_SUBDIRS}|" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|%%MANS%%|${MANS}|" ${WRKSRC}/man/Makefile.in
	@${REINPLACE_CMD} -e "s|^\(install:\).*|\1|" ${WRKSRC}/mysql-test/Makefile.in ${WRKSRC}/sql-bench/Makefile.in
	@${REINPLACE_CMD} -e "s|^\(aclocal_DATA =\).*|\1|" ${WRKSRC}/support-files/Makefile.in
	@${REINPLACE_CMD} -e "s|^\(pkginclude_HEADERS =\).*|\1|" ${WRKSRC}/cmd-line-utils/libedit/Makefile.in
	@${REINPLACE_CMD} -e "s|^\(install-data-am:\) install-pkgincludeHEADERS|\1|g" ${WRKSRC}/extra/Makefile.in ${WRKSRC}/include/Makefile.in
	@${REINPLACE_CMD} -e "s|^\(install-exec-am:\) install-pkglibLTLIBRARIES|\1|g" ${WRKSRC}/libmysql/Makefile.in
	@${REINPLACE_CMD} -e "s|-fno-implicit-templates||g" ${WRKSRC}/configure

post-stage:
	# Delete files that should only be installed by client
	@${RM} ${STAGEDIR}/${PREFIX}/bin/mysql_convert_table_format
	@${RM} ${STAGEDIR}/${PREFIX}/bin/mysql_find_rows
	@${RM} ${STAGEDIR}/${PREFIX}/bin/mysql_fix_extensions
	@${RM} ${STAGEDIR}/${PREFIX}/bin/mysql_secure_installation
	@${RM} ${STAGEDIR}/${PREFIX}/bin/mysql_setpermission
	@${RM} ${STAGEDIR}/${PREFIX}/bin/mysql_zap
	@${RM} ${STAGEDIR}/${PREFIX}/bin/mysqlaccess
	@${RM} ${STAGEDIR}/${PREFIX}/bin/mysqld_multi
	@${RM} ${STAGEDIR}/${PREFIX}/bin/mysqldumpslow
	@${RM} ${STAGEDIR}/${PREFIX}/bin/mysqlhotcopy
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/client_plugin.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/decimal.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/errmsg.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/keycache.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/m_ctype.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/m_string.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/ma_dyncol.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/my_alloc.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/my_attribute.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/my_compiler.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/my_config.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/my_dbug.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/my_decimal_limits.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/my_dir.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/my_getopt.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/my_global.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/my_list.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/my_net.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/my_no_pthread.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/my_pthread.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/my_sys.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/my_valgrind.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/my_xml.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/mysql.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/mysql_com.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/mysql_embed.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/mysql_time.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/mysql_version.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/plugin.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/plugin_auth.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/plugin_auth_common.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/service_my_snprintf.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/service_progress_report.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/service_thd_alloc.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/services.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/sql_common.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/sslopt-case.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/sslopt-longopts.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/sslopt-vars.h
	@${RM} ${STAGEDIR}/${PREFIX}/include/mysql/typelib.h

.endif	# .if !defined(MARIADB_CLIENT_SLAVE)
.endif	# .if !defined(MARIADB_SCRIPTS_SLAVE)

.include <bsd.port.mk>
