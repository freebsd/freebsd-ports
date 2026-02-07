PORTNAME=	Contextual-Return
PORTVERSION=	0.004014
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DCONWAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create context-sensitive return values
WWW=		https://metacpan.org/release/Contextual-Return

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Want>=0:devel/p5-Want
TEST_DEPENDS=	p5-Test-Pod>=1.14:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
