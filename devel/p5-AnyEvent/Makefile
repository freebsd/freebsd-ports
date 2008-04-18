# New ports collection makefile for:	p5-AnyEvent
# Date created:		2006-12-09
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	AnyEvent
PORTVERSION=	3.1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/ML/MLEHMANN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Provide framework for multiple event loops

PERL_CONFIGURE=	5.8.0+

MAN3=		AnyEvent.3 AnyEvent::Impl::Coro.3 \
		AnyEvent::Impl::CoroEV.3 AnyEvent::Impl::CoroEvent.3 \
		AnyEvent::Impl::EV.3 AnyEvent::Impl::Event.3 \
		AnyEvent::Impl::Glib.3 AnyEvent::Impl::Perl.3 \
		AnyEvent::Impl::Tk.3

.include <bsd.port.mk>
