# $FreeBSD$

PORTNAME=	backports
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PORTVERSION=	1
CATEGORIES=	devel python
DISTFILES=

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Shared namespace shim for py-backports.* ports

LICENSE=	MIT

USES=		python
USE_PYTHON=	flavors py3kplist

NO_ARCH=	yes
NO_BUILD=	yes
NO_FETCH=	yes

PLIST_FILES=	${PYTHON_SITELIBDIR}/backports/__init__.py \
		${PYTHON_SITELIBDIR}/backports/__init__.pyc \
		${PYTHON_SITELIBDIR}/backports/__init__.pyo

do-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/backports
	${ECHO_CMD} "__path__ = __import__('pkgutil').extend_path(__path__, __name__)" > ${STAGEDIR}${PYTHON_SITELIBDIR}/backports/__init__.py
	${PYTHON_CMD} -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${PYTHON_CMD} -O -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
