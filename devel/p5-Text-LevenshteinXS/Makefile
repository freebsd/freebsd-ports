# New ports collection makefile for:   p5-Text-LevenshteinXS
# Date created:        18 June 2005
# Whom:                christian
#
# $FreeBSD$
#

PORTNAME=      Text-LevenshteinXS
PORTVERSION=   0.03
CATEGORIES=    devel perl5
MASTER_SITES=  ${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR= Text
PKGNAMEPREFIX=  p5-

MAINTAINER=    christian@karg.org
COMMENT=       Text::LevenshteinXS - CPAN Levenshtein edit distance

PERL_CONFIGURE= yes

MAN3=           Text::LevenshteinXS.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=         Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
