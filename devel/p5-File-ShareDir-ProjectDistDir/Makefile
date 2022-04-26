PORTNAME=	File-ShareDir-ProjectDistDir
PORTVERSION=	1.000009
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for set-and-forget using a directory in projects root

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-Path-FindDev>=0:devel/p5-Path-FindDev \
		p5-Path-IsDev>=0:devel/p5-Path-IsDev \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter
TEST_DEPENDS=	p5-Class-Tiny>=0:devel/p5-Class-Tiny

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
