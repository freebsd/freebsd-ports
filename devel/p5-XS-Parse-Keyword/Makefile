PORTNAME=	XS-Parse-Keyword
PORTVERSION=	0.44
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PEVANS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XS functions to assist in parsing keyword syntax
WWW=		https://metacpan.org/dist/XS-Parse-Keyword

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-ExtUtils-CChecker>=0.11:devel/p5-ExtUtils-CChecker \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-ShareDir>=1.00:devel/p5-File-ShareDir
TEST_DEPENDS=	p5-Test2-Suite>=0:devel/p5-Test2-Suite

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/XS/Parse/Keyword/Keyword.so

.include <bsd.port.mk>
