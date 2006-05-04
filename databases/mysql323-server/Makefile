# ports collection makefile for:	MySQL-server
# Date created:				Sun Sep 24 21:20:46 CEST 2000
# Whom:					Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	mysql
DISTVERSION=	3.23.59-nightly-20050301
PORTREVISION?=	3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ale
PKGNAMESUFFIX?=	-server

MAINTAINER=	ale@FreeBSD.org
COMMENT?=	Multithreaded SQL database (server)

SLAVEDIRS=	databases/mysql323-client
USE_AUTOTOOLS=	libtool:15

CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--localstatedir=/var/db/mysql \
		--without-debug \
		--without-readline \
		--without-bench \
		--with-libwrap \
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
.if defined(BUILD_STATIC)
CONFIGURE_ARGS+=--with-mysqld-ldflags=-all-static
.endif
.if !defined(WITHOUT_INNODB)
CONFIGURE_ARGS+=--with-innodb
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
.if ${OSVERSION} > 500000
LIB_DEPENDS+=	lthread.[35]:${PORTSDIR}/devel/linuxthreads
CONFIGURE_ARGS+=-L${LOCALBASE}/lib -llthread -llgcc_r -llstdc++ -llsupc++'
.else
LIB_DEPENDS+=	lthread.[24]:${PORTSDIR}/devel/linuxthreads
CONFIGURE_ARGS+=-L${LOCALBASE}/lib -llthread -llgcc_r'
.endif
.else
CONFIGURE_ARGS+=--with-named-thread-libs=${PTHREAD_LIBS}
CFLAGS+=	${PTHREAD_CFLAGS}
.endif

.if ${OSVERSION} < 500000
CXX=		${CC}
.endif
.if defined(BUILD_OPTIMIZED)
CFLAGS+=	-O3 -fno-omit-frame-pointer
.if ${OSVERSION} > 500000 || (defined(USE_GCC) && (${USE_GCC} == 3.0 || ${USE_GCC} == 3.1 || ${USE_GCC} == 3.2 || ${USE_GCC} == 3.3))
CFLAGS+=	-fno-gcse
.endif
.endif
CXXFLAGS+=	${CFLAGS} -felide-constructors -fno-rtti
.if ${OSVERSION} >= 400002
CXXFLAGS+=	-fno-exceptions
.endif

# MySQL-Server part
.if !defined(CLIENT_ONLY) && !defined(SCRIPTS_ONLY)
USE_MYSQL=	yes
WANT_MYSQL_VER=	323

LATEST_LINK=	mysql323-server

CONFLICTS=	mysql-server-4.* mysql-server-5.*

USE_RC_SUBR=	mysql-server.sh

PLIST_SUB=	VER=${DISTVERSION}

MAN1=		isamchk.1 isamlog.1 mysqld.1 \
		safe_mysqld.1 perror.1 replace.1

.if !defined(NOPORTDOCS)
DOCS=		manual.html manual.txt manual_toc.html
PORTDOCS=	${DOCS} Flags
.endif

INFO=		mysql

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "	WITH_CHARSET=charset	Define the primary built-in charset (latin1)."
	@${ECHO} "	WITH_XCHARSET=list	Define other built-in charsets (may be 'all')."
	@${ECHO} "	WITH_OPENSSL=yes	Enable secure connections."
	@${ECHO} "	WITH_LINUXTHREADS=yes	Use the linuxthreads pthread library."
	@${ECHO} "	WITH_PROC_SCOPE_PTH=yes	Use process scope threads"
	@${ECHO} "				(try it if you use libpthread)."
	@${ECHO} "	BUILD_OPTIMIZED=yes	Enable compiler optimizations"
	@${ECHO} "				(use it if you need speed)."
	@${ECHO} "	BUILD_STATIC=yes	Build a static version of mysqld."
	@${ECHO} "				(use it if you need even more speed)."
	@${ECHO} "	WITHOUT_INNODB=yes	Disable support for InnoDB table handler."
	@${ECHO} ""

post-patch:
	@${REINPLACE_CMD} -e "s|SUBDIRS =|SUBDIRS = include @docs_dirs@ @sql_server_dirs@ scripts man support-files|g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|bin_SCRIPTS =|bin_SCRIPTS = @server_scripts@|g" ${WRKSRC}/scripts/Makefile.in
	@${REINPLACE_CMD} -e "s|man_MANS =|man_MANS = ${MAN1}|g" ${WRKSRC}/man/Makefile.in
	@${REINPLACE_CMD} -e "s|install-data-am: install-pkgincludeHEADERS|install-data-am:|g" ${WRKSRC}/include/Makefile.in
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/mysys/default.c
.if defined(WITH_PROC_SCOPE_PTH)
	@${REINPLACE_CMD} -e "s|PTHREAD_SCOPE_SYSTEM|PTHREAD_SCOPE_PROCESS|g" ${WRKSRC}/libmysqld/lib_sql.cc ${WRKSRC}/sql/mysqld.cc
.endif

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/Flags
.for doc in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/Docs/${doc} ${DOCSDIR}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/Docs/Flags/*.gif ${DOCSDIR}/Flags
.endif

.else
# MySQL-Client part
.if defined(CLIENT_ONLY)
LATEST_LINK=	mysql323-client

CONFLICTS=	mysql-client-4.* mysql-client-5.*

MAN1=		mysql.1 mysqladmin.1 mysqldump.1 mysqlshow.1

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/mysql
USE_LDCONFIG=	${PREFIX}/lib/mysql
.include "${PORTSDIR}/misc/ldconfig_compat/bsd.ldconfig.mk"

CONFIGURE_ARGS+=--without-server

post-patch:
	@${REINPLACE_CMD} -e "s|SUBDIRS =|SUBDIRS = include @sql_client_dirs@ tests scripts man|g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|bin_SCRIPTS =|bin_SCRIPTS = mysql_config mysqlbug|g" ${WRKSRC}/scripts/Makefile.in
	@${REINPLACE_CMD} -e "s|man_MANS =|man_MANS = ${MAN1}|g" ${WRKSRC}/man/Makefile.in
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/mysys/default.c

post-install: install-ldconfig-file

.else
# MySQL-Scripts part
USE_MYSQL=	yes
WANT_MYSQL_VER=	323
USE_PERL5=	yes

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Mysql.pm:${PORTSDIR}/databases/p5-Mysql
.if ${PERL_LEVEL} <= 500800
RUN_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
.endif

LATEST_LINK=	mysql323-scripts

CONFLICTS=	mysql-scripts-4.* mysql-scripts-5.*

MAN1=		mysql_zap.1 mysqlaccess.1 mysqld_multi.1

SCRIPTS=	msql2mysql mysql_setpermission mysql_zap mysqlaccess \
		mysql_convert_table_format mysql_find_rows mysqlhotcopy \
		mysqldumpslow mysqld_multi

post-patch:
	@${REINPLACE_CMD} -e "s|SUBDIRS =|SUBDIRS = scripts man|g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|bin_SCRIPTS =|bin_SCRIPTS = ${SCRIPTS}|g" ${WRKSRC}/scripts/Makefile.in
	@${REINPLACE_CMD} -e "s|man_MANS =|man_MANS = ${MAN1}|g" ${WRKSRC}/man/Makefile.in
.endif
.endif
# Common part
post-extract:
	@${CP} /usr/include/tcpd.h ${WRKSRC}/sql/mytcpd.h

.include <bsd.port.post.mk>
