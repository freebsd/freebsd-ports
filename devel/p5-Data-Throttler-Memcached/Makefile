# New ports collection makefile for:	p5-Data-Throttler-Memcached
# Date created:		2008-01-30
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	Data-Throttler-Memcached
PORTVERSION=	0.00003
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Memcached-Based Data::Throttler

BUILD_DEPENDS=	p5-Cache-Memcached-Managed>=0:${PORTSDIR}/databases/p5-Cache-Memcached-Managed \
		p5-Data-Throttler>=0:${PORTSDIR}/devel/p5-Data-Throttler \
		p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS=	p5-Cache-Memcached-Managed>=0:${PORTSDIR}/databases/p5-Cache-Memcached-Managed \
		p5-Data-Throttler>=0:${PORTSDIR}/devel/p5-Data-Throttler \
		p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor

PERL_CONFIGURE=	yes

MAN3=		Data::Throttler::Memcached.3 \
		Data::Throttler::BucketChain::Memcached.3

.include <bsd.port.mk>
