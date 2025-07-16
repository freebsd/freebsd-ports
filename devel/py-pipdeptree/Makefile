PORTNAME=	pipdeptree
DISTVERSION=	2.27.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Command line utility to show dependency tree of packages
WWW=		https://github.com/naiquevin/pipdeptree

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.25:devel/py-hatchling@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0.4:devel/py-hatch-vcs@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>=6.0.0:devel/py-pip@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|import __version__|import version as __version__|g' \
		${WRKSRC}/src/pipdeptree/_cli.py

.include <bsd.port.mk>
