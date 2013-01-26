# Created by: George Hartzell <hartzell@alerce.com>
# $FreeBSD$

PORTNAME=	App-Cmd
PORTVERSION=	0.319
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	App::Cmd - Write command line apps with less suffering

BUILD_DEPENDS=	p5-Capture-Tiny>=0.13:${PORTSDIR}/devel/p5-Capture-Tiny \
		p5-Class-Load>=0.06:${PORTSDIR}/devel/p5-Class-Load \
		p5-Getopt-Long-Descriptive>=0.084:${PORTSDIR}/devel/p5-Getopt-Long-Descriptive \
		p5-IO-TieCombine>=0:${PORTSDIR}/devel/p5-IO-TieCombine \
		p5-String-RewritePrefix>=0:${PORTSDIR}/textproc/p5-String-RewritePrefix \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-Sub-Install>=0:${PORTSDIR}/devel/p5-Sub-Install
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal

PERL_CONFIGURE=	yes

MAN3=		App::Cmd.3 \
		App::Cmd::ArgProcessor.3 \
		App::Cmd::Command.3 \
		App::Cmd::Command::commands.3 \
		App::Cmd::Command::help.3 \
		App::Cmd::Plugin.3 \
		App::Cmd::Setup.3 \
		App::Cmd::Simple.3 \
		App::Cmd::Subdispatch.3 \
		App::Cmd::Subdispatch::DashedStyle.3 \
		App::Cmd::Tester.3 \
		App::Cmd::Tester::CaptureExternal.3 \
		App::Cmd::Tutorial.3 \

.include <bsd.port.mk>
