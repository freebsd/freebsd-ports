# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	DateTimeX-Easy
PORTVERSION=	0.089
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parse a date/time string using the best method available

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-DateParse>=0:${PORTSDIR}/devel/p5-DateTime-Format-DateParse \
		p5-DateTime-Format-Flexible>=0:${PORTSDIR}/devel/p5-DateTime-Format-Flexible \
		p5-DateTime-Format-ICal>=0:${PORTSDIR}/devel/p5-DateTime-Format-ICal \
		p5-DateTime-Format-Natural>=0:${PORTSDIR}/devel/p5-DateTime-Format-Natural \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Most>=0:${PORTSDIR}/devel/p5-Test-Most

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
