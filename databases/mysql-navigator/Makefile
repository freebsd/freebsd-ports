# New ports collection makefile for:	mysql-navigator
# Date created:				2 June 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mysql-navigator
PORTVERSION=	1.2.4
CATEGORIES=	databases kde
MASTER_SITES=	http://sql.kldp.org/snapshots/ \
		ftp://sise15.mizi.com/pub/
DISTNAME=	mysqlnavigator-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client

USE_KDELIBS_VER=2
INSTALLS_SHLIB=	yes

MYSQL_NAV_HOME=	${PREFIX}/share/mysql_navigator

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/bin/mysql_navigator ${PREFIX}/bin/
	@ ${INSTALL_DATA} ${WRKSRC}/lib/libmysqlui.* ${PREFIX}/lib/
	@ ${MKDIR} ${MYSQL_NAV_HOME}/po
	@ ${INSTALL_DATA} ${WRKSRC}/po/* ${MYSQL_NAV_HOME}/po/
	@ ${MKDIR} ${MYSQL_NAV_HOME}/pics
	@ ${INSTALL_DATA} ${WRKSRC}/pics/* ${MYSQL_NAV_HOME}/pics/

.include <bsd.port.mk>
