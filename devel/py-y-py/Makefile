PORTNAME=	y-py
PORTVERSION=	0.6.2
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	y_py-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python bindings for the Y-CRDT built from yrs (Rust)
WWW=		https://ypy.readthedocs.io/en/latest/ \
		https://github.com/y-crdt/ypy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.2.3<2:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no
WRKSRC=		${WRKDIR}/y_py-${PORTVERSION}

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
