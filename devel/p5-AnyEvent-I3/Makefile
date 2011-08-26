# New ports collection makefile for:	p5-AnyEvent-I3
# Date created:	   26 Aug 2011
# Whom:		   Aldis Berjoza <aldis@bsdroot.lv>
#
# $FreeBSD$
#

PORTNAME=	AnyEvent-I3
DISTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	aldis@bsdroot.lv
COMMENT=	Communicate with the i3 window manager

RUN_DEPENDS=	p5-AnyEvent>=4.15:${PORTSDIR}/devel/p5-AnyEvent
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.10.0+

MAN3=		AnyEvent::I3.3

.include <bsd.port.mk>
