# New ports collection makefile for:	mysql-navigator
# Date created:				2 June 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mysql-navigator
PORTVERSION=	0.7.5
CATEGORIES=	databases kde
MASTER_SITES=	http://sql.kldp.org/snapshots/ \
		ftp://sise15.mizi.com/pub/
DISTNAME=	mysql_navigator_${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client

USE_KDELIBS_VER=2
INSTALLS_SHLIB=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/mysql_navigator ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/lib/libmysqlnavigator.* ${PREFIX}/lib/

.include <bsd.port.mk>
