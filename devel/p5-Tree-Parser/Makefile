# New ports collection makefile for:	Tree::Parser
# Date created:				1 August 2004
# Whom:					Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	Tree-Parser
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tree
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Module to parse formatted files into tree structures

BUILD_DEPENDS=	${SITE_PERL}/Array/Iterator.pm:${PORTSDIR}/devel/p5-Array-Iterator \
		${SITE_PERL}/Tree/Simple.pm:${PORTSDIR}/devel/p5-Tree-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=		Tree::Parser.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
