# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	POE
PORTVERSION=	1.354
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RCAPUTO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Multitasking and networking framework for perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Curses>=1.08:${PORTSDIR}/devel/p5-Curses \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-IO-Tty>=1.08:${PORTSDIR}/devel/p5-IO-Tty \
		p5-POE-Test-Loops>=1.351:${PORTSDIR}/devel/p5-POE-Test-Loops \
		p5-Socket-GetAddrInfo>=0.20:${PORTSDIR}/net/p5-Socket-GetAddrInfo \
		p5-Term-ReadKey>=2.21:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-URI>=1.30:${PORTSDIR}/net/p5-URI \
		p5-libwww>=5.79:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
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
		POE::Resource::Signals.3 \
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
