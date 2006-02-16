# New ports collection makefile for:	p5-Net-DBus
# Date created:				2005-11-25
# Whom:					Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-DBus
PORTVERSION=	0.33.1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Perl extension for the DBus message system

LIB_DEPENDS=	dbus-1.2:${PORTSDIR}/devel/dbus

USE_GNOME=	pkgconfig
PERL_CONFIGURE=	yes

MAN3=	Net::DBus::Tutorial.3 Net::DBus::RemoteObject.3 \
	Net::DBus::Binding::Connection.3 Net::DBus::RemoteService.3 \
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
	Net::DBus::Binding::Message::Error.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.006 or better
.endif

.include <bsd.port.post.mk>
