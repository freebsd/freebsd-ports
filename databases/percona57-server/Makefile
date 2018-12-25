# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	percona
DISTVERSION=	5.7.21-20
PORTREVISION?=	3
CATEGORIES=	databases ipv6
MASTER_SITES=	http://www.percona.com/downloads/Percona-Server-5.7/Percona-Server-${DISTVERSION}/source/tarball/:percona \
		SF/boost/boost/1.59.0:boost
PKGNAMESUFFIX?=	57-server
DISTNAME=	percona-server-${DISTVERSION}
DISTFILES=	percona-server-${DISTVERSION}${EXTRACT_SUFX}:percona \
		boost_1_59_0${EXTRACT_SUFX}:boost

MAINTAINER=	feld@FreeBSD.org
COMMENT?=	Multithreaded SQL database (server)

LICENSE?=	GPLv2+

LIB_DEPENDS=	libevent.so:devel/libevent \
		liblz4.so:archivers/liblz4

BROKEN_powerpc64=	Does not build

SLAVEDIRS=	databases/percona57-client \
		databases/percona57-pam-for-mysql
USES=		bison:build cmake:insource,noninja compiler:c11 compiler:c++11-lib \
		cpe libedit localbase perl5 shebangfix

MY_DBDIR=	/var/db/mysql
MY_SECDIR=	/var/db/mysql_secure
MY_TMPDIR=	/var/db/mysql_tmpdir

DATADIR=	${LOCALBASE}/share/mysql
DOCSDIR=	${LOCALBASE}/share/doc/mysql

CMAKE_ARGS+=	-DINSTALL_LAYOUT=FREEBSD \
		-DINSTALL_DOCDIR="share/doc/mysql" \
		-DINSTALL_LDCONFIGDIR="${LOCALBASE}/libdata/ldconfig" \
		-DINSTALL_PKGCONFIGDIR="${LOCALBASE}/libdata/pkgconfig" \
		-DINSTALL_DOCREADMEDIR="share/doc/mysql" \
		-DINSTALL_INCLUDEDIR="include/mysql" \
		-DINSTALL_INFODIR="${INFO_PATH}" \
		-DINSTALL_LIBDIR="lib/mysql" \
		-DINSTALL_MANDIR="man" \
		-DINSTALL_MYSQLDATADIR="/var/db/mysql" \
		-DINSTALL_SECURE_FILE_PRIVDIR="${MY_SECDIR}" \
		-DINSTALL_MYSQLSHAREDIR="share/mysql" \
		-DINSTALL_MYSQLTESTDIR="share/mysql/tests" \
		-DINSTALL_PLUGINDIR="lib/mysql/plugin" \
		-DINSTALL_SBINDIR="libexec" \
		-DINSTALL_SCRIPTDIR="bin" \
		-DINSTALL_SHAREDIR="share" \
		-DINSTALL_SQLBENCHDIR="share/mysql" \
		-DINSTALL_SUPPORTFILESDIR="share/mysql" \
		-DWITH_UNIT_TESTS=0 \
		-DWITH_EDITLINE=system \
		-DWITH_LIBWRAP=0 \
		-DWITH_LZ4=system \
		-DWITH_ZLIB=system \
		-DINSTALL_MYSQLTESTDIR=0 \
		-DWITH_BOOST="${WRKDIR}/boost_1_59_0"

SHEBANG_FILES=	scripts/*.pl* scripts/*.sh

.ifdef USE_MYSQL
.error You have `USE_MYSQL' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

SUB_LIST=	MY_DBDIR=${MY_DBDIR} \
		MY_SECDIR=${MY_SECDIR} \
		MY_TMPDIR=${MY_TMPDIR}

PLIST_SUB=	MY_DBDIR=${MY_DBDIR} \
		MY_SECDIR=${MY_SECDIR} \
		MY_TMPDIR=${MY_TMPDIR}

.ifdef CLIENT_ONLY
# Client part
USES+=		libedit
.elifdef PLUGIN_ONLY
# For building plugins (percona-pam-for-mysql, etc)
# Currently do nothing special
USES+=		libedit
.else
LIB_DEPENDS+=	libcurl.so:ftp/curl
# MySQL-Server part
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

USES+=mysql:57p

CONFLICTS_INSTALL=	mysql*-server-* \
			mysqlwsrep* \
			mariadb*-server-* \
			percona5[0-68-9]-server-*

USE_RC_SUBR=	mysql-server

USERS=		mysql
GROUPS=		mysql

INFO=		mysql

USE_LDCONFIG+=	${PREFIX}/lib/mysql/plugin

MANPAGES=	my_print_defaults.1 myisam_ftdump.1 myisamchk.1 myisamlog.1 myisampack.1 \
		mysql.server.1 mysql_convert_table_format.1 mysql_fix_extensions.1 \
		mysql_install_db.1 mysql_plugin.1 mysql_secure_installation.1 mysql_setpermission.1 \
		mysql_tzinfo_to_sql.1 mysql_upgrade.1 mysql_zap.1 mysqlbug.1 \
		mysqld_multi.1 mysqld_safe.1 mysqldumpslow.1 mysqlhotcopy.1 mysqlman.1 \
		mysqltest.1 perror.1 replace.1 resolve_stack_dump.1 resolveip.1

CMAKE_ARGS+=	-DWITH_EMBEDDED_SERVER="ON"
# issue 220865: Currently there's no source to be built with server-side support.
# But this keeps the pkg-plist not overlaping
CMAKE_ARGS+=	-DWITH_AUTHENTICATION_LDAP=0

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200057
SUB_LIST+=	LEGACY_LIMITS="@comment " MODERN_LIMITS=""
.else
SUB_LIST+=	LEGACY_LIMITS="" MODERN_LIMITS="@comment "
.endif

post-install:
	${MKDIR} ${STAGEDIR}/var/db/mysql
	${MKDIR} ${STAGEDIR}${ETCDIR}/keyring
	${MKDIR} ${STAGEDIR}${MY_SECDIR}
	${MKDIR} ${STAGEDIR}${MY_TMPDIR}
.endif

post-patch:
	@${REINPLACE_CMD} 's/*.1/${MANPAGES}/' ${WRKSRC}/man/CMakeLists.txt
	# issue 220865: MySQL developers forgot that FreeBSD != Linux
	@${REINPLACE_CMD} -e 's|%%FREEBSD_LOCAL_LIB%%|${LOCALBASE}/lib|g' \
	${WRKSRC}/configure.cmake

.include <bsd.port.pre.mk>

.if ${ARCH} == "arm"
BROKEN=		Does not compile on arm
.endif

.if ${PORT_OPTIONS:MTOKUDB}
NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	TokuDB not supported on 32-bit platforms, see \
			https://github.com/percona/PerconaFT/blob/master/README.md
.endif

.include <bsd.port.post.mk>
