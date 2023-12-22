PORTNAME=	mutmut
DISTVERSION=	2.4.4
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Mutation testing for Python 3
WWW=		https://mutmut.readthedocs.io/en/latest/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}glob2>0:devel/py-glob2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}junit-xml>=1.8:textproc/py-junit-xml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parso>0:textproc/py-parso@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pony>0:databases/py-pony@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>0:textproc/py-toml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
