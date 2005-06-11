# New ports collection makefile for:	PerlIO-gzip
# Date created:	   08 December 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	PerlIO-gzip
PORTVERSION=	0.17
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	PerlIO
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Perl extension to provide a PerlIO layer to gzip/gunzip

PERL_CONFIGURE=	yes

MAN3=		PerlIO::gzip.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	Perl 5.8 or newer required. Install lang/perl5.8 and try again.
.endif

.include <bsd.port.post.mk>
