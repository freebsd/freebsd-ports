PORTNAME=	Package-Stash
PORTVERSION=	0.40
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Routines for manipulating stashes

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Dist-CheckConflicts>=0.02:devel/p5-Dist-CheckConflicts \
		p5-Module-Implementation>=0.06:devel/p5-Module-Implementation \
		p5-Package-Stash-XS>=0.22:devel/p5-Package-Stash-XS
TEST_DEPENDS=	p5-CPAN-Meta-Check>=0.011:devel/p5-CPAN-Meta-Check \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Needs>=0:devel/p5-Test-Needs

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
