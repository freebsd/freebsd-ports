# New ports collection makefile for:	MySQL-server
# Date created:				Fri Apr 11 10:06:26 CET 2003
# Whom:					Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME?=	mysql
PORTVERSION=	4.1.25
PORTREVISION?=	0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ale
PKGNAMESUFFIX?=	-server

MAINTAINER=	ale@FreeBSD.org
COMMENT?=	Multithreaded SQL database (server)

SLAVEDIRS=	databases/mysql41-client
USE_AUTOTOOLS=	libtool:22
MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS=	--localstatedir=/var/db/mysql \
		--without-debug \
		--without-readline \
		--without-libedit \
		--without-bench \
		--without-extra-tools \
		--with-libwrap \
		--with-mysqlfs \
		--with-vio \
		--with-low-memory \
		--with-comment='FreeBSD port: ${PKGNAME}' \
		--enable-thread-safe-client

.ifdef USE_MYSQL
.error You have `USE_MYSQL' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

.if defined(WITH_CHARSET) && ${WITH_CHARSET} != ""
CONFIGURE_ARGS+=--with-charset=${WITH_CHARSET}
.endif
.if defined(WITH_XCHARSET) && ${WITH_XCHARSET} != ""
CONFIGURE_ARGS+=--with-extra-charsets=${WITH_XCHARSET}
.endif
.if defined(WITH_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-openssl=${OPENSSLBASE}
.endif
.if defined(BUILD_STATIC)
CONFIGURE_ARGS+=--with-mysqld-ldflags=-all-static
.endif
.if defined(WITHOUT_INNODB)
CONFIGURE_ARGS+=--without-innodb
.endif
.if defined(WITH_NDB)
CONFIGURE_ARGS+=--with-ndbcluster
.endif
.if defined(WITH_COLLATION) && ${WITH_COLLATION} != ""
CONFIGURE_ARGS+=--with-collation=${WITH_COLLATION}
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=--enable-assembler --with-berkeley-db
.endif
.if defined(WITH_LINUXTHREADS)
CONFIGURE_ARGS+=--with-named-thread-libs='-DHAVE_GLIBC2_STYLE_GETHOSTBYNAME_R
CONFIGURE_ARGS+=-D_THREAD_SAFE -I${LOCALBASE}/include/pthread/linuxthreads
CFLAGS+=	-D__USE_UNIX98 -D_REENTRANT -D_THREAD_SAFE
CFLAGS+=	-I${LOCALBASE}/include/pthread/linuxthreads
LIB_DEPENDS+=	lthread:${PORTSDIR}/devel/linuxthreads
CONFIGURE_ARGS+=-L${LOCALBASE}/lib -llthread -llgcc_r -llstdc++ -llsupc++'
.else
CONFIGURE_ARGS+=--with-named-thread-libs=${PTHREAD_LIBS}
CFLAGS+=	${PTHREAD_CFLAGS}
.endif

.if defined(BUILD_OPTIMIZED)
CFLAGS+=	-O3 -fno-omit-frame-pointer
CFLAGS+=	-fno-gcse
.endif
CXXFLAGS+=	${CFLAGS} -felide-constructors -fno-rtti
CXXFLAGS+=	-fno-exceptions

# MySQL-Server part
.if !defined(CLIENT_ONLY) && !defined(SCRIPTS_ONLY)
USE_MYSQL=	yes
WANT_MYSQL_VER=	41

LATEST_LINK=	mysql41-server

CONFLICTS=	mysql-server-3.* mysql-server-4.[02-9].* mysql-server-5.* mysql-server-6.*

USE_RC_SUBR=	mysql-server.sh

USE_BISON=	build

.if defined(WITH_NDB)
PLIST_SUB+=	NDB=""
.else
PLIST_SUB+=	NDB="@comment "
.endif

MAN1=		myisamchk.1 myisamlog.1 myisampack.1 mysqld.1 \
		mysqld_safe.1 mysql.server.1 perror.1 replace.1

MAN8=		mysqld.8

INFO=		mysql

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "	WITH_CHARSET=charset	Define the primary built-in charset (latin1)."
	@${ECHO} "	WITH_XCHARSET=list	Define other built-in charsets (may be 'all')."
	@${ECHO} "	WITH_COLLATION=collate	Define default collation (latin1_swedish_ci)."
	@${ECHO} "	WITH_OPENSSL=yes	Enable secure connections."
	@${ECHO} "	WITH_LINUXTHREADS=yes	Use the linuxthreads pthread library."
	@${ECHO} "	WITH_PROC_SCOPE_PTH=yes	Use process scope threads"
	@${ECHO} "				(try it if you use libpthread)."
	@${ECHO} "	BUILD_OPTIMIZED=yes	Enable compiler optimizations"
	@${ECHO} "				(use it if you need speed)."
	@${ECHO} "	BUILD_STATIC=yes	Build a static version of mysqld."
	@${ECHO} "				(use it if you need even more speed)."
	@${ECHO} "	WITHOUT_INNODB=yes	Disable support for InnoDB table handler."
	@${ECHO} "	WITH_NDB=yes		Enable support for NDB Cluster."
	@${ECHO} ""

post-patch:
	@${REINPLACE_CMD} -e "s|SUBDIRS =|SUBDIRS = include @docs_dirs@ @sql_server_dirs@ scripts @man_dirs@ support-files|g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|all: config.h|all: config.h all-local|g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|bin_SCRIPTS =|bin_SCRIPTS = @server_scripts@ mysql_create_system_tables|g" ${WRKSRC}/scripts/Makefile.in
	@${REINPLACE_CMD} -e "s|dist_pkgdata_DATA =|dist_pkgdata_DATA = fill_help_tables.sql|g" ${WRKSRC}/scripts/Makefile.in
	@${REINPLACE_CMD} -e "s|man1_MANS =|man1_MANS = ${MAN1}|g;s|man8_MANS =|man8_MANS = ${MAN8}|g" ${WRKSRC}/man/Makefile.in
	@${REINPLACE_CMD} -e "s|install-data-am: install-pkgincludeHEADERS|install-data-am:|g" ${WRKSRC}/include/Makefile.in
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/mysys/default.c
.if defined(WITH_PROC_SCOPE_PTH)
	@${REINPLACE_CMD} -e "s|PTHREAD_SCOPE_SYSTEM|PTHREAD_SCOPE_PROCESS|g" ${WRKSRC}/sql/mysqld.cc
.endif

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.else
# MySQL-Client part
.if defined(CLIENT_ONLY)
LATEST_LINK=	mysql41-client

CONFLICTS=	mysql-client-3.* mysql-client-4.[02-9].* mysql-client-5.* mysql-client-6.*

MAN1=		mysql_config.1 mysql.1 mysqladmin.1 mysqlbinlog.1 \
		mysqlcheck.1 mysqldump.1 mysqlimport.1 mysqlshow.1

USE_LDCONFIG=	${PREFIX}/lib/mysql

CONFIGURE_ARGS+=--without-server

post-patch:
	@${REINPLACE_CMD} -e "s|SUBDIRS =|SUBDIRS = include @sql_client_dirs@ scripts @man_dirs@|g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|install-exec-am: install-pkglibLIBRARIES|install-exec-am:|g" ${WRKSRC}/strings/Makefile.in
	@${REINPLACE_CMD} -e "s|all: config.h|all: config.h all-local|g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|bin_SCRIPTS =|bin_SCRIPTS = mysql_config mysql_fix_privilege_tables mysqlbug|g" ${WRKSRC}/scripts/Makefile.in
	@${REINPLACE_CMD} -e "s|dist_pkgdata_DATA =|dist_pkgdata_DATA = mysql_fix_privilege_tables.sql|g" ${WRKSRC}/scripts/Makefile.in
	@${REINPLACE_CMD} -e "s|man1_MANS =|man1_MANS = ${MAN1}|g" ${WRKSRC}/man/Makefile.in
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/mysys/default.c
.if defined(WITH_PROC_SCOPE_PTH)
	@${REINPLACE_CMD} -e "s|PTHREAD_SCOPE_SYSTEM|PTHREAD_SCOPE_PROCESS|g" ${WRKSRC}/tools/mysqlmanager.c
.endif

.else
# MySQL-Scripts part
USE_MYSQL=	yes
WANT_MYSQL_VER=	41

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql41
.if ${PERL_LEVEL} <= 500800
RUN_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
.endif

LATEST_LINK=	mysql41-scripts

CONFLICTS=	mysql-scripts-3.* mysql-scripts-4.[02-9].* mysql-scripts-5.* mysql-scripts-6.*

MAN1=		msql2mysql.1 mysql_zap.1 mysqlaccess.1 mysqlhotcopy.1 \
		mysqld_multi.1 mysql_fix_privilege_tables.1

SCRIPTS=	msql2mysql mysql_fix_extensions mysql_setpermission \
		mysql_secure_installation mysql_zap mysqlaccess \
		mysql_convert_table_format mysql_find_rows mysqlhotcopy \
		mysqldumpslow mysql_explain_log mysql_tableinfo mysqld_multi

post-patch:
	@${REINPLACE_CMD} -e "s|SUBDIRS =|SUBDIRS = scripts @man_dirs@|g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|bin_SCRIPTS =|bin_SCRIPTS = ${SCRIPTS}|g" ${WRKSRC}/scripts/Makefile.in
	@${REINPLACE_CMD} -e "s|install-exec-am install-data-am|install-exec-am|g" ${WRKSRC}/scripts/Makefile.in
	@${REINPLACE_CMD} -e "s|man1_MANS =|man1_MANS = ${MAN1}|g" ${WRKSRC}/man/Makefile.in
.endif
.endif
# Common part
post-extract:
	@${CP} /usr/include/tcpd.h ${WRKSRC}/sql/mytcpd.h

.if defined(WITH_OPENSSL) && defined(BUILD_STATIC)
pre-configure:
	@${ECHO} "You can't use the BUILD_STATIC option when using OpenSSL."
	@${FALSE}
.endif

.include <bsd.port.post.mk>
