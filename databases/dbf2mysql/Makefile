# New ports collection makefile for:	dbf2mysql
# Date created:				02 October 1999
# Whom:					jedgar@fxp.org
#
# $FreeBSD$
#

PORTNAME=	dbf2mysql
PORTVERSION=	1.14
CATEGORIES=	databases
MASTER_SITES=	http://download.sourceforge.net/pub/mirrors/mysql/Downloads/Contrib/

MAINTAINER=	jedgar@FreeBSD.org

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dbf2mysql ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mysql2dbf ${PREFIX}/bin

.include <bsd.port.mk>
