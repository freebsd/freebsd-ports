# ports collection makefile for:	mySQL
# Version required:			v3.21.21
# Date created:				26 Jan 1998
# Whom:					Josh Tiefenbach <josh@ican.net>
#
# $Id: Makefile,v 1.14 1998/01/13 04:48:26 asami Exp $
#

DISTNAME=	mysql-3.21.21a-beta
PKGNAME=	mysql-3.21.21b
CATEGORIES=	databases
MASTER_SITES=	http://www.buoy.com/mysql/Downloads/MySQL-3.21/ \
					http://mysql.polaris.ca/Downloads/MySQL-3.21/ \
					http://www.tcx.se/Downloads/MySQL-3.21/ 
MAINTAINER=	josh@ican.net

USE_GMAKE=	YES
USE_PERL5=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--localstatedir=/var/db/mysql \
		--with-MAKE=gmake \
		--without-perl \
		--without-debug \
		--without-readline
CONFIGURE_ENV+=	PERL=${PREFIX}/bin/perl INSTALL_SCRIPT="${INSTALL_SCRIPT}"

pre-install:
.if defined(PACKAGE_BUILDING)
	@ ${RM} -rf /var/db/mysql
.endif
	@ ${SETENV} ${MAKE_ENV} /usr/bin/perl ${SCRIPTDIR}/check_old_version

post-install:
	cd ${WRKSRC} && ${WRKSRC}/scripts/mysql_install_db
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

.include <bsd.port.mk>
