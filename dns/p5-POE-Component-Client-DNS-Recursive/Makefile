PORTNAME=	POE-Component-Client-DNS-Recursive
PORTVERSION=	1.14
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Recursive DNS client for POE
WWW=		https://metacpan.org/release/POE-Component-Client-DNS-Recursive

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Net-DNS>=1.38,1:dns/p5-Net-DNS \
		p5-Net-IP-Minimal>=0:net/p5-Net-IP-Minimal \
		p5-POE>=1.004:devel/p5-POE

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
