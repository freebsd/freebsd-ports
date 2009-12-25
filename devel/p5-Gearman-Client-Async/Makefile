# New ports collection makefile for:	p5-Gearman-Client-Async
# Date created:		2007-09-03
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	Gearman-Client-Async
PORTVERSION=	0.94
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/B/BR/BRADFITZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Asynchronous client module for Gearman for Danga::Socket applications

RUN_DEPENDS=	\
	${SITE_PERL}/Danga/Socket.pm:${PORTSDIR}/devel/p5-Danga-Socket \
	${SITE_PERL}/Gearman/Client.pm:${PORTSDIR}/devel/p5-Gearman
BUILD_DEPENDS=	${RUN_DEPENDS}

USE_PERL=	yes
PERL_CONFIGURE=	yes
MAN3=	Gearman::Client::Async.3

.include <bsd.port.mk>
