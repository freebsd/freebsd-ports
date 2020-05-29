# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jaraco.functools
PORTVERSION=	2.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Additional functools for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.15.0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jaraco>=0:devel/py-jaraco@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

POST_PLIST=	trim-jaraco-namespace

# jaraco.functools 3.0.0+ requires Python 3.6+
PORTSCOUT=	limit:^2\.

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}backports.functools_lru_cache>=1.0.3:devel/py-backports.functools_lru_cache@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} >= 3400
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}more-itertools>=2.7:devel/py-more-itertools@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}more-itertools5>=2.7:devel/py-more-itertools5@${PY_FLAVOR}
.endif

post-install:
	@${RM} ${STAGEDIR}${PYTHON_SITELIBDIR}/jaraco/__init__.py*
	-@${RM} ${STAGEDIR}${PYTHON_SITELIBDIR}/jaraco/__pycache__/__init__.*
	-@${RMDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/jaraco/__pycache__

trim-jaraco-namespace:
	@${REINPLACE_CMD} '/jaraco\/__init__\./d; /jaraco\/__pycache__\/__init__\./d' ${TMPPLIST}

.include <bsd.port.post.mk>
