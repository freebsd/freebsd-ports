# New ports collection makefile for:    MySQL-server
# Date created:         Sun Mar 3 12:20:35 CET 2002
# Whom:                 Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME?=	mysql
PORTVERSION=	4.0.9
PORTREVISION?=	0
CATEGORIES=	databases
MASTER_SITES=	ftp://mysql.secsup.org/pub/software/mysql/Downloads/MySQL-4.0/ \
		http://mysql.tzone.it/Downloads/MySQL-4.0/ \
		ftp://planetmirror.com/pub/mysql/Downloads/MySQL-4.0/ \
		http://www.softagency.co.jp/MySQL/Downloads/MySQL-4.0/ \
		ftp://sunsite.dk/mirrors/mysql/Downloads/MySQL-4.0/ \
		http://mysql.mediatraffic.fi/Downloads/MySQL-4.0/ \
		ftp://filepile.tiscali.de/mirror/mysql/Downloads/MySQL-4.0/ \
		http://mirrors.tilian.co.uk/mysql.com/Downloads/MySQL-4.0/ \
		ftp://ftp.rtfm.no/pub/mysql/Downloads/MySQL-4.0/ \
		http://www.mysql.cz/Downloads/MySQL-4.0/ \
		ftp://ftp.u-paris10.fr/mysql.com/Downloads/MySQL-4.0/ \
		http://mysql.oms-net.nl/Downloads/MySQL-4.0/ \
		ftp://ftp.free.fr/pub/MySQL/Downloads/MySQL-4.0/
PKGNAMESUFFIX?=	-server
DISTNAME=	${PORTNAME}-${PORTVERSION}-gamma

MAINTAINER=	sysadmin@alexdupre.com

SLAVEDIRS=	databases/mysql40-client
DB_DIR?=	/var/db/mysql
USE_PERL5_RUN=	yes
USE_LIBTOOL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${DB_DIR} \
		--without-debug \
		--without-readline \
		--without-bench \
		--without-extra-tools \
		--with-libwrap \
		--with-raid \
		--with-mysqlfs \
		--with-vio \
		--with-low-memory \
		--with-comment='FreeBSD port: ${PKGNAME}' \
		--with-server-suffix='' \
		--program-prefix=''

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
.if defined(THREAD_SAFE_CLIENT)
CONFIGURE_ARGS+=--enable-thread-safe-client
.endif

CFLAGS+=	-O3 -fno-omit-frame-pointer
CXXFLAGS=	${CFLAGS} -felide-constructors -fno-rtti

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 400002
CXXFLAGS+=	-fno-exceptions
.endif
.if ${OSVERSION} < 500000
CXX=		${CC}
.endif

# MySQL-Server part
.if !defined(CLIENT_ONLY)
RUN_DEPENDS=	mysql:${PORTSDIR}/databases/mysql40-client \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Mysql.pm:${PORTSDIR}/databases/p5-Mysql

PLIST_SUB=	MYSQL_VERSION=${PORTVERSION}-gamma

ONLY_FOR_ARCHS=	i386 alpha

DOCS=		manual.html manual.ps manual_toc.html manual.txt manual.texi \
		include.texi

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "	WITH_CHARSET=charset	Define the primary built-in charset (latin1)."
	@${ECHO} "	WITH_XCHARSET=list	Define other built-in charsets (may be 'all')."
	@${ECHO} "	WITH_OPENSSL=yes	Enable secure connections."
	@${ECHO} "	DB_DIR=directory	Set alternate directory for database files"
	@${ECHO} "				(default is /var/db/mysql)."
	@${ECHO} "	SKIP_INSTALL_DB=yes	Skip database initialization"
	@${ECHO} "				(useful for upgrades)."
	@${ECHO} "	SKIP_DNS_CHECK=yes	Don't run resolveip to do an additional"
	@${ECHO} "				DNS check before inserting local hostname to"
	@${ECHO} "				mysql database"
	@${ECHO} "				(use if your machine has no official DNS entry)."
	@${ECHO} "	BUILD_STATIC=yes	Build a static version of mysqld."
	@${ECHO} "	BUILD_OPTIMIZED=yes	Add -mcpu=i686 to CFLAGS."
	@${ECHO} ""

.if defined(WITH_OPENSSL) && defined(BUILD_STATIC)
pre-configure:
	@${ECHO} "You can't use the BUILD_STATIC option when using OpenSSL."
	@${FALSE}
.endif

.if exists(${DB_DIR}) && !defined(PACKAGE_BUILDING) && !defined(OVERWRITE_DB) && !defined(SKIP_INSTALL_DB)
pre-install:
	@${ECHO} "You appear to already have a mysql database directory in ${DB_DIR}."
	@${ECHO} ""
	@${ECHO} "In order to preserve your existing data, you should:"
	@${ECHO} "	- dump all your databases"
	@${ECHO} "	- kill mysql if it is running"
	@${ECHO} "	- delete the ${DB_DIR} directory"
	@${ECHO} "	- run 'make install'"
	@${ECHO} "	- start up mysql"
	@${ECHO} "	- re-create all of your database"
	@${ECHO} "	- re-load your data"
	@${ECHO} ""
	@${ECHO} "If you understand the consequences of this upgrade, please re-build this"
	@${ECHO} "port with the environment variable OVERWRITE_DB defined."
	@${FALSE}
.endif

post-install:
.if !defined(PACKAGE_BUILDING)
.if !defined(SKIP_INSTALL_DB)
.if defined(SKIP_DNS_CHECK)
	${PREFIX}/bin/mysql_install_db --force
.else
	${PREFIX}/bin/mysql_install_db
.endif
.endif
	@${SETENV} DB_DIR=${DB_DIR} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	@${SED} "s|%%PREFIX%%|${PREFIX}|g; s|%%DB_DIR%%|${DB_DIR}|g" < ${FILESDIR}/mysql-server.sh > ${PREFIX}/etc/rc.d/mysql-server.sh
	@${CHMOD} 750 ${PREFIX}/etc/rc.d/mysql-server.sh

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/Flags
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/Docs/${doc} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/Docs/Flags/*.gif ${DOCSDIR}/Flags
.endif

# MySQL-Client part
.else
MAN1=		isamchk.1 isamlog.1 mysql.1 mysql_zap.1 mysqlaccess.1  \
		mysqladmin.1 mysqld.1 mysqld_multi.1 mysqld_safe.1 mysqldump.1 \
		mysqlshow.1 perror.1 replace.1

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/mysql

CONFIGURE_ARGS+=--without-server
MAKE_ENV=	CLIENT_ONLY="${CLIENT_ONLY}"

post-install:
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${FILESDIR}/mysql-client.sh > ${PREFIX}/etc/rc.d/000.mysql-client.sh
	@${CHMOD} 750 ${PREFIX}/etc/rc.d/000.mysql-client.sh

.endif

.include <bsd.port.post.mk>
