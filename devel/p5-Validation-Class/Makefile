PORTNAME=	Validation-Class
PORTVERSION=	7.900059
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CKRAS
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Perl extension for centralized input validation for any application
WWW=		https://metacpan.org/dist/Validation-Class

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BR_DEPENDS=	p5-Hash-Flatten>0:devel/p5-Hash-Flatten \
		p5-Hash-Merge>0:textproc/p5-Hash-Merge \
		p5-List-MoreUtils>0:lang/p5-List-MoreUtils \
		p5-Module-Find>0:devel/p5-Module-Find \
		p5-Module-Runtime>0:devel/p5-Module-Runtime
BUILD_DEPENDS=	${BR_DEPENDS}
RUN_DEPENDS=	${BR_DEPENDS}
TEST_DEPENDS=	p5-Class-Method-Modifiers>0:devel/p5-Class-Method-Modifiers

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
