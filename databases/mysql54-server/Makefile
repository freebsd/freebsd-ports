# New ports collection makefile for:	MySQL-server
# Date created:				Fri Apr 11 10:06:26 CET 2003
# Whom:					Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME?=	mysql
PORTVERSION=	4.1.0
PORTREVISION?=	1
CATEGORIES=	databases
MASTER_SITES=	ftp://mysql.secsup.org/pub/software/mysql/Downloads/MySQL-4.1/ \
		http://mysql.tzone.it/Downloads/MySQL-4.1/ \
		ftp://planetmirror.com/pub/mysql/Downloads/MySQL-4.1/ \
		http://www.softagency.co.jp/MySQL/Downloads/MySQL-4.1/ \
		ftp://sunsite.dk/mirrors/mysql/Downloads/MySQL-4.1/ \
		http://mysql.mediatraffic.fi/Downloads/MySQL-4.1/ \
		ftp://filepile.tiscali.de/mirror/mysql/Downloads/MySQL-4.1/ \
		http://mirrors.tilian.co.uk/mysql.com/Downloads/MySQL-4.1/ \
		ftp://ftp.rtfm.no/pub/mysql/Downloads/MySQL-4.1/ \
		http://www.mysql.cz/Downloads/MySQL-4.1/ \
		ftp://ftp.u-paris10.fr/mysql.com/Downloads/MySQL-4.1/ \
		http://mysql.oms-net.nl/Downloads/MySQL-4.1/ \
		ftp://ftp.free.fr/pub/MySQL/Downloads/MySQL-4.1/
PKGNAMESUFFIX?=	-server
DISTNAME=	${PORTNAME}-${PORTVERSION}-alpha

MAINTAINER=	sysadmin@alexdupre.com
COMMENT?=	Multithreaded SQL database (server)

