PORTNAME=	mpl-interactions
DISTVERSION=	0.24.1
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mpl_interactions-${DISTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Simple interactive Matplotlib plots
WWW=		https://pypi.python.org/pypi/mpl-interactions

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
