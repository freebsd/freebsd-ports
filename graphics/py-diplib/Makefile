PORTNAME=	diplib
DISTVERSION=	3.5.1
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library and development environment for quantitative image analysis
WWW=		https://diplib.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}build>0:devel/py-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}installer>0:devel/py-installer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libDIP.so:graphics/diplib

USES=		cmake compiler:c++14-lang python
USE_PYTHON=	flavors

USE_GITHUB=	yes
GH_ACCOUNT=	DIPlib

WRKSRC_SUBDIR=	pydip

ALL_TARGET=	bdist_wheel

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	@cd ${INSTALL_WRKSRC} && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${PYTHON_CMD} \
			-m installer --destdir ${STAGEDIR} --prefix ${PREFIX} ${BUILD_WRKSRC}/staging/dist/${PORTNAME:C|[-_]+|_|g}-${DISTVERSION}*.whl
	# remove the file conficting with the C++ diplib package
	@${RM} ${STAGEDIR}${PREFIX}/bin/dipview

.include <bsd.port.mk>
