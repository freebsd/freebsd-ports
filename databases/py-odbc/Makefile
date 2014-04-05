# Created by: Robert Kruus <rob.kruus@gmail.com>
# $FreeBSD$

PORTNAME=	pyodbc
PORTVERSION=	3.0.7
CATEGORIES=	databases python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rob.kruus@gmail.com
COMMENT=	ODBC connections for python

LICENSE=	MIT

USES=		zip
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_AUTOPLIST=	yes
PYEASYINSTALL_ARCHDEP=	yes

OPTIONS_DEFINE= UNIXODBC
OPTIONS_DEFAULT=UNIXODBC

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUNIXODBC}
LIB_DEPENDS+=	libodbc.so:${PORTSDIR}/databases/unixODBC
BUILD_DEPENDS+=	unixODBC>=2.2.14_1:${PORTSDIR}/databases/unixODBC
.else
LIB_DEPENDS+=	libiodbc.so:${PORTSDIR}/databases/libiodbc
.endif

.include <bsd.port.mk>
