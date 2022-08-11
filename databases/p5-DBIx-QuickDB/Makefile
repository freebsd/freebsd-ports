PORTNAME=	DBIx-QuickDB
PORTVERSION=	0.000022
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Quickly start a db server

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-Copy-Recursive>=0:devel/p5-File-Copy-Recursive \
		p5-Importer>=0.024:devel/p5-Importer \
		p5-Module-Pluggable>=2.7:devel/p5-Module-Pluggable \
		p5-Test2-Suite>=0.000097:devel/p5-Test2-Suite
TEST_DEPENDS=	p5-Capture-Tiny>=0.20:devel/p5-Capture-Tiny

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
