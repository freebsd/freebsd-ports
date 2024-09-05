PORTNAME=	JavaScript-QuickJS
PORTVERSION=	0.21
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Run JavaScript via QuickJS in Perl
WWW=		https://metacpan.org/dist/JavaScript-QuickJS

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-ExtUtils-MakeMaker-CPANfile>=0:devel/p5-ExtUtils-MakeMaker-CPANfile \
		p5-File-Slurper>=0:devel/p5-File-Slurper \
		p5-File-Which>=0:sysutils/p5-File-Which
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-FailWarnings>=0:devel/p5-Test-FailWarnings \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Types-Serialiser>=0:devel/p5-Types-Serialiser

USES=		gmake perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/JavaScript/QuickJS/QuickJS.so

.include <bsd.port.mk>
