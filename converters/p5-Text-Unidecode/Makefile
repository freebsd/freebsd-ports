# New ports collection makefile for:	converters/p5-Text-Unidecode
# Date created:				15 December 2004
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Unidecode
PORTVERSION=	0.04
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Text::Unidecode -- US-ASCII transliterations of Unicode text

PERL_CONFIGURE=	yes

MAN3=	Text::Unidecode.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	"This port requires perl 5.6 or newer"
.endif

.include <bsd.port.post.mk>
