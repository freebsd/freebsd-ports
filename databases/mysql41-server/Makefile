# ports collection makefile for:	MySQL-server
# Date created:				Sun Sep 24 21:20:46 CEST 2000
# Whom:					Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	${MASTERPORTNAME}
PORTVERSION=	3.23.47
PORTREVISION?=	0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.kernelnotes.de/MySQL/Downloads/MySQL-3.23/ \
		http://mysql.he.net/Downloads/MySQL-3.23/ \
		ftp://ftp.sunet.se/pub/unix/databases/relational/mysql/Downloads/MySQL-3.23/
MASTER_SITE_SUBDIR=	mirrors/mysql/Downloads/MySQL-3.23
DISTFILES=	mysql-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	dirk@FreeBSD.org

WRKSRC=		${WRKDIR}/mysql-${PORTVERSION}
SLAVEDIRS=	databases/mysql323-client
MASTERPORTNAME=	mysql-server
DB_DIR?=	/var/db/mysql
USE_PERL5=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--localstatedir=${DB_DIR} \
		--without-perl \
		--without-debug \
		--without-readline \
		--without-bench \
		--with-mit-threads=no \
		--with-libwrap \
		--with-low-memory \
		--with-comment='FreeBSD port: ${PKGNAME}'

.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=--enable-assembler --with-berkeley-db --with-innodb
.endif
.if defined(WITH_CHARSET) && ${WITH_CHARSET} != ""
CONFIGURE_ARGS+=--with-charset=${WITH_CHARSET}
.if defined(WITH_XCHARSET) && ${WITH_XCHARSET} != ""
CONFIGURE_ARGS+=--with-extra-charsets=${WITH_XCHARSET}
.endif
.endif
.if defined(BUILD_STATIC)
CONFIGURE_ARGS+=--with-mysqld-ldflags=--static
.endif
.if defined(BUILD_OPTIMIZED)
CFLAGS+=	-mcpu=pentiumpro -O3
.endif
.if defined(WITH_LINUXTHREADS)
CONFIGURE_ARGS+=--with-named-thread-libs='-DHAVE_GLIBC2_STYLE_GETHOSTBYNAME_R -D_THREAD_SAFE -I${LOCALBASE}/include/pthread/linuxthreads -L${LOCALBASE}/lib -llthread -llgcc_r'
CFLAGS+=	-D__USE_UNIX98 -D_REENTRANT -D_THREAD_SAFE -I${LOCALBASE}/include/pthread/linuxthreads
LIB_DEPENDS+=	lthread.2:${PORTSDIR}/devel/linuxthreads
.endif
CONFIGURE_ENV+=	PERL=${PERL} \
		PERL5=${PERL} \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		CXX="${CC}" \
		CFLAGS="${CFLAGS}" \
		CONFIGURE_ARGS="${CONFIGURE_ARGS}"

.include <bsd.port.pre.mk>
# without including these flags mysqld may crash under heavy load
# and multiple connections at the same time
CXXFLAGS=	${CFLAGS} -felide-constructors -fno-rtti
.if ${OSVERSION} >= 400002
CXXFLAGS+=	-fno-exceptions
.endif

# MySQL-Server part
.if !defined(CLIENT_ONLY)
RUN_DEPENDS=	mysql:${PORTSDIR}/databases/mysql323-client \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Mysql.pm:${PORTSDIR}/databases/p5-Mysql

PLIST_SUB=	MYSQL_VERSION=${PORTVERSION}

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "	WITH_CHARSET=charset	define the primary built-in charset (latin1);"
	@${ECHO} "	WITH_XCHARSET=list	define other built-in charsets (may be 'all');"
	@${ECHO} "	DB_DIR=directory	Set alternate directory for database files"
	@${ECHO} "				(default is /var/db/mysql)."
	@${ECHO} "	WITH_LINUXTHREADS=yes	Use the linuxthreads pthread library."
	@${ECHO} "				This is _NOT_ recommended for production"
	@${ECHO} "				servers. Expect problems when enabled."
	@${ECHO} "	SKIP_INSTALL_DB=yes	Skip mysql_install_db"
	@${ECHO} "				(i. e. leave ${DB_DIR} alone)."
	@${ECHO} "				This is useful for upgrades."
	@${ECHO} "				Be sure to know what you are doing!"
	@${ECHO} "	SKIP_DNS_CHECK=yes	don't run resolveip to do an additional"
	@${ECHO} "				DNS check before inserting local hostname to"
	@${ECHO} "				mysql database."
	@${ECHO} "				Use if your machine has no offical DNS entry."
	@${ECHO} "	BUILD_STATIC=yes	Build a static version of mysqld."
	@${ECHO} "	BUILD_OPTIMIZED=yes	Add -mcpu=pentiumpro -O3 to CFLAGS."
	@${ECHO} "				This setting may produce broken code and thus"
	@${ECHO} "				is not recommended for production servers."
	@${ECHO} ""

post-patch:
	${MV} ${WRKSRC}/strings/strings-x86.s ${WRKSRC}/strings/strings-x86.S
	${MV} ${WRKSRC}/strings/longlong2str-x86.s ${WRKSRC}/strings/longlong2str-x86.S

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
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${FILESDIR}/mysql-server.sh > ${PREFIX}/etc/rc.d/mysql-server.sh
	@${CHMOD} 750 ${PREFIX}/etc/rc.d/mysql-server.sh

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mysql/Flags
.for doc in manual.html manual.ps manual_toc.html manual.txt manual.texi include.texi
	${INSTALL_DATA} ${WRKSRC}/Docs/${doc} ${PREFIX}/share/doc/mysql
.endfor
	${INSTALL_DATA} ${WRKSRC}/Docs/Flags/*.gif ${PREFIX}/share/doc/mysql/Flags
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info
	@install-info ${PREFIX}/info/mysql.info ${PREFIX}/info/dir
.endif

# MySQL-Client part
.else
MAN1=		isamchk.1 isamlog.1 mysql.1 mysql_zap.1 mysqlaccess.1  \
		mysqladmin.1 mysqld.1 mysqld_multi.1 mysqldump.1 mysqlshow.1 \
		perror.1 replace.1 safe_mysqld.1

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/mysql

CONFIGURE_ARGS+=--without-server
MAKE_ENV=	CLIENT_ONLY="${CLIENT_ONLY}"

post-install:
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${FILESDIR}/mysql-client.sh > ${PREFIX}/etc/rc.d/00mysql-client.sh
	@${CHMOD} 750 ${PREFIX}/etc/rc.d/00mysql-client.sh

.endif

# This is for the maintainer only...
make-plist:
	/usr/bin/find foo -type f -or -type l | /usr/bin/cut -d / -f 2- | /usr/bin/sort  > ${.CURDIR}/pkg-plist.new
	/usr/bin/perl -i -ne 'if (m#share/doc/#) { print "%%PORTDOCS%%", $$_; } else { print $$_; }' ${.CURDIR}/pkg-plist.new

.include <bsd.port.post.mk>
