# New ports collection makefile for:   postgresql-relay
# Date created:        14 February 2003
# Whom:                Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	postgresql-relay
PORTVERSION=	1.2.1
CATEGORIES=	databases net
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Multiplex multiple PostgreSQL databases to one relay

MAN8=		postgresql-relay.8
PLIST_FILES=	bin/postgresql-relay etc/postgresql-relay.conf-sample

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/postgresql-relay ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/postgresql-relay.conf ${PREFIX}/etc/postgresql-relay.conf-sample
	${INSTALL_MAN} ${WRKSRC}/postgresql-relay.8 ${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
