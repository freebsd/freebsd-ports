# New ports collection makefile for:	DBIx::Class::Tree::NestedSet
# Date created:		17 Mar 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-Tree-NestedSet
PORTVERSION=	0.10
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to manage trees of data using the nested set model

RUN_DEPENDS=	\
	p5-DBIx-Class>=0.08:${PORTSDIR}/databases/p5-DBIx-Class
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBIx::Class::Tree::NestedSet.3

.include <bsd.port.mk>
