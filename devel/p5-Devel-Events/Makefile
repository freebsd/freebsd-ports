# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Devel-Events
PORTVERSION=	0.08
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Perl 5 module providing an extensible instrumentation framework

BUILD_DEPENDS=	p5-Moose>=0.39:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-AttributeHelpers>=0.13:${PORTSDIR}/devel/p5-MooseX-AttributeHelpers \
		p5-Set-Object>=1.19:${PORTSDIR}/devel/p5-Set-Object \
		p5-Time-HiRes>=0.01:${PORTSDIR}/devel/p5-Time-HiRes
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok \
		p5-Sub-Uplevel>=0.18:${PORTSDIR}/devel/p5-Sub-Uplevel

USES=		perl5
USE_PERL5=	configure

MAN3=		Devel::Events.3 \
		Devel::Events::Filter.3 \
		Devel::Events::Filter::Callback.3 \
		Devel::Events::Filter::Drop.3 \
		Devel::Events::Filter::HandlerOptional.3 \
		Devel::Events::Filter::RemoveFields.3 \
		Devel::Events::Filter::Stamp.3 \
		Devel::Events::Filter::Stringify.3 \
		Devel::Events::Filter::Warn.3 \
		Devel::Events::Generator.3 \
		Devel::Events::Generator::LineTrace.3 \
		Devel::Events::Generator::Require.3 \
		Devel::Events::Generator::SubTrace.3 \
		Devel::Events::Handler.3 \
		Devel::Events::Handler::Callback.3 \
		Devel::Events::Handler::Log::Memory.3 \
		Devel::Events::Handler::Multiplex.3 \
		Devel::Events::Match.3

NO_STAGE=	yes
.include <bsd.port.mk>
