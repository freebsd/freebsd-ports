PORTNAME=	rlpycairo
DISTVERSION=	0.4.0
CATEGORIES=	graphics print python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Plugin backend renderer for reportlab.graphics.renderPM
WWW=		https://hg.reportlab.com/hg-public/rlPyCairo

LICENSE=	BSD3CLAUSE
#LICENSE_FILE=	Not yet packaged in sdist

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>=1.20:graphics/py-cairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freetype-py>=2.3:print/py-freetype-py@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
