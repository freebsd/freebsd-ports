# New ports collection makefile for:	databases/p5-SQL-ReservedWords
# Date created:				29 August 2006
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	SQL-ReservedWords
PORTVERSION=	0.7
CATEGORIES=	databases
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Reserved SQL words by ANSI/ISO

BUILD_DEPENDS=	${SITE_PERL}/Sub/Exporter.pm:${PORTSDIR}/devel/p5-Sub-Exporter
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN1=	sqlrw.1
MAN3=	SQL::ReservedWords.3 \
	SQL::ReservedWords::DB2.3 \
	SQL::ReservedWords::MySQL.3 \
	SQL::ReservedWords::ODBC.3 \
	SQL::ReservedWords::Oracle.3 \
	SQL::ReservedWords::PostgreSQL.3 \
	SQL::ReservedWords::SQLServer.3 \
	SQL::ReservedWords::SQLite.3 \
	SQL::ReservedWords::Sybase.3

.include <bsd.port.mk>
