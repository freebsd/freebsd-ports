# ports collection makefile for:	MySQL-server
# Version required:			v3.22.x
# Date created:				26 Jan 1998
# Whom:					Josh Tiefenbach <josh@ican.net>
#
# $FreeBSD$
#

DISTNAME=	mysql-3.22.32
PKGNAME?=	${DISTNAME:S/-/-server-/}
CATEGORIES=	databases
MASTER_SITES=	http://www.fh-wolfenbuettel.de/ftp/pub/database/mysql/Downloads/MySQL-3.22/ \
		ftp://ftp.digex.net/pub/packages/database/mysql/Downloads/MySQL-3.22/ \
		ftp://ftp.plig.net/pub/mysql/Downloads/MySQL-3.22/ \
		ftp://ftp.sunet.se/pub/unix/databases/relational/mysql/Downloads/MySQL-3.22/

MAINTAINER=	dirk@FreeBSD.org

Y2K=		http://www.tcx.se/Manual_chapter/manual_Introduction.html#Year_2000_compliance

DB_DIR?=	/var/db/mysql
USE_PERL5=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--localstatedir=${DB_DIR} \
		--without-perl \
		--without-debug \
		--without-readline \
		--without-bench
.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=--enable-assembler
.endif
CONFIGURE_ENV+=	PERL=${PERL} \
		PERL5=${PERL} \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		CONFIGURE_ARGS="${CONFIGURE_ARGS}"

# MySQL-Server part
.if !defined(CLIENT_ONLY)
RUN_DEPENDS=	mysql:${PORTSDIR}/databases/mysql322-client

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 320000
.if defined(MIT_PTHREADS)
CONFIGURE_ARGS+=	--with-mit-threads=yes

pre-fetch:
	@${ECHO}
	@${ECHO} "Using supplied mit-pthreads."
	@${ECHO}
.else
CONFIGURE_ARGS+=	--with-mit-threads=no

pre-fetch:
	@${ECHO}
	@${ECHO} "Using native FreeBSD threads (libc_r)."
	@${ECHO}
	@${ECHO} "You may set MIT_PTHREADS (make MIT_PTHREADS=yes)"
	@${ECHO} "to compile mysql with the supplied mit-pthreads."
	@${ECHO} "(You don't want to set this unless you have a good reason)."
	@${ECHO}
.endif
.elif ${OSVERSION} >= 300000
.if defined(NATIVE_THREADS)
CONFIGURE_ARGS+=	--with-mit-threads=no

pre-fetch:
	@${ECHO}
	@${ECHO} "Using native FreeBSD threads (libc_r)."
	@${ECHO}
.else
CONFIGURE_ARGS+=	--with-mit-threads=yes

pre-fetch:
	@${ECHO}
	@${ECHO} "Using supplied mit-pthreads."
	@${ECHO}
	@${ECHO} "You may set NATIVE_THREADS (make NATIVE_THREADS=yes)"
	@${ECHO} "to compile mysql with the native FreeBSD threads (libc_r)."
	@${ECHO} "Warning: There are some bugs in libc_r which prevent"
	@${ECHO} "         'mysqladmin shutdown' from working properly and"
	@${ECHO} "         killing mysqld might not work."
	@${ECHO}
.endif
.else
CONFIGURE_ARGS+=	--with-mit-threads=yes

pre-fetch:
	@${ECHO}
	@${ECHO} "Using supplied mit-pthreads."
	@${ECHO}
.endif

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
	${MKDIR} ${PREFIX}/share/doc/mysql/Img
.for doc in manual.html manual.ps manual_toc.html manual.txt manual.texi include.texi
	${INSTALL_DATA} ${WRKSRC}/Docs/${doc} ${PREFIX}/share/doc/mysql
.endfor
	${INSTALL_DATA} ${WRKSRC}/Docs/Img/*.gif ${PREFIX}/share/doc/mysql/Img
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info
	@install-info ${PREFIX}/info/mysql.info ${PREFIX}/info/dir
.endif

.include <bsd.port.post.mk>

# MySQL-Client part
.else
MAN1=		mysql.1

CONFIGURE_ARGS+=--without-server
MAKE_ENV=	CLIENT_ONLY="${CLIENT_ONLY}"

post-install:
	@${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/mysql-client.sh
	@${ECHO} "" >> ${PREFIX}/etc/rc.d/mysql-client.sh
	@${ECHO} "${LDCONFIG} -m ${PREFIX}/lib/mysql" >> ${PREFIX}/etc/rc.d/mysql-client.sh
	@${CHMOD} 750 ${PREFIX}/etc/rc.d/mysql-client.sh

	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib/mysql

.include <bsd.port.mk>
.endif
