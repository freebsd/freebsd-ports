# New ports collection makefile for:	dnsmasq
# Date created:				1 June 2003
# Whom:					Steven Honson <shonson@isoproplex.net>
#
# $FreeBSD$
#

PORTNAME=	dnsmasq
PORTVERSION=	1.12
CATEGORIES=	net
MASTER_SITES=	http://www.thekelleys.org.uk/dnsmasq/

MAINTAINER=	shonson@isoproplex.net
COMMENT=	A caching DNS forwarder

.if defined(WITH_IPV6)
CFLAGS +=	-DWITH_IPV6
.endif

MAN8=	dnsmasq.8

pre-fetch:
.if !defined(WITH_IPV6)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Define WITH_IPV6 to build dnsmasq with IPv6 support."
	@${ECHO_CMD} ""
.endif

.include <bsd.port.mk>
