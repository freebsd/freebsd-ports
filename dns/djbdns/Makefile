# New ports collection makefile for: dnscache
# Date created:		24 Jan 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	djbdns
PORTVERSION=	1.05
CATEGORIES=	net
MASTER_SITES=	http://cr.yp.to/djbdns/ \
		ftp://cr.yp.to/djbdns/

MAINTAINER=	nbm@FreeBSD.org

RUN_DEPENDS=	setuidgid:${PORTSDIR}/sysutils/daemontools

ALL_TARGET=	it
INSTALL_TARGET=	setup check

NO_PACKAGE=	Forbidden - we have patches to the distribution.

post-patch:
	@echo "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@echo "${CC} -s" > ${WRKSRC}/conf-ld
	@echo "${PREFIX}" > ${WRKSRC}/conf-home

.include <bsd.port.mk>
