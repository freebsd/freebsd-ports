# $FreeBSD$

PORTNAME=	MooseX-Types-LoadableClass
PORTVERSION=	0.015
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ETHER
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	ClassName type constraint with coercion to load the class

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-Types>=0.42:devel/p5-MooseX-Types \
		p5-namespace-clean>=0:devel/p5-namespace-clean
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Moose>=0:devel/p5-Moose \
		p5-namespace-clean>=0:devel/p5-namespace-clean

USES=		perl5
USE_PERL5=	modbuildtiny
NO_ARCH=	yes

.include <bsd.port.mk>
