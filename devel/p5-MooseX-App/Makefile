# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MooseX-App
PORTVERSION=	1.15
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Write user-friendly command line apps with even less suffering

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Config-Any>=0:${PORTSDIR}/devel/p5-Config-Any \
		p5-Moose>=2:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Getopt>=0.43:${PORTSDIR}/devel/p5-MooseX-Getopt \
		p5-MooseX-Types-Path-Class>=0:${PORTSDIR}/devel/p5-MooseX-Types-Path-Class \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Pod-Elemental>=0:${PORTSDIR}/textproc/p5-Pod-Elemental \
		p5-String-CamelCase>=0:${PORTSDIR}/textproc/p5-String-CamelCase \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Most>=0:${PORTSDIR}/devel/p5-Test-Most \
		p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings

PERL_CONFIGURE=	yes

MAN3=		MooseX::App.3 \
		MooseX::App::Command.3 \
		MooseX::App::Message::Block.3 \
		MooseX::App::Message::Envelope.3 \
		MooseX::App::Meta::Role::Class::Base.3 \
		MooseX::App::Meta::Role::Class::Command.3 \
		MooseX::App::Plugin::BashCompletion.3 \
		MooseX::App::Plugin::Color.3 \
		MooseX::App::Plugin::Config.3 \
		MooseX::App::Plugin::ConfigHome.3 \
		MooseX::App::Plugin::Env.3 \
		MooseX::App::Plugin::Typo.3 \
		MooseX::App::Plugin::Version.3 \
		MooseX::App::Role.3 \
		MooseX::App::Simple.3 \
		MooseX::App::Tutorial.3 \
		MooseX::App::WritingPlugins.3

.include <bsd.port.mk>
