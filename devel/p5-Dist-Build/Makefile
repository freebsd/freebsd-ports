PORTNAME=	Dist-Build
DISTVERSION=	0.026
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LEONT
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Modern module builder, author tools not included
WWW=		https://metacpan.org/dist/Dist-Build

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

MY_DEPENDS=	p5-ExtUtils-Builder>=0.020:devel/p5-ExtUtils-Builder \
		p5-ExtUtils-Builder-Compiler>=0.034:devel/p5-ExtUtils-Builder-Compiler \
		p5-ExtUtils-Config>=0:devel/p5-ExtUtils-Config \
		p5-ExtUtils-Helpers>=0.028:devel/p5-ExtUtils-Helpers \
		p5-ExtUtils-InstallPaths>=0:devel/p5-ExtUtils-InstallPaths
BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}

USES=		perl5
USE_PERL5=	distbuild
NO_ARCH=	yes

.include <bsd.port.mk>
