# New ports collection makefile for:	devel/p5-Perl-Tidy
# Date created:				01 September 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Perl-Tidy
PORTVERSION=	20031021
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Perl
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl::Tidy - Parses and beautifies perl source

PERL_CONFIGURE=	yes

MAN1=	perltidy.1
MAN3=	Perl::Tidy.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.0 or later. Install lang/perl5 and try again
.endif

.include <bsd.port.post.mk>
