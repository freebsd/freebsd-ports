# New ports collection makefile for:	p5-PHP-Serialization
# Date created:		2007-02-23
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	PHP-Serialization
PORTVERSION=	0.27
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	PHP
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Converting the output of PHP serialize() into the Perl

PERL_CONFIGURE=	yes

MAN3=		PHP::Serialization.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires Perl 5.8 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
