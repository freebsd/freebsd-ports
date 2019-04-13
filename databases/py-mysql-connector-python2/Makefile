# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	mysql-connector-python
PORTVERSION=	2.2.2
CATEGORIES=	databases python
MASTER_SITES=	MYSQL/Connector-Python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	2

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	MySQL driver written in Python

LICENSE=	GPLv2

DEPRECATED=	Please consider using databases/py-mysql-connector-python which has been\
		updated to latest upstream version
EXPIRATION_DATE=2019-05-15

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes
.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS:=	${PYDISTUTILS_INSTALLARGS:N--single-version-externally-managed}

.include <bsd.port.post.mk>
