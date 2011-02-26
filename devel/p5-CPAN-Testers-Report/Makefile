# New ports collection makefile for:	p5-CPAN-Testers-Report
# Date created:		2011-02-05
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CPAN-Testers-Report
PORTVERSION=	1.999001
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/D/DA/DAGOLDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	CPAN Testers report object

BUILD_DEPENDS=	p5-Metabase-Fact>0:${PORTSDIR}/devel/p5-Metabase-Fact
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	CPAN::Testers::Fact::LegacyReport.3 \
	CPAN::Testers::Fact::TestEnvironment.3 \
	CPAN::Testers::Fact::InstalledModules.3 \
	CPAN::Testers::Report.3 \
	CPAN::Testers::Fact::TestSummary.3 \
	CPAN::Testers::Fact::TesterComment.3 \
	CPAN::Testers::Fact::TestOutput.3 \
	CPAN::Testers::Fact::Prereqs.3 \
	CPAN::Testers::Fact::PerlConfig.3

.include <bsd.port.mk>
