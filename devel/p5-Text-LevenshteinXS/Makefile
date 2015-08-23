# Created by: christian
# $FreeBSD$

PORTNAME=	Text-LevenshteinXS
PORTVERSION=	0.03
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text::LevenshteinXS - CPAN Levenshtein edit distance

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Text/LevenshteinXS/LevenshteinXS.so

.include <bsd.port.mk>
