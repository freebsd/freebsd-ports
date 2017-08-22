# Created by: Matthew Seaman <matthew@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Data-ICal-DateTime
PORTVERSION=	0.82
CATEGORIES=	deskutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Convenience methods for using Data::ICal with DateTime

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

NO_ARCH=	yes

BUILD_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Data-ICal>=0.07:deskutils/p5-Data-ICal \
		p5-Clone>=0:devel/p5-Clone \
		p5-DateTime-Set>=0:devel/p5-DateTime-Set \
		p5-DateTime-Format-ICal>=0:devel/p5-DateTime-Format-ICal
RUN_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Data-ICal>=0.07:deskutils/p5-Data-ICal \
		p5-Clone>=0:devel/p5-Clone \
		p5-DateTime-Set>=0:devel/p5-DateTime-Set \
		p5-DateTime-Format-ICal>=0:devel/p5-DateTime-Format-ICal
TEST_DEPENDS=	p5-Test-LongString>=0:devel/p5-Test-LongString \
		p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings \
		p5-Test-Warn>=0:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
