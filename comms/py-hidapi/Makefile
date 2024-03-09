PORTNAME=	hidapi
DISTVERSION=	0.14.0
CATEGORIES=	comms python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${GH_ACCOUNT}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cython interface to comms/hidapi
WWW=		https://pypi.org/project/hidapi/

LICENSE=	BSD3CLAUSE GPLv3 PD
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSE-bsd.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE-gpl3.txt
LICENSE_FILE_PD=	${WRKSRC}/LICENSE-orig.txt
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cython>0:lang/cython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}recommonmark>0:textproc/py-recommonmark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libhidapi.so:comms/hidapi
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	trezor
GH_PROJECT=	cython-hidapi
USE_PYTHON=	autoplist cython pep517 pytest

MAKE_ENV+=	DISTUTILS_DEBUG=1

DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|usb-1.0|usb|g' ${WRKSRC}/setup.py

post-build:
	(cd ${WRKSRC}/docs && \
		${SETENV} sphinx-build-${PYTHON_VER} -b man . _build/man)

post-build-DOCS-on:
	(cd ${WRKSRC}/docs && \
		${SETENV} sphinx-build-${PYTHON_VER} -b html . _build/html)

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/_build/man/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/hid*.so

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/_build/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/ "-not -name .buildinfo -not -regex ^./.doctrees.* -not -regex ^./_sources.*")

.include <bsd.port.mk>
