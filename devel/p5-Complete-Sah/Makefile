PORTNAME=	Complete-Sah
PORTVERSION=	0.008
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PERLANCAR
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Sah-related completion Perl routines

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Complete-Common>=0.22:devel/p5-Complete-Common \
		p5-Complete-Util>=0.608:devel/p5-Complete-Util \
		p5-Data-Sah-Normalize>=0.051:devel/p5-Data-Sah-Normalize \
		p5-Log-ger>=0.038:devel/p5-Log-ger \
		p5-Module-Installed-Tiny>=0.004:devel/p5-Module-Installed-Tiny
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
