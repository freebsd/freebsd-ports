# ex:ts=8
# Ports collection makefile for:	Astro-DSS
# Date created:			Oct 19, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Astro-DSS
PORTVERSION=	1.6.1
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Astro
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	An OO interface to the 1st and 2nd Digital Sky Surveys

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww

MAKE_JOBS_SAFE=  yes

PERL_CONFIGURE=	yes

MAN3=	Astro::DSS.3

.include <bsd.port.mk>
