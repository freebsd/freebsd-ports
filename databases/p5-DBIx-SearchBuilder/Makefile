# New ports collection makefile for:	databases/p5-DBIx-SearchBuilder
# Date created:				29 May 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-SearchBuilder
PORTVERSION=	0.90
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl extension for easy SQL SELECT Statement generation

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/Class/ReturnValue.pm:${PORTSDIR}/devel/p5-Class-ReturnValue
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBIx::SearchBuilder.3 DBIx::SearchBuilder::Handle.3 \
	DBIx::SearchBuilder::Handle::Oracle.3 \
	DBIx::SearchBuilder::Handle::mysql.3 \
	DBIx::SearchBuilder::Handle::mysqlPP.3 \
	DBIx::SearchBuilder::Record.3

.include <bsd.port.mk>
