# Created by: Simon Olofsson <simon@olofsson.de>
# $FreeBSD$

PORTNAME=	Weather-Underground
PORTVERSION=	3.03
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Weather
PKGNAMEPREFIX=	p5-

MAINTAINER=	simon@olofsson.de
COMMENT=	Retrieve weather information from wunderground.com

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_STAGE=	yes

MAN3=		Weather::Underground.3

.include <bsd.port.mk>
