PORTNAME=	pycrdt
PORTVERSION=	0.12.28
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	pycrdt-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python bindings for Yrs
WWW=		https://y-crdt.github.io/pycrdt/ \
		https://github.com/y-crdt/pycrdt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.8.2<2:devel/py-maturin@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=4.4.0<5.0.0:devel/py-anyio@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=3.6:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.14.0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
