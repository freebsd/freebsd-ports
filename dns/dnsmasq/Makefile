# New ports collection makefile for:	dnsmasq
# Date created:				1 June 2003
# Whom:					Steven Honson <shonson@isoproplex.net>
#
# $FreeBSD$
#

PORTNAME=	dnsmasq
PORTVERSION=	1.18
CATEGORIES=	dns
MASTER_SITES=	http://www.thekelleys.org.uk/dnsmasq/

MAINTAINER=	shonson@isoproplex.net
COMMENT=	A caching DNS forwarder

USE_REINPLACE=	yes

MAN8=	dnsmasq.8

post-patch:
	@${REINPLACE_CMD} -e \
	's|^CC = gcc|CC?=cc|g ; \
	s|^CFLAGS = -O2|CFLAGS+=-O2|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
