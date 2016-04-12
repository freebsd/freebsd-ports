# Created by: "Mahdi Mokhtari <mokhi64@gmail.com>"
# $FreeBSD$

PORTNAME=	mysql
PORTVERSION=	5.7.10
PORTREVISION?=	4
CATEGORIES=	databases ipv6
MASTER_SITES=	MYSQL/MySQL-5.7:MySQL SF/boost/boost/1.59.0:boost
PKGNAMESUFFIX?=	57-server
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:MySQL boost_1_59_0.tar.gz:boost

MAINTAINER=	mokhi64@gmail.com
COMMENT=	Multithreaded SQL database (server)

LICENSE=	GPLv2

SLAVEDIRS=	databases/mysql57-client
USES=		cmake:outsource shebangfix

OPTIONS_RADIO=		SSL
OPTIONS_RADIO_SSL=	BUNDLED_SSL OPENSSL WITHOUT_SSL
OPTIONS_DEFAULT+=	OPENSSL
NO_OPTIONS_SORT=	yes

BUNDLED_SSL_DESC=	SSL/TLS support via (bundled) CyaSSL
WITHOUT_SSL_DESC=	No SSL/TLS support

CMAKE_ARGS+=	-DINSTALL_DOCDIR="share/doc/mysql" \
		-DINSTALL_DOCREADMEDIR="share/doc/mysql" \
		-DINSTALL_INCLUDEDIR="include/mysql" \
		-DINSTALL_INFODIR="info" \
		-DINSTALL_LIBDIR="lib/mysql" \
		-DINSTALL_PKGCONFIGDIR=${PREFIX}/libdata/pkgconfig \
		-DINSTALL_MANDIR="man" \
		-DINSTALL_MYSQLDATADIR="/var/db/mysql" \
		-DINSTALL_MYSQLSHAREDIR="share/mysql" \
		-DINSTALL_MYSQLTESTDIR="share/mysql/tests" \
		-DINSTALL_PLUGINDIR="lib/mysql/plugin" \
		-DINSTALL_SBINDIR="libexec" \
		-DINSTALL_SCRIPTDIR="bin" \
		-DINSTALL_SHAREDIR="share" \
		-DINSTALL_SUPPORTFILESDIR="share/mysql" \
		-DLOCAL_BOOST_DIR=${WRKDIR}/boost_1_59_0 \
		-DBOOST_INCLUDE_DIR=${WRKDIR}/boost_1_59_0 \
		-DWITH_INNODB_EXTRA_DEBUG=0

SHEBANG_FILES=	scripts/*.pl* scripts/*.sh

.ifdef USE_MYSQL
.error You have `USE_MYSQL' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

BUNDLED_SSL_CMAKE_ON=	-DWITH_SSL=bundled
OPENSSL_USE=		OPENSSL=yes
WITHOUT_SSL_CMAKE_ON=	-DWITH_SSL=no

# MySQL-Server part
.if !defined(CLIENT_ONLY)
USE_MYSQL=	yes
WANT_MYSQL_VER=	57

USES+=		bison:build cpe perl5
USE_PERL5=	run

CONFLICTS_INSTALL=	mariadb[0-9]*-server-* \
			mysql[0-46-9][0-689]-server-* \
			percona[0-9]*-server-*

USE_RC_SUBR=	mysql-server

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

PERFSCHM_SUB_LIST+=	PERFSCHEMRC=""
PERFSCHM_SUB_LIST_OFF+=	PERFSCHEMRC="--skip-performance-schema"

.else
USES+=		readline
.endif

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
CC=	clang
CXX=	clang++
CPP=	clang-cpp
OPENSSL_CMAKE_ON=	-DWITH_SSL=system
.elif ${OSVERSION} >= 1000000
OPENSSL_CMAKE_ON=	-DWITH_SSL=yes
.endif

post-extract:
	@${RM} -rvf ${WRKSRC}/sql/sql_hints.yy.cc ${WRKSRC}/sql/sql_hints.yy.h

post-patch:
	@${REINPLACE_CMD} 's/*.1/${MMAN1}/' ${WRKSRC}/man/CMakeLists.txt

.include <bsd.port.post.mk>
