# New ports collection makefile for:	p5-Date-Manip
# Date created:				April 28th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Date-Manip
PORTVERSION=	6.22
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SBECK
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Perl5 module containing date manipulation routines

RUN_DEPENDS=	p5-YAML-Syck>=1.15:${PORTSDIR}/textproc/p5-YAML-Syck

PERL_CONFIGURE=	YES

MAN3=	Date::Manip.3 Date::Manip::Base.3 Date::Manip::Calc.3 \
	Date::Manip::Changes5.3 Date::Manip::Changes5to6.3 \
	Date::Manip::Changes6.3 Date::Manip::Config.3 \
	Date::Manip::ConfigFile.3 \
	Date::Manip::DM5.3 Date::Manip::DM5abbrevs.3 \
	Date::Manip::DM6.3 Date::Manip::Date.3 \
	Date::Manip::Delta.3 Date::Manip::Examples.3 \
	Date::Manip::Holidays.3 Date::Manip::Lang.3 \
	Date::Manip::Migration5to6.3 Date::Manip::Misc.3 \
	Date::Manip::Obj.3 Date::Manip::Objects.3 \
	Date::Manip::Problems.3 Date::Manip::Recur.3 \
	Date::Manip::TZ.3 Date::Manip::TZ_Base.3 \
	Date::Manip::TZdata.3 Date::Manip::Zones.3

.include "extramanpages.mk"
.include <bsd.port.mk>
