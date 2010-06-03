# New ports collection makefile for:	mysqlsniffer
# Date created:		26 May 2010
# Whom:			Frederic Hardy <frederic.hardy@mageekbox.net>
#
# $FreeBSD$
#

PORTNAME=	mysqlsniffer
PORTVERSION=	1.2
CATEGORIES=	databases
MASTER_SITES=	http://hackmysql.com/code/
DISTNAME=	mysqlsniffer
EXTRACT_SUFX=	.tgz

MAINTAINER=	frederic.hardy@mageekbox.net
COMMENT=	Tcpdump clone specifically for MySQL

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/mysqlsniffer

do-build:
	${CC} -lpcap -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/mysqlsniffer.c ${WRKSRC}/packet_handlers.c ${WRKSRC}/misc.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
