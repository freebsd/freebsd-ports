PORTNAME=	DBIx-QuickDB
PORTVERSION=	0.000035
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Quickly start a db server
WWW=		https://metacpan.org/dist/DBIx-QuickDB

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Capture-Tiny>=0.20:devel/p5-Capture-Tiny \
		p5-File-Copy-Recursive>=0:devel/p5-File-Copy-Recursive \
		p5-Importer>=0.024:devel/p5-Importer \
		p5-Module-Pluggable>=2.7:devel/p5-Module-Pluggable \
		p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
