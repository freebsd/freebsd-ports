PORTNAME=	POE-Loop-AnyEvent
PORTVERSION=	0.004
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	AnyEvent event loop support for POE

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-POE-Test-Loops>=1.035:devel/p5-POE-Test-Loops \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-AnyEvent>=0,1:devel/p5-AnyEvent \
		p5-POE>=1.289:devel/p5-POE

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
