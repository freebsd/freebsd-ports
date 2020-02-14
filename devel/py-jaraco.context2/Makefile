# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jaraco.context
PORTVERSION=	2.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Context managers by jaraco

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.15.0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jaraco>=0:devel/py-jaraco@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

POST_PLIST=	trim-jaraco-namespace

PORTSCOUT=	limit:^2\.

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}contextlib2>=0:devel/py-contextlib2@${PY_FLAVOR}
.endif

post-patch:
	@${REINPLACE_CMD} -e '/jaraco.apt/d; /yg.lockfile/d' ${WRKSRC}/setup.cfg

post-install:
	@${RM} ${STAGEDIR}${PYTHON_SITELIBDIR}/jaraco/__init__.py*
	-@${RM} ${STAGEDIR}${PYTHON_SITELIBDIR}/jaraco/__pycache__/__init__.*
	-@${RMDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/jaraco/__pycache__

trim-jaraco-namespace:
	@${REINPLACE_CMD} '/jaraco\/__init__\./d; /jaraco\/__pycache__\/__init__\./d' ${TMPPLIST}

.include <bsd.port.post.mk>
