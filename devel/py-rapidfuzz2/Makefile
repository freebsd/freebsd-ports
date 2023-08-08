PORTNAME=	rapidfuzz
DISTVERSION=	2.15.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rapid fuzzy string matching in Python
WWW=		https://github.com/maxbachmann/RapidFuzz

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake-core \
		jarowinkler-cpp>=0:textproc/jarowinkler-cpp \
		ninja:devel/ninja \
		${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rapidfuzz-capi>=1.0.5<1.0.5_99:devel/py-rapidfuzz-capi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build>=0.13.0:devel/py-scikit-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		rapidfuzz-cpp>=0:devel/rapidfuzz-cpp \
		taskflow>=0:devel/taskflow
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jarowinkler>=1.0.3:textproc/py-jarowinkler@${PY_FLAVOR}

USES=		compiler:c++14-lang python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
