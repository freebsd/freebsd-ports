# $FreeBSD$

PORTNAME=	Data-Serializable
PORTVERSION=	0.41.0
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Moose role that adds serialization support to any class

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-JSON>=0:converters/p5-JSON \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Moose>=0:devel/p5-Moose
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
