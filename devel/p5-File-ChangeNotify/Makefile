# Created by: Alexey V. Degtyarev
# $FreeBSD$

PORTNAME=	File-ChangeNotify
PORTVERSION=	0.31
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Watch for changes to files

LICENSE=	ART20

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Module-Pluggable>=0:devel/p5-Module-Pluggable \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Moo>=1.006:devel/p5-Moo \
		p5-Type-Tiny>=0:devel/p5-Type-Tiny \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
TEST_DEPENDS=	p5-Test-Exception>0:devel/p5-Test-Exception \
		p5-Test-Requires>=0:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
