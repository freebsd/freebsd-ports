PORTNAME=	Data-Sah-Resolve
PORTVERSION=	0.011
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Resolve Sah schema
WWW=		https://metacpan.org/dist/Data-Sah-Resolve

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Data-ModeMerge>=0:devel/p5-Data-ModeMerge \
		p5-Data-Sah-Normalize>=0.051:devel/p5-Data-Sah-Normalize
TEST_DEPENDS=	p5-Data-Dmp>=0.241:devel/p5-Data-Dmp \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Needs>=0:devel/p5-Test-Needs

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
