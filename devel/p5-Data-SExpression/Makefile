# $FreeBSD$

PORTNAME=	Data-SExpression
PORTVERSION=	0.41
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to parse lisp S-expressions into perl data structures

RUN_DEPENDS=	\
	p5-Class-Accessor>0:devel/p5-Class-Accessor
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
