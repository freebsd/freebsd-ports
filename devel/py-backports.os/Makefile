# $FreeBSD$

PORTNAME=	backports.os
DISTVERSION=	0.1.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Backport of new features in Python's os module

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}backports>=0:devel/py-backports@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0:devel/py-future@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

POST_PLIST=	trim-backports-namespace

post-install:
	@${RM} ${STAGEDIR}${PYTHON_SITELIBDIR}/backports/__init__.py*

trim-backports-namespace:
	@${REINPLACE_CMD} '/backports\/__init__.py*/d' ${TMPPLIST}

.include <bsd.port.mk>
