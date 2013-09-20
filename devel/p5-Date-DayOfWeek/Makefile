# Created by: ijliao
# $FreeBSD$

PORTNAME=	Date-DayOfWeek
PORTVERSION=	1.22
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Determine the day of the week for any date

BUILD_DEPENDS=	p5-Date-Leapyear>=0:${PORTSDIR}/devel/p5-Date-Leapyear \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Date::DayOfWeek.3 Date::DayOfWeek::Birthday.3 \
	Date::DayOfWeek::Nails.3 Date::DayOfWeek::Sneeze.3 Date::Doomsday.3

NO_STAGE=	yes
.include <bsd.port.mk>
