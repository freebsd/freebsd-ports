PORTNAME=	Lexical-Import
PORTVERSION=	0.002
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Clean imports from package-exporting modules

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Lexical-Var>=0.006:devel/p5-Lexical-Var \
		p5-Module-Runtime>=0.011:devel/p5-Module-Runtime \
		p5-Params-Classify>=0:devel/p5-Params-Classify
TEST_DEPENDS=	p5-Test-Pod>=1:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:devel/p5-Test-Pod-Coverage

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Lexical/Import/Import.so

.include <bsd.port.mk>
