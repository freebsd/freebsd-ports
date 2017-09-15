# $FreeBSD$

PORTNAME=	Encode-EUCJPASCII
PORTVERSION=	0.03
CATEGORIES=	japanese converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	ja-p5-

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Perl5 module for eucJP-open

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

post-install:
	for F in ${SITE_ARCH}/auto/Encode/EUCJPASCII/EUCJPASCII.so; do \
		${CHMOD} +w ${STAGEDIR}$$F; \
		${STRIP_CMD} ${STAGEDIR}$$F; \
	done

.include <bsd.port.mk>
