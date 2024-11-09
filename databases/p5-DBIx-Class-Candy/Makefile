PORTNAME=	DBIx-Class-Candy
PORTVERSION=	0.005004
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Sugar for your favorite ORM, DBIx::Class
WWW=		https://metacpan.org/release/DBIx-Class-Candy

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBIx-Class>=0.08123:databases/p5-DBIx-Class \
		p5-Lingua-EN-Inflect>=0:textproc/p5-Lingua-EN-Inflect
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
