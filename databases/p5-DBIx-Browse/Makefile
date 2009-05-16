# New ports collection makefile for:	p5-DBIx-Browse
# Date created:				January 29th 2003
# Whom:	      				Philip M. Gollucci <philip@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Browse
PORTVERSION=	2.09
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	DBIx::Browse - Perl extension to browse tables

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI

MAKE_JOBS_SAFE=  yes

PERL_CONFIGURE=	yes

MAN3=		DBIx::Browse::CGI.3 \
		DBIx::Browse.3

.include <bsd.port.mk>
