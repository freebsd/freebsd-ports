# ports collection makefile for:	MySQL-server
# Version required:			v3.22.x
# Date created:				26 Jan 1998
# Whom:					Josh Tiefenbach <josh@ican.net>
#
# $FreeBSD$
#

DISTNAME=	mysql-3.22.25
PKGNAME?=	${DISTNAME:S/-/-server-/}
CATEGORIES=	databases
MASTER_SITES=	http://www.fh-wolfenbuettel.de/ftp/pub/database/mysql/Downloads/MySQL-3.22/ \
		ftp://ftp.digex.net/pub/packages/database/mysql/Downloads/MySQL-3.22/ \
		ftp://ftp.bse.bg/pub/Unix/database/MySQL/ \
		ftp://ftp.plig.net/pub/mysql/Downloads/MySQL-3.22/ \
		ftp://ftp.sunet.se/pub/unix/databases/relational/mysql/Downloads/MySQL-3.22/

MAINTAINER=	dirk@FreeBSD.org

.if ${MACHINE_ARCH} == "alpha"
BROKEN=		doesn\'t build on the alpha yet
.endif

Y2K=		http://www.tcx.se/Manual_chapter/manual_Introduction.html#Year_2000_compliance

DB_DIR?=	/var/db/mysql
USE_PERL5=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--localstatedir=${DB_DIR} \
		--without-perl \
		--without-debug \
		--without-readline \
		--without-bench
CONFIGURE_ENV+=	PERL=${PERL} \
		PERL5=${PERL} \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		CXXFLAGS="${CFLAGS}" \
		CONFIGURE_ARGS="${CONFIGURE_ARGS}"

.if !defined(CLIENT_ONLY)
RUN_DEPENDS=	mysql:${PORTSDIR}/databases/mysql322-client

.include <bsd.port.pre.mk>

.if defined(NATIVE_THREADS) && ${OSVERSION} >= 300000
CONFIGURE_ARGS+=	--with-mit-threads=no
.else
CONFIGURE_ARGS+=	--with-mit-threads=yes
.endif

.if !defined(NATIVE_THREADS) && ${OSVERSION} >= 300000
pre-fetch:
	@${ECHO}
	@${ECHO} "You may set NATIVE_THREADS (make NATIVE_THREADS=yes)"
	@${ECHO} "to compile mysql with the native FreeBSD threads (libc_r)."
	@${ECHO} "Warning: There are still some bugs in libc_r which prevent"
	@${ECHO} "         'mysqladmin shutdown' from working properly and"
	@${ECHO} "         killing mysqld might not work."
	@${ECHO}
.elif defined(NATIVE_THREADS) && ${OSVERSION} >= 300000
pre-fetch:
	@${ECHO}
	@${ECHO} "Using native FreeBSD threads (libc_r)."
	@${ECHO}
.elif defined(NATIVE_THREADS) && ${OSVERSION} < 300000
pre-fetch:
	@${ECHO}
	@${ECHO} "Sorry, native FreeBSD threads (libc_r) in 2.2-branch"
	@${ECHO} "are still too buggy to use with mysql."
	@${ECHO} "Using mit-pthreads."
	@${ECHO}
.endif

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
	@${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/mysql-server.sh
	@${ECHO} "#" >> ${PREFIX}/etc/rc.d/mysql-server.sh
	@${ECHO} "" >> ${PREFIX}/etc/rc.d/mysql-server.sh
	@${ECHO} "if [ -x ${PREFIX}/bin/safe_mysqld ]" >> ${PREFIX}/etc/rc.d/mysql-server.sh
	@${ECHO} "then" >> ${PREFIX}/etc/rc.d/mysql-server.sh
	@${ECHO} "	${PREFIX}/bin/safe_mysqld --user=mysql > /dev/null & && ${ECHO} -n ' mysql'" >> ${PREFIX}/etc/rc.d/mysql-server.sh
	@${ECHO} "fi" >> ${PREFIX}/etc/rc.d/mysql-server.sh
	@${CHMOD} 750 ${PREFIX}/etc/rc.d/mysql-server.sh

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mysql/Img
.for doc in manual.html manual.ps manual_toc.html manual.txt manual.texi include.texi
	${INSTALL_DATA} ${WRKSRC}/Docs/${doc} ${PREFIX}/share/doc/mysql
.endfor
	${INSTALL_DATA} ${WRKSRC}/Docs/Img/*.gif ${PREFIX}/share/doc/mysql/Img
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info
	@install-info ${PREFIX}/info/mysql.info ${PREFIX}/info/dir
.endif

.include <bsd.port.post.mk>
.else
MAN1=		mysql.1

CONFIGURE_ARGS+=--without-server
MAKE_ENV=	CLIENT_ONLY="${CLIENT_ONLY}"

post-install:
	@${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/mysql-client.sh
	@${ECHO} "#" >> ${PREFIX}/etc/rc.d/mysql-client.sh
	@${ECHO} "${LDCONFIG} -m ${PREFIX}/lib/mysql" >> ${PREFIX}/etc/rc.d/mysql-client.sh
	@${CHMOD} 750 ${PREFIX}/etc/rc.d/mysql-client.sh

	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib/mysql

.include <bsd.port.mk>
.endif
