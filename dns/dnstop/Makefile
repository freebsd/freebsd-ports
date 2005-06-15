# New ports collection makefile for:	dnstop
# Date created:		31 October 2002
# Whom:			fenner
#
# $FreeBSD$

PORTNAME=	dnstop
PORTVERSION=	20050405
CATEGORIES=	dns
MASTER_SITES=	http://dns.measurement-factory.com/tools/dnstop/src/

MAINTAINER=	mark@foster.cc
COMMENT=	Captures and analyzes DNS traffic (or analyzes libpcap dump)

MAN8=		dnstop.8
PLIST_FILES=	bin/dnstop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnstop ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dnstop.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
