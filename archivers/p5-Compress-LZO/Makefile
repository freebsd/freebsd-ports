PORTNAME=	Compress-LZO
PORTVERSION=	1.09
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interface to the LZO compression library

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Devel-CheckLib>=0.9:devel/p5-Devel-CheckLib
LIB_DEPENDS=	liblzo2.so:archivers/lzo2

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Compress/LZO/LZO.so

.include <bsd.port.mk>
