# ports collection makefile for:	mySQL
# Version required:			v3.21.33
# Date created:				14 Aug 1998
# Whom:					Josh Tiefenbach <josh@ican.net>
#
# $Id: Makefile,v 1.21 1998/04/29 01:10:01 jseger Exp $
#

DISTNAME=	mysql-3.21.33
PKGNAME=	mysql-3.21.33
CATEGORIES=	databases
MASTER_SITES=	http://www.buoy.com/mysql/Downloads/ \
		http://mysql.bluep.com/Downloads/ \
		http://mysql.polaris.ca/Downloads/MySQL-3.21/ \
		http://www.fh-wolfenbuettel.de/ftp/pub/database/mysql/Downloads/MySQL-3.21/ \
		http://www.tcx.se/Downloads/MySQL-3.21/

MAINTAINER=	josh@ican.net

MAN1=		mysql.1

USE_GMAKE=	YES
USE_PERL5=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--localstatedir=/var/db/mysql \
		--with-MAKE=gmake \
		--without-perl \
		--without-debug \
		--without-readline \
		--without-bench
CONFIGURE_ENV+=	PERL=${PREFIX}/bin/perl INSTALL_SCRIPT="${INSTALL_SCRIPT}"

pre-install:
.if defined(PACKAGE_BUILDING)
	@ ${RM} -rf /var/db/mysql
.endif
	@ ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl ${SCRIPTDIR}/check_old_version

post-install:
	${MKDIR} ${PREFIX}/share/mysql/mysql
	${CP} ${WRKSRC}/data/mysql/*.frm ${PREFIX}/share/mysql/mysql
	${WRKSRC}/scripts/mysql_install_db
	@ /usr/bin/killall mysqld
	@ ${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/mysql.sh
	@ ${ECHO} "#" >> ${PREFIX}/etc/rc.d/mysql.sh
	@ ${ECHO} "" >> ${PREFIX}/etc/rc.d/mysql.sh
	@ ${ECHO} "if [ -x ${PREFIX}/bin/safe_mysqld ]" >> ${PREFIX}/etc/rc.d/mysql.sh
	@ ${ECHO} "then" >> ${PREFIX}/etc/rc.d/mysql.sh
	@ ${ECHO} "	${PREFIX}/bin/safe_mysqld & && ${ECHO} -n ' mysql'" >> ${PREFIX}/etc/rc.d/mysql.sh
	@ ${ECHO} "fi" >> ${PREFIX}/etc/rc.d/mysql.sh
	@ /bin/chmod 750 ${PREFIX}/etc/rc.d/mysql.sh
	${MKDIR} ${PREFIX}/share/doc/mysql
.for doc in manual.html manual.ps manual_toc.html manual.txt manual.texi include.texi
	${INSTALL_DATA} ${WRKSRC}/Docs/${doc} ${PREFIX}/share/doc/mysql
.endfor
	@if [ ! -f ${PREFIX}/info/dir -a -f /usr/share/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info
	@install-info ${PREFIX}/info/mysql.info ${PREFIX}/info/dir

.include <bsd.port.mk>
