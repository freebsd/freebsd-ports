# $FreeBSD$

PORTNAME?=	mariadb
PORTVERSION=	10.2.7
PORTREVISION?=	1
CATEGORIES=	databases ipv6
MASTER_SITES=	http://mirrors.supportex.net/${SITESDIR}/ \
		http://mirror2.hs-esslingen.de/pub/Mirrors/${SITESDIR}/ \
		http://gd.tuwien.ac.at/db/${SITESDIR}/ \
		http://mirrors.fe.up.pt/pub/${SITESDIR}/ \
		http://mirror.de.gsnw.de:56431/${SITESDIR}/ \
		http://mirror.layerjet.com/${SITESDIR}/ \
		http://mirror.switch.ch/mirror/${SITESDIR}/ \
		http://ftp.osuosl.org/pub/${SITESDIR}/
PKGNAMESUFFIX?=	102-server

MAINTAINER=	brnrd@FreeBSD.org
COMMENT?=	Multithreaded SQL database (server)

LICENSE=	GPLv2
LICENSE_NAME_PerconaFT=	PerconaFT patents license
LICENSE_FILE_PerconaFT=	${WRKSRC}/storage/tokudb/PerconaFT/PATENTS
LICENSE_PERMS_PerconaFT=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_aarch64=		fails to link: stacktrace.c: undefined reference to 'sbrk'

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

