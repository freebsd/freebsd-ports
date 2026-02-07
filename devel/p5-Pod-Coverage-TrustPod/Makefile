PORTNAME=	Pod-Coverage-TrustPod
PORTVERSION=	0.100006
CATEGORIES=	devel textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Declare trusted symbol names in POD
WWW=		https://metacpan.org/release/Pod-Coverage-TrustPod

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Pod-Coverage>=0:devel/p5-Pod-Coverage \
		p5-Pod-Eventual>=0:textproc/p5-Pod-Eventual

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
