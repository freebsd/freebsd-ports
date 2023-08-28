PORTNAME=	gdstk
DISTVERSION=	0.9.42
CATEGORIES=	cad
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for creation and manipulation of GDSII and OASIS files
WWW=		https://heitzmann.github.io/gdstk/

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake-core \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYNUMPY}

USES=		compiler:c++11-lang python
USE_PYTHON=	pep517 autoplist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/gdstk${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
