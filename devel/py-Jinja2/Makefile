# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Jinja2
PORTVERSION=	2.8
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX?=

MAINTAINER=	nivit@FreeBSD.org
COMMENT?=	Fast and easy to use stand-alone template engine

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MarkupSafe>=0.18:textproc/py-MarkupSafe
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MarkupSafe>=0.18:textproc/py-MarkupSafe

NO_ARCH=	yes
USES=		python
.if empty(PKGNAMESUFFIX)
USE_PYTHON=	autoplist distutils
.endif

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE?=	BABEL EXAMPLES
OPTIONS_DEFAULT?=	BABEL
BABEL_DESC=		Enable Babel extension

BABEL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=1.3:devel/py-babel

PY2TO3_CMD=	${LOCALBASE}/bin/2to3-${PYTHON_VER}
PY2TO3_ARGS=	--fix=all --no-diffs --nobackups --verbose --write

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if ${PKGNAMESUFFIX} == "-doc"
BUILD_DEPENDS+=	${PKGNAMEPREFIX}sphinx>=1.1.3:textproc/py-sphinx
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
PORTDOCS=	*
PORT_OPTIONS:=	${PORT_OPTIONS:NEXAMPLES}
.endif

.if ${PKGNAMESUFFIX} == "-doc"
do-build:
	(cd ${WRKSRC}/docs && ${MAKE} html)

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/_build/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
		"! -name .buildinfo")
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
PORTEXAMPLES=	*
post-build:
.	if ${PYTHON_REL} >= 3000
	${PY2TO3_CMD} ${PY2TO3_ARGS} ${WRKSRC}/examples
.	endif
	${PYTHON_CMD} -m compileall ${WRKSRC}/examples ; \
	${PYTHON_CMD} -O -m compileall ${WRKSRC}/examples

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
.endif

check regression-test test: build
.if empty(PKGNAMESUFFIX)
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test
.else
	@${DO_NADA}
.endif

.include <bsd.port.post.mk>
