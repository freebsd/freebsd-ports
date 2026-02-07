PORTNAME=	Compress-Raw-Lzma
PORTVERSION=	2.213
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Low-Level Interface to lzma compression library
WWW=		https://metacpan.org/release/Compress-Raw-Lzma

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Pod-Markdown>=0:textproc/p5-Pod-Markdown
TEST_DEPENDS=	p5-Test-Pod>=1:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Compress/Raw/Lzma/Lzma.so

.include <bsd.port.mk>
