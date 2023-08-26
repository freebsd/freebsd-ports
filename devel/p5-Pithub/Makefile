PORTNAME=	Pithub
PORTVERSION=	0.01041
CATEGORIES=	devel
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:OALDERS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Github v3 API
WWW=		https://metacpan.org/release/Pithub

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-CHI>=0:devel/p5-CHI \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-Moo>=0:devel/p5-Moo \
		p5-libwww>=0:www/p5-libwww
TEST_DEPENDS=	p5-Import-Into>=0:devel/p5-Import-Into \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-Test-Differences>=0:devel/p5-Test-Differences \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Most>=0:devel/p5-Test-Most \
		p5-Test-Needs>=0:devel/p5-Test-Needs

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
