# New ports collection makefile for:	DBIx::Connector
# Date created:		16 Oct 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Connector
PORTVERSION=	0.47
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for fast, safe DBI connection management

RUN_DEPENDS=	\
	p5-DBI>=1.605:${PORTSDIR}/databases/p5-DBI
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	DBIx::Connector.3 \
	DBIx::Connector::Driver.3 \
	DBIx::Connector::Driver::MSSQL.3 \
	DBIx::Connector::Driver::Oracle.3 \
	DBIx::Connector::Driver::Pg.3 \
	DBIx::Connector::Driver::SQLite.3 \
	DBIx::Connector::Driver::mysql.3

.include <bsd.port.mk>
