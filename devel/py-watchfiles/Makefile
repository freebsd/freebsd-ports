PORTNAME=	watchfiles
PORTVERSION=	0.24.0
PORTREVISION=	9
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple, modern and high performance file watching and code reload in python
WWW=		https://watchfiles.helpmanual.io/ \
		https://github.com/samuelcolvin/watchfiles

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=0.14.16<2:devel/py-maturin@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=3.0.0:devel/py-anyio@${PY_FLAVOR}

USES=		cargo dos2unix python
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no

PORTSCOUT=	limit:^\0.

.include <bsd.port.mk>
