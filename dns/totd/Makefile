# New ports collection makefile for:   totd
# Date created:        17 Nov 2000
# Whom:                Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	totd
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/Vermicelli/

MAINTAINER=	ports@FreeBSD.org

MAN8=		totd.8

GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA} ${FILESDIR}/totd.conf.sample ${PREFIX}/etc

.include <bsd.port.mk>
