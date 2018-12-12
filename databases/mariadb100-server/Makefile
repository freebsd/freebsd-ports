# $FreeBSD$

PORTNAME?=	mariadb
PORTVERSION=	10.0.37
PORTREVISION?=	2
CATEGORIES=	databases ipv6
MASTER_SITES=	http://ftp.osuosl.org/pub/${SITESDIR}/ \
		http://mirrors.supportex.net/${SITESDIR}/ \
		http://mirror2.hs-esslingen.de/pub/Mirrors/${SITESDIR}/ \
		http://gd.tuwien.ac.at/db/${SITESDIR}/ \
		http://mirrors.fe.up.pt/pub/${SITESDIR}/ \
		http://mirror.de.gsnw.de:56431/${SITESDIR}/ \
		http://mirror.layerjet.com/${SITESDIR}/ \
		http://mirror.switch.ch/mirror/${SITESDIR}/
PKGNAMESUFFIX?=	100-server

MAINTAINER=	brnrd@FreeBSD.org
COMMENT?=	Multithreaded SQL database (server)

DEPRECATED=	Upstream End-of-Life March 2019 (https://mariadb.org/about/maintenance-policy/)
EXPIRATION_DATE=	2019-04-01

LICENSE=	GPLv2
LICENSE_NAME_PerconaFT=	PerconaFT patents license
LICENSE_FILE_PerconaFT=	${WRKSRC}/storage/tokudb/PerconaFT/PATENTS
LICENSE_PERMS_PerconaFT=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_SSL=		openssl111
BROKEN_SSL_REASON_openssl111=	Does not support OpenSSL 1.1, use MariaDB 10.2 or 10.3

SUB_FILES=	pkg-message

SLAVEDIRS=	databases/mariadb100-client
USES=		bison:build cmake:noninja compiler:c++11-lib cpe \
		ncurses shebangfix ssl
USE_LDCONFIG=	${PREFIX}/lib/mysql ${PREFIX}/lib/mysql/plugin
SHEBANG_FILES=	scripts/*.sh
SITESDIR=	mariadb/mariadb-${PORTVERSION}/source

OPTIONS_DEFINE=		FASTMTX
NO_OPTIONS_SORT=	yes

FASTMTX_DESC=		Replace mutexes with spinlocks

CMAKE_ARGS+=	-DINSTALL_DOCDIR="share/doc/mariadb" \
		-DINSTALL_DOCREADMEDIR="share/doc/mariadb" \
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
		-DWITH_UNIT_TESTS=0 \
		-DWITH_SSL=${OPENSSLBASE} \
		-DWITH_LIBWRAP=1 \
		-DCOMPILATION_COMMENT="FreeBSD Ports"

DATADIR=	${PREFIX}/share/mysql

.ifdef USE_MYSQL
.error You have `USE_MYSQL' variable defined either in environment or in make(1) arguments. This leads to a circular dependency. Please undefine and try again.
.endif

CONFLICTS_INSTALL=	mariadb5*-${PKGNAMESUFFIX:C/^[0-9]*-//}-* \
			mariadb10[1-9]-${PKGNAMESUFFIX:C/^[0-9]*-//}-* \
			mysql[0-9]*-${PKGNAMESUFFIX:C/^[0-9]*-//}-* \
			mysqlwsrep* \
			percona[0-9]*-${PKGNAMESUFFIX:C/^[0-9]*-//}-* \

.if !defined(CLIENT_ONLY)
# MySQL-Server options
OPTIONS_DEFINE+=	CONNECT_EXTRA MAXKEY DOCS
OPTIONS_DEFAULT+=	MAXKEY
OPTIONS_GROUP=		ENGINES
OPTIONS_GROUP_ENGINES=	INNOBASE MROONGA OQGRAPH SPHINX SPIDER TOKUDB

CONNECT_EXTRA_DESC=	Enable ODBC and XML in CONNECT engine
ENGINES_DESC=	Optional MariaDB storage engines
INNOBASE_DESC=	Build InnoDB engine next to XtraDB
MAXKEY_DESC=	Change max key length from 1000 to 4000
MROONGA_DESC=	Mroonga Full Text Search engine
OQGRAPH_DESC=	Open Query Graph Computation engine (Requires GCC)
SPHINX_DESC=	SphinxSE engine
SPIDER_DESC=	Partitioning and XA-transactions engine
TOKUDB_DESC=	Fractal tree index tree data structure engine

OPTIONS_SUB=	yes

.endif

FASTMTX_CMAKE_ON=	-DWITH_FAST_MUTEXES=1

.if defined(CLIENT_ONLY)
# MySQL-Client part
USES+=		readline
.else
# MySQL-Server part
BROKEN_powerpc64=	Does not build: fatal error: sys/platform/ppc.h: No such file or directory
USES+=		mysql:100m
USE_LDCONFIG+=	${PREFIX}/lib/mysql/plugin
USE_RC_SUBR=	mysql-server
USERS=		mysql
GROUPS=		mysql
CMAKE_ARGS+=	-DWITH_EMBEDDED_SERVER="ON" \
		-DCMAKE_SKIP_BUILD_RPATH:BOOL=YES \
		-DWITHOUT_EXAMPLE_STORAGE_ENGINE=1

.for ENGINE in ${OPTIONS_GROUP_ENGINES}
${ENGINE}_CMAKE_OFF=    -DWITHOUT_${ENGINE}=1
.endfor

CONNECT_EXTRA_LIB_DEPENDS=	libodbc.so:databases/unixODBC
CONNECT_EXTRA_USE=	gnome=libxml2
MAXKEY_EXTRA_PATCHES+=	${FILESDIR}/extra-patch-include_my__compare.h
MROONGA_CMAKE_OFF=	-DWITHOUT_MROONGA=1
MROONGA_LIB_DEPENDS=	liblz4.so:archivers/liblz4
OQGRAPH_LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
			libJudy.so:devel/judy
TOKUDB_LIB_DEPENDS=	libsnappy.so:archivers/snappy
TOKUDB_PORTDOCS=	PATENTS README.md
TOKUDB_VARS=		LICENSE+=PerconaFT LICENSE_COMB=multi

post-install:
	# Remove programs to avoid conflict with mariadb100-client
	# These are "client" components, so there should be a switch that
	# prevents them from being installed but it's unknown right now
.	for f in bin/msql2mysql bin/mysql_config bin/mysql_find_rows \
		bin/mysqlaccess share/aclocal/mysql.m4
		${RM} ${STAGEDIR}${PREFIX}/${f}
.	endfor
	${RM} -r ${STAGEDIR}${DATADIR}/SELinux

post-install-TOKUDB-on:
	${RM} ${STAGEDIR}${DOCSDIR}/COPYING.GPLv2 \
		${STAGEDIR}${DOCSDIR}/COPYING.AGPLv3
.endif

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
.  if ${OSVERSION} >= 1200085 && ${SSL_DEFAULT} == base
BROKEN=	${BROKEN_SSL_REASON_openssl111}
.  endif
CMAKE_ARGS+=	-DWITH_JEMALLOC="system"
.else
CMAKE_ARGS+=	-DWITH_JEMALLOC="no"
.endif

.if ${PORT_OPTIONS:MTOKUDB}
NOT_FOR_ARCHS=		i386
NOT_FOR_ARCHS_REASON=	TokuDB not supported on 32-bit platforms, see \
			https://github.com/percona/PerconaFT/blob/master/README.md
.endif

.if ${ARCH} == 'i386'
# Server segfaults on i386 when built with clang >= 3.4
USE_GCC=	yes
.endif

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200057
SUB_LIST+=	LEGACY_LIMITS="@comment " MODERN_LIMITS=""
.else
SUB_LIST+=	LEGACY_LIMITS="" MODERN_LIMITS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} 's/*.1/${MAN1}/' ${WRKSRC}/man/CMakeLists.txt
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/mysys/my_default.c
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/scripts/mysql_config.sh
.if ${OPSYS} == DragonFly
	${CP} ${WRKSRC}/cmake/os/FreeBSD.cmake \
		${WRKSRC}/cmake/os/DragonFly.cmake
	${MV} ${WRKSRC}/storage/tokudb ${WRKSRC}/skip-tokudb
.endif

# This file is being generated incorrectly for unknown reasons.
# See https://bugs.freebsd.org/230839 for details.
post-configure:
	${REINPLACE_CMD} -e 's|-l-pthread|-pthread|g' ${WRKSRC}/scripts/mysql_config

post-configure-MROONGA-on:
	${REINPLACE_CMD} 's|-llz4|-L${LOCALBASE}/lib -llz4|' \
		${WRKSRC}/storage/mroonga/CMakeFiles/mroonga.dir/link.txt

.include <bsd.port.post.mk>
