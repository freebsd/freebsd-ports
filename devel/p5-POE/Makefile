# New ports collection makefile for:	POE
# Date created:		29 Apr 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE
PORTVERSION=	0.28
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Multitasking and networking framework for perl

IS_INTERACTIVE=	yes

BUILD_DEPENDS=	\
		${SITE_PERL}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/${PERL_ARCH}/Event.pm:${PORTSDIR}/devel/p5-Event \
		${SITE_PERL}/${PERL_ARCH}/Filter/Util/Call.pm:${PORTSDIR}/devel/p5-Filter \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	</dev/null

MAN3=		POE.3 POE::API::ResLoader.3 POE::Component.3 \
		POE::Component::Client::TCP.3 POE::Component::Server::TCP.3 \
		POE::Driver.3 POE::Driver::SysRW.3 POE::Filter.3 \
		POE::Filter::Block.3 POE::Filter::Grep.3 POE::Filter::HTTPD.3 \
		POE::Filter::Line.3 POE::Filter::Map.3 \
		POE::Filter::RecordBlock.3 POE::Filter::Reference.3 \
		POE::Filter::Stackable.3 POE::Filter::Stream.3 POE::Kernel.3 \
		POE::Loop.3 POE::Loop::Event.3 POE::Loop::Gtk.3 \
		POE::Loop::PerlSignals.3 POE::Loop::Poll.3 POE::Loop::Select.3 \
		POE::Loop::Tk.3 POE::Loop::TkActiveState.3 \
		POE::Loop::TkCommon.3 POE::NFA.3 POE::Pipe.3 \
		POE::Pipe::OneWay.3 POE::Pipe::TwoWay.3 POE::Preprocessor.3 \
		POE::Queue.3 POE::Queue::Array.3 POE::Resource.3 \
		POE::Resource::Aliases.3 POE::Resource::Events.3 \
		POE::Resource::Extrefs.3 POE::Resource::FileHandles.3 \
		POE::Resource::SIDs.3 POE::Resource::Sessions.3 \
		POE::Resource::Signals.3 POE::Resource::Statistics.3 \
		POE::Session.3 POE::Wheel.3 POE::Wheel::Curses.3 \
		POE::Wheel::FollowTail.3 POE::Wheel::ListenAccept.3 \
		POE::Wheel::ReadLine.3 POE::Wheel::ReadWrite.3 \
		POE::Wheel::Run.3 POE::Wheel::SocketFactory.3

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/samples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
