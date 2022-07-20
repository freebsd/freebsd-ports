PORTNAME=	twine
PORTVERSION=	4.0.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collection of utilities for interacting with PyPI

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.15:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=3.6:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyring>=15.1,1:security/py-keyring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pkginfo>=1.8.1:sysutils/py-pkginfo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}readme-renderer>=35.0:devel/py-readme-renderer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.20:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-toolbelt>=0.8.0:www/py-requests-toolbelt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc3986>=1.4.0:www/py-rfc3986@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=12.0.0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.26.0,1:net/py-urllib3@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}/

.include <bsd.port.mk>
