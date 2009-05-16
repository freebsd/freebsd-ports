# New ports collection makefile for:	p5-ApacheDBILogConfig
# Date created:				November 22, 2000
# Whom:	      				Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	Apache-DBILogConfig
PORTVERSION=	0.02
CATEGORIES=	databases www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Perl module that logs access information in a DBI database

BUILD_DEPENDS=	${SITE_PERL}/Apache/DBI.pm:${PORTSDIR}/www/p5-Apache-DBI \
		${SITE_PERL}/Date/Format.pm:${PORTSDIR}/devel/p5-TimeDate \
		${LOCALBASE}/libexec/apache/libperl.so:${PORTSDIR}/www/mod_perl
RUN_DEPENDS=	${BUILD_DEPENDS}

MAKE_JOBS_SAFE=  yes

PERL_CONFIGURE=	yes

MAN3=		Apache::DBILogConfig.3

.include <bsd.port.mk>
