PORTNAME=	RedisDB
PORTVERSION=	2.57
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to access redis database

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-RedisDB-Parser>=2.21:databases/p5-RedisDB-Parser \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-URI>=0:net/p5-URI
TEST_DEPENDS=	p5-Test-Differences>=0.610,1:devel/p5-Test-Differences \
		p5-Test-FailWarnings>=0:devel/p5-Test-FailWarnings \
		p5-Test-Most>=0.22:devel/p5-Test-Most \
		p5-Test-TCP>=1.17:devel/p5-Test-TCP

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
