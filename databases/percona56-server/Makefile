# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	percona
DISTVERSION=	5.6.26-74.0
PORTREVISION?=	0
CATEGORIES=	databases ipv6
MASTER_SITES=	http://www.percona.com/downloads/Percona-Server-5.6/Percona-Server-${DISTVERSION}/source/tarball/
PKGNAMESUFFIX?=	56-server
DISTNAME=	percona-server-${DISTVERSION}

MAINTAINER=	flo@FreeBSD.org
COMMENT?=	Multithreaded SQL database (server)

SLAVEDIRS=	databases/percona56-client
USES=		bison cmake perl5 shebangfix

OPTIONS_DEFINE=	OPENSSL FASTMTX INNODBMEMCACHED
OPTIONS_DEFAULT=	OPENSSL INNODBMEMCACHED
OPTIONS_SUB=    yes
FASTMTX_DESC=	Replace mutexes with spinlocks
INNODBMEMCACHED_DESC= InnoDB Memcached plugin
INNODBMEMCACHED_CMAKE_ON=-DWITH_INNODB_MEMCACHED=1

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
		-DWITH_EDITLINE=system \
		-DWITH_LIBWRAP=1 \
		-DHAVE_PAM=0

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
WANT_MYSQL_VER=	56p

CONFLICTS_INSTALL=	mysql*-server-* \
			mariadb*-server-* \
			percona5[0-57-9]-server-*

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

.else
USES+=		libedit
.endif

post-patch:
	@${REINPLACE_CMD} 's/*.1/${MANPAGES}/' ${WRKSRC}/man/CMakeLists.txt

.include <bsd.port.pre.mk>

.if ${ARCH} == "arm"
BROKEN=		Does not compile on arm
.endif

.include <bsd.port.post.mk>
