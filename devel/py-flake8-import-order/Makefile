PORTNAME=	flake8-import-order
PORTVERSION=	0.19.2
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:C/-/_/g}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Flake8 and pylama plugin that checks the ordering of import statements
WWW=		https://pypi.org/project/flake8-import-order/ \
		https://github.com/PyCQA/flake8-import-order

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycodestyle>=0:devel/py-pycodestyle@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils pytest
NO_ARCH=	yes

.include <bsd.port.mk>
