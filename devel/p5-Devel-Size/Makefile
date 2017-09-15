# Created by: mat
# $FreeBSD$

PORTNAME=	Devel-Size
PORTVERSION=	0.81
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for finding the memory usage of Perl variables

LICENSE_COMB=	dual
LICENSES=	ART10 GPLv1+

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Devel/Size/Size.so

.include <bsd.port.mk>
