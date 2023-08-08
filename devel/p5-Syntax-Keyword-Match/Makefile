PORTNAME=	Syntax-Keyword-Match
PORTVERSION=	0.12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Match/case syntax for Perl
WWW=		https://metacpan.org/dist/Syntax-Keyword-Match

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-XS-Parse-Keyword>=0.23:devel/p5-XS-Parse-Keyword
TEST_DEPENDS=	p5-Test2-Suite>=0.000147:devel/p5-Test2-Suite

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Syntax/Keyword/Match/Match.so

.include <bsd.port.mk>
