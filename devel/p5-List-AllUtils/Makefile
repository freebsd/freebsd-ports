# $FreeBSD$

PORTNAME=	List-AllUtils
PORTVERSION=	0.12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Combines List::Util and List::MoreUtils in one bite-sized package

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-List-SomeUtils>=0.50:devel/p5-List-SomeUtils \
		p5-List-UtilsBy>=0.10:devel/p5-List-UtilsBy \
		p5-Scalar-List-Utils>=1.45:lang/p5-Scalar-List-Utils
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
