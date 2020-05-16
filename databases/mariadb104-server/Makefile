# Created by: Bernard Spil <brnrd@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	mariadb
PORTVERSION=	10.4.13
PORTREVISION?=	0
CATEGORIES=	databases
MASTER_SITES=	http://mirrors.supportex.net/${SITESDIR}/ \
		http://mirror2.hs-esslingen.de/pub/Mirrors/${SITESDIR}/ \
		http://gd.tuwien.ac.at/db/${SITESDIR}/ \
		http://mirrors.fe.up.pt/pub/${SITESDIR}/ \
		http://mirror.de.gsnw.de:56431/${SITESDIR}/ \
		http://mirror.layerjet.com/${SITESDIR}/ \
		http://mirror.switch.ch/mirror/${SITESDIR}/ \
		http://ftp.osuosl.org/pub/${SITESDIR}/
PKGNAMESUFFIX?=	104-server

MAINTAINER=	brnrd@FreeBSD.org
COMMENT?=	Multithreaded SQL database (server)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_NAME_PerconaFT=	PerconaFT patents license
LICENSE_FILE_PerconaFT=	${WRKSRC}/storage/tokudb/PerconaFT/PATENTS
LICENSE_PERMS_PerconaFT=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		bison:build cmake:insource,noninja compiler:c++11-lib cpe iconv:translit libedit ncurses shebangfix ssl

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

