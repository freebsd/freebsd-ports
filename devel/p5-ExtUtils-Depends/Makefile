# New ports collection makefile for:	ExtUtils-Depends
# Date created:	   18 October 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	ExtUtils-Depends
PORTVERSION=	0.202
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	ExtUtils
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Easily build XS extensions that depend on XS extensions

PERL_CONFIGURE=	yes

MAN3=		ExtUtils::Depends.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BROKEN=		"Does not compile with this version of perl"
.endif

.include <bsd.port.post.mk>
