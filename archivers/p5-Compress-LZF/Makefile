# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Compress-LZF
PORTVERSION=	3.80
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/0$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extremely lightweight Lempel-Ziv-Free compression

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Compress/LZF/LZF.so

.include <bsd.port.mk>
