# New ports collection makefile for:	bind
# Date created:				6 October 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	bind
PORTVERSION=	9.0.0
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.isc.org/isc/bind9/${PORTVERSION}/ \
		ftp://ftp.sunet.se/pub/network/isc/bind9/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes

MAN1=	host.1
MAN5=	rndc.conf.5
MAN8=	lwresd.8 named.8 nsupdate.8 rndc.8 dnssec-keygen.8 dnssec-makekeyset.8 \
	dnssec-signkey.8 dnssec-signzone.8

post-install:
.for NUM in 1 5 8
	${INSTALL_MAN} ${WRKSRC}/doc/man/bin/*.${NUM} ${MANPREFIX}/man/man${NUM}
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/man/dnssec/* ${MANPREFIX}/man/man8

.include <bsd.port.mk>
