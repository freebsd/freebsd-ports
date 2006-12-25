# New ports collection makefile for:	ExtUtils-Command
# Date created:	   02 November 2006
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	ExtUtils-Command
PORTVERSION=	1.13
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	ExtUtils
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Utilities to replace common UNIX commands

PERL_CONFIGURE=	YES

MAN3=		ExtUtils::Command.3 Shell::Command.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.x or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
