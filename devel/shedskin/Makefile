PORTNAME=	shed-skin
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.11
CATEGORIES=	devel python
#MASTER_SITES=	PYPI # no test files
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Restricted Python-to-C++ compiler
WWW=		https://shedskin.github.io/ \
		https://github.com/shedskin/shedskin

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	boehm-gc>0:devel/boehm-gc \
		pcre>0:devel/pcre

USES=		python #:3.13
USE_PYTHON=	pep517 autoplist noflavors pytest

USE_GITHUB=	yes
GH_ACCOUNT=	shedskin
GH_PROJECT=	shedskin

NO_ARCH=	yes

TEST_WRKSRC=	${WRKSRC}/tests

post-extract:
	@${RM} ${WRKSRC}/tests/test_ops_assignment/test_ops_assignment.py.orig

post-patch:
	# adjust FLAGS placed into generated makefiles
	@${REINPLACE_CMD} -e ' \
		s|^CXX?=.*|CXX?=${CXX}|; \
		s|^CXXFLAGS?=.*|& -I${PREFIX}/include |; \
		s|^LFLAGS=.*|& -L${PREFIX}/lib |; \
		' ${WRKSRC}/shedskin/resources/flags/FLAGS
	# adjust pyproject.toml for the difference between GH and PYPI tarballs
	@${REINPLACE_CMD} \
		-e 's/name = "shedskin"/name = "shed-skin"/' \
		${WRKSRC}/pyproject.toml

# tests as of 0.9.10: 2 failed, 627 passed in 343.34s (0:05:43), AttributeError: module 'itertools' has no attribute 'batched', see https://github.com/shedskin/shedskin/issues/555
# tests as of 0.9.11: 22 failed, 655 passed in 16.66s (failures are due to tests switching to Python-3.13 or later only features)

.include <bsd.port.mk>
