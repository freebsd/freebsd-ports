# New ports collection makefile for:	p5-GPS
# Date created:			5 December 2000
# Whom:				Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$

PORTNAME=	GPS
PORTVERSION=	0.12
CATEGORIES=	astro perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	perl-gps
PKGNAMEPREFIX=	p5-
DISTNAME=	perl-GPS-${PORTVERSION}

MAINTAINER=	jeremy@external.org

PERL_CONFIGURE=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		GPS::Garmin.3 \
		GPS::Serial.3 \
		GPS::Garmin::Handler.3

.include <bsd.port.mk>
