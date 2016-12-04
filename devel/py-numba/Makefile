# Created by: David Kalliecharan <dave@dal.ca>
# $FreeBSD$

PORTNAME=	numba
PORTVERSION=	0.29.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dave@dal.ca
COMMENT=	Optimizing compiler for Python using LLVM

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>1.7,1:math/py-numpy
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}llvmlite>=0.12:devel/py-llvmlite

# Uses Python 2.7, 3.4+
USES=		python fortran
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

# Requried for Python 2.7
.if ${PYTHON_REL} < 3400
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}enum34>0:devel/py-enum34 \
		${PYTHON_PKGNAMEPREFIX}singledispatch>0:devel/py-singledispatch \
		${PYTHON_PKGNAMEPREFIX}funcsigs>0:devel/py-funcsigs
.endif

.include <bsd.port.post.mk>
