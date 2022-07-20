PORTNAME=	FFI-Platypus-Declare
PORTVERSION=	1.34
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Declarative interface to FFI::Platypus

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-FFI-Platypus>=1.33:devel/p5-FFI-Platypus
TEST_DEPENDS=	p5-FFI-CheckLib>=0:devel/p5-FFI-CheckLib

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
