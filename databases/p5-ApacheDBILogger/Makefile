# New ports collection makefile for:	p5-ApacheDBILogger
# Date created:				November 22, 2000
# Whom:	      				Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	Apache-DBILogger
PORTVERSION=	0.93
CATEGORIES=	databases www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A module that tracks what's being transferred in a DBI database

BUILD_DEPENDS=	${SITE_PERL}/Apache/DBI.pm:${PORTSDIR}/www/p5-Apache-DBI \
		${LOCALBASE}/libexec/apache/libperl.so:${PORTSDIR}/www/mod_perl

PERL_CONFIGURE=	yes

MAN3=		Apache::DBILogger.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
