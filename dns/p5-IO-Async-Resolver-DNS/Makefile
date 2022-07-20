PORTNAME=	IO-Async-Resolver-DNS
PORTVERSION=	0.06
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Resolve DNS queries using IO::Async

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Future>=0:devel/p5-Future \
		p5-IO-Async>=0.52:devel/p5-IO-Async \
		p5-List-UtilsBy>=0.07:devel/p5-List-UtilsBy \
		p5-Net-DNS>=0:dns/p5-Net-DNS

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
