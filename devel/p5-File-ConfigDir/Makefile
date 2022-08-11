PORTNAME=	File-ConfigDir
PORTVERSION=	0.021
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Get directories of configuration files

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-HomeDir>=0.50:devel/p5-File-HomeDir \
		p5-List-MoreUtils>=0.419:lang/p5-List-MoreUtils \
		p5-List-MoreUtils-XS>=0.418:lang/p5-List-MoreUtils-XS \
		p5-local-lib>=1.008008:devel/p5-local-lib
TEST_DEPENDS=	p5-Test-Without-Module>=0:devel/p5-Test-Without-Module

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
