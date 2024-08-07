PORTNAME=	ExtUtils-Builder-Compiler
DISTVERSION=	0.017
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Interface around different compilers
WWW=		https://metacpan.org/dist/ExtUtils-Builder-Compiler

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

MY_DEPENDS=	p5-ExtUtils-Builder>=0.011:devel/p5-ExtUtils-Builder \
		p5-ExtUtils-Config>=0.009:devel/p5-ExtUtils-Config \
		p5-ExtUtils-Helpers>=0.027:devel/p5-ExtUtils-Helpers
BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
