PORTNAME=	IO-Compress-Brotli
PORTVERSION=	0.017000
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	IO-Compress-Brotli-${PORTVERSION:C|000$||}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl implementation of Brotli
WWW=		https://metacpan.org/release/IO-Compress-Brotli

LICENSE=	MIT

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libbrotlicommon.so:archivers/brotli
RUN_DEPENDS=	p5-File-Slurper>0:devel/p5-File-Slurper

USES=		gmake localbase:ldflags perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/IO/Compress/Brotli/Brotli.so

.include <bsd.port.mk>
