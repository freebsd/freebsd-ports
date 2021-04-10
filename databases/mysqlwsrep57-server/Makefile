# Created by: Vasil Dimov <vd@FreeBSD.org>

PORTNAME=	mysqlwsrep
PORTVERSION?=	5.7.33
DISTVERSIONPREFIX?=	wsrep_
DISTVERSIONSUFFIX?=	-25.25
PORTREVISION?=	1
CATEGORIES=	databases
MASTER_SITES+=	SF/boost/boost/1.59.0:boost
PKGNAMESUFFIX=	57-server
DISTFILES+=	boost_1_59_0${EXTRACT_SUFX}:boost

MAINTAINER=	devel@galeracluster.com
COMMENT=	MySQL database enhanced with Galera replication (server package)

LICENSE=	GPLv2

RUN_DEPENDS=	bash:shells/bash \
		rsync:net/rsync \
		socat:net/socat
LIB_DEPENDS=	libevent.so:devel/libevent liblz4.so:archivers/liblz4

USES=		bison \
		cmake:noninja \
		compiler:c++11-lib \
		compiler:c11 \
		libedit \
		mysql:57 \
		perl5 \
		shebangfix \
		ssl

USE_PERL5=	run

MY_DBDIR=	/var/db/mysql
MY_SECDIR=	/var/db/mysql_secure
MY_TMPDIR=	/var/db/mysql_tmpdir

USE_GITHUB=	yes
GH_TUPLE?=	codership:mysql-wsrep:${DISTVERSIONPREFIX}${PORTVERSION}${DISTVERSIONSUFFIX} \
		codership:wsrep-API:eab2d5d5a31672c0b7d116ef1629ff18392fd7d0:dummy/wsrep/src

DATADIR=	${PREFIX}/share/mysql
ETCDIR=		${PREFIX}/etc/mysql

CMAKE_ARGS+=	-DINSTALL_LAYOUT=FREEBSD \
		-DINSTALL_PKGCONFIGDIR="${LOCALBASE}/libdata/pkgconfig" \
		-DINSTALL_DOCDIR="share/doc/mysql" \
		-DINSTALL_DOCREADMEDIR="share/doc/mysql" \
		-DINSTALL_INCLUDEDIR="include/mysql" \
		-DINSTALL_INFODIR="info" \
		-DINSTALL_LDCONFIGDIR="${LOCALBASE}/libdata/ldconfig" \
		-DINSTALL_LIBDIR="lib/mysql" \
		-DINSTALL_MANDIR="man" \
		-DINSTALL_MYSQLDATADIR="${MY_DBDIR}" \
		-DINSTALL_MYSQLKEYRINGDIR="etc/mysql/keyring" \
		-DINSTALL_MYSQLSHAREDIR="share/mysql" \
		-DINSTALL_PLUGINDIR="lib/mysql/plugin" \
		-DINSTALL_SBINDIR="libexec" \
		-DINSTALL_SCRIPTDIR="bin" \
		-DINSTALL_SECURE_FILE_PRIVDIR="${MY_SECDIR}" \
		-DINSTALL_SHAREDIR="share" \
		-DINSTALL_SUPPORTFILESDIR="share/mysql" \
		-DMYSQL_KEYRINGDIR="${ETCDIR}/keyring" \
		-DWITH_BOOST="${WRKDIR}/boost_1_59_0" \
		-DWITH_EDITLINE=system \
		-DWITH_LIBEVENT=system \
		-DWITH_LZ4=system \
		-DWITH_ZLIB=system \
		-DINSTALL_MYSQLTESTDIR=0 \
		-DDOWNLOAD_BOOST=1 \
		-DWITH_WSREP=1

