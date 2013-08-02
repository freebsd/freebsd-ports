# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Data-ICal
PORTVERSION=	0.20
CATEGORIES=	deskutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TSIBLEY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Data::ICal - Generates iCalendar (RFC 2445) calendar files

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-ReturnValue>=0:${PORTSDIR}/devel/p5-Class-ReturnValue \
		p5-Text-vFile-asData>=0:${PORTSDIR}/devel/p5-Text-vFile-asData
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-LongString>=0:${PORTSDIR}/devel/p5-Test-LongString \
		p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings \
		p5-Test-Pod>=1.14:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.04:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
		p5-Test-Warn>=0:${PORTSDIR}/devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure

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

post-patch:
	@${REINPLACE_CMD} -e '/^auto_install/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
