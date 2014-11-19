# $FreeBSD$

PORTNAME?=	mariadb
PORTVERSION=	10.0.14
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

MAINTAINER=	spil.oss@gmail.com
COMMENT?=	Multithreaded SQL database (server)

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

SLAVEDIRS=	databases/mariadb100-client
USES=		bison:build cmake execinfo gmake shebangfix
SHEBANG_FILES=	scripts/*.sh
SITESDIR=	mariadb/mariadb-${PORTVERSION}/source

BROKEN_arm=	Does not compile on arm

OPTIONS_DEFINE=		SSL OPENSSL PORTSSL FASTMTX
OPTIONS_DEFAULT=	SSL
NO_OPTIONS_SORT=	yes

FASTMTX_DESC=		Replace mutexes with spinlocks
OPENSSL_DESC=		Use OpenSSL instead of bundled yassl
PORTSSL_DESC=		Use OpenSSL from port (requires OPENSSL to be set)

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

.ifdef USE_MYSQL
.error You have USE_MYSQL variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

DATADIR=	${PREFIX}/share/mysql

# MySQL-Server options
.if !defined(CLIENT_ONLY)
USE_MYSQL=		yes
OPTIONS_DEFINE+=	OQGRAPH MAXKEY
OPTIONS_DEFAULT+=	MAXKEY

OQGRAPH_DESC=		Open Query Graph Computation engine
MAXKEY_DESC=		Change max key length from 1000 to 4000
.endif

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000012
CMAKE_ARGS+=	-DWITH_JEMALLOC="system"
.else
CMAKE_ARGS+=	-DWITH_JEMALLOC="no"
.endif

.if ${PORT_OPTIONS:MSSL}
.  if exists(${LOCALBASE}/include/openssl/opensslv.h)
.    if !${PORT_OPTIONS:MOPENSSL} || !${PORT_OPTIONS:MPORTSSL}
IGNORE=	security/openssl package is installed. To build this either select the OPENSSL and PORTSSL options or deinstall openssl
.    endif
.  endif
.  if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
.    if !${PORT_OPTIONS:MPORTSSL}
WITH_OPENSSL_BASE=	yes
.    else
WITH_OPENSSL_PORT=	yes
.    endif
CMAKE_ARGS+=	-DWITH_SSL=yes
.  else
CMAKE_ARGS+=	-DWITH_SSL=bundled
.  endif
.else
CMAKE_FLAGS+=	-DWITH_SSL=no
.endif

.if ${PORT_OPTIONS:MFASTMTX}
CMAKE_ARGS+=	-DWITH_FAST_MUTEXES=1
.endif

# MySQL-Client part
.if defined(CLIENT_ONLY)
USES+=		readline
.else
# MySQL-Server part

CONFLICTS_INSTALL=	mysql[0-9][0-9]-server-* mariadb[0-9][0-9]-server-* percona[0-9][0-9]-server-*

USE_MYSQL=	yes
WANT_MYSQL_VER=	100m
USE_RC_SUBR=	mysql-server
USERS=		mysql
GROUPS=		mysql
CMAKE_ARGS+=	-DWITH_EMBEDDED_SERVER="ON" \
		-DCMAKE_SKIP_BUILD_RPATH:BOOL=YES \
		-DWITHOUT_EXAMPLE_STORAGE_ENGINE=1

.  if empty(PORT_OPTIONS:MOQGRAPH)
CMAKE_ARGS+=	-DWITHOUT_OQGRAPH=1
PLIST_SUB+=	OQGRAPH="@comment "
.  else
USE_GCC?=	yes
CMAKE_ARGS+=	-DWITH_OQGRAPH_STORAGE_ENGINE=1
PLIST_SUB+=	OQGRAPH=""
LIB_DEPENDS+=	libboost_system.so:${PORTSDIR}/devel/boost-libs
.  endif
.  if ${PORT_OPTIONS:MMAXKEY}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-include_my_compare.h
.  endif

post-install:
	# Remove programs to avoid conflict with mariadb100-client
	# These are "client" components, so there should be a switch that
	# prevents them from being installed but it's unknown right now
	${RM} ${STAGEDIR}${PREFIX}/bin/msql2mysql \
		${STAGEDIR}${PREFIX}/bin/mysql_config \
		${STAGEDIR}${PREFIX}/bin/mysql_find_rows \
		${STAGEDIR}${PREFIX}/bin/mysqlaccess
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

.include <bsd.port.mk>
