# $FreeBSD$

PORTNAME?=	mariadb
PORTVERSION=	10.0.23
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

LICENSE=	GPLv2

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

SLAVEDIRS=	databases/mariadb100-client
USES=		bison:build cmake cpe execinfo gmake shebangfix
USE_LDCONFIG=	${PREFIX}/lib/mysql ${PREFIX}/lib/mysql/plugin
SHEBANG_FILES=	scripts/*.sh
SITESDIR=	mariadb/mariadb-${PORTVERSION}/source

OPTIONS_DEFINE=		FASTMTX
OPTIONS_RADIO=		SSL
OPTIONS_RADIO_SSL=	BUNDLED_SSL OPENSSL WITHOUT_SSL
OPTIONS_DEFAULT+=	OPENSSL
NO_OPTIONS_SORT=	yes

BUNDLED_SSL_DESC=	SSL/TLS support via (bundled) CyaSSL
FASTMTX_DESC=		Replace mutexes with spinlocks
WITHOUT_SSL_DESC=	No SSL/TLS support

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
		-DWITH_LIBEDIT=0 \
		-DWITH_LIBWRAP=1 \
		-DEXECINFO_ROOT=${LOCALBASE} \
		-DCOMPILATION_COMMENT="FreeBSD Ports"

DATADIR=	${PREFIX}/share/mysql

.ifdef USE_MYSQL
.error You have `USE_MYSQL' variable defined either in environment or in make(1) arguments. This leads to a circular dependency. Please undefine and try again.
.endif

CONFLICTS_INSTALL=	mariadb5*-${PKGNAMESUFFIX:C/^[0-9]*-//}-* \
			mariadb10[1-9]-${PKGNAMESUFFIX:C/^[0-9]*-//}-* \
			mysql[0-9]*-${PKGNAMESUFFIX:C/^[0-9]*-//}-* \
			percona[0-9]*-${PKGNAMESUFFIX:C/^[0-9]*-//}-* \

.if !defined(CLIENT_ONLY)
# MySQL-Server options
USE_MYSQL=		yes
USE_LDCONFIG+=		${PREFIX}/lib/mysql/plugin
OPTIONS_DEFINE+=	INNODB MAXKEY MROONGA OQGRAPH
OPTIONS_DEFAULT+=	MAXKEY
OPTIONS_SUB=		yes

INNODB_DESC=		Build InnoDB engine next to XtraDB
MAXKEY_DESC=		Change max key length from 1000 to 4000
MROONGA_DESC=		Mroonga Full Text Search engine (gcc)
OQGRAPH_DESC=		Open Query Graph Computation engine (gcc)
.endif

BUNDLED_SSL_CMAKE_ON=	-DWITH_SSL=bundled
FASTMTX_CMAKE_ON=	-DWITH_FAST_MUTEXES=1
OPENSSL_CMAKE_ON=	-DWITH_SSL=yes
OPENSSL_USE=	OPENSSL=yes
WITHOUT_SSL_CMAKE_ON=	-DWITH_SSL=no

.if defined(CLIENT_ONLY)
# MySQL-Client part
USES+=		readline
.else
# MySQL-Server part
USE_MYSQL=	yes
WANT_MYSQL_VER=	100m
USE_RC_SUBR=	mysql-server
USERS=		mysql
GROUPS=		mysql
CMAKE_ARGS+=	-DWITH_EMBEDDED_SERVER="ON" \
		-DCMAKE_SKIP_BUILD_RPATH:BOOL=YES \
		-DWITHOUT_EXAMPLE_STORAGE_ENGINE=1

INNODB_CMAKE_OFF=	-DWITHOUT_INNOBASE=1
MAXKEY_EXTRA_PATCHES+=	${FILESDIR}/extra-patch-include_my__compare.h
MROONGA_CMAKE_OFF=	-DWITHOUT_MROONGA=1
OQGRAPH_CMAKE_OFF=	-DWITHOUT_OQGRAPH=1
OQGRAPH_LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
			libJudy.so:devel/judy
# Currently OQGraph does not build using clang.
# See See https://mariadb.atlassian.net/browse/MDEV-8051.
OQGRPAH_USE=		gcc

post-install:
	# Remove programs to avoid conflict with mariadb100-client
	# These are "client" components, so there should be a switch that
	# prevents them from being installed but it's unknown right now
	${RM} ${STAGEDIR}${PREFIX}/bin/msql2mysql \
		${STAGEDIR}${PREFIX}/bin/mysql_config \
		${STAGEDIR}${PREFIX}/bin/mysql_find_rows \
		${STAGEDIR}${PREFIX}/bin/mysqlaccess
.endif

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000012
CMAKE_ARGS+=	-DWITH_JEMALLOC="system"
.else
CMAKE_ARGS+=	-DWITH_JEMALLOC="no"
.endif

# Server segfaults on i386 when built with clang >= 3.4
.if ${ARCH} == 'i386' && ${OSVERSION} >= 1001000
USE_GCC=	yes
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

.include <bsd.port.post.mk>
