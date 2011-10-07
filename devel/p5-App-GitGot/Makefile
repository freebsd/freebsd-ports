# New ports collection makefile for:	p5-App-GitGot
# Date created:		2010-11-12
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	App-GitGot
PORTVERSION=	1.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Tool to make it easier to manage multiple git repositories

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Config-INI>=0:${PORTSDIR}/devel/p5-Config-INI \
		p5-Data-Dumper>=0:${PORTSDIR}/devel/p5-Data-Dumper \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Git-Wrapper>=0.014:${PORTSDIR}/devel/p5-Git-Wrapper \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-App-Cmd>=0:${PORTSDIR}/devel/p5-MooseX-App-Cmd \
		p5-Net-GitHub>=0:${PORTSDIR}/net/p5-Net-GitHub \
		p5-Term-ANSIColor>=0:${PORTSDIR}/devel/p5-Term-ANSIColor \
		p5-Test-MockObject>=0:${PORTSDIR}/devel/p5-Test-MockObject \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean

RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Class>=0:${PORTSDIR}/devel/p5-Test-Class \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-File>=0:${PORTSDIR}/devel/p5-Test-File \
		p5-Sort-Versions>=0:${PORTSDIR}/devel/p5-Sort-Versions

PERL_CONFIGURE=	yes

MAN1=		got.1
MAN3=		App::GitGot.3 \
		App::GitGot::Command.3 \
		App::GitGot::Command::add.3 \
		App::GitGot::Command::chdir.3 \
		App::GitGot::Command::clone.3 \
		App::GitGot::Command::fork.3 \
		App::GitGot::Command::gc.3 \
		App::GitGot::Command::list.3 \
		App::GitGot::Command::push.3 \
		App::GitGot::Command::remove.3 \
		App::GitGot::Command::status.3 \
		App::GitGot::Command::update.3 \
		App::GitGot::Command::update_status.3 \
		App::GitGot::Command::version.3 \
		App::GitGot::Outputter::dark.3 \
		App::GitGot::Outputter.3 \
		App::GitGot::Outputter::light.3 \
		App::GitGot::Repo.3 \
		App::GitGot::Repo::Git.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
RUN_DEPENDS+=	p5-autodie>=0:${PORTSDIR}/devel/p5-autodie
.endif

.include <bsd.port.post.mk>
