# Created by: ijliao
# $FreeBSD$

PORTNAME=	Astro-SIMBAD
PORTVERSION=	2.0.0
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Astro
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	OO Perl interface to the SIMBAD astronomical database

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww

USES=		perl5
USE_PERL5=	configure

MAN3=	Astro::SIMBAD.3 \
	Astro::SIMBAD::Query.3 \
	Astro::SIMBAD::Result.3 \
	Astro::SIMBAD::Result::Object.3

.include <bsd.port.mk>
