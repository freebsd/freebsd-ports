# New ports collection makefile for:	devel/p5-PerlIO-via-dynamic
# Date created:				Mar  2004
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	PerlIO-via-dynamic
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/C/CL/CLKAO
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@infor.org
COMMENT=	Dynamic PerlIO layers

PERL_CONFIGURE=	yes

MAN3=		PerlIO::via::dynamic.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		This module only supports perl 5.8.0 or above
.endif

.include <bsd.port.post.mk>
