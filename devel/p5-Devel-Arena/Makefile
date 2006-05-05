# New ports collection makefile for:	Devel-Arena
# Date created:	   13 May 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Devel-Arena
PORTVERSION=	0.23
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Perl extension for inspecting the core's arena structures

PERL_CONFIGURE=	yes

MAN3=		Devel::Arena.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	perl 5.8 or newer required. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
