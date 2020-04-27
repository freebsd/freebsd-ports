# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MooX-TypeTiny
PORTVERSION=	0.002002
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Optimized type checks for Moo + Type::Tiny

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Moo>=2.004000:devel/p5-Moo \
		p5-Type-Tiny>=1.008000:devel/p5-Type-Tiny
TEST_DEPENDS=	p5-Test-Fatal>=0.003:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
