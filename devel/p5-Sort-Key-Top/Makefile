# Created by: ijliao
# $FreeBSD$

PORTNAME=	Sort-Key-Top
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SALVA
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Select and sort top n elements

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Sort/Key/Top/Top.so

.include <bsd.port.mk>
