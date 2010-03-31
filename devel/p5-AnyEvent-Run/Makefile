# New ports collection makefile for:	p5-AnyEvent-Run
# Date created:	   19 Mar 2010
# Whom:		   Denis Pokataev <catone@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	AnyEvent-Run
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	catone@cpan.org
COMMENT=	Run a process or coderef asynchronously

RUN_DEPENDS=	p5-AnyEvent>=4.15:${PORTSDIR}/devel/p5-AnyEvent
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		AnyEvent::Run.3

.include <bsd.port.mk>
