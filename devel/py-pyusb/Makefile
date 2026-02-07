PORTNAME=	pyusb
PORTVERSION=	1.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python wrapper around libusb
WWW=		https://pyusb.github.io/pyusb/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

USE_GITHUB=	yes

MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION=${PORTVERSION}
NO_ARCH=	yes

PORTDOCS=	*.rst

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/docs/,} ${STAGEDIR}${DOCSDIR}

test: extract
	@(cd ${WRKSRC}/tests && ${PYTHON_CMD} testall.py)

.include <bsd.port.mk>
