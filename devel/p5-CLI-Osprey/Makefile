PORTNAME=	CLI-Osprey
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	MooX::Options + MooX::Cmd + Sanity

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Getopt-Long-Descriptive>=0.100:devel/p5-Getopt-Long-Descriptive \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Moo>=0:devel/p5-Moo \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny
TEST_DEPENDS=	p5-Capture-Tiny>=0.48:devel/p5-Capture-Tiny

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
