# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Jinja2
PORTVERSION=	2.7
PORTREVISION=	0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX?=

MAINTAINER=	nivit@FreeBSD.org
COMMENT?=	Fast and easy to use stand-alone template engine

LICENSE=	BSD

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MarkupSafe>=0.11:${PORTSDIR}/textproc/py-MarkupSafe

USE_PYTHON=	yes
.if empty(PKGNAMESUFFIX)
USE_PYDISTUTILS=	easy_install
.endif

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS_DEFINE?=	BABEL EXAMPLES SPEEDUPS
OPTIONS_DEFAULT?=	BABEL SPEEDUPS
SPEEDUPS_DESC=	Enable speedups
BABEL_DESC=	Enable Babel extension

PY2TO3_CMD=	${LOCALBASE}/bin/2to3-${PYTHON_VER}
PY2TO3_ARGS=	--fix=all --no-diffs --nobackups --verbose --write

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if ${PKGNAMESUFFIX} == "-doc"
BUILD_DEPENDS+=	${PKGNAMEPREFIX}sphinx>=1.1.3:${PORTSDIR}/textproc/py-sphinx
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
PORT_OPTIONS:=	${PORT_OPTIONS:NEXAMPLES}
.endif

.if ${PORT_OPTIONS:MBABEL} && ${PYTHON_REL} < 300
# Actually >= 0.9.8, devel/py-babel doesn't yet build with Py3k
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Babel>=0.9.6:${PORTSDIR}/devel/py-babel
.endif

.if ${PORT_OPTIONS:MSPEEDUPS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MarkupSafe>=0.11:${PORTSDIR}/textproc/py-MarkupSafe
.endif

# no problem with Python > 3.2
.if ${PYTHON_VERSION} == python3.2
pre-build:
	${PY2TO3_CMD} ${PY2TO3_ARGS} ${WRKSRC}/jinja2
.endif

.if ${PKGNAMESUFFIX} == "-doc"
do-build:
.	if ${PYTHON_REL} >= 300
	@${PY2TO3_CMD} ${PY2TO3_ARGS} ${WRKSRC}/docs
.	endif
	@cd ${WRKSRC}/docs && ${MAKE} html

do-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs/_build/html && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
post-build:
.	if ${PYTHON_REL} >= 300
	${PY2TO3_CMD} ${PY2TO3_ARGS} ${WRKSRC}/examples
.	endif
	${PYTHON_CMD} -m compileall ${WRKSRC}/examples ; \
	${PYTHON_CMD} -O -m compileall ${WRKSRC}/examples

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

check regression-test test: build
.if empty(PKGNAMESUFFIX)
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test
.else
	@${DO_NADA}
.endif

.if ${PYTHON_REL} >= 320
.include "${.CURDIR}/../py-virtualenv/files/py3k-fix-pkg-plist.inc"
.endif

.include <bsd.port.post.mk>
