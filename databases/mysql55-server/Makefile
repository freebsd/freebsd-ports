# New ports collection makefile for:	MySQL-server
# Date created:				28 Jan 2006
# Whom:					Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	mysql
PORTVERSION=	5.5.16
PORTREVISION?=	0
CATEGORIES=	databases ipv6
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	MySQL-5.5
PKGNAMESUFFIX?=	-server

MAINTAINER=	ale@FreeBSD.org
COMMENT?=	Multithreaded SQL database (server)

SLAVEDIRS=	databases/mysql55-client
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS=	OPENSSL "Enable SSL support" on \
		FASTMTX "Replace mutexes with spinlocks" off

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
		-DWITH_LIBWRAP=1

.ifdef USE_MYSQL
.error You have `USE_MYSQL' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

.include <bsd.port.options.mk>

.if !defined(WITHOUT_OPENSSL)
CMAKE_ARGS+=	-DWITH_SSL=bundled
.endif
.if defined(WITH_FASTMTX)
CMAKE_ARGS+=	-DWITH_FAST_MUTEXES=1
.endif

# MySQL-Server part
.if !defined(CLIENT_ONLY)
USE_MYSQL=	yes
WANT_MYSQL_VER=	55

LATEST_LINK=	mysql55-server

CONFLICTS_INSTALL=	mysql-server-[34].* mysql-server-5.[0-46-9].*

USE_RC_SUBR=	mysql-server.sh

USERS=		mysql
GROUPS=		mysql

INFO=		mysql

MAN1=		my_print_defaults.1 myisam_ftdump.1 myisamchk.1 myisamlog.1 myisampack.1 \
		mysql.server.1 mysql_convert_table_format.1 mysql_fix_extensions.1 \
		mysql_install_db.1 mysql_secure_installation.1 mysql_setpermission.1 \
		mysql_tzinfo_to_sql.1 mysql_upgrade.1 mysql_zap.1 mysqlbug.1 \
		mysqld_multi.1 mysqld_safe.1 mysqldumpslow.1 mysqlhotcopy.1 mysqlman.1 \
		mysqltest.1 perror.1 replace.1 resolve_stack_dump.1 resolveip.1

MAN8=		mysqld.8

CMAKE_ARGS+=	-DWITH_EMBEDDED_SERVER="ON"

post-install:
.if !defined(PACKAGE_BUILDING)
	@${CAT} ${PKGMESSAGE}
.endif
.endif

post-patch:
	@${REINPLACE_CMD} 's/*.1/${MAN1}/' ${WRKSRC}/man/CMakeLists.txt

.include <bsd.port.mk>
