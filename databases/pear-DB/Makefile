# Ports collection makefile for:  pear-DB
# Date created:			  28 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	DB
PORTVERSION=	1.5.0.r2
PORTEPOCH=	1
PORTREVISION=	1
CATEGORIES=	databases www pear
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r2/RC2/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR Database Abstraction Layer

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		DB.php DB/common.php DB/dbase.php DB/fbsql.php \
		DB/ibase.php DB/ifx.php DB/msql.php DB/mssql.php \
		DB/mysql.php DB/oci8.php DB/odbc.php DB/pgsql.php \
		DB/sqlite.php DB/storage.php DB/sybase.php
DOCS=		IDEAS MAINTAINERS STATUS TESTERS
TESTS=		db_error.phpt db_error2.phpt db_factory.phpt \
		db_ismanip.phpt db_parsedsn.phpt driver/01connect.phpt \
		driver/02fetch.phpt driver/03simplequery.phpt \
		driver/04numcols.phpt driver/05sequences.phpt \
		driver/06prepexec.phpt driver/08affectedrows.phpt \
		driver/09numrows.phpt driver/10errormap.phpt \
		driver/13limit.phpt driver/14fetchmode_object.phpt \
		driver/15quote.phpt driver/bug22328.phpt \
		driver/connect.inc driver/mktable.inc driver/setup.inc \
		driver/skipif.inc
_DOCSDIR=	doc

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
