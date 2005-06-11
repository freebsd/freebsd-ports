# New ports collection makefile for:	Want
# Date created:	   19 June 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Want
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/R/RO/ROBIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	A generalisation of wantarray

PERL_CONFIGURE=	yes

MAN3=		Want.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	Perl 5.6 or newer required. Install lang/perl5 or lang/perl5.8 and try again.
.endif

.include <bsd.port.post.mk>
