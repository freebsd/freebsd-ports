# Created by: Joseph Mingrone <jrm@ftfl.ca>
# $FreeBSD$

PORTNAME=	biom-format
PORTVERSION=	2.1.5
CATEGORIES=	biology python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jrm@ftfl.ca
COMMENT=	Biological Observation Matrix (BIOM) Format Project

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} ${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py

USE_GITHUB=	yes
GH_ACCOUNT=	biocore

USES=		python
USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/biom/*.so

.include <bsd.port.mk>
