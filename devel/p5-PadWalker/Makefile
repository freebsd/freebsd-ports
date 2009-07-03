# New ports collection makefile for:	devel/p5-PadWalker
# Date created:				22 September 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PadWalker
PORTVERSION=	1.9
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/R/RO/ROBIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	PadWalker - play with Perl lexical variables

PERL_CONFIGURE=	5.8.0+

MAN3=	PadWalker.3

post-patch:
	${PERL} -i -pe '$$_ = "" if /DEBUGGING/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