SLAVEDIRS=	databases/mariadb102-client
USES=		bison:build cmake compiler:c++11-lib cpe execinfo iconv:translit libedit ncurses shebangfix ssl
USE_LDCONFIG=	${PREFIX}/lib/mysql
SHEBANG_FILES=	scripts/*.sh
SITESDIR=	mariadb/mariadb-${PORTVERSION}/source
DOCSDIR=	${PREFIX}/share/doc/mysql

OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE
OPTIONS_DEFAULT=	GSSAPI_BASE

.if !defined(CLIENT_ONLY)
# MySQL-Server options
OPTIONS_DEFAULT+=	CONNECT_EXTRA INNOBASE SPHINX SPIDER
OPTIONS_GROUP=		COMPRESSION ENGINES GROONGA
OPTIONS_DEFINE=		CONNECT_EXTRA
OPTIONS_GROUP_COMPRESSION=	LZ4 LZO SNAPPY ZSTD
OPTIONS_GROUP_ENGINES=	INNOBASE MROONGA OQGRAPH ROCKSDB SPHINX SPIDER TOKUDB XTRADB
OPTIONS_GROUP_GROONGA=	ZMQ MSGPACK
OPTIONS_EXCLUDE_i386=	TOKUDB

CONNECT_EXTRA_DESC=	Enable ODBC and XML in CONNECT engine
COMPRESSION_DESC=	Optional page compression
ENGINES_DESC=	Optional MariaDB storage engines
GROONGA_DESC=	Optional Mroonga features
INNOBASE_DESC=	InnoDB default engine
MROONGA_DESC=	Mroonga Full Text Search engine
MSGPACK_DESC=	MsgPack support
OQGRAPH_DESC=	Open Query Graph Computation engine
ROCKSDB_DESC=	RocksDB LSM engine (Alpha)
SPHINX_DESC=	SphinxSE engine
SPIDER_DESC=	Partitioning and XA-transactions engine
TOKUDB_DESC=	Fractal tree index tree data structure engine
XTRADB_DESC=	Build XtraDB engine next to InnoDB
ZMQ_DESC=	ZeroMQ support
ZSTD_DESC+=	Zstandard compression support (RocksDB only)
.endif

GSSAPI_BASE_USES=	gssapi
GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_MIT_USES=	gssapi:mit

CMAKE_ARGS+=	-DINSTALL_DOCDIR="share/doc/mysql" \
		-DINSTALL_DOCREADMEDIR="share/doc/mysql" \
		-DINSTALL_INCLUDEDIR="include/mysql" \
		-DINSTALL_INFODIR="info" \
		-DINSTALL_LIBDIR="lib/mysql" \
		-DINSTALL_MANDIR="man" \
		-DINSTALL_MYSQLDATADIR="/var/db/mysql" \
		-DINSTALL_MYSQLSHAREDIR="share/mysql" \
		-DINSTALL_MYSQLTESTDIR= \
		-DINSTALL_PLUGINDIR="lib/mysql/plugin" \
		-DINSTALL_SBINDIR="libexec" \
		-DINSTALL_SCRIPTDIR="bin" \
		-DINSTALL_SHAREDIR="share" \
		-DINSTALL_SQLBENCHDIR= \
		-DINSTALL_SUPPORTFILESDIR="share/mysql" \
		-DDEFAULT_SYSCONFDIR="${PREFIX}/etc" \
		-DWITH_JEMALLOC="system" \
		-DWITH_LIBWRAP=1 \
		-DWITH_SSL="${OPENSSLBASE}" \
		-DWITH_UNIT_TESTS=0 \
		-DWITHOUT_DOCS=1 \
		-DCURSES_CURSES_LIBRARY="/usr/lib/libcurses.so" \
		-DCURSES_FORM_LIBRARY="/usr/lib/libform.so" \
		-DCURSES_CURSES_LIBRARY="/usr/lib/libncurses.so" \
		-DEXECINFO_ROOT="${LOCALBASE}" \
		-DICONV_LIBRARIES="${ICONV_LIB_PATH}" \
		-DKRB5_CONFIG="${KRB5CONFIG}" \
		-DCURSES_NCURSES_LIBRARY="${NCURSESLIB}/libncurses.so" \
		-DOPENSSL_ROOT_DIR="${OPENSSLBASE}" \
		-DOPENSSL_CRYPTO_LIBRARY="${OPENSSLBASE}/lib/libcrypto.so" \
		-DOPENSSL_SSL_LIBRARY="${OPENSSLBASE}/lib/libssl.so" \
		-DREMOTEIO_PLUGIN_TYPE="NO" \
		-DCOMPILATION_COMMENT="FreeBSD Ports" \
		-DCMAKE_PREFIX_PATH=${PREFIX}

DATADIR=	${PREFIX}/share/mysql

.ifdef USE_MYSQL
.error You have `USE_MYSQL' variable defined either in environment or in make(1) arguments. This leads to a circular dependency. Please undefine and try again.
.endif

CONFLICTS_INSTALL=	mariadb5*-${PKGNAMESUFFIX:C/^[0-9]*-//}-* \
			mariadb10[013-9]-${PKGNAMESUFFIX:C/^[0-9]*-//}-* \
			mysql[0-9]*-${PKGNAMESUFFIX:C/^[0-9]*-//}-* \
			mysqlwsrep* \
			percona[0-9]*-${PKGNAMESUFFIX:C/^[0-9]*-//}-*

FASTMTX_CMAKE_ON=	-DWITH_FAST_MUTEXES=1
OPTIONS_SUB=		yes

.if defined(CLIENT_ONLY)
# MySQL-Client part
USES+=		readline
GSSAPI_NONE_CMAKE_ON=	-DPLUGIN_AUTH_GSSAPI_CLIENT=NO
.else
# MySQL-Server part
USES+=		mysql:102m
USE_LDCONFIG+=	${PREFIX}/lib/mysql/plugin
USE_RC_SUBR=	mysql-server
USERS=		mysql
GROUPS=		mysql
CMAKE_ARGS+=	-DWITH_EMBEDDED_SERVER="ON" \
		-DPLUGIN_AUTH_GSSAPI_CLIENT=NO \
		-DCMAKE_SKIP_BUILD_RPATH:BOOL=YES \
		-DWITHOUT_EXAMPLE_STORAGE_ENGINE=1 \
		-DWITHOUT_CLIENT=1

.for ENGINE in ${OPTIONS_GROUP_ENGINES:NINNOBASE}
${ENGINE}_CMAKE_OFF=	-DPLUGIN_${ENGINE}=NO \
			-DWITHOUT_${ENGINE}=1
${ENGINE}_CMAKE_ON=	-DPLUGIN_${ENGINE}=DYNAMIC
.endfor
INNOBASE_CMAKE_OFF=	-DPLUGIN_INNOBASE=NO -DWITHOUT_INNOBASE=1

CONNECT_EXTRA_LIB_DEPENDS=	libodbc.so:databases/unixODBC
CONNECT_EXTRA_USE=		gnome=libxml2
GSSAPI_NONE_CMAKE_ON=	-DPLUGIN_AUTH_GSSAPI=NO -DPLUGIN_AUTH_GSSAPI_CLIENT=NO
LZ4_CMAKE_OFF=		-DGRN_WITH_LZ4=OFF -DWITH_INNODB_LZ4=OFF -DWITH_ROCKSDB_LZ4=OFF
LZ4_CMAKE_ON=		-DGRN_WITH_LZ4=ON  -DWITH_INNODB_LZ4=ON  -DWITH_ROCKSDB_LZ4=ON
LZ4_LIB_DEPENDS=	liblz4.so:archivers/liblz4
LZO_CMAKE_OFF=		-DWITH_INNODB_LZO=OFF
LZO_CMAKE_ON=		-DWITH_INNODB_LZO=ON
LZO_LIB_DEPENDS=	liblzo2.so:archivers/lzo2
MROONGA_IMPLIES=	LZ4
MSGPACK_LIB_DEPENDS=	libmsgpackc.so:devel/msgpack
OQGRAPH_LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
			libJudy.so:devel/judy
SNAPPY_CMAKE_OFF=	-DWITH_INNODB_SNAPPY=OFF -DWITH_ROCKSDB_snappy=OFF
SNAPPY_CMAKE_ON=	-DWITH_INNODB_SNAPPY=ON  -DWITH_ROCKSDB_snappy=ON
SNAPPY_LIB_DEPENDS=	libsnappy.so:archivers/snappy
TOKUDB_IMPLIES=		SNAPPY
TOKUDB_PORTDOCS=	README.md
TOKUDB_VARS=		LICENSE+=PerconaFT LICENSE_COMB=multi
ZMQ_LIB_DEPENDS=	libzmq.so:net/libzmq4
ZSTD_CMAKE_ON=		-DWITH_ROCKSDB_ZSTD=ON
ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd

NOT_FOR_ARCHS=		i386
NOT_FOR_ARCHS_REASON=	currently does not compile on i386, see \
			https://jira.mariadb.org/browse/MDEV-9627

post-install:
# Remove programs to avoid conflict with mariadb102-client
# These are "client" components, so there should be a switch that
# prevents them from being installed but it's unknown right now
	${RM} ${STAGEDIR}${PREFIX}/bin/msql2mysql \
		${STAGEDIR}${PREFIX}/bin/mysql_config \
		${STAGEDIR}${PREFIX}/bin/mysql_find_rows \
		${STAGEDIR}${PREFIX}/bin/mysqlaccess
	${RM} -r ${STAGEDIR}/${PREFIX}/share/mysql/policy \
		${STAGEDIR}/${PREFIX}/share/pkgconfig
	${RM} ${STAGEDIR}${LOCALBASE}/lib/mysql/libmysqlclient*
.endif # defined(CLIENT_ONLY)

.if defined(WITH_OPENSSL_PORT)
GSSAPI_BASE_IGNORE=	BASE_GSSAPI is not compatible with OpenSSL from ports. Use other GSSAPI options or OpenSSL from base system
.endif

.include <bsd.port.pre.mk>

.if ${OPSYS} == DragonFly
CMAKE_ARGS+=	-DWITHOUT_TOKUDB
.endif

post-patch:
	${REINPLACE_CMD} 's/*.1/${MAN1}/' ${WRKSRC}/man/CMakeLists.txt
	${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/mysys/my_default.c
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/scripts/mysql_config.sh
.if ${OPSYS} == DragonFly
	${CP} ${WRKSRC}/cmake/os/FreeBSD.cmake \
		${WRKSRC}/cmake/os/DragonFly.cmake
.endif

#post-configure-MROONGA-on:
#	${REINPLACE_CMD} 's|-llz4|-L${LOCALBASE}/lib -llz4|' \
#		${WRKSRC}/storage/mroonga/CMakeFiles/mroonga.dir/link.txt

.include <bsd.port.post.mk>
