# New ports collection makefile for:	dbf2mysql
# Date created:				02 October 1999
# Whom:					jedgar@fxp.org
#
# $FreeBSD$
#

PORTNAME=	dbf2mysql
PORTVERSION=	1.14
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.ntu.edu.tw/pub/MySQL/Downloads/Contrib/Old-Versions/ \
		ftp://ftp.ip.pt/pub/mysql/Downloads/Contrib/Old-Versions/ \
		ftp://ftp.chu.edu.tw/Mirrors/www.mysql.com/Downloads/Contrib/ \
		ftp://ftp.ps.pl/dsk0/ftp.mysql.com/Downloads/Contrib/Old-Versions/ \
		ftp://mir1.ovh.net/ftp.mysql.com/Downloads/Contrib/Old-Versions/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programs to convert .dbf files to MySQL tables and vice versa

USE_MYSQL=	yes

PORTDOCS=	README

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dbf2mysql ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mysql2dbf ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	-${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
