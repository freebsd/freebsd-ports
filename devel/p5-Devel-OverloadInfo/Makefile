PORTNAME=	Devel-OverloadInfo
PORTVERSION=	0.008
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Introspect overloaded operators
WWW=		https://metacpan.org/release/Devel-OverloadInfo

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-MRO-Compat>=0:devel/p5-MRO-Compat \
		p5-Package-Stash>=0.14:devel/p5-Package-Stash
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
