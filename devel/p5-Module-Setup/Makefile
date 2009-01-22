# New ports collection makefile for:	Module::Setup
# Date created:		22 Jan 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Module-Setup
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for a simple module maker

RUN_DEPENDS=	\
	p5-Class-Trigger>0:${PORTSDIR}/devel/p5-Class-Trigger \
	p5-File-Find-Rule>0:${PORTSDIR}/devel/p5-File-Find-Rule \
	p5-File-HomeDir>0:${PORTSDIR}/devel/p5-File-HomeDir \
	p5-Module-Collect>=0.04:${PORTSDIR}/devel/p5-Module-Collect \
	p5-Path-Class>0:${PORTSDIR}/devel/p5-Path-Class \
	p5-Template-Toolkit>=2.20:${PORTSDIR}/www/p5-Template-Toolkit \
	p5-YAML>0:${PORTSDIR}/textproc/p5-YAML \
	p5-Module-Install-AuthorTests>0:${PORTSDIR}/devel/p5-Module-Install-AuthorTests
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		module-setup.1
MAN3=		Module::Setup.3 \
		Module::Setup::Flavor.3 \
		Module::Setup::Flavor::CodeRepos.3 \
		Module::Setup::Flavor::Default.3 \
		Module::Setup::Plugin.3 \
		Module::Setup::Plugin::VC::Git.3

.include <bsd.port.mk>
