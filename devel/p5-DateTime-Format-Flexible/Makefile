# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	DateTime-Format-Flexible
PORTVERSION=	0.30
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Flexibly parse strings and turn them into DateTime objects

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DateTime>=0:devel/p5-DateTime \
		p5-DateTime-Format-Builder>=0.74:devel/p5-DateTime-Format-Builder \
		p5-DateTime-TimeZone>=0:devel/p5-DateTime-TimeZone \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Module-Pluggable>=0:devel/p5-Module-Pluggable
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-MockTime>=0:devel/p5-Test-MockTime \
		p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
