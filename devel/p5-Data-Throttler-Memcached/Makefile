# Created by: Masahiro Teramoto <markun@onohara.to>
# $FreeBSD$

PORTNAME=	Data-Throttler-Memcached
PORTVERSION=	0.00003
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Memcached-Based Data::Throttler

BUILD_DEPENDS=	p5-Cache-Memcached-Managed>=0:databases/p5-Cache-Memcached-Managed \
		p5-Data-Throttler>=0:devel/p5-Data-Throttler \
		p5-Class-Accessor>0:devel/p5-Class-Accessor
RUN_DEPENDS=	p5-Cache-Memcached-Managed>=0:databases/p5-Cache-Memcached-Managed \
		p5-Data-Throttler>=0:devel/p5-Data-Throttler \
		p5-Class-Accessor>0:devel/p5-Class-Accessor

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
