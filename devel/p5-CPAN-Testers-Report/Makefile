# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CPAN-Testers-Report
PORTVERSION=	1.999001
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAGOLDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	CPAN Testers report object

BUILD_DEPENDS=	p5-Metabase-Fact>0:${PORTSDIR}/devel/p5-Metabase-Fact
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	CPAN::Testers::Fact::LegacyReport.3 \
	CPAN::Testers::Fact::TestEnvironment.3 \
	CPAN::Testers::Fact::InstalledModules.3 \
	CPAN::Testers::Report.3 \
	CPAN::Testers::Fact::TestSummary.3 \
	CPAN::Testers::Fact::TesterComment.3 \
	CPAN::Testers::Fact::TestOutput.3 \
	CPAN::Testers::Fact::Prereqs.3 \
	CPAN::Testers::Fact::PerlConfig.3

NO_STAGE=	yes
.include <bsd.port.mk>
