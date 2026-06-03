PORTNAME=	Js2Py
DISTVERSION=	0.74
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/PiotrDabkowski/Js2Py/commit/
PATCHFILES=		fd7df4a91fb08060914c7b1d9e94583d18f3371b.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JavaScript to Python translator and interpreter
WWW=		https://pypi.org/project/Js2Py/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyjsparser>=2.5.1:devel/py-pyjsparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzlocal>=1.2:devel/py-tzlocal@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
