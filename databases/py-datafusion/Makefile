PORTNAME=	datafusion
PORTVERSION=	51.0.0
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Build and run queries against data
WWW=		https://datafusion.apache.org/python/ \
		https://github.com/apache/datafusion-python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_armv7=	rustc-LLVM ERROR: out of memory
BROKEN_i386=	rustc-LLVM ERROR: out of memory

BUILD_DEPENDS=	protoc:devel/protobuf \
		${PYTHON_PKGNAMEPREFIX}maturin>=1.8.1:devel/py-maturin@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyarrow>=16.0.0:databases/py-pyarrow@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist concurrent pep517 pytest

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

USE_GITHUB=	yes
GH_ACCOUNT=	apache
GH_PROJECT=	datafusion-python

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
