# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	MooseX-Types-URI
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	URI related types and coercions for Moose

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENCE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-Types>=0.40:devel/p5-MooseX-Types \
		p5-URI>=0:net/p5-URI \
		p5-URI-FromHash>=0:net/p5-URI-FromHash \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
TEST_DEPENDS=	p5-Test-Needs>=0:devel/p5-Test-Needs \
		p5-Test-Without-Module>=0:devel/p5-Test-Without-Module

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
