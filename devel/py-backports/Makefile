# $FreeBSD$

PORTNAME=	backports
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PORTVERSION=	1
CATEGORIES=	devel python
DISTFILES=

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Shared namespace shim for py-backports.* ports

LICENSE=	MIT

NO_FETCH=	yes
NO_BUILD=	yes
NO_ARCH=	yes
USES=		python
USE_PYTHON=	flavors

.include <bsd.port.pre.mk>

.if ${PYTHON_MAJOR_VER} == 2
PLIST_FILES=	${PYTHON_SITELIBDIR}/backports/__init__.py \
		${PYTHON_SITELIBDIR}/backports/__init__.pyc \
		${PYTHON_SITELIBDIR}/backports/__init__.${PYTHON_PYOEXTENSION}
.else
PLIST_FILES=	${PYTHON_SITELIBDIR}/backports/__init__.py \
		${PYTHON_SITELIBDIR}/backports/__pycache__/__init__.cpython-${PYTHON_SUFFIX}.pyc \
		${PYTHON_SITELIBDIR}/backports/__pycache__/__init__.cpython-${PYTHON_SUFFIX}.${PYTHON_PYOEXTENSION}
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/backports
	${ECHO_CMD} "__path__ = __import__('pkgutil').extend_path(__path__, __name__)" > ${STAGEDIR}${PYTHON_SITELIBDIR}/backports/__init__.py
	${PYTHON_CMD} -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${PYTHON_CMD} -O -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.post.mk>
