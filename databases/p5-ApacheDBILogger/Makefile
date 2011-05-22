# New ports collection makefile for:	p5-ApacheDBILogger
# Date created:				November 22, 2000
# Whom:	      				Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	Apache-DBILogger
PORTVERSION=	0.93
PORTREVISION=	1
CATEGORIES=	databases www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A module that tracks what's being transferred in a DBI database

BUILD_DEPENDS=	${SITE_PERL}/Apache/DBI.pm:${PORTSDIR}/www/p5-Apache-DBI-mp1 \
		${LOCALBASE}/libexec/apache/libperl.so:${PORTSDIR}/www/mod_perl

RUN_DEPENDS:=	${BUILD_DEPENDS}

MAKE_JOBS_SAFE=  yes

USE_APACHE=	13
PERL_CONFIGURE=	yes

MAN3=		Apache::DBILogger.3

.include <bsd.port.mk>
