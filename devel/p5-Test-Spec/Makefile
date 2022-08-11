PORTNAME=	Test-Spec
PORTVERSION=	0.54
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Write tests in a declarative specification style

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Package-Stash>=0.23:devel/p5-Package-Stash \
		p5-Test-Deep>=0.103:devel/p5-Test-Deep \
		p5-Test-Trap>=0:devel/p5-Test-Trap \
		p5-Tie-IxHash>=0:devel/p5-Tie-IxHash

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
