PORTNAME=	Future-AsyncAwait
PORTVERSION=	0.66
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PEVANS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Deferred subroutine syntax for futures
WWW=		https://metacpan.org/dist/Future-AsyncAwait

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Future>=0.50:devel/p5-Future \
		p5-XS-Parse-Keyword>=0.13:devel/p5-XS-Parse-Keyword \
		p5-XS-Parse-Sublike>=0.14:devel/p5-XS-Parse-Sublike
TEST_DEPENDS=	p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Future/AsyncAwait/AsyncAwait.so

.include <bsd.port.mk>
