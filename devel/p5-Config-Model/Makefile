# Created by: ijliao
# $FreeBSD$

PORTNAME=	Config-Model
PORTVERSION=	2.052
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DDUMONT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Model to create configuration validation tool

LICENSE=	LGPL21

BUILD_DEPENDS=	p5-AnyEvent>=0:${PORTSDIR}/devel/p5-AnyEvent \
		p5-AnyEvent-HTTP>=0:${PORTSDIR}/www/p5-AnyEvent-HTTP \
		p5-Carp-Assert-More>=0:${PORTSDIR}/devel/p5-Carp-Assert-More \
		p5-EV>=0:${PORTSDIR}/devel/p5-EV \
		p5-Exception-Class>=0:${PORTSDIR}/devel/p5-Exception-Class \
		p5-File-HomeDir>=0:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Hash-Merge>=0.12:${PORTSDIR}/textproc/p5-Hash-Merge \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Log-Log4perl>=1.11:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Mouse>=0:${PORTSDIR}/devel/p5-Mouse \
		p5-MouseX-NativeTraits>=0:${PORTSDIR}/devel/p5-MouseX-NativeTraits \
		p5-MouseX-StrictConstructor>=0:${PORTSDIR}/devel/p5-MouseX-StrictConstructor \
		p5-Parse-RecDescent>=1.90.0:${PORTSDIR}/devel/p5-Parse-RecDescent \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Pod-POM>=0:${PORTSDIR}/textproc/p5-Pod-POM \
		p5-Text-Autoformat>=0:${PORTSDIR}/textproc/p5-Text-Autoformat \
		p5-Text-Diff>=0:${PORTSDIR}/textproc/p5-Text-Diff \
		p5-YAML>=0.30.3:${PORTSDIR}/textproc/p5-YAML \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Config-Model-Tester>=2.046:${PORTSDIR}/devel/p5-Config-Model-Tester \
		p5-Probe-Perl>=0:${PORTSDIR}/sysutils/p5-Probe-Perl \
		p5-Test-Command>=0:${PORTSDIR}/devel/p5-Test-Command \
		p5-Test-Differences>=0:${PORTSDIR}/devel/p5-Test-Differences \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-File-Contents>=0:${PORTSDIR}/devel/p5-Test-File-Contents \
		p5-Test-Memory-Cycle>=0:${PORTSDIR}/devel/p5-Test-Memory-Cycle \
		p5-Test-Warn>=0:${PORTSDIR}/devel/p5-Test-Warn

USES=		perl5 shebangfix
USE_PERL5=	modbuild

SHEBANG_FILES=	lib/Config/Model/extensions/cme-gen-class-pod

.include <bsd.port.mk>
