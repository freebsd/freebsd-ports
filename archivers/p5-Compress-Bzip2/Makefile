# New ports collection makefile for:	Compress::Bzip2
# Date created:				23 February 2003
# Whom:	      				Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Compress-Bzip2
PORTVERSION=	2.08
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/A/AR/ARJAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Perl5 interface to bzip2 compression library

PERL_CONFIGURE=	YES

MAN3=		Compress::Bzip2.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This module only support perl 5.6.1 or above
.endif

.include <bsd.port.post.mk>
