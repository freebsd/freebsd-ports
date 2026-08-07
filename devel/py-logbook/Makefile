PORTNAME=	logbook
PORTVERSION=	1.10.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	logbook-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	philip@FreeBSD.org
COMMENT=	Logging replacement for Python
WWW=		https://logbook.readthedocs.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=  ${PYTHON_PKGNAMEPREFIX}setuptools-rust>0:devel/py-setuptools-rust@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist concurrent pep517
WRKSRC=		${WRKDIR}/logbook-${PORTVERSION}

CARGO_BUILD=   no
CARGO_INSTALL= no

post-install:
		@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/logbook/_speedups${PYTHON_TAG}.so

.include <bsd.port.mk>
