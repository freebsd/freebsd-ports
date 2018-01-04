# Created by: Sofian Brabez <sbrabez@gmail.com>
# $FreeBSD$

PORTNAME=	aspects
PORTVERSION=	1.3
CATEGORIES=	devel python
MASTER_SITES=	http://www.cs.tut.fi/~ask/aspects/ \
		LOCAL/sbz
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Lightweight aspect oriented programming library for Python

LICENSE=	LGPL21

USES=		python:2.7
USE_PYTHON=	distutils autoplist

SUB_FILES=	pkg-message

PORTEXAMPLES=	httpget_example.py timeout_advice.py timeout_example.py \
		tracer_advice.py tracer_example.py typecheck_advice.py \
		typecheck_example.py
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

OPTIONS_DEFINE=	EXAMPLES

#regression-test: extract
#	@PYTHON="${PYTHON_CMD}" ${MAKE_CMD} -C ${WRKSRC} check

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/examples/,} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
