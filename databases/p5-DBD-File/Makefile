# New ports collection makefile for:    p5-DBD-File
# Date created:				Nov 15 2003
# Whom:	      				vanilla
#
# $FreeBSD$
#

PORTNAME=	DBD-File
PORTVERSION=	0.35
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Base class for writing DBI drivers for plain files

RUN_DEPENDS=	${SITE_PERL}/SQL/Statement.pm:${PORTSDIR}/databases/p5-SQL-Statement
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DBD::File.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
.else
IGNORE=		is useless with p5-DBI
.endif

.include <bsd.port.post.mk>
