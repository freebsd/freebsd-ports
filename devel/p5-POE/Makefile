# New ports collection makefile for:	POE
# Date created:		29 Apr 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE
PORTVERSION=	0.15
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@protey.ru

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Filter/Util/Call.pm:${PORTSDIR}/devel/p5-Filter
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		POE::Driver::SysRW.3 POE::Wheel::ListenAccept.3\
		POE::Filter::Grep.3 POE::Session.3 POE::Filter::Reference.3\
		POE::Wheel::SocketFactory.3 POE::Filter.3 POE::Preprocessor.3\
		POE::Pipe::TwoWay.3 POE::Wheel::ReadLine.3 POE::Wheel::ReadWrite.3\
		POE::Driver.3 POE::Component::Server::TCP.3 POE::Pipe::OneWay.3\
		POE.3 POE::Component.3 POE::Filter::Map.3 POE::Wheel.3 POE::NFA.3\
		POE::Wheel::Run.3 POE::Filter::HTTPD.3 POE::Filter::Line.3\
		POE::Filter::Stackable.3 POE::Filter::RecordBlock.3\
		POE::Filter::Block.3 POE::Wheel::FollowTail.3 POE::Kernel.3\
		POE::Filter::Stream.3 POE::Wheel::Curses.3

.include <bsd.port.mk>
