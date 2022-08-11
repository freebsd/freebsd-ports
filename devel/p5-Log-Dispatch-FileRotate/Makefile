PORTNAME=	Log-Dispatch-FileRotate
PORTVERSION=	1.38
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Log::Dispatch plug-in for files that archive/rotate themselves

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Date-Manip>=0:devel/p5-Date-Manip \
		p5-Log-Dispatch>=2.60:devel/p5-Log-Dispatch
TEST_DEPENDS=	p5-Path-Tiny>=0.018:devel/p5-Path-Tiny \
		p5-Test-Warn>=0:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
