PORTNAME=	pypemicro
PORTVERSION=	0.1.11
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	awoonyaa@gmail.com
COMMENT=	Python PEMicro debug probes support (stub package)
WWW=		https://pypi.org/project/pypemicro/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

# remove binary blobs for other OSes
post-install:
	${RM} -r ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/libs
	${REINPLACE_CMD} -e '\|site-packages/pypemicro/libs|d' ${_PYTHONPKGLIST}

.include <bsd.port.mk>
