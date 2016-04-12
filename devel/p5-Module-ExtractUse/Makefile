# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Module-ExtractUse
PORTVERSION=	0.34.1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Find out what CPAN modules are used

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Parse-RecDescent>=1.967:devel/p5-Parse-RecDescent \
		p5-Pod-Strip>=0:textproc/p5-Pod-Strip
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-UNIVERSAL-require>=0.11:devel/p5-UNIVERSAL-require \
		p5-Test-Deep>0:devel/p5-Test-Deep

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
