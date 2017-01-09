# $FreeBSD$

PORTNAME?=	mariadb
PORTVERSION=	10.1.20
PORTREVISION=	1
CATEGORIES=	databases ipv6
MASTER_SITES=	http://ftp.osuosl.org/pub/${SITESDIR}/ \
		http://mirrors.supportex.net/${SITESDIR}/ \
		http://mirror2.hs-esslingen.de/pub/Mirrors/${SITESDIR}/ \
		http://gd.tuwien.ac.at/db/${SITESDIR}/ \
		http://mirrors.fe.up.pt/pub/${SITESDIR}/ \
		http://mirror.de.gsnw.de:56431/${SITESDIR}/ \
		http://mirror.layerjet.com/${SITESDIR}/ \
		http://mirror.switch.ch/mirror/${SITESDIR}/
PKGNAMESUFFIX?=	101-server

MAINTAINER=	brnrd@FreeBSD.org
COMMENT?=	Multithreaded SQL database (server)

LICENSE=	GPLv2
LICENSE_NAME_PerconaFT=	PerconaFT patents license
LICENSE_FILE_PerconaFT=	${WRKSRC}/storage/tokudb/PerconaFT/PATENTS
LICENSE_PERMS_PerconaFT=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_aarch64=		Fails to link: missing sbrk
BROKEN_powerpc64=	Does not build

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

SLAVEDIRS=	databases/mariadb101-client
USES=		bison:build cmake compiler:c++11-lib cpe execinfo ncurses \
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

.if !defined(CLIENT_ONLY)
# MySQL-Server options
OPTIONS_DEFINE+=	MAXKEY
OPTIONS_DEFAULT+=	MAXKEY SPHINX SPIDER
OPTIONS_GROUP=		ENGINES
OPTIONS_GROUP_ENGINES=	INNOBASE MROONGA OQGRAPH SPHINX SPIDER TOKUDB
OPTIONS_EXCLUDE_i386=	TOKUDB

ENGINES_DESC=	Optional MariaDB storage engines
INNOBASE_DESC=	Build InnoDB engine next to XtraDB
MAXKEY_DESC=	Change max key length from 1000 to 4000
MROONGA_DESC=	Mroonga Full Text Search engine
OQGRAPH_DESC=	Open Query Graph Computation engine
SPHINX_DESC=	SphinxSE engine
SPIDER_DESC=	Partitioning and XA-transactions engine
TOKUDB_DESC=	Fractal tree index tree data structure engine
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
		-DWITH_UNIT_TESTS=0 \
		-DWITH_LIBWRAP=1 \
		-DWITH_SSL=${OPENSSLBASE} \
		-DKRB5_CONFIG=${KRB5CONFIG} \
		-DEXECINFO_ROOT=${LOCALBASE} \
		-DCOMPILATION_COMMENT="FreeBSD Ports"

DATADIR=	${PREFIX}/share/mysql

.ifdef USE_MYSQL
.error You have 'USE_MYSQL' variable defined either in environment or in make(1) arguments. This leads to a circular dependency. Please undefine and try again.
.endif

CONFLICTS_INSTALL=	mariadb5*-${PKGNAMESUFFIX:C/^[0-9]*-//}-* \
			mariadb10[02-9]-${PKGNAMESUFFIX:C/^[0-9]*-//}-* \
			mysql[0-9]*-${PKGNAMESUFFIX:C/^[0-9]*-//}-* \
			percona[0-9]*-${PKGNAMESUFFIX:C/^[0-9]*-//}-*

FASTMTX_CMAKE_ON=	-DWITH_FAST_MUTEXES=1
OPTIONS_SUB=		yes

.if defined(CLIENT_ONLY)
# MySQL-Client part
USES+=		readline
GSSAPI_NONE_CMAKE_ON=	-DPLUGIN_AUTH_GSSAPI_CLIENT=NO
.else
# MySQL-Server part
USES+=		mysql:101m
USE_GNOME=	libxml2
USE_LDCONFIG+=	${PREFIX}/lib/mysql/plugin
USE_RC_SUBR=	mysql-server
USERS=		mysql
GROUPS=		mysql
CMAKE_ARGS+=	-DWITH_EMBEDDED_SERVER="ON" \
		-DPLUGIN_AUTH_GSSAPI_CLIENT=NO \
		-DCMAKE_SKIP_BUILD_RPATH:BOOL=YES \
		-DWITHOUT_EXAMPLE_STORAGE_ENGINE=1

.for ENGINE in ${OPTIONS_GROUP_ENGINES}
${ENGINE}_CMAKE_OFF=	-DPLUGIN_${ENGINE}=NO \
			-DWITHOUT_${ENGINE}=1
.endfor

GSSAPI_NONE_CMAKE_ON=	-DPLUGIN_AUTH_GSSAPI=NO
MAXKEY_EXTRA_PATCHES+=	${FILESDIR}/extra-patch-include_my__compare.h
MROONGA_LIB_DEPENDS=	liblz4.so:archivers/liblz4
OQGRAPH_LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
			libJudy.so:devel/judy
TOKUDB_LIB_DEPENDS=	libsnappy.so:archivers/snappy
TOKUDB_PORTDOCS=	README.md
TOKUDB_VARS=		LICENSE+=PerconaFT LICENSE_COMB=multi
NOT_FOR_ARCHS=		i386
NOT_FOR_ARCHS_REASON=	currently does not compile on i386, see \
			https://mariadb.atlassian.net/browse/MDEV-9627

post-install:
# Remove programs to avoid conflict with mariadb101-client
# These are "client" components, so there should be a switch that
# prevents them from being installed but it's unknown right now
	${RM} ${STAGEDIR}${PREFIX}/bin/msql2mysql \
		${STAGEDIR}${PREFIX}/bin/mysql_config \
		${STAGEDIR}${PREFIX}/bin/mysql_find_rows \
		${STAGEDIR}${PREFIX}/bin/mysqlaccess
	${RM} -r ${STAGEDIR}${PREFIX}/share/mysql/policy \
		${STAGEDIR}${PREFIX}/share/pkgconfig
.endif # defined(CLIENT_ONLY)

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
.if ${OPSYS} == DragonFly
	${CP} ${WRKSRC}/cmake/os/FreeBSD.cmake \
		${WRKSRC}/cmake/os/DragonFly.cmake
.endif

post-configure-MROONGA-on:
	@${REINPLACE_CMD} "s|/usr/bin/c++ |/usr/bin/c++ -L${LOCALBASE}/lib |" \
		${WRKSRC}/storage/mroonga/CMakeFiles/mroonga.dir/link.txt

.include <bsd.port.post.mk>