SLAVEDIRS=	databases/mysql41-client
DB_DIR?=	/var/db/mysql
USE_LIBTOOL=	yes
USE_REINPLACE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--localstatedir=${DB_DIR} \
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

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=--enable-assembler --with-berkeley-db
.endif
.if defined(WITH_CHARSET) && ${WITH_CHARSET} != ""
CONFIGURE_ARGS+=--with-charset=${WITH_CHARSET}
.endif
.if defined(WITH_XCHARSET) && ${WITH_XCHARSET} != ""
CONFIGURE_ARGS+=--with-extra-charsets=${WITH_XCHARSET}
.endif
.if defined(WITH_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-openssl
.endif
.if defined(BUILD_STATIC)
CONFIGURE_ARGS+=--with-mysqld-ldflags=-all-static
.endif
.if defined(BUILD_OPTIMIZED)
CFLAGS+=	-mcpu=i686
.endif
.if defined(WITH_LINUXTHREADS)
CONFIGURE_ARGS+=--with-named-thread-libs='-DHAVE_GLIBC2_STYLE_GETHOSTBYNAME_R
CONFIGURE_ARGS+=-D_THREAD_SAFE -I${LOCALBASE}/include/pthread/linuxthreads
CFLAGS+=	-D__USE_UNIX98 -D_REENTRANT -D_THREAD_SAFE
CFLAGS+=	-I${LOCALBASE}/include/pthread/linuxthreads
.if ${OSVERSION} > 500000
LIB_DEPENDS+=   lthread.3:${PORTSDIR}/devel/linuxthreads
CONFIGURE_ARGS+=-L${LOCALBASE}/lib -llthread -llgcc_r -llstdc++ -llsupc++'
.else
LIB_DEPENDS+=   lthread.2:${PORTSDIR}/devel/linuxthreads
CONFIGURE_ARGS+=-L${LOCALBASE}/lib -llthread -llgcc_r'
.endif
.endif

CFLAGS+=	-O3 -fno-omit-frame-pointer
CXXFLAGS=	${CFLAGS} -felide-constructors -fno-rtti

.if ${OSVERSION} >= 400002
CXXFLAGS+=	-fno-exceptions
.endif
.if ${OSVERSION} < 500000
CXX=		${CC}
.endif

# MySQL-Server part
.if !defined(CLIENT_ONLY)
USE_PERL5_RUN=	yes

RUN_DEPENDS=	mysql:${PORTSDIR}/databases/mysql41-client \
		${SITE_PERL}/${PERL_ARCH}/Mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql

PLIST_SUB=	MYSQL_VERSION=${PORTVERSION}-alpha

ONLY_FOR_ARCHS=	i386 alpha sparc64

DOCS=		manual.html manual.txt manual_toc.html

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "	WITH_CHARSET=charset	Define the primary built-in charset (latin1)."
	@${ECHO} "	WITH_XCHARSET=list	Define other built-in charsets (may be 'all')."
	@${ECHO} "	WITH_OPENSSL=yes	Enable secure connections."
	@${ECHO} "	DB_DIR=directory	Set alternate directory for database files"
	@${ECHO} "				(default is /var/db/mysql)."
	@${ECHO} "	WITH_LINUXTHREADS=yes	Use the linuxthreads pthread library."
	@${ECHO} "	OVERWRITE_DB=yes	Re-initialize default databases."
	@${ECHO} "	SKIP_DNS_CHECK=yes	Don't run resolveip to do an additional DNS"
	@${ECHO} "				reverse lookup  before inserting local"
	@${ECHO} "				hostname into mysql database"
	@${ECHO} "				(use if your machine has no official DNS entry)."
	@${ECHO} "	BUILD_STATIC=yes	Build a static version of mysqld."
	@${ECHO} "	BUILD_OPTIMIZED=yes	Add -mcpu=i686 to CFLAGS."
	@${ECHO} ""

post-patch:
	 @${REINPLACE_CMD} -e "s|SUBDIRS =|SUBDIRS = include @sql_server_dirs@ scripts support-files|g" ${WRKSRC}/Makefile.in
	 @${REINPLACE_CMD} -e "s|install: install-am|install:|g" ${WRKSRC}/include/Makefile.in

.if defined(WITH_OPENSSL) && defined(BUILD_STATIC)
pre-configure:
	@${ECHO} "You can't use the BUILD_STATIC option when using OpenSSL."
	@${FALSE}
.endif

post-install:
.if !defined(PACKAGE_BUILDING)
.if exists(${DB_DIR}) && defined(OVERWRITE_DB)
	@${RM} -r ${DB_DIR}/mysql ${DB_DIR}/test 2>/dev/null || true
.endif
.if !exists(${DB_DIR}) || defined(OVERWRITE_DB)
.if defined(SKIP_DNS_CHECK)
	${PREFIX}/bin/mysql_install_db --force --ldata=${DB_DIR}
.else
	${PREFIX}/bin/mysql_install_db --ldata=${DB_DIR}
.endif
.endif
	@${SETENV} DB_DIR=${DB_DIR} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	@${SED} "s|%%PREFIX%%|${PREFIX}|g; s|%%DB_DIR%%|${DB_DIR}|g" < ${FILESDIR}/mysql-server.sh > ${PREFIX}/etc/rc.d/mysql-server.sh
	@${CHMOD} 750 ${PREFIX}/etc/rc.d/mysql-server.sh
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/Flags
.for doc in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/Docs/${doc} ${DOCSDIR}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/Docs/Flags/*.gif ${DOCSDIR}/Flags
	@${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info
	@install-info ${PREFIX}/info/mysql.info ${PREFIX}/info/dir
.endif

# MySQL-Client part
.else
MAN1=		isamchk.1 isamlog.1 mysql.1 mysql_zap.1 mysqlaccess.1  \
		mysqladmin.1 mysqld.1 mysqld_multi.1 mysqld_safe.1 mysqldump.1 \
		mysqlshow.1 perror.1 replace.1

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/mysql

CONFIGURE_ARGS+=--without-server

post-patch:
	 @${REINPLACE_CMD} -e "s|SUBDIRS =|SUBDIRS = include @sql_client_dirs@ tests man|g" ${WRKSRC}/Makefile.in

post-install:
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${FILESDIR}/mysql-client.sh > ${PREFIX}/etc/rc.d/000.mysql-client.sh
	@${CHMOD} 750 ${PREFIX}/etc/rc.d/000.mysql-client.sh
.endif

.include <bsd.port.post.mk>
