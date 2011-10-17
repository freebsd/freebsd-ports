# New ports collection makefile for:	p5-Bread-Board
# Date created:		2011-05-31
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Bread-Board
PORTVERSION=	0.24
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:STEVAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A solderless way to wire up your application components

OPTIONS=	GRAPHVIZ "Using Graphviz to visualize a Bread::Board system" off

BUILD_DEPENDS=	p5-Moose>=2:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Clone>=0.05:${PORTSDIR}/devel/p5-MooseX-Clone \
		p5-MooseX-Params-Validate>=0.14:${PORTSDIR}/devel/p5-MooseX-Params-Validate \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny
RUN_DEPENDS=	p5-Moose>=2:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Clone>=0.05:${PORTSDIR}/devel/p5-MooseX-Clone \
		p5-MooseX-Params-Validate>=0.14:${PORTSDIR}/devel/p5-MooseX-Params-Validate \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny

TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires

PERL_CONFIGURE=	yes

MAN1=		visualize-breadboard.1
MAN3=		Bread::Board.3 \
		Bread::Board::BlockInjection.3 \
		Bread::Board::ConstructorInjection.3 \
		Bread::Board::Container.3 \
		Bread::Board::Container::Parameterized.3 \
		Bread::Board::Dependency.3 \
		Bread::Board::Dumper.3 \
		Bread::Board::GraphViz.3 \
		Bread::Board::GraphViz::App.3 \
		Bread::Board::LifeCycle.3 \
		Bread::Board::LifeCycle::Singleton.3 \
		Bread::Board::LifeCycle::Singleton::WithParameters.3 \
		Bread::Board::Literal.3 \
		Bread::Board::Manual.3 \
		Bread::Board::Manual::Concepts.3 \
		Bread::Board::Manual::Concepts::Advanced.3 \
		Bread::Board::Manual::Concepts::Typemap.3 \
		Bread::Board::Manual::Example.3 \
		Bread::Board::Manual::Example::FormSensible.3 \
		Bread::Board::Manual::Example::LogDispatch.3 \
		Bread::Board::Service.3 \
		Bread::Board::Service::Alias.3 \
		Bread::Board::Service::Deferred.3 \
		Bread::Board::Service::Deferred::Thunk.3 \
		Bread::Board::Service::Inferred.3 \
		Bread::Board::Service::WithClass.3 \
		Bread::Board::Service::WithDependencies.3 \
		Bread::Board::Service::WithParameters.3 \
		Bread::Board::SetterInjection.3 \
		Bread::Board::Traversable.3 \
		Bread::Board::Types.3

.include <bsd.port.options.mk>

.if defined(WITH_GRAPHVIZ)
BUILD_DEPENDS+=	p5-Data-Visitor>=0:${PORTSDIR}/devel/p5-Data-Visitor \
		p5-GraphViz>=0:${PORTSDIR}/graphics/p5-GraphViz \
		p5-MooseX-Runnable>=0:${PORTSDIR}/devel/p5-MooseX-Runnable \
		p5-MooseX-Types-Set-Object>=0:${PORTSDIR}/devel/p5-MooseX-Types-Set-Object \
		p5-Set-Object>=0:${PORTSDIR}/devel/p5-Set-Object
RUN_DEPENDS+=	p5-Data-Visitor>=0:${PORTSDIR}/devel/p5-Data-Visitor \
		p5-GraphViz>=0:${PORTSDIR}/graphics/p5-GraphViz \
		p5-MooseX-Runnable>=0:${PORTSDIR}/devel/p5-MooseX-Runnable \
		p5-MooseX-Types-Set-Object>=0:${PORTSDIR}/devel/p5-MooseX-Types-Set-Object \
		p5-Set-Object>=0:${PORTSDIR}/devel/p5-Set-Object
.endif

post-patch:
.if defined(WITH_GRAPHVIZ)
	@${REINPLACE_CMD} -e 's|^# require|require|' ${WRKSRC}/Makefile.PL
.else
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
