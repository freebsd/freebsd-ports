PORTNAME=	Text-Levenshtein-Damerau-XS
PORTVERSION=	3.2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	m.ne@gmx.net
COMMENT=	Damerau Levenshtein edit distance
WWW=		https://metacpan.org/dist/Text-Levenshtein-Damerau-XS

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Text/Levenshtein/Damerau/XS/XS.so

.include <bsd.port.mk>
