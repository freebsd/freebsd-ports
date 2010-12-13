# New ports collection makefile for:	p5-Event-Join
# Date created:	   24 Mar 2010
# Whom:		   Denis Pokataev <catone@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	Event-Join
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	catone@cpan.org
COMMENT=	Join multiple "events" into one

RUN_DEPENDS=	p5-Moose>=0.94:${PORTSDIR}/devel/p5-Moose
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		Event::Join.3

.include <bsd.port.mk>
