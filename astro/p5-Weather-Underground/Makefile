# New ports collection makefile for:	p5-Weather-Underground
# Date created:		2006-05-16
# Whom:			Simon Olofsson <simon@olofsson.de>
#
# $FreeBSD$
#

PORTNAME=	Weather-Underground
PORTVERSION=	3.02
CATEGORIES=	astro perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Weather
PKGNAMEPREFIX=	p5-

MAINTAINER=	simon@olofsson.de
COMMENT=	Retrieve weather information from wunderground.com

BUILD_DEPENDS=	${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/HTML/TokeParser.pm:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		Weather::Underground.3

.include <bsd.port.mk>
