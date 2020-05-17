# Created by: William Grzybowski <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jaraco.timing
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Routines pertinent to the fourth dimension

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.15.0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jaraco>=0:devel/py-jaraco@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=3.5:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-flake8>=0:devel/py-pytest-flake8@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

POST_PLIST=	trim-jaraco-namespace

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3600
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tempora1>=1.5:devel/py-tempora1@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tempora>=1.5:devel/py-tempora@${PY_FLAVOR}
.endif

post-install:
	@${RM} ${STAGEDIR}${PYTHON_SITELIBDIR}/jaraco/__init__.py*
	-@${RM} ${STAGEDIR}${PYTHON_SITELIBDIR}/jaraco/__pycache__/__init__.*
	-@${RMDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/jaraco/__pycache__

trim-jaraco-namespace:
	@${REINPLACE_CMD} '/jaraco\/__init__\./d; /jaraco\/__pycache__\/__init__\./d' ${TMPPLIST}

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -rs -v

.include <bsd.port.post.mk>
