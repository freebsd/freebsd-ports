# New ports collection makefile for:	p5-Time
# Date created:				October 12th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Time
PORTVERSION=	101.062101
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Time
PKGNAMEPREFIX=	p5-
DISTNAME=	Time-modules-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A collection of functions to convert and use time variables in perl5

PERL_CONFIGURE=	YES

MAN3=		Time::CTime.3 \
		Time::DaysInMonth.3 \
		Time::JulianDay.3 \
		Time::ParseDate.3 \
		Time::Timezone.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
