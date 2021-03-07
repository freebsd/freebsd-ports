# $FreeBSD$

PORTNAME=	jaraco
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PORTVERSION=	1
CATEGORIES=	devel python
DISTFILES=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Shared namespace shim for py-jaraco.* ports

LICENSE=	MIT

USES=		python:3.6+
USE_PYTHON=	flavors

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${PYTHON_SITELIBDIR}/jaraco/__init__.py \
		${PYTHON_SITELIBDIR}/jaraco/__pycache__/__init__.cpython-${PYTHON_SUFFIX}.opt-1.pyc \
		${PYTHON_SITELIBDIR}/jaraco/__pycache__/__init__.cpython-${PYTHON_SUFFIX}.pyc

do-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/jaraco
	${ECHO_CMD} "__path__ = __import__('pkgutil').extend_path(__path__, __name__)" > ${STAGEDIR}${PYTHON_SITELIBDIR}/jaraco/__init__.py
	${PYTHON_CMD} -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${PYTHON_CMD} -O -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
