# $FreeBSD$

PORTNAME=	Log-Dispatch-Screen-Color
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to support color for Log::Dispatch::Screen

RUN_DEPENDS=	\
	p5-Log-Dispatch>0:devel/p5-Log-Dispatch \
	p5-Params-Validate>0:devel/p5-Params-Validate
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-IO-stringy>0:devel/p5-IO-stringy

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
