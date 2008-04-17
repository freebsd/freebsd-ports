# New ports collection makefile for:	p5-Net-DAAP-DMAP
# Date created:		2004-08-08
# Whom:			Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-DAAP-DMAP
PORTVERSION=	1.26
PORTREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Perl module for reading and writing DAAP structures

RUN_DEPENDS=	${SITE_PERL}/Math/BigInt.pm:${PORTSDIR}/math/p5-Math-BigInt
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Net::DAAP::DMAP.3

.include <bsd.port.mk>
