PORTNAME=	termcolor-whl
PORTVERSION=	1.1.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	termcolor_whl-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ANSI Color formatting for output in terminal, successor to termcolor
WWW=		https://github.com/matthewdeanmartin/termcolor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=0.12:devel/py-poetry-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
