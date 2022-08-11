PORTNAME=	Encode-HanExtra
PORTVERSION=	0.23
PORTREVISION=	2
CATEGORIES=	chinese perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extra sets of Chinese encodings

LICENSE=	MIT

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Encode/HanExtra/HanExtra.so

.include <bsd.port.mk>
