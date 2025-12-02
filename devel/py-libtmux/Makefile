PORTNAME=	libtmux
PORTVERSION=	0.48.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Typed scripting library / ORM / API wrapper for tmux
WWW=		https://libtmux.git-pull.com/ \
		https://github.com/tmux-python/libtmux

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	tmux:sysutils/tmux

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
