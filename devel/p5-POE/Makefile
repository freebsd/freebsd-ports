# New ports collection makefile for:	POE
# Date created:		29 Apr 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE
PORTVERSION=	1.289
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0+$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Multitasking and networking framework for perl

BUILD_DEPENDS=	\
		p5-IO-Tty>=1.08:${PORTSDIR}/devel/p5-IO-Tty \
		p5-POE-Test-Loops>=1.031:${PORTSDIR}/devel/p5-POE-Test-Loops
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	--default

MAN3=		POE.3 POE::Component.3 POE::Component::Client::TCP.3 \
		POE::Component::Server::TCP.3 POE::Driver.3 \
		POE::Driver::SysRW.3 POE::Filter.3 \
		POE::Filter::Block.3 POE::Filter::Grep.3 \
		POE::Filter::HTTPD.3 POE::Filter::Line.3 \
		POE::Filter::Map.3 POE::Filter::RecordBlock.3 \
		POE::Filter::Reference.3 POE::Filter::Stackable.3 \
		POE::Filter::Stream.3 POE::Kernel.3 POE::Loop.3 \
		POE::Loop::IO_Poll.3 POE::Loop::PerlSignals.3 \
		POE::Loop::Select.3 POE::NFA.3 POE::Pipe.3 \
		POE::Pipe::OneWay.3 POE::Pipe::TwoWay.3 POE::Queue.3 \
		POE::Queue::Array.3 POE::Resource.3 \
		POE::Resource::Aliases.3 POE::Resource::Events.3 \
		POE::Resource::Extrefs.3 POE::Resource::FileHandles.3 \
		POE::Resource::SIDs.3 POE::Resource::Sessions.3 \
		POE::Resource::Signals.3 POE::Resource::Statistics.3 \
		POE::Resources.3 POE::Session.3 POE::Wheel.3 \
		POE::Wheel::Curses.3 POE::Wheel::FollowTail.3 \
		POE::Wheel::ListenAccept.3 POE::Wheel::ReadLine.3 \
		POE::Wheel::ReadWrite.3 POE::Wheel::Run.3 \
		POE::Wheel::SocketFactory.3

post-install:
.ifndef(NOPORTEXAMPLES)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

test: build
	@(cd ${WRKSRC}; make test)

.include <bsd.port.mk>
