# $FreeBSD$

PORTNAME=	MooseX-LazyRequire
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Required attributes which fail only when trying to use them

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=0.94:devel/p5-Moose \
		p5-aliased>=0.30:devel/p5-aliased \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
