# ex:ts=8
# New ports collection makefile for:	p5-Date-DayOfWeek
# Date created:			Jun 5, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Date-DayOfWeek
PORTVERSION=	1.21
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Date
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org

BUILD_DEPENDS=	${SITE_PERL}/Date/Leapyear.pm:${PORTSDIR}/devel/p5-Date-Leapyear \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	Date::DayOfWeek.3 Date::DayOfWeek::Birthday.3 \
	Date::DayOfWeek::Nails.3 Date::DayOfWeek::Sneeze.3 Date::Doomsday.3

.include <bsd.port.mk>
