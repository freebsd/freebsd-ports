# New ports collection makefile for:	SQL-Abstract-Limit
# Date created:		14 Aug 2005
# Whom:			Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SQL-Abstract-Limit
PORTVERSION=	0.120
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/D/DA/DAVEBAIRD
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-0.12

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	SQL Portability layer for LIMIT emulation

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/SQL/Abstract.pm:${PORTSDIR}/databases/p5-SQL-Abstract \
		${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		SQL::Abstract::Limit.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires perl 5.6.x or later
.endif

.include <bsd.port.post.mk>
