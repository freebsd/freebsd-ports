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

USES=	gmake
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	python-${PORTNAME}

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

EXAMPLESFILES=	httpget_example.py timeout_advice.py timeout_example.py \
		tracer_advice.py tracer_example.py typecheck_advice.py \
		typecheck_example.py
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

NO_STAGE=	yes
do-build:
	@PYTHON="${PYTHON_CMD}" @${GMAKE} -C ${WRKSRC} check

.if !defined(NOPORTEXAMPLES)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
.for f in ${EXAMPLESFILES}
	@${INSTALL_DATA} ${WRKSRC}/examples/${f} ${EXAMPLESDIR}
.endfor
.endif

.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
