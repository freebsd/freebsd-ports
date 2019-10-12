# $FreeBSD$

PORTNAME=	CHI-Driver-Memcached
PORTVERSION=	0.16
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Memcached Driver to use with the Cache Handling Interface CHI

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-CHI>=0.33:devel/p5-CHI \
		p5-Moose>=0.66:devel/p5-Moose
TEST_DEPENDS=	p5-Test-Class>=0:devel/p5-Test-Class

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/CHI/Driver/Memcached/Test
	@${RM} -r ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/CHI/Driver/Memcached/t

.include <bsd.port.mk>
