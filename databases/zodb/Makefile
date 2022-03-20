PORTNAME=	zodb
PORTVERSION=	5.7.0
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ZODB-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python object-oriented database

LICENSE=	ZPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}persistent>=4.4.0:devel/py-persistent@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}BTrees>=4.2.0:devel/py-BTrees@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zconfig>0:devel/py-zconfig@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transaction>=2.4:devel/py-transaction@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zclockfile>=0:devel/py-zclockfile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zodbpickle>=1.0.1:databases/py-zodbpickle@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
