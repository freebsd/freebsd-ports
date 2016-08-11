# Created by: Joseph Mingrone <jrm@ftfl.ca>
# $FreeBSD$

PORTNAME=	biom-format
PORTVERSION=	2.1.5
PORTREVISION=	1
CATEGORIES=	biology python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jrm@ftfl.ca
COMMENT=	Biological Observation Matrix (BIOM) Format Project

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}h5py>=2.6.0:science/py-h5py    \
		${PYTHON_PKGNAMEPREFIX}click>=6.6:devel/py-click      \
		${PYTHON_PKGNAMEPREFIX}future>=0.15.2:devel/py-future \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.16.1:science/py-scipy

USE_GITHUB=	yes
GH_ACCOUNT=	biocore

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pyqi>=0.2.0:devel/py-pyqi
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/biom/*.so

.include <bsd.port.post.mk>
