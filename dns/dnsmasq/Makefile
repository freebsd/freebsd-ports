# New ports collection makefile for:	dnsmasq
# Date created:				1 June 2003
# Whom:					Steven Honson <steven@honson.org>
#
# $FreeBSD$
#

PORTNAME=	dnsmasq
PORTVERSION=	2.2
CATEGORIES=	dns
MASTER_SITES=	http://www.thekelleys.org.uk/dnsmasq/

MAINTAINER=	steven@honson.org
COMMENT=	A caching DNS forwarder

USE_REINPLACE=	yes

MAN8=		dnsmasq.8
PLIST_FILES=	sbin/dnsmasq

post-patch:
	@${REINPLACE_CMD} -e \
	's|^CC = gcc|CC?=cc|g ; \
	s|^CFLAGS = -O2|CFLAGS+=-O2|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dnsmasq ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/dnsmasq.conf.example ${PREFIX}/etc/dnsmasq.conf.example
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
