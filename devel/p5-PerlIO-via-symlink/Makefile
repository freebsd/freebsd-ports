# New ports collection makefile for:	devel/p5-PerlIO-via-symlink
# Date created:				Aug 05 2004
# Whom:					Rong-En Fan <rafan@infor.org>
#
# $FreeBSD$
#

PORTNAME=	PerlIO-via-symlink
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/C/CL/CLKAO
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@infor.org
COMMENT=	Symbolic link PerlIO layers

PERL_CONFIGURE=	yes

MAN3=		PerlIO::via::symlink.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		This program only support perl 5.8.0 or above
.endif

.include <bsd.port.post.mk>
