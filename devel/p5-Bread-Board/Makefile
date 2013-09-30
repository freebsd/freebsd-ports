# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Bread-Board
PORTVERSION=	0.25
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:STEVAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Solderless way to wire up your application components

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=2:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Clone>=0.05:${PORTSDIR}/devel/p5-MooseX-Clone \
		p5-MooseX-Params-Validate>=0.14:${PORTSDIR}/devel/p5-MooseX-Params-Validate \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Form-Sensible>=0:${PORTSDIR}/devel/p5-Form-Sensible \
		p5-Log-Dispatch>=0:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires

OPTIONS_DEFINE=	GRAPHVIZ
GRAPHVIZ_DESC=	Visualize a Bread::Board system via Graphviz

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGRAPHVIZ}
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
.if ${PORT_OPTIONS:MGRAPHVIZ}
	@${REINPLACE_CMD} -e 's|^# require|require|' ${WRKSRC}/Makefile.PL
.else
.endif

.include <bsd.port.mk>
