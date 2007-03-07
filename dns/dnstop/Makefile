# New ports collection makefile for:	dnstop
# Date created:		31 October 2002
# Whom:			fenner
#
# $FreeBSD$

PORTNAME=	dnstop
PORTVERSION=	20070219
CATEGORIES=	dns ipv6
MASTER_SITES=	http://dns.measurement-factory.com/tools/dnstop/src/

MAINTAINER=	mark@foster.cc
COMMENT=	Captures and analyzes DNS traffic (or analyzes libpcap dump)

USE_GCC=	3.4+

MAN8=		dnstop.8
PLIST_FILES=	bin/dnstop

post-patch:
	${REINPLACE_CMD} -e 's|^CFLAGS=|CFLAGS\?=|' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|^CC=|CC\?=|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnstop ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dnstop.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
