# ports collection makefile for:	mySQL
# Version required:			v3.20.31d
# Date created:				9 Oct 1997
# Whom:					Josh Tiefenbach <josh@ican.net>
#
# $Id: Makefile,v 1.3 1997/09/05 20:23:04 jfitz Exp $
#

DISTNAME=	mysql-3.20.31d
CATEGORIES=	databases
MASTER_SITES=	http://www.tcx.se/ \
		http://www.buoy.com/mysql/ \
		http://web.tryc.on.ca/mysql/ \
		http://mysql.staufen.de/ \
		http://mysql.acer.net/

MAINTAINER=	josh@ican.net

RUN_DEPENDS=	perl5.00401:${PORTSDIR}/lang/perl5

USE_GMAKE=	YES
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
	@ echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/mysql.sh
	@ echo "#" >> ${PREFIX}/etc/rc.d/mysql.sh
	@ echo "" >> ${PREFIX}/etc/rc.d/mysql.sh
	@ echo "if [ -x /usr/local/bin/safe_mysqld ]" >> ${PREFIX}/etc/rc.d/mysql.sh
	@ echo "then" >> ${PREFIX}/etc/rc.d/mysql.sh
	@ echo "	/usr/local/bin/safe_mysqld & && echo -n ' mysql'" >> ${PREFIX}/etc/rc.d/mysql.sh
	@ echo "fi" >> ${PREFIX}/etc/rc.d/mysql.sh
	@ /bin/chmod 750 ${PREFIX}/etc/rc.d/mysql.sh
	${MKDIR} ${PREFIX}/share/doc/mysql
.for doc in mysql-faq.html mysql-faq.ps mysql-faq_toc.html mysql-faq.txt mysql-faq.texi
	${INSTALL_DATA} ${WRKSRC}/FAQs/${doc} ${PREFIX}/share/doc/mysql
.endfor

.include <bsd.port.mk>
