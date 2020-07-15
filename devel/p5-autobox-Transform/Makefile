# $FreeBSD$

PORTNAME=	autobox-Transform
PORTVERSION=	1.034
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=CPAN:JOHANL
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Autobox methods to transform Arrays and Hashes

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Sort-Maker>=0:devel/p5-Sort-Maker \
		p5-autobox>=0:devel/p5-autobox \
		p5-autobox-Core>=0:devel/p5-autobox-Core \
		p5-true>=0:devel/p5-true
TEST_DEPENDS=	p5-Moo>=0:devel/p5-Moo \
		p5-Test-Differences>=0:devel/p5-Test-Differences \
		p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	modbuildtiny
PLIST_FILES=	${SITE_PERL}/autobox/Transform.pm \
		${SITE_MAN3_REL}/autobox::Transform.3.gz

NO_ARCH=	yes

.include <bsd.port.mk>
