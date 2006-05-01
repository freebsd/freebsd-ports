# New ports collection makefile for:	Class-DBI-Sweet
# Date created:		6 Jul 2005
# Whom:			Lars Balker Rasmussen <lbr@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-Sweet
PORTVERSION=	0.08
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Extra sweet features for Class::DBI

BUILD_DEPENDS=	p5-Class-DBI>=3.0.12:${PORTSDIR}/databases/p5-Class-DBI \
		${SITE_PERL}/Data/Page.pm:${PORTSDIR}/databases/p5-Data-Page \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/SQL/Abstract.pm:${PORTSDIR}/databases/p5-SQL-Abstract \
		${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Class::DBI::Sweet.3 Class::DBI::Sweet::Topping.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500801
IGNORE=	requires at least Perl 5.8.1. Install lang/perl5.8, and try again
.endif

.include <bsd.port.post.mk>
