# New ports collection makefile for:   p5-Date-ICal
# Date created:                12 May 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	Date-ICal
PORTVERSION=	1.72
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for ICalendar date objects

BUILD_DEPENDS=	${SITE_PERL}/Date/Leapyear.pm:${PORTSDIR}/devel/p5-Date-Leapyear
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Date::ICal.3 Date::ICal::Duration.3

.include <bsd.port.mk>
