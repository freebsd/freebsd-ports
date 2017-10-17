# Created by: Mahdi Mokhtari <mokhi64@gmail.com>
# $FreeBSD$

PORTNAME?=	mysql
PORTVERSION=	5.7.19
PORTREVISION=	2
CATEGORIES=	databases ipv6
MASTER_SITES=	MYSQL/MySQL-5.7
PKGNAMESUFFIX?=	57-server
DISTNAME=	${PORTNAME}-boost-${PORTVERSION}

MAINTAINER=	mmokhi@FreeBSD.org
COMMENT?=	Multithreaded SQL database (server)

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

SLAVEDIRS=	databases/mysql57-client
USES=		bison:build cmake:outsource,noninja compiler:c11 compiler:c++11-lib \
		cpe libedit localbase perl5 shebangfix ssl

USE_PERL5=	run

MY_DBDIR=	/var/db/mysql
MY_SECDIR=	/var/db/mysql_secure
MY_TMPDIR=	/var/db/mysql_tmpdir

LIB_DEPENDS+=	libevent.so:devel/libevent \
		liblz4.so:archivers/liblz4

CMAKE_BUILD_TYPE=	Release

CMAKE_ARGS+=	-DINSTALL_LAYOUT=FREEBSD \
		-DINSTALL_LDCONFIGDIR="${LOCALBASE}/libdata/ldconfig" \
		-DINSTALL_PKGCONFIGDIR="${LOCALBASE}/libdata/pkgconfig" \
		-DINSTALL_DOCDIR="share/doc/mysql" \
		-DINSTALL_DOCREADMEDIR="share/doc/mysql" \
		-DINSTALL_INCLUDEDIR="include/mysql" \
		-DINSTALL_INFODIR="info" \
		-DINSTALL_LIBDIR="lib/mysql" \
		-DINSTALL_MANDIR="man" \
		-DINSTALL_MYSQLDATADIR="${MY_DBDIR}" \
		-DINSTALL_MYSQLKEYRINGDIR="etc/mysql/keyring" \
		-DINSTALL_MYSQLSHAREDIR="share/mysql" \
		-DINSTALL_MYSQLTESTDIR="share/mysql/tests" \
		-DINSTALL_PLUGINDIR="lib/mysql/plugin" \
		-DINSTALL_SBINDIR="libexec" \
		-DINSTALL_SCRIPTDIR="bin" \
		-DINSTALL_SECURE_FILE_PRIVDIR="${MY_SECDIR}" \
		-DINSTALL_SHAREDIR="share" \
		-DINSTALL_SUPPORTFILESDIR="share/mysql" \
		-DMYSQL_KEYRINGDIR="${ETCDIR}/keyring" \
		-DWITH_BOOST="${WRKSRC}/boost" \
		-DWITH_EDITLINE=system \
		-DWITH_LIBEVENT=system \
		-DWITH_LZ4=system \
		-DWITH_ZLIB=system \
		-DINSTALL_MYSQLTESTDIR=0 \
		-DWITH_DEBUG=0

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

OPTIONS_SUB=		YES

# MySQL-Server part
.if !defined(CLIENT_ONLY)
USES+=		mysql:57

CONFLICTS_INSTALL=	mysql5[0-68-9]-server-* \
			mysql[0-46-9][0-9]-server-* \
			mysqlwsrep* \
			mariadb[0-9][0-9]-server-* \
			percona[0-9][0-9]-server-*

USE_RC_SUBR=	mysql-server

SUB_FILES=	my.cnf.sample

USERS=		mysql
GROUPS=		mysql

USE_LDCONFIG+=	${PREFIX}/lib/mysql/plugin

MMAN1=		my_print_defaults.1 myisam_ftdump.1 myisamchk.1 myisamlog.1 myisampack.1 \
		mysql.server.1 mysql_convert_table_format.1 mysql_fix_extensions.1 \
		mysql_install_db.1 mysql_plugin.1 mysql_secure_installation.1 mysql_setpermission.1 \
		mysql_tzinfo_to_sql.1 mysql_upgrade.1 mysql_zap.1 mysqlbug.1 \
		mysqld_multi.1 mysqld_safe.1 mysqldumpslow.1 mysqlhotcopy.1 mysqlman.1 \
		mysqltest.1 perror.1 replace.1 resolve_stack_dump.1 resolveip.1

