PORTNAME?=	mariadb
PORTVERSION=	10.11.14
PORTREVISION?=	1
CATEGORIES=	databases
MASTER_SITES=	\
		https://ftp.nluug.nl/db/${SITESDIR}/ \
		https://mirror.nodesdirect.com/${SITESDIR}/ \
		https://mirror.one.com/${SITESDIR}/ \
		https://ftp.icm.edu.pl/pub/unix/database/${SITESDIR}/ \
		https://mirror.truenetwork.ru/${SITESDIR}/ \
		https://mirrors.aliyun.com/${SITESDIR}/ \
		https://ftp.ubuntu-tw.org/mirror/${SITESDIR}/ \
		https://mirror.kku.ac.th/${SITESDIR}/ \
		https://espejito.fder.edu.uy/${SITESDIR}/ \
		https://ftp.osuosl.org/pub/${SITESDIR}/ \
		https://downloads.mariadb.org/rest-api/mariadb/${PORTVERSION}/
PKGNAMESUFFIX?=	1011-server

MAINTAINER=	brnrd@FreeBSD.org
COMMENT?=	Multithreaded SQL database (server)
WWW=		https://mariadb.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

#EXPIRATION_DATE=	2028-02-01

LIB_DEPENDS+=	libfmt.so:devel/libfmt \
		liblz4.so:archivers/liblz4 \
		libpcre2-8.so:devel/pcre2 \
		libzstd.so:archivers/zstd

# Ugly workaround for MariaDB/CMake library detection
LDFLAGS+=	-L${LOCALBASE}/lib

USES=		bison:build cmake:insource compiler:c++11-lib cpe iconv:translit libedit ncurses shebangfix ssl

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

