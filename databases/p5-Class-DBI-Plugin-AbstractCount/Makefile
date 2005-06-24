# New ports collection makefile for:	databases/p5-Class-DBI-Plugin-AbstractCount
# Date created:				01 April 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-Plugin-AbstractCount
PORTVERSION=	0.04
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Get COUNT(*) results with abstract SQL

BUILD_DEPENDS=	${SITE_PERL}/Class/DBI/Plugin.pm:${PORTSDIR}/databases/p5-Class-DBI-Plugin \
		${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Class::DBI::Plugin::AbstractCount.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500600
IGNORE=	requires Perl 5.6 or newer. Install lang/perl5 or lang/perl5.8, and try again.
.endif
.include <bsd.port.post.mk>
