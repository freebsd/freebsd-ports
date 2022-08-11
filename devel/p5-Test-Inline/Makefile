PORTNAME=	Test-Inline
PORTVERSION=	2.214
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Inlining your tests next to the code being tested

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Algorithm-Dependency>=1.020:devel/p5-Algorithm-Dependency \
		p5-Config-Tiny>=2.00:devel/p5-Config-Tiny \
		p5-File-Find-Rule>=0.26:devel/p5-File-Find-Rule \
		p5-File-Flat>=1.00:devel/p5-File-Flat \
		p5-File-Remove>=0.37:devel/p5-File-Remove \
		p5-File-chmod>=0.31:devel/p5-File-chmod \
		p5-Params-Util>=0.21:devel/p5-Params-Util \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny
TEST_DEPENDS=	p5-Test-ClassAPI>=1.02:devel/p5-Test-ClassAPI \
		p5-Test-Script>=1.02:devel/p5-Test-Script

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
