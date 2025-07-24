PORTNAME=	Future-IO
PORTVERSION=	0.17
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PEVANS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Future-returning IO methods
WWW=		https://metacpan.org/dist/Future-IO

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Future>=0:devel/p5-Future \
		p5-Struct-Dumb>=0:devel/p5-Struct-Dumb
TEST_DEPENDS=	p5-Test-ExpectAndCheck>=0.06:devel/p5-Test-ExpectAndCheck \
		p5-Test-Future-IO-Impl>=0.15:devel/p5-Test-Future-IO-Impl \
		p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
