# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	pre-commit-hooks
PORTVERSION=	4.0.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pre_commit_hooks-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Some out-of-the-box hooks for pre-commit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.15:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0:textproc/py-toml@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
