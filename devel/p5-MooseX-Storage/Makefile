# Created by: chinsan
# $FreeBSD$

PORTNAME=	MooseX-Storage
PORTVERSION=	0.53
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Serialization framework for Moose classes

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-JSON-MaybeXS>=1.001000:converters/p5-JSON-MaybeXS \
		p5-Moose>=0.99:devel/p5-Moose \
		p5-String-RewritePrefix>=0.004:textproc/p5-String-RewritePrefix \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
TEST_DEPENDS=	p5-IO-Stringy>=0:devel/p5-IO-Stringy \
		p5-JSON-XS>=0:converters/p5-JSON-XS \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-JSON>=0.06:devel/p5-Test-JSON \
		p5-Test-Needs>=0:devel/p5-Test-Needs \
		p5-Test-Without-Module>=0:devel/p5-Test-Without-Module \
		p5-YAML>=0:textproc/p5-YAML \
		p5-YAML-LibYAML>=0:textproc/p5-YAML-LibYAML \
		p5-YAML-Syck>=0:textproc/p5-YAML-Syck

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
