PORTNAME=	Test-DBIC-ExpectedQueries
PORTVERSION=	2.002
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=CPAN:JOHANL
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Test that only expected DBIx::Class queries are run

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-DBIx-Class>=0:databases/p5-DBIx-Class \
		p5-Devel-StackTrace>=0:devel/p5-Devel-StackTrace \
		p5-Exporter-Tiny>=0:devel/p5-Exporter-Tiny \
		p5-Moo>=0:devel/p5-Moo \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-autobox-Core>=0:devel/p5-autobox-Core \
		p5-autobox-Transform>=0:devel/p5-autobox-Transform
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Warnings>=0:devel/p5-Test-Warnings

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
