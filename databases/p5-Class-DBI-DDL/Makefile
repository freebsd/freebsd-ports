# New ports collection makefile for:	p5-Class-DBI-DDL
# Date created:	   18 january 2005
# Whom:		   Daniel Wijnands <daniel@itxl.nl>
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-DDL
PORTVERSION=	1.01
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	daniel@itxl.nl
COMMENT=	DDL for Class-DBI

RUN_DEPENDS=	${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::DBI::DDL.3 \
		Class::DBI::DDL::Pg.3 \
		Class::DBI::DDL::mysql.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		"Needs perl 5.6.0 or higher, install lang/perl5.6 and try again"
.endif

.include <bsd.port.post.mk>
