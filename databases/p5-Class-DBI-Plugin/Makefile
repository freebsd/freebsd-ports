# New ports collection makefile for:	databases/p5-Class-DBI-Plugin
# Date created:				01 April 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-Plugin
PORTVERSION=	0.03
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Abstract base class for Class::DBI plugins

BUILD_DEPENDS=	${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Class::DBI::Plugin.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500600
IGNORE=	requires Perl 5.6 or newer. Install lang/perl5 or lang/perl5.8, and try again.
.endif
.include <bsd.port.post.mk>
