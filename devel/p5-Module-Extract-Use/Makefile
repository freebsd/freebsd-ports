PORTNAME=	Module-Extract-Use
DISTVERSION=	1.053
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Pull out the modules a module explicitly uses
WWW=		https://github.com/briandfoy/module-extract-use/tree/master

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-PPI>=0:textproc/p5-PPI
TEST_DEPENDS=	p5-Test-Pod-Coverage>0:devel/p5-Test-Pod-Coverage \
		p5-Test-Pod>0:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