SHEBANG_FILES=	scripts/*.pl* scripts/*.sh scripts/wsrep_sst_*

.ifdef USE_MYSQL
.error You have USE_MYSQL variable defined either in environment or in make(1) arguments. Please undefine it and try again.
.endif

SUB_LIST=	MY_DBDIR=${MY_DBDIR} \
		MY_SECDIR=${MY_SECDIR} \
		MY_TMPDIR=${MY_TMPDIR}

PLIST_SUB=	MY_DBDIR=${MY_DBDIR} \
		MY_SECDIR=${MY_SECDIR} \
		MY_TMPDIR=${MY_TMPDIR}

CONFLICTS_INSTALL=	mariadb*-server-* \
			mysql[0-9]*-server-* \
			mysqlwsrep56*-server-* \
			mysqlwsrep[1-489]*-server-* \
			percona*-server-*

USE_RC_SUBR=	mysql-server

SUB_FILES=	my.cnf.sample

USERS=		mysql
GROUPS=		mysql

USE_CXXSTD=	c++11
USE_LDCONFIG+=	${PREFIX}/lib/mysql/plugin

MMAN1=		my_print_defaults.1 \
		myisam_ftdump.1 \
		myisamchk.1 \
		myisamlog.1 \
		myisampack.1 \
		mysql.server.1 \
		mysql_convert_table_format.1 \
		mysql_fix_extensions.1 \
		mysql_install_db.1 \
		mysql_plugin.1 \
		mysql_secure_installation.1 \
		mysql_setpermission.1 \
		mysql_tzinfo_to_sql.1 \
		mysql_upgrade.1 \
		mysql_zap.1 \
		mysqlbug.1 \
		mysqld_multi.1 \
		mysqld_safe.1 \
		mysqldumpslow.1 \
		mysqlhotcopy.1 \
		mysqlman.1 \
		perror.1 \
		replace.1 \
		resolve_stack_dump.1 \
		resolveip.1

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
FEDERATED_SUB_LIST+=	FEDER="--federated"
FEDERATED_SUB_LIST_OFF+=FEDER=""

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPERFSCHM}
SUB_LIST+=	PERFSCHEMRC=""
.else
SUB_LIST+=	PERFSCHEMRC="--skip-performance-schema"
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200057
SUB_LIST+=	LEGACY_LIMITS="@comment " MODERN_LIMITS=""
.else
SUB_LIST+=	LEGACY_LIMITS="" MODERN_LIMITS="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
CMAKE_ARGS+=		-DWITH_SSL=system
.else
CMAKE_ARGS+=		-DWITH_SSL=${OPENSSLBASE}
.endif

# ${LOCALBASE}/include/lz4.h does not compile with Clang 6.
# Also MySQL code itself needs -Wno-c++11-narrowing when Clang 6 is used.
.if ${OSVERSION} >= 1200056
CFLAGS+=	-DLZ4_DISABLE_DEPRECATE_WARNINGS
CXXFLAGS+=	-DLZ4_DISABLE_DEPRECATE_WARNINGS
LDFLAGS+=	-L${LOCALBASE}/lib
.  if ${CHOSEN_COMPILER_TYPE} == clang
CXXFLAGS+=	-Wno-c++11-narrowing
.  endif
.endif

# Plugin innodb_memcached requires -fcommon to avoid duplicate symbol linker
# error with llmv11.
.if (${OPSYS} == FreeBSD && ${OSVERSION} >= 1300109) || ${CHOSEN_COMPILER_TYPE} == gcc
CFLAGS+=	-fcommon
.endif

post-extract:
	${RM} -fv ${WRKSRC}/sql/sql_hints.yy.cc ${WRKSRC}/sql/sql_hints.yy.h

post-patch:
	${REINPLACE_CMD} 's/*.1/${MMAN1}/' ${WRKSRC}/man/CMakeLists.txt

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/my.cnf.sample ${STAGEDIR}${ETCDIR}/my.cnf.sample
	${MKDIR} ${STAGEDIR}${ETCDIR}/keyring
	${MKDIR} ${STAGEDIR}${MY_SECDIR}
	${MKDIR} ${STAGEDIR}${MY_TMPDIR}

.include <bsd.port.post.mk>
