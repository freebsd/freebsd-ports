PORTNAME=	Getargs-Long
PORTVERSION=	1.1012
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parse routine arguments

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Log-Agent>=0.105:devel/p5-Log-Agent \
		p5-URI>=0:net/p5-URI
TEST_DEPENDS=	p5-Test-Compile>=0:devel/p5-Test-Compile

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
