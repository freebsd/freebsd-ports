PORTNAME=	DBIx-Admin-CreateTable
PORTVERSION=	2.11
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Create and drop tables, primary indexes, and sequences

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		p5-Moo>=1.004002:devel/p5-Moo
TEST_DEPENDS=	p5-Test-Version>=1.002003:devel/p5-Test-Version

USES=		perl5 tar:tgz
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
