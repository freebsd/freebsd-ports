# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Params-Classify
PORTVERSION=	0.015
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Argument type classification

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Devel-CallChecker>=0.003:devel/p5-Devel-CallChecker

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Params/Classify/Classify.so

.include <bsd.port.mk>
