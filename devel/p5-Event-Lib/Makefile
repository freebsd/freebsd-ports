# New ports collection makefile for:	Event-Lib
# Date created:				07 Jun 2006
# Whom:					Fabian Keil <fk@fabiankeil.de>
#
# $FreeBSD$
#

PORTNAME=	Event-Lib
PORTVERSION=	1.01
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Event
PKGNAMEPREFIX=	p5-

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Makes libevent(3) accessible with Perl

LIB_DEPENDS=	event-1.3d:${PORTSDIR}/devel/libevent

PERL_CONFIGURE=	yes

MAN3=		Event::Lib.3

.include <bsd.port.mk>
