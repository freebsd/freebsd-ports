PORTNAME=	qemu.qmp
DISTVERSION=	0.0.5
CATEGORIES=	emulators
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/./_/g}-${DISTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	QEMU Monitor Protocol library
WWW=		https://gitlab.com/qemu-project/python-qemu-qmp

LICENSE=	GPLv2

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
				${PYTHON_PKGNAMEPREFIX}setuptools_scm7>0:devel/py-setuptools_scm7@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
