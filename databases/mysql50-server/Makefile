# ports collection makefile for:	MySQL-server
# Date created:				Sun Sep 24 21:20:46 CEST 2000
# Whom:					Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	${MASTERPORTNAME}
PORTVERSION=	3.23.26
CATEGORIES=	databases
MASTER_SITES=	http://download.sourceforge.net/mysql/ \
		http://www.fh-wolfenbuettel.de/ftp/pub/database/mysql/Downloads/MySQL-3.23/ \
		ftp://ftp.digex.net/pub/packages/database/mysql/Downloads/MySQL-3.23/ \
		ftp://ftp.plig.net/pub/mysql/Downloads/MySQL-3.23/ \
		ftp://ftp.sunet.se/pub/unix/databases/relational/mysql/Downloads/MySQL-3.23/
DISTNAME=	mysql-${PORTVERSION}-beta

MAINTAINER=	dirk@FreeBSD.org

Y2K=		http://www.mysql.com/documentation/mysql/bychapter/manual_Introduction.html#Year_2000_compliance

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
		--with-mit-threads=no
.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=--enable-assembler
.endif
CONFIGURE_ENV+=	PERL=${PERL} \
		PERL5=${PERL} \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		CONFIGURE_ARGS="${CONFIGURE_ARGS}"

# MySQL-Server part
.if !defined(CLIENT_ONLY)
RUN_DEPENDS=	mysql:${PORTSDIR}/databases/mysql323-client

PLIST_SUB=	MYSQL_VERSION=${PORTVERSION}-beta

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
MAN1=		mysql.1

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/mysql

CONFIGURE_ARGS+=--without-server
MAKE_ENV=	CLIENT_ONLY="${CLIENT_ONLY}"

post-install:
	@${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/mysql-client.sh
	@${ECHO} "" >> ${PREFIX}/etc/rc.d/mysql-client.sh
	@${ECHO} "${LDCONFIG} -m ${PREFIX}/lib/mysql" >> ${PREFIX}/etc/rc.d/mysql-client.sh
	@${CHMOD} 750 ${PREFIX}/etc/rc.d/mysql-client.sh
.endif

.include <bsd.port.mk>
