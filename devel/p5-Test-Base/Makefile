PORTNAME=	Test-Base
PORTVERSION=	0.89
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Data Driven Testing Framework

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Spiffy>=0.40:devel/p5-Spiffy \
		p5-Text-Diff>=0.35:textproc/p5-Text-Diff
TEST_DEPENDS=	p5-Test-Deep>0:devel/p5-Test-Deep \
		p5-YAML>=0:textproc/p5-YAML

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
