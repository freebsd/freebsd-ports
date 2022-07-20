PORTNAME=	Debug-Client
PORTVERSION=	0.31
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Client for the standard Perl debugger

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-PadWalker>=1.98:devel/p5-PadWalker \
		p5-Term-ReadLine-Gnu>=1.20:devel/p5-Term-ReadLine-Gnu
TEST_DEPENDS=	p5-File-HomeDir>=1:devel/p5-File-HomeDir \
		p5-Test-CheckDeps>=0.010:devel/p5-Test-CheckDeps \
		p5-Test-Class>=0.42:devel/p5-Test-Class \
		p5-Test-Deep>=0.112:devel/p5-Test-Deep \
		p5-Test-Requires>=0.07:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
