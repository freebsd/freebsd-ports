# New ports collection makefile for:	Event-Lib
# Date created:				07 Jun 2006
# Whom:					Fabian Keil <fk@fabiankeil.de>
#
# $FreeBSD$
#

PORTNAME=	Event-Lib
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Event
PKGNAMEPREFIX=	p5-

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Makes libevent(3) accessible with Perl

LIB_DEPENDS=	event-1.3b:${PORTSDIR}/devel/libevent

PERL_CONFIGURE=	yes

MAN3=		Event::Lib.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
