# $FreeBSD$

PORTNAME?=	mariadb
PORTVERSION=	10.1.45
PORTREVISION=	0
CATEGORIES=	databases
MASTER_SITES=	http://ftp.osuosl.org/pub/${SITESDIR}/ \
		http://mirrors.supportex.net/${SITESDIR}/ \
		http://mirror2.hs-esslingen.de/pub/Mirrors/${SITESDIR}/ \
		http://gd.tuwien.ac.at/db/${SITESDIR}/ \
		http://mirrors.fe.up.pt/pub/${SITESDIR}/ \
		http://mirror.de.gsnw.de:56431/${SITESDIR}/ \
		http://mirror.layerjet.com/${SITESDIR}/ \
		http://mirror.switch.ch/mirror/${SITESDIR}/
PKGNAMESUFFIX?=	101-server

DEPRECATED=		Port will be removed when 10.5 is added, please\
			switch to a newer version
EXPIRATION_DATE=	2020-07-01

MAINTAINER=	brnrd@FreeBSD.org
COMMENT?=	Multithreaded SQL database (server)

LICENSE=	GPLv2
LICENSE_NAME_PerconaFT=	PerconaFT patents license
LICENSE_FILE_PerconaFT=	${WRKSRC}/storage/tokudb/PerconaFT/PATENTS
LICENSE_PERMS_PerconaFT=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

SUB_FILES=	pkg-message

USES=		bison:build cmake:insource,noninja cpe libedit ncurses \
		shebangfix ssl
