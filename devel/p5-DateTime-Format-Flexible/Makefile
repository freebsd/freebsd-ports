PORTNAME=	DateTime-Format-Flexible
PORTVERSION=	0.34
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Flexibly parse strings and turn them into DateTime objects

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DateTime>=0:devel/p5-DateTime \
		p5-DateTime-Format-Builder>=0.74:devel/p5-DateTime-Format-Builder \
		p5-DateTime-TimeZone>=0:devel/p5-DateTime-TimeZone \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Module-Pluggable>=0:devel/p5-Module-Pluggable
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-MockTime>=0:devel/p5-Test-MockTime \
		p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
