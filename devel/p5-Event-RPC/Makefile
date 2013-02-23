# Created by: Vivek Khera <vivek@khera.org>
# $FreeBSD$

PORTNAME=	Event-RPC
PORTVERSION=	1.03
CATEGORIES=	devel net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vivek@khera.org
COMMENT=	Event based transparent Client/Server RPC framework

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

PERL_CONFIGURE=	yes

MAN3=	Event::RPC.3 \
	Event::RPC::Client.3 \
	Event::RPC::Connection.3 \
	Event::RPC::LogConnection.3 \
	Event::RPC::Logger.3 \
	Event::RPC::Loop.3 \
	Event::RPC::Loop::AnyEvent.3 \
	Event::RPC::Loop::Event.3 \
	Event::RPC::Loop::Glib.3 \
	Event::RPC::Message.3 \
	Event::RPC::Server.3

OPTIONS=	GLIB	"Register dependency to Glib event handler"	off \
		EVENT	"Register dependency to Event.pm event handler"	on \
		ANYEVENT	"Register dependency to AnyEvent event handler"	on \
		SSL	"Register dependency to SSL lib"	on

.include <bsd.port.pre.mk>

BUILD_DEPENDS=	p5-Storable>=0:${PORTSDIR}/devel/p5-Storable

.if !defined(WITHOUT_EVENT)
BUILD_DEPENDS+=	p5-Event>=0:${PORTSDIR}/devel/p5-Event
.endif

.if defined(WITH_ANYEVENT)
BUILD_DEPENDS+=	p5-AnyEvent>=0:${PORTSDIR}/devel/p5-AnyEvent
.endif

.if defined(WITH_GLIB)
BUILD_DEPENDS+=	p5-Glib2>=0:${PORTSDIR}/devel/p5-Glib2
.endif

.if !defined(WITHOUT_SSL)
# we can't use USE_OPENSSL=yes after including bsd.port.pre.mk
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
BUILD_DEPENDS+=	p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL
.endif

RUN_DEPENDS:=	${BUILD_DEPENDS}

.include <bsd.port.post.mk>
