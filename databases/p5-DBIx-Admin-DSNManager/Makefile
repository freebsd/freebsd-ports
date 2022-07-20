PORTNAME=	DBIx-Admin-DSNManager
PORTVERSION=	2.02
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Manage a file of DSNs, for both testing and production

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Config-Tiny>=2.12:devel/p5-Config-Tiny \
		p5-DBI>=0:databases/p5-DBI \
		p5-File-Slurp>=9999.13:devel/p5-File-Slurp \
		p5-Moo>=1.004002:devel/p5-Moo
TEST_DEPENDS=	p5-Test-Version>=1.002003:devel/p5-Test-Version \
		p5-Try-Tiny>=0.06:lang/p5-Try-Tiny

USES=		perl5 tar:tgz
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
