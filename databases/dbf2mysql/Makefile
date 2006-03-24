# New ports collection makefile for:	dbf2mysql
# Date created:				02 October 1999
# Whom:					jedgar@fxp.org
#
# $FreeBSD$
#

PORTNAME=	dbf2mysql
PORTVERSION=	1.14
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://mirror.etf.bg.ac.yu/mysql/Downloads/Contrib/ \
		ftp://ftp.ciril.fr/pub/sgbd/mysql/Downloads/Contrib

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programs to convert .dbf files to MySQL tables and vice versa

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client

PORTDOCS=	README

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dbf2mysql ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mysql2dbf ${PREFIX}/bin
	-${MKDIR} ${PREFIX}/share/doc/dbf2mysql
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dbf2mysql

.include <bsd.port.mk>
