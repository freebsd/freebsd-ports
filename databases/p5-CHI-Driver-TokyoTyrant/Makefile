# $FreeBSD$

PORTNAME=	CHI-Driver-TokyoTyrant
PORTVERSION=	0.02
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	TokyoTyrant Driver to use with the Cache Handling Interface CHI

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-tokyotyrant>=0:databases/p5-tokyotyrant \
		p5-CHI>=0:devel/p5-CHI \
		p5-Module-Build>=0.40:devel/p5-Module-Build
RUN_DEPENDS=	p5-CHI>=0.241:devel/p5-CHI
TEST_DEPENDS=	p5-Test-Class>=0:devel/p5-Test-Class

USES=		perl5

NO_ARCH=	yes
USE_PERL5=	modbuild

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/CHI/t/

.include <bsd.port.mk>
