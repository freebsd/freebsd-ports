# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Rinci
PORTVERSION=	1.1.83
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PERLANCAR
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Language-neutral metadata for your code entities

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Data-Sah-Normalize>=0:devel/p5-Data-Sah-Normalize
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DefHash>=1.0.6:devel/p5-DefHash \
		p5-Sah>=0.9.36:devel/p5-Sah

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
