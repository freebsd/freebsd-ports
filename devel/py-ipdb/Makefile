PORTNAME=	ipdb
PORTVERSION=	0.13.7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	IPython-enabled pdb

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>=7.17.0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0.10.2:textproc/py-toml@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
