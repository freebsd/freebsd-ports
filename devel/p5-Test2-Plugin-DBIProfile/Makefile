PORTNAME=	Test2-Plugin-DBIProfile
PORTVERSION=	0.002006
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:EXODIST
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Plugin to enable and display DBI profiling
WWW=		https://metacpan.org/release/Test2-Plugin-DBIProfile

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Test-Simple>=1.302200:devel/p5-Test-Simple
TEST_DEPENDS=	p5-DBD-SQLite>=1.44:databases/p5-DBD-SQLite

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
