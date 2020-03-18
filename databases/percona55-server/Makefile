# $FreeBSD$

PORTNAME?=	percona
DISTVERSION=	5.5.61-38.13
PORTREVISION?=	4
CATEGORIES=	databases
MASTER_SITES=	http://www.percona.com/downloads/Percona-Server-5.5/Percona-Server-${DISTVERSION}/source/tarball/
PKGNAMESUFFIX?=	55-server
DISTNAME=	percona-server-${DISTVERSION}

MAINTAINER=	flo@FreeBSD.org
COMMENT?=	Multithreaded SQL database (server)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

SLAVEDIRS=	databases/percona55-client
USES=		bison cmake:insource,noninja readline shebangfix

CXXFLAGS+=	${CPPFLAGS}

OPTIONS_DEFINE=	OPENSSL FASTMTX
OPTIONS_DEFAULT=	OPENSSL
FASTMTX_DESC=	Replace mutexes with spinlocks

DATADIR=	${PREFIX}/share/mysql

CMAKE_ARGS+=	-DINSTALL_DOCDIR="share/doc/mysql" \
		-DINSTALL_DOCREADMEDIR="share/doc/mysql" \
		-DINSTALL_INCLUDEDIR="include/mysql" \
		-DINSTALL_INFODIR="${INFO_PATH}" \
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
		-DWITH_LIBEDIT=0 \
		-DWITH_LIBWRAP=1 \
		-DHAVE_PAM=0 \
		-DWITH_UNIT_TESTS=0 \
		-DENABLE_DTRACE=OFF

SHEBANG_FILES=	scripts/*.pl* scripts/*.sh

.include <bsd.port.options.mk>

.if defined(PPC_ABI) && ${PPC_ABI} == ELFv2
USES+=		compiler:gcc-c++11-lib
USE_CXXSTD=	gnu++11
.else
USES+=		compiler:c11
USE_CXXSTD=	gnu++98
.endif

.if ${PORT_OPTIONS:MOPENSSL}
CMAKE_ARGS+=	-DWITH_SSL=system
USES+=		ssl
.endif
.if ${PORT_OPTIONS:MFASTMTX}
CMAKE_ARGS+=	-DWITH_FAST_MUTEXES=1
.endif

# MySQL-Server part
.if !defined(CLIENT_ONLY)
USES+=mysql:55p

CONFLICTS_INSTALL=	mysql*-server-* \
			mysqlwsrep* \
			mariadb*-server-* \
			percona5[0-46-9]-server-*

USE_RC_SUBR=	mysql-server

USERS=		mysql
GROUPS=		mysql

INFO=		mysql

MANPAGES=	my_print_defaults.1 myisam_ftdump.1 myisamchk.1 myisamlog.1 myisampack.1 \
		mysql.server.1 mysql_convert_table_format.1 mysql_fix_extensions.1 \
		mysql_install_db.1 mysql_plugin.1 mysql_secure_installation.1 mysql_setpermission.1 \
		mysql_tzinfo_to_sql.1 mysql_upgrade.1 mysql_zap.1 mysqlbug.1 \
		mysqld_multi.1 mysqld_safe.1 mysqldumpslow.1 mysqlhotcopy.1 mysqlman.1 \
		mysqltest.1 perror.1 replace.1 resolve_stack_dump.1 resolveip.1

CMAKE_ARGS+=	-DWITH_EMBEDDED_SERVER="ON"

post-install:
	@${MKDIR} ${STAGEDIR}/var/db/mysql

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200057
SUB_LIST+=	LEGACY_LIMITS="@comment " MODERN_LIMITS=""
.else
SUB_LIST+=	LEGACY_LIMITS="" MODERN_LIMITS="@comment "
.endif

.endif

post-patch:
	@${REINPLACE_CMD} 's/*.1/${MANPAGES}/' ${WRKSRC}/man/CMakeLists.txt

.include <bsd.port.pre.mk>

.if ${ARCH} == "arm"
BROKEN=		Does not compile on arm
.endif

.include <bsd.port.post.mk>
