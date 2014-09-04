# $FreeBSD$

PORTNAME?=	mariadb
PORTVERSION=	5.5.39
CATEGORIES=	databases ipv6
MASTER_SITES=	http://ftp.osuosl.org/pub/mariadb/${PORTNAME}-${PORTVERSION}/source/ \
		http://mirrors.supportex.net/mariadb/${PORTNAME}-${PORTVERSION}/source/ \
		http://mirror.aarnet.edu.au/pub/MariaDB/${PORTNAME}-${PORTVERSION}/source/ \
		http://mirror2.hs-esslingen.de/pub/Mirrors/mariadb/${PORTNAME}-${PORTVERSION}/source/ \
		http://gd.tuwien.ac.at/db/mariadb/${PORTNAME}-${PORTVERSION}/source/ \
		http://mirrors.fe.up.pt/pub/mariadb/${PORTNAME}-${PORTVERSION}/source/ \
		http://mirror.de.gsnw.de:56431/mariadb/${PORTNAME}-${PORTVERSION}/source/ \
		http://mirror.layerjet.com/mariadb/${PORTNAME}-${PORTVERSION}/source/ \
		http://mirror.switch.ch/mirror/mariadb/${PORTNAME}-${PORTVERSION}/source/
PKGNAMESUFFIX?=	55-server

MAINTAINER=	never@nevermind.kiev.ua
COMMENT?=	Multithreaded SQL database (server)

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

SLAVEDIRS=	databases/mariadb55-client
USES=		cmake gmake shebangfix
SHEBANG_FILES=	scripts/*.sh
NO_OPTIONS_SORT=yes

OPTIONS_DEFINE+=	SSL OPENSSL PORTSSL FASTMTX
OPTIONS_DEFAULT+=	SSL

FASTMTX_DESC=	Replace mutexes with spinlocks
OPENSSL_DESC=	Use OpenSSL instead of bundled yassl
PORTSSL_DESC=	Use OpenSSL from port (requires OPENSSL to be set)

CMAKE_ARGS+=	-DINSTALL_DOCDIR="share/doc/mysql" \
		-DINSTALL_DOCREADMEDIR="share/doc/mysql" \
		-DINSTALL_INCLUDEDIR="include/mysql" \
		-DINSTALL_INFODIR="info" \
		-DINSTALL_LIBDIR="lib/mysql" \
		-DINSTALL_MANDIR="man" \
		-DINSTALL_MYSQLDATADIR="/var/db/mysql" \
		-DINSTALL_MYSQLSHAREDIR="share/mysql" \
		-DINSTALL_MYSQLTESTDIR="share/mysql/tests" \
		-DINSTALL_PLUGINDIR="lib/mysql/plugin" \
		-DINSTALL_SBINDIR="libexec" \
		-DINSTALL_SCRIPTDIR="bin" \
		-DINSTALL_SHAREDIR="share" \
		-DINSTALL_SQLBENCHDIR="share/mysql" \
		-DINSTALL_SUPPORTFILESDIR="share/mysql" \
		-DWITH_UNIT_TESTS=0 \
		-DWITH_LIBEDIT=0 \
		-DWITH_LIBWRAP=1 \
		-DEXECINFO_ROOT=${LOCALBASE} \
		-DCOMPILATION_COMMENT="FreeBSD Ports"

.ifdef USE_MYSQL
.error You have `USE_MYSQL' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

DATADIR=	${PREFIX}/share/mysql

# MySQL-Server options
.if !defined(CLIENT_ONLY)
OPTIONS_DEFINE+=	OQGRAPH MAXKEY

OQGRAPH_DESC=	Open Query Graph Computation engine
MAXKEY_DESC=	Change max key length from 1000 to 4000

OPTIONS_DEFAULT+=	MAXKEY
.endif

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000052
LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo
.endif

.if ${OSVERSION} < 1000012
CMAKE_ARGS+=	-DWITH_JEMALLOC="bundled"
.else
CMAKE_ARGS+=	-DWITH_JEMALLOC="system"
.endif

.if ${PORT_OPTIONS:MSSL}
.if exists(${LOCALBASE}/include/openssl/opensslv.h)
.  if !${PORT_OPTIONS:MOPENSSL} || !${PORT_OPTIONS:MPORTSSL}
IGNORE=	security/openssl package is installed. To build this either select the OPENSSL and PORTSSL options or deinstall openssl
.  endif
.endif
.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
.if !${PORT_OPTIONS:MPORTSSL}
WITH_OPENSSL_BASE=	yes
.else
WITH_OPENSSL_PORT=	yes
.endif
CMAKE_ARGS+=	-DWITH_SSL=yes
.else
CMAKE_ARGS+=	-DWITH_SSL=bundled
.endif
.else
CMAKE_FLAGS+=	-DWITH_SSL=no
.endif
.if ${PORT_OPTIONS:MFASTMTX}
CMAKE_ARGS+=	-DWITH_FAST_MUTEXES=1
.endif

# MySQL-Server part
.if !defined(CLIENT_ONLY)
USE_MYSQL=	yes
WANT_MYSQL_VER=	55m

CONFLICTS_INSTALL=	mysql[0-9][0-9]-server-* mariadb[0-46-9][0-9]-server-* mariadb5.[0-46-9]-server-* percona[0-9][0-9]-server-*

USE_RC_SUBR=	mysql-server

USERS=		mysql
GROUPS=		mysql

CMAKE_ARGS+=	-DWITH_EMBEDDED_SERVER="ON" \
		-DWITHOUT_EXAMPLE_STORAGE_ENGINE=1

post-install:
.if !defined(PACKAGE_BUILDING)
	@${CAT} ${PKGMESSAGE}
.endif

.if empty(PORT_OPTIONS:MOQGRAPH)
CMAKE_ARGS+=	-DWITHOUT_OQGRAPH_STORAGE_ENGINE=1
PLIST_SUB+=	OQGRAPH="@comment "
.else
USE_GCC?=	yes
CMAKE_ARGS+=	-DWITH_OQGRAPH_STORAGE_ENGINE=1
PLIST_SUB+=	OQGRAPH=""
LIB_DEPENDS+=	libboost_system.so:${PORTSDIR}/devel/boost-libs
.endif
.if ${PORT_OPTIONS:MMAXKEY}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-include_my_compare.h
.endif
.else
USES+=		readline
.endif

post-patch:
	@${REINPLACE_CMD} 's/*.1/${MAN1}/' ${WRKSRC}/man/CMakeLists.txt
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/mysys/default.c
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/scripts/mysql_config.sh

.include <bsd.port.pre.mk>

.if ${ARCH} == "arm"
BROKEN=		Does not compile on arm
.endif

.include <bsd.port.post.mk>
