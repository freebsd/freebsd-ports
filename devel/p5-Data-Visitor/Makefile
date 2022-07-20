PORTNAME=	Data-Visitor
PORTVERSION=	0.31
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Visitor style traversal of Perl data structures

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Moose>=0.89:devel/p5-Moose \
		p5-Sub-Name>=0:devel/p5-Sub-Name \
		p5-Tie-ToObject>=0.01:devel/p5-Tie-ToObject \
		p5-namespace-clean>=0.19:devel/p5-namespace-clean
TEST_DEPENDS=	p5-Data-Alias>=0:devel/p5-Data-Alias \
		p5-Test-Needs>=0:devel/p5-Test-Needs \
		p5-Tie-RefHash>=0:devel/p5-Tie-RefHash

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
