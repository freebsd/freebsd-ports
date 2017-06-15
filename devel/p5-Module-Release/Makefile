# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Module-Release
PORTVERSION=	2.123
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Upload files to CPAN and SourceForge

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CACertOrg-CA>=0:security/p5-CACertOrg-CA \
		p5-ConfigReader-Simple>=0:devel/p5-ConfigReader-Simple \
		p5-IO-Null>=0:devel/p5-IO-Null \
		p5-Mojolicious>=4.50:www/p5-Mojolicious \
		p5-URI>=0:net/p5-URI \
		p5-libwww>=6.02:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Output>=0:devel/p5-Test-Output \
		p5-Test-Pod>=1:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1:devel/p5-Test-Pod-Coverage \
		p5-Test-Without-Module>=0:devel/p5-Test-Without-Module

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
