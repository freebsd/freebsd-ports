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

USE_PERL5=	YES

MAN3=		GPS::Garmin.3 \
		GPS::Serial.3 \
		GPS::Garmin::Handler.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
