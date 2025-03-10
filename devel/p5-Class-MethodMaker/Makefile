PORTNAME=	Class-MethodMaker
PORTVERSION=	2.25
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for creating generic methods
WWW=		https://metacpan.org/release/Class-MethodMaker

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Class/MethodMaker/MethodMaker.so

.include <bsd.port.mk>
