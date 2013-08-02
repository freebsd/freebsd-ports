# Created by: Mikhail T. <michael@fun-box.ru>
# $FreeBSD$

PORTNAME=	DateTime-Event-Zodiac
PORTVERSION=	1.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Return zodiac for a given date

RUN_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Util-Astro>=0:${PORTSDIR}/devel/p5-DateTime-Util-Astro \
		p5-Exporter-Lite>=0:${PORTSDIR}/devel/p5-Exporter-Lite
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage

USES=		perl5
USE_PERL5=	configure

MAN3=		DateTime::Event::Zodiac.3

.include <bsd.port.mk>
