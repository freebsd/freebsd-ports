# $FreeBSD$

PORTNAME=	Params-ValidationCompiler
PORTVERSION=	0.21
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Build an optimized subroutine parameter validator once, use it forever

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Exception-Class>=0:devel/p5-Exception-Class \
		p5-Eval-Closure>=0:devel/p5-Eval-Closure
RUN_DEPENDS=	p5-Exception-Class>=0:devel/p5-Exception-Class \
		p5-Eval-Closure>=0:devel/p5-Eval-Closure \
		p5-Specio>=0.14:devel/p5-Specio
TEST_DEPENDS=	p5-Test2-Suite>=0:devel/p5-Test2-Suite \
		p5-Test2-Plugin-NoWarnings>=0:devel/p5-Test2-Plugin-NoWarnings \
		p5-Test-Without-Module>=0:devel/p5-Test-Without-Module

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
