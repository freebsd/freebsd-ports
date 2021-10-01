PORTNAME=	Validation-Class
PORTVERSION=	7.900057
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AWNCORP
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Perl extension for centralized input validation for any application

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Hash-Flatten>0:devel/p5-Hash-Flatten \
		p5-Hash-Merge>0:textproc/p5-Hash-Merge \
		p5-List-MoreUtils>0:lang/p5-List-MoreUtils \
		p5-Module-Find>0:devel/p5-Module-Find \
		p5-Module-Runtime>0:devel/p5-Module-Runtime
TEST_DEPENDS=	p5-Class-Method-Modifiers>0:devel/p5-Class-Method-Modifiers

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
