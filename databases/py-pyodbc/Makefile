# Created by: Robert Kruus <rob.kruus@gmail.com>
# $FreeBSD$

PORTNAME=	pyodbc
PORTVERSION=	4.0.30
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rob.kruus@gmail.com
COMMENT=	ODBC connections for python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libodbc.so:databases/unixODBC
BUILD_DEPENDS=	unixODBC>=2.2.14:databases/unixODBC

USES=		localbase python
USE_PYTHON=	autoplist distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pyodbc.so

.include <bsd.port.mk>