USE_LDCONFIG=	${PREFIX}/lib/mysql
SHEBANG_FILES=	scripts/*.sh support-files/*.sh
SITESDIR=	mariadb/mariadb-${PORTVERSION}/source
DOCSDIR=	${PREFIX}/share/doc/mysql

MARIADB_USER?=		mysql
MARIADB_GROUP?=		mysql
MARIADB_DBDIR?=		/var/db/mysql
MARIADB_RUNDIR?=	/var/run/mysql
MARIADB_SOCK?=		mysql.sock
MARIADB_LOGDIR?=	/var/log/mysql

USERS=			${MARIADB_USER}
GROUPS=			${MARIADB_GROUP}

OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE
OPTIONS_DEFAULT=	GSSAPI_BASE

.if ${PKGNAMESUFFIX:M*-server}
# MySQL-Server options
OPTIONS_DEFAULT+=	AWS_KEY_MGMT CONNECT_EXTRA HASHICORP_VAULT INNOBASE SPHINX SPIDER WSREP
OPTIONS_GROUP=		COMPRESSION ENGINES GROONGA
OPTIONS_DEFINE=		AWS_KEY_MGMT CONNECT_EXTRA DOCS HASHICORP_VAULT
OPTIONS_DEFINE_amd64=	WSREP
OPTIONS_DEFINE_aarch64=	WSREP
OPTIONS_DEFINE_powerpc64le=	WSREP
OPTIONS_DEFINE_powerpc64=	WSREP
OPTIONS_DEFINE_riscv64=	WSREP
OPTIONS_GROUP_COMPRESSION=	LZO SNAPPY
OPTIONS_GROUP_ENGINES=	COLUMNSTORE INNOBASE MROONGA OQGRAPH ROCKSDB S3 SPHINX SPIDER
OPTIONS_GROUP_GROONGA=	ZMQ MSGPACK
OPTIONS_EXCLUDE_i386=	ROCKSDB

AWS_KEY_MGMT_DESC=	AWS Encryption Key Management Plugin
COLUMNSTORE_DESC=	Columnar storage egine
CONNECT_EXTRA_DESC=	Enable ODBC and XML in CONNECT engine
COMPRESSION_DESC=	Optional page compression
ENGINES_DESC=	Optional MariaDB storage engines
GROONGA_DESC=	Optional Mroonga features
HASHICORP_VAULT_DESC=	Enable HashiCorp vault key-storage plugin
INNOBASE_DESC=	InnoDB default engine
MROONGA_DESC=	Mroonga Full Text Search engine
MSGPACK_DESC=	MsgPack support
OQGRAPH_DESC=	Open Query Graph Computation engine
ROCKSDB_DESC=	RocksDB LSM engine
S3_DESC=	S3 storage engine (Gamma)
SPHINX_DESC=	SphinxSE engine
SPIDER_DESC=	Partitioning and XA-transactions engine
WSREP_DESC=	Build wsrep clustering
ZMQ_DESC=	ZeroMQ support
.endif

CMAKE_ARGS+=	-DCMAKE_PREFIX_PATH=${PREFIX} \
		-DINSTALL_DOCDIR="share/doc/mysql" \
		-DINSTALL_DOCREADMEDIR="share/doc/mysql" \
		-DINSTALL_INFODIR="info" \
		-DINSTALL_LIBDIR="lib/mysql" \
		-DINSTALL_MANDIR="share/man" \
		-DINSTALL_MYSQLDATADIR="${MARIADB_DBDIR}" \
		-DINSTALL_MYSQLSHAREDIR="share/mysql" \
		-DINSTALL_MYSQLTESTDIR= \
		-DINSTALL_PLUGINDIR="lib/mysql/plugin" \
		-DINSTALL_SBINDIR="libexec" \
		-DINSTALL_SCRIPTDIR="bin" \
		-DINSTALL_SQLBENCHDIR= \
		-DINSTALL_SUPPORTFILESDIR="share/mysql" \
		-DINSTALL_SYSCONFDIR="${ETCDIR}" \
		-DINSTALL_SYSCONF2DIR="${ETCDIR}/conf.d" \
		-DINSTALL_UNIX_ADDRDIR="${MARIADB_RUNDIR}/${MARIADB_SOCK}" \
		-DWITH_PCRE=system \
		-DPCRE_LIBRARY_DIRS=${PREFIX}/lib \
		-DWITH_LIBFMT=system \
		-DLIBFMT_INCLUDE_DIR=${PREFIX}/include \
		-DHAVE_SYSTEM_LIBFMT=yes \
		-DWITH_SSL="${OPENSSLBASE}" \
		-DGRN_WITH_LZ4=ON -DWITH_INNODB_LZ4=ON -DWITH_ROCKSDB_LZ4=ON \
		-DCURSES_CURSES_LIBRARY="/usr/lib/libcurses.so" \
		-DCURSES_FORM_LIBRARY="/usr/lib/libform.so" \
		-DCURSES_CURSES_LIBRARY="/usr/lib/libncurses.so" \
		-DKRB5_CONFIG="${KRB5CONFIG}" \
		-DCURSES_NCURSES_LIBRARY="${NCURSESLIB}/libncurses.so" \
		-DCOMPILATION_COMMENT="FreeBSD Ports" \
		-DPLUGIN_AUTH_TEST_PLUGIN=NO
CMAKE_OFF+=	CONC_WITH_UNIT_TESTS CONNECT_WITH_MONGO WITH_UNIT_TESTS
CMAKE_ON+=	WITH_LIBWRAP WITHOUT_DOCS
DISABLED_PLUGINS+=	AUTH_TEST_PLUGIN DAEMON_EXAMPLE DIALOG_EXAMPLES \
		EXAMPLE EXAMPLE_KEY_MANAGEMENT FTEXAMPLE

DATADIR=	${PREFIX}/share/mysql
ETCDIR=		${PREFIX}/etc/mysql

CONFLICTS_INSTALL=	mariadb10[0-57-9]-${PKGNAMESUFFIX:C/^[0-9]*-//}-* \
			mysql[0-9]*-${PKGNAMESUFFIX:C/^[0-9]*-//}-* \
			mysqlwsrep* \
			percona[0-9]*-${PKGNAMESUFFIX:C/^[0-9]*-//}-* \
			mytop

FASTMTX_CMAKE_BOOL=	WITH_FAST_MUTEXES
GSSAPI_BASE_USES=	gssapi
GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_MIT_USES=	gssapi:mit
GSSAPI_NONE_CMAKE_ON=	-DPLUGIN_AUTH_GSSAPI_CLIENT=OFF
OPTIONS_SUB=		yes
SUB_LIST+=	MARIADB_RUNDIR="${MARIADB_RUNDIR}" \
		MARIADB_SOCK="${MARIADB_SOCK}"

.if ${PKGNAMESUFFIX:M*-client}
# MySQL-Client part
CMAKE_ON+=	CONC_WITH_MYSQLCOMPAT WITHOUT_SERVER
CMAKE_OFF+=	WITH_WSREP
USES+=		readline
USE_LDCONFIG=	${PREFIX}/lib/mysql
SUB_FILES+=	my.cnf.sample client.cnf.sample

.else # ! ${PKGNAMESUFFIX:M*-client}
# MySQL-Server part
USES+=		mysql:1011m

USE_LDCONFIG+=	${PREFIX}/lib/mysql/plugin
USE_RC_SUBR=	mysql-server

CMAKE_ON+=	CMAKE_SKIP_BUILD_RPATH WITH_EMBEDDED_SERVER
CMAKE_OFF+=	WITH_CLIENT
SUB_FILES+=	server.cnf.sample
SUB_LIST+=	MARIADB_DBDIR="${MARIADB_DBDIR}" \
		MARIADB_LOGDIR="${MARIADB_LOGDIR}" \
		MARIADB_USER="${MARIADB_USER}"
PLIST_SUB+=	MARIADB_LOGDIR="${MARIADB_LOGDIR}" \
		MARIADB_USER="${MARIADB_USER}" \
		MARIADB_GROUP="${MARIADB_GROUP}"

.for ENGINE in ${OPTIONS_GROUP_ENGINES:NINNOBASE}
${ENGINE}_CMAKE_OFF=	-DPLUGIN_${ENGINE}=NO
${ENGINE}_CMAKE_ON=	-DPLUGIN_${ENGINE}=DYNAMIC
.endfor
AWS_KEY_MGMT_CMAKE_ON=	-DPLUGIN_AWS_KEY_MANAGEMENT=ON
INNOBASE_VARS_OFF=	disabled_plugins+=INNOBASE
COLUMNSTORE_BROKEN=	ColumnStore engine build failure "fatal error: 'sys/prctl.h' file not found"
CONNECT_EXTRA_LIB_DEPENDS=	libodbc.so:databases/unixODBC
CONNECT_EXTRA_USE=		gnome=libxml2
CONNECT_EXTRA_USES=		gnome
CONNECT_EXTRA_CMAKE_BOOL=	CONNECT_WITH_LIBXML2 CONNECT_WITH_ODBC
GSSAPI_NONE_VARS=	disabled_plugins+=AUTH_GSSAPI
HASHICORP_VAULT_CMAKE_OFF=	-DPLUGIN_HASHICORP_KEY_MANAGEMENT=NO
HASHICORP_VAULT_LIB_DEPENDS=	libcurl.so:ftp/curl
LZO_CMAKE_ON=		-DWITH_INNODB_LZO=ON
LZO_CMAKE_OFF=		-DWITH_INNODB_LZO=OFF
LZO_LIB_DEPENDS=	liblzo2.so:archivers/lzo2
MSGPACK_LIB_DEPENDS=	libmsgpackc.so:devel/msgpack-c
OQGRAPH_LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
			libJudy.so:devel/judy
ROCKSDB_BROKEN=		RocksDB engine build failyure "jemalloc_helper.h:65:61: error: use of undeclared identifier 'nothrow'; did you mean 'std::nothrow'?"
ROCKSDB_USES=		python
ROCKSDB_CMAKE_ON=	-DPYTHON_SHEBANG=${PYTHON_CMD} -DWITH_ROCKSDB_zstd=ON
S3_LIB_DEPENDS=		libcurl.so:ftp/curl
SNAPPY_CMAKE_ON=	-DWITH_INNODB_SNAPPY=ON  -DWITH_ROCKSDB_snappy=ON
SNAPPY_CMAKE_OFF=	-DWITH_INNODB_SNAPPY=OFF -DWITH_ROCKSDB_snappy=OFF
SNAPPY_LIB_DEPENDS=	libsnappy.so:archivers/snappy
WSREP_CMAKE_BOOL=	WITH_WSREP
WSREP_LIB_DEPENDS=	libgalera.so:databases/galera26
WSREP_RUN_DEPENDS=	bash:shells/bash \
			rsync:net/rsync \
			#stunnel:security/stunnel
WSREP_SHEBANG_FILES=	bin/wsrep_sst_rsync
ZMQ_LIB_DEPENDS=	libzmq.so:net/libzmq4

.for PLUGIN in ${DISABLED_PLUGINS}
CMAKE_ARGS+=		-DPLUGIN_${PLUGIN}=NO
.endfor

.endif # ${PKGNAMESUFFIX:M*-client}

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
SUB_LIST+=	LEGACY_LIMITS="@comment " MODERN_LIMITS=""
.else
SUB_LIST+=	LEGACY_LIMITS="" MODERN_LIMITS="@comment "
.endif

.if ${SSL_DEFAULT} != base && ${PORT_OPTIONS:MGSSAPI_BASE}
GSSAPI_BASE_IGNORE=	GSSAPI_BASE is not compatible with OpenSSL from ports. Use other GSSAPI options or OpenSSL from base system
.endif

.if ${SSL_DEFAULT:Mlibressl*}
CFLAGS+=	-Wno-incompatible-function-pointer-types
.warning HELLO FROM MAKE LIBRESSL
.endif

.if ${ARCH} != amd64 && ${ARCH} != aarch64
PLIST_SUB+=	WSREP="@comment "
.endif

post-patch:
.if ${OPSYS} == DragonFly
	${CP} ${WRKSRC}/cmake/os/FreeBSD.cmake \
		${WRKSRC}/cmake/os/DragonFly.cmake
.endif

post-configure:
	${REINPLACE_CMD} -Ee 's|(#define INCLUDE.*)"$$|\1 -I${PREFIX}/include"|' \
		-e 's|(#define LIBS .*)"$$|\1 -L${PREFIX}/lib"|' \
		${WRKSRC}/libmariadb/mariadb_config/mariadb_config.c
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${PREFIX}|' \
		${WRKSRC}/scripts/mysql_config.sh

pre-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}/conf.d

.if ${PKGNAMESUFFIX:M*-client}
post-install:
	${INSTALL_DATA} ${WRKDIR}/my.cnf.sample ${STAGEDIR}${ETCDIR}/my.cnf.sample
	${INSTALL_DATA} ${WRKDIR}/client.cnf.sample \
		${STAGEDIR}${ETCDIR}/conf.d/client.cnf.sample
	${RM} -r ${STAGEDIR}${DATADIR} \
		${STAGEDIR}${PREFIX}/include/mysql/server \
		${STAGEDIR}${ETCDIR}/init.d \
		${STAGEDIR}${PREFIX}/lib/mysql/pkgconfig

post-install-GSSAPI_NONE-off:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mysql/plugin/auth_gssapi_client.so

.else # ! ${PKGNAMESUFFIX:M*-client}
post-install:
	${INSTALL_DATA} ${WRKDIR}/server.cnf.sample \
		${STAGEDIR}${ETCDIR}/conf.d/server.cnf.sample
	${MV} ${STAGEDIR}${PREFIX}/share/user_map.conf \
		${STAGEDIR}${PREFIX}/etc/mysql/user_map.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/share/pam_user_map.so \
		${STAGEDIR}${PREFIX}/lib/mysql/
	${RM} -r ${STAGEDIR}${PREFIX}/share/mysql/policy \
		${STAGEDIR}${PREFIX}/include/mysql/server/private \
		${STAGEDIR}${PREFIX}/lib/mysql/pkgconfig \
		${STAGEDIR}${PREFIX}/libexec/rcmysql \
		${STAGEDIR}/suite \
		${STAGEDIR}${ETCDIR}/init.d \
		${STAGEDIR}${ETCDIR}/logrotate.d \
		${STAGEDIR}${DOCSDIR}/COPYING
	${MKDIR} ${STAGEDIR}${MARIADB_LOGDIR}
	${SED} '/%%/d;/^@comment /d;s/^/@comment /' ${PORTSDIR}/${CATEGORIES:[1]}/${PORTNAME}${PKGNAMESUFFIX:S/-server/-client/}/pkg-plist \
		>> ${TMPPLIST}

post-install-MROONGA-on:
	${MV} ${STAGEDIR}${PREFIX}/share/groonga ${STAGEDIR}${DOCSDIR}/
	${RM}	${STAGEDIR}${DOCSDIR}/groonga/COPYING \
		${STAGEDIR}${DATADIR}/mroonga/COPYING

post-install-SPIDER-on:
	${MV} ${STAGEDIR}${ETCDIR}/conf.d/spider.cnf \
		${STAGEDIR}${ETCDIR}/conf.d/spider.cnf.sample

post-install-WSREP-on:
	${MV} ${STAGEDIR}${DATADIR}/wsrep.cnf \
		${STAGEDIR}${ETCDIR}/conf.d/wsrep.cnf.sample

.endif # ${PKGNAMESUFFIX:M*-client}

.include <bsd.port.mk>
