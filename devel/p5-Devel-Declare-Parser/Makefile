# $FreeBSD$

PORTNAME=	Devel-Declare-Parser
PORTVERSION=	0.020
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for higher level interface to Devel-Declare

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-B-Compiling>=0.02:devel/p5-B-Compiling \
	p5-B-Hooks-EndOfScope>=0.08:devel/p5-B-Hooks-EndOfScope \
	p5-Devel-Declare>=0.006:devel/p5-Devel-Declare
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception-LessClever>=0:devel/p5-Test-Exception-LessClever

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	YES

.include <bsd.port.mk>
