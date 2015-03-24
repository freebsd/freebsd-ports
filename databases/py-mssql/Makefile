# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mssql
PORTVERSION=	1.0.2
PORTREVISION=	3
CATEGORIES=	databases python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pymssql-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python database interface for simple MS-SQL access

LICENSE=	LGPL21 # or later
LICENSE_FILE=	${WRKSRC}/lgpl.txt

LIB_DEPENDS=	libsybdb.so:${PORTSDIR}/databases/freetds

USES=		dos2unix python:2
USE_PYTHON=	autoplist distutils

DOS2UNIX_FILES=	mssqldbmodule.c

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_mssql.so

.include <bsd.port.mk>
