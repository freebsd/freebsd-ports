PORTNAME=	pdm-autoexport
PORTVERSION=	0.2.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pdm_autoexport-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PDM plugin to sync the exported files with the project file
WWW=		https://github.com/pdm-project/pdm-autoexport

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>=0:devel/py-pdm-backend@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
