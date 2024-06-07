PORTNAME=	pywgsim
DISTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Modified wgsim genomic data simulator
WWW=		https://pypi.python.org/pypi/pywgsim

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plac>=0:devel/py-plac@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist cython distutils

post-configure:
	cython-${PYTHON_VER} ${WRKSRC}/pywgsim/wgsim_lib.pyx

.include <bsd.port.mk>
