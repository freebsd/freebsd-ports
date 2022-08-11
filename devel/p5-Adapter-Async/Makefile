PORTNAME=	Adapter-Async
PORTVERSION=	0.019
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TEAM
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provide a way to link a data source with a view

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Future>=0.30:devel/p5-Future \
		p5-List-BinarySearch>=0.25:devel/p5-List-BinarySearch \
		p5-Log-Any>=0:devel/p5-Log-Any \
		p5-Mixin-Event-Dispatch>=1.006:devel/p5-Mixin-Event-Dispatch \
		p5-Variable-Disposition>=0.004:devel/p5-Variable-Disposition \
		p5-curry>=0:devel/p5-curry
TEST_DEPENDS=	p5-Test-CheckDeps>=0.010:devel/p5-Test-CheckDeps \
		p5-Test-Fatal>=0.010:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
