PORTNAME=	MooX-Types-MooseLike
PORTVERSION=	0.29
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Some Moosish types and a typer builder

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Module-Runtime>=0.014:devel/p5-Module-Runtime
TEST_DEPENDS=	p5-Moo>=1.004002:devel/p5-Moo \
		p5-Set-Object>=1:devel/p5-Set-Object \
		p5-Test-Fatal>=0.003:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
