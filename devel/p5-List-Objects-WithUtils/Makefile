# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	List-Objects-WithUtils
PORTVERSION=	2.028003
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	List objects, kitchen sink included

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Class-Method-Modifiers>=0:devel/p5-Class-Method-Modifiers \
		p5-List-UtilsBy>=0.09:devel/p5-List-UtilsBy \
		p5-Module-Runtime>=0.013:devel/p5-Module-Runtime \
		p5-Role-Tiny>=1.003:devel/p5-Role-Tiny \
		p5-Type-Tie>=0.004:devel/p5-Type-Tie \
		p5-autobox>=0:devel/p5-autobox \
		p5-strictures>=2:devel/p5-strictures
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
