PORTNAME=	Bread-Board-Declare
PORTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DOY
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Create Bread::Board containers as normal Moose objects

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Bread-Board>=0.22:devel/p5-Bread-Board \
		p5-Class-Load>=0.07:devel/p5-Class-Load \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Moose>=2.0200:devel/p5-Moose
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
