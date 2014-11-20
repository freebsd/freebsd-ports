# $FreeBSD$

PORTNAME=	Scalar-Util-LooksLikeNumber
PORTVERSION=	1.39.1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for looks_like_number() perl API

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${SITE_ARCH}/auto/Scalar/Util/LooksLikeNumber/LooksLikeNumber.so

.include <bsd.port.mk>
