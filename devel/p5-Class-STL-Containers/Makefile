# New ports collection makefile for:	p5-Class-STL-Containers
# Date created:				12 Jun 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-STL-Containers
PORTVERSION=	0.26
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Perl extension for STL-like object management

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500807
IGNORE=	requires at least Perl 5.8.7.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
