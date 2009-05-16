# New ports collection makefile for:	p5-DBIx-Tree
# Date created:				January 29th 2003
# Whom:	      				Philip M. Gollucci <philip@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Tree
PORTVERSION=	1.9
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Perl module for generating a tree from a self-referential table

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI

MAKE_JOBS_SAFE=  yes

PERL_CONFIGURE=	yes

MAN3=		DBIx::Tree.3

.include <bsd.port.mk>
