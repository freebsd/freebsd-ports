PORTNAME=	Event-RPC
PORTVERSION=	1.03
PORTREVISION=	3
CATEGORIES=	devel net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vivek@khera.org
COMMENT=	Event based transparent Client/Server RPC framework

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	GLIB EVENT ANYEVENT SSL
GLIB_DESC=	Dependency to Glib event handler
EVENT_DESC=	Dependency to Event.pm event handler
ANYEVENT_DESC=	Dependency to AnyEvent event handler
SSL_DESC=	Dependency to SSL lib

OPTIONS_DEFAULT=	EVENT ANYEVENT SSL

ANYEVENT_BUILD_DEPENDS=	p5-AnyEvent>=0:devel/p5-AnyEvent
ANYEVENT_RUN_DEPENDS=	p5-AnyEvent>=0:devel/p5-AnyEvent
EVENT_BUILD_DEPENDS=	p5-Event>=0:devel/p5-Event
EVENT_RUN_DEPENDS=	p5-Event>=0:devel/p5-Event
GLIB_BUILD_DEPENDS=	p5-Glib>=0:devel/p5-Glib
GLIB_RUN_DEPENDS=	p5-Glib>=0:devel/p5-Glib
SSL_BUILD_DEPENDS=	p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL
SSL_RUN_DEPENDS=	p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL
SSL_USES=		ssl

.include <bsd.port.mk>
