# New ports collection makefile for:	dnstop
# Date created:		31 October 2002
# Whom:			fenner
#
# $FreeBSD$

PORTNAME=	dnstop
PORTVERSION=	20030124
CATEGORIES=	dns
MASTER_SITES=	http://dnstop.measurement-factory.com/src/

MAINTAINER=	fenner@FreeBSD.Org
COMMENT=	Captures and analyzes DNS traffic (or analyzes libpcap dump)

NO_WRKSUBDIR=	true

MAN8=		dnstop.8
PLIST_FILES=	bin/dnstop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnstop ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dnstop.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
