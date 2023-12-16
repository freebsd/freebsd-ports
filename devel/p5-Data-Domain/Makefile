PORTNAME=	Data-Domain
PORTVERSION=	1.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Data description and validation
WWW=		https://metacpan.org/release/Data-Domain

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Date-Calc>=0:devel/p5-Date-Calc \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Scalar-Does>=0.007:devel/p5-Scalar-Does \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-experimental>=0:devel/p5-experimental \
		p5-match-simple>=0:devel/p5-match-simple
TEST_DEPENDS=	p5-Clone>=0:devel/p5-Clone \
		p5-Test-Pod>=1.14:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.04:devel/p5-Test-Pod-Coverage \
		p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

OPTIONS_DEFINE=	RECOMMENDED
OPTIONS_DEFAULT=RECOMMENDED
RECOMMENDED_DESC=	Recommended dependencies by upstream

RECOMMENDED_BUILD_DEPENDS=	p5-match-simple-XS>=0:devel/p5-match-simple-XS
RECOMMENDED_RUN_DEPENDS=p5-match-simple-XS>=0:devel/p5-match-simple-XS

.include <bsd.port.mk>
