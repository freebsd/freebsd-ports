# New ports collection makefile for:	mariadb-server
# Date created:				30 May 2011
# Whom:					Doug Barton <dougb@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	mariadb
PORTVERSION=	5.2.10
PORTREVISION?=	0
CATEGORIES=	databases ipv6
MASTER_SITES=	http://www.percona.com/downloads/MariaDB/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://ftp.osuosl.org/pub/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://mirrors.supportex.net/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://mirror.aarnet.edu.au/pub/MariaDB/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://mirror2.hs-esslingen.de/pub/Mirrors/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://gd.tuwien.ac.at/db/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://mirrors.fe.up.pt/pub/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://mirror.de.gsnw.de:56431/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://mirror.layerjet.com/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://mirror.switch.ch/mirror/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/
PKGNAMESUFFIX?=	-server

MAINTAINER=	dgeo@centrale-marseille.fr
COMMENT?=	Database server - drop-in replacement for MySQL

LICENSE=	GPLv2

UNIQUENAME=	${PORTNAME}${PKGNAMESUFFIX}

CONFLICTS?=	mysql-server-[0-9]*

GNU_CONFIGURE=	yes

.if !defined(MARIADB_CLIENT_SLAVE)
USE_MYSQL=	yes
WANT_MYSQL_VER=	52
.endif

.if !defined(MARIADB_SCRIPTS_SLAVE)
CPPFLAGS+=	-I${LOCALBASE}/include

DATADIR=	${PREFIX}/share/mysql
USE_LDCONFIG=	${PREFIX}/lib/mysql

USERS=		mysql
GROUPS=		mysql

OPTIONS+=	STATIC "Build statically linked (not on 9.x)" Off \
		SSL "Activate SSL support (yassl)" On \
		OPENSSL "Use OpenSSL instead of bundled yassl" Off

MAKE_JOBS_SAFE=	yes

.if !defined(MARIADB_CLIENT_SLAVE)
CONFIGURE_ARGS+=	--with-libevent=${LOCALBASE}
LIB_DEPENDS+=	event-1.4:${PORTSDIR}/devel/libevent

MAN1=	innochecksum.1 my_print_defaults.1 myisam_ftdump.1 myisamchk.1 \
	myisamlog.1 myisampack.1 mysql.server.1 mysql_client_test_embedded.1 \
	mysql_install_db.1 mysql_tzinfo_to_sql.1 mysql_waitpid.1 mysqld_safe.1 \
	mysqltest_embedded.1 perror.1 replace.1 resolve_stack_dump.1 resolveip.1
MAN8=	mysqld.8 mysqlmanager.8

INFO=		mysql

CONFIGURE_ARGS+=	--with-embedded-server --enable-local-infile
USE_RC_SUBR=	mysql-server

OPTIONS+=	ARIADB "Aria storage engine" On \
		ARCHIVE "Archive storage plugin" On \
		BLACKHOLE "Blackhole storage engine" On \
		SPHINX "SE client for Sphinx search daemon" On \
		FEDX "FederatedX storage engine (Federated replacement)" On \
		FEDERATED "Federated (old) storage engine" Off \
		XTRADB "XtraDB (InnoDB replacement) engine" On \
		INNODB "InnoDB (old) engine" Off \
		OQGRAPH "Open Query Graph Computation engine" Off \
		PBXT "MVCC-based transactional engine" Off \
		PARTITION "Partitioning support" Off \
		NDB "Enable NDB support (implies PARTITION)" Off \
		EXAMPLES "Example engine,daemon and ftsearch plugins" Off
.endif	# .if !defined(MARIADB_CLIENT_SLAVE)

.include <bsd.port.options.mk>

.if ${OSVERSION} > 900000 && defined(WITH_STATIC)
BROKEN=	WITH_STATIC is not functional on 9-current
.endif

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
CONFIGURE_ARGS+=	--enable-assembler
.endif
.if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--with-big-tables
.endif
.if defined(WITH_SSL)
.if defined(WITH_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}
.else
CONFIGURE_ARGS+=	--with-ssl=bundled
MDB_EXTRA_SUBDIRS=	extra
.endif
.else
CONFIGURE_ARGS+=	--without-ssl
.endif
.if defined(WITH_STATIC)
CONFIGURE_ARGS+=	--with-client-ldflags="-static -all-static"
.endif
.if defined(WITH_THREADSAFE)
CONFIGURE_ARGS+=	--enable-thread-safe-client
.endif

