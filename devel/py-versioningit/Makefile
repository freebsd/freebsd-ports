PORTNAME=	versioningit
PORTVERSION=	3.3.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Obtain package version from repo tags
WWW=		https://github.com/jwodder/versioningit

LICENSE=	MIT

BUILD_DEPENDS= hatchling:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>3.6:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>17.1:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli>=1.2<3.0:textproc/py-tomli@${PY_FLAVOR} \
		git>0:devel/git

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

post-patch:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}/

.include <bsd.port.mk>
