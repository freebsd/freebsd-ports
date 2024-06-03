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
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} > 31100
BROKEN=		modern python is not supported
.endif

.include <bsd.port.post.mk>
