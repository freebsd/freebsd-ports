PORTNAME=	notebook-shim
PORTVERSION=	0.2.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	notebook_shim-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Shim layer for notebook traits and config
WWW=		https://github.com/jupyter/notebook_shim

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyter-server>=1.8<3:devel/py-jupyter-server@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${SED} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${FILESDIR}/setup.py > ${WRKSRC}/setup.py

.include <bsd.port.mk>
