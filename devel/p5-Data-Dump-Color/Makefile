# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Data-Dump-Color
PORTVERSION=	0.243
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Like Data::Dump, but with color

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-File-ShareDir-Install>=0.06:devel/p5-File-ShareDir-Install \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-ColorThemeBase-Static>=0.006:devel/p5-ColorThemeBase-Static \
		p5-ColorThemeUtil-ANSI>=0:devel/p5-ColorThemeUtil-ANSI \
		p5-Data-Dump>=0:devel/p5-Data-Dump \
		p5-Module-Load-Util>=0.004:devel/p5-Module-Load-Util
TEST_DEPENDS=	p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
