# $FreeBSD$

PORTNAME=	CHI-Driver-Redis
PORTVERSION=	0.10
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Redis driver for CHI

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-CHI>=0.36:devel/p5-CHI \
		p5-Moo>=0:devel/p5-Moo \
		p5-Redis>=1.901:databases/p5-Redis \
		p5-URI>=0:net/p5-URI
TEST_DEPENDS=	p5-Test-Class>=0:devel/p5-Test-Class \
		p5-Test-Mock-Redis>=0:devel/p5-Test-Mock-Redis

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes
PLIST_FILES=	${SITE_PERL_REL}/CHI/Driver/Redis.pm \
		${SITE_MAN3_REL}/CHI::Driver::Redis.3.gz

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/CHI/Driver/Redis/t
	${RMDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/CHI/Driver/Redis

.include <bsd.port.mk>
