PORTNAME=	Cache-FastMmap
PORTVERSION=	1.60
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN \
		CPAN/Cache
MASTER_SITE_SUBDIR=	CPAN:ROBM
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Uses an mmap'ed file to act as a shared memory interprocess cache #'
WWW=		https://metacpan.org/release/Cache-FastMmap

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-JSON>=0:converters/p5-JSON \
		p5-Sereal>0:converters/p5-Sereal \
		p5-Test-Deep>=0:devel/p5-Test-Deep

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Cache/FastMmap/FastMmap.so

.include <bsd.port.mk>
