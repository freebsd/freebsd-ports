# $FreeBSD$

PORTNAME=	Test-Deep-UnorderedPairs
PORTVERSION=	0.006
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=CPAN:ETHER
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Plugin for Test::Deep to compare unordered lists of tuples

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes
PLIST_FILES=	${SITE_PERL_REL}/Test/Deep/UnorderedPairs.pm \
		${SITE_MAN3_REL}/Test::Deep::UnorderedPairs.3.gz

.include <bsd.port.mk>
