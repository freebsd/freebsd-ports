# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=		mysql-connector-python
PORTVERSION=		2.2.0
CATEGORIES=		databases python
MASTER_SITES=		MYSQL/Connector-Python
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=		2

MAINTAINER=		bofh@FreeBSD.org
COMMENT=		MySQL driver written in Python

LICENSE=		GPLv2

NO_ARCH=		yes
USES=			python
USE_PYTHON=		autoplist distutils

.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS:=	${PYDISTUTILS_INSTALLARGS:N--single-version-externally-managed}

.include <bsd.port.post.mk>
