# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Date-Manip
PORTVERSION=	6.34
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SBECK
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Perl5 module containing date manipulation routines

BUILD_DEPENDS=	p5-YAML-Syck>=1.15:${PORTSDIR}/textproc/p5-YAML-Syck
RUN_DEPENDS=	p5-YAML-Syck>=1.15:${PORTSDIR}/textproc/p5-YAML-Syck
TEST_DEPENDS=	p5-Test-Inter>=0:${PORTSDIR}/devel/p5-Test-Inter

USES=		perl5
USE_PERL5=	configure

MAN1=	dm_date.1 dm_zdump.1
MAN3=	Date::Manip.3 Date::Manip::Base.3 Date::Manip::Calc.3 \
	Date::Manip::Changes5.3 Date::Manip::Changes5to6.3 \
	Date::Manip::Changes6.3 Date::Manip::Config.3 \
	Date::Manip::ConfigFile.3 \
	Date::Manip::DM5.3 Date::Manip::DM5abbrevs.3 \
	Date::Manip::DM6.3 Date::Manip::Date.3 \
	Date::Manip::Delta.3 Date::Manip::Examples.3 \
	Date::Manip::Holidays.3 Date::Manip::Lang.3 \
	Date::Manip::Lang::finnish.3 \
	Date::Manip::Migration5to6.3 Date::Manip::Misc.3 \
	Date::Manip::Obj.3 Date::Manip::Objects.3 \
	Date::Manip::Problems.3 Date::Manip::Recur.3 \
	Date::Manip::TZ.3 Date::Manip::TZ_Base.3 \
	Date::Manip::TZdata.3 Date::Manip::Zones.3

NO_STAGE=	yes
.include "extramanpages.mk"
.include <bsd.port.mk>
