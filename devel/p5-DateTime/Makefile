# Created by: Mathieu Arnold <m@absolight.net>
# $FreeBSD$

PORTNAME=	DateTime
PORTVERSION=	1.28
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Date and time object

LICENSE=	ART20

# Do not add p5-DateTime-Format-Strptime>=1.20.00 to TEST_DEPENDS to avoid cyclic dependency in tinderbox
BUILD_DEPENDS=	p5-DateTime-Locale>=0.41:devel/p5-DateTime-Locale \
		p5-DateTime-TimeZone>=1.74:devel/p5-DateTime-TimeZone \
		p5-Params-Validate>=1.03:devel/p5-Params-Validate \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Warnings>=0.005:devel/p5-Test-Warnings

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/DateTime/DateTime.so

.include <bsd.port.mk>
