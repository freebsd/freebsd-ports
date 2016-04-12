# $FreeBSD$

PORTNAME=	Data-Thunk
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FLORA
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Lazy/deferred evaluation - a sneakier Scalar::Defer

BUILD_DEPENDS=	p5-Check-ISA>=0:devel/p5-Check-ISA \
		p5-Data-Swap>=0:devel/p5-Data-Swap \
		p5-Devel-Refcount>=0:devel/p5-Devel-Refcount \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-UNIVERSAL-ref>=0:devel/p5-UNIVERSAL-ref \
		p5-namespace-clean>=0:devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
