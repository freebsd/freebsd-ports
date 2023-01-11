PORTNAME=	curtsies
PORTVERSION=	0.4.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Curses-like terminal wrapper, with colored strings
WWW=		https://github.com/bpython/curtsies

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}blessed>=1.5:devel/py-blessed@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cwcwidth>=0:devel/py-cwcwidth@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyte>=0:devel/py-pyte@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}backports.cached-property>=0:devel/py-backports.cached-property@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
