# Created by: Robert Kruus <rob.kruus@gmail.com>
# $FreeBSD$

PORTNAME=	pyodbc
PORTVERSION=	3.0.10
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
MASTER_SITE_SUBDIR=	source/p/${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rob.kruus@gmail.com
COMMENT=	ODBC connections for python

LICENSE=	MIT

USES=		python
USE_PYTHON=	autoplist distutils

LIB_DEPENDS+=	libodbc.so:databases/unixODBC
BUILD_DEPENDS+=	unixODBC>=2.2.14_1:databases/unixODBC

.include <bsd.port.mk>
