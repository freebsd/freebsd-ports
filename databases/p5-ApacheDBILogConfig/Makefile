# New ports collection makefile for:	p5-ApacheDBILogConfig
# Date created:				November 22, 2000
# Whom:	      				Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	Apache-DBILogConfig
PORTVERSION=	0.01
CATEGORIES=	databases www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	dburr@FreeBSD.ORG

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Apache/DBI.pm:${PORTSDIR}/www/p5-Apache-DBI \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${LOCALBASE}/libexec/apache/libperl.so:${PORTSDIR}/www/mod_perl

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
