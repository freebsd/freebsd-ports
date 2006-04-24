# New ports collection makefile for:	p5-Locale-Maketext-Simple
# Date created:				Aug 27 2003
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	Locale-Maketext-Simple
PORTVERSION=	0.13
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Locale
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@infor.org
COMMENT=	Simple interface to Locale::Maketext::Lexicon

PERL_CONFIGURE=	yes

MAN3=		Locale::Maketext::Simple.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires Perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
