# New ports collection makefile for:	p5-DBIx-Tree
# Date created:				January 29th 2003
# Whom:	      				Philip M. Gollucci <philip@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Tree
PORTVERSION=	0.91
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	philip@p6m7g8.com
COMMENT=	Perl module for generating a tree from a self-referential table

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI

PERL_CONFIGURE=	yes
IS_INTERACTIVE=	yes

MAN3=		DBIx::Tree.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
