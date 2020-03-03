# $FreeBSD$

PORTNAME=	List-AllUtils
PORTVERSION=	0.16
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Combines List::Util and List::MoreUtils in one bite-sized package

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-List-SomeUtils>=0.56:devel/p5-List-SomeUtils \
		p5-List-UtilsBy>=0.11:devel/p5-List-UtilsBy \
		p5-Scalar-List-Utils>=1.45:lang/p5-Scalar-List-Utils

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
