PORTNAME=	Date-Calc-XS
PORTVERSION=	6.4
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	XS wrapper and C library plug-in for Date::Calc

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Date-Calc>=6.4:devel/p5-Date-Calc \
		p5-Bit-Vector>=7.4:math/p5-Bit-Vector \
		p5-Carp-Clan>=5.3:devel/p5-Carp-Clan

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
