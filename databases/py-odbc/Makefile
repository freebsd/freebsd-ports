# Created by: Robert Kruus <rob.kruus@gmail.com>
# $FreeBSD$

PORTNAME=	pyodbc
PORTVERSION=	3.0.7
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rob.kruus@gmail.com
COMMENT=	ODBC connections for python

LICENSE=	MIT

USES=		zip
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

LIB_DEPENDS+=	libodbc.so:${PORTSDIR}/databases/unixODBC
BUILD_DEPENDS+=	unixODBC>=2.2.14_1:${PORTSDIR}/databases/unixODBC

.include <bsd.port.mk>
