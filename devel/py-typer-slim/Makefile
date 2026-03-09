PORTNAME=	typer-slim
PORTVERSION=	0.24.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	typer_slim-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Typer, build great CLIs. Easy to code. Based on Python type hints
WWW=		https://typer.tiangolo.com/ \
		https://github.com/fastapi/typer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>=0:devel/py-pdm-backend@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typer>=${PORTVERSION}:devel/py-typer@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
