PORTNAME=	ExtUtils-CppGuess
PORTVERSION=	0.27
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Guess C++ compiler and flags
WWW=		https://metacpan.org/release/ExtUtils-CppGuess

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Capture-Tiny>=0:devel/p5-Capture-Tiny
TEST_DEPENDS=	p5-ExtUtils-CBuilder>=0.280231:devel/p5-ExtUtils-CBuilder

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
