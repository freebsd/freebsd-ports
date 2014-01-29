# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mssql
PORTVERSION=	1.0.2
CATEGORIES=	databases python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pymssql-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python database interface for simple MS-SQL access

LIB_DEPENDS=	libsybdb.so:${PORTSDIR}/databases/freetds-msdblib

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
PYDISTUTILS_PKGNAME=	pymssql

.include <bsd.port.mk>
