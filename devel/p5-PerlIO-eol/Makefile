# New ports collection makefile for:	devel/p5-PerlIO-eol
# Date created:				Oct 19 2004
# Whom:					Rong-En Fan <rafan@infor.org>
#
# $FreeBSD$
#

PORTNAME=	PerlIO-eol
PORTVERSION=	0.13
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/A/AU/AUTRIJUS
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@infor.org
COMMENT=	PerlIO layer for normalizing line endings

PERL_CONFIGURE=	yes

MAN3=		PerlIO::eol.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		This module only supports perl 5.8.0 or above
.endif

.include <bsd.port.post.mk>
