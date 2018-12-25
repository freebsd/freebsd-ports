# Created by: Philip Stoev <philip.stoev@galeracluster.com>
# $FreeBSD$

PORTNAME=	mysqlwsrep
PORTVERSION?=	5.6.42
DISTVERSIONPREFIX?=	wsrep_
DISTVERSIONSUFFIX?=	-25.24
CATEGORIES=	databases ipv6
PKGNAMESUFFIX=	56-server

MAINTAINER=	devel@galeracluster.com
COMMENT=	MySQL database enhanced with Galera replication (server package)

LICENSE=	GPLv2

NOT_FOR_ARCHS=		aarch64 armv6 armv7 powerpc64
NOT_FOR_ARCHS_REASON=	error: Unsupported platform

RUN_DEPENDS=	bash:shells/bash \
		lsof:sysutils/lsof \
		netcat:net/netcat \
		rsync:net/rsync \
		socat:net/socat
LIB_DEPENDS=	libevent.so:devel/libevent liblz4.so:archivers/liblz4

BROKEN_SSL=	openssl111
BROKEN_SSL_REASON_openssl111=	incomplete definition of type 'struct dh_st'

DATADIR=	${PREFIX}/share/mysql
ETCDIR=		${PREFIX}/etc/mysql

USES=		bison \
		cmake:noninja \
		compiler:c++11-lib \
		compiler:c11 \
		libedit \
		perl5 \
		shebangfix \
		ssl

USE_PERL5=	run
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_TUPLE?=	codership:mysql-wsrep:${DISTVERSIONPREFIX}${PORTVERSION}${DISTVERSIONSUFFIX} \
		codership:wsrep-API:eab2d5d5a31672c0b7d116ef1629ff18392fd7d0:dummy/wsrep/src

MY_DBDIR=	/var/db/mysql
MY_SECDIR=	/var/db/mysql_secure
MY_TMPDIR=	/var/db/mysql_tmpdir

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
		-DINSTALL_SQLBENCHDIR="share/mysql" \
		-DINSTALL_SUPPORTFILESDIR="share/mysql" \
		-DMYSQL_KEYRINGDIR="${ETCDIR}/keyring" \
		-DWITH_EDITLINE=system \
		-DWITH_LIBEVENT=system \
		-DWITH_LZ4=system \
		-DWITH_ZLIB=system \
		-DWITH_SSL=${OPENSSLBASE} \
		-DCRYPTO_LIBRARY=${OPENSSLLIB}/libcrypto.so \
		-DOPENSSL_LIBRARY=${OPENSSLLIB}/libssl.so \
		-DINSTALL_MYSQLTESTDIR=0 \
		-DWITH_LIBWRAP=1 \
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
			mysqlwsrep57*-server-* \
			mysqlwsrep[1-489]*-server-* \
			percona*-server-*

USE_RC_SUBR=	mysql-server

SUB_FILES=	my.cnf.sample

USERS=		mysql
GROUPS=		mysql

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

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200057
SUB_LIST+=	LEGACY_LIMITS="@comment " MODERN_LIMITS=""
.else
SUB_LIST+=	LEGACY_LIMITS="" MODERN_LIMITS="@comment "
.endif

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} 's/*.1/${MMAN1}/' ${WRKSRC}/man/CMakeLists.txt

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/my.cnf.sample ${STAGEDIR}${ETCDIR}/my.cnf.sample
	${MKDIR} ${STAGEDIR}${ETCDIR}/keyring
	${MKDIR} ${STAGEDIR}${MY_SECDIR}
	${MKDIR} ${STAGEDIR}${MY_TMPDIR}

.if ${ARCH} == armv6 || ${ARCH} == armv7
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-config.h.cmake
.endif

.include <bsd.port.post.mk>
