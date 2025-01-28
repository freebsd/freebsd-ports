PORTNAME=	Test-Class
PORTVERSION=	0.52
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easily create test classes in an xUnit style
WWW=		https://metacpan.org/release/Test-Class

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-MRO-Compat>=0.11:devel/p5-MRO-Compat \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny
TEST_DEPENDS=	p5-Contextual-Return>=0:devel/p5-Contextual-Return \
		p5-Test-Exception>=0.25:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
