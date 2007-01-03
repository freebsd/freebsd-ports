# New ports collection makefile for:	devel/p5-PadWalker
# Date created:				22 September 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PadWalker
PORTVERSION=	1.3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/R/RO/ROBIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	PadWalker - play with Perl lexical variables

PERL_CONFIGURE=	yes

MAN3=	PadWalker.3

post-patch:
	${PERL} -i -pe '$$_ = "" if /DEBUGGING/' ${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	This port requires perl 5.8.X.  Please install lang/perl5.8.
.endif

.include <bsd.port.post.mk>
