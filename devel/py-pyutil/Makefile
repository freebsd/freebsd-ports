PORTNAME=	pyutil
DISTVERSION=	3.4.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Collection of utilities for Python programmers
WWW=		https://pypi.org/project/${PORTNAME} \
		https://github.com/tpltnt/${PORTNAME}

LICENSE=	GPLv2+ SPL TGGPL
LICENSE_COMB=	dual
LICENSE_NAME_SPL=	Simple Permissive License
LICENSE_NAME_TGGPL=	Transitive Grace Period Public Licence 1.0
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING.GPL
LICENSE_FILE_SPL=	${WRKSRC}/COPYING.SPL.txt
LICENSE_FILE_TGGPL=	${WRKSRC}/COPYING.TGPPL.rst
LICENSE_PERMS_SPL=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell
LICENSE_PERMS_TGGPL=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}versioneer>0:devel/py-versioneer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=2.1.0:devel/py-simplejson@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

# setup.py installs every file in the package directories, including the
# .orig backups left by the patches
post-patch:
	@${FIND} ${WRKSRC}/pyutil -name '*.orig' -delete

.include <bsd.port.mk>
