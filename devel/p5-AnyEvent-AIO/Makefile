# New ports collection makefile for:	devel/p5-AnyEvent-AIO
# Date created:				Wed Sep  2 14:59:22 CEST 2009
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	AnyEvent-AIO
PORTVERSION=	1.1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	AnyEvent
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Asynchronous file and directory I/O with AnyEvent

BUILD_DEPENDS=	p5-AnyEvent>=3.4:${PORTSDIR}/devel/p5-AnyEvent \
		p5-IO-AIO>=3.0:${PORTSDIR}/devel/p5-IO-AIO

PERL_CONFIGURE=	yes

MAN3=	AnyEvent::AIO.3

.include <bsd.port.mk>
