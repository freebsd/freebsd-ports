# New ports collection makefile for:	Devel-Arena
# Date created:	   13 May 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Devel-Arena
PORTVERSION=	0.23
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Perl extension for inspecting the core's arena structures

PERL_CONFIGURE=	5.8.0+

MAN3=		Devel::Arena.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 501000
BROKEN=		Does not build with perl >= 5.10
.endif

.include <bsd.port.post.mk>
