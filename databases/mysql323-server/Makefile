# ports collection makefile for:	MySQL-server
# Date created:				Sun Sep 24 21:20:46 CEST 2000
# Whom:					Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	${MASTERPORTNAME}
PORTVERSION=	3.23.58
#PORTREVISION?=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.kernelnotes.de/MySQL/Downloads/MySQL-3.23/ \
		http://mysql.he.net/Downloads/MySQL-3.23/ \
		ftp://ftp.sunet.se/pub/unix/databases/relational/mysql/Downloads/MySQL-3.23/ \
		ftp://mysql.secsup.org/pub/software/mysql/Downloads/MySQL-3.23/ \
		http://mysql.orst.edu/Downloads/MySQL-3.23/ \
		http://web.tryc.on.ca/mysql/Downloads/MySQL-3.23/ \
		ftp://ftp.gwdg.de/pub/misc/mysql/Downloads/MySQL-3.23/
DISTFILES=	mysql-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Multithreaded SQL database (server)

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
		--with-comment='FreeBSD port: ${PKGNAME}' \
		--program-prefix='' \
		--with-innodb

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
.if defined(BUILD_STATIC)
CONFIGURE_ARGS+=--with-mysqld-ldflags=--static
.endif
.if defined(BUILD_OPTIMIZED)
CFLAGS+=	-mcpu=pentiumpro -O3
.endif
.if defined(WITH_LINUXTHREADS)
CONFIGURE_ARGS+=--with-named-thread-libs='-DHAVE_GLIBC2_STYLE_GETHOSTBYNAME_R
CONFIGURE_ARGS+=-D_THREAD_SAFE -I${LOCALBASE}/include/pthread/linuxthreads
CFLAGS+=	-D__USE_UNIX98 -D_REENTRANT -D_THREAD_SAFE -I${LOCALBASE}/include/pthread/linuxthreads
.if ${OSVERSION} > 500000
CONFIGURE_ARGS+=-L${LOCALBASE}/lib -llthread -llgcc_r -llstdc++ -llsupc++'
LIB_DEPENDS+=	lthread.3:${PORTSDIR}/devel/linuxthreads
.else
CONFIGURE_ARGS+=-L${LOCALBASE}/lib -llthread -llgcc_r'
LIB_DEPENDS+=	lthread.2:${PORTSDIR}/devel/linuxthreads
.endif
.endif
.if defined(THREAD_SAFE_CLIENT)
CONFIGURE_ARGS+=--enable-thread-safe-client
.endif
CONFIGURE_ENV+=	PERL=${PERL} \
		PERL5=${PERL} \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		CFLAGS="${CFLAGS}" \
		CONFIGURE_ARGS="${CONFIGURE_ARGS}"

# without including these flags mysqld may crash under heavy load
# and multiple connections at the same time
CXXFLAGS=	${CFLAGS} -felide-constructors -fno-rtti
.if ${OSVERSION} >= 400002
CXXFLAGS+=	-fno-exceptions
.endif
.if ${OSVERSION} < 500000
CONFIGURE_ENV+=	CXX="${CC}"
.endif

# MySQL-Server part
.if !defined(CLIENT_ONLY)
.if !defined(NOPORTDOCS)
INFO=		mysql
.endif

RUN_DEPENDS=	mysql:${PORTSDIR}/databases/mysql323-client \
		${SITE_PERL}/${PERL_ARCH}/Mysql.pm:${PORTSDIR}/databases/p5-Mysql

PLIST_SUB=	MYSQL_VERSION=${PORTVERSION}

ONLY_FOR_ARCHS=	i386 alpha sparc64

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITH_CHARSET=charset	define the primary built-in charset (latin1);"
	@${ECHO_MSG} "	WITH_XCHARSET=list	define other built-in charsets (may be 'all');"
	@${ECHO_MSG} "	DB_DIR=directory	Set alternate directory for database files"
	@${ECHO_MSG} "				(default is /var/db/mysql)."
	@${ECHO_MSG} "	WITH_LINUXTHREADS=yes	Use the linuxthreads pthread library."
	@${ECHO_MSG} "	SKIP_INSTALL_DB=yes	Skip mysql_install_db"
	@${ECHO_MSG} "				(i. e. leave ${DB_DIR} alone)."
	@${ECHO_MSG} "				This is useful for upgrades."
	@${ECHO_MSG} "				Be sure to know what you are doing!"
	@${ECHO_MSG} "	SKIP_DNS_CHECK=yes	don't run resolveip to do an additional"
	@${ECHO_MSG} "				DNS check before inserting local hostname to"
	@${ECHO_MSG} "				mysql database."
	@${ECHO_MSG} "				Use if your machine has no offical DNS entry."
	@${ECHO_MSG} "	BUILD_STATIC=yes	Build a static version of mysqld."
	@${ECHO_MSG} "	BUILD_OPTIMIZED=yes	Add -mcpu=pentiumpro -O3 to CFLAGS."
	@${ECHO_MSG} "				This setting may produce broken code and thus"
	@${ECHO_MSG} "				is not recommended for production servers."
	@${ECHO_MSG} ""

.if exists(${DB_DIR}) && !defined(PACKAGE_BUILDING) && !defined(OVERWRITE_DB) && !defined(SKIP_INSTALL_DB)
pre-install:
	@${ECHO_MSG} "You appear to already have a mysql database directory in ${DB_DIR}."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "In order to preserve your existing data, you should:"
	@${ECHO_MSG} "	- dump all your databases"
	@${ECHO_MSG} "	- kill mysql if it is running"
	@${ECHO_MSG} "	- delete the ${DB_DIR} directory"
	@${ECHO_MSG} "	- run 'make install'"
	@${ECHO_MSG} "	- start up mysql"
	@${ECHO_MSG} "	- re-create all of your database"
	@${ECHO_MSG} "	- re-load your data"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you understand the consequences of this upgrade, please re-build this"
	@${ECHO_MSG} "port with the environment variable OVERWRITE_DB defined."
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
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${FILESDIR}/mysql-client.sh > ${PREFIX}/etc/rc.d/000.mysql-client.sh
	@${CHMOD} 750 ${PREFIX}/etc/rc.d/000.mysql-client.sh

.endif

# This is for the maintainer only...
make-plist:
	${FIND} foo -type f -or -type l | /usr/bin/cut -d / -f 2- | \
		/usr/bin/sort  > ${.CURDIR}/pkg-plist.new
	/usr/bin/perl -i -ne 'if (m#share/doc/#) { print "%%PORTDOCS%%", $$_; } else { print $$_; }' ${.CURDIR}/pkg-plist.new

.include <bsd.port.post.mk>
