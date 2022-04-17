PORTNAME=	Path-IsDev
PORTVERSION=	1.001003
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KENTNL
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to determine if path resembles dev source tree

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Tiny>=0.010:devel/p5-Class-Tiny \
		p5-File-HomeDir>=0:devel/p5-File-HomeDir \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Path-Tiny>=0.004:devel/p5-Path-Tiny \
		p5-Role-Tiny>=0:devel/p5-Role-Tiny \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
