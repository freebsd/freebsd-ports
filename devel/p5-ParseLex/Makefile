# New ports collection makefile for:	p5-ParseLex
# Date created:				16 February 2004
# Whom:					Jim Pirzyk <pirzyk@uiuc.edu>
#
# $FreeBSD$
#

PORTNAME=	ParseLex
PORTVERSION=	2.15
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Parse
PKGNAMEPREFIX=	p5-

MAINTAINER=	pirzyk@freebsd.org
COMMENT= 	Object-oriented generator of lexical analyzers

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Parse::Lex.3 Parse::Token.3 Parse::YYLex.3 Parse::LexEvent.3 Parse::CLex.3 Parse::Template.3

post-patch:
	@${RM} ${WRKSRC}/lib/Parse/*.orig

.include <bsd.port.mk>
