# ports collection makefile for:	MySQL
# Version required:			v3.22.13-beta
# Date created:				26 Jan 1998
# Whom:					Josh Tiefenbach <josh@ican.net>
#
# $Id: Makefile,v 1.41 1999/02/07 22:35:56 dirk Exp $
#

DISTNAME=	mysql-3.22.16a-gamma
PKGNAME=	mysql-3.22.16g
CATEGORIES=	databases
MASTER_SITES=	http://www.fh-wolfenbuettel.de/ftp/pub/database/mysql/Downloads/MySQL-3.22/ \
		ftp://ftp.digex.net/pub/database/mysql/Downloads/MySQL-3.22/ \
		ftp://ftp.bse.bg/pub/Unix/database/MySQL/ \
		ftp://ftp.plig.net/pub/mysql/Downloads/MySQL-3.22/ \
		ftp://ftp.sunet.se/pub/unix/databases/relational/mysql/Downloads/MySQL-3.22/

MAINTAINER=	dirk@FreeBSD.ORG

MAN1=		mysql.1

USE_PERL5=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--localstatedir=/var/db/mysql \
		--without-perl \
		--without-debug \
		--without-readline \
		--without-bench
CONFIGURE_ENV+=	PERL=${PERL5} \
		PERL5=${PERL5} \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		CXXFLAGS="${CFLAGS}"

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
	@${ECHO} "are still to buggy to use with mysql."
	@${ECHO} "Using mit-pthreads."
	@${ECHO}
.endif

pre-install:
.if !defined(PACKAGE_BUILDING)
	@ ${SETENV} ${MAKE_ENV} ${PERL5} ${SCRIPTDIR}/check_old_version
.endif

post-install:
	${MKDIR} ${PREFIX}/share/mysql/mysql
.if !defined(PACKAGE_BUILDING)
	${PREFIX}/bin/mysql_install_db
.endif
	@ ${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/mysql.sh
	@ ${ECHO} "#" >> ${PREFIX}/etc/rc.d/mysql.sh
	@ ${ECHO} "" >> ${PREFIX}/etc/rc.d/mysql.sh
	@ ${ECHO} "/sbin/ldconfig -m ${PREFIX}/lib/mysql" >> ${PREFIX}/etc/rc.d/mysql.sh
	@ ${ECHO} "" >> ${PREFIX}/etc/rc.d/mysql.sh
	@ ${ECHO} "if [ -x ${PREFIX}/bin/safe_mysqld ]" >> ${PREFIX}/etc/rc.d/mysql.sh
	@ ${ECHO} "then" >> ${PREFIX}/etc/rc.d/mysql.sh
	@ ${ECHO} "	${PREFIX}/bin/safe_mysqld > /dev/null & && ${ECHO} -n ' mysql'" >> ${PREFIX}/etc/rc.d/mysql.sh
	@ ${ECHO} "fi" >> ${PREFIX}/etc/rc.d/mysql.sh
	@ /bin/chmod 750 ${PREFIX}/etc/rc.d/mysql.sh

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mysql
.for doc in manual.html manual.ps manual_toc.html manual.txt manual.texi include.texi
	${INSTALL_DATA} ${WRKSRC}/Docs/${doc} ${PREFIX}/share/doc/mysql
.endfor
	@if [ ! -f ${PREFIX}/info/dir -a -f /usr/share/info/dir ]; then \
		${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info
	@install-info ${PREFIX}/info/mysql.info ${PREFIX}/info/dir
.endif

	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib/mysql

.include <bsd.port.post.mk>
