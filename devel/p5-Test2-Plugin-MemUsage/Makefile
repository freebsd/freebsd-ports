PORTNAME=	Test2-Plugin-MemUsage
PORTVERSION=	0.002006
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:EXODIST
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collect and display memory usage information
WWW=		https://metacpan.org/release/Test2-Plugin-MemUsage

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	RECOMMENDED
OPTIONS_DEFAULT=RECOMMENDED
RECOMMENDED_DESC=	Recommended dependencies by upstream

RECOMMENDED_BUILD_DEPENDS=	p5-BSD-Resource>=1.2911:devel/p5-BSD-Resource
RECOMMENDED_RUN_DEPENDS=p5-BSD-Resource>=1.2911:devel/p5-BSD-Resource

.include <bsd.port.mk>
