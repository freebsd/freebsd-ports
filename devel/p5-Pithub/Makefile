# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Pithub
PORTVERSION=	0.01.020
CATEGORIES=	devel
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ANDREMAR
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Github v3 API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Array-Iterator>=0:${PORTSDIR}/devel/p5-Array-Iterator \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-LWP-Protocol-https>=0:${PORTSDIR}/www/p5-LWP-Protocol-https \
		p5-Moo>=0:${PORTSDIR}/devel/p5-Moo \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Test-Most>=0:${PORTSDIR}/devel/p5-Test-Most

USE_PERL5=	configure
USES=		perl5

MAN3=		Pithub.3 \
		Pithub::Base.3 \
		Pithub::Events.3 \
		Pithub::Gists.3 \
		Pithub::Gists::Comments.3 \
		Pithub::GitData.3 \
		Pithub::GitData::Blobs.3 \
		Pithub::GitData::Commits.3 \
		Pithub::GitData::References.3 \
		Pithub::GitData::Tags.3 \
		Pithub::GitData::Trees.3 \
		Pithub::Issues.3 \
		Pithub::Issues::Assignees.3 \
		Pithub::Issues::Comments.3 \
		Pithub::Issues::Events.3 \
		Pithub::Issues::Labels.3 \
		Pithub::Issues::Milestones.3 \
		Pithub::Orgs.3 \
		Pithub::Orgs::Members.3 \
		Pithub::Orgs::Teams.3 \
		Pithub::PullRequests.3 \
		Pithub::PullRequests::Comments.3 \
		Pithub::Repos.3 \
		Pithub::Repos::Collaborators.3 \
		Pithub::Repos::Commits.3 \
		Pithub::Repos::Contents.3 \
		Pithub::Repos::Downloads.3 \
		Pithub::Repos::Forks.3 \
		Pithub::Repos::Hooks.3 \
		Pithub::Repos::Keys.3 \
		Pithub::Repos::Starring.3 \
		Pithub::Repos::Stats.3 \
		Pithub::Repos::Watching.3 \
		Pithub::Result.3 \
		Pithub::Search.3 \
		Pithub::Users.3 \
		Pithub::Users::Emails.3 \
		Pithub::Users::Followers.3 \
		Pithub::Users::Keys.3

NO_STAGE=	yes
.include <bsd.port.mk>
