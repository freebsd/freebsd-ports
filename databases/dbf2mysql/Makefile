# New ports collection makefile for:	dbf2mysql
# Date created:				02 October 1999
# Whom:					jedgar@fxp.org
#
# $FreeBSD$
#

PORTNAME=	dbf2mysql
PORTVERSION=	1.13
CATEGORIES=	databases
MASTER_SITES=	http://www.mysql.com/Contrib/
EXTRACT_SUFX=	.tgz

MAINTAINER=jedgar@fxp.org

LIB_DEPENDS=	mysqlclient.6:${PORTSDIR}/databases/mysql322-client

NO_WRKSUBDIR=	yes

do-configure:
	@${MV} ${WRKDIR}/Makefile ${WRKDIR}/Makefile.orig
	@${SED} -e 's|/usr/local/mysql/include|${PREFIX}/include/mysql|' \
		-e 's|/usr/local/mysql/lib|${PREFIX}/lib/mysql|' \
		< ${WRKDIR}/Makefile.orig > ${WRKDIR}/Makefile
do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/dbf2mysql ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/mysql2dbf ${PREFIX}/bin

.include <bsd.port.mk>
