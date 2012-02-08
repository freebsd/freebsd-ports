# New ports collection makefile for:	p5-AnyMQ
# Date created:		2011-06-02
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	AnyMQ
PORTVERSION=	0.34
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CLKAO
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Non-blocking message queue system based on AnyEvent

BUILD_DEPENDS=	p5-Any-Moose>=0:${PORTSDIR}/devel/p5-Any-Moose \
		p5-AnyEvent>=0:${PORTSDIR}/devel/p5-AnyEvent \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-MouseX-NativeTraits>=0:${PORTSDIR}/devel/p5-MouseX-NativeTraits \
		p5-MouseX-Traits>=0:${PORTSDIR}/devel/p5-MouseX-Traits
RUN_DEPENDS=	p5-Any-Moose>=0:${PORTSDIR}/devel/p5-Any-Moose \
		p5-AnyEvent>=0:${PORTSDIR}/devel/p5-AnyEvent \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-MouseX-NativeTraits>=0:${PORTSDIR}/devel/p5-MouseX-NativeTraits \
		p5-MouseX-Traits>=0:${PORTSDIR}/devel/p5-MouseX-Traits

PERL_CONFIGURE=	yes

MAN3=		AnyMQ.3 \
		AnyMQ::Queue.3 \
		AnyMQ::Topic.3 \
		AnyMQ::Topic::Trait::WithBacklog.3

.include <bsd.port.mk>
