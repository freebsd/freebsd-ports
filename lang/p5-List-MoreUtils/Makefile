PORTNAME=	List-MoreUtils
PORTVERSION=	0.430
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provide the stuff missing in List::Util

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Exporter-Tiny>=0.038:devel/p5-Exporter-Tiny \
		p5-List-MoreUtils-XS>=0.426:lang/p5-List-MoreUtils-XS
TEST_DEPENDS=	p5-Test-LeakTrace>=0:devel/p5-Test-LeakTrace

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
