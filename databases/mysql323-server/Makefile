# ports collection makefile for:	MySQL-server
# Date created:				Sun Sep 24 21:20:46 CEST 2000
# Whom:					Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	${MASTERPORTNAME}
PORTVERSION=	3.23.36
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
		--with-low-memory
.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=--enable-assembler --with-berkeley-db
.endif
.if defined(WITH_CHARSET) && ${WITH_CHARSET} != ""
CONFIGURE_ARGS+=--with-charset=${WITH_CHARSET}
.if defined(WITH_XCHARSET) && ${WITH_XCHARSET} != ""
CONFIGURE_ARGS+=--with-extra-charsets=${WITH_XCHARSET}
.endif
.endif
CONFIGURE_ENV+=	PERL=${PERL} \
		PERL5=${PERL} \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		CONFIGURE_ARGS="${CONFIGURE_ARGS}"

.include <bsd.port.pre.mk>
# without including these flags mysqld may crash under heavy load
# and multiple connections at the same time
CXXFLAGS=	${CFLAGS} -felide-constructors -fno-rtti
.if ${OSVERSION} >= 400002
CXXFLAGS+=	-fno-exceptions
.endif

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "	WITH_CHARSET=charset	define the primary built-in charset (latin1);"
	@${ECHO} "	WITH_XCHARSET=list	define other built-in charsets (may be 'all');"
	@${ECHO} "	DB_DIR=directory	Set alternate directory for database files."
	@${ECHO} ""

# MySQL-Server part
.if !defined(CLIENT_ONLY)
RUN_DEPENDS=	mysql:${PORTSDIR}/databases/mysql323-client

PLIST_SUB=	MYSQL_VERSION=${PORTVERSION}

post-patch:
	${MV} ${WRKSRC}/strings/strings-x86.s ${WRKSRC}/strings/strings-x86.S
	${MV} ${WRKSRC}/strings/longlong2str-x86.s ${WRKSRC}/strings/longlong2str-x86.S

pre-install:
.if !defined(PACKAGE_BUILDING) && exists(${DB_DIR}) && !defined(OVERWRITE_DB)
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
	${PREFIX}/bin/mysql_install_db
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

.include <bsd.port.post.mk>
