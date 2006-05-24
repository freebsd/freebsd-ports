# New ports collection makefile for:	p5-Tree-Binary-Dictionary
# Date created:				24 May 2006
# Whom:					Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	Tree-Binary-Dictionary
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tree
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	A dictionary API to a binary tree

BUILD_DEPENDS=	${SITE_PERL}/Tree/Binary.pm:${PORTSDIR}/devel/p5-Tree-Binary
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=		Tree::Binary::Dictionary.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.x or later. Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
