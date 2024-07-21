PORTNAME=	nox
PORTVERSION=	${GH_TAGNAME:S/.0/./g} # .whl file built w/out zeros in the version, possibly based on some clause in the standard
CATEGORIES=	devel python
#MASTER_SITES=	PYPI # no tests

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Flexible test automation
WWW=		https://nox.thea.codes/en/stable/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argcomplete>=1.9.4<4.0:devel/py-argcomplete@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorlog>=2.6.1<7.0.0:devel/py-colorlog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.9:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=20.14.1:devel/py-virtualenv@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PY_DEPENDS} \
		${PY_TOMLI}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # 37 tests fail, see https://github.com/wntrblm/nox/issues/820

USE_GITHUB=	yes
GH_ACCOUNT=	wntrblm
GH_TAGNAME=	2024.04.15

NO_ARCH=	yes

.include <bsd.port.mk>
