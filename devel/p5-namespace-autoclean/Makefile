# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	namespace-autoclean
PORTVERSION=	0.28
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Keep imports out of your namespace

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-B-Hooks-EndOfScope>=0.12:devel/p5-B-Hooks-EndOfScope \
		p5-Sub-Identify>=0:devel/p5-Sub-Identify \
		p5-namespace-clean>=0.20:devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Moo>=0:devel/p5-Moo \
		p5-Moose>=2:devel/p5-Moose \
		p5-Mouse>=0:devel/p5-Mouse \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Requires>=0:devel/p5-Test-Requires \
		p5-Test-Spelling>0.12:devel/p5-Test-Spelling

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
