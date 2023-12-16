PORTNAME=	python-dbusmock
PORTVERSION=	0.30.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Mock D-Bus objects for tests
WWW=		https://pypi.org/project/python-dbusmock

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR}

USES=		gnome python
USE_GNOME=	pygobject3
USE_PYTHON=	autoplist pep517

BINARY_ALIAS=	python3=${PYTHON_CMD}
NO_ARCH=	yes

do-test:
	cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m unittest

.include <bsd.port.mk>
