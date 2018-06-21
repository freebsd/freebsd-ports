# $FreeBSD$

PORTNAME=	Test-Mock-Redis
PORTVERSION=	0.20
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Use in place of Redis for unit testing

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Module-Build>=0.4:devel/p5-Module-Build \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Deep-UnorderedPairs>=0:devel/p5-Test-Deep-UnorderedPairs \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal
RUN_DEPENDS=	p5-Class-Method-Modifiers>=0:devel/p5-Class-Method-Modifiers \
		p5-Package-Stash>=0.34:devel/p5-Package-Stash \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-namespace-clean>=0:devel/p5-namespace-clean

USES=		perl5
USE_PERL5=	modbuild
PLIST_FILES=	${SITE_PERL_REL}/Test/Mock/Redis.pm \
		${SITE_MAN3_REL}/Test::Mock::Redis.3.gz

.include <bsd.port.mk>
