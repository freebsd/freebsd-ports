# New ports collection makefile for:   mariadb
# Date created:        14 November 2010
# Whom:                siasia
#
# $FreeBSD$
#

PORTNAME=	mariadb
PORTVERSION=	5.2.5
CATEGORIES=	databases
MASTER_SITES=	http://www.percona.com/downloads/MariaDB/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://ftp.osuosl.org/pub/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://mirrors.supportex.net/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://technocation.org/mirror/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://mirror.aarnet.edu.au/pub/MariaDB/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://ftp-stud.hs-esslingen.de/pub/Mirrors/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://gd.tuwien.ac.at/db/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://mirrors.fe.up.pt/pub/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/

MAINTAINER=	dgeo@centrale-marseille.fr
COMMENT=	A database server - drop-in replacement functionality for MySQL

IGNORE=		Post repo-copy, not ready for use yet

LICENSE=	GPLv2

CONFLICTS=	mysql-server-[0-9]* mysql-client-[0-9]* mysql-scripts-[0-9]*

CONFIGURE_ARGS=	--with-embedded-server

CPPFLAGS+=	-I${LOCALBASE}/include

DATADIR=	${PREFIX}/share/mysql
GNU_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/mysql
USE_RC_SUBR=	mysql-server

USERS=		mysql
GROUPS=		mysql

INFO=		mysql
MAN1=		comp_err.1 \
		innochecksum.1 \
		msql2mysql.1 \
		my_print_defaults.1 \
		myisam_ftdump.1 \
		myisamchk.1 \
		myisamlog.1 \
		myisampack.1 \
		mysql-stress-test.pl.1 \
		mysql-test-run.pl.1 \
		mysql.1 \
		mysql.server.1 \
		mysql_client_test.1 \
		mysql_client_test_embedded.1 \
		mysql_config.1 \
		mysql_convert_table_format.1 \
		mysql_find_rows.1 \
		mysql_fix_extensions.1 \
		mysql_fix_privilege_tables.1 \
		mysql_install_db.1 \
		mysql_secure_installation.1 \
		mysql_setpermission.1 \
		mysql_tzinfo_to_sql.1 \
		mysql_upgrade.1 \
		mysql_waitpid.1 \
		mysql_zap.1 \
		mysqlaccess.1 \
		mysqladmin.1 \
		mysqlbinlog.1 \
		mysqlbug.1 \
		mysqlcheck.1 \
		mysqld_multi.1 \
		mysqld_safe.1 \
		mysqldump.1 \
		mysqldumpslow.1 \
		mysqlhotcopy.1 \
		mysqlimport.1 \
		mysqlman.1 \
		mysqlshow.1 \
		mysqlslap.1 \
		mysqltest.1 \
		mysqltest_embedded.1 \
		perror.1 \
		replace.1 \
		resolve_stack_dump.1 \
		resolveip.1
MAN8=		mysqld.8 \
		mysqlmanager.8

OPTIONS=	ARIADB  "Aria storage engine" On \
		ARCHIVE "Archive storage plugin" On \
		BLACKHOLE       "Blackhole storage engine" On \
		FEDERATED       "Federated (old) storage engine" Off \
		FEDERATEDX      "FederatedX storage engine (Federated replacement)" On \
		INNODB  "InnoDB (old) engine" Off \
		XTRADB  "XtraDB (InnoDB replacement) engine" On \
		OQGRAPH "Open Query Graph Computation engine" Off \
		PBXT    "MVCC-based transactional engine" Off \
		PARTITION       "Partitioning support" Off \
		SPHINX  "SE client for Sphinx search daemon" On \
		NDB     "Enable NDB support (imply PARTITION)" Off \
		EXAMPLES        "Example engine,daemon and ftsearch plugins" Off \
		PORTEVENT       "Use libevent from ports" Off \
		SSL     "Activate SSL support (yassl)" Off \
		OPENSSL "Use OpenSSL instead of bundled yassl" Off

