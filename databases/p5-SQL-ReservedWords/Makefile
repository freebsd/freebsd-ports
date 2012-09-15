# New ports collection makefile for:	databases/p5-SQL-ReservedWords
# Date created:				29 August 2006
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	SQL-ReservedWords
PORTVERSION=	0.8
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Reserved SQL words by ANSI/ISO

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

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
