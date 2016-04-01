# $FreeBSD$

PORTNAME=	Class-Method-Modifiers-Fast
PORTVERSION=	0.041
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to provide Moose-like method modifiers

RUN_DEPENDS=	\
	p5-Data-Util>=0.55:devel/p5-Data-Util
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Sub-Uplevel>=0.18:devel/p5-Sub-Uplevel

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
