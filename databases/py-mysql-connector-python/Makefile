# $FreeBSD$

PORTNAME=	mysql-connector-python
PORTVERSION=	8.0.19
PORTREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	MYSQL/Connector-Python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	MySQL driver written in Python

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.7.1:devel/py-protobuf@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes
.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS:=	${PYDISTUTILS_INSTALLARGS:N--single-version-externally-managed}

post-patch:
	${REINPLACE_CMD} -e 's|protobuf==|protobuf>=|; s|dnspython==|dnspython>=|' \
		${WRKSRC}/setupinfo.py

.include <bsd.port.post.mk>
