# $FreeBSD$

PORTNAME=	biom-format
PORTVERSION=	2.1.7
PORTREVISION=	3
CATEGORIES=	biology python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Biological Observation Matrix (BIOM) Format Project

LICENSE=	BSD3CLAUSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}future>=0.16.0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.13.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=0.20.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>=2.2.0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR}

USES=		python:-3.6
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pyqi>0:devel/py-pyqi@${PY_FLAVOR}
.endif

post-extract:
	${RM} -r ${WRKSRC}/tests

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/biom/*.so

.include <bsd.port.post.mk>
