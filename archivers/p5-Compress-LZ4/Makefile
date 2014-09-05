# $FreeBSD$

PORTNAME=	Compress-LZ4
PORTVERSION=	0.20
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interface to the LZ4 (de)compressor

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

post-stage:
	${STRIP_CMD} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Compress/LZ4/LZ4.so

.include <bsd.port.mk>
