# New ports collection makefile for:	p5-Lexical-Persistence
# Date created:				01 Jan 2007
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Lexical-Persistence
PORTVERSION=	1.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Persistent lexical variable values for arbitrary calls

BUILD_DEPENDS=	p5-Devel-LexAlias>=0.04:${PORTSDIR}/devel/p5-Devel-LexAlias \
		p5-PadWalker>=1.1:${PORTSDIR}/devel/p5-PadWalker
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Lexical::Persistence.3

PERL_CONFIGURE=	5.8.0+

.include <bsd.port.mk>
