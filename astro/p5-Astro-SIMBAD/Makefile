# ex:ts=8
# Ports collection makefile for:	Astro-SIMBAD
# Date created:			Oct 19, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Astro-SIMBAD
PORTVERSION=	1.9.5
CATEGORIES=	astro perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://www.estar.org.uk/software/
MASTER_SITE_SUBDIR=	Astro
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OO Perl interface to the SIMBAD astronomical database

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	Astro::SIMBAD.3 \
	Astro::SIMBAD::Query.3 \
	Astro::SIMBAD::Result.3 \
	Astro::SIMBAD::Result::Object.3

.include <bsd.port.mk>
