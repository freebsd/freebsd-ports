# New ports collection makefile for:	p5-AnyEvent-IRC
# Date created:		05 Nov, 2009
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	AnyEvent-IRC
PORTVERSION=	0.96
CATEGORIES=	irc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	An event system independend IRC protocol module

BUILD_DEPENDS=	p5-AnyEvent>=0:${PORTSDIR}/devel/p5-AnyEvent \
		p5-Object-Event>=0.7:${PORTSDIR}/devel/p5-Object-Event
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	AnyEvent::IRC::Client.3 \
	AnyEvent::IRC::Connection.3 \
	AnyEvent::IRC.3 \
	AnyEvent::IRC::Util.3

.include <bsd.port.mk>
