PORTNAME=	cairocffi
PORTVERSION=	1.2.0
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dch@FreeBSD.org
COMMENT=	CFFI-based Cairo bindings for Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.1.0:devel/py-cffi@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.1.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xcffib>=0.3.2:x11/py-xcffib@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYNUMPY} \
		gdk-pixbuf2>0:graphics/gdk-pixbuf2

USES=		gnome python:3.5+
USE_GNOME=	cairo
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

# --record output is not complete so supplement autoplist w/ a plist for now
# https://github.com/Kozea/cairocffi/issues/108

# _generated files only exist after install not build
# so copy them to the src directory so we can run tests against WRKSRC
#
# -v = verbose, -rs print skip reasons, -o override tox.ini/pytest.ini args
do-test:
	${CP} -Rp ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/_generated ${WRKSRC}/${PORTNAME}
	${TOUCH} ${WRKSRC}/${PORTNAME}/_generated/__init__.py
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs -o addopts=

.include <bsd.port.mk>
