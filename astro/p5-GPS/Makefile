# Created by: Jeremy Shaffner <jeremy@external.org>
# $FreeBSD$

PORTNAME=	GPS
PORTVERSION=	0.17
CATEGORIES=	astro perl5 geography
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	perl-GPS-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Perl interface to GPS receivers

BUILD_DEPENDS=	p5-Device-SerialPort>=0.07:${PORTSDIR}/comms/p5-Device-SerialPort
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		GPS::Serial.3 \
		GPS::NMEA.3 \
		GPS::NMEA::Handler.3 \
		GPS::Garmin.3 \
		GPS::Garmin::Handler.3

.include <bsd.port.mk>
