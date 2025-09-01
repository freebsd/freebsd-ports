PORTNAME=	rpds-py
PORTVERSION=	0.26.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/crate-py/rpds/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	rpds_py-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python bindings to Rust persistent data structures (rpds)
WWW=		https://rpds.readthedocs.io/en/latest/ \
		https://github.com/crate-py/rpds

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.9<2.0:devel/py-maturin@${PY_FLAVOR}

USES=		cargo dos2unix python
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no
WRKSRC=		${WRKDIR}/rpds_py-${PORTVERSION}

.include <bsd.port.mk>
