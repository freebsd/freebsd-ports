# ex:ts=8
# Ports collection makefile for:	tinycdb
# Date created:			Oct 17, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tinycdb
PORTVERSION=	0.72
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.corpit.ru/pub/tinycdb/

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
USE_GMAKE=	yes

MAN1=	cdb.1
MAN3=	cdb.3
MAN5=	cdb.5

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g" \
		-e "s|^CC|#CC|" -e "s|^CFLAGS|#CFLAGS|" ${WRKSRC}/Makefile

.include <bsd.port.mk>
