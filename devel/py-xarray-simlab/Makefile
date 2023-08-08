PORTNAME=	xarray-simlab
DISTVERSION=	0.5.0-5
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g33a4c83
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Xarray extension and framework for computer model simulations
WWW=		https://xarray-simlab.readthedocs.io/en/latest/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	distutils autoplist pytest # 1 test fails, see https://github.com/xarray-contrib/xarray-simlab/issues/192

USE_GITHUB=	yes
GH_ACCOUNT=	xarray-contrib

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=18.1.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dask>0:devel/py-dask@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}xarray>=0.10.0:devel/py-xarray@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zarr>=2.3.0:devel/py-zarr@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}distributed>0:devel/py-distributed@${PY_FLAVOR} # extra dep for devel/py-dask

NO_ARCH=	yes

.include <bsd.port.mk>
