# New ports collection makefile for:	devel/p5-App-Cmd
# Date created:				07 Oct 2008
# Whom:					George Hartzell <hartzell@alerce.com>
#
# $FreeBSD$
#

PORTNAME=	App-Cmd
PORTVERSION=	0.304
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hartzell@alerce.com
COMMENT=	App::Cmd - Write command line apps with less suffering

BUILD_DEPENDS=	\
		p5-Getopt-Long-Descriptive>=0.06:${PORTSDIR}/devel/p5-Getopt-Long-Descriptive \
		p5-Module-Pluggable>=0:${PORTSDIR}/devel/p5-Module-Pluggable \
		p5-Sub-Exporter>=0.975:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-IO-TieCombine>=0:${PORTSDIR}/devel/p5-IO-TieCombine \
		p5-Sub-Install>=0:${PORTSDIR}/devel/p5-Sub-Install
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	App::Cmd.3 \
	App::Cmd::Command.3 \
	App::Cmd::Tester.3 \
	App::Cmd::Subdispatch.3 \
	App::Cmd::Subdispatch::DashedStyle.3 \
	App::Cmd::Command::help.3 \
	App::Cmd::Tutorial.3 \
	App::Cmd::Simple.3 \
	App::Cmd::ArgProcessor.3 \
	App::Cmd::Command::commands.3

.include <bsd.port.mk>
