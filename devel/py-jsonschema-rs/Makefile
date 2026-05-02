PORTNAME=	jsonschema-rs
PORTVERSION=	0.46.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	jsonschema_rs-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	High-performance JSON Schema validator for Python
WWW=		https://github.com/Stranger6667/jsonschema/tree/master/crates/jsonschema-py \
		https://github.com/Stranger6667/jsonschema

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.0<2.0:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no
WRKSRC=		${WRKDIR}/jsonschema_rs-${PORTVERSION}

.include <bsd.port.mk>
