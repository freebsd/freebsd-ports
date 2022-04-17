PORTNAME=	Perl-Metrics-Simple
PORTVERSION=	0.19
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to count packages, subs, lines, etc. of many files

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-PPI>=1.113:textproc/p5-PPI \
		p5-Readonly>=1.03:devel/p5-Readonly \
		p5-Statistics-Basic>=0:math/p5-Statistics-Basic
TEST_DEPENDS=	p5-Test-Compile>=0:devel/p5-Test-Compile \
		p5-Test-Pod-Coverage>=1.04:devel/p5-Test-Pod-Coverage \
		p5-Test-Pod>=1.00:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

post-patch:
	${FIND} ${WRKSRC} -name '*.orig' -delete

.include <bsd.port.mk>
