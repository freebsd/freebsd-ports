# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	percona
DISTVERSION=	5.6.38-83.0
PORTREVISION?=	0
CATEGORIES=	databases ipv6
MASTER_SITES=	http://www.percona.com/downloads/Percona-Server-5.6/Percona-Server-${DISTVERSION}/source/tarball/
PKGNAMESUFFIX?=	56-server
DISTNAME=	percona-server-${DISTVERSION}

MAINTAINER=	flo@FreeBSD.org
COMMENT?=	Multithreaded SQL database (server)

BROKEN_armv6=		fails to compile: sql/mysqld.cc:198:19: error: cannot combine with previous 'type-name' declaration specifier
BROKEN_armv7=		fails to compile: sql/mysqld.cc:198:19: error: cannot combine with previous 'type-name' declaration specifier
NOT_FOR_ARCHS=		powerpc64
NOT_FOR_ARCHS_REASON=	unsupported platform

SLAVEDIRS=	databases/percona56-client \
		databases/percona-pam-for-mysql
USES=		bison cmake:noninja perl5 shebangfix

OPTIONS_DEFINE=	OPENSSL FASTMTX INNODBMEMCACHED TOKUDB
OPTIONS_DEFAULT=	OPENSSL INNODBMEMCACHED
OPTIONS_SUB=	yes

FASTMTX_DESC=	Replace mutexes with spinlocks
FASTMTX_CMAKE_ON=	-DWITH_FAST_MUTEXES=1
INNODBMEMCACHED_DESC=	InnoDB Memcached plugin
INNODBMEMCACHED_CMAKE_ON=	-DWITH_INNODB_MEMCACHED=1
OPENSSL_CMAKE_ON=	-DWITH_SSL=system
OPENSSL_USES=	ssl
TOKUDB_DESC=	TokuDB Engine (experimental)
TOKUDB_CMAKE_ON=	-DUSE_CTAGS=0
TOKUDB_EXTRA_PATCHES=${PATCHDIR}/extrapatch-tokudb

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
		-DWITH_LIBWRAP=1

SHEBANG_FILES=	scripts/*.pl* scripts/*.sh

.ifdef USE_MYSQL
.error You have `USE_MYSQL' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

.ifdef CLIENT_ONLY
# Client part
USES+=		libedit
.elifdef PLUGIN_ONLY
# For building plugins (percona-pam-for-mysql, etc)
# Currently do nothing special
USES+=		libedit
.else
# MySQL-Server part
USES+=mysql:56p

CONFLICTS_INSTALL=	mysql*-server-* \
			mysqlwsrep* \
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
.endif

post-patch:
	@${REINPLACE_CMD} 's/*.1/${MANPAGES}/' ${WRKSRC}/man/CMakeLists.txt

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTOKUDB}
NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	TokuDB not supported on 32-bit platforms, see \
			https://github.com/percona/PerconaFT/blob/master/README.md
.endif

.include <bsd.port.post.mk>
