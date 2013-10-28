# $FreeBSD$

PORTNAME?=	percona
DISTVERSION=	5.5.34-32.0
DISTNAME=	Percona-Server-5.5.34-rel32.0
PORTREVISION?=	0
CATEGORIES=	databases ipv6
# rel link http://www.percona.com/downloads/Percona-Server-5.5/LATEST/release-5.5.34-32.0/591/source/Percona-Server-5.5.34-rel32.0.tar.gz
#          http://www.percona.com/downloads/Percona-Server-5.5/LATEST/release-5.5.34.32.0/591/source/Percona-Server-5.5.34-rel32.0.tar.gz
MASTER_SITES=	http://www.percona.com/downloads/Percona-Server-5.5/LATEST/release-${DISTVERSION:S/rel//}/591/source/
MASTER_SITE_SUBDIR=	MySQL-5.5
PKGNAMESUFFIX?=	55-server

MAINTAINER=	flo@FreeBSD.org
COMMENT?=	Multithreaded SQL database (server)

SLAVEDIRS=	databases/percona55-client
USES=		bison cmake shebangfix

OPTIONS_DEFINE=	OPENSSL FASTMTX
OPTIONS_DEFAULT=	OPENSSL
FASTMTX_DESC=	Replace mutexes with spinlocks

DATADIR=	${PREFIX}/share/mysql

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
		-DWITH_LIBEDIT=0 \
		-DWITH_LIBWRAP=1 \
		-DHAVE_PAM=0 \
		-DWITH_UNIT_TESTS=0

SHEBANG_FILES=	scripts/*.pl* scripts/*.sh

.ifdef USE_MYSQL
.error You have `USE_MYSQL' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
CMAKE_ARGS+=	-DWITH_SSL=bundled
.endif
.if ${PORT_OPTIONS:MFASTMTX}
CMAKE_ARGS+=	-DWITH_FAST_MUTEXES=1
.endif

# MySQL-Server part
.if !defined(CLIENT_ONLY)
USE_MYSQL=	yes
WANT_MYSQL_VER=	55p

CONFLICTS_INSTALL=	mysql[0-9][0-9]-server-* mariadb[0-9][0-9]-server-* percona5.[0-46-9]-server-* percona[0-46-9][0-9]-server-*

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
.endif

post-patch:
	@${REINPLACE_CMD} 's/*.1/${MANPAGES}/' ${WRKSRC}/man/CMakeLists.txt

.include <bsd.port.pre.mk>

.if ${ARCH} == "arm"
BROKEN=		Does not compile on arm
.endif

.include <bsd.port.post.mk>
