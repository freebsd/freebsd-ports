PORTNAME=	rapidfuzz
DISTVERSION=	2.0.7
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Rapid fuzzy string matching in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}rapidfuzz-capi==1.0.5:devel/py-rapidfuzz-capi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build>=0.13.0:devel/py-scikit-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}

USES=		compiler:c++14-lang python:3.6+
USE_PYTHON=	distutils autoplist

post-install:
	@cd ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME} && \
		${STRIP_CMD} \
			${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/*.so \
			${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/distance/*.so

.include <bsd.port.mk>
