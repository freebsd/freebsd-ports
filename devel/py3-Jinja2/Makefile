# Created by: Muhammad Moinur Rahman <bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Jinja2
PORTVERSION=	2.8
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX?=

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Fast and easy to use stand-alone template engine

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MarkupSafe>=0.18:textproc/py3-MarkupSafe
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MarkupSafe>=0.18:textproc/py3-MarkupSafe

NO_ARCH=	yes
USES=		python:3.3+
USE_PYTHON=	autoplist concurrent distutils

OPTIONS_DEFINE=	BABEL EXAMPLES
OPTIONS_DEFAULT=	BABEL
BABEL_DESC=		Enable Babel extension

BABEL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=1.3:devel/py3-babel

PY2TO3_CMD=	${LOCALBASE}/bin/2to3-${PYTHON_VER}
PY2TO3_ARGS=	--fix=all --no-diffs --nobackups --verbose --write

PORTEXAMPLES=	*

post-build-EXAMPLES-on:
	${PY2TO3_CMD} ${PY2TO3_ARGS} ${WRKSRC}/examples
	${PYTHON_CMD} -m compileall ${WRKSRC}/examples ; \
	${PYTHON_CMD} -O -m compileall ${WRKSRC}/examples

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

check regression-test test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
