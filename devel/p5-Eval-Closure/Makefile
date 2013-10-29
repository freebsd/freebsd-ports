# $FreeBSD$

PORTNAME=	Eval-Closure
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DOY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Safely and cleanly create closures via string eval

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Devel-LexAlias>=0.05:${PORTSDIR}/devel/p5-Devel-LexAlias \
		p5-PadWalker>=0:${PORTSDIR}/devel/p5-PadWalker \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Output>=0:${PORTSDIR}/devel/p5-Test-Output \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
