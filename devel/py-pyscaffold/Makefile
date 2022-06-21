# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	pyscaffold
PORTVERSION=	4.2.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyScaffold-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Template tool for putting up the scaffold of a Python project

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configupdater>=3.0<4:devel/py-configupdater@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.7:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=2<3:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=5:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>=0.7.0<2:textproc/py-tomlkit@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