SLAVEDIRS=	databases/mariadb102-client
USE_LDCONFIG=	${PREFIX}/lib/mysql
SHEBANG_FILES=	scripts/*.sh
SITESDIR=	mariadb/mariadb-${PORTVERSION}/source
DOCSDIR=	${PREFIX}/share/doc/mysql

OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE
OPTIONS_DEFAULT=	GSSAPI_BASE

.if ${PKGNAMESUFFIX:M*-server}
# MySQL-Server options
OPTIONS_DEFAULT+=	CONNECT_EXTRA INNOBASE SPHINX SPIDER WSREP
OPTIONS_GROUP=		COMPRESSION ENGINES GROONGA
OPTIONS_DEFINE=		CONNECT_EXTRA DOCS
OPTIONS_DEFINE_amd64=	WSREP
OPTIONS_GROUP_COMPRESSION=	LZ4 LZO SNAPPY ZSTD
OPTIONS_GROUP_ENGINES=	INNOBASE MROONGA OQGRAPH ROCKSDB SPHINX SPIDER TOKUDB
OPTIONS_GROUP_GROONGA=	ZMQ MSGPACK
OPTIONS_EXCLUDE_i386=	ROCKSDB TOKUDB

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
WSREP_DESC=	Build wsrep clustering
ZMQ_DESC=	ZeroMQ support
ZSTD_DESC+=	Zstandard compression support (RocksDB only)
.endif

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
		-DWITH_SSL="${OPENSSLBASE}" \
		-DCURSES_CURSES_LIBRARY="/usr/lib/libcurses.so" \
		-DCURSES_FORM_LIBRARY="/usr/lib/libform.so" \
		-DCURSES_CURSES_LIBRARY="/usr/lib/libncurses.so" \
		-DKRB5_CONFIG="${KRB5CONFIG}" \
		-DCURSES_NCURSES_LIBRARY="${NCURSESLIB}/libncurses.so" \
		-DCOMPILATION_COMMENT="FreeBSD Ports" \
		-DCMAKE_PREFIX_PATH=${PREFIX} \
		-DPLUGIN_AUTH_TEST_PLUGIN=NO
CMAKE_OFF+=	CONC_WITH_UNIT_TESTS CONNECT_WITH_MONGO WITH_UNIT_TESTS
CMAKE_ON+=	WITH_LIBWRAP WITHOUT_DOCS
DISABLED_PLUGINS+=	DAEMON_EXAMPLE DIALOG_EXAMPLES EXAMPLE \
		EXAMPLE_KEY_MANAGEMENT FTEXAMPLE

DATADIR=	${PREFIX}/share/mysql

CONFLICTS_INSTALL=	mariadb5*-${PKGNAMESUFFIX:C/^[0-9]*-//}-* \
			mariadb10[0-24-9]-${PKGNAMESUFFIX:C/^[0-9]*-//}-* \
			mysql[0-9]*-${PKGNAMESUFFIX:C/^[0-9]*-//}-* \
			mysqlwsrep* \
			percona[0-9]*-${PKGNAMESUFFIX:C/^[0-9]*-//}-*

FASTMTX_CMAKE_BOOL=	WITH_FAST_MUTEXES
GSSAPI_BASE_USES=	gssapi
GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_MIT_USES=	gssapi:mit
GSSAPI_NONE_CMAKE_ON=	-DPLUGIN_AUTH_GSSAPI_CLIENT=OFF
OPTIONS_SUB=		yes

.if ${PKGNAMESUFFIX:M*-client}
# MySQL-Client part
CMAKE_ON+=	CONC_WITH_MYSQLCOMPAT WITHOUT_SERVER
CMAKE_OFF+=	WITH_WSREP
USES+=		readline
USE_LDCONFIG=	${PREFIX}/lib/mysql
.else # ! ${PKGNAMESUFFIX:M*-client}
# MySQL-Server part
USES+=		mysql:104m
USE_LDCONFIG+=	${PREFIX}/lib/mysql/plugin
USE_RC_SUBR=	mysql-server
USERS=		mysql
GROUPS=		mysql
CMAKE_ON+=	CMAKE_SKIP_BUILD_RPATH WITH_EMBEDDED_SERVER
CMAKE_OFF+=	WITH_CLIENT

.for ENGINE in ${OPTIONS_GROUP_ENGINES:NINNOBASE}
${ENGINE}_CMAKE_OFF=	-DPLUGIN_${ENGINE}=NO
${ENGINE}_CMAKE_ON=	-DPLUGIN_${ENGINE}=DYNAMIC
.endfor
INNOBASE_VARS_OFF=	disabled_plugins+=INNOBASE

CONNECT_EXTRA_LIB_DEPENDS=	libodbc.so:databases/unixODBC
CONNECT_EXTRA_USE=		gnome=libxml2
CONNECT_EXTRA_USES=		gnome
CONNECT_EXTRA_CMAKE_BOOL=	CONNECT_WITH_LIBXML2 CONNECT_WITH_ODBC
GSSAPI_NONE_VARS=	disabled_plugins+=AUTH_GSSAPI
LZ4_CMAKE_ON=		-DGRN_WITH_LZ4=ON  -DWITH_INNODB_LZ4=ON  -DWITH_ROCKSDB_LZ4=ON
LZ4_CMAKE_OFF=		-DGRN_WITH_LZ4=OFF -DWITH_INNODB_LZ4=OFF -DWITH_ROCKSDB_LZ4=OFF
LZ4_LIB_DEPENDS=	liblz4.so:archivers/liblz4
LZO_CMAKE_ON=		-DWITH_INNODB_LZO=ON
LZO_CMAKE_OFF=		-DWITH_INNODB_LZO=OFF
LZO_LIB_DEPENDS=	liblzo2.so:archivers/lzo2
MROONGA_IMPLIES=	LZ4
MSGPACK_LIB_DEPENDS=	libmsgpackc.so:devel/msgpack
OQGRAPH_LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
			libJudy.so:devel/judy
ROCKSDB_USES=		python
SNAPPY_CMAKE_ON=	-DWITH_INNODB_SNAPPY=ON  -DWITH_ROCKSDB_snappy=ON
SNAPPY_CMAKE_OFF=	-DWITH_INNODB_SNAPPY=OFF -DWITH_ROCKSDB_snappy=OFF
SNAPPY_LIB_DEPENDS=	libsnappy.so:archivers/snappy
TOKUDB_IMPLIES=		SNAPPY
TOKUDB_PORTDOCS=	README.md
TOKUDB_VARS=		LICENSE+=PerconaFT LICENSE_COMB=multi
WSREP_CMAKE_BOOL=	WITH_WSREP
WSREP_LIB_DEPENDS=	libgalera.so:databases/galera26
ZMQ_LIB_DEPENDS=	libzmq.so:net/libzmq4
ZSTD_CMAKE_ON=		-DWITH_ROCKSDB_zstd=ON
ZSTD_CMAKE_OFF=		-DWITH_ROCKSDB_zstd=OFF
ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd

.include <bsd.port.options.mk>

.for PLUGIN in ${DISABLED_PLUGINS}
CMAKE_ARGS+=		-DPLUGIN_${PLUGIN}=NO
.endfor

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200057
SUB_LIST+=	LEGACY_LIMITS="@comment " MODERN_LIMITS=""
.else
SUB_LIST+=	LEGACY_LIMITS="" MODERN_LIMITS="@comment "
.endif

.endif # ${PKGNAMESUFFIX:M*-client}

.if defined(WITH_OPENSSL_PORT)
GSSAPI_BASE_IGNORE=	BASE_GSSAPI is not compatible with OpenSSL from ports. Use other GSSAPI options or OpenSSL from base system
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64
PLIST_SUB+=	WSREP="@comment "
.endif

.if ${OPSYS} == DragonFly
CMAKE_OFF+=	WITH_TOKUDB
.endif

post-patch:
	${REINPLACE_CMD} 's|/usr/bin/env python|${PYTHON_CMD}|' ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/mysys/my_default.c
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/scripts/mysql_config.sh \
		${WRKSRC}/storage/tokudb/PerconaFT/cmake_modules/TokuThirdParty.cmake
	${MV} ${WRKSRC}/storage/mroonga/version ${WRKSRC}/storage/mroonga/version_txt
.if ${OPSYS} == DragonFly
	${CP} ${WRKSRC}/cmake/os/FreeBSD.cmake \
		${WRKSRC}/cmake/os/DragonFly.cmake
.endif

post-configure:
	${REINPLACE_CMD} -Ee 's|(#define INCLUDE.*)"$$|\1 -I${PREFIX}/include"|' \
		-e 's|(#define LIBS .*)"$$|\1 -L${PREFIX}/lib"|' \
		${WRKSRC}/libmariadb/mariadb_config/mariadb_config.c

# Fix build failure in mbstream, see https://jira.mariadb.org/browse/MDEV-14072
post-configure-INNOBASE-on:
	${REINPLACE_CMD} -e 's| ${PREFIX}/lib/liblz4.so\(.* ${PREFIX}/lib/liblz4.so.*\)|\1|' \
		-e 's| ${PREFIX}/lib/liblzo2.so\(.* ${PREFIX}/lib/liblzo2.so.*\)|\1|' \
		-e 's| ${PREFIX}/lib/libsnappy.so\(.* ${PREFIX}/lib/libsnappy.so\)|\1|' \
		-e 's| -llzma\(.* -llzma\)|\1|;s| -lbz2\(.* -lbz2\)|\1|;' \
		${WRKSRC}/extra/mariabackup/CMakeFiles/mbstream.dir/link.txt

.if ${PKGNAMESUFFIX:M*-client}
post-install:
	${RM} -r ${STAGEDIR}${DATADIR}
	${RM} -r ${STAGEDIR}${PREFIX}/include/mysql/server
	${MV} ${STAGEDIR}${PREFIX}/lib/mysql/pkgconfig/mariadb.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/mariadb.pc

post-install-GSSAPI_NONE-off:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mysql/plugin/auth_gssapi_client.so

.else # ! ${PKGNAMESUFFIX:M*-client}
post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share/mysql/policy
	${RM} -r ${STAGEDIR}${PREFIX}/include/mysql/server/private
	${RM} -r ${STAGEDIR}${PREFIX}/lib/mysql/pkgconfig
.endif # ${PKGNAMESUFFIX:M*-client}

.include <bsd.port.post.mk>
