# $FreeBSD$

PORTNAME=	Devel-Callsite
PORTVERSION=	1.0.1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Gets current callsite and interpreter context

LICENSE=	ART10 GPLv2+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/Artistic
LICENSE_FILE_GPLv2+ =	${WRKSRC}/gpl-2.0.txt

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Devel/Callsite/Callsite.so

.include <bsd.port.mk>
