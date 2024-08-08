PORTNAME=	ExtUtils-Builder
DISTVERSION=	0.011
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Overview of foundations of ExtUtils::Builder Plan framework
WWW=		https://metacpan.org/dist/ExtUtils-Builder

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

MY_DEPENDS=	p5-ExtUtils-Config>=0.009:devel/p5-ExtUtils-Config
BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
