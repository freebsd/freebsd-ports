# New ports collection makefile for:	py-mssql
# Date created:		5 March 2004
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mssql
PORTVERSION=	0.7.3
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pymssql
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pymssql-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python database interface for simple MS-SQL access

LIB_DEPENDS=	sybdb.5:${PORTSDIR}/databases/freetds-msdblib

USE_PYTHON=	2.2+
USE_PYDISTUTILS=yes

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
		${WRKSRC}/mssqldbmodule.c

.include <bsd.port.mk>
