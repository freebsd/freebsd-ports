# New ports collection makefile for:    p5-DBD-File
# Date created:				Nov 15 2003
# Whom:	      				vanilla
#
# $FreeBSD$
#

PORTNAME=	DBD-File
PORTVERSION=	0.33
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Base class for writing DBI drivers for plain files

BUILD_DEPENDS=	${SITE_PERL}/SQL/Statement.pm:${PORTSDIR}/databases/p5-SQL-Statement
RUN_DEPENDS=	${SITE_PERL}/SQL/Statement.pm:${PORTSDIR}/databases/p5-SQL-Statement

PERL_CONFIGURE=	yes

MAN3=		DBD::File.3 \
		DBI::SQL::Nano.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
.else
IGNORE=		This module is useless with p5-DBI
.endif

.include <bsd.port.post.mk>
