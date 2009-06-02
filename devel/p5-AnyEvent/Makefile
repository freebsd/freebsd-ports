# New ports collection makefile for:	p5-AnyEvent
# Date created:		2006-12-09
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	AnyEvent
PORTVERSION=	4.35.2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/ML/MLEHMANN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Provide framework for multiple event loops

PERL_CONFIGURE=	5.8.0+

MAN3=		AnyEvent.3 \
		AnyEvent::DNS.3 AnyEvent::Handle.3 \
		AnyEvent::Impl::EventLib.3 \
		AnyEvent::Impl::POE.3 \
		AnyEvent::Impl::Qt.3 \
		AnyEvent::Impl::EV.3 AnyEvent::Impl::Event.3 \
		AnyEvent::Impl::Glib.3 AnyEvent::Impl::Perl.3 \
		AnyEvent::Impl::Tk.3 AnyEvent::Intro.3 \
		AnyEvent::Socket.3 AnyEvent::Strict.3 \
		AnyEvent::Util.3

.include <bsd.port.mk>
