# New ports collection makefile for:   p5-Date-ICal
# Date created:                12 May 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	Date-ICal
PORTVERSION=	2.678
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for ICalendar date objects

BUILD_DEPENDS=	p5-Date-Leapyear>=1.03:${PORTSDIR}/devel/p5-Date-Leapyear
RUN_DEPENDS=	p5-Date-Leapyear>=1.03:${PORTSDIR}/devel/p5-Date-Leapyear

PERL_CONFIGURE=	yes

MAN3=		Date::ICal.3 Date::ICal::Duration.3

.include <bsd.port.mk>
