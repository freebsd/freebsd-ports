PORTNAME=	Sentinel
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PEVANS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Create lightweight SCALARs with get/set callbacks
WWW=		https://metacpan.org/release/Sentinel

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Sentinel/Sentinel.so

.include <bsd.port.mk>
