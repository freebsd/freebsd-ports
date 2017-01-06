# $FreeBSD$

PORTNAME?=	mariadb
PORTVERSION=	5.5.54
PORTREVISION?=	1
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

LICENSE=	GPLv2

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

SLAVEDIRS=	databases/mariadb55-client
USES=		cmake execinfo shebangfix ssl
SHEBANG_FILES=	scripts/*.sh

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
		-DINSTALL_SQLBENCHDIR="share/mysql" \
		-DINSTALL_SUPPORTFILESDIR="share/mysql" \
		-DWITH_UNIT_TESTS=0 \
		-DWITH_LIBEDIT=0 \
		-DWITH_LIBWRAP=1 \
		-DWITH_SSL=yes \
		-DEXECINFO_ROOT=${LOCALBASE} \
		-DCOMPILATION_COMMENT="FreeBSD Ports"

DATADIR=	${PREFIX}/share/mysql

BROKEN_aarch64=		Fails to link: missing sbrk
BROKEN_armv6=		Does not compile on armv6
BROKEN_sparc64=		Does not compile: Unsupported platform

.if defined(USE_MYSQL)
.error You have 'USE_MYSQL' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

.if !defined(CLIENT_ONLY)
# MySQL-Server part
USES+=		mysql:55m

CONFLICTS_INSTALL=	mariadb5[0-46-9]-server-* \
			mariadb1*-server-* \
			mysql[0-9]*-server-* \
			percona[0-9]*-server-*

USE_RC_SUBR=	mysql-server

USERS=		mysql
GROUPS=		mysql

CMAKE_ARGS+=	-DREADLINE_INCLUDE_DIR=/usr/include \
		-DWITH_EMBEDDED_SERVER="ON" \
		-DWITHOUT_EXAMPLE_STORAGE_ENGINE=1

.else
# MySQL-Client part
USES+=		ncurses readline
.endif

OPTIONS_DEFINE+=	FASTMTX
OPTIONS_SUB=		yes
NO_OPTIONS_SORT=yes

FASTMTX_DESC=	Replace mutexes with spinlocks

FASTMTX_CMAKE_ON=	-DWITH_FAST_MUTEXES=1

.if !defined(CLIENT_ONLY)
# MySQL-Server options
OPTIONS_DEFINE+=	MAXKEY OQGRAPH
OPTIONS_DEFAULT+=	MAXKEY

MAXKEY_DESC=	Change max key length from 1000 to 4000

OQGRAPH_DESC=	Open Query Graph Computation engine

OQGRAPH_USE=	GCC=yes
OQGRAPH_LIB_DEPENDS=	libboost_system.so:devel/boost-libs
OQGRAPH_BROKEN=	yes

MAXKEY_EXTRA_PATCHES=	${FILESDIR}/extra-patch-include_my_compare.h
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

post-extract-OQGRAPH-off:
	@${RM} -r ${WRKSRC}/storage/oqgraph

post-patch:
	@${REINPLACE_CMD} 's/*.1/${MAN1}/' ${WRKSRC}/man/CMakeLists.txt
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/mysys/default.c
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/scripts/mysql_config.sh

.include <bsd.port.post.mk>
