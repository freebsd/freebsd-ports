PORTNAME=	DBIx-QueryLog
PORTVERSION=	0.42
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for logging queries for DBI
WWW=		https://metacpan.org/release/DBIx-QueryLog

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		p5-Text-ASCIITable>=0:textproc/p5-Text-ASCIITable
TEST_DEPENDS=	p5-Test-Requires>=0:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

post-patch:
	@${RM} -r ${WRKSRC}/script/

.include <bsd.port.mk>
