# ex:ts=8
# Ports collection makefile for:	Astro-ADS
# Date created:			Oct 19, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Astro-ADS
PORTVERSION=	1.20.7
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Astro
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	An OO Perl interface to the ADS abstract service

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww

MAKE_JOBS_SAFE=  yes

PERL_CONFIGURE=	yes

MAN1=	adsquery.1
MAN3=	Astro::ADS.3 Astro::ADS::Query.3 Astro::ADS::Result.3 Astro::ADS::Result::Paper.3

.include <bsd.port.mk>
