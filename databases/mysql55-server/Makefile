# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	mysql
PORTVERSION=	5.5.62
PORTREVISION?=	3
CATEGORIES=	databases
MASTER_SITES=	MYSQL/MySQL-5.5
PKGNAMESUFFIX?=	55-server

MAINTAINER=	ale@FreeBSD.org
COMMENT?=	Multithreaded SQL database (server)

LICENSE=	GPLv2

SLAVEDIRS=	databases/mysql55-client
USES=		cmake:insource,noninja compiler:c++11-lang readline shebangfix
CXXFLAGS+=	${CPPFLAGS}
NO_OPTIONS_SORT=yes

OPTIONS_DEFINE=	SSL FASTMTX
OPTIONS_DEFAULT=SSL

FASTMTX_DESC=	Replace mutexes with spinlocks

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
		-DWITH_LIBWRAP=1

SHEBANG_FILES=	scripts/*.pl* scripts/*.sh

.ifdef USE_MYSQL
.error You have `USE_MYSQL' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200057
SUB_LIST+=	LEGACY_LIMITS="@comment " MODERN_LIMITS=""
.else
SUB_LIST+=	LEGACY_LIMITS="" MODERN_LIMITS="@comment "
.endif

.if ${PORT_OPTIONS:MSSL}
CMAKE_ARGS+=	-DWITH_SSL=bundled
.endif
.if ${PORT_OPTIONS:MFASTMTX}
CMAKE_ARGS+=	-DWITH_FAST_MUTEXES=1
.endif

# MySQL-Server part
.if !defined(CLIENT_ONLY)
USE_MYSQL=	yes
WANT_MYSQL_VER=	55

CONFLICTS_INSTALL=	mysql5[0-46-9]-server-* \
			mysqlwsrep* \
			mariadb*-server-* \
			percona*-server-*

USE_RC_SUBR=	mysql-server

USERS=		mysql
GROUPS=		mysql

MMAN1=		my_print_defaults.1 myisam_ftdump.1 myisamchk.1 myisamlog.1 myisampack.1 \
		mysql.server.1 mysql_convert_table_format.1 mysql_fix_extensions.1 \
		mysql_install_db.1 mysql_plugin.1 mysql_secure_installation.1 mysql_setpermission.1 \
		mysql_tzinfo_to_sql.1 mysql_upgrade.1 mysql_zap.1 mysqlbug.1 \
		mysqld_multi.1 mysqld_safe.1 mysqldumpslow.1 mysqlhotcopy.1 mysqlman.1 \
		perror.1 replace.1 resolve_stack_dump.1 resolveip.1

CMAKE_ARGS+=	-DWITH_EMBEDDED_SERVER="ON"
.endif

post-patch:
	@${REINPLACE_CMD} 's/*.1/${MMAN1}/' ${WRKSRC}/man/CMakeLists.txt

.include <bsd.port.pre.mk>

.if ${ARCH} == armv6 || ${ARCH} == armv7
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-config.h.cmake
.endif

.include <bsd.port.post.mk>
