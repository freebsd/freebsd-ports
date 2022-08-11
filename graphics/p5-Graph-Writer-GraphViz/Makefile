PORTNAME=	Graph-Writer-GraphViz
PORTVERSION=	0.12
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GraphViz Writer for Graph object

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Graph>=0.9275,1:math/p5-Graph \
		p5-Graph-ReadWrite>=2.10:graphics/p5-Graph-ReadWrite \
		p5-GraphViz>=2.24:graphics/p5-GraphViz \
		p5-IO-All>=0.87:devel/p5-IO-All

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
