# Created by: Ilia Chipitsine <ilia@cgu.chel.su>
# $FreeBSD$

PORTNAME=	String-Approx
PORTVERSION=	3.28
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for approximate matching (fuzzy matching)

LICENSE=	ART20 LGPL20
LICENSE_COMB=	dual
LICENSE_FILE_ART20=	${WRKSRC}/Artistic
LICENSE_FILE_LGPL20=	${WRKSRC}/LGPL

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/String/Approx/Approx.so

.include <bsd.port.mk>
