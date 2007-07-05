# New ports collection makefile for:	MySQL-server
# Date created:				28 Jan 2006
# Whom:					Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	mysql
PORTVERSION=	5.1.20
PORTREVISION?=	0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	MySQL-5.1
PKGNAMESUFFIX?=	-server
DISTNAME=	${PORTNAME}-${PORTVERSION}-beta

MAINTAINER=	ale@FreeBSD.org
COMMENT?=	Multithreaded SQL database (server)

SLAVEDIRS=	databases/mysql51-client databases/mysql51-scripts
USE_AUTOTOOLS=	libtool:15

CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--localstatedir=/var/db/mysql \
		--without-debug \
		--without-readline \
		--without-libedit \
		--with-libwrap \
		--with-mysqlfs \
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
CONFIGURE_ARGS+=--with-ssl=bundled
.endif
.if defined(BUILD_STATIC)
CONFIGURE_ARGS+=--with-mysqld-ldflags=-all-static
.endif
.if defined(WITH_NDB)
CONFIGURE_ARGS+=--with-plugins=max
.else
CONFIGURE_ARGS+=--with-plugins=max-no-ndb
.endif
.if defined(WITH_COLLATION) && ${WITH_COLLATION} != ""
CONFIGURE_ARGS+=--with-collation=${WITH_COLLATION}
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=--enable-assembler
.endif
.if defined(WITH_LINUXTHREADS)
CONFIGURE_ARGS+=--with-named-thread-libs='-DHAVE_GLIBC2_STYLE_GETHOSTBYNAME_R
CONFIGURE_ARGS+=-D_THREAD_SAFE -I${LOCALBASE}/include/pthread/linuxthreads
CFLAGS+=	-D__USE_UNIX98 -D_REENTRANT -D_THREAD_SAFE
CFLAGS+=	-I${LOCALBASE}/include/pthread/linuxthreads
LIB_DEPENDS+=	lthread.[35]:${PORTSDIR}/devel/linuxthreads
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
WANT_MYSQL_VER=	51

LATEST_LINK=	mysql51-server

CONFLICTS=	mysql-server-3.* mysql-server-4.* mysql-server-5.0.*

USE_RC_SUBR=	mysql-server.sh

.if defined(WITH_NDB)
PLIST_SUB+=	NDB=""
.else
PLIST_SUB+=	NDB="@comment "
.endif

MAN1=		myisamchk.1 myisamlog.1 myisampack.1 \
		my_print_defaults.1 mysql_tzinfo_to_sql.1 \
		mysqld_safe.1 mysql.server.1 perror.1 replace.1

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
	@${ECHO} "	WITH_NDB=yes		Enable support for NDB Cluster."
	@${ECHO} ""

post-patch:
	@${REINPLACE_CMD} -e "s|SUBDIRS =|SUBDIRS = include @docs_dirs@ sql-common @sql_server_dirs@ storage scripts @sql_server@ @man_dirs@ support-files|g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|bin_SCRIPTS =|bin_SCRIPTS = @server_scripts@|g" ${WRKSRC}/scripts/Makefile.in
	@${REINPLACE_CMD} -e "s|dist_pkgdata_DATA =|dist_pkgdata_DATA = fill_help_tables.sql mysql_system_tables.sql mysql_system_tables_data.sql|g" ${WRKSRC}/scripts/Makefile.in
	@${REINPLACE_CMD} -e "s|man1_MANS =|man1_MANS = ${MAN1}|g" ${WRKSRC}/man/Makefile.in
	@${REINPLACE_CMD} -e "s|install-data-am: install-pkgincludeHEADERS|install-data-am:|g" ${WRKSRC}/extra/Makefile.in
	@${REINPLACE_CMD} -e "s|install-data-am: install-pkgincludeHEADERS|install-data-am:|g" ${WRKSRC}/include/Makefile.in
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/mysys/default.c
	@${REINPLACE_CMD} -e "/^AM_CXXFLAGS/s|=.*|+= \$$(NDB_CXXFLAGS)|" `${FIND} ${WRKSRC}/storage/ndb -name Makefile.in`
