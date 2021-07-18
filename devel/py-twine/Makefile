# Created by: Tom Judge <tj@FreeBSD.org>

PORTNAME=	twine
PORTVERSION=	3.3.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collection of utilities for interacting with PyPI

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.15:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>=0.4.3:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyring>=15.1,1:security/py-keyring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pkginfo>=1.4.2:sysutils/py-pkginfo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}readme-renderer>=21.0:devel/py-readme-renderer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.20:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-toolbelt>=0.8.0:www/py-requests-toolbelt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc3986>=1.4.0:www/py-rfc3986@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.14:misc/py-tqdm@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
