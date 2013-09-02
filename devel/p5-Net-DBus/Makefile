# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-DBus
PORTVERSION=	1.0.0
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Perl extension for the DBus message system

LIB_DEPENDS=	dbus-1.3:${PORTSDIR}/devel/dbus
RUN_DEPENDS=	p5-XML-Twig>=0:${PORTSDIR}/textproc/p5-XML-Twig \
		p5-XML-Grove>=0:${PORTSDIR}/textproc/p5-XML-Grove \
		p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes

USES=		pkgconfig perl5
USES_PERL5=	configure

MAN3=	Net::DBus::ASyncReply.3 Net::DBus::Annotation.3 Net::DBus::Tutorial.3 \
	Net::DBus::RemoteObject.3 Net::DBus::Binding::Connection.3 \
	Net::DBus::Binding::PendingCall.3 Net::DBus::RemoteService.3 \
	Net::DBus::Tutorial::ExportingObjects.3 Net::DBus::Dumper.3 \
	Net::DBus::Binding::Iterator.3 Net::DBus::Binding::Message.3 \
	Net::DBus::Binding::Message::Signal.3 Net::DBus::Binding::Bus.3 \
	Net::DBus::Binding::Server.3 Net::DBus::Binding::Watch.3 \
	Net::DBus::Service.3 Net::DBus::Tutorial::UsingObjects.3\
	Net::DBus.3 Net::DBus::Object.3 Net::DBus::Reactor.3 \
	Net::DBus::Exporter.3 Net::DBus::Binding::Value.3 \
	Net::DBus::Test::MockConnection.3 Net::DBus::Test::MockObject.3 \
	Net::DBus::Binding::Introspector.3 Net::DBus::Callback.3 \
	Net::DBus::Binding::Message::MethodReturn.3 \
	Net::DBus::Binding::Message::MethodCall.3 \
	Net::DBus::Binding::Message::Error.3 \
	Net::DBus::Error.3 Net::DBus::Test::MockIterator.3 \
	Net::DBus::Test::MockMessage.3

.include <bsd.port.mk>
