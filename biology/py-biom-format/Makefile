# $FreeBSD$

PORTNAME=	biom-format
PORTVERSION=	2.1.6
PORTREVISION=	1
CATEGORIES=	biology python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Biological Observation Matrix (BIOM) Format Project

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}click>=6.6:devel/py-click@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0.15.2:devel/py-future@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>=2.6.0:science/py-h5py@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.16.1:science/py-scipy@${FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	biocore

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pyqi>=0.2.0:devel/py-pyqi@${FLAVOR}
.endif

post-extract:
	${RM} -r ${WRKSRC}/tests

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/biom/*.so

.include <bsd.port.post.mk>