.include <bsd.port.options.mk>

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
CONFIGURE_ARGS+=	--enable-assembler
.endif
.if defined(WITH_SSL)
.if defined(WITH_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}
.else
CONFIGURE_ARGS+=	--with-ssl=bundled
.endif
.else
CONFIGURE_ARGS+=	--without-ssl
.endif
.if defined(WITH_PORTEVENT)
CONFIGURE_ARGS+=	--with-libevent=${LOCALBASE}
LIB_DEPENDS+=	event-1.4:${PORTSDIR}/devel/libevent
.else
CONFIGURE_ARGS+=	--with-libevent=bundled
.endif
.if defined(WITH_ARIADB)
PLIST_SUB+=	ARIADB=""
CONFIGURE_ARGS+=	--with-plugin-aria --with-aria-tmp-tables
.else
CONFIGURE_ARGS+=	--without-plugin-aria
PLIST_SUB+=	ARIADB="@comment "
.endif
.if defined(WITH_SPHINX)
PLIST_SUB+=	SPHINX=""
.else
CONFIGURE_ARGS+=	--without-plugin-sphinx
PLIST_SUB+=	SPHINX="@comment "
.endif
.if defined(WITH_ARIADB)
PLIST_SUB+=	ARIADB=""
.else
CONFIGURE_ARGS+=	--without-plugin-aria
PLIST_SUB+=	ARIADB="@comment "
.endif
.if defined(WITH_ARCHIVE)
PLIST_SUB+=	ARCHIVE=""
.else
CONFIGURE_ARGS+=	--without-plugin-archive
PLIST_SUB+=	ARCHIVE="@comment "
.endif
.if defined(WITH_BLACKHOLE)
PLIST_SUB+=	BLACKHOLE=""
.else
CONFIGURE_ARGS+=	--without-plugin-blackhole
PLIST_SUB+=	BLACKHOLE="@comment "
.endif
.if defined(WITH_FEDERATED)
PLIST_SUB+=	FEDERATED=""
.else
CONFIGURE_ARGS+=	--without-plugin-federated
PLIST_SUB+=	FEDERATED="@comment "
.endif
.if defined(WITH_FEDERATEDX)
PLIST_SUB+=	FEDERATEDX=""
.else
CONFIGURE_ARGS+=	--without-plugin-federatedx
PLIST_SUB+=	FEDERATEDX="@comment "
.endif
.if defined(WITH_INNODB)
PLIST_SUB+=	INNODB=""
.else
CONFIGURE_ARGS+=	--without-plugin-innodb_plugin
PLIST_SUB+=	INNODB="@comment "
.endif
.if defined(WITH_XTRADB)
PLIST_SUB+=	XTRADB=""
.else
CONFIGURE_ARGS+=	--without-plugin-xtradb
PLIST_SUB+=	XTRADB="@comment "
.endif
.if defined(WITH_OQGRAPH)
CONFIGURE_ARGS+=	--with-plugin-oqgraph
PLIST_SUB+=	OQGRAPH=""
LIB_DEPENDS+=	boost_system.4:${PORTSDIR}/devel/boost-libs
.else
CONFIGURE_ARGS+=	--without-plugin-oqgraph
PLIST_SUB+=	OQGRAPH="@comment "
.endif
.if defined(WITH_PBXT)
CONFIGURE_ARGS+=	--with-plugin-pbxt
PLIST_SUB+=	PBXT=""
.else
CONFIGURE_ARGS+=	--without-plugin-pbxt
PLIST_SUB+=	PBXT="@comment "
.endif
.if defined(WITH_EXAMPLES)
PLIST_SUB+=	EXAMPLES=""
.else
CONFIGURE_ARGS+=	--without-plugin-example --without-plugin-daemon_example --without-plugin-ftexample
PLIST_SUB+=	EXAMPLES="@comment "
.endif
.if defined(WITH_NDB)
CONFIGURE_ARGS+=	--with-plugin-ndbcluster
WITH_PARTITION=yes
#MAN1+=       ndb_config.1 ndb_delete_all.1 ndb_desc.1 ndb_drop_index.1 \
#     ndb_drop_table.1 ndb_error_reporter.1 ndb_mgm.1 \
#     ndb_print_backup_file.1 ndb_print_schema_file.1 \
#     ndb_print_sys_file.1 ndb_restore.1 ndb_select_all.1 \
#     ndb_select_count.1 ndb_show_tables.1 ndb_size.pl.1 ndb_waiter.1
PLIST_SUB+=	NDB=""
.else
CONFIGURE_ARGS+=	--without-plugin-ndbcluster
PLIST_SUB+=	NDB="@comment "
.endif
.if defined(WITH_PARTITION)
CONFIGURE_ARGS+=	--with-plugin-partition
.else
CONFIGURE_ARGS+=	--without-plugin-partition
.endif

.if defined(WITH_CHARSET) && ${WITH_CHARSET} != ""
CONFIGURE_ARGS+=	--with-charset=${WITH_CHARSET}
.endif
.if defined(WITH_XCHARSET) && ${WITH_XCHARSET} != ""
CONFIGURE_ARGS+=	--with-extra-charsets=${WITH_XCHARSET}
.endif
.if defined(WITH_COLLATION) && ${WITH_COLLATION} != ""
CONFIGURE_ARGS+=	--with-collation=${WITH_COLLATION}
.endif

pre-fetch:
	@${ECHO} ""
	@${ECHO} "      WITH_CHARSET=charset    Define the primary built-in charset (def: latin1 selected: ${WITH_CHARSET})."
	@${ECHO} "      WITH_XCHARSET=list      Define other built-in charsets (selected: ${WITH_XCHARSET})."
	@${ECHO} "      WITH_COLLATION=collate  Define default collation (def: latin1_swedish_ci selected: ${WITH_COLLATION})."
	@${ECHO} ""

post-patch:
	@${REINPLACE_CMD} -e '/^install:/ s|^\(install:\).*$$|\1|' \
		${WRKSRC}/mysql-test/Makefile.in ${WRKSRC}/sql-bench/Makefile.in

port-install:
	@${CAT} pkg-message

.include <bsd.port.mk>
