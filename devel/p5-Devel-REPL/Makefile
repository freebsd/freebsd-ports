# New ports collection makefile for:	p5-Devel-REPL
# Date created:		2009-08-31
# Whom:			Ashish SHUKLA <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Devel-REPL
PORTVERSION=	1.003010
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	A modern perl interactive shell

BUILD_DEPENDS=	p5-Moose>=0.74:${PORTSDIR}/devel/p5-Moose \
	p5-MooseX-Object-Pluggable>=0.0009:${PORTSDIR}/devel/p5-MooseX-Object-Pluggable \
	p5-MooseX-Getopt>=0.18:${PORTSDIR}/devel/p5-MooseX-Getopt \
	p5-MooseX-AttributeHelpers>=0.21:${PORTSDIR}/devel/p5-MooseX-AttributeHelpers \
	p5-namespace-clean>0:${PORTSDIR}/devel/p5-namespace-clean \
	p5-File-HomeDir>0:${PORTSDIR}/devel/p5-File-HomeDir \
	p5-Task-Weaken>0:${PORTSDIR}/devel/p5-Task-Weaken \
	p5-PPI>0:${PORTSDIR}/textproc/p5-PPI \
	p5-Data-Dump-Streamer>0:${PORTSDIR}/devel/p5-Data-Dump-Streamer \
	p5-Data-Dumper-Concise>0:${PORTSDIR}/devel/p5-Data-Dumper-Concise \
	p5-File-Next>0:${PORTSDIR}/sysutils/p5-File-Next \
	p5-B-Keywords>0:${PORTSDIR}/devel/p5-B-Keywords \
	p5-Lexical-Persistence>0:${PORTSDIR}/devel/p5-Lexical-Persistence \
	p5-App-Nopaste>0:${PORTSDIR}/www/p5-App-Nopaste \
	p5-Module-Refresh>0:${PORTSDIR}/devel/p5-Module-Refresh \
	p5-Sys-SigAction>0:${PORTSDIR}/devel/p5-Sys-SigAction
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	Devel::REPL.3 \
	Devel::REPL::Overview.3 \
	Devel::REPL::Plugin::B::Concise.3 \
	Devel::REPL::Plugin::Colors.3 \
	Devel::REPL::Plugin::Commands.3 \
	Devel::REPL::Plugin::Completion.3 \
	Devel::REPL::Plugin::CompletionDriver::Globals.3 \
	Devel::REPL::Plugin::CompletionDriver::INC.3 \
	Devel::REPL::Plugin::CompletionDriver::Keywords.3 \
	Devel::REPL::Plugin::CompletionDriver::LexEnv.3 \
	Devel::REPL::Plugin::CompletionDriver::Methods.3 \
	Devel::REPL::Plugin::CompletionDriver::Turtles.3 \
	Devel::REPL::Plugin::DDC.3 \
	Devel::REPL::Plugin::DDS.3 \
	Devel::REPL::Plugin::DumpHistory.3 \
	Devel::REPL::Plugin::FancyPrompt.3 \
	Devel::REPL::Plugin::FindVariable.3 \
	Devel::REPL::Plugin::History.3 \
	Devel::REPL::Plugin::Interrupt.3 \
	Devel::REPL::Plugin::LexEnv.3 \
	Devel::REPL::Plugin::MultiLine::PPI.3 \
	Devel::REPL::Plugin::NewlineHack.3 \
	Devel::REPL::Plugin::Nopaste.3 \
	Devel::REPL::Plugin::OutputCache.3 \
	Devel::REPL::Plugin::PPI.3 \
	Devel::REPL::Plugin::Packages.3 \
	Devel::REPL::Plugin::Peek.3 \
	Devel::REPL::Plugin::ReadLineHistory.3 \
	Devel::REPL::Plugin::Refresh.3 \
	Devel::REPL::Plugin::ShowClass.3 \
	Devel::REPL::Plugin::Timing.3 \
	Devel::REPL::Plugin::Turtles.3 \
	Devel::REPL::Profile.3

.include <bsd.port.mk>
