PORTNAME=	mpl-scatter-density
PORTVERSION=	0.7
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Matplotlib helpers to make density scatter plots

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}fast-histogram>=0.3:misc/py-fast-histogram@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=2.0:math/py-matplotlib@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
