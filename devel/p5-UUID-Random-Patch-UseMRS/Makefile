PORTNAME=	UUID-Random-Patch-UseMRS
PORTVERSION=	0.030
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Make UUID::Random use Math::Random::Secure::rand()

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Math-Random-Secure>=0:math/p5-Math-Random-Secure \
		p5-UUID-Random>=0:devel/p5-UUID-Random

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
