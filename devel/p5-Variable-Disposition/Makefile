PORTNAME=	Variable-Disposition
PORTVERSION=	0.005
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Helper functions for disposing of variables
WWW=		https://metacpan.org/release/Variable-Disposition

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Future>=0.36:devel/p5-Future
TEST_DEPENDS=	p5-Test-CheckDeps>=0.010:devel/p5-Test-CheckDeps \
		p5-Test-Fatal>=0.010:devel/p5-Test-Fatal \
		p5-Test-Refcount>=0:devel/p5-Test-Refcount

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
