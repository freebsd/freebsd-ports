# ex:ts=8
# Ports collection makefile for:	Astro-SIMBAD
# Date created:			Oct 19, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Astro-SIMBAD
PORTVERSION=	2.0.0
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Astro
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An OO Perl interface to the SIMBAD astronomical database

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww

MAKE_JOBS_SAFE=  yes

PERL_CONFIGURE=	yes

MAN3=	Astro::SIMBAD.3 \
	Astro::SIMBAD::Query.3 \
	Astro::SIMBAD::Result.3 \
	Astro::SIMBAD::Result::Object.3

.include <bsd.port.mk>
