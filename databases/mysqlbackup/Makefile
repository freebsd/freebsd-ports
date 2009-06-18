# New ports collection makefile for:	mysqlbackup
# Date created:				Sun 07 Jun 2009
# Whom:					Alexey V. Degtyarev
#
# $FreeBSD$
#

PORTNAME=	mysqlbackup
PORTVERSION=	2.2
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Program to create everyday MySQL-database servers backup

USE_MYSQL=	yes
NO_BUILD=	yes

MAN1=		mysqlbackup.1
PLIST_FILES=	bin/mysqlbackup

do-install:
	${INSTALL_MAN} ${WRKSRC}/mysqlbackup.1 ${MAN1PREFIX}/man/man1/mysqlbackup.1
	${INSTALL_SCRIPT} ${WRKSRC}/mysqlbackup ${PREFIX}/bin/mysqlbackup

.include <bsd.port.mk>
