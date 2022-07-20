PORTNAME=	Class-Accessor-Grouped
PORTVERSION=	0.10014
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RIBASUSHI
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Lets you build groups of accessors

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Module-Runtime>=0.012:devel/p5-Module-Runtime \
		p5-Class-XSAccessor>=1.19:devel/p5-Class-XSAccessor \
		p5-Sub-Name>=0.05:devel/p5-Sub-Name
TEST_DEPENDS=	p5-Test-Exception>=0.31:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
