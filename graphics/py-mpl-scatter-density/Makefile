PORTNAME=	mpl-scatter-density
DISTVERSION=	0.8
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mpl_scatter_density-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Matplotlib helpers to make density scatter plots
WWW=		https://github.com/astrofrog/mpl-scatter-density

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fast-histogram>=0.3:misc/py-fast-histogram@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
