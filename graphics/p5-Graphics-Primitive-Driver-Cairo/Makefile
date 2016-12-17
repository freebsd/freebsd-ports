# Created by: chinsan
# $FreeBSD$

PORTNAME=	Graphics-Primitive-Driver-Cairo
PORTVERSION=	0.47
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Cairo backend for Graphics::Primitive

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Cairo>=0:graphics/p5-Cairo \
		p5-Graphics-Primitive>=0:graphics/p5-Graphics-Primitive \
		p5-Moose>=0:devel/p5-Moose \
		p5-Text-Flow>=0:textproc/p5-Text-Flow
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Graphics-Color>=0:graphics/p5-Graphics-Color

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
