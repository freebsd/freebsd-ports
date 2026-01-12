PORTNAME=	logbook
PORTVERSION=	1.9.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	logbook-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	philip@FreeBSD.org
COMMENT=	Logging replacement for Python
WWW=		https://logbook.readthedocs.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-rust>0:devel/py-setuptools-rust@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	distutils autoplist
WRKSRC=		${WRKDIR}/logbook-${PORTVERSION}

CARGO_BUILD=   no
CARGO_INSTALL= no

PLIST_FILES+=	${PYTHON_SITELIBDIR}/logbook/_speedups${PYTHON_TAG}.so

post-install:
		@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/logbook/_speedups${PYTHON_TAG}.so

.include <bsd.port.mk>
