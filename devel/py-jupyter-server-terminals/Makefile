PORTNAME=	jupyter-server-terminals
PORTVERSION=	0.5.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jupyter_server_terminals-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Jupyter Server Extension Providing Terminals
WWW=		https://github.com/jupyter-server/jupyter_server_terminals

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.5:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}terminado>=0.8.3:net/py-terminado@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
