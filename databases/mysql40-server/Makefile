# ports collection makefile for:	mySQL
# Version required:			v3.20.32a
# Date created:				28 Oct 1997
# Whom:					Josh Tiefenbach <josh@ican.net>
#
# $Id: Makefile,v 1.10 1997/11/18 19:05:12 jfitz Exp $
#

DISTNAME=	mysql-3.20.32a
CATEGORIES=	databases
MASTER_SITES=	http://www.tcx.se/ \
		http://www.buoy.com/mysql/ \
		http://web.tryc.on.ca/mysql/

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
.for doc in mysql-faq.html mysql-faq.ps mysql-faq_toc.html mysql-faq.txt mysql-faq.texi
	${INSTALL_DATA} ${WRKSRC}/FAQs/${doc} ${PREFIX}/share/doc/mysql
.endfor

.include <bsd.port.mk>
