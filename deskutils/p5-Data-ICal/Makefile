# New ports collection makefile for:	deskutils/p5-Data-ICal
# Date created:				10 November 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Data-ICal
PORTVERSION=	0.13
CATEGORIES=	deskutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Data::ICal - Generates iCalendar (RFC 2445) calendar files
TAGS=	calendar ical devel

BUILD_DEPENDS=	${SITE_PERL}/Test/LongString.pm:${PORTSDIR}/devel/p5-Test-LongString \
		${SITE_PERL}/Test/Warn.pm:${PORTSDIR}/devel/p5-Test-Warn \
		${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/Test/NoWarnings.pm:${PORTSDIR}/devel/p5-Test-NoWarnings \
		${SITE_PERL}/Text/vFile/asData.pm:${PORTSDIR}/devel/p5-Text-vFile-asData \
		p5-Class-ReturnValue>0:${PORTSDIR}/devel/p5-Class-ReturnValue
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Data::ICal.3 \
	Data::ICal::Entry.3 \
	Data::ICal::Entry::Alarm::Audio.3 \
	Data::ICal::Entry::Alarm::Display.3 \
	Data::ICal::Entry::Alarm::Email.3 \
	Data::ICal::Entry::Alarm::Procedure.3 \
	Data::ICal::Entry::Event.3 \
	Data::ICal::Entry::FreeBusy.3 \
	Data::ICal::Entry::Journal.3 \
	Data::ICal::Entry::TimeZone.3 \
	Data::ICal::Entry::TimeZone::Daylight.3 \
	Data::ICal::Entry::TimeZone::Standard.3 \
	Data::ICal::Entry::Todo.3 \
	Data::ICal::Property.3

.include <bsd.port.mk>
