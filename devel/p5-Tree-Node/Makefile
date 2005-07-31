# New ports collection makefile for:	p5-Tree-Node
# Date created: 			01 July 2005
# Whom: 				Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	Tree-Node
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tree
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@daltons.ca
COMMENT=	Memory-efficient tree nodes in Perl

PERL_MODBUILD=	yes

MAN3=		Tree::Node.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BROKEN=		"This module only for perl >= 5.8"
.endif

.include <bsd.port.post.mk>
