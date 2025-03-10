PORTNAME=	Syntax-Keyword-Dynamically
PORTVERSION=	0.14
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Dynamically change the value of a variable
WWW=		https://metacpan.org/dist/Syntax-Keyword-Dynamically

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Future-AsyncAwait>=0.60:devel/p5-Future-AsyncAwait \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-XS-Parse-Keyword>=0.13:devel/p5-XS-Parse-Keyword
TEST_DEPENDS=	p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Syntax/Keyword/Dynamically/Dynamically.so

.include <bsd.port.mk>
