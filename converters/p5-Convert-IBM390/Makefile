PORTNAME=	Convert-IBM390
PORTVERSION=	0.30
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Functions for manipulating mainframe data

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Convert/IBM390/IBM390.so

.include <bsd.port.mk>
