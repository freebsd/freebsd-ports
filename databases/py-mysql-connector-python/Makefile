# $FreeBSD$

PORTNAME=	mysql-connector-python
PORTVERSION=	8.0.19
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	MYSQL/Connector-Python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	MySQL driver written in Python

LICENSE=	GPLv2

BUILD_DEPENDS=  ${PYTHON_PKGNAMEPREFIX}dnspython>0:dns/py-dnspython@${PY_FLAVOR}
RUN_DEPENDS=  ${PYTHON_PKGNAMEPREFIX}dnspython>0:dns/py-dnspython@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes
.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS:=	${PYDISTUTILS_INSTALLARGS:N--single-version-externally-managed}

.include <bsd.port.post.mk>
