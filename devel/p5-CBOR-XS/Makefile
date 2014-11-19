# Created by: Kurt Jaeger <fbsd-ports@opsec.eu>
# $FreeBSD$

PORTNAME=	CBOR-XS
PORTVERSION=	1.26
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MLEHMANN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Perl does Concise Binary Object Representation (CBOR, RFC7049)

LICENSE=	GPLv3

USES=		perl5
USE_PERL5=	configure

post-stage:
	${STRIP_CMD} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/CBOR/XS/XS.so

.include <bsd.port.mk>
