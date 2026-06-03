PORTNAME=	PyGObject-stubs
DISTVERSION=	2.17.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pygobject_stubs-${DISTVERSION}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Typing stubs for PyGObject
WWW=		https://github.com/pygobject/pygobject-stubs \
		https://pypi.org/project/PyGObject-stubs

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		gnome python
USE_GNOME=	pygobject3:run
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
