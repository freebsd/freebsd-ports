PORTNAME=	Net-DNS-Paranoid
PORTVERSION=	0.10
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Paranoid DNS resolver
WWW=		https://metacpan.org/release/Net-DNS-Paranoid

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSE
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Module-Build-Tiny>0:devel/p5-Module-Build-Tiny
RUN_DEPENDS=	p5-Class-Accessor-Lite>=0.05:devel/p5-Class-Accessor-Lite \
		p5-Net-DNS>=1.35:dns/p5-Net-DNS

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
