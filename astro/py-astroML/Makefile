PORTNAME=	astroML
PORTVERSION=	1.0.2
PORTREVISION=	3
CATEGORIES=	astro
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${PORTVERSION}.post1.tar.gz

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Tools for machine learning and data mining in Astronomy
WWW=		https://www.astroml.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.19:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=0.18:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}astropy>=3.0:astro/py-astropy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.post1

.include <bsd.port.mk>
