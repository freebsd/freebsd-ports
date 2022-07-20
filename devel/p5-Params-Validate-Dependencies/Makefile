PORTNAME=	Params-Validate-Dependencies
PORTVERSION=	1.40
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Validate combinations of parameters

LICENSE=	ART10 GPLv2
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/ARTISTIC.txt
LICENSE_FILE_GPLv2=	${WRKSRC}/GPL2.txt

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Clone>=0.38:devel/p5-Clone \
		p5-Data-Domain>=1.02:devel/p5-Data-Domain \
		p5-PadWalker>=1.96:devel/p5-PadWalker \
		p5-Params-Validate>=1.07:devel/p5-Params-Validate
TEST_DEPENDS=	p5-Test-Differences>=0:devel/p5-Test-Differences \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Pod>=1:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1:devel/p5-Test-Pod-Coverage \
		p5-Test-Warnings>=0.026:devel/p5-Test-Warnings

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
