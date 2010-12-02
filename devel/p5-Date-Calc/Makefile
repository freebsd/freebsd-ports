# New ports collection makefile for:	p5-Date-Calc
# Date created:				25 February 2000
# Whom:	      				Brad Hendrickse <bradh@uunet.co.za>
#
# $FreeBSD$
#

PORTNAME=	Date-Calc
PORTVERSION=	6.3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Gregorian calendar date calculations

RUN_DEPENDS=	p5-Bit-Vector>=7.1:${PORTSDIR}/math/p5-Bit-Vector \
		p5-Carp-Clan>=5.3:${PORTSDIR}/devel/p5-Carp-Clan
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Date::Calc.3 Date::Calc::PP.3 Date::Calc::Object.3 Date::Calendar.3 \
		Date::Calendar::Profiles.3 Date::Calendar::Year.3

.include <bsd.port.mk>