.if !defined(MARIADB_CLIENT_SLAVE)
.if defined(WITH_ARIADB)
PLIST_SUB+=	ARIADB=""
CONFIGURE_ARGS+=	--with-plugin-aria --with-aria-tmp-tables
PLUGINS+=	aria
.else
CONFIGURE_ARGS+=	--without-plugin-aria
PLIST_SUB+=	ARIADB="@comment "
.endif
.if defined(WITH_SPHINX)
PLIST_SUB+=	SPHINX=""
PLUGINS+=	sphinx
.else
CONFIGURE_ARGS+=	--without-plugin-sphinx
PLIST_SUB+=	SPHINX="@comment "
.endif
.if defined(WITH_ARCHIVE)
PLIST_SUB+=	ARCHIVE=""
PLUGINS+=	archive
.else
CONFIGURE_ARGS+=	--without-plugin-archive
PLIST_SUB+=	ARCHIVE="@comment "
.endif
.if defined(WITH_BLACKHOLE)
PLIST_SUB+=	BLACKHOLE=""
PLUGINS+=	blackhole
.else
CONFIGURE_ARGS+=	--without-plugin-blackhole
PLIST_SUB+=	BLACKHOLE="@comment "
.endif
.if defined(WITH_FEDERATED)
PLIST_SUB+=	FEDERATED=""
PLUGINS+=	federated
.else
CONFIGURE_ARGS+=	--without-plugin-federated
PLIST_SUB+=	FEDERATED="@comment "
.endif
.if defined(WITH_FEDX)
PLIST_SUB+=	FEDERATEDX=""
PLUGINS+=	federatedx
.else
CONFIGURE_ARGS+=	--without-plugin-federatedx
PLIST_SUB+=	FEDERATEDX="@comment "
.endif
.if defined(WITH_INNODB)
PLIST_SUB+=	INNODB=""
PLUGINS+=	innodb_plugin
.else
CONFIGURE_ARGS+=	--without-plugin-innodb_plugin
PLIST_SUB+=	INNODB="@comment "
.endif
.if defined(WITH_XTRADB)
PLIST_SUB+=	XTRADB=""
PLUGINS+=	xtradb
.else
CONFIGURE_ARGS+=	--without-plugin-xtradb
PLIST_SUB+=	XTRADB="@comment "
.endif
.if defined(WITH_OQGRAPH)
CONFIGURE_ARGS+=	--with-plugin-oqgraph
PLIST_SUB+=	OQGRAPH=""
LIB_DEPENDS+=	boost_system.4:${PORTSDIR}/devel/boost-libs
PLUGINS+=	oqgraph
.else
CONFIGURE_ARGS+=	--without-plugin-oqgraph
PLIST_SUB+=	OQGRAPH="@comment "
.endif
.if defined(WITH_PBXT)
CONFIGURE_ARGS+=	--with-plugin-pbxt
PLIST_SUB+=	PBXT=""
PLUGINS+=	pbxt
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
PLIST_SUB+=	NDB=""
PLUGINS+=	ndbcluster
.else
CONFIGURE_ARGS+=	--without-plugin-ndbcluster
PLIST_SUB+=	NDB="@comment "
.endif
.if defined(WITH_PARTITION)
CONFIGURE_ARGS+=	--with-plugin-partition
PLUGINS+=	partition
.else
CONFIGURE_ARGS+=	--without-plugin-partition
.endif
.if defined(WITH_STATIC)
CONFIGURE_ARGS+=	--with-mysqld-ldflags="-static -all-static" --with-plugins="${PLUGINS}"
PLIST_SUB+=	STATIC="@comment "
.else
PLIST_SUB+=	STATIC=""
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

.if defined(WITH_STATIC) && ( defined(WITH_OPENSSL) || defined(WITH_NDB) )
pre-extract:
	@${ECHO} ''
	@${ECHO} "WITH_STATIC is not compatible with WITH_OPENSSL or WITH_NDB"
	@${ECHO} ''
	@${FALSE}
.endif

.if !defined(MARIADB_CLIENT_SLAVE)
.if !defined(WITH_STATIC)
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

EXTRA_PATCHES=	${FILESDIR}/scripts__Makefile.in
MDB_SERVER_SUBDIRS=	include @docs_dirs@ sql-common libservices mysys strings dbug ${MDB_EXTRA_SUBDIRS} unittest cmd-line-utils libmysql scripts @sql_server_dirs@ @sql_server@ @man_dirs@ @libmysqld_dirs@ support-files

post-patch:
	@${REINPLACE_CMD} -e "s|%%SUBDIRS%%|${MDB_SERVER_SUBDIRS}|" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|%%MANS%%|${MAN1}|" ${WRKSRC}/man/Makefile.in
	@${REINPLACE_CMD} -e "s|^\(install:\).*|\1|" ${WRKSRC}/mysql-test/Makefile.in ${WRKSRC}/sql-bench/Makefile.in
	@${REINPLACE_CMD} -e "s|^\(aclocal_DATA =\).*|\1|" ${WRKSRC}/support-files/Makefile.in
	@${REINPLACE_CMD} -e "s|^\(pkginclude_HEADERS =\).*|\1|" ${WRKSRC}/cmd-line-utils/libedit/Makefile.in
	@${REINPLACE_CMD} -e "s|^\(install-data-am:\) install-pkgincludeHEADERS|\1|g" ${WRKSRC}/extra/Makefile.in ${WRKSRC}/include/Makefile.in
	@${REINPLACE_CMD} -e "s|^\(install-exec-am:\) install-pkglibLTLIBRARIES|\1|g" ${WRKSRC}/libmysql/Makefile.in

.if !defined(WITH_STATIC)
post-install:
	@${CAT} ${PKGMESSAGE}
.endif
.endif	# .if !defined(MARIADB_CLIENT_SLAVE)
.endif	# .if !defined(MARIADB_SCRIPTS_SLAVE)

.include <bsd.port.mk>
