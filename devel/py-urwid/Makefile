PORTNAME=	urwid
PORTVERSION=	2.2.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Curses-based user interface library for Python
WWW=		https://urwid.org/ \
		https://github.com/urwid/urwid

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=6.2:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 unittest

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/urwid/str_util*.so

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/examples/ && ${INSTALL_DATA} * ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
