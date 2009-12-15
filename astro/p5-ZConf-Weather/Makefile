# New ports collection makefile for:	p5-ZConf-Weather
# Date created:		2009-09-27
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	ZConf-Weather
PORTVERSION=	1.0.0
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/V/VV/VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	A ZConf module to assist with fetching/printing weather information

BUILD_DEPENDS=	${SITE_PERL}/ZConf.pm:${PORTSDIR}/net/p5-ZConf \
		${SITE_PERL}/Text/NeatTemplate.pm:${PORTSDIR}/textproc/p5-Text-NeatTemplate \
		${SITE_PERL}/Weather/Underground.pm:${PORTSDIR}/astro/p5-Weather-Underground

PERL_CONFIGURE=	yes

MAN3=		ZConf::Weather.3

.include <bsd.port.mk>