.if defined(WITH_PROC_SCOPE_PTH)
	@${REINPLACE_CMD} -e "s|PTHREAD_SCOPE_SYSTEM|PTHREAD_SCOPE_PROCESS|g" ${WRKSRC}/sql/mysqld.cc
.endif

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}
.endif

.else
# MySQL-Client part
.if defined(CLIENT_ONLY)
LATEST_LINK=	mysql51-client

CONFLICTS=	mysql-client-3.* mysql-client-4.* mysql-client-5.0.*

MAN1=		mysql_config.1 mysql.1 mysqladmin.1 mysqlbinlog.1 \
		mysqlcheck.1 mysqldump.1 mysqlimport.1 mysqlshow.1

MAN8=		mysqlmanager.8

USE_LDCONFIG=	${PREFIX}/lib/mysql

CONFIGURE_ARGS+=--without-server

post-patch:
	@${REINPLACE_CMD} -e "s|SUBDIRS =|SUBDIRS = include sql-common scripts strings regex mysys dbug extra libmysql libmysql_r client @man_dirs@|g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|install-exec-am: install-pkglibLIBRARIES|install-exec-am:|g" ${WRKSRC}/strings/Makefile.in ${WRKSRC}/mysys/Makefile.in ${WRKSRC}/dbug/Makefile.in
	@${REINPLACE_CMD} -e "s|bin_SCRIPTS =|bin_SCRIPTS = mysql_config mysql_fix_privilege_tables mysqlbug|g" ${WRKSRC}/scripts/Makefile.in
	@${REINPLACE_CMD} -e "s|dist_pkgdata_DATA =|dist_pkgdata_DATA = mysql_fix_privilege_tables.sql|g" ${WRKSRC}/scripts/Makefile.in
	@${REINPLACE_CMD} -e "s|man1_MANS =|man1_MANS = ${MAN1}|g;s|man8_MANS =|man8_MANS = ${MAN8}|g" ${WRKSRC}/man/Makefile.in
	@${REINPLACE_CMD} -e "s|install-exec-am: install-binPROGRAMS|install-exec-am:|g" ${WRKSRC}/extra/Makefile.in
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/mysys/default.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/support-files/mysql.m4 ${PREFIX}/share/aclocal/

.else
# MySQL-Scripts part
USE_MYSQL=	yes
WANT_MYSQL_VER=	51
USE_PERL5=	yes

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql51
.if ${PERL_LEVEL} <= 500800
RUN_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
.endif

LATEST_LINK=	mysql51-scripts

CONFLICTS=	mysql-scripts-3.* mysql-scripts-4.* mysql-scripts-5.0.*

MAN1=		msql2mysql.1 mysql_zap.1 mysqlaccess.1 mysqlhotcopy.1 \
		mysqld_multi.1 mysql_fix_privilege_tables.1

SCRIPTS=	msql2mysql mysql_fix_extensions mysql_setpermission \
		mysql_secure_installation mysql_zap mysqlaccess \
		mysql_convert_table_format mysql_find_rows mysqlhotcopy \
		mysqldumpslow mysqld_multi

post-patch:
	@${REINPLACE_CMD} -e "s|SUBDIRS =|SUBDIRS = scripts @man_dirs@|g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|bin_SCRIPTS =|bin_SCRIPTS = ${SCRIPTS}|g" ${WRKSRC}/scripts/Makefile.in
	@${REINPLACE_CMD} -e "s|install-exec-am install-data-am|install-exec-am|g" ${WRKSRC}/scripts/Makefile.in
	@${REINPLACE_CMD} -e "s|man1_MANS =|man1_MANS = ${MAN1}|g" ${WRKSRC}/man/Makefile.in
.endif
.endif
# Common part
post-extract:
	@${CP} /usr/include/tcpd.h ${WRKSRC}/include/my_tcpd.h

.if defined(WITH_OPENSSL) && defined(BUILD_STATIC)
pre-configure:
	@${ECHO} "You can't use the BUILD_STATIC option when using OpenSSL."
	@${FALSE}
.endif

.include <bsd.port.post.mk>
