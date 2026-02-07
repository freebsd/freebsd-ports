PORTNAME=	Convert-Binary-C
PORTVERSION=	0.86
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Binary Data Conversion using C Types
WWW=		https://metacpan.org/release/Convert-Binary-C

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

MAKE_JOBS_UNSAFE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Convert/Binary/C/C.so

.include <bsd.port.mk>
