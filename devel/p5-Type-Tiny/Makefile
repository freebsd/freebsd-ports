# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Type-Tiny
PORTVERSION=	1.010001
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOBYINK
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tiny, yet Moo(se)-compatible type constraint

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Exporter-Tiny>=1.000000:devel/p5-Exporter-Tiny
TEST_DEPENDS=	p5-Class-InsideOut>=0:devel/p5-Class-InsideOut \
		p5-Function-Parameters>=0:devel/p5-Function-Parameters \
		p5-JSON>=0:converters/p5-JSON \
		p5-Moo>=1.006000:devel/p5-Moo \
		p5-Moose>=2.0000:devel/p5-Moose \
		p5-MooseX-Types>=0:devel/p5-MooseX-Types \
		p5-MooseX-Types-Common>=0:devel/p5-MooseX-Types-Common \
		p5-Mouse>=1.00:devel/p5-Mouse \
		p5-MouseX-Types>=0:devel/p5-MouseX-Types \
		p5-Role-Tiny>=0:devel/p5-Role-Tiny \
		p5-Sub-Exporter-Lexical>=0:devel/p5-Sub-Exporter-Lexical \
		p5-Test-LeakTrace>=0:devel/p5-Test-LeakTrace \
		p5-Test-Requires>=0:devel/p5-Test-Requires \
		p5-Test-Warnings>=0:devel/p5-Test-Warnings \
		p5-Validation-Class>=0:devel/p5-Validation-Class \
		p5-match-simple>=0:devel/p5-match-simple

OPTIONS_DEFINE=	RECOMMENDED
OPTIONS_DEFAULT=RECOMMENDED
RECOMMENDED_DESC=	Recommended dependencies by upstream

PORTSCOUT=	limit:^[0-9\.]*$$

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

RECOMMENDED_BUILD_DEPENDS=	p5-Devel-StackTrace>=0:devel/p5-Devel-StackTrace \
				p5-Ref-Util-XS>=0.100:devel/p5-Ref-Util-XS \
				p5-Type-Tie>=0:devel/p5-Type-Tie \
				p5-Type-Tiny-XS>=0.016:devel/p5-Type-Tiny-XS
RECOMMENDED_RUN_DEPENDS=	p5-Devel-StackTrace>=0:devel/p5-Devel-StackTrace \
				p5-Ref-Util-XS>=0.100:devel/p5-Ref-Util-XS \
				p5-Type-Tie>=0:devel/p5-Type-Tie \
				p5-Type-Tiny-XS>=0.016:devel/p5-Type-Tiny-XS

.include <bsd.port.mk>
