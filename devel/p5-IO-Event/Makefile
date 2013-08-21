# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	IO-Event
PORTVERSION=	0.812
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tied Filehandles for Nonblocking IO with Object Callbacks

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-AnyEvent>=0:${PORTSDIR}/devel/p5-AnyEvent

OPTIONS_DEFINE=	ANYEVENT EVENT
OPTIONS_DEFAULT=ANYEVENT EVENT
EVENT_DESC=	Use Event as underlying event handler
ANYEVENT_DESC=	Use AnyEvent as underlying event handler

USE_PERL5=	configure
USES=		perl5

MAN3=		IO::Event.3 \
		IO::Event::Callback.3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MANYEVENT}
BUILD_DEPENDS+=	p5-AnyEvent>=0:${PORTSDIR}/devel/p5-AnyEvent
RUN_DEPENDS+=	p5-AnyEvent>=0:${PORTSDIR}/devel/p5-AnyEvent
.endif

.if ${PORT_OPTIONS:MEVENT}
BUILD_DEPENDS+=	p5-Event>=0:${PORTSDIR}/devel/p5-Event
RUN_DEPENDS+=	p5-Event>=0:${PORTSDIR}/devel/p5-Event
.endif

.include <bsd.port.mk>
