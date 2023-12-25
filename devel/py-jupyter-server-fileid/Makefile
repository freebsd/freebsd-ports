PORTNAME=	jupyter-server-fileid
PORTVERSION=	0.9.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jupyter_server_fileid-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Jupyter Server extension for File ID service
WWW=		https://github.com/jupyter-server/jupyter_server_fileid

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyter-events>=0.5.0:devel/py-jupyter-events@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-server>=1.15<3:devel/py-jupyter-server@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
