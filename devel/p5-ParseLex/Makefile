# New ports collection makefile for:	p5-ParseLex
# Date created:				16 February 2004
# Whom:					Jim Pirzyk <pirzyk@uiuc.edu>
#
# $FreeBSD$
#

PORTNAME=	ParseLex
PORTVERSION=	2.19
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN/Parse
PKGNAMEPREFIX=	p5-

MAINTAINER=	pirzyk@FreeBSD.org
COMMENT=	Object-oriented generator of lexical analyzers

BUILD_DEPENDS=  p5-ParseTemplate>=3.01:${PORTSDIR}/devel/p5-ParseTemplate
RUN_DEPENDS=    ${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Parse::ALex.3 Parse::Lex.3 Parse::Token.3 Parse::YYLex.3 \
		Parse::LexEvent.3 Parse::CLex.3 Parse::Trace.3

.include <bsd.port.mk>
