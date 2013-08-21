# New ports collection makefile for:	p5-PostgreSQL-PLPerl-Call
# Date created:		2010-07-04
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
#
# $FreeBSD$
#

PORTNAME=	PostgreSQL-PLPerl-Call
PORTVERSION=	1.006
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TIMB
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple interface for calling SQL functions from PostgreSQL PL/Perl

BUILD_DEPENDS=	p5-DBI>=1.60.5:${PORTSDIR}/databases/p5-DBI

USE_PERL5=	configure
USES=		perl5

MAN3=		PostgreSQL::PLPerl::Call.3

.include <bsd.port.mk>
