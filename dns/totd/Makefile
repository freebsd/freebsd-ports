# New ports collection makefile for:   totd
# Date created:        17 Nov 2000
# Whom:                Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	totd
PORTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/Vermicelli/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	DNS proxy that supports IPv6 <==> IPv4 record translation

MAN8=		totd.8

GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA} ${FILESDIR}/totd.conf.sample ${PREFIX}/etc
	@${SED} 's@%PREFIX%@${LOCALBASE}@g' ${FILESDIR}/totd.sh > ${PREFIX}/etc/rc.d/totd.sh
	@${CHMOD} +x ${PREFIX}/etc/rc.d/totd.sh

.include <bsd.port.mk>
