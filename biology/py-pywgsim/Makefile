PORTNAME=	pywgsim
DISTVERSION=	0.6.0
CATEGORIES=	biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Modified wgsim genomic data simulator
WWW=		https://github.com/ialbert/pywgsim/

LICENSE=	MIT

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plac>=0:devel/py-plac@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pywgsim/*.so

.include <bsd.port.mk>
