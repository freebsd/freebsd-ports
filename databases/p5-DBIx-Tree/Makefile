# New ports collection makefile for:	p5-DBIx-Tree
# Date created:				January 29th 2003
# Whom:	      				Philip M. Gollucci <philip@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Tree
PORTVERSION=	1.9
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@p6m7g8.com
COMMENT=	Perl module for generating a tree from a self-referential table

PERL_CONFIGURE=	yes

MAN3=		DBIx::Tree.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.endif

.include <bsd.port.post.mk>
