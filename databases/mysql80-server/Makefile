# Created by: Mahdi Mokhtari <mokhi64@gmail.com>
# $FreeBSD$

PORTNAME?=		mysql
PORTVERSION=		8.0.18
PORTREVISION?=		0
CATEGORIES=		databases
MASTER_SITES=		MYSQL/MySQL-8.0
PKGNAMESUFFIX?=		80-server
DISTNAME=		${PORTNAME}-boost-${PORTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=		mmokhi@FreeBSD.org
COMMENT?=		Multithreaded SQL database (server)

LICENSE=		GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}${DISTVERSIONSUFFIX}

SLAVEDIRS=	databases/mysql80-client
USES=		bison:build cmake:noninja compiler:c++14-lang cpe \
		libedit localbase ncurses perl5 pkgconfig shebangfix ssl

USE_PERL5=	run

MY_DBDIR=	/var/db/mysql
MY_SECDIR=	/var/db/mysql_secure
MY_TMPDIR=	/var/db/mysql_tmpdir

LIB_DEPENDS+=	libcurl.so:ftp/curl \
		libevent.so:devel/libevent \
		libicutu.so:devel/icu \
		liblz4.so:archivers/liblz4 \
		libzstd.so:archivers/zstd \
		libprotobuf.so:devel/protobuf \
		libunwind.so:devel/libunwind

BUILD_DEPENDS=	liblz4>0:archivers/liblz4 \
		libunwind>0:devel/libunwind

CMAKE_BUILD_TYPE=	Release
CFLAGS+=		-fPIC

CMAKE_ARGS+=	-DINSTALL_LAYOUT=FREEBSD \
		-DINSTALL_LDCONFIGDIR="${LOCALBASE}/libdata/ldconfig" \
		-DINSTALL_PKGCONFIGDIR="${LOCALBASE}/libdata/pkgconfig" \
		-DINSTALL_DOCDIR="share/doc/mysql" \
		-DINSTALL_DOCREADMEDIR="share/doc/mysql" \
		-DINSTALL_INCLUDEDIR="include/mysql" \
		-DINSTALL_INFODIR="${INFO_PATH}" \
		-DINSTALL_LIBDIR="lib/mysql" \
		-DINSTALL_MANDIR="man" \
		-DINSTALL_MYSQLDATADIR="${MY_DBDIR}" \
		-DINSTALL_MYSQLKEYRINGDIR="etc/mysql/keyring" \
		-DINSTALL_MYSQLSHAREDIR="share/mysql" \
		-DINSTALL_MYSQLTESTDIR="" \
		-DINSTALL_PLUGINDIR="lib/mysql/plugin" \
		-DINSTALL_SBINDIR="libexec" \
		-DINSTALL_SCRIPTDIR="bin" \
		-DINSTALL_SECURE_FILE_PRIVDIR="${MY_SECDIR}" \
		-DINSTALL_SHAREDIR="share" \
		-DINSTALL_SUPPORTFILESDIR="share/mysql" \
		-DMYSQL_KEYRINGDIR="${ETCDIR}/keyring" \
		-DWITH_BOOST="${WRKSRC}/boost" \
		-DWITH_SYSTEM_LIBS=1 \
		-DWITH_EDITLINE=system \
		-DWITH_LIBEVENT=system \
		-DWITH_LZ4=system \
		-DWITH_ICU=system \
		-DWITH_CURL=system \
		-DWITH_ZLIB=system \
		-DWITH_ZSTD=system \
		-DWITH_PROTOBUF=system \
		-DWITH_SSL=${OPENSSLBASE} \
		-DBUILD_BUNDLED_ZLIB=0 \
		-DBUILD_BUNDLED_LZ4=0 \

SHEBANG_FILES=	scripts/*.pl* scripts/*.sh

.ifdef USE_MYSQL
.error You have `USE_MYSQL' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

SUB_LIST=	MY_DBDIR=${MY_DBDIR} \
		MY_SECDIR=${MY_SECDIR} \
		MY_TMPDIR=${MY_TMPDIR}

PLIST_SUB=	MY_DBDIR=${MY_DBDIR} \
		MY_SECDIR=${MY_SECDIR} \
		MY_TMPDIR=${MY_TMPDIR} \
		MYSQL80_LIBVER=${MYSQL80_LIBVER}

# MySQL-Server part
.if !defined(CLIENT_ONLY)
USES+=		mysql:80

CONFLICTS_INSTALL=	mysql8[1-9]-server-* \
			mysql[0-79][0-9]-server-* \
			mysqlwsrep* \
			mariadb[0-9][0-9]-server-* \
			percona[0-9][0-9]-server-*

USE_RC_SUBR=	mysql-server

SUB_FILES=	my.cnf.sample

USERS=		mysql
GROUPS=		mysql

USE_LDCONFIG+=	${PREFIX}/lib/mysql/plugin

MMAN1=		ibd2sdi.1 innochecksum.1 my_print_defaults.1 myisam_ftdump.1 myisamchk.1 \
		myisamlog.1 myisampack.1 mysql_secure_installation.1 mysql_ssl_rsa_setup.1 \
		mysql_tzinfo_to_sql.1 mysql_upgrade.1 mysql.server.1 mysqldumpslow.1 mysqld_multi.1 \
		mysqld_safe.1 mysqlrouter_passwd.1 mysqlrouter_plugin_info.1 mysqlrouter.1
MMAN8=		mysqld.8

CMAKE_ARGS+=	-DWITH_EMBEDDED_SERVER="ON"
CMAKE_ARGS+=	-DWITHOUT_CLIENTLIBS="ON"

OPTIONS_GROUP=		STORAGE
OPTIONS_GROUP_STORAGE=	ARCHIVE BLACKHOLE EXAMPLE FEDERATED INNOBASE PARTITION PERFSCHEMA
OPTIONS_SUB=		YES
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
OPTIONS_GROUP_FEATURES=	PERFSCHM
FEATURES_DESC=		Default features knobs
PERFSCHM_DESC=		Enable "Performance Schema" by default (High RAM usage)
OPTIONS_DEFAULT+=	PERFSCHM

PERFSCHM_SUB_LIST+=		PERFSCHEMRC=""
PERFSCHM_SUB_LIST_OFF+=		PERFSCHEMRC="--skip-performance-schema"
FEDERATED_SUB_LIST+=		FEDER="--federated"
FEDERATED_SUB_LIST_OFF+=	FEDER=""
.endif

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200057
SUB_LIST+=	LEGACY_LIMITS="@comment " MODERN_LIMITS=""
.else
SUB_LIST+=	LEGACY_LIMITS="" MODERN_LIMITS="@comment "
.endif

.include <bsd.port.pre.mk>

post-extract:
	@${RM} -rv ${WRKSRC}/sql/sql_hints.yy.cc ${WRKSRC}/sql/sql_hints.yy.h

.if !defined(CLIENT_ONLY)
post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/my.cnf.sample ${STAGEDIR}${ETCDIR}/my.cnf.sample
	${MKDIR} ${STAGEDIR}${ETCDIR}/keyring
	${MKDIR} ${STAGEDIR}${MY_SECDIR}
	${MKDIR} ${STAGEDIR}${MY_TMPDIR}
.endif

.include <bsd.port.post.mk>