USE_LDCONFIG=	${PREFIX}/lib/mysql
SHEBANG_FILES=	scripts/*.sh
SITESDIR=	mariadb/mariadb-${PORTVERSION}/source
DOCSDIR=	${PREFIX}/share/doc/mysql

OPTIONS_DEFINE=		FASTMTX
OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE
OPTIONS_DEFAULT=	GSSAPI_BASE

FASTMTX_DESC=		Replace mutexes with spinlocks

.if ${PKGNAMESUFFIX:M*-server}
# MySQL-Server options
OPTIONS_DEFINE+=	CONNECT_EXTRA MAXKEY DOCS
OPTIONS_DEFAULT+=	MAXKEY SPHINX SPIDER
OPTIONS_GROUP=		COMPRESSION ENGINES GROONGA
OPTIONS_GROUP_COMPRESSION=	LZ4 LZO SNAPPY
OPTIONS_GROUP_ENGINES=	INNOBASE MROONGA OQGRAPH SPHINX SPIDER TOKUDB
OPTIONS_GROUP_GROONGA=	ZMQ MSGPACK
OPTIONS_EXCLUDE_i386=	TOKUDB

CONNECT_EXTRA_DESC=	Enable ODBC and XML in CONNECT engine
COMPRESSION_DESC=	Optional page compression
ENGINES_DESC=	Optional MariaDB storage engines
GROONGA_DESC=	Optional Mroonga features
INNOBASE_DESC=	Build InnoDB engine next to XtraDB
MAXKEY_DESC=	Change max key length from 1000 to 4000
MROONGA_DESC=	Mroonga Full Text Search engine
MSGPACK_DESC=	MsgPack support
OQGRAPH_DESC=	Open Query Graph Computation engine
SPHINX_DESC=	SphinxSE engine
SPIDER_DESC=	Partitioning and XA-transactions engine
TOKUDB_DESC=	Fractal tree index tree data structure engine
ZMQ_DESC=	ZeroMQ support
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
		-DWITH_SSL=${OPENSSLBASE} \
		-DKRB5_CONFIG=${KRB5CONFIG} \
		-DCOMPILATION_COMMENT="FreeBSD Ports"
CMAKE_ON+=	WITH_LIBWRAP
CMAKE_OFF+=	WITH_UNIT_TESTS

DATADIR=	${PREFIX}/share/mysql

.ifdef USE_MYSQL
.error You have 'USE_MYSQL' variable defined either in environment or in make(1) arguments. This leads to a circular dependency. Please undefine and try again.
.endif

CONFLICTS_INSTALL=	mariadb5*-${PKGNAMESUFFIX:C/^[0-9]*-//}-* \
			mariadb10[02-9]-${PKGNAMESUFFIX:C/^[0-9]*-//}-* \
			mysql[0-9]*-${PKGNAMESUFFIX:C/^[0-9]*-//}-* \
			mysqlwsrep* \
			percona[0-9]*-${PKGNAMESUFFIX:C/^[0-9]*-//}-*

FASTMTX_CMAKE_BOOL=	WITH_FAST_MUTEXES
GSSAPI_BASE_USES=	gssapi
GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_MIT_USES=	gssapi:mit
OPTIONS_SUB=		yes

.if ${PKGNAMESUFFIX:M*-client}
# MySQL-Client part
USES+=		readline
USE_LDCONFIG=	${PREFIX}/lib/mysql
CMAKE_ON+=	WITHOUT_SERVER
GSSAPI_NONE_CMAKE_ON=	-DPLUGIN_AUTH_GSSAPI_CLIENT=NO
.else
# MySQL-Server part
USES+=		gnome mysql:101m
USE_GNOME=	libxml2
USE_LDCONFIG+=	${PREFIX}/lib/mysql/plugin
USE_RC_SUBR=	mysql-server
USERS=		mysql
GROUPS=		mysql
CMAKE_ARGS+=	-DPLUGIN_AUTH_GSSAPI_CLIENT=NO
CMAKE_ON+=	WITH_EMBEDDED_SERVER CMAKE_SKIP_BUILD_RPATH WITHOUT_EXAMPLE_STORAGE_ENGINE

.for ENGINE in ${OPTIONS_GROUP_ENGINES}
${ENGINE}_CMAKE_OFF=	-DPLUGIN_${ENGINE}=NO
${ENGINE}_CMAKE_ON=	-DPLUGIN_${ENGINE}=DYNAMIC
.endfor

CONNECT_EXTRA_LIB_DEPENDS=	libodbc.so:databases/unixODBC
CONNECT_EXTRA_USES=	gnome
CONNECT_EXTRA_USE=	gnome=libxml2
GSSAPI_NONE_CMAKE_ON=	-DPLUGIN_AUTH_GSSAPI=NO
LZ4_BROKEN=		LZ4 compression broken in 10.1, use a newer release
LZ4_CMAKE_ON=		-DGRN_WITH_LZ4=ON  -DWITH_INNODB_LZ4=ON
LZ4_CMAKE_OFF=		-DGRN_WITH_LZ4=OFF -DWITH_INNODB_LZ4=OFF
LZ4_LIB_DEPENDS=	liblz4.so:archivers/liblz4
LZO_BROKEN=		LZO compression broken in 10.1, use a newer release
LZO_CMAKE_ON=		-DWITH_INNODB_LZO=ON
LZO_CMAKE_OFF=		-DWITH_INNODB_LZO=OFF
LZO_LIB_DEPENDS=	liblzo2.so:archivers/lzo2
MAXKEY_EXTRA_PATCHES+=	${FILESDIR}/extra-patch-include_my__compare.h
MROONGA_LIB_DEPENDS=	liblz4.so:archivers/liblz4
MROONGA_VARS=		LICENSE+=LGPL20 LICENSE_COMB=multi
MSGPACK_LIB_DEPENDS=	libmsgpackc.so:devel/msgpack
OQGRAPH_LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
			libJudy.so:devel/judy
SNAPPY_BROKEN=		Snappy compression broken in 10.1, use a newer release
SNAPPY_CMAKE_ON=	-DWITH_INNODB_SNAPPY=ON
SNAPPY_CMAKE_OFF=	-DWITH_INNODB_SNAPPY=OFF
SNAPPY_LIB_DEPENDS=	libsnappy.so:archivers/snappy
TOKUDB_PORTDOCS=	README.md
TOKUDB_VARS=		LICENSE+=PerconaFT LICENSE_COMB=multi
ZMQ_LIB_DEPENDS=	libzmq.so:net/libzmq4
.endif # ${PKGNAMESUFFIX:M*-client}

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200057
SUB_LIST+=	LEGACY_LIMITS="@comment " MODERN_LIMITS=""
.else
SUB_LIST+=	LEGACY_LIMITS="" MODERN_LIMITS="@comment "
.endif

.if defined(PPC_ABI) && ${PPC_ABI} == ELFv2
USES+=	compiler:gcc-c++11-lib
.else
USES+=	compiler:c++11-lib
.endif

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} != base && ${PORT_OPTIONS:MGSSAPI_BASE}
IGNORE=		BASE_GSSAPI is not compatible with OpenSSL from ports. Use other GSSAPI options or OpenSSL from base system
.endif

.if ${OPSYS} == FreeBSD
CMAKE_ARGS+=	-DWITH_JEMALLOC="system"
.endif

post-patch:
	@${REINPLACE_CMD} 's/*.1/${MAN1}/' ${WRKSRC}/man/CMakeLists.txt
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/mysys/my_default.c
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/scripts/mysql_config.sh
	@${MV} ${WRKSRC}/storage/mroonga/version ${WRKSRC}/storage/mroonga/version_txt
.if ${OPSYS} == DragonFly
	${CP} ${WRKSRC}/cmake/os/FreeBSD.cmake \
		${WRKSRC}/cmake/os/DragonFly.cmake
.endif


.if ${PKGNAMESUFFIX:M*-client}
post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/wsrep*
	${RM} ${STAGEDIR}${PREFIX}/bin/mysqld_safe_helper
	${RM} ${STAGEDIR}${PREFIX}/share/aclocal/mysql.m4
	${RM} -r ${STAGEDIR}${PREFIX}/share/pkgconfig
	${RM} -r ${STAGEDIR}${PREFIX}/include/mysql/private
.else
post-install:
# Remove programs to avoid conflict with mariadb101-client
# These are "client" components, so there should be a switch that
# prevents them from being installed but it's unknown right now
	${RM} ${STAGEDIR}${PREFIX}/bin/msql2mysql \
		${STAGEDIR}${PREFIX}/bin/mysql_config \
		${STAGEDIR}${PREFIX}/bin/mysql_find_rows \
		${STAGEDIR}${PREFIX}/bin/mysqlaccess \
		${STAGEDIR}${PREFIX}/lib/mysql/plugin/client_ed25519.so \
		${STAGEDIR}${PREFIX}/share/groonga-normalizer-mysql/lgpl-2.0.txt \
		${STAGEDIR}${PREFIX}/share/groonga/COPYING \
		${STAGEDIR}${DATADIR}/mroonga/COPYING
	${RM} -r ${STAGEDIR}${PREFIX}/share/mysql/policy \
		${STAGEDIR}${PREFIX}/share/pkgconfig \
		${STAGEDIR}${PREFIX}/mysql/mysql-test \
		${STAGEDIR}${PREFIX}/mysql/sql-bench

post-install-MROONGA-on:
	${MV} ${STAGEDIR}${PREFIX}/share/groonga-normalizer-mysql \
		${STAGEDIR}${PREFIX}/share/groonga \
		${STAGEDIR}${PREFIX}/share/mysql
.endif # ${PKGNAMESUFFIX:M*-client}

.include <bsd.port.post.mk>
