# New ports collection makefile for:	Time-modules
# Date created:	   09 December 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Time-modules
PORTVERSION=	2002.1001
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Time
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Time::CTime.3 Time::DaysInMonth.3 Time::JulianDay.3 \
		Time::ParseDate.3 Time::Timezone.3

.include <bsd.port.mk>
