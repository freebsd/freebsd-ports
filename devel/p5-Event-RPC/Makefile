# Created by: Vivek Khera <vivek@khera.org>
# $FreeBSD$

PORTNAME=	Event-RPC
PORTVERSION=	1.03
PORTREVISION=	1
CATEGORIES=	devel net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vivek@khera.org
COMMENT=	Event based transparent Client/Server RPC framework

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	GLIB EVENT ANYEVENT SSL
GLIB_DESC=	Dependency to Glib event handler
EVENT_DESC=	Dependency to Event.pm event handler
ANYEVENT_DESC=	Dependency to AnyEvent event handler
SSL_DESC=	Dependency to SSL lib

OPTIONS_DEFAULT=	EVENT ANYEVENT SSL

.include <bsd.port.options.mk>

BUILD_DEPENDS=	p5-Storable>=0:devel/p5-Storable

.if ${PORT_OPTIONS:MEVENT}
BUILD_DEPENDS+=	p5-Event>=0:devel/p5-Event
.endif

.if ${PORT_OPTIONS:MANYEVENT}
BUILD_DEPENDS+=	p5-AnyEvent>=0:devel/p5-AnyEvent
.endif

.if ${PORT_OPTIONS:MGLIB}
BUILD_DEPENDS+=	p5-Glib2>=0:devel/p5-Glib2
.endif

.if ${PORT_OPTIONS:MSSL}
USES+=		ssl
BUILD_DEPENDS+=	p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL
.endif

RUN_DEPENDS:=	${BUILD_DEPENDS}

.include <bsd.port.mk>
