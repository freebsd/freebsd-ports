# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Specio
PORTVERSION=	0.14
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DROLSKY
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Type constraints and coercions for Perl

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Class-Load>=0:devel/p5-Class-Load \
		p5-Class-Method-Modifiers>=0:devel/p5-Class-Method-Modifiers \
		p5-Devel-PartialDump>=0:devel/p5-Devel-PartialDump \
		p5-Devel-StackTrace>=0:devel/p5-Devel-StackTrace \
		p5-Eval-Closure>=0:devel/p5-Eval-Closure \
		p5-Lingua-EN-Inflect>=0:textproc/p5-Lingua-EN-Inflect \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Moo>=0:devel/p5-Moo \
		p5-Params-Util>=0:devel/p5-Params-Util \
		p5-Role-Tiny>=0:devel/p5-Role-Tiny \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Requires>=0:devel/p5-Test-Requires \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502000
BUILD_DEPENDS+=	p5-Scalar-List-Utils>=1.33:lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	p5-Scalar-List-Utils>=1.33:lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
