PORTNAME=	MooseX-MungeHas
PORTVERSION=	0.011
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dgeo@centrale-marseille.fr
COMMENT=	Munge your "has" (works with Moo, Moose and Mouse)

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSE
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Moose>=1.10:devel/p5-Moose
RUN_DEPENDS=	p5-Moose>=1.10:devel/p5-Moose
TEST_DEPENDS=	p5-Test-Requires>=0:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes
PLIST_FILES=	${SITE_PERL_REL}/MooseX/MungeHas.pm \
		${SITE_MAN3_REL}/MooseX::MungeHas.3.gz

.include <bsd.port.mk>