CMAKE_ARGS+=	-DWITH_EMBEDDED_SERVER="ON"

OPTIONS_GROUP+=		STORAGE
OPTIONS_GROUP_STORAGE=	ARCHIVE BLACKHOLE EXAMPLE FEDERATED INNOBASE PARTITION PERFSCHEMA
STORAGE_DESC=		Permissible "Storage Engines" (to compile statically into the server)
ARCHIVE_DESC=		Compile "Archive Storage" statically in server
BLACKHOLE_DESC=		Compile "Blackhole Storage" statically in server
EXAMPLE_DESC=		Compile "Example Storage" statically in server
FEDERATED_DESC=		Compile "Federated Storage" statically in server
INNOBASE_DESC=		Compile "InnoDB Storage" statically in server
PARTITION_DESC=		Compile "Partitioning support Storage" statically in server
PERFSCHEMA_DESC=	Compile "Performance Schema Storage" statically in server

ARCHIVE_CMAKE_ON=	-DWITH_ARCHIVE_STORAGE_ENGINE=1
BLACKHOLE_CMAKE_ON=	-DWITH_BLACKHOLE_STORAGE_ENGINE=1
EXAMPLE_CMAKE_ON=	-DWITH_EXAMPLE_STORAGE_ENGINE=1
FEDERATED_CMAKE_ON=	-DWITH_FEDERATED_STORAGE_ENGINE=1
INNOBASE_CMAKE_ON=	-DWITH_INNOBASE_STORAGE_ENGINE=1
PARTITION_CMAKE_ON=	-DWITH_PARTITION_STORAGE_ENGINE=1
PERFSCHEMA_CMAKE_ON=	-DWITH_PERFSCHEMA_STORAGE_ENGINE=1

OPTIONS_GROUP+=		FEATURES
FEATURES_DESC=		Default features knobs
OPTIONS_GROUP_FEATURES=	PERFSCHM
PERFSCHM_DESC=		Enable "Performance Schema" by default (High RAM usage)
OPTIONS_DEFAULT+=	PERFSCHM

PERFSCHM_SUB_LIST+=		PERFSCHEMRC=""
PERFSCHM_SUB_LIST_OFF+=		PERFSCHEMRC="--skip-performance-schema"
FEDERATED_SUB_LIST+=		FEDER="--federated"
FEDERATED_SUB_LIST_OFF+=	FEDER=""

# issue 220865: Currently there's no source to be built with server-side support.
# 		But this keeps the pkg-plist not overlaping
CMAKE_ARGS+=	-DWITH_AUTHENTICATION_LDAP=0
.endif

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
CMAKE_ARGS+=		-DWITH_SSL=system
.else
CMAKE_ARGS+=		-DWITH_SSL=${OPENSSLBASE}
.endif

post-extract:
	@${RM} -rv ${WRKSRC}/sql/sql_hints.yy.cc ${WRKSRC}/sql/sql_hints.yy.h

post-patch:
	@${REINPLACE_CMD} 's/*.1/${MMAN1}/' ${WRKSRC}/man/CMakeLists.txt
	# issue 220865: MySQL developers forgot that FreeBSD != Linux
	@${REINPLACE_CMD} -e 's|%%FREEBSD_LOCAL_LIB%%|${LOCALBASE}/lib|g' \
	    ${WRKSRC}/cmake/plugin.cmake

.if !defined(CLIENT_ONLY)
post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/my.cnf.sample ${STAGEDIR}${ETCDIR}/my.cnf.sample
	${MKDIR} ${STAGEDIR}${ETCDIR}/keyring
	${MKDIR} ${STAGEDIR}${MY_SECDIR}
	${MKDIR} ${STAGEDIR}${MY_TMPDIR}
.endif

.include <bsd.port.post.mk>
