PORTNAME=	pickledb
PORTVERSION=	0.9.2
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pickleDB-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Lightweight, fast, and simple key-value store
WWW=		https://github.com/patx/pickledb

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=0:devel/py-simplejson@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
